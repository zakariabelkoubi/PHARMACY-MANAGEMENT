#include <stdio.h>
#include <stdlib.h>
int n,i,hh,bb,PTTC;
int z,low,high,mid;
int j,step;
int o,q,df,gc;

typedef struct {
    char name[20];
    double pr;
    int code,qu;
}pharmacy;

pharmacy pharm[200];
static int x = 0;

void deletpr(){
     int e,t;
     printf("enter the code of product to delete\n");
     scanf("%d" ,&e);
     for (i=0;i<x;i++){
        if (pharm[i].code==e){
            for (t=i;t<(x-1);t++);{
                pharm[t]=pharm[t+1];
            }
            x--;
        }

     }
}
////////////////////////////////////

void menu(){
 printf("1=> ADD PRODUCTS\n");
 printf("2=> DELETE A PRODUCT\n");
 printf("3=> SEARCH FOR A PRODUCT\n");
 printf("4=> SALL A PRODUCT\n");
 printf("5=> SALES LIST\n");
 printf("6=> THE PRODUCT LIST\n");
 printf("7=> ADD QUANTITY\n");
 printf("ANY NUMBER=> EXITE\n\n");
}
/////////////////////////////////////////////////
void sortbynum( pharmacy pharm[], int n)
{
    int l, b;
     pharmacy s;
    for (l=0;l<n-1;l++)
    {
        for (b =0;b<(n-1-l);b++)
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
//////////////////////////////////////////
void sortbyalpha( pharmacy pharm[], int n)
{
    int v, k;
     pharmacy h;
    for (v=0;v<n-1; v++)
    {
        for (k=0;k<(n-1-v);k++)
        {
            if (strcasecmp(pharm[k].name, pharm[k + 1].name) > 0)
            {
                h= pharm[k];
                pharm[k]=pharm[k + 1];
                pharm[k+1]=h;
            }
        }
    }
}

///////////////////////////////////////////
void sall(){
printf("enter the number of the product:\n");
scanf("%d",&bb);
printf("how much do you want:\n");
scanf("%d",&hh);
pharm[bb-1].qu -= hh;

}
int main()
{
 printf("\t\t\t=>=>=>=>=>=>=> WELCOM TO PHARMACY MANAGEMENT PROGRAM! <=<=<=<=<=<=<=\n\n");
 BEGINING:
 printf("=>=> THE MENU! <=<=\n");
 menu();
 printf("enter your choice\n");
 scanf("%d" , &j);
 switch (j){
 case 1 :
     printf("ADD A PRODUCT\n");

    printf("how many product you want to add\n");
    scanf("%d" , &n);
    for(i=x;i<x+n;i++){
        printf("enter the name of the product %d\n" , i+1);
        scanf("%s" , pharm[i].name);
        printf("enter the price of the product(DH)\n");
        scanf("%lf", &pharm[i].pr);
        printf("enter the quantity of the product\n");
        scanf("%d" , &pharm[i].qu);
        printf("enter the code of the product\n");
        scanf("%d", &pharm[i].code);
        printf("\tA NEW PRODUCT WAS ADD BACK TO THE MENU!!\n\n");
        }
        x+=n;
 goto BEGINING;
 break;
 case 2 :
        printf("DELETE A PRODUCT\n");
        deletpr();
        printf("1=> BACK TO THE MENU!\n");
        printf("ANY NUMBER=> EXIT!\n");
        scanf("%d" , &o);
        if (o==1){
                goto BEGINING;
        }
        else {
            printf("\n");
        }



 break;
 case 3 :
          SEARCH:
            printf("SEARCH FOR A PRODUCT\n");
            printf("enter the product code to find:\n");
            scanf("%d" , &z);
            low=0;
            high=n-1;
            mid=(low+high)/2;
            while (low<=high){
                if(pharm[mid].code<z)
                    low=mid+1;
                else if (pharm[mid].code==z)
                {
            printf("product number %d\n" , mid+1);
            printf("product name: %s\n" , pharm[mid].name);
            printf("product price: %lf + (15%TTC) = %lf\n" ,pharm[mid].pr,pharm[mid].pr+pharm[mid].pr*0.15);
            printf("product quantity: %d\n" , pharm[mid].qu);
            break;
                }
                else
                    high=mid-1;
                mid=(low+high)/2;
            }
            if (low>high){
            printf("this code %d is not exist in the list/n" , z);
            }
        printf("1=> BACK TO THE MENU!\n");
        printf("ANY NUMBER=> EXIT!\n");
        scanf("%d" , &o);
        if (o==1){
                goto BEGINING;
        }
        else {
            printf("\n");
        }

 break;
 case 4 :
         printf("SALL A PRODUCT\n");
         sall();
         printf("DONE\n");
        printf("1=> BACK TO THE MENU!\n");
        printf("ANY NUMBER=> EXIT!\n");
        scanf("%d" , &o);
        if (o==1){
                goto BEGINING;
        } else {
            printf("\n");
        }

 break;
 case 5 :
   printf("not yet");
   printf("%d" , pharm[bb-1]);


 break;
 case 6 :
        printf("\t\t<=THE PRODUCT LISTE=>\n");
        printf("YOU WANT A LIST SORTED BY\n");
        printf("1=>BY NAME A->Z\n");
        printf("2=>BY PRICE BIGGER->SMALLER\n");
        scanf("%d" , &q);
        if (q==1){
            for (i=0;i<x;i++){
            sortbyalpha(pharm , n);
            printf("product number %d\n" , i+1);
            printf("product name: %s\n" , pharm[i].name);
            printf("product price: %lf + (15%TTC) = %lf\n" , pharm[i].pr , pharm[i].pr+pharm[i].pr*0.15);
            printf("product quantity: %d\n" , pharm[i].qu);
            printf("product code: %d\n" , pharm[i].code);
            printf("--------------------------------------------------------------\n");
            }
            }
              else if (q==2){
            for (i=0;i<x;i++){
            sortbynum(pharm , n);
            printf("product number %d\n" , i+1);
            printf("product name: %s\n" , pharm[i].name);
            printf("product price: %lf + (15%TTC) = %lf\n" , pharm[i].pr ,pharm[i].pr+pharm[i].pr*0.15);
            printf("product quantity: %d\n" , pharm[i].qu);
            printf("product code: %d\n" , pharm[i].code);
            printf("--------------------------------------------------------------\n");
            } }
            else {
            printf("this number does not exist\n");
            }

        printf("1=> BACK TO THE MENU!\n");
        printf("ANY NUMBER=> EXIT!\n");
        scanf("%d" , &o);
        if (o==1){
                goto BEGINING;
        } else {
            printf("\n");
        }
 break;
 case 7 :

    printf("enter the number of the product\n");
    scanf("%d",&df);
    printf("HOW MUCH DO YOU WANT TO ADD\n");
    scanf("%d" , &gc);
    pharm[df-1].qu +=gc;
    printf("1=> BACK TO THE MENU!\n");
        printf("ANY NUMBER=> EXIT!\n");
        scanf("%d" , &o);
        if (o==1){
                goto BEGINING;
        } else {
            printf("\n");
        }

 default: printf("EXIT!\n");

 }
    return 0;
 }





