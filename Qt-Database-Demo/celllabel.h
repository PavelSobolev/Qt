#ifndef CELLLABEL_H
#define CELLLABEL_H

#include <QLabel>
#include "cell.h"

class CellLabel : public QLabel // model of text in the cell
{
    Q_OBJECT
public:
    Cell RaspData;
    explicit CellLabel(QWidget *parent = nullptr);
};

#endif // CELLLABEL_H
