#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define pi 3.141592654

double convert(double a);
void j2g(double jd, int *tab);

int main()
{
    int a, m;
    printf("Année : ");
    scanf("%d", &a);
    printf("Mois : ");
    scanf("%d", &m);
    int k = (a+0.0849 - 2000) * 12.3685;
    double t = k / 1236.85;
    double am = 2.5534+29.10535670*k-0.0000014*pow(t,2)-0.00000011*pow(t,3);
    am = convert(am);
    double amp = 201.5643+385.81693528*k+0.0107582*pow(t, 2)+
                 0.00001238*pow(t, 3)-0.000000058*pow(t, 4);
    amp = convert(amp);
    double f = 160.7108+390.67050284*k-0.0016118*pow(t, 2)
               - 0.00000227*pow(t, 3)+0.00000001*pow(t,4);
    f = convert(f);
    double o = 124.7746-1.56375588*k+0.0020672*pow(t,2)+0.00000215*pow(t,3);
    o = convert(o);
    // 14 variables
    double a1 = 299.77+0.107408*k-0.009173*pow(t, 2);
    a1 = convert(a1);
    double a2 = 251.88+0.016321*k;
    a2 = convert(a2);
    double a3 = 251.83+26.651886*k;
    a3 = convert(a3);
    double a4 = 349.42+36.412478*k;
    a4 = convert(a4);
    double a5 = 84.66 +18.206239*k;
    a5 = convert(a5);
    double a6 = 141.74+53.303771*k;
    a6 = convert(a6);
    double a7 = 207.14+2.453732*k;
    a7 = convert(a7);
    double a8 = 154.84+7.306860*k;
    a8 = convert(a8);
    double a9 = 34.52 +27.261239*k;
    a9 = convert(a9);
    double a10 = 207.19 + 0.121824*k;
    a10 = convert(a10);
    double a11 = 291.34 + 1.844379*k;
    a11 = convert(a11);
    double a12 = 161.72 + 24.198154*k;
    a12 = convert(a12);
    double a13 = 239.56 + 25.513099*k;
    a13 = convert(a13);
    double a14 = 331.55 + 3.592518*k;
    a14 = convert(a14);
    // Premier groupe de facteurs de correction
    double fact[14]={0.000325, 0.000165, 0.000164,
                     0.000126, 0.000110, 0.000062,
                     0.000060, 0.000056, 0.000047,
                     0.000042, 0.000040, 0.000037,
                     0.000035, 0.000023};
    double s1 = fact[0]*sin(a1/180*pi)+
                fact[1]*sin(a2/180*pi)+
                fact[2]*sin(a3/180*pi)+
                fact[3]*sin(a4/180*pi)+
                fact[4]*sin(a5/180*pi)+
                fact[5]*sin(a6/180*pi)+
                fact[6]*sin(a7/180*pi)+
                fact[7]*sin(a8/180*pi)+
                fact[8]*sin(a9/180*pi)+
                fact[9]*sin(a10/180*pi)+
                fact[10]*sin(a11/180*pi)+
                fact[11]*sin(a12/180*pi)+
                fact[12]*sin(a13/180*pi)+
                fact[13]*sin(a14/180*pi);
    double e = 1-0.002516*t-0.0000074*pow(t, 2);
    // Facteur additionnelle pour les Quartiers :
    double w = 0.00306-(0.00038*e*cos(am/180*pi))+(0.00026*cos(amp/180*pi))
               -(0.00002*cos((amp-am)/180*pi))+0.00002*cos((amp+am)/180*pi)
               +0.00002*cos(2*f/180*pi);
    double s2 = -0.40720*sin(amp/180*pi)+0.17241*e*sin(am/180*pi)
                +0.01608*sin(2*amp/180*pi)+0.01039*sin(2*f/180*pi)
                +0.00739*e*sin((amp-am)/180*pi)-0.00514*e*sin((amp+am)/180*pi)
                +0.00208*pow(e,2)*sin(2*am/180*pi)-0.00111*sin((amp-2*f)/180*pi)
                -0.00057*sin((amp+2*f)/180*pi)+0.00056*e*sin((2*amp+am)/180*pi)
                -0.00042*sin(3*amp/180*pi)+0.00042*e*sin((am+2*f)/180*pi)
                +0.00038*e*sin((am-2*f)/180*pi)-0.00024*e*sin((2*amp-am)/180*pi)
                -0.00017*sin(o/180*pi)-0.00007*sin((amp+2*am)/180*pi)
                +0.00004*sin((2*amp-2*f)/180*pi)+0.00004*sin(3*am/180*pi)
                +0.00003*sin((amp+am-2*f)/180*pi)+0.00003*sin((2*amp+2*f)/180*pi)
                -0.00003*sin((amp+am+2*f)/180*pi)+0.00003*sin((amp-am+2*f)/180*pi)
                -0.00002*sin((amp-am-2*f)/180*pi)-0.00002*sin((3*amp+am)/180*pi)
                +0.00002*sin(4*amp/180*pi);
    double s3 = -0.40614*sin(amp/180*pi)+0.17302*e*sin(am/180*pi)
                +0.01614*sin(2*amp/180*pi)+0.01043*sin(2*f/180*pi)
                +0.00734*e*sin((amp-am)/180*pi)-0.00515*e*sin((amp+am)/180*pi)
                +0.00209*pow(e,2)*sin(2*am/180*pi)-0.00111*sin((amp-2*f)/180*pi)
                -0.00057*sin((amp+2*f)/180*pi)+0.00056*e*sin((2*amp+am)/180*pi)
                -0.00042*sin(3*amp/180*pi)+0.00042*e*sin((am+2*f)/180*pi)
                +0.00038*e*sin((am-2*f)/180*pi)-0.00024*e*sin((2*amp-am)/180*pi)
                -0.00017*sin(o/180*pi)-0.00007*sin((amp+2*am)/180*pi)
                +0.00004*sin((2*amp-2*f)/180*pi)+0.00004*sin(3*am/180*pi)
                +0.00003*sin((amp+am-2*f)/180*pi)+0.00003*sin((2*amp+2*f)/180*pi)
                -0.00003*sin((amp+am+2*f)/180*pi)+0.00003*sin((amp-am+2*f)/180*pi)
                -0.00002*sin((amp-am-2*f)/180*pi)-0.00002*sin((3*amp+am)/180*pi)
                +0.00002*sin(4*amp/180*pi);
    double s4 = -0.62801*sin(amp/180*pi)+0.17172*e*sin(am/180*pi)
                -0.01183*e*sin((amp+am)/180*pi)+0.00862*sin(2*amp/180*pi)
                +0.00804*sin(2*f/180*pi)+0.00454*e*sin((amp-am)/180*pi)
                +0.00204*pow(e,2)*sin(2*am/180*pi)-0.00180*sin((amp-2*f)/180*pi)
                -0.00070*sin((amp+2*f)/180*pi)-0.00040*e*sin(3*amp/180*pi)
                -0.00034*e*sin((2*amp-am)/180*pi)+0.00032*e*sin((am+2*f)/180*pi)
                +0.00032*e*sin((am-2*f)/180*pi)-0.00028*pow(e,2)*sin((amp+2*am)/180*pi)
                +0.00027*e*sin((2*amp+am)/180*pi)-0.00017*sin(o/180*pi)
                -0.00005*sin((amp-am-2*f)/180*pi)+0.00004*sin((2*amp+2*f)/180*pi)
                -0.00004*sin((amp+am+2*f)/180*pi)+0.00004*sin((amp-2*am)/180*pi)
                +0.00003*sin((amp+am-2*f)/180*pi)+0.00003*sin(3*am/180*pi)
                +0.00002*sin((2*amp-2*f)/180*pi)+0.00002*sin((amp-am+2*f)/180*pi)
                -0.00002*sin((3*amp+am)/180*pi);
    double jde = 2451550.59766+29.53058886*k+0.00015437*pow(t,2)-
                 0.000000150*pow(t,3)+0.00000000073*pow(t,4);
    double jd = jde+s1+s2;
    // Calculer les phases de la lune pour le mois.
    // Pour la Nouvelle Lune :
    double nl;
    if (m==1)
        nl=jd;
    else
        nl = jd + (29.530588852) * (m - 1);
    /*
    int tab[3];
    j2g(nl, tab);
    printf("\nPremiere nouvelle lune de l'annee : ");
    printf("%d/%d/%d\n", tab[0], tab[1], tab[2]);
    */
    printf("nl = %f", nl);
    return 0;
}

double convert(double a)
{
    if (a<0)
        return 360+a;
    else
        return a-((int)a/360)*360;
}

void j2g(double jd, int *tab)
{
    int z = (int)jd;
    int alpha = (z-1867216.25)/36524.25;
    int s = z+1+alpha-(int)(alpha/4);
    int b = s+1524;
    int c = (int)((b-122.1)/365.25);
    int d = (int)(365.25*c);
    int e = (int)((b-d)/30.6001);
    tab[0] = b-d-(int)(30.6001*e);
    if (e<14)
        tab[1] = e-1;
    else
        tab[1] = e-13;
    if (tab[1]>2)
        tab[2] = c-4716;
    else
        tab[2] = c-4715;
}

