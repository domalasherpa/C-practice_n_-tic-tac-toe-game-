#include <stdio.h>
#include <float.h>


const int TOTAL=5;


float average(int length, int array[])
{
	int sum=0, i;
	for(i=0; i<length; i++)
	{
		sum+=array[i];                   //sum=sum+array
	}
	return (sum/(float)length);            //length is defined as float
}

int main()
{
	//calcullate the average scores.
	int scores[TOTAL], i;
	for(i=0; i<TOTAL; i++)
	{
		printf("scores :");
		scanf("%d",&scores[i]);
	}
	printf("Average:%f\n",average(TOTAL,scores));
	
}
