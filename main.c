#include <stdio.h>
#include <stdlib.h>

void secimsonucu(char x[],long int y[][3],float z,int a,float b);
void reset(char partiler[]);
void turkiyesonuc(char a[],long int b[],int d,float e,int x,long int z[][2],float f,int g,int h[][1]);

int main()
{
    char x;
    char partiler[6]={'A','B','C','D','E','F'};
    int partiSayisi=6,ilPlakaKodu,ilMilletvekilKontenjan;
    int mvSayisi[20];
    int i=0,mvToplami=0,a,b,j;
    int ilsayac;
    int mvBirincilik[10][1]={0,0,0,0,0,0,0,0,0,0};
    int tmp;
    int sayac=0;
    long int partiOy[23][3]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    long int tmpPartiOy[23]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    long int toplamPartiMv[23][2]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    float toplamOy=0,toplamTrOy=0;
    float oyYuzde=0;
    float mvYuzde=0;


    printf("-----------------------------------TURKIYE SECIM SIMULASYONU-----------------------------------\n\n");


    do
    {


        do
        {
            printf("%d. Ilin plaka kodunu giriniz(1-81) :",ilsayac); // Türkiyedeki il sayisi sýnýrlarý koyuyoruz.
            ilsayac++;
            scanf("%d",&ilPlakaKodu);
            if(ilPlakaKodu>0 && ilPlakaKodu<82)
                break;
        }
        while(ilPlakaKodu>0 || ilPlakaKodu<82);
        do
		{
		printf("Ilin milletvekili kontenjanini giriniz(1-20) :");
        scanf("%d",&ilMilletvekilKontenjan);
        printf("\n");
        if(ilMilletvekilKontenjan>0 && ilMilletvekilKontenjan<21)
                break;
		}
        while(ilMilletvekilKontenjan>0 || ilMilletvekilKontenjan<82);
        mvToplami+=ilMilletvekilKontenjan;
        for(i=0;i<partiSayisi;i++)
        {
            printf("%c Partisi'nin oy sayisini giriniz :",partiler[i]);
            scanf("%ld",&partiOy[i][0]);
            toplamOy+=partiOy[i][0];
            tmpPartiOy[i]+=partiOy[i][0];

        }
        toplamTrOy+=toplamOy;
        printf("\nIl Plaka Kodu : %d",ilPlakaKodu);
        printf("\nMilletvekili Kontenjani : %d",ilMilletvekilKontenjan);
        printf("\nGecerli Oy Sayisi : %.0f",toplamOy);
        for(i=0;i<partiSayisi;i++)
        {
            partiOy[i][2]=i;
            toplamPartiMv[i][1]=i;
        }
        for(a=0;a<=partiSayisi;a++)
        {
            for(b=0;b<=partiSayisi;b++)
            {
                if(partiOy[a][0]>partiOy[b][0])
                {
                    tmp=partiOy[a][0];
                    partiOy[a][0]=partiOy[b][0];
                    partiOy[b][0]=tmp;

                    tmp=partiOy[a][2];
                    partiOy[a][2] = partiOy[b][2];
                    partiOy[b][2] = tmp;
                }
            }
        }
        for(i=0;i<partiSayisi;i++)
        {
                if(partiOy[0][2]==i)
             {
                 mvBirincilik[i][0]++;
                 break;//Kac ile birinci olduklarýný burada hesaplayýp atýyoruz.
             }
        }
        int partiayar[partiSayisi][2];
        for(i=0;i<partiSayisi;i++)
        {
            partiayar[i][0] = partiOy[i][0];
            partiayar[i][1] = i;
        }
        do {
            for(i=0;i<partiSayisi;i++)
            {
                for(j=0;j<partiSayisi-1;j++)
                {
                    if(partiayar[j][0] < partiayar[j+1][0])
                    {
                        tmp = partiayar[j][0];
                        partiayar[j][0] = partiayar[j+1][0];
                        partiayar[j+1][0] = tmp;

                        tmp = partiayar[j][1];
                        partiayar[j][1] = partiayar[j+1][1];
                        partiayar[j+1][1] = tmp;
                    }
                }
            }
            ilMilletvekilKontenjan--;
            partiOy[partiayar[0][1]][1]++;
            partiayar[0][0] = partiayar[0][0]/2;

        }while(ilMilletvekilKontenjan>0);
        for(i=0;i<partiSayisi;i++)
        {

        }
        printf("\n\t\tOy Say \t\tOy Yuzde \tMV Say");
        printf("\n\t\t------\t\t------\t\t------");
        secimsonucu(partiler,partiOy,oyYuzde,partiSayisi,toplamOy);
        for(i=0;i<partiSayisi;i++)
        {
        	toplamPartiMv[partiOy[i][2]][0]+=partiOy[i][1];
		}
		printf("\n\n");

        system("PAUSE");

        printf("\n\n");
        if(sayac<5)
        {
            toplamOy=0;
            ilMilletvekilKontenjan=0;
            for(i=0;i<partiSayisi;i++)
            {
                partiOy[i][1]=0;
            }
            sayac++;
        }
    }
    while(sayac<5);
    printf("\n\t\t\t\t************** TURKIYE GENEL **************\t\t\n");
    printf("\nMilletvekili Kontenjani : %d",mvToplami);
    printf("\nGecerli Oy Sayisi : %.0f",toplamTrOy);
    printf("\n\t\tOy Say \t\tOy Yuzde \t MV Say \tMV Yuzde \t Il 1.lik Say. ");
    printf("\n\t\t------\t\t------\t\t------\t\t------\t\t------\t\n\n");
    turkiyesonuc(partiler,tmpPartiOy,partiSayisi,oyYuzde,toplamTrOy,toplamPartiMv,mvYuzde,mvToplami,mvBirincilik);
}

void secimsonucu(char x[],long int y[][3],float z,int a,float b)
{
    int c;
    for(c=0;c<a;c++)
    {
        z=(y[c][0]*100)/b;
        printf("\n%c Partisi \t%ld \t\t%.2f \t\t%ld",x[y[c][2]],y[c][0],z,y[c][1]);
    }
}

void reset(char partiler[])
{
    char partiler1[6]={'A','B','C','D','E','F'};
    int i;
    for(i=0;i<6;i++)
    {
        partiler[i]=partiler1[i];
    }
}

void turkiyesonuc(char a[],long int b[],int d,float e,int x,long int z[][2],float f,int g,int h[][1])
{
    long int mv_s[d][2];
    int i,j;
    for(i=0;i<d;i++)
    {
        mv_s[i][0] = z[i][0];
        mv_s[i][1] = i;
    }
    for(i=0;i<d;i++)
    {
        for(j=0;j<d-1;j++)
        {
            if(mv_s[j][0] < mv_s[j+1][0])
            {
                int tmp;
                tmp = mv_s[j][0];
                mv_s[j][0] = mv_s[j+1][0];
                mv_s[j+1][0] = tmp;

                tmp = mv_s[j][1];
                mv_s[j][1] = mv_s[j+1][1];
                mv_s[j+1][1] = tmp;
            }
        }
    }
    for(i=0;i<d;i++)
    {
        f= (float)(z[i][0]*100)/g;
        e=(float)(b[i]*100)/x;
        printf("\n%c Partisi \t%ld \t\t%.2f\t\t%ld\t\t%.2f\t\t%d",a[i],b[i],e,z[i][0],f,h[i][0]);
    }
    printf("\n\nIktidar Partisi : %c\nAna Muhalefet Partisi:%c",a[mv_s[0][1]],a[mv_s[1][1]]);
}
