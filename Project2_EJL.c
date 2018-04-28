/*
Earl John Liva
CEG-4350-01 Spring 2018
Project 1: Producer / Consumer Problem
Project2_EJL.c

-implementation of several page replacement algorithms: FIFO, Optimal, LRU, LFU, and MFU. 
*/

#include "Project2_EJL.h"
/*
* 	This function implements FIFO algorithm.
*   @param int pages[] : array of pages.
*  
*/
void FIFO(int pageArray[]){
  
  printf("FIFO: \n");
  char * fault;
  int numFaults = 0;  //track number of faults
  int frames[numFrames];

  for(int i = 0; i < numFrames; i++)
  {
   frames[i] = -1;
  }
 
  //iterate through the pages
  for(int i = 0; i < numPages; i++)
  {
    fault = "";
    if(checkArray(frames, numFrames, pageArray[i])){
    }
    else{
      int temp1 = pageArray[i];
      int temp2;
      
      for(int j = 0; j < numFrames; j++)
      {
        temp2 = frames[j];
        frames[j] = temp1;
        temp1 = temp2;
      }
      fault = "*";
      numFaults++;
    }
    for(int j = 0; j < numFrames; j++)
    {
      if(frames[j] > -1)
      {
        printf("%d ",frames[j]);
      }
    }
    printf("%s\n", fault);
  }
  //print number of faults
  printf("\n Number of faults: %d\n", numFaults);
  printf("--------------------------------- \n");
} //end of function

/*
This function implements optimal algorithm
@param pageArray[]: 
*/
void optimal(int pageArray[])
{
  printf("Optimal: \n");
  char * fault;
  int numFaults = 0; //track number of faults
  int frames[numFrames];
  
  for(int i = 0; i < numFrames; i++)
  {
   frames[i] = -1;
  }
  
  for(int i = 0; i < numPages; i++){
    fault = "";
    if(checkArray(frames, numFrames, pageArray[i])){
    }
    else{
      int victimIndex = 0;
      int victimFound = 0;
      int distance = 0;
      
      for(int j = 0; j < numFrames; j++)
      {  
        victimFound = 0;
        if(fault == "")
        {
          for(int k = i; k < numPages; k++)
          {          
            if(pageArray[k] == frames[j] && victimFound == 0)
            {
              victimFound = 1;
              if(k > distance)
              {
                victimIndex = j;
                distance = k;
              }
            }
          }
          if(victimFound == 0)
          {
            frames[j] = pageArray[i];
            fault = "*";
            numFaults++;
          }
        }        
      }      
    }
    for(int j = 0; j < numFrames; j++)
    {
        printf("%d ",frames[j]);
    }
    printf("%s\n", fault);
  }
  //print number of faults
  printf("\n Number of faults: %d\n", numFaults);
  printf("--------------------------------- \n");
}//end of function

/*
This function implements LRU (least recently used) algorithm
@ param pageArray[]: array of page.
*/
void LRU(int pageArray[])
{  
  printf("LRU: \n" );
  char * fault;
  int numFaults = 0;  //track number of faults
  int frames[numFrames];
  
  for(int i = 0; i < numFrames; i++)
  {
   frames[i] = -1;
  }
  
  for(int i = 0; i < numPages; i++){
    fault = "";
    if(checkArray(frames, numFrames, pageArray[i])){
    }
    else{
      int victimIndex = 0;
      int victimFound = 0;
      int distance = numPages;
      
      for(int j = 0; j < numFrames; j++)
      {
        victimFound = 0;
        if(fault == "")
        {
          for(int k=i-1; k>= 0; k--)
          {
            
            if(pageArray[k] == frames[j] && victimFound == 0)
            {
              victimFound = 1;
              if(k < distance)
              {
                victimIndex = j;
                distance = k;
              }
            }
          }
          if(victimFound == 0)
          {
            frames[j] = pageArray[i];
            fault = "*";
            numFaults++;
          }
        }        
      }  
      if(fault == "")
      {
        frames[victimIndex] = pageArray[i];
        fault = "*";
        numFaults++;
      }    
    }
    for(int j = 0; j < numFrames; j++)
    {
      if(frames[j] > -1)
      {
        printf("%d ",frames[j]);
      }
    }
    printf("%s\n", fault);
  }
  //print number of faults
  printf("\n Number of faults: %d\n", numFaults);
  printf("--------------------------------- \n");
}//end of function

/*
This function implements LFU (least frequently used) algorithm
@ param pageArray[]: array of page.
*/
void LFU(int pageArray[])
{  
  printf("LFU: \n");
  char * fault;
  int numFaults = 0;  //number of faults
  int frames[numFrames]; 
  
  for(int i = 0; i < numFrames; i++)
  {
   frames[i] = -1;
  }
  
  for(int i = 0; i < numPages; i++)
  {
  fault = "";
    if(checkArray(frames, numFrames, pageArray[i])){
    }
    else{
      int victimIndex = 0;
      int victimFound = 0;
      int appearances = 0;
      int leastAppearances = numPages;
      
      for(int j = 0; j < numFrames; j++)
      {
        appearances = 0;
        if(frames[j] == -1)
        {
          appearances = -1;
        }          
        for(int k = i; k < numPages; k++)
        {
          if(pageArray[k] == frames[j])
          {
            appearances++;
          }
        }        
        if(appearances < leastAppearances)
        {
          leastAppearances = appearances;
          victimIndex = j;
        }
      }
        
      frames[victimIndex] = pageArray[i];
      
      fault = "*";
      numFaults++;    
    
    }

    for(int j = 0; j < numFrames; j++)
    {
      if(frames[j] > -1)
      {
        printf("%d ",frames[j]);
      }
    }
    printf("%s\n", fault);
  }

  //print number of faults
  printf("\n Number of faults: %d\n", numFaults);
  printf("--------------------------------- \n");
}//end of function

/*
This function implements MFU (most frequently used) algorithm
@ param pageArray[]: array of page.
*/
void MFU(int pageArray[])
{  
  printf("MFU: \n");
  char * fault;
  int numFaults = 0; //track number of faults
  int frames[numFrames];
  
  for(int i = 0; i < numFrames; i++)
  {
   frames[i] = -1;
  }
  
  for(int i = 0; i < numPages; i++)
  {
  fault = "";
    if(checkArray(frames, numFrames, pageArray[i])){
    }
    else{
      int victimIndex = 0;
      int victimFound = 0;
      int appearances = 0;
      int maxAppearances = 0;

      for(int j = 0; j < numFrames; j++)
      {
        appearances = 0;
        if(frames[j] == -1)
        {
          appearances = numPages;
        }
          
        for(int k = i - 1; k >= 0; k--)
        {
          if(pageArray[k] == frames[j])
          {
            appearances++;
          }
        }        
        if(appearances > maxAppearances)
        {
          maxAppearances = appearances;
          victimIndex = j;
        }
      }
      frames[victimIndex] = pageArray[i];
      fault = "*";
      numFaults++;
    }   
    for(int j = 0; j < numFrames; j++)
    {
      if(frames[j] > -1)
      {
        printf("%d ",frames[j]);
      }
    }
    printf("%s\n", fault);
    
  }
  //print number of faults
  printf("\n Number of faults: %d\n", numFaults);
  printf("--------------------------------- \n");
}// end of function

/*
This function checks if the number is in the array.
*/
int checkArray(int array[], int length, int val)
{
  for(int i = 0; i < length; i++)
  {
    if(array[i] == val)
    {
      return 1;
    }
  }
  return 0;
} //end of function

/*
This is the main function
*/
int main(int argc, char ** argv)
{
  if(argc < 3)
  {
    printf("must input more than 3 numbers");
  }
  else if(atoi(argv[1]) < 1)
  {
    printf("input is not valid.");
  }
  else
  {
    numFrames = atoi(argv[1]);
    numPages = argc-2;
    int pageArray[numPages];

    for(int i = 2; i < argc; i++)
    {
      pageArray[i-2] = atoi(argv[i]);
    }
    FIFO(pageArray); 
    optimal(pageArray);
    LRU(pageArray);
    LFU(pageArray);
    MFU(pageArray);
    printf("\n");
  }
}