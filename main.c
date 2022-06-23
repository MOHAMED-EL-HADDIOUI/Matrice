#include "matrices.h"
#include <stdio.h>
int main()
{
    int i;
    do
{
    printf("|_______________________________________________________________________|\n");
    printf("|_______________APPLICATION : Les operations sur les matrices___________|\n");
    printf("|_______________________________________________________________________|\n");
    printf("|____________________Realise par : EL HADDIOUI MOHAMED__________________|\n");
    printf("|____________________________Filiere II-BDCC____________________________|\n");
    printf("|_______________________________________________________________________|\n");
    printf("\n");
    printf("\n");
    printf("\n");
    printf("|_________________________________MENU__________________________________|\n");
    printf("|        { 1}|=> La Somme du deux Matrices                              |\n");
    printf("|        { 2}|=> Le Produit du deux Matrices                            |\n");
    printf("|        { 3}|=> Le Multiplication entre Matrice et Vecteur             |\n");
    printf("|        { 4}|=> Le Diagonale de la Matrice                             |\n");
    printf("|        { 5}|=> Calculer le Trace d une Matrice                        |\n");
    printf("|        { 6}|=> Le 2eme Diagonale de la Matrice                        |\n");
    printf("|        { 7}|=> Le Transformer une Matrice en un Vecteur               |\n");
    printf("|        { 8}|=> Le Transformer un Vecteur en une Matrice               |\n");
    printf("|        { 9}|=> Extraire la sous matrice d une Matrice                 |\n");
    printf("|        {10}|=> Trouver la ligne d une Matrice(contient le max de 0)   |\n");
    printf("|        {11}|=> Calculer le Determinant d une Matrice                  |\n");
    printf("|        {12}|=> Calculer la Matrice Transpose d une Matrice            |\n");
    printf("|        {13}|=> Calculer la Matrice Inverse d une Matrice              |\n");
    printf("|        {14}|=> Resoudre un Systeme Lineaire A.X=Y                     |\n");
    printf("|                            {0}|=> Quttier                             |\n");
    printf("|_______________________________________________________________________|\n");
    printf("\n");
    
    printf("|_____________________Veullez choisir une action _______________________|\n");
    scanf("%d",&i);
    printf("|_______________________________________________________________________|\n");
    switch (i)
    {
    case 1:
              printf("|        La Somme du deux Matrices             |\n");
              matrice_t A1,A2,A3;
              printf("|             Entrez la Matrice 1              |\n");
              scanMatrice(&A1);
              printf("|             Entrez la Matrice 2              |\n");
              scanMatrice(&A2);
              printf("|                    La Somme:                 |\n");
              A3=add(&A1,&A2);
              printMatrice(&A3);
        break;
    case 2:
              printf("|        Le Produit du deux Matrices           |\n");
              matrice_t B1,B2,B3;
              printf("|             Entrez la Matrice 1              |\n");
              scanMatrice(&B1);
              printf("|             Entrez la Matrice 2              |\n");
              scanMatrice(&B2);
              printf("|                  Le Produit:                 |\n");
              B3=produit(&B1,&B2);
              printMatrice(&B3);
        
        break;
    case 3:
              printf("|   Le Multiplication entre Matrice et Vecteur |\n");
              matrice_t C1;
              vecteur_t VA1,VA2;
              printf("|             Entrez la Matrice                |\n");
              scanMatrice(&C1);
              printf("|             Entrez le Vecteur                |\n");
              scanVecteur(&VA1);
              printf("|                  Le Vecteur:                 |\n");
              VA2=MatDotVect(&C1,&VA1);
              printVecteur(&VA2);
        
        break;
    case 4:
              printf("|        Le Diagonale de la Matrice            |\n");
              matrice_t D1;
              printf("|             Entrez la Matrice                |\n");
              scanMatrice(&D1);
              printf("|                  Le Diagonale:               |\n");
              vecteur_t VB1;
              VB1=getDiag(&D1);
              printVecteur(&VB1);
        
        break;
    case 5:
              printf("|            Le Trace d une Matrice            |\n");
              matrice_t E1;
              printf("|             Entrez la Matrice                |\n");
              scanMatrice(&E1);
              printf("|                   Le Trace:                  |\n");
              double Y;
              Y=getTrace(&E1);
              printf("|                       %lf                    |\n",Y);
        
        break;
    case 6:
              printf("|       Le 2eme Diagonale de la Matrice        |\n");
              matrice_t F1;
              printf("|             Entrez la Matrice                |\n");
              scanMatrice(&F1);
              printf("|              Le 2eme Diagonale:              |\n");
              vecteur_t VC1;
              VC1=get2emeDiag(&F1);
              printVecteur(&VC1);
        
        break;
    case 7:
              printf("|   Le Transformer une Matrice en un Vecteur   |\n");
              matrice_t G1;
              printf("|             Entrez la Matrice                |\n");
              scanMatrice(&G1);
              printf("|                  Le Transformer:             |\n");
              vecteur_t VD1;
              VD1=Mat2Vect(&G1);
              printVecteur(&VD1);
        
        break;
    case 8:
              printf("|   Le Transformer un Vecteur en une Matrice   |\n");
              vecteur_t VE1;
              printf("|             Entrez le Vecteur                |\n");
              scanVecteur(&VE1);
              printf("|            Entrez le nombre des lignes       |\n");
              int P;
              scanf("%d",P);
              printf("|                Le Transformer:               |\n");
              matrice_t H1;
              H1=Vect2Mat(&VE1,P);
              printMatrice(&H1);
        
        break;
    case 9:
              printf("|    Extraire la sous matrice d une Matrice    |\n");
              matrice_t I1,I2;
              printf("|             Entrez la Matrice                |\n");
              scanMatrice(&I1);
              int l,n;
              printf("|                 Entrez la ligne              |\n");
              scanf("%d",&l);
              printf("|                 Entrez la colonne            |\n");
              scanf("%d",&n);
              printf("|                 la sous matrice:             |\n");
              I2=extracSubMatrice(&I1,l-1,n-1);
              printMatrice(&I2);
        
        break;
    case 10:
              printf("|          Trouver la ligne d une Matrice      |\n");
              matrice_t J1;
              printf("|             Entrez la Matrice                |\n");
              scanMatrice(&J1);
              printf("|                   la ligne:                  |\n");
              int indince;
              indince=getBestligneCol(&J1);
              printf("|                       %d                     |\n",indince);
        
        break;
    case 11:
              printf("|          le Determinant d une Matrice        |\n");
              matrice_t L1;
              printf("|             Entrez la Matrice                |\n");
              scanMatrice(&L1);
              printf("|                Le Determinant:               |\n");
              double Determinant;
              Determinant=getDet(&L1);
              printf("|                       %lf                    |\n",Determinant);
        
        break;
    case 12:
              printf("|            le Transpose d une Matrice        |\n");
              matrice_t M1,M2;
              printf("|             Entrez la Matrice                |\n");
              scanMatrice(&M1);
              printf("|                    Le Transpose:             |\n");
              M2=getTranspose(&M1);
              printMatrice(&M2);
        
        break;
    case 13:
              printf("|             la Inverse d une Matrice         |\n");
              matrice_t N1,N2;
              printf("|             Entrez la Matrice                |\n");
              scanMatrice(&N1);
              printf("|                    La Inverce :              |\n");
              N2=getInverse(&N1);
              printMatrice(&N2);
        
        break;
    case 14:
              printf("|       Resoudre un Systeme Lineaire A.X=Y     |\n");
              matrice_t O1;
              vecteur_t VP1,VP2;
              printf("|             Entrez la Matrice                |\n");
              scanMatrice(&O1);
              printf("|             Entrez le Vecteur                |\n");
              scanVecteur(&VP1);
              printf("|                  La solution :               |\n");
              VP2=SolveSys(&O1,&VP1);
              printVecteur(&VP2);
        break;
    default:
        break;
    }
} while (i!=0);
}
