/**
 *
 * @author madD7
*/

#include <stdio.h>

inline int Compare(int iNum1, int iNum2)
{
	if(iNum1 == iNum2)
		return 0;
	else if (iNum1 > iNum2)
		return 1;
	else if (iNum1 < iNum2)
		return -1;
}

int binsearch(int *piArr, int iSrchnum, int iMin, int iMax )
{
	int iMidpt=0;

	if(iSrchnum < iMin || iSrchnum > iMax)
		return -1;

	while(iMin <= iMax)
	{
		iMidpt = (iMin+iMax)/2;

		printf("iMin=%d, iMax=%d, iMid=%d\n", iMin, iMax, iMidpt);
		switch(Compare(piArr[iMidpt], iSrchnum)) 
		{
			case 0:
				return iMidpt;

			case 1:
				return binsearch(piArr, iSrchnum, iMin, iMidpt-1);

			case -1:
				return binsearch(piArr, iSrchnum, iMidpt+1, iMax);
		}
	}

	return -1;
}


int main(void)
{
	int iArray[100] = {0};
	int iNum=0,iMin=0, iMax=0, iPos=0;

	for(iMin=0; iMin<(sizeof(iArray)/sizeof(int)); iMin++)
		iArray[iMin] = iMin;

	printf("Enter a integer number to be searched\n");
	scanf("%d", &iNum);

	iMin = iArray[0];
	iMax = iArray[((sizeof(iArray)/sizeof(int))-1)];

	if((iPos = binsearch(iArray, iNum, iMin, iMax)) != -1)
	{
		printf("The number %d is at %d position\n", iNum, iPos);
		return 0;
	}
	else
	{
		printf("Number not found\n");
	}
	return 1;
}



