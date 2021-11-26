#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    iniUI();
    iniSig();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    switch (event->key()) {
    case Qt::Key_Up:
        ta->setCellWidget(1,2,new QLabel("上"));
        break;
    case Qt::Key_Down:
        ta->setCellWidget(1,2,new QLabel("下"));
        break;
    case Qt::Key_Left:
        leftMethod();
        break;
    case Qt::Key_Right:
        rightMethod();
        break;
    }
}

void MainWindow::iniUI()
{
    start=new QPushButton("开始新游戏");
    ta=new QTableWidget(4,4);
    ta->horizontalHeader()->setHidden(true);
    ta->verticalHeader()->setHidden(true);
    for(int i=0;i<4;i++){
        ta->setColumnWidth(i,100);
        ta->setRowHeight(i,100);
    }

    matrix.append(QVector<int>()<<0<<2<<0<<4);
    matrix.append(QVector<int>()<<0<<64<<8<<8);
    matrix.append(QVector<int>()<<0<<256<<0<<8);
    matrix.append(QVector<int>()<<32<<32<<128<<4);
    paintMatrix(matrix);

    QHBoxLayout *h1=new QHBoxLayout;
    h1->addWidget(start);
    h1->addItem(new QSpacerItem(400,1));
    QWidget *wid=new QWidget;
    QVBoxLayout *v1=new QVBoxLayout;
    v1->addLayout(h1);
    v1->addWidget(ta);
    wid->setLayout(v1);
    wid->setFocusPolicy(Qt::FocusPolicy::StrongFocus);
    this->setCentralWidget(wid);
    setWindowTitle("2048");
    resize(420,520);


}

void MainWindow::iniSig()
{

}

void MainWindow::upMethod()
{
    for(int i=0;i<4;i++){
        for (int j=3;j>=0;j--) {
        }
    }
}

void MainWindow::downMethod()
{

}

void MainWindow::leftMethod()
{
    QVector<int>* temp1;
    for(int i=0;i<4;i++){
        temp1=new QVector<int>;
        for(int j=3;j>=0;j++){
            temp1->append(matrix.at(i).at(j));
        }
       temp1=sortAndAdd(temp1);
       matrix.replace(i,*temp1);
    }
    paintMatrix(matrix);
}

void MainWindow::rightMethod()
{
    QVector<int>* temp1;
    for(int i=0;i<4;i++){
       temp1=new QVector<int>(matrix.at(i));
       temp1=sortAndAdd(temp1);
       matrix.replace(i,*temp1);
    }
    paintMatrix(matrix);

}

QVector<int>* MainWindow::sortAndAdd(QVector<int> *num)
{
    QStack<int> *stack=new QStack<int>;
    for (int i=3;i>=0;i--) {
        int t=num->at(i);
        if(t!=0&&stack->isEmpty()){
            stack->push(t);
        }
        else if(t!=0&&stack->isEmpty()==false){
            if(t==stack->top()){t=t+stack->pop();}
                stack->push(t);
        }
    }
    QVector<int> *re=new QVector<int>;
    for(int i=0;i<4-stack->size();i++){
        re->append(0);
    }
    int shuzi=stack->size();
    for(int i=0;i<shuzi;i++){
        re->append(stack->pop());
    }
    return re;
}

QLabel* MainWindow::addblock(int i)
{
    QLabel *l=new QLabel(QString::number(i));
    switch (i) {
    case 2:
    l->setStyleSheet("QLabel{font:30pt ; background-color:yellow}");
        break;
    case 4:
    l->setStyleSheet("QLabel{font:30pt ; background-color:blue}");
        break;
    case 8:
        l->setStyleSheet("QLabel{font:30pt ; background-color:green}");
        break;
    case 16:
        l->setStyleSheet("QLabel{font:30pt ; background-color:pink}");
        break;
    case 32:
        l->setStyleSheet("QLabel{font:30pt ; background-color:red}");
        break;
    case 64:
        l->setStyleSheet("QLabel{font:30pt ; background-color:gray}");
        break;
    case 128:
        l->setStyleSheet("QLabel{font:30pt ; background-color:rgb(255,128,0)}");
        break;
    case 256:
        l->setStyleSheet("QLabel{font:30pt ; background-color:purple}");
        break;
    case 512:
        l->setStyleSheet("QLabel{font:30pt ; background-color:rgb(88,234,1)}");
        break;
    case 1024:
        l->setStyleSheet("QLabel{font:30pt ; background-color:rgb(88,24,199)}");
        break;
    case 2048:
        l->setStyleSheet("QLabel{font:30pt ; background-color:rgb(13,93,80)}");
        break;
    default:
        l->setStyleSheet("QLabel{font:30pt ;}");
        break;
    }

    return l;
}

void MainWindow::paintMatrix(QVector<QVector<int> > ma)
{
    int temp;
    for(int i=0;i<4;i++){
        for (int j=0;j<4;j++) {
            temp=ma.at(i).at(j);
            ta->setCellWidget(i,j,addblock(temp));
        }
    }
}



