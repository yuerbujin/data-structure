#include "maze.h"

Maze::Maze(QObject *parent) : QObject(parent)
{

}

Status Maze::readIn(QString path)
{
//    打开文件
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)){
        return ERROR;
    }

    QByteArray bArray;
    QVector<int> v;

    //读入迷宫
    oriMaze.clear();//先清空原迷宫

    while (!file.atEnd())
    {
        v.clear();
        //读入一行迷宫
        bArray = file.readLine();
        for (int i = 0; i < bArray.size(); i++)
        {
            if (bArray.at(i) == '0')
                v.push_back(0);
            else if (bArray.at(i) == '1')
                v.push_back(1);
        }

        this->oriMaze.push_back(v);
    }

    this->col = oriMaze.size();
    this->row = oriMaze[0].size();
    ansMaze = oriMaze;

    file.close();
    return OK;
}

Status Maze::findDes(int startRow, int startCol, int desRow, int desCol)
{
    QVector<QVector<int> > visited(oriMaze);//辅助数组
    Position cur;

    QStack<Position> stack;
    stack.push(Position(startRow, startCol));
    ansMaze[startRow][startCol] = PATH;
    visited[startRow][startCol] = VISITED;

    //核心实现（路径实时存放于maze中）
    while (1)
    {
        //没走到终点
        if (stack.empty())
            return NOTFOUND;

        cur = stack.top();
//        qDebug() << "cur.row: " << cur.row << "cur.col: " << cur.col
//                 << "desRow: " << desRow << "desCol: " << desCol
//                 << endl;

        ansMaze[cur.row][cur.col] = PATH;
        //判断cur是不是终点
        if (    (cur.row == desRow)
            &&  (cur.col == desCol))
            return FOUND;

        bool flag = false;

        //依次试探上右下左
        //上
        if (    (cur.row-1 >= 0)//不越界
            &&  (visited[cur.row-1][cur.col] != VISITED)//未走过
            &&  (ansMaze[cur.row-1][cur.col] == ROAD))//不是墙
        {
            stack.push(Position(cur.row-1, cur.col));
            visited[cur.row-1][cur.col] = VISITED;
            flag = true;
        }

        //右
        if (    (cur.col+1 <= col-1)//不越界
            &&  (visited[cur.row][cur.col+1] != VISITED)//未走过
            &&  (ansMaze[cur.row][cur.col+1] == ROAD))//不是墙
        {
            stack.push(Position(cur.row, cur.col+1));
            visited[cur.row][cur.col+1] = VISITED;
            flag = true;
        }

        //下
        if (    (cur.row+1 <= row-1)//不越界
            &&  (visited[cur.row+1][cur.col] != VISITED)//未走过
            &&  (ansMaze[cur.row+1][cur.col] == ROAD))//不是墙
        {
            stack.push(Position(cur.row+1, cur.col));
            visited[cur.row+1][cur.col] = VISITED;
            flag = true;
        }

        //左
        if (    (cur.col-1 >= 0)//不越界
            &&  (visited[cur.row][cur.col-1] != VISITED)//未走过
            &&  (ansMaze[cur.row][cur.col-1] == ROAD))//不是墙
        {
            stack.push(Position(cur.row, cur.col-1));
            visited[cur.row][cur.col-1] = VISITED;
            flag = true;
        }

        if (!flag)
        {
            stack.pop();
            ansMaze[cur.row][cur.col] = NOTPATH;
        }
    }
}

void Maze::show(QTextBrowser* pos)
{
    pos->clear();//先清屏

    for (int i = 0; i < ansMaze.size(); i++)
    {
        //打印一行
        for (int j = 0; j < ansMaze[i].size(); j++)
        {
            if (ansMaze[i][j] == ROAD)
            {
                //路：黄色
                pos->setTextColor(QColor(Qt::yellow));
                pos->insertPlainText(QString("0"));
            }
            else if (ansMaze[i][j] == WALL)
            {
                //墙：黑色
                pos->setTextColor(QColor(Qt::black));
                pos->insertPlainText(QString("1"));
            }
            else if (ansMaze[i][j] == PATH)
            {
                //走过的路：红色
                pos->setTextColor(QColor(Qt::red));
                pos->insertPlainText(QString("$"));
            }
            pos->insertPlainText("  ");
        }
        //换行（append函数自带换行）
        pos->append(QString(""));
    }
}

Position::Position()
{

}

Position::Position(int r, int c): row(r), col(c)
{

}
