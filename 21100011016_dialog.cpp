// Yunus Emre Ay - 21100011016

#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);


    arka_plan->setStyleSheet("border-image:url(:/arkaplan/images/back1.jpg);");
    arka_plan->setGeometry(0,100,1350,650);

    Karpuz_olustur_timer->start(350);
    connect(Karpuz_olustur_timer,&QTimer::timeout,this,&Dialog::Karpuz_olustur);


    Karpuz_kaydir_timer->start(15);
    connect(Karpuz_kaydir_timer,&QTimer::timeout,this,&Dialog::Karpuz_kaydir);


    saniye_azalt->start(1000);
    connect(saniye_azalt,&QTimer::timeout,this,&Dialog::kalan_sure);
    ui->Sure->setText(QString::number(sure));

    connect(ui->btn_karpuz,&QPushButton::clicked,[&](){meyve = "karpuz";}); // 'Karpuz' butonuna tiklandiginda, meyve = "karpuz" olur.
    connect(ui->btn_elma,&QPushButton::clicked,[&](){meyve = "elma";}); // 'elma' butonuna tiklandiginda, meyve = "elma" olur.
    connect(ui->btn_ananas,&QPushButton::clicked,[&](){meyve = "ananas";}); // 'ananas' butonuna tiklandiginda, meyve = "ananas" olur.
    connect(ui->btn_hcevizi,&QPushButton::clicked,[&](){meyve = "hcevizi";}); // 'hcevizi' butonuna tiklandiginda, meyve = "hcevizi" olur.
    connect(ui->btn_limon,&QPushButton::clicked,[&](){meyve = "limon";}); // 'limon' butonuna tiklandiginda, meyve = "limon" olur.
    connect(ui->btn_portakal,&QPushButton::clicked,[&](){meyve = "portakal";}); // 'portakal' butonuna tiklandiginda, meyve = "portakal" olur.
    connect(ui->btn_rastgele,&QPushButton::clicked,[&](){meyve = "rastgele";}); // 'rastgele' butonuna tiklandiginda, meyve = "rastgele" olur.

    connect(ui->btn_eksure,&QPushButton::clicked,[&](){sure+=10;}); // 'eksure' butonuna tiklandiginda, sure 10 sn artar.
    connect(ui->btn_oyunbitir,&QPushButton::clicked,[&](){sure=1;});  // 'oyunbitir' butonuna tiklandiginda, sure = 1 sn olur.

    connect(ui->btn_arkaplan1,&QPushButton::clicked,[&](){
        arka_plan->setStyleSheet("border-image:url(:/arkaplan/images/back1.jpg);");  // 'arkaplan1' butonuna tiklandiginda, arka_plan = "back1.jpg" olarak degistirilir.
    });

    connect(ui->btn_arkaplan2,&QPushButton::clicked,[&](){
        arka_plan->setStyleSheet("border-image:url(:/arkaplan/images/back2.jpg);");   // 'arkaplan2' butonuna tiklandiginda, arka_plan = "back2.jpg" olarak degistirilir.
    });

    connect(ui->btn_arkaplan3,&QPushButton::clicked,[&](){
        arka_plan->setStyleSheet("border-image:url(:/arkaplan/images/back3.jpg);");  // 'arkaplan3' butonuna tiklandiginda, arka_plan = "back3.jpg" olarak degistirilir.
    });

}
Dialog::~Dialog()
{
    delete ui;
}



void Dialog::Karpuz_olustur()
{
    QList <QString> meyve_setStyleSheet = {"border-image:url(:/meyve/images/karpuz.png);", "border-image:url(:/meyve/images/elma.png);",
"border-image:url(:/meyve/images/ananas.png);", "border-image:url(:/meyve/images/hindistancevizi.png);", "border-image:url(:/meyve/images/limon.png);",
"border-image:url(:/meyve/images/portakal.png);" }; // Liste, butun meyveleri icermektedir. Liste, "rastgele meyve" icin kullanilmaktadir.

    int rastgele_meyve;

    QFile konumlar(":/konumlar.txt");
    if(!konumlar.open(QIODevice::ReadOnly)) // Dosyayı "ReadOnly" modunda açar ve açılıp açılmadığını kontrol eder.
    {
        QMessageBox::critical(this,"Error!", konumlar.errorString()); // Dosya açılmama hata mesajını yazdırır.
        return;
    }

    QTextStream stream(&konumlar);
    QList <QString> konumlar_liste = stream.readAll().split("\r\n");
    int rastgele_karpuz = rand()%konumlar_liste.count();

    QPushButton* karpuz = new QPushButton(this);

    if (meyve == "karpuz") // 'meyve' degiskeninin icerigine gore, olusturulan butona "StyleSheet" atanmaktadir.
    {
        karpuz->setStyleSheet("border-image:url(:/meyve/images/karpuz.png);");
    }
    else if (meyve == "elma")
    {
        karpuz->setStyleSheet("border-image:url(:/meyve/images/elma.png);");
    }
    else if (meyve == "ananas")
    {
        karpuz->setStyleSheet("border-image:url(:/meyve/images/ananas.png);");
    }
    else if (meyve == "hcevizi")
    {
        karpuz->setStyleSheet("border-image:url(:/meyve/images/hindistancevizi.png);");
    }
    else if (meyve == "limon")
    {
        karpuz->setStyleSheet("border-image:url(:/meyve/images/limon.png);");
    }
    else if (meyve == "portakal")
    {
        karpuz->setStyleSheet("border-image:url(:/meyve/images/portakal.png);");
    }
    else if (meyve == "rastgele") // raskele "StyleSheet" atama islemi, yukarıda olusturulan "meyve_setStyleSheet" QList'inden random indis alarak yapilmaktadir.
    {
        rastgele_meyve = rand()%6;
        karpuz->setStyleSheet(meyve_setStyleSheet[rastgele_meyve]);
    }

    connect(karpuz,SIGNAL(clicked()),this,SLOT(Karpuz_kes()));
    karpuz->setGeometry(konumlar_liste[rastgele_karpuz].split(" ")[0].toInt(),konumlar_liste[rastgele_karpuz].split(" ")[1].toInt(),75,75);
    karpuz_listesi.push_back(karpuz);
    karpuz->show();

    konumlar.close();
}

void Dialog::Karpuz_kes()
{
    kesilen_karpuz_sayisi++;
    QPushButton *btn=qobject_cast<QPushButton*>(sender());
    QPushButton* karpuz_kes = new QPushButton(this);


    if(btn->styleSheet() == "border-image:url(:/meyve/images/karpuz.png);") // meyve "styleSheet"i ile kontrol edilerek, uygun "kesilen meyve" gorseli kullanilmaktadir.
        karpuz_kes->setStyleSheet("border-image:url(:/meyve/images/kesilmiskarpuz.png);");
    else if(btn->styleSheet() == "border-image:url(:/meyve/images/elma.png);")
        karpuz_kes->setStyleSheet("border-image:url(:/meyve/images/kesilmiselma.png);");
    else if(btn->styleSheet() == "border-image:url(:/meyve/images/ananas.png);")
        karpuz_kes->setStyleSheet("border-image:url(:/meyve/images/kesilmisananas.png);");
    else if(btn->styleSheet() == "border-image:url(:/meyve/images/hindistancevizi.png);")
        karpuz_kes->setStyleSheet("border-image:url(:/meyve/images/kesilmishindistancevizi.jpg);");
    else if(btn->styleSheet() == "border-image:url(:/meyve/images/limon.png);")
        karpuz_kes->setStyleSheet("border-image:url(:/meyve/images/kesilmislimon.png);");
    else if(btn->styleSheet() == "border-image:url(:/meyve/images/portakal.png);")
        karpuz_kes->setStyleSheet("border-image:url(:/meyve/images/kesilmisportakal.png);");

    karpuz_kes->setGeometry(btn->x(),btn->y(),75,75);
    btn->deleteLater();
    karpuz_listesi.removeOne(sender());
    karpuz_kes->show();

    ui->Kesilen_Karpuz_Sayisi->setText(QString::number(kesilen_karpuz_sayisi));

    QTimer *Kesilmis_karpuz_timer = new QTimer(this);
    Kesilmis_karpuz_timer->start(1000);
    Kesilmis_karpuz_timer->setSingleShot(true);
    connect(Kesilmis_karpuz_timer,&QTimer::timeout,[=](){
        karpuz_kes->deleteLater();
    });

}

void Dialog::kalan_sure()
{
    sure--;
    ui->Sure->setText(QString::number(sure));
    if(sure == 0)
    {
        Karpuz_olustur_timer->stop();
        Karpuz_kaydir_timer->stop();
        saniye_azalt->stop();

        QFile skorlar("skorlar.txt");
        if(!skorlar.open(QIODevice::ReadOnly))
        {
            QMessageBox::critical(this,"Error!", skorlar.errorString()); // Dosya açılmama hata mesajını yazdırır.
            return;
        }

        QTextStream stream(&skorlar);

        QList <QString> skorlar_liste = stream.readAll().split("\n");

        int max_skor = 0;
        foreach (QString skor, skorlar_liste)
        {
            if (skor.toInt()>max_skor)
            {
                max_skor = skor.toInt();
            }
        }

        skorlar.close();


        QFile skorlar2("skorlar.txt");
        if(!skorlar2.open(QIODevice::Append))
        {
            QMessageBox::critical(this,"Error!",skorlar2.errorString()); // Dosya açılmama hata mesajını yazdırır.
            return;
        }

        QTextStream stream2(&skorlar2);

        stream2 << "\n" + QString::number(kesilen_karpuz_sayisi) ;

        skorlar2.close();



        if(kesilen_karpuz_sayisi>max_skor)
        {
            int tiklama = QMessageBox::information(this, "Bilgi!", "Oyun Bitti! Tebrikler Maximum Skor Sizde!\nKesilen Meyve Sayısı: "+
                                                         QString::number(kesilen_karpuz_sayisi)+"\nKaçırılan Meyve Sayısı: "+
                                                         QString::number(kacirilan_karpuz_sayisi)+"\nMaximum Skor: "+
                                                                       QString::number(max_skor), QMessageBox::Ok);

            if (tiklama == QMessageBox::Ok)
                close();
        }
        else
        {
            int tiklama = QMessageBox::information(this, "Bilgi!", "Oyun Bitti! Maximum Skoru Geçemediniz!\nKesilen Meyve Sayısı: "+
                                                         QString::number(kesilen_karpuz_sayisi)+"\nKaçırılan Meyve Sayısı: "+
                                                         QString::number(kacirilan_karpuz_sayisi)+"\nMaximum Skor: "+
                                                         QString::number(max_skor), QMessageBox::Ok);

            if (tiklama == QMessageBox::Ok)
                close();
        }








    }
}

void Dialog::Karpuz_kaydir()
{
    int liste_boyutu = karpuz_listesi.count();

    for(int i=0; i<liste_boyutu; i++)
    {
        if(karpuz_listesi[i]->y() >= 750)
        {
            kacirilan_karpuz_sayisi++;
            ui->Kacirilan_Karpuz_Sayisi->setText(QString::number(kacirilan_karpuz_sayisi));
            kacan_karpuz_listesi.push_back(karpuz_listesi[i]);
        }
        else
            karpuz_listesi[i]->setGeometry(karpuz_listesi[i]->x(),karpuz_listesi[i]->y()+2,karpuz_listesi[i]->width(),karpuz_listesi[i]->height());
    }


    for(QPushButton* kacan_karpuz : kacan_karpuz_listesi)
    {
        karpuz_listesi.removeOne(kacan_karpuz);
    }

    kacan_karpuz_listesi.clear();

}

















