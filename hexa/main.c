#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void  dec2bin(int dec, int tab[8])
{
    int i=7, b=0;
    while(dec>=1)
    {
        b=dec%2;
        tab[i]=b;
        dec=dec/2;
        i--;
    }
}

char dec2hex(int dec)
{
	char ch;
	switch (dec)
	{
		case 0:
			ch='0';
			break;
		case 1:
			ch='1';
			break;
		case 10:
			ch='2';
			break;
		case 11:
			ch='3';
			break;
		case 100:
			ch='4';
			break;
		case 101:
			ch='5';
			break;
		case 110:
			ch='6';
			break;
		case 111:
			ch='7';
			break;
		case 1000:
			ch='8';
			break;
		case 1001:
			ch='9';
			break;
		case 1010:
			ch='A';
			break;
		case 1011:
			ch='B';
			break;
		case 1100:
			ch='C';
			break;
		case 1101:
			ch='D';
			break;
		case 1110:
			ch='E';
			break;
		default:
			ch='F';
	}
	return ch;
}

void bin2hex(int bin[8])
{
    int i, first=0, second=0;
	for (i=7;i>=0;i--)
	{
		if (i<4)
		{
			if (bin[i]==1)
				first+=pow(10, 3-i);
		}
		else
		{
			if (bin[i]==1)
				second+=pow(10, 3-i%4);
		}
	}
	printf("%d\n", first);
	printf("%d\n", second);
	printf("%c", dec2hex(first));
	printf("%c", dec2hex(second));
	printf("%c", '\n\n');
}

void dump_buffer(void *buffer, int buffer_size)
{
    int i, j;
	int bin[8]={0};
    for(i = 0;i < buffer_size;++i)
    {
        int dec = ((char *)buffer)[i];
		dec2bin(dec, bin);
		bin2hex(bin);
		printf("%c", ' ');
    }
}

void ReadFile(char *name)
{
	FILE *file;
	char *buffer;
	unsigned long fileLen;

	//Open file
	file = fopen(name, "rb");
	if (!file)
	{
		fprintf(stderr, "Unable to open file %s", name);
		return;
	}
	
	//Get file length
	fseek(file, 0, SEEK_END);
	fileLen=ftell(file);
	fseek(file, 0, SEEK_SET);

	//Allocate memory
	buffer=(char *)malloc(fileLen+1);
	if (!buffer)
	{
		fprintf(stderr, "Memory error!");
                                fclose(file);
		return;
	}

	//Read file contents into buffer
	fread(buffer, fileLen, 1, file);
	fclose(file);

	//Do what ever with buffer
	dump_buffer(buffer, fileLen);

	free(buffer);
}

int main(int argc, char *argv[])
{
	ReadFile("test.txt");
	return 0;
}
