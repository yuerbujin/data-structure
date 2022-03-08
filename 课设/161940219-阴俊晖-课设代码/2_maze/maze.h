#ifndef MAZE_H
#define MAZE_H

#include <QObject>
#include <iostream>
#include <QVector>
#include <QString>
#include <QTextBrowser>
#include <QFile>
#include <QDialog>
#include <QDebug>
#include <QByteArray>
#include <QStack>

enum Status{
    ERROR = 0,
    OK = 1,
    NOTFOUND = 0,
    FOUND = 1
};

#define ROAD 0
#define WALL 1
#define VISITED 2
#define PATH 3
#define NOTPATH ROAD

class QMainWindow;

class Maze : public QObject
{
    Q_OBJECT
public:
    explicit Maze(QObject *parent = nullptr);

    //1.获得原迷宫
    Status readIn(QString path);

    //2.找到路径
    Status findDes(int startRow, int startCol, int desRow, int desCol);

    //3.输出迷宫
    void show(QTextBrowser* pos);

//private:
    int row;
    int col;

    QVector<QVector<int> > oriMaze;
    QVector<QVector<int> > ansMaze;

signals:

public slots:
};

struct Position{
    int row;
    int col;

    Position();
    Position(int r, int c);
};

#endif // MAZE_H
