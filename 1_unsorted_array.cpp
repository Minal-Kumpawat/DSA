#include <stdio.h>
#include<stdlib.h>
void merge_sort(int *,int);
int main(){
	int *a,n,i;
	printf("enter how many n term:");
	scanf("%d",&n);
	a=(int *)malloc(n*sizeof(int));
	//input
	for (i=0;i<n;i++)
	{
		printf("enter element %d:",i+1);
		scanf("%d",&a[i]);
	}
	merge_sort(a,n);
	//output
	for (i=0;i<n;i++)
	{
		printf("%d\t",a[i]);
	}

}
void merge_sort(int *a,int n){
	int *t,lb1,lb2,ub1,ub2,k,sz,i,j;
	t=(int *)calloc (n,sizeof(int));
	sz=1;

	while (sz<n)
	{
	    k=0;
		lb1=0;
		while(lb1+sz<n)
		{
			lb2=lb1+sz;
			ub1=lb2-1;
			ub2=ub1+sz<n?ub1+sz:n-1;
			//merging sort
			for (i=lb1,j=lb2;i<=ub1 && j<=ub2; )
			{
				if (a[i]<a[j])
					t[k++]=a[i++];
				else
					t[k++]=a[j++];
			}
			for (;i<=ub1||j<=ub2;)
                if (i<=ub1)
                {
                    t[k++]=a[i++];
                }
                else
                    t[k++]=a[j++];
			lb1=ub2+1;
		}
		while (k<n)
		{
			t[k]=a[k];
			k++;
		}
		for (i=0;i<n;i++)
			a[i]=t[i];
		sz*=2;
	}
}

