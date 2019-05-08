#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "menugenkey.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ButtonGenerateKey_clicked();

    void on_ButtonExit_clicked();

private:
    Ui::MainWindow *ui;
    MenuGenKey* genKey;
};

#endif // MAINWINDOW_H
