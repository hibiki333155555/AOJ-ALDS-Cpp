#include <stdio.h>
#include <string.h>
#define max(a,b) (a>b?a:b)
int xy[1001][1001];
char X[1001],Y[1001];

int main(){
  int n,l,i,j,a,b;
   scanf("%s",Y);
    scanf("%s",X);
    a=strlen(Y);
    b=strlen(X);
    for(i=0;i<=strlen(Y);i++){
      for(j=0;j<=strlen(X);j++)
        xy[i][j]=0;
    }

    for(i=1;i<=a;i++){
      for(j=1;j<=b;j++){
        if(X[j-1]==Y[i-1]) xy[i][j]=xy[i-1][j-1]+1;
        else xy[i][j]=max(xy[i-1][j],xy[i][j-1]);
      }
    }
    printf("%d\n",xy[i-1][j-1]);


}