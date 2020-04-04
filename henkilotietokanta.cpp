#include <henkilotietokanta.h>



henkiloTietokanta::henkiloTietokanta(const QString &tablename, QWidget *parent) :
    QWidget(parent)

{


    mainWindowSetup();

    createMenuActions();
    createMenu();


    addPtr = new addDialog(this);

    setSqlTableModel(tablename);
    showDatabase(model);

    createButtons();

    connectFunctions();

    setMainlayout();

}

henkiloTietokanta::~henkiloTietokanta()
{

    delete model;
    delete addPtr;
    delete lisaaIhminenButton;
    delete quitButton;
    delete revertButton;
    delete submitButton;
    delete removeRowButton;
    delete mainMenu;
    delete menuPalkki;
    delete saveToExel;
    delete etsiButton;


}
void henkiloTietokanta::mainWindowSetup()
{

    resize(490, 400);
    setWindowTitle(tr("Henkilötietokanta"));
    QPixmap pixMapIcon(":/resurssit/karsamakivaakuna.jpg");
    QIcon windowIcon(pixMapIcon);
    setWindowIcon(windowIcon);

}
void henkiloTietokanta::setSqlTableModel(const QString &tablename)
{
    //create viewable table
     model = new QSqlTableModel(this);
    model->setTable(tablename);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    model->select();

    std::string str1 = model->record().fieldName(0).toStdString();
    const char *lohko = str1.c_str();
    std::string str2 = model->record().fieldName(1).toStdString();
    const char *rivi = str2.c_str();
    std::string str3 = model->record().fieldName(2).toStdString();
    const char *paikka = str3.c_str();
    std::string str4 = model->record().fieldName(3).toStdString();
    const char *etunimi = str4.c_str();
    std::string str5 = model->record().fieldName(4).toStdString();
    const char *sukunimi = str5.c_str();
    std::string str6 = model->record().fieldName(5).toStdString();
    const char *burialmethod = str6.c_str();

    model->setHeaderData(0, Qt::Horizontal, tr(lohko));
    model->setHeaderData(1, Qt::Horizontal, tr(rivi));
    model->setHeaderData(2, Qt::Horizontal, tr(paikka));
    model->setHeaderData(3, Qt::Horizontal, tr(etunimi));
    model->setHeaderData(4, Qt::Horizontal, tr(sukunimi));
    model->setHeaderData(5, Qt::Horizontal, tr(burialmethod));

}
void henkiloTietokanta::showDatabase(QSqlTableModel *modeli)
{
    //show database
    view = new QTableView;
    view->setModel(modeli);
    view->resizeColumnsToContents();
    view->resizeRowsToContents();
    view->setSortingEnabled(true);




}

void henkiloTietokanta::setMainlayout()
{

    //add widgets and menubar
    mainLayout = new QHBoxLayout;
    mainLayout->setMenuBar(menuPalkki);
    mainLayout->addWidget(view);
    mainLayout->addWidget(buttonBox);
    setLayout(mainLayout);

}

void henkiloTietokanta::createButtons()
{

    lisaaIhminenButton = new QPushButton(tr("lisää"));
    lisaaIhminenButton->setDefault(true);
    submitButton = new QPushButton(tr("tallenna muutokset"));
    lisaaIhminenButton->setDefault(true);
    etsiButton = new QPushButton(tr(""));
    //etsiButton->setStyleSheet("background: white; ");
    removeRowButton = new QPushButton(tr(""));
    revertButton = new QPushButton(tr("&revert"));


    buttonBox = new QDialogButtonBox(Qt::Vertical);
    buttonBox->addButton(lisaaIhminenButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(submitButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(etsiButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(removeRowButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(revertButton, QDialogButtonBox::ActionRole);



    setButtonIcons();

    connect(etsiButton, &QPushButton::clicked, this, &henkiloTietokanta::search);
    connect(lisaaIhminenButton, &QPushButton::clicked,this, &henkiloTietokanta::add);
    connect(submitButton, &QPushButton::clicked, this, &henkiloTietokanta::submit);
    connect(removeRowButton, &QPushButton::clicked, this, &henkiloTietokanta::removeRow);
    connect(revertButton, &QPushButton::clicked,  this, &henkiloTietokanta::revertAll);



}

void henkiloTietokanta::setButtonIcons()
{
    //removebutton icon
    QPixmap pixmap(":/resurssit/bin-icon.jpg");
    QIcon buttonIcon(pixmap);
    removeRowButton->setIcon(buttonIcon);
    removeRowButton->setIconSize(pixmap.rect().size());

    //etsibutton icon
    QPixmap pixmap2(":/resurssit/etsi.jpg");
    QIcon buttonIcon2(pixmap2);

    etsiButton->setIcon(buttonIcon2);
    //etsiButton->setIconSize(pixmap2.rect().size());



}

void henkiloTietokanta::submit()

{

    qDebug() << model->database();
    model->database().transaction();
    if (model->submitAll()) {
        model->database().commit();
    } else {
        model->database().rollback();
        QMessageBox::warning(this, tr("henkilotietokanta"),
                             tr("The database reported an error: %1")
                             .arg(model->lastError().text()));
    }
}
void henkiloTietokanta::revertAll()
{
    model->revertAll();

    for(int i = 0; i < model->rowCount(); i++)
    {


        if(view->isRowHidden(i))
        {
            view->showRow(i);
        }
    }
}

void henkiloTietokanta::createMenu()
{

    menuPalkki = new QMenuBar;
    mainMenu = new QMenu(tr("&file"), this);
    menuPalkki->addMenu(mainMenu);
    mainMenu->addAction(saveToExel);
    mainMenu->addAction(quitButton);

}

void henkiloTietokanta::createMenuActions()
{
    saveToExel = new QAction(tr("&Tallenna"), this);
    connect(saveToExel, &QAction::triggered, this, &henkiloTietokanta::saveToExcel);

    quitButton = new QAction(tr("&Quit"), this);
    connect(quitButton, &QAction::triggered, this, &henkiloTietokanta::close);


}

void henkiloTietokanta::removeRow()

{

    QModelIndex index;

    QModelIndexList indexes = view->selectionModel()->selectedIndexes();

    for(int i = 0; i < indexes.count(); i++)
    {
        index = indexes.at(i);

    }


    msgBox.setText("Oot poistamassa henkilöä tietokannasta.");
    msgBox.setInformativeText("Ootko varma?");

    QPushButton *yesButton = msgBox.addButton(tr("kyllä"), QMessageBox::ActionRole);
    QPushButton *backButton = msgBox.addButton(tr("takaisin"), QMessageBox::RejectRole);
    msgBox.exec();
    if(msgBox.clickedButton() == yesButton)
    {
        model->removeRow(index.row());
        model->submitAll();
    }
    else if(msgBox.clickedButton() == backButton)
    {


    }


    delete yesButton;
    delete backButton;
}

void henkiloTietokanta::search()
{

    QInputDialog *inputDialog = new QInputDialog;

    QString text;
    inputDialog->setWindowFlags(inputDialog->windowFlags() & (~Qt::WindowContextHelpButtonHint));
    inputDialog->setWindowTitle("Etsi");

    inputDialog->setLabelText("Anna etsittava arvo");
    inputDialog->setOkButtonText("Etsi");
    inputDialog->setCancelButtonText("Takaisin");
    inputDialog->exec();


    text = inputDialog->textValue();
    if(!text.isEmpty())
    {
        for(int i = 0; i < model->rowCount(); i++)
        {

            if(model->record(i).value("Lohko") != text ||
                    model->record(i).value("Rivi") != text ||
                    model->record(i).value("Paikka") != text ||
                    model->record(i).value("Etunimi") != text ||
                    model->record(i).value("Sukunimi") != text ||
                    model->record(i).value("Hautaustapa") != text)
            {
                view->hideRow(i);
            }
            if(model->record(i).value("Lohko") == text ||
                    model->record(i).value("Rivi") == text ||
                    model->record(i).value("Paikka") == text ||
                    model->record(i).value("Etunimi") == text ||
                    model->record(i).value("Sukunimi") == text ||
                    model->record(i).value("Hautaustapa") == text)
            {
                view->showRow(i);
            }
        }
    }
    delete inputDialog;

}
void henkiloTietokanta::add()
{

    addPtr->show();

}
void henkiloTietokanta::aseta(QString &stretu, QString &strSuku, QString &lohkoN, QString &riviNum, QString &paikkaNum, bool &arkku)
{

    bool teeRecord;

    /*insert data to database...
    *..if user given row and place values are not already in the database
    */
    for(int i = 0;i < model->rowCount(); i++)
    {
        if(model->record(i).value("Rivi") == riviNum && model->record(i).value("Paikka") == paikkaNum)
        {
            QMessageBox::information(this, tr("Huomio"),tr("tarkista, onko samalla rivilla ja paikalla jo henkilo."));
            teeRecord = false;
            break;
        }
        else
        {
            teeRecord = true;
        }
    }

    if(teeRecord == true)
    {

        QSqlRecord newRecord = model->record();
        newRecord.setValue("lohko", lohkoN);
        newRecord.setValue("Rivi", riviNum);
        newRecord.setValue("Paikka", paikkaNum);
        newRecord.setValue("Etunimi", stretu);
        newRecord.setValue("Sukunimi", strSuku);

        if(arkku)
        {
            QString metodi = "Arkku";
            newRecord.setValue("hautaustapa", metodi);

        }
        else
        {
            QString uurna = "Uurna";
            newRecord.setValue("hautaustapa", uurna);

        }
        model->insertRecord(model->rowCount(), newRecord);
        emit lisaaTietokantaan();
    }


}
void henkiloTietokanta::connectFunctions()
{
    //add-window connects
    connect(this, SIGNAL(lisaaTietokantaan()), this, SLOT(submit()));
    connect(addPtr,SIGNAL(lahetaHenkilo(QString&, QString&, QString&, QString&, QString&, bool&)),this, SLOT(aseta(QString&, QString&, QString&,QString&, QString&, bool&)));

}

void henkiloTietokanta::saveToExcel()
{

    QString filename = QFileDialog::getSaveFileName(this, "Tallenna tiedosto", "Tiedoston nimi.csv","CSV files(.csv);;Zip files(.zip, *.7z)", 0, 0);


    QFile data(filename);
    if(data.open(QFile::WriteOnly|QFile::Truncate))
    {
        QTextStream output(&data);
        output        << model->record().fieldName(0)
                      << ";" << model->record().fieldName(1)
                      << ";" << model->record().fieldName(2)
                      << ";" << model->record().fieldName(3)
                      << ";" << model->record().fieldName(4)
                      << ";" << model->record().fieldName(5)
                      << endl;

        for(int i = 0; i <model->rowCount(); i++)
        {
            output        << model->record(i).value("Lohko").toInt()
                          << ";" << model->record(i).value("Rivi").toInt()
                          << ";" << model->record(i).value("Paikka").toInt()
                          << ";" << model->record(i).value("firstname").toString()
                          << ";" << model->record(i).value("lastname").toString()
                          << ";" << model->record(i).value("burialmethod").toString()
                          << endl;
        }


    }
    data.close();
}



