


//The objective of this program
//is to request a file from user
//that may be opened to read contents
// of the file and output the
//vertical additive symmetry - 
//sums each column and adds the value of each column

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<sstream>
#include<iomanip>


using namespace std;

//set prototype to check symmetry of
void checkSymmetry(double symm[], const int columns);
int main()
{

  //set variables for reading data
  ifstream inputFile;
  string filename;
  string line1;
  string line2;
  string entries;
  short int number;
  int x, y, i, j;


  //prompt user to enter name of file through a string
  //& ensure user has entered a filename
  cout << "Please enter a filename: ";
  getline(cin, filename);
  if (cin.fail()){
    cin.clear();
    cin.ignore(10000, '\n');
  }
  //open the file
  inputFile.open(filename.c_str());


  //if file cannot be open send an error message
  //else open the file
  if (!inputFile)
    {
      cout << "Error: Filename does not exist";
      cout << " or could not be opened";
    }

  else
    {
      cout << "File was successfully opened!" << endl;


      //once file is open read first two valid numbers
      //these valid numbers should be assigned
      //as the rows and columns

      //use vector to store the values of columns and rows
      vector <int> numbers;
      for (int i = 0; i < 2; i++)
	{
	  //read the rows and columns numbers
	  inputFile >> number;

	  //if not valid entries output an error message
	  if(!(number))
	    {
	      cout << "Values in file are not valid and cannot be read.";
	      return 0;
	    }
	  numbers.push_back(number);
	}


      //get the rows and columns from the vector
      //used to read the first two valid numbers
      const int NUM_OF_ROWS = numbers[0];
      const int NUM_OF_COLUMNS = numbers[1];

      //validate that rows and columns is a valid entry
      if((NUM_OF_ROWS <= 0 ) || (NUM_OF_COLUMNS <= 0) )
	{
	  cout << "ERROR: Number of rows and columns ";
	  cout << "is a negative number or 0" << endl;
	  return 0;
	}

      //if valid entry proceed to read
      //values that will be inserted into
      //the two-dimensional array
      else
	{

	  //initialize the vector with the rows and
	  //columns gather from the vector
	  double data[NUM_OF_ROWS][NUM_OF_COLUMNS];

	  //read the rest of the data from
	  //file into the two-dimensional array
	  for (x = 0; x <NUM_OF_ROWS; x++){
	    for(y = 0; y < NUM_OF_COLUMNS; y++)
	      {
		inputFile >> data[x][y];
		if(data[x][y] == !(number))
		  {
		    cout << "Error in amount of data";
		    return 0;
		  }

	      }
	  }




	  //set up a different array
	  //that gathers the sums of each of the columns
	  //this array will later be used in order
	  //to detect vertical additive symmetry
	  double total;
	  double symm[NUM_OF_COLUMNS];

	  for(i = 0; i < NUM_OF_COLUMNS; ++i)
            {
	      total = 0;
	      for(j = 0; j < NUM_OF_ROWS; ++ j)
                {
		  total += data[j][i];
		  symm[i] = total;
                }
            }


	  //call the function to check symmetry

	  checkSymmetry(symm, NUM_OF_COLUMNS);

	  //sort array where each row is printed
	  //in descending order
	  //using selection sort

	  for (int k = 0; k < NUM_OF_ROWS; k++)
            {
	      for (int m = 0; m < NUM_OF_COLUMNS; m++)
                {
		  x = m+1;
		  for (int i = k; i < NUM_OF_ROWS ; i++)
                    {
		      for (int j = x; j < NUM_OF_COLUMNS; j++)
                        {
			  if (data [k][m] < data [i][j])
                            swap(data [k][m] ,data [i][j]);
                        }
		      x=0;
                    }
                } cout << endl;
            }


	  //display the values in descending order from
	  //the selection sort
	  for (int i = 0; i < NUM_OF_ROWS; i++)
            {
	      for (int j = 0; j < NUM_OF_COLUMNS; j++)
                {
		  cout << setw(6) << data [i][j] << " ";
                }
	      cout << endl;
            }
        }
    }
  //close file correctly
  inputFile.close();

  return 0;

}


//function use to determine vertical
//additive symmetry
void checkSymmetry(double symm[], const int columns){


  //set a different array that has the same values
  //as the array where the values of the columns
  //where added

  //this array will have the values backwards
  //in order to compare original array that reads forwards
  //and new array that reads backwards
  double newSymm[columns];;
  int i, j;
  for(i = 0, j = (columns -1)  ; i < columns; i++, j--)
    {
      newSymm[i] = symm[j];
    }



  //compare arrays using a boolean
  bool symmetry = true;
  for(i = 0; i < columns; i++)
    {
      if(symm[i] != newSymm[i])
	//false if arrays do not read the same
	symmetry = false;
    }

  if (symmetry == true)
    {
      //display if arrays had equal elements
      cout << endl;
      cout << "Vertical additive symmetry" << endl;
    }
  else
    {
      //display if arrays had different elements
      cout << endl;
      cout << "No vertical additive symmetry" << endl;
    }
}
