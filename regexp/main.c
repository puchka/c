#include <stdio.h>
#include <stdlib.h>
#include <regex.h>

int main (void)
{
   int err;
   regex_t preg;
   const char *str_request = "www.developpez.com";
   const char *str_regex = "www\\.[-_[:alnum:]]+\\.[[:lower:]]{2,4}";

/* (1) */
   err = regcomp (&preg, str_regex, REG_NOSUB | REG_EXTENDED);
   if (err == 0)
   {
      int match;

/* (2) */
      match = regexec (&preg, str_request, 0, NULL, 0);
/* (3) */
      regfree (&preg);
/* (4) */
      if (match == 0)
      {
         printf ("%s est une adresse internet valide\n", str_request);
      }
/* (5) */
      else if (match == REG_NOMATCH)
      {
         printf ("%s n\'est pas une adresse internet valide\n", str_request);
      }
/* (6) */
      else
      {
         char *text;
         size_t size;

/* (7) */
         size = regerror (err, &preg, NULL, 0);
         text = malloc (sizeof (*text) * size);
         if (text)
         {
/* (8) */
            regerror (err, &preg, text, size);
            fprintf (stderr, "%s\n", text);
            free (text);
         }
         else
         {
            fprintf (stderr, "Memoire insuffisante\n");
            exit (EXIT_FAILURE);
         }
      }
   }
   puts ("\nPress any key\n");
/* Dev-cpp */
   getchar ();
   return (EXIT_SUCCESS);
}
