//This question was later considered wrong as something went wrong with the autograder.
#include<iostream>
#include <cmath>
using namespace std;


// Please write your code, within the "BEGIN-END" blocks given below.
// A "BEGIN-END" block is identified as follows :
//
// "//// BEGIN: Some string DONT_ERASE_xx_yy"
// 
//
// "//// END: Some other string DONT_ERASE_xx_yy"
//
// where "xx" is the block number and "yy" is the
// marks allocated for the block
//
// The FIRST block (BLOCK 1 i.e. DONT_ERASE_01_0) carries 0 marks and 
// is a placeholder for your personal information, to be written as a comment.
//
// WARNING :
// (1) Do NOT write any cout or cin statements
// (2) Do NOT delete or modify the existing code i.e. main function, comments, blocks, etc.
// (3) Write your code in between BEGIN and END of the respective blocks only
// (4) Do NOT rename the .cpp file

//// ---------------------------------------------------------------------------
//// BEGIN: Fill your details as comments below DONT_ERASE_01_0
//// Name:
////
//// END: Fill your details as comments above DONT_ERASE_01_0
//// ---------------------------------------------------------------------------

int comparator(float marksarray[][2], int index1, int index2);
int selectionSort2(float array[][2], int numElements);
int merge(float sortedarray[][2], float mergedarray[][2], int break_point, int numElements);

int main()
{
    float studentmarks[100][2]= {0}, mergedmarks[100][2] = {0};
    int i, j, N;

    cout<<"Enter no. of students"<<endl;
    cin >> N;	// Enter number of the students
    if ((N < 0) || (N >= 100))
    {
        cout << "Invalid input!" << endl;
        return -1;
    }

    cout << "Enter marks of all students: " << endl;
    for(i=0; i<N; i++)
    {
        cout << "Student " << i+1 << " :" << endl;
        cout << "Midsem: ";
        cin >> studentmarks[i][0];
        cout << "Endsem: ";
        cin >> studentmarks[i][1];
        cout << endl;
    }

    cout << "Comparison results:" << endl;
    for(i=0; i < N; i++)
    {
        for(j=0; j < N; j++)
        {
            cout << "(" << i << "," << j << ") : " << comparator(studentmarks,i,j) << endl;
        }
        cout << endl;
    }

    int break_point = selectionSort2(studentmarks, N);

    cout << endl << "Break point detected at row : " << break_point << endl << endl;
    cout<< "Sorted marks: " << endl;
    for(i=0; i < N ; i++)
    {
        cout << studentmarks[i][0] <<" "<< studentmarks[i][1]<<endl;
    }
    int nonDuplicate = merge(studentmarks, mergedmarks, break_point, N);

    cout << endl << "Merged marks: "<<endl;
    for(i=0; i<nonDuplicate; i++)
    {
        cout << mergedmarks[i][0] <<" "<< mergedmarks[i][1] << endl;
    }
    return 0;
}

int comparator(float marksarray[][2],int index1, int index2)
{
////-----------------------------------------------------------------------
//// BEGIN: write your code to calculate RMS, compare them, and return either -1, 0, or 1  DONT_ERASE_02_01
    float rms1,rms2;
    rms1=pow((0.5*((marksarray[index1][0]*marksarray[index1][0])+(marksarray[index1][1]*marksarray[index1][1]))),0.5);
    rms2=pow((0.5*((marksarray[index2][0]*marksarray[index2][0])+(marksarray[index2][1]*marksarray[index2][1]))),0.5);
    if(rms1>rms2){
      return -1;
    }
    else if(rms2>rms1){
      return 0;
    }
    else if(rms1==rms2){
      if(marksarray[index1][1]>marksarray[index2][1])
	return -1;
      else if(marksarray[index1][1]<marksarray[index2][1])
	return 0;
      else if(marksarray[index1][1]==marksarray[index2][1]){
	return 1;
      }
    }
      

////END: End of function code 'compare' DONT_ERASE_02_01
////------------------------------------------------------------------------
}


int selectionSort2(float array[][2], int numElements)
{
////-----------------------------------------------------------------------
//// BEGIN: write your code to find out the breakpoint Sort the upper part of array (if required) DONT_ERASE_03_01
//// Hint: Use the comparator function
int i=numElements-1,bp=numElements,temp;
while(i>=0)
{
  temp=comparator(array,i,i-1);
  switch(temp)
  {
    case -1:
      bp=i;
      break;
    case 0:
     i--;
      break;
    case 1:
      bp=i;
      break;
    default:
      break;
  }
  if(bp<numElements)
    break;
}
//SORT 
int min=0,temp1,temp2,c,j;
for(i=0;i<bp;i++)
{
  min=i;
  for(j=i+1;j<bp;j++)
  {
    c=comparator(array,min,j);
    if(c==-1)
    {

      min=j;
    }
  }
      temp1=array[min][0];
      array[min][0]=array[i][0];
      array[i][0]=temp1;
      
      temp2=array[min][1];
      array[min][1]=array[i][1];
      array[i][1]=temp2;
  
  
}
return bp;
////END: End of function code DONT_ERASE_03_01
////-----------------------------------------------------------------------
}


int merge(float sortedarray[][2], float mergedarray[][2], int break_point, int numElements)
{
////----------------------------------------------------------------------------
//// BEGIN: Write your code to merge non-duplicate array rows of Part A and Part B DONT_ERASE_04_01
//REMOVE DUPLICATE
 int start=0,i1,j1,i=0,c,j=numElements-1,temp=numElements,temp1,temp2;
while(i<break_point)
{
  while(j>=break_point)
  {
    c=comparator(sortedarray,i,j);
    if(c==1)
    {
     for(i1=i;i1<numElements;i1++){
      sortedarray[i1][0]=sortedarray[i1+1][0];
      sortedarray[i1][1]=sortedarray[i1+1][1];
      
     }
     numElements--;
     break_point--;
     j--;
      for(j1=j+1;j1<numElements ;j1++){
      sortedarray[j1-1][0]=sortedarray[j1][0];
      sortedarray[j1-1][1]=sortedarray[j1][1];
      
     }
     numElements--;
    }
    else{
      j--;
    }
  }
  i++;
      
} 
//nonDuplicate=numElements;
i=0;
j=numElements-1;
while(i<break_point && j>=break_point)
{
  c=comparator(sortedarray,i,j);
  if(c==-1)
  {
    mergedarray[start][0]=sortedarray[j][0];
    mergedarray[start][1]=sortedarray[j][1];
    j--;
    start++;
  }
  else if(c==0)
  {
    mergedarray[start][0]=sortedarray[i][0];
    mergedarray[start][1]=sortedarray[i][1];
    i++;
    start++;
  }
  else if(c==1)
  {
    i++;
    j--;
  }
}
while(i<break_point)
{
  mergedarray[start][0]=sortedarray[i][0];
  mergedarray[start][1]=sortedarray[i][1];
  start++;
  i++;
}
while(j>=break_point)
{
  mergedarray[start][0]=sortedarray[j][0];
    mergedarray[start][1]=sortedarray[j][1];
    j--;
    start++;
}
return start;


//// END: End of your code to merge   DONT_ERASE_04_01
////---------------------------------------------------------------------------------
}

