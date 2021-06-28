#include <stdio.h>
int main()

{  
	int num,rev=0,temp,rem;
	printf("Enter the number:\n");
	scanf("%d",&num);
	temp=num;

	while(num!=0)
	{
	rem=num%10;
	rev=rev*10+rem;
	num=num/10;
	}
	if(temp==rev)
	{
	printf("%d is Palindrome number",temp);
	}
	else
	{
	printf("%d is not Palindrome number",temp);
	}	
	
}
