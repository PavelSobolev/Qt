## Desktop application for editing of classes schedule of Sakhalin Humanitarian and Technological Institute

This utility was created to provide quick and easy way of creating (and editing) of classes schedules for publication on the web site of the Institute. This app uses connection to remote SQL Server in order to exchange appropriate data (information about studying groups, group's curriculum, lecturers, classrooms and available date/time slots). The used relational database available in local network of the Institute.

### Used technologies
1. C++ / Qt / Qt Creator
2. MS SQL Server / SQL

## UI Examples (in Russian)

#### Main window with table of schedule

* Upper part of the window has several lists (list of groups, list of curricula for the chosen group (with name of the lecturer), list of class's types (seminar, practical traning, lecture, exam, etc.), list of available classrooms, and list of weeks.
* The schedule can be different from week to week.
* The table's rows represent days of chosen week, table's rows represent fixed standard times (start and finish) for each class. 

![UI](https://github.com/PavelSobolev/Qt/blob/master/Qt-Database-Demo/uiimg/01.png)

#### Dialog for quick editing of curricula 

This window contains list of student groups (according their specialization), list of academic disciplines of the chosen group. Also, there are two buttons (add new academic discipline, edit chosen academic discipline).

![UI](https://github.com/PavelSobolev/Qt/blob/master/Qt-Database-Demo/uiimg/02.png)![UI](https://github.com/PavelSobolev/Qt/blob/master/Qt-Database-Demo/uiimg/0_2).png)
