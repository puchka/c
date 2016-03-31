void ordonnerTableau (int tableau [],int tailleTableau)
{
    int i=0,j=0,tp=0;
    for (j=0;j<tailleTableau;j++)
    {
        for (i=0;i<tailleTableau;i++)
        {
            if (tableau[i]>tableau[i+1])
            {
                tp=tableau[i];
                tableau[i]=tableau[i+1];
                tableau[i+1]=tp;
            }

        }
    }
}

