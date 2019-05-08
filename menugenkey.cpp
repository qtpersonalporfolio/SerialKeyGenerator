#include <QMessageBox>
#include <QCheckBox>
#include <random>
#include "menugenkey.h"
#include "ui_menugenkey.h"

MenuGenKey::MenuGenKey(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MenuGenKey)
{
    ui->setupUi(this);
}

MenuGenKey::~MenuGenKey()
{
    delete ui;
}

QString MenuGenKey::MakeAlphabet()
{
    static const QString upperCase = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    static const QString lowerCase = "abcdefghijklmnopqrstuvwxyz";
    static const QString numbers = "0123456789";
    static const QString specialChars = "!@#$%^&*()_+-=;':\",./<>?~`";

    QString alphabet;
    if(ui->IncludeUppoerCase->isChecked())
    {
        alphabet += upperCase;
    }
    if(ui->IncludeLowerCase->isChecked())
    {
        alphabet += lowerCase;
    }
    if(ui->IncludeNumbers->isChecked())
    {
        alphabet += numbers;
    }
    if(ui->IncludeSpecial->isChecked())
    {
        alphabet += specialChars;
    }

    if(!ui->IncludeUppoerCase->isChecked() && !ui->IncludeLowerCase->isChecked() && !ui->IncludeNumbers->isChecked() && !ui->IncludeSpecial->isChecked())
    {
        QMessageBox::warning(this, "No Character Set Error", "You need to include at least one parameter");
        return alphabet;
    }

    return GenerateKey(alphabet);
}

QString MenuGenKey::GenerateKey(QString& alphabet)
{
    //Random number generator to generate a character
    //using the std number generator. Need to research on QT version
    std::random_device rd;
    std::mt19937 ValueGenerator(rd());
    std::uniform_int_distribution<> dist(0, alphabet.size() - 1);
    QString CDKey;
    int codeValue = 0;

    //Create the key using all the available characters
    for(int i = 0; i < ui->lineEdit->maxLength(); ++i)
    {
        codeValue = (dist(ValueGenerator));
        CDKey.push_back(alphabet.at(codeValue));
    }
    return CDKey;
}

void MenuGenKey::on_pushButton_clicked()
{
    ui->lineEdit->setText(MakeAlphabet());
}

void MenuGenKey::on_pushButton_2_clicked()
{
    MenuGenKey::close();
}
