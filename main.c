#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

 // fonksiyonlar

void baslangic_sayfasi();
void ava_yazisi();
void ava_cizim();
void ihtiyaclari_getir(char ihtiyaclar[][50],int duzeyler[]);
void ana_menu_cagir();
int secim_yap();        // cogu fonksiyonda yaptirilan secimler icin fonksiyon

// ihtiyac fonksiyonlarina etkiledikleri faktorleri  parametre olarak alma

void tokluk(int *tokluk,int *saglik,int *hijyen,int *tuvalet,int *enerji);
int adet_bul(char yemek_dizisi[],int adet);    // karakter dizisi icinden sayiyi almak icin

void uyku(int duzeyler[],int sure);   // uyku tum duzeyleri etkiledigi icin

void sevgi(int *sevgi,int *eglence);

void sosyallesme(int *sosyallesme,int *sevgi,int *eglence,int *tokluk,int *enerji);

void saglik(int *saglik,int *enerji);

void egitim(int *egitim,int *sosyallesme,int *tokluk,int *enerji);

void hijyen(int *hijyen,int *saglik,int *tokluk,int *enerji);

void tuvalet(int *tuvalet,int *saglik,int *hijyen);

void eglence(int *eglence,int *sosyallesme,int *uyku,int *tokluk,int *enerji);

void enerji(int *enerji);

void para_kazan(int *enerji,int *uyku,int *tokluk);

void r_yetenekler(int *yetenek_duzey);

// ihtiyaclar duzeyler ve parayi tanimlama

char ihtiyaclar[12][50] = {"TOKLUK","UYKU","SEVGI","SOSYALLESME","SAGLIK","EGITIM","HIJYEN","TUVALET","EGLENCE","ENERJI","PARA KAZANMA","ROBOTIK YETENEKLER"};
int duzeyler[12] = {25,50,25,25,50,25,50,20,30,30,0,0}; // ortalama 100 uzerinden
int r_para = 30; // robotik para tanimlamasi

// Robotik yetenekleri tanimlama

char ytek[4][150] = {"Elektriksel Onarim ( 20$ )","Elektrik Sistemleri ( 20$ )","Altyapi Yonetimi ( 30$ )","Guvenlik Algoritmalari ve Robotik Koruma ( 30$ )"};
char alinan_ytek[4][150] = {"-","-","-","-"}; // alinan robotik yetenekleri buraya atmak icin

int main()
{
    char nickname[75];
    baslangic_sayfasi(nickname);         // kullanicidan nickname alinmasi icin adresiyle fonksiyona gonderme

    ihtiyaclari_getir(ihtiyaclar,duzeyler);  // ihtiyaclar listesini ekrana yazdirma ve oyuna baslama

    return 0;
}

void baslangic_sayfasi(char nickname[75])  // bilgilendirme sonrasi kullanicidan nickname alarak oyunu baslatma
{
    printf("-AVA'nin dunyasina hos geldin!\n");     // bilgilendirme metinleri ve karsılama
    ava_yazisi();
    ava_cizim();

    printf("-Gunes patlamalarinin yol actigi firtinalar, dunyadaki tum elektrikleri keserek hayati durma noktasina getirdi.\n");
    printf("-Bilim insanlari cozum olarak, elektirige ihtiyac duymayan bir yari insan yari robot olan AVA'yi urettiler.\n");
    printf("-AVA,robotik para kazanarak becerilerini gelistirmeli,yasamsal fonksiyonlarini surdurmeli ve dunyayi kurtarmak icin\n mucadele etmelidir.\n");
    printf("-Haydi AVA'nin rehberi ol ve unutma, her bir tercih AVA'nin ve dunyanin kaderini etkileyecektir!\n");
    printf("\nNOT:Robotik yetenekler 100'e ulastiginda AVA dunyayi kurtaracak ve dunyayi eski haline dondurecektir!!!\n");

    printf("\nOyuna baslamak icin bir kullanici adi gir ve enter'a bas: ");  // nickname alma;
    gets(nickname);
    printf("\n\n");

}

void ava_yazisi()
{
    printf("------------------------------------------------------------\n");
    printf("***                                                      ***\n");
    printf("***                       AVA                            ***\n");
    printf("***                                                      ***\n");
    printf("------------------------------------------------------------\n\n");

}

void ava_cizim()    // ava karakterinin cizimi
{
    printf("             \\      /  \n");
    printf("              .----.   \n");
    printf("          - -|      |- -\n");
    printf("             |      |   \n");
    printf("              \\____/   \n");
    printf("            ___|  |___  \n");
    printf("           (          ) \n");
    printf("            |         | \n");
    printf("             \\  ==  /   \n");
    printf("          ___|-----|___\n");
    printf("         |   |     |   |\n");
    printf("         |   |     |   |\n\n");
}

void  ihtiyaclari_getir(char ihtiyaclar[][50],int duzeyler[])
{
    ava_yazisi();
    printf("ROBOTIK PARA: %d$\n\n",r_para);   // ana menude olmasi gerekenleri yazdirma
    for(int i=1;i<11;i++)
    {
        printf("%2d --> %s: %d\n",i,ihtiyaclar[i-1],duzeyler[i-1]);  // ihtiyac listesi ve duzeylerini yazdirma
    }
    printf("\n11 --> PARA KAZAN ( Islere gozat )\n");
    printf("----------------------------------------\n");
    printf("     12 --> ROBOTIK YETENEKLER: %d      \n",duzeyler[11]);
    printf("----------------------------------------\n");


    // oyunu kapat
    printf("13 --> OYUNDAN CIK\n\n");


    int ihtiyac_no;

    do{
        printf("\nYapmak istediginiz ihtiyacin / aktivitenin numarasini giriniz: ");   // kullanicinin dogru deger girmesi icin dongu
        scanf("%d",&ihtiyac_no);
        fflush(stdin);

    }while((ihtiyac_no > 13) || (ihtiyac_no<=0));


    int sure;
    switch(ihtiyac_no){                 //  ilgili duzeyleri ilgili ihtiyac fonksiyonuna gönderme

        case 1:
            tokluk(&duzeyler[0],&duzeyler[4],&duzeyler[6],&duzeyler[7],&duzeyler[9]);
            break;
        case 2:
            printf("\nNOT:Uyku modunda diger yasam fonksiyonlari da etkilenecektir!!!\n\n");
            printf("Uyku moduna alinmak istenen sureyi saat(onerilen:6) cinsinden giriniz: ");
            scanf("%d",&sure);
            uyku(duzeyler,sure);
            break;
        case 3:
            sevgi(&duzeyler[2],&duzeyler[8]);
            break;
        case 4:
            sosyallesme(&duzeyler[3],&duzeyler[2],&duzeyler[8],&duzeyler[0],&duzeyler[9]);
            break;
        case 5:
            saglik(&duzeyler[4],&duzeyler[9]);
            break;
        case 6:
            egitim(&duzeyler[5],&duzeyler[3],&duzeyler[0],&duzeyler[9]);
            break;
        case 7:
            hijyen(&duzeyler[6],&duzeyler[4],&duzeyler[0],&duzeyler[9]);
            break;
        case 8:
            tuvalet(&duzeyler[7],&duzeyler[4],&duzeyler[6]);
            break;
        case 9:
            eglence(&duzeyler[8],&duzeyler[3],&duzeyler[1],&duzeyler[0],&duzeyler[9]);
            break;
        case 10:
            enerji(&duzeyler[9]);
            break;
        case 11:
            para_kazan(&duzeyler[9],&duzeyler[1],&duzeyler[0]);
            break;
        case 12:
            r_yetenekler(&duzeyler[11]);
            break;
        case 13:
            printf("OYUN BITTI\n");        // do while dongusunde kontrolleri sagladigimiz icin default kullanmaya gerek kalmadi
            exit(1);
    }
}

void ana_menu_cagir()
{
    // oyunun sonlanip sonlanmadigini ogrenme
        //tokluk duzeyi
        if(duzeyler[0] <= 0)
        {
            printf("\n\nAVA acliktan tum islevlerini kaybetti ve oldu!!!\n\n");
            exit(1);
        }
        else if(duzeyler[0] > 100)
        {
            printf("\n\nAVA tokluktan dolayi patladi!!!\n\n");
            exit(1);
        }
        //enerji duzeyi
        if(duzeyler[9] < -10)
        {
            printf("\n\nAVA enerjisizlikten tum islevlerini kaybetti ve oldu!!!\n\n");
            exit(1);
        }
        else if(duzeyler[9] >= 200)
        {
            printf("\n\nAVA fazla enerjiden dolayi patladi!!!\n\n");
            exit(1);
        }
        // saglik
        if(duzeyler[4] <= 0)
        {
            printf("\n\nAVA sagligindan dolayi tum islevlerini kaybetti ve oldu!!!\n\n");
            exit(1);
        }
        // oyunu basarili bitirme
        if(duzeyler[11] == 100)
        {
            printf("\n\n-TEBRIKLER\n\n-AVA patlamalar sonucu olusan elektrik sorunlarini cozerek dunyayi kurtardi.\n-Boylece dunya eski haline dondu ve insanlar yasamlarina devam etmeye basladilar\n");
            exit(1);
        }

        // tuvalet
        if(duzeyler[9] <= -100)
        {
            printf("\n\nAVA tuvaletini yapmadigindan patladi!!!\n\n");
            exit(1);
        }

        // para 0 dan asagi gitmemeli
        if(r_para < 0)
        {
            printf("\n\nRobotik parayi yonetemediniz ve robot sistemi coktu, AVA oldu!!!\n\n");
            exit(1);
        }

    // oyun devam ediyorsa
    int secilen_sayi;
    printf("1 harici deger girmeniz durumunda oyun kapanacaktir.\n");
    printf("Ana menuye donmek icin 1 gir ve enter'a bas:");
    scanf("%d",&secilen_sayi);
    if(secilen_sayi == 1)
    {
        ihtiyaclari_getir(ihtiyaclar,duzeyler);
    }
    else
    {
        printf("Hatali deger girdiginiz icin oyun sonlandi!!!\n");
        exit(1);
    }
}

void tokluk(int *tokluk,int *saglik,int *hijyen,int *tuvalet,int *enerji)
{
    fflush(stdin);
    char yemek[75];                  // yemek cesidi ve adedi almak icin
    int adet=0;          // yemek dizisindeki adeti sayi olarak almak icin

    printf("\n--> Yuksek proteinli bar ye. ( adet 10$ )\n--> Kalori hap al. ( adet 10$ )\n--> Tokluk iksiri ic. ( adet 10$ )\n\n");
    printf("Lutfen birini secin ve once adet sonra cesit olmak uzere yazin: ");
    gets(yemek);
    fflush(stdin);

    // duzeyleri ayarlama (100 uzerinden oldugu icin * 10)
    adet = adet_bul(yemek,adet)*10;

    (*tokluk) += adet;
    (*saglik) += adet/3;
    (*tuvalet) += adet/2;
    (*enerji) += adet/2;
    r_para-=(adet);
    printf("\n%s yeme/icme islemi basarili.\n",yemek);
    printf("--> tokluk: +%d, saglik: +%d, tuvalet: +%d, enerji: +%d, robotik para: -%d$\n\n",adet,adet/3,adet/2,adet/2,adet);


    ana_menu_cagir();
}

int adet_bul(char yemek_dizisi[],int adet)   // gelen karakter dizisindeki sayiyi al
{
    for(int i=0;i<strlen(yemek_dizisi);i++)
        {
            if(isdigit(yemek_dizisi[i]))
            {
                adet = atoi(&yemek_dizisi[i]);
            }

        }
        return adet;
}

void uyku(int duzeyler[],int sure)   // recursive fonksiyonla her uyunan saat icin uyku ve diger ihtiyaclari arttirma/azaltma
{
    if(sure > 0)
    {

        for(int i=0;i<10;i++)
        {
           if(i == 1)  // uyku
           {
               duzeyler[i] -= 5;
           }
           else if(i == 9)  // enerji
           {
               duzeyler[i] +=3;
           }
           else if(i == 0)   // tokluk
           {
               duzeyler[i] -=3;
           }
           else if(i == 7)   // tuvalet
           {
               duzeyler[i] +=3;
           }
           else  // diger ihtiyaclar;
           {
               duzeyler[i] -=1;
           }
        }
        uyku(duzeyler,sure-1);
    }
    else
    {
        printf("\nUyku modu islemi basarili!!!\n\n");
        ana_menu_cagir();
    }
}

int secim_yap()  // cogu fonksiyonda yaptirilan secimler icin fonksiyon
{
    int secim_no;
    printf("Lutfen bir secim yapiniz: "),
    scanf("%d",&secim_no);

    return secim_no;
}

void sevgi(int *sevgi,int *eglence)
{
    printf("\n1 ---> Sevgi iksiri ic.( 2 kat etki ve 10$ ucret )\n2 ---> Sevgili edin.( ucretsiz )\n3 ---> Hayvan sahiplen.( ucretsiz )\n\n");

    int secim_no = secim_yap();

    if(secim_no == 1)
    {
        (*sevgi) += 20;
        (*eglence) += 10;
        r_para -= 10;
        printf("\n--> sevgi:+10, eglence: +10, robotik para: -10$\n");
    }
    else if((secim_no == 2) || (secim_no ==3))
    {
        (*sevgi) += 10;
        (*eglence) += 10;
        printf("sevgi --> +10, eglence --> +10\n\n");
    }
    else
    {
        printf("Hatali bir sayi girdiniz!!!\n");
    }
    ana_menu_cagir();

}

void sosyallesme(int *sosyallesme,int *sevgi,int *eglence,int *tokluk, int *enerji)
{
    printf("\n1 ---> Sanal konferanslara katil.( 2 kat etki ve 10$ ucret )\n2 ---> Robot bulusma etkinligine katil. ( 2 kat etki ve 10$ ucret )\n3 ---> Tiyatroya git.( 2 kat etki ve 10$ ucret )\n");
    printf("4 ---> Arkadas edin. ( ucretsiz )\n5 ---> Arkadas veya sevgiliyle bulus. ( ucretsiz )\n\n");

    int secim_no = secim_yap();

    if((secim_no>0) && (secim_no <4) )
    {
        (*sosyallesme) += 20;
        (*sevgi) +=5;
        (*eglence) +=10;
        (*tokluk) -=5;
        (*enerji) -=5;
        r_para -= 10;
        printf("\n--> sosyallesme: +20, sevgi: +5, eglence: +10, tokluk: -5, enerji: -5, robotik para: -10$\n\n");

    }
    else if((secim_no == 4) || (secim_no == 5))
    {
        (*sosyallesme) += 10;
        (*sevgi) +=5;
        (*eglence) +=5;
        (*tokluk) -=10;
        (*enerji) -=10;
        printf("\n--> sosyallesme: +10, sevgi: +5, tokluk: -10, enerji: -10, eglence: +5\n\n");

    }
    else
    {
        printf("Hatali bir sayi girdiniz!!!\n");
    }
    ana_menu_cagir();
}

void saglik(int *saglik,int *enerji)
{
    printf("\n1 ---> Biyonik onarim yap. ( 10$ )\n2 ---> Guclu saglik iksiri ic. ( 10$ )\n3 ---> Robotik parcalari onar. ( 10$ )\n\n");

    int secim_no = secim_yap();

    if((secim_no>0) && (secim_no<4))
    {
        (*saglik) += 10;
        (*enerji) += 5;
        r_para -= 10;
        printf("\n--> saglik: +10, enerji: +5, robotik para: -10$\n\n");
    }
    else
    {
        printf("Hatali bir sayi girdiniz!!!\n\n");
    }
    ana_menu_cagir();
}

void egitim(int *egitim,int *sosyallesme,int *tokluk, int *enerji)
{
    printf("\n1 ---> Sanal labaratuvar egitimi al. ( ucretsiz )\n2 ---> Dijital kitap oku. ( ucretsiz )\n3 ---> Farkli dil ogren. ( ucretsiz )\n\n");

    int secim_no = secim_yap();

    if((secim_no>0) && (secim_no<4))
    {
        (*egitim) += 10;
        (*sosyallesme) += 5;
        (*tokluk) -=5;
        (*enerji) -=5;
        printf("\n--> egitim: +10, sosyallesme: +5, tokluk: -5, enerji: -5\n\n");
    }
    else
    {
        printf("Hatali bir sayi girdiniz!!!\n\n");
    }
    ana_menu_cagir();
}

void hijyen(int *hijyen,int *saglik,int *tokluk,int *enerji)
{
    printf("\n1 ---> Kiyafet degistir. ( ucretsiz )\n2 ---> Dus al. ( ucretsiz )\n3 ---> Dis bakimi yap. ( ucretsiz )\n\n");

    int secim_no = secim_yap();

    if((secim_no>0) && (secim_no<4))
    {
        (*hijyen) += 10;
        (*saglik) += 2;
        (*tokluk) -= 5;
        (*enerji) -= 5;
        printf("\n--> hijyen: +10, saglik: +2,vtokluk: -5, enerji: -5\n\n");
    }
    else
    {
        printf("\nHatali bir sayi girdiniz!!!\n\n");
    }
    ana_menu_cagir();
}
void tuvalet(int *tuvalet,int *saglik,int *hijyen)
{
    printf("\n1 ---> Biyonik tuvalet yap. ( ucretsiz )\n2 ---> Atiklari depondan at. ( ucretsiz )\n3 ---> Kirli sivilari dok. ( ucretsiz )\n\n");

    int secim_no = secim_yap();

    if((secim_no>0) && (secim_no<4))
    {
        (*tuvalet) -= 10;
        (*saglik) += 1;
        (*hijyen) -= 2;
        printf("\n--> tuvalet: -10, saglik: +1, hijyen: -2\n\n");
    }
    else
    {
        printf("\nHatali bir sayi girdiniz!!!\n\n");
    }
    ana_menu_cagir();
}
void eglence(int *eglence,int *sosyallesme,int *uyku,int *tokluk,int *enerji)
{
    printf("\n1 ---> Hologram konser izle.( 2 kat etki ve 10$ ucret )\n2 ---> Sanal gerceklik oyunlari oyna.( 2 kat etki ve 10$ ucret )\n3 ---> Dans et. ( ucretsiz )\n4 ---> Film izle. ( ucretsiz ) \n\n");

    fflush(stdin);
    int secim_no = secim_yap();

    if((secim_no == 1) || (secim_no == 2))
    {
        (*eglence) += 20;
        (*sosyallesme) += 5;
        (*uyku) += 10;
        (*tokluk) -= 5;
        (*enerji) -=5;
        printf("\n--> eglence: +20, sosyallesme: +5, uyku: +10, tokluk: -5, enerji: -5\n\n");
    }
    else if((secim_no == 3) || (secim_no == 4))
    {
        (*eglence) += 10;
        (*sosyallesme) += 2;
        (*uyku) += 10;
        (*tokluk) -= 3;
        (*enerji) -= 3;
        printf("\n--> eglence: +10, sosyallesme: +2, uyku: +10, tokluk: -3, enerji: -3\n\n");
    }
    else
    {
        printf("\nHatali bir sayi girdiniz!!!\n\n");
    }
    ana_menu_cagir();
}

void enerji(int *enerji)
{
    fflush(stdin);
    char cesit[75];                  //  cesidi ve adedi almak icin
    int adet=0;          // diziden adeti sayi olarak almak icin

    printf("\n--> Enerji cubugu ye. ( adet 10$ )\n--> Mini batarya kullan. ( adet 10$ )\n--> Enerji icecegi ic. ( adet 10$ )\n\n");
    printf("Lutfen birini secin ve once adet sonra cesit olmak uzere yazin: ");
    gets(cesit);

    // duzeyleri ayarlama (100 uzerinden oldugu icin * 10)
    adet = adet_bul(cesit,adet)*10;

    (*enerji) += adet;
    r_para-=(adet);
    printf("\nIslem basarili.\n");
    printf("--> enerji: +%d, robotik para: -%d$\n\n",adet,adet);
    ana_menu_cagir();
}

void para_kazan(int *enerji,int *uyku,int *tokluk)
{
    printf("\n1 ---> Insanlara guvenlik sistemleri tasarla. ( 12$ )\n2 ---> Enerji panalleri kur. ( 12$ )\n3 ---> Arastirmalara katil. ( 20$ )\n4 ---> Yenilenebilir enerji projelerinde calis. ( 20$ )\n\n");

    int secim_no = secim_yap();

    if((secim_no ==1) || (secim_no == 2))
    {
        r_para += 12;
        (*enerji) -=10;
        (*uyku) +=10;
        (*tokluk) -=5;
        printf("\n12 ROBOTIK PARA KAZANILDI!!!\n\n");
    }
    else if((secim_no == 3) || (secim_no == 4))
    {
        r_para += 20;
        (*enerji) -=12;
        (*uyku) +=12;
        (*tokluk) -=8;
        printf("\n20 ROBOTIK PARA KAZANILDI!!!\n\n");
    }
    else
    {
        printf("\nHatali bir sayi girdiniz!!!\n\n");
    }
    ana_menu_cagir();
}

void r_yetenekler(int *yetenek_duzey)
{
    printf("\nROBOTIK YETENEK AL\n");   // yazdirma islenleri
    for(int i=0;i<4;i++)
    {
        printf("\n%d --> %s",i+1,ytek[i]);
    }
    printf("\n\nALINAN ROBOTIK YETENEKLER\n");
    for(int i=0;i<4;i++)
    {
        printf("\n%d --> %s",i+1,alinan_ytek[i]);
    }
    printf("\n\n");

    int secim_no = secim_yap();

    if((secim_no == 1) || (secim_no == 2))
    {
        r_para -=20;
        strcpy(alinan_ytek[secim_no-1],ytek[secim_no-1]);     // alinan yetenekleri strcpy ile diger diziye atma
        strcpy(ytek[secim_no-1],"-");
        (*yetenek_duzey) +=20;
        printf("\n%s becerisine sahip olundu!!!\n\n",alinan_ytek[secim_no-1]);
    }
    else if((secim_no == 3) || (secim_no == 4))
    {
        r_para -=30;
        strcpy(alinan_ytek[secim_no-1],ytek[secim_no-1]);          // alinan yetenekleri strcpy ile diger diziye atma
        strcpy(ytek[secim_no-1],"-");
        (*yetenek_duzey) +=30;
        printf("\n%s becerisine sahip olundu!!!\n\n",alinan_ytek[secim_no-1]);
    }
    else
    {
        printf("\nHatali bir sayi girdiniz!!!\n\n");
    }
    ana_menu_cagir();
}
