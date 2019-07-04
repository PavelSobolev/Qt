#ifndef CELL_H
#define CELL_H

class Cell // table's cell
{
public:
    int zanId;
    int grId;
    int facultId;
    int predmId;
    int prepodId;
    int vzId;
    int kabId;
    int day;
    int mon;
    int year;
    int para;
    Cell()
    {
        facultId = 7;
        zanId = 0;
        grId = 0;
        predmId = 0;
        prepodId = 0;
        vzId = 0;
        kabId = 0;
        day = 0;
        mon = 0;
        year = 0;
        para = 0;
    }
};


#endif // CELL_H
