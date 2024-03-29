#ifndef TARKISTATUNNUKSET_H
#define TARKISTATUNNUKSET_H

#include <QDialog>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QDebug>
#include <QMessageBox>
#include <QTimer>
#include <QGraphicsOpacityEffect>
#include <QPropertyAnimation>




namespace Ui {
class tarkistaTunnukset;
}

class tarkistaTunnukset : public QDialog
{
    Q_OBJECT

public:
    explicit tarkistaTunnukset(const QString &tablename, QWidget *parent);
    ~tarkistaTunnukset();

    bool getIdentification() const;

signals:
    void tunnusHaku(QString&, QString&);

private slots:
    void haeTunnukset(QString&, QString&);
    void on_pushButton_clicked();



private:

    Ui::tarkistaTunnukset *ui;
    bool identification = false;
    QSqlTableModel *model;
    void setupUi();
    void setUsedSqlTableModel(const QString &tablename);
    void setupInfoBoxes();
    void connects();
    void failInfoBoxAnimations(QLabel *Label);
    void setBackground();


};

#endif // TARKISTATUNNUKSET_H
