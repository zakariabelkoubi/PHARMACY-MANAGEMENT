#include <stdio.h>
#include <stdlib.h>
struct pharmacy{
    char name[20];
     float pr;
    int code,qu;
};
struct oneProduct{
char na[20];
float pri;
int cd,Q;
};
void menu(){
 printf("1=> ADD PRODUCTS\n");
 printf("2=> ADD 1 PRODUCT\n");
 printf("3=> MODIFY\n");
 printf("4=> SEARCH FOR A PRODUCT\n");
 printf("5=> DELETE A PRODUCT\n");
 printf("6=> SALL A PRODUCT\n");
 printf("7=> VIEW PRODUCT LIST\n");
 printf("8=> SALES LIST\n");
 printf("ANY NUMBER=> EXITE\n\n");
}
void sortbynum(struct pharmacy pharm[], int n)
{
    int l, b;
    struct pharmacy s;
    for (l = 0; l < n - 1; l++)
    {
        for (b = 0; b < (n - 1 - l); b++)
        {
            if (pharm[b].pr < pharm[b + 1].pr)
            {
                s = pharm[b];
                pharm[b] = pharm[b + 1];
                pharm[b + 1] = s;
            }
        }
    }
}
void sortbyalpha(struct pharmacy pharm[], int n)
{
    int v, k;
    struct pharmacy h;
    for (v = 0; v < n - 1; v++)
    {
        for (k = 0; k < (n - 1 - v); k++)
        {
            if (strcasecmp(pharm[k].name, pharm[k + 1].name) > 0)
            {
                h = pharm[k];
                pharm[k] = pharm[k + 1];
                pharm[k + 1] = h;
            }
        }
    }
}

int main()
{
    int j,step;
    int n,i,o,q;
    float TTC;
 printf("\t\t\t=>=>=>=>=>=>=> WELCOM TO PHARMACY MANAGEMENT PROGRAM! <=<=<=<=<=<=<=\n\n");
  BEGINING:
 printf("=>=> THE MENU! <=<=\n");
 menu();
 printf("enter your choice\n");
 scanf("%d" , &j);
 switch (j){
 case 1 :

    printf("how many product you want to add\n");
    scanf("%d" , &n);
    struct pharmacy *pharm=malloc(n*sizeof(int));
    for(i=0;i<n;i++){
        printf("enter the name of the product %d\n" , i+1);
        scanf("%s" , &pharm[i].name);
        printf("enter the price of the product(DH)\n");
        scanf("%f", &pharm[i].pr);
        printf("enter the quantity of the product\n");
        scanf("%d" , &pharm[i].qu);
        printf("enter the code of the product\n");
        scanf("%d", &pharm[i].code);
        }
printf("\tA NEW PRODUCT WAS ADD BACK TO THE MENU!!\n\n");
goto BEGINING;
 break;
 case 2 : printf("NOT YET");
 break;
 case 3 : printf("NOT YET\n");
 break;
 case 4 : printf("NOT YET\n");
 break;
 case 5 : printf("NOT YET\n");
 break;
 case 6 : printf("NOT YET \n");
 break;
 case 7 :
        printf("\t\t<=THE PRODUCT LISTE=>\n");
        TRYA:
        printf("YOU WANT A LIST SORTED BY\n");
        printf("1=>BY NAME A->Z\n");
        printf("2=>BY PRICE BIGGER->SMALLER\n");
        scanf("%d" , &q);
        if (q==1){
            for (i=0;i<n;i++){
            sortbyalpha(pharm , n);
            TTC=pharm[i].pr+(pharm[i].pr*15/100);
            printf("product number %d\n" , i+1);
            printf("product name: %s\n" , pharm[i].name);
            printf("product price: %.2f + (15%TTC) = %.2f\n" , pharm[i].pr , TTC);
            printf("product quantity: %d\n" , pharm[i].qu);
            printf("product code: %d\n" , pharm[i].code);
            printf("--------------------------------------------------------------\n");
        }
        }  else if (q==2){
            for (i=0;i<n;i++){
          sortbynum(pharm , n);
          TTC=pharm[i].pr+(pharm[i].pr*15/100);
            printf("product number %d\n" , i+1);
            printf("product name: %s\n" , pharm[i].name);
            printf("product price: %.2f + (15%TTC) = %.2f\n" , pharm[i].pr , TTC);
            printf("product quantity: %d\n" , pharm[i].qu);
            printf("product code: %d\n" , pharm[i].code);
            printf("--------------------------------------------------------------\n");
        } }
          else {
            printf("this number does not exist\n");
            goto TRYA;
        }


        printf("1=> BACK TO THE MENU!\n");
        printf("ANY NUMBER=> EXIT!\n");
        scanf("%d" , &o);
        if (o==1){
            goto BEGINING;
        } else {
            printf("\n");
        }
 case 8 : printf("NOT YET\n");
 break;
 default: printf("EXIT!\n");

 }
    return 0;
 }





