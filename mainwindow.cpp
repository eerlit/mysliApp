#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent)

{

    createConnection();
    tunnusOlio = new tarkistaTunnukset("kayttajatable");


    tunnusOlio->show();

    tunnusOlio->exec();





    if(tunnusOlio->getIdentification())
    {
        tunnusOlio->close();
        tietokantaOlio = new henkiloTietokanta("henkilot");
        tietokantaOlio->show();
    }
}




MainWindow::~MainWindow()
{


    delete tunnusOlio;
    delete tietokantaOlio;


}

