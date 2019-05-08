#ifndef MENUGENKEY_H
#define MENUGENKEY_H

#include <QDialog>
#include <QString>

namespace Ui {
class MenuGenKey;
}

class MenuGenKey : public QDialog
{
    Q_OBJECT

public:
    explicit MenuGenKey(QWidget *parent = nullptr);
    ~MenuGenKey();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MenuGenKey *ui;
    QString MakeAlphabet();
    QString GenerateKey(QString& alphabet);
};

#endif // MENUGENKEY_H
