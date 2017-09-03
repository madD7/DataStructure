/**
 * @author madD7
 *
*/
#include <stdio.h>



int main(void)
{
	int array[100] = {0};
	int num=0, min=0, max=0, midpt=0;

	for(min=0; min<(sizeof(array)/sizeof(int)); min++)
		array[min] = min;

	printf("Enter a integer number to be searched\n");
	scanf("%d", &num);

	min=array[0];
	max=array[(sizeof(array)/sizeof(int))-1];
	
	if( (num < min) || (num > max) )
	{
		printf("Number out of range\n");
		return 1;
	}
		
	while(min < max)
	{
		if(midpt > num)
			max = array[midpt];
		else if(midpt < num)
			min = array[midpt] + 1;
		else if(array[midpt] == num)
		{
			printf("The number is %d found at %d position in array\n", num, midpt);
			return 0;
		}

		midpt= (min+max)/2;
		printf("min=%d max=%d midpt=%d\n", min, max, midpt);
	}
	
	if(min >= max)
		printf("Number not present in the list\n");

	return 1;
}



