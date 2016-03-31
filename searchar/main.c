#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	char chaine[100];
	char ch[100];
	char c;
	printf("Entrez une chaine de caractère : ");
	scanf("%s", chaine);
	printf("Entrez le caractère à rechercher : ");
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
		printf("\nLe caractère %c se trouve à la position %d", c, pos);
	else
		printf("\nLe caractère %c n'a pas été trouvé dans la chaine.", c);
}
