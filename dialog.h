#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLabel>
#include <QPushButton>
#include <QList>
#include <QMessageBox>
#include <QFile>
#include <iostream>
#include <QTimer>
#include <QString>




QT_BEGIN_NAMESPACE
namespace Ui {
class Dialog;
}
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void Karpuz_kes();


private:
    Ui::Dialog *ui;

    QLabel *arka_plan = new QLabel(this);

    void Karpuz_olustur();
    void Karpuz_kaydir();
    void kalan_sure();

    QList <QPushButton*> karpuz_listesi;
    QList <QPushButton*> kacan_karpuz_listesi;

    int kesilen_karpuz_sayisi = 0;
    int kacirilan_karpuz_sayisi = 0;
    int sure = 30;

    QTimer *Karpuz_olustur_timer = new QTimer(this);
    QTimer *Karpuz_kaydir_timer = new QTimer(this);
    QTimer *saniye_azalt = new QTimer(this);

    QString meyve = "karpuz";

    QList <QString> meyveler = {"karpuz", "elma", "ananas", "hcevizi", "limon", "portakal"};

};
#endif // DIALOG_H
