#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTableWidget>
#include <QHeaderView>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QPushButton>
#include <QSpacerItem>
#include <QKeyEvent>
#include <QDebug>
#include <QStack>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;
    void iniUI();
    void iniSig();

    QPushButton *start;
    QTableWidget *ta;
    QVector<QVector<int>> matrix;
    void upMethod();
    void downMethod();
    void leftMethod();
    void rightMethod();
    QVector<int>* sortAndAdd(QVector<int> *num);
    QLabel* addblock(int i);
    void paintMatrix(QVector<QVector<int>> ma);
};
#endif // MAINWINDOW_H
