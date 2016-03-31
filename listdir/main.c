#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>

int main()
{
    DIR *repertoire;
    repertoire = opendir("Dossier/");
    struct dirent *lecture;

    while ((lecture = readdir(repertoire))) {
        if (strcmp(lecture->d_name, ".")!=0 && strcmp(lecture->d_name, "..")!=0){
            printf("- nom du fichier : %s\n", lecture->d_name);
            struct stat st;

            stat (lecture->d_name, &st);

            /* Modified time */
            time_t t = st.st_mtime;
            struct tm tm = *localtime (&t);
            char s[32];
            strftime (s, sizeof s, "%d/%m/%Y %H:%M:%S", &tm);

            printf ("Date de creation : %s\n", s);

        }
    }
    closedir(repertoire);
    return EXIT_SUCCESS;
}
