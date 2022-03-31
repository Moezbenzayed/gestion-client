#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include"client.h"
#include<QDate>
#include<QWidget>
#include<QMediaPlayer>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ajouter_clicked();

    void on_modifier_clicked();

    void on_supprimer_clicked();

    void on_rechercher_textChanged(const QString &arg1);

    void on_tri_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;
 client C;
};
#endif // MAINWINDOW_H
