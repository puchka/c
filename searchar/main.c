#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char chaine[100];
	char ch[100];
	char c;
	printf("Entrez une chaine de caract�re : ");
	scanf("%s", chaine);
	printf("Entrez le caract�re � rechercher : ");
	scanf("%s", ch);
	c = ch[0];
	int i, pos=-1;
	for (i=0;i<strlen(chaine);i++)
	{
		if (chaine[i]==c)
		{
			pos = i;
			break;
		}
	}
	if (pos!=-1)
		printf("\nLe caract�re %c se trouve � la position %d", c, pos);
	else
		printf("\nLe caract�re %c n'a pas �t� trouv� dans la chaine.", c);
}
