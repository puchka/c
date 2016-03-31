#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
	double init_somme, taux, fin_somme, temp;
	int nb_jours, roi, roi_set = 0;
	char type_compose;
	printf("Investissement compose (O/N) : ");
	scanf("%c", &type_compose);
	if (type_compose=='O' || type_compose=='o')
		printf("Investissement compose.\n\n");
	else
		printf("Investissement non compose.\n\n");
	printf("Somme initiale ($) : ");
	scanf("%lf", &init_somme);
	printf("Taux (%%) : ");
	scanf("%lf", &taux);
	printf("Duree investissement (jours) : ");
	scanf("%d", &nb_jours);
	if (type_compose=='O' || type_compose=='o')
	{
		temp = init_somme;
		int i;
		for (i = 1; 1; i++)
		{
			temp+=(taux/100)*temp;
			if (i==nb_jours) fin_somme = temp;
			if (i==nb_jours && roi_set) break;
			if (!roi_set && temp-init_somme>=init_somme)
			{
				roi = i;
				roi_set = 1;
				if (i>=nb_jours) break;
			}
		}
	}
	else
	{
		fin_somme = init_somme + init_somme*(taux/100)*nb_jours;
		roi = ceil(init_somme/((taux/100)*init_somme));
	}
	printf("Somme finale : %.2f$\n", fin_somme);
	printf("Bénefice : %.2f$\n", fin_somme-init_somme);
	printf("ROI : %d jours\n", roi);
	return EXIT_SUCCESS;
}
