#include "adddialog.h"
#include "ui_adddialog.h"

addDialog::addDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addDialog)
{
    ui->setupUi(this);
    //default
    ui->arkkuBox->setChecked(true);

    ui->counterLaatikko->setVisible(false);
    ui->counterTeksti->setVisible(false);
}

addDialog::~addDialog()
{
    delete ui;
}
void addDialog::asetaCounter(int arvo)
{
    counter = arvo;

}
int addDialog::annaCounter() const
{
    return counter;
}

void addDialog::on_lahetaNappi_clicked()
{


    //get wanted data
    QString strEtu = ui->etuNimiLaatikko->text();
    QString strSuku = ui->sukunimiLaatikko->text();
    QString lohkoNum = ui->lohkoLaatikko->text();
    QString riviNum = ui->riviLaatikko->text();
    QString paikkaNum = ui->paikkaLaatikko->text();

    bool arkku = true;
    if(ui->uurnaBox->isChecked())
    {
        arkku = false;
    }

    //send
    emit lahetaHenkilo(strEtu, strSuku, lohkoNum, riviNum, paikkaNum, arkku);
    emit lisaaTietokantaan();

    //counter related
    counter++;
    QString laskuri = QString::number(annaCounter());
    ui->counterLaatikko->setText(laskuri);
    //show counter
    ui->counterTeksti->setVisible(true);
    ui->counterLaatikko->setVisible(true);

    //empty fields
    ui->etuNimiLaatikko->setText("");
    ui->lohkoLaatikko->setText("");
    ui->sukunimiLaatikko->setText("");
    ui->paikkaLaatikko->setText("");
    ui->riviLaatikko->setText("");
}

void addDialog::on_arkkuBox_clicked()
{

    ui->uurnaBox->setChecked(false);
}

void addDialog::on_uurnaBox_clicked()
{
    ui->arkkuBox->setChecked(false);
}


