/*To check whether 
 *the given parameter can form traingle or not*/
#include <stdio.h>
#include <stdbool.h>

bool valid_traingle(float l, float b, float h);

int main()
{
	float l, b, h;
	printf("length of the sides:");
	scanf("%i%i%i", &l, &b, &h);
	printf("The answer is %d:", valid_traingle(l, b, h));
	printf("\n\n0= NO, 1=Yes ");
}

bool valid_traingle(float l, float b, float h)
{
     if(l<=0||b<=0|h<=0)                  //finding for the positive sides
    {
    	return 0;
	}
	else if(l+b<=h || b+h<=l || h+l<=b)  //To check if the side is greater or nor
	{
		return 0;
	}
	else
	{
	  return 1;	
    }
}


	

