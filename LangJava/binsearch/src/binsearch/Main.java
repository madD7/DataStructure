package binsearch;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author madD7
 */

class binsearch
{
    int iMax=0;
    int iMin=0;
    int iMidpt=0;
    int iArray[] = new int[100];
    
    binsearch()
    {
        for(int i=0; i<iArray.length; i++)
            iArray[i] = i;
        
        iMin = iArray[0];
        iMax = iArray[iArray.length-1];
    }
    
    private int compare(int iNum1, int iNum2)
    {
        if(iNum1 > iNum2)
            return 1;
        else if(iNum1 == iNum2)
            return 0;
        
        return -1;
    }
    
    int search(int iNum)
    {        
        if( iNum < iMin || iMax < iNum)
            return -1;
        
        while(iMin <= iMax)
        {
            switch (compare(iArray[iMidpt], iNum))
            {
                case 0:
                    return iMidpt;
                
                case 1:
                    iMax = iMidpt;
                    break;
                    
                case -1:
                    iMin = iMidpt + 1;
                    break;
            }
            
            iMidpt = (iMin + iMax) / 2;
        }
        
        return -1;
    }
}


public class Main {
    
    public static void main(String args[]) throws IOException
    {
        InputStreamReader in = new InputStreamReader(System.in);
        BufferedReader read = new BufferedReader(in);
        
        System.out.println("Enter the number");
        
        int iNum = Integer.parseInt(read.readLine());
        
        binsearch srch = new binsearch();
        
        int iPos = srch.search(iNum);
        
        if(iPos != -1)
            System.out.println("The number " + iNum + " is at position " + iPos);
        else
            System.out.println("Number not found");
    }
    
}
