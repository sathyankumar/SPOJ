include<stdio.h>
#include<math.h>
int main()
{
    int i,n;
	 int n0,n1,n2,t;
	double time,l;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&n0);
    scanf("%d",&n1);
    scanf("%d",&t);
    scanf("%d",&n2);
    l=log((double)n1/n0)/(double)t;
    time=log((double)n2/n0)/(double)l;
    printf("Scenario #%d: %.2f\n",i+1,time);
    }
	return 0;
}
