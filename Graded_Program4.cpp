//// ---------------------------------------------------------------------------
//// BEGIN: Write function getArray2D DONT_ERASE_03_1
//// The function should return a 2D array to the main function
//// Call the function getArray1D in this function
int** getArray2D(int m,int n,int** Array)
{
  Array=new int*[m];
  for(int i=0;i<m;i++)
  {
    Array[i]=getArray1D(n,Array[i]);
  }
  return Array;
}


//// END: End of function code DONT_ERASE_03_1
//// ---------------------------------------------------------------------------



int main() {
  int **Array;
  int m, n;
  cin>>m>>n;
  Array = getArray2D(m,n,Array);
  for(int i=0;i<m;i++)
    for(int j=0;j<n;j++){
      cin >> Array[i][j];
    }
    cout<<endl;
  for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
      cout<<Array[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}

