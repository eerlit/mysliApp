#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <adddialog.h>
//#include <tarkistatunnukset.h>
#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlTableModel>
#include <QTableView>
#include <QDialogButtonBox>
#include <QPushButton>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QtSql/QSqlError>
#include <connection.h>
#include <QtWidgets>
#include <QString>
#include <QDebug>
#include <QModelIndexList>
#include <QMenu>
#include <QBoxLayout>
#include <QmenuBar>

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(const QString &tablename, QWidget *parent = 0);




    ~MainWindow();

signals:



private slots:

    void submit();
    void removeRow();
    void add();
    void aseta(QString stretu, QString strSuku, QString lohkoN, QString riviNum, QString paikkaNum, bool arkku);
private:
        QPushButton *lisaaIhminenButton;
        QPushButton *submitButton;
        QPushButton *revertButton;
        QPushButton *quitButton;
        QPushButton *removeRowButton;
        QDialogButtonBox *buttonBox;
        QSqlTableModel *model;
        addDialog *addPtr;
        QMessageBox msgBox;
        QHBoxLayout *mainLayout;
        QMenuBar *menuPalkki;
        QTableView *view;
        QMenu *mainMenu;



};




#endif // MAINWINDOW_H
