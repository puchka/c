#ifndef FILE_H_INCLUDED
#define FILE_H_INCLUDED

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *suivant;
};

typedef struct File File;
struct File
{
    Element *premier;
};

void enfiler(File *file, int nombre);
int defiler(File *file);
void afficherFile(File *file);

#endif // FILE_H_INCLUDED
