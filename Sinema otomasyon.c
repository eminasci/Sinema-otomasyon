#include <stdio.h>
#include <stdlib.h>

typedef struct
{//salonlar
    char Red[5][50];
    char Green[5][50];
    char Blue[5][50];
}Salonlar;
typedef enum
{
   ogrenci=1,
   tam
}ucretler;

    //global tanimlamalar
    char kullanici_adi[20];
    char sifre[20];
    char kontrol_kullanici_adi[20];
    char kontrol_sifre[20];
    char kontroldosya_kullanici_adi[20];
    char kontroldosya_sifre[20];
    int menu_secimi;
    char salon_secimi;
    int hasilat;
    int matine;
    int i,j,k;
    int koltuknum=0;
    int odemesekli;
    int tutar=0;
    int koltuksayaci=0;

void odeme()
{
    printf("\nOdeme sekliniz?\n(Ogrenci icin 1'e Tam icin 2'ye basin)\n");
    scanf(" %d",&odemesekli);
    if(odemesekli == ogrenci )
    {
        tutar = 20;
        hasilat+=tutar;
    }
    else if(odemesekli == tam)
    {
        tutar = 30;
        hasilat+=tutar;
    }
    printf("\nRezarvasyon Bilgileri:\n");
    printf("\n\n%d numarali koltuga rezerve yapilmistir.\n",koltuknum+1);
    printf("\nUcretiniz %d liradir.\n",tutar);
    printf("\nANA MENUYE DONULUYOR\n\n");
    sleep(1);
}



void login()
{
    printf("Kullanici Adinizi Giriniz=");
    scanf("%s",&kontrol_kullanici_adi);
    printf("Sifrenizi Giriniz=");
    scanf("%s",&kontrol_sifre);

}
void ana_menu()
{
    printf("SINEMA REZERVASYON SISTEMINE HOS GELDINIZ\n");
    printf("\nRezervasyon yapmak icin 1'e basiniz\n");
    printf("Hasilati ogrenmek icin 2'ye basiniz\n");
    printf("Izlenme miktarlari icin 3'e basiniz\n");
    scanf("%d",&menu_secimi);
}

int main()
{
    //dosya login
    char kullanici_adi[20];
    char sifre[20];
     Salonlar salon;
    ucretler ucret;
    Salonlar *psalon;
    psalon= &salon;

    FILE *fhasilat;
    fhasilat=fopen("hasilat.txt","r");
    fscanf(fhasilat,"%d",&hasilat);
    fclose(fhasilat);

    FILE *fkoltukred;
    fkoltukred=fopen("koltukred.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Red[j][k] = getc(fkoltukred) ;
        }

    }
    fclose(fkoltukred);

    FILE *fkoltukgreen;
    fkoltukgreen=fopen("koltukgreen.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Green[j][k] = getc(fkoltukgreen) ;
        }

    }
    fclose(fkoltukgreen);

     FILE *fkoltukblue;
    fkoltukblue=fopen("koltukblue.txt","r");
    for(j=0;j<5;j++)
    {
        for(k=0;k<50;k++)
        {
            psalon->Blue[j][k] = getc(fkoltukblue) ;
        }

    }
    fclose(fkoltukblue);



    FILE *psifre;
    psifre = fopen("sifre.txt","w+");
    if(psifre==NULL)
    {
        printf("Lutfen bir kullanici adi ile sifre giriniz\n");
        exit(-1);

    }
    else

    {
        printf("Kayit olmak icin kullanici adiyla sifre girmeniz yeterlidir...\n");
        sleep(1);
        printf("Kullanici Adi=");
        scanf("%s",&kullanici_adi);
        printf("\n Sifre=");
        scanf("%s",&sifre);
        fprintf(psifre,"%s %s",&kullanici_adi,&sifre);
        printf("kaydiniz gerceklestirilmistir...\n");
        sleep(1);
       giris_ekrani:
        login();
        fclose(psifre);

        if (strcmp(kullanici_adi,kontrol_kullanici_adi) == 0)
        {
             if (strcmp(sifre,kontrol_sifre) == 0)
            {
                printf("Sisteme giris yapiliyor...\n");
                sleep(1);
                anamenu:
                ana_menu();
                switch(menu_secimi)
                {
                case 1:
                    {
                        printf("\nHangi salona rezarvasyon yapmak istersiniz?\n(Red icin R/r\nGreen icin G/g\nBlue icin B/b)\n");
                        scanf(" %c",&salon_secimi);
                        switch(salon_secimi)
                        {
                            case 'R':
                            case 'r':

                            printf("\n\nKac numarali matinede rezarvasyon yapmak istersiniz?\n(1/2/3/4/5)");
                            scanf("%d",&matine);
                            for(i=matine-1;i<matine;i++)
                                {
                                for(j=0;j<50;j++)
                                    {
                                        if(psalon->Red[i][j] == '0')
                                        {
                                            psalon->Red[i][j] = 1;
                                            koltuknum = j;
                                            break;
                                        }
                                    else
                                        continue;
                                    }
                                }

                            odeme();
                            fkoltukred=fopen("koltukred.txt","w+");
                            for(j=0;j<5;j++)
                            {
                                for(k=0;k<50;k++)
                                {
                                    if(psalon->Red[j][k] == '0')
                                    fputc('0',fkoltukred);
                                else
                                    fputc('1',fkoltukred);
                                }

                            }
                            fclose(fkoltukred);

                            fhasilat=fopen("hasilat.txt","w+");

                            fprintf(fhasilat,"%d",hasilat);

                            fclose(fhasilat);

                            break;
                            break;

                            case 'B':
                            case 'b':
                                printf("\n\nKac numarali matinede rezarvasyon yapmak istersiniz?\n(1/2/3/4/5)");
                                scanf("%d",&matine);
                                for(i=matine-1;i<matine;i++)
                                {
                                    for(j=0;j<50;j++)
                                    {
                                        if(psalon->Blue[i][j] == '0')
                                        {
                                            psalon->Blue[i][j] = 1;
                                            koltuknum = j;
                                            break;
                                        }
                                        else
                                            continue;

                                    }
                                }
                                odeme();

                                fkoltukblue=fopen("koltukblue.txt","w+");
                                for(j=0;j<5;j++)
                                    {
                                    for(k=0;k<50;k++)
                                    {
                                        if(psalon->Blue[j][k] == '0')
                                        fputc('0',fkoltukblue);
                                    else
                                        fputc('1',fkoltukblue);
                                    }

                                }
                                fclose(fkoltukblue);
                                fhasilat=fopen("hasilat.txt","w+");

                                fprintf(fhasilat,"%d",hasilat);

                                fclose(fhasilat);

                                break;
                                break;

                            case 'G':
                            case 'g':
                                printf("\n\nKac numarali matinede rezarvasyon yapmak istersiniz?\n(1/2/3/4/5)");
                                scanf("%d",&matine);
                                for(i=matine-1;i<matine;i++)
                                {
                                    for(j=0;j<50;j++)
                                    {
                                        if(psalon->Green[i][j] == '0')
                                        {
                                            psalon->Green[i][j] = 1;
                                            koltuknum = j;
                                            break;
                                        }
                                        else
                                            continue;
                                    }
                                }
                                odeme();
                                 fkoltukgreen=fopen("koltukgreen.txt","w+");
                                    for(j=0;j<5;j++)
                                    {
                                        for(k=0;k<50;k++)
                                    {
                                        if(psalon->Green[j][k] == '0')
                                            fputc('0',fkoltukgreen);
                                        else
                                            fputc('1',fkoltukgreen);
                                    }

                                    }
                                fclose(fkoltukgreen);
                                fhasilat=fopen("hasilat.txt","w+");

                                fprintf(fhasilat,"%d",hasilat);
                                close(fhasilat);

                                break;
                                break;

                        default:
                            printf("\nYanlis secim yaptiniz.\n");
                            break;

                    }
                    goto anamenu;


                        }
                            case 2:
                                fhasilat=fopen("hasilat.txt","r");
                                fscanf(fhasilat,"%d",&hasilat);
                                fclose(fhasilat);
                                printf("\nToplam hasilat : %d TL.\n",hasilat);
                                printf("\n ANA MENUYE DONULUYOR\n");
                                sleep(1);
                               goto anamenu;
                            case 3:
                                   printf("\nRed salonu izin izlenme bilgileri,\n");
                                    for(i=0;i<5;i++)
                                    {
                                        for(j=0;j<50;j++)
                                        {
                                            if(psalon->Red[i][j] == '1')
                                            {
                                                koltuksayaci++;

                                            }
                                        }
                                        printf("\n%d. Matinede %d izlenme.\n",i+1,koltuksayaci);
                                        koltuksayaci=0;
                                    }
                                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

                                    printf("\nGreen salonu izin izlenme bilgileri,\n");
                                    for(i=0;i<5;i++)
                                    {
                                        for(j=0;j<50;j++)
                                        {
                                            if(psalon->Green[i][j] == '1')
                                            {
                                                koltuksayaci++;

                                            }
                                        }
                                        printf("\n%d. Matinede %d izlenme.\n",i+1,koltuksayaci);
                                        koltuksayaci=0;
                                    }

                                    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");

                                    printf("\nBlue salonu izin izlenme bilgileri,\n");
                                    for(i=0;i<5;i++)
                                    {
                                        for(j=0;j<50;j++)
                                        {
                                            if(psalon->Blue[i][j] == '1')
                                            {
                                                koltuksayaci++;

                                            }
                                        }
                                        printf("\n%d. Matinede %d izlenme.\n",i+1,koltuksayaci);
                                        koltuksayaci=0;
                                    }
                                    printf("\nANA MENUYE DONULUYOR\n");
                                    sleep(1);

                                    goto anamenu;

                                default:
                                    break;


                    }
                }
                 else
                    {
                    printf("Hatali giris lutfen tekrar deneyiniz\n");
                    sleep(1);
                    goto giris_ekrani;
                    }

        }
        else
        {
            printf("Hatali giris lutfen tekrar deneyiniz\n");
            sleep(1);
            goto giris_ekrani;
        }


        }


}










