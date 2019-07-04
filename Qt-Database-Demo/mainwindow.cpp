#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowState(Qt::WindowMaximized);

    // connect to DB (remote SQL Server)
    if (!initDB())
    {
        // if error
        QMessageBox::critical(this,"Ошибка соединения",
           connection.lastError().text());
        return;
    }

    fill_date_list ();
    fill_vidzan_list();
    fill_kab_list();

    initUI();
}


bool MainWindow::initDB()
{
    connection = QSqlDatabase::addDatabase("QODBC");
    connection.setUserName("***");
    connection.setPassword("*****");
    conData = "DRIVER={SQL SERVER};SERVER=******;DATABASE=****;";

    connection.setDatabaseName(conData);

    bool Res = connection.open();
    return Res;
}

void MainWindow::initUI()
{
    groups = new QSqlQuery(connection);
    if (!groups->exec("select grupa.id, grupa.name, grupa.kurs_id, grupa.fakultet_id from grupa "
                     " join specialnost on specialnost.id = grupa.specialnost_id"
                     " where actual=1 and specialnost.zaoch = 0 and (fakultet_id = 7 or fakultet_id = 10)"
                     " order by fakultet_id, kurs_id "))
    {
        QMessageBox::critical(this,"Ошибка запроса",
           connection.lastError().text());
        return;
    }

    while(groups->next())
    {
        ui->grList->addItem(
                    QString("%1 [ид=%2]")
                    .arg(groups->value(1).toString())
                    .arg(groups->value(0).toString()));
    }

    if (ui->grList->count()>0)
        ui->grList->setCurrentRow(0);

    QSqlQuery *UchGodQ = new QSqlQuery(connection);
    UchGodQ->exec("select id from Uch_God where getdate()>=start and getdate()<=finish");

    if (UchGodQ->size()>0)
        UchGodId = UchGodQ->value(0).toInt();
    else
        UchGodId = UchNumberDefault;
}

void MainWindow::fill_date_list()
{
        QDate actual, start, end, current;

        starts.clear();
        ends.clear();

        actual = QDate::currentDate();

        int m = actual.month();
        int y = actual.year();

        if ( m >= 1 && m <= 6 )
            start = QDate(y - 1, 9, 1);
        else
            start = QDate(y, 9, 1);

        if ( m <= 12 && m > 6 )
            end = QDate(y + 1, 6, 20);
        else
            end = QDate(y, 6, 20);

        int ts = 1;  // first day
        int ts7 = 7; // last day

        do
        {
            if (start.dayOfWeek() != 1 )
                start = start.addDays(-ts);
            else
                break;
        }
        while(true);

        do
        {
            if ( end.dayOfWeek() != 7 )
                end = end.addDays(ts);
            else
                break;
        }
        while (true);

        for ( current = start; current < end; current = current.addDays(ts7) )
        {
            starts.append(current);
            ends.append(current.addDays(6));

            QString dateitem = "Неделя c " + current.toString("dd.MM.yyyy") + " по " +
                current.addDays(6).toString("dd.MM.yyyy");
            ui->week_list->addItem(dateitem);
        }

        int curInd = get_current_date_listnumber();
        ui->week_list->setCurrentIndex(curInd);

        QStringList Headers;

        for(int i=0; i<7; i++)
        {
            Headers << starts[curInd].addDays(i).toString("dddd") +
                       "\n" + starts[curInd].addDays(i).toString("MMMM, dd ").toLower();
        }

        ui->rasp->setHorizontalHeaderLabels(Headers);

    }

int MainWindow::get_current_date_listnumber ( )
{
    QDate now = QDate::currentDate();

    for (int i = 0; i < starts.count(); i++)
    {
        if ( now >= starts[i] && now <= ends[i] )
        {
            return i;
        }
    }

    return 0;
}

void MainWindow::fill_predm_list(int grId) //subjects list
{
    QString grKurs = groups->value(2).toString();

    int CurMon = starts[ui->week_list->currentIndex()].month();
    int ChetSemestr = (CurMon >=2 && CurMon<9) ? 0 : 1;

    predms = new QSqlQuery(connection);
    ui->predmList->clear();

    QString Sql = QString("select predmet.id, prepod.id, predmet.name, predmet.name_krat, dbo.GetPrepodFIOByID(prepod.id)"
                          " from predmet"
                          " join prepod on prepod.id = predmet.prepod_id"
                          " where predmet.actual=1 and predmet.grupa_id = %1 and"
                          " predmet.kurs_id = %2 and predmet.semestr % 2 = %3"
                          " order by predmet.name, prepod.fam").arg(grId).arg(grKurs).arg(ChetSemestr);
    predms->exec(Sql);

    while (predms->next()) {
        ui->predmList->addItem(predms->value(0).toString() + ": " + predms->value(2).toString() +
                               " [" + predms->value(4).toString() + " (" + predms->value(1).toString() + ")]") ;
    }
}

// изменение выбранной группы
void MainWindow::on_grList_currentRowChanged(int currentRow)
{
    groups->seek(currentRow);
    fill_predm_list(groups->value(0).toInt());
    ui->predmList->setCurrentRow(0);
    ui->vidZanList->setCurrentRow(0);
    ui->kabList->setCurrentRow(0);

    fill_rasp_table();
}

// изменение выбранной недели
void MainWindow::on_week_list_currentIndexChanged(int index)
{
    if (ui->grList->currentRow()<0) return;

    groups->seek(ui->grList->currentRow());
    fill_predm_list(groups->value(0).toInt());
    fill_rasp_table();
}


void MainWindow::fill_kab_list()
{
    kabins = new QSqlQuery(connection);
    kabins->exec("select * from kabinet where korpus_id=1 order by prioritet");

    while(kabins->next()){
        ui->kabList->addItem(kabins->value(1).toString());
    }

    ui->kabList->setCurrentRow(0);
}

void MainWindow::fill_vidzan_list()
{
    vidzans = new QSqlQuery(connection);
    vidzans->exec("select id, name, krat_name from vid_zan where id = 1 or id = 2 or id = 3 or "
                  " id = 5 or id = 6 or id = 7  or id = 8 or id = 16 or id = 19");

    while(vidzans->next()){
        ui->vidZanList->addItem(vidzans->value(1).toString());
    }

    ui->vidZanList->setCurrentRow(0);
}

int MainWindow::getColnumByDate(QDate D)
{
    int ci = ui->week_list->currentIndex();
    int index = 0;
    for(QDate id=starts[ci]; id<=ends[ci]; id=id.addDays(1))
    {
        if (D==id) return index;
        index++;
    }
}


void MainWindow::fill_rasp_table()
{
    ui->rasp->clearContents();

    for(int i=0; i<7; i++)
    {
        ui->rasp->setRowHeight(i,60);
        ui->rasp->setColumnWidth(i,220);
        for(int j=0; j<7; j++)
        {
            CellLabel *lb = new CellLabel(this);
            lb->setText("");
            ui->rasp->setCellWidget(i,j,lb);
        }
    }

    QStringList Headers;

    for(int i=0; i<7; i++)
    {
        Headers << starts[ui->week_list->currentIndex()].addDays(i).toString("dddd") +
                   "\n" + starts[ui->week_list->currentIndex()].addDays(i).toString("MMMM, dd ").toLower();
    }

    ui->rasp->setHorizontalHeaderLabels(Headers);

    QString date1 = starts[ui->week_list->currentIndex()].toString("yyyyMMdd");
    QString date2 = ends[ui->week_list->currentIndex()].toString("yyyyMMdd");

    groups->seek(ui->grList->currentRow());

    QString sql = QString("select y, m, d, nom_zan, rasp.grupa_id, rasp.predmet_id, " // 0 1 2 3 4 5
            " rasp.prepod_id, rasp.kabinet_id, rasp.vid_zan_id, rasp.id, " // 6 7 8 9
            " predmet.name, predmet.name_krat, dbo.GetPrepodFIOByID(rasp.prepod_id), "
            " kabinet.nomer, vid_zan.name, rasp.fakultet_id " //  10-15
            " from rasp "
        " join predmet on predmet.id = rasp.predmet_id "
        " join vid_zan on vid_zan.id = rasp.vid_zan_id "
        " join kabinet on kabinet.id = rasp.kabinet_id "
        " where rasp.grupa_id = %1 "
        " and cast((cast(y as nvarchar(4)) + '-' + cast(m as nvarchar(2)) + '-' + cast(d as nvarchar(2))) as date)"
        " between '%2'  and '%3' "
        " order by cast((cast(y as nvarchar(4)) + '-' + cast(m as nvarchar(2)) + '-' + cast(d as nvarchar(2))) as date), "
        " nom_zan ").arg(groups->value(0).toString()).arg(date1).arg(date2);

    rasp = new QSqlQuery();
    rasp->exec(sql);

    while(rasp->next())
    {
        QDate raspdate = QDate(rasp->value(0).toInt(),rasp->value(1).toInt(),rasp->value(2).toInt());
        int Col = getColnumByDate(raspdate);
        int Row = rasp->value(3).toInt();

        CellLabel *Lbl = (CellLabel*)ui->rasp->cellWidget(Row-1,Col);
        QString txt = QString("<center><b style='font-size:14px;color:green;'>%1, %2</b><br>/<span style='color:orange;'><b>%3</b></span>/</center>").
                arg(rasp->value(11).toString()).
                arg(rasp->value(13).toString()).
                arg(rasp->value(12).toString());
        Lbl->setText(txt);

        Cell C;
        C.year = rasp->value(0).toInt();
        C.mon = rasp->value(1).toInt();
        C.day = rasp->value(2).toInt();
        C.para = rasp->value(3).toInt();
        C.grId = rasp->value(4).toInt();
        C.predmId = rasp->value(5).toInt();
        C.prepodId = rasp->value(6).toInt();
        C.kabId = rasp->value(7).toInt();
        C.vzId = rasp->value(8).toInt();
        C.zanId = rasp->value(9).toInt();
        C.facultId = rasp->value(15).toInt();

        Lbl->RaspData = C;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_rasp_cellDoubleClicked(int row, int column)
{
    if (!ui->action_2->isChecked()) return;
    Cell NewItem;
    NewItem.year = starts[ui->week_list->currentIndex()].addDays(column).year();
    NewItem.day = starts[ui->week_list->currentIndex()].addDays(column).day();
    NewItem.mon = starts[ui->week_list->currentIndex()].addDays(column).month();
    NewItem.para = row + 1;
    groups->seek(ui->grList->currentRow());
    NewItem.grId = groups->value(0).toInt();
    predms->seek(ui->predmList->currentRow());
    NewItem.predmId = predms->value(0).toInt();
    NewItem.prepodId = predms->value(1).toInt();
    kabins->seek(ui->kabList->currentRow());
    NewItem.kabId = kabins->value(1).toInt();
    vidzans->seek(ui->vidZanList->currentRow());
    NewItem.vzId = vidzans->value(0).toInt();
    NewItem.facultId = groups->value(3).toInt(); ///////////

    CellLabel *Cl = (CellLabel*)ui->rasp->cellWidget(row, column);
    predms->seek(ui->predmList->currentRow());

    QString txt = QString("<center><b style='color:green;'>%1</b>, %2<br>/<span style='color:cyan;'>%3</span>/</center>").
            arg(predms->value(3).toString()).
            arg(ui->kabList->currentItem()->text()).
            arg(predms->value(4).toString());

    if (Cl->text().trimmed().length()>0)
    {
        // for future impl.
        //selectZanData(Cl->RaspData);
        // update
    }
    else
    {
        QDate RaspDate = starts[ui->week_list->currentIndex()].addDays(column);
        int D = RaspDate.day();
        int M = RaspDate.month();
        int Y = RaspDate.year();
        predms->seek(ui->predmList->currentRow());
        int PredmId = predms->value(0).toInt();
        int PrepId = predms->value(1).toInt();
        groups->seek(ui->grList->currentRow());
        int GrId = groups->value(0).toInt();
        int FacId =  groups->value(3).toInt();
        int KursNum = groups->value(2).toInt();
        int NomZan = row + 1;
        vidzans->seek(ui->vidZanList->currentRow());
        int VidZanId = vidzans->value(0).toInt();
        kabins->seek(ui->kabList->currentRow());
        int KabId = kabins->value(0).toInt();
        qsrand(QDateTime::currentDateTime().currentMSecsSinceEpoch());
        int PotokId = qrand();

        QString Sql = QString("INSERT INTO [VKR].[dbo].[rasp]"
                "([d],[m],[y],[predmet_id]"
                ",[grupa_id],[prepod_id]"
                ",[fakultet_id],[kurs_id]"
                ",[nom_zan],[vid_zan_id]"
                ",[kabinet_id],[semestr_id]"
                ",[potok_id],[subgr_nomer]"
                ",[kol_chas],[uch_god_id])"
          " VALUES "
                " (%1, %2, %3, %4," // 1 2 3 4
                " %5, %6," // 5 6
                " %7, %8," // 7 8
                " %9, ") // 9
                .arg(D).arg(M).arg(Y).arg(PredmId)
                .arg(GrId).arg(PrepId)
                .arg(FacId).arg(KursNum)
                .arg(NomZan) +
                QString("%1," // 10
                      " %2, 1," // 11 12
                      " %4, 0," // 13 14
                      " 2, %3); select SCOPE_IDENTITY()") // 15 16
                      .arg(VidZanId)
                      .arg(KabId)
                      .arg(UchGodId).arg(PotokId);

        QSqlQuery *Insert = new QSqlQuery(connection);
        Insert->exec(Sql);
        Insert->~QSqlQuery();
        fill_rasp_table();
        ui->rasp->setCurrentCell(row, column);
    }
}

void MainWindow::on_rasp_cellPressed(int row, int column)
{
    CellLabel *Cl = (CellLabel*)ui->rasp->cellWidget(row, column);
    if (Cl->text().trimmed().length()>0)
    {
        if (!ui->action_2->isChecked())
            selectZanData(Cl->RaspData);
    }
}

void MainWindow::selectZanData(Cell C)
{
    int i = -1;

    predms->first();
    do
    {
        i++;
        if (C.predmId == predms->value(0).toInt())
        {
            ui->predmList->setCurrentRow(i);
            break;
        }

    }
    while(predms->next());

    i = -1;
    vidzans->first();
    do
    {
        i++;
        if (C.vzId == vidzans->value(0).toInt())
        {
            ui->vidZanList->setCurrentRow(i);
            break;
        }
    }
    while(vidzans->next());


    i = -1;
    kabins->first();
    do
    {
        i++;
        if (C.kabId == kabins->value(0).toInt())
        {
            ui->kabList->setCurrentRow(i);
            break;
        }
    }
    while(kabins->next());
}

void MainWindow::on_rasp_itemClicked(QTableWidgetItem *item)
{
    Cell *C = (Cell*)item;
    selectZanData(*C);
}

void MainWindow::on_action_triggered()
{
    fill_rasp_table();
}

void MainWindow::on_action_2_triggered()
{
    ui->action_3->setEnabled(ui->action_2->isChecked());
}

void MainWindow::on_action_3_triggered()
{
    if (ui->rasp->currentColumn()<0) return;
    if (ui->rasp->currentRow()<0) return;

    CellLabel *Cl = (CellLabel*)ui->rasp->cellWidget(ui->rasp->currentRow(), ui->rasp->currentColumn());

    int c = ui->rasp->currentColumn();
    int r = ui->rasp->currentRow();

    if (Cl->text().trimmed().length()==0) return;

    //int Id = Cl->RaspData.zanId;

    QString Sql = QString("delete from rasp where id = %1").arg(Cl->RaspData.zanId);
    QSqlQuery *DelQuery = new QSqlQuery(connection);
    DelQuery->exec(Sql);
    Cl->setText("");

    fill_rasp_table();
    ui->rasp->setCurrentCell(r,c);
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key()==16777220)
    {
        int row = ui->rasp->currentRow();
        int column = ui->rasp->currentColumn();

        if (row >= 0 && column >= 0)
        {
            on_rasp_cellDoubleClicked(row, column);
        }
    }

    if (event->key()==45)
    {
        if (ui->action_3->isEnabled())
        {
            on_action_3_triggered();
        }
    }
}
