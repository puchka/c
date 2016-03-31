#include <stdio.h>
#include <stdlib.h>

int main()
{
    char szMots[254], *p;

    scanf("%s", szMots);

    for(p=szMots; *p !='\0'; p++);

    *(p+1) = 0;//utile

    (*((unsigned int*)(p-sizeof(unsigned int))) == 0x65636972) ? (*((unsigned int*)(p-sizeof(unsigned int))) = 0x00727565) : (*((unsigned int*)(p-sizeof(unsigned int)+1)) = 0x65636972);

    printf(">> %s : %s\n\n",((!(*p))?"masculin":"feminin"),szMots);

    system("pause");
    return 0;
}
