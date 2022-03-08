#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(1024, 768);

    Maze* maze = new Maze;

    //1.读入起始迷宫
    connect(ui->btn1, &QPushButton::clicked, [=](){
        QString path = QFileDialog::getOpenFileName(this, "读入原迷宫", "");
        this->ui->lineEdit1->setText(path);

        if (maze->readIn(path) == OK)
        {
            maze->show(ui->textBrowser_ori);
            qDebug() << "迷宫路径读入" << endl;

            //设置用户选择起点、终点的最大范围
            ui->spinBox_startRow->setMaximum(maze->row);
            ui->spinBox_startCol->setMaximum(maze->col);
            ui->spinBox_desRow->setMaximum(maze->row);
            ui->spinBox_desCol->setMaximum(maze->col);
        }
        else {
            QMessageBox::critical(this,"错误","文件读入失败！");
        }
    });

    connect(ui->btn_print, &QPushButton::clicked, [=]()
    {
        //清除原路径
        maze->ansMaze = maze->oriMaze;

        //2.用户选择起点和终点
        int startRow, startCol, desRow, desCol;
        startRow = ui->spinBox_startRow->value();
        startCol = ui->spinBox_startCol->value();
        desRow = ui->spinBox_desRow->value();
        desCol = ui->spinBox_desCol->value();

        //2.1考虑非法输入
        bool inputLegal = true;
        if (maze->oriMaze[startRow][startCol] == WALL){
            QMessageBox::critical(this,"输入错误","起点位置必须在 0 上!");
            inputLegal = false;
        }
        else if (maze->oriMaze[desRow][desCol] == WALL){
            QMessageBox::critical(this,"输入错误","终点位置必须在 0 上!");
            inputLegal = false;
        }

//        qDebug() << "33333" << endl;
        //3.输出迷宫路径
        if (inputLegal)
        {
            Status found = maze->findDes(startRow, startCol, desRow, desCol);//走迷宫！
            if (found){
                //显示结果
                maze->show(ui->textBrowser_ans);
                qDebug() << "迷宫路径成功输出" << endl;
            }
            else {
                //抛出异常
                qDebug() << "未找到终点"
                         << "宁输入的起点与终点不连通！" << endl;
                QMessageBox::critical(this,"未找到终点","宁输入的起点与终点不连通！");
            }
        }
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}
