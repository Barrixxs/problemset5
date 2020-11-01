//Kevin Barrios
//NSHE 2001697903
//Problem Set 5
#include <iostream> // cin, cout
#include <iomanip> // setprecision
#include <string> // stod, strings...
#include <fstream> // ifstream, ofstream
#include <cmath> // pow sqrt

using namespace std;

int main(int argc, char const *argv[]) {

// define variables
  ifstream inData, inQuery;
  ofstream outputFile;
// defining variables for 2 major loops
  string line, label, label2, linex, liney;
  double x, y, x2, y2;
  string delimiter = " ";

// validation to make sure correct number of
// command line arguments are being used
  if (argc == 1)
  {
    cout << "Usage: ./a.out dataFile queryFile outputFile";
    return 0;
  } else if (argc !=1 && argc != 4)
  {
    cout << "Error: Incorrect amount of command line arguments,";
    return 0;
  }

// assigning input streams and output streams with the command line text names.
  inData.open(argv[1]);
  inQuery.open(argv[2]);
  outputFile.open(argv[3]);

// output an error message and terminate program if file cant open
  if (inData.fail()){
    cout << "Error: Invalid data file extension";
    return 0;
  } else if (inQuery.fail()){
    cout << "Error: Invalid query file extenstion";
    return 0;
  } else if (outputFile.fail()){
    outputFile << "Invalid outputfile";
    return 0;
  }

//First major loop is the outer loop that grabs input from the
//QUERY text files and assigns them to point values and labels
  while (getline(inQuery, line)) {

// this method was got by TA it basically splits the line up to
// different substrings each time it reaches a space or " "
    linex = line.substr(0, line.find(delimiter));
    line.erase(0, line.find(delimiter) + delimiter.length());
    liney = line.substr(0, line.find(delimiter));
    line.erase(0, line.find(delimiter) + delimiter.length());
    label = line.substr(0, line.find(delimiter));
    line.erase(0, line.find(delimiter) + delimiter.length());

// loop to error check the value inputted
    if (linex[linex.length() -1] != '0'){
      cout << "Error: Invalid x1 entry\n";
      line.clear();
    } else if (liney[liney.length() -1] != '0'){
      cout << "Error: Invalid y1 entry\n";
      line.clear();
    } else{
      x = stod(linex);
      y = stod(liney);
    }

// outputs a header to the outputfile
    outputFile << "x1 y1 label" << endl;
    outputFile << linex << " " << liney << " " << label << endl;
    outputFile << "manDist eucDist label" << endl;


//Second major loop its the inner loop that grabs input from the
//DATA text files and assigns them to point values and labesl
// NOTE: This while loop is nested inside the other while loop.
    while (getline(inData, line)){

    // same method from before
      linex = line.substr(0, line.find(delimiter));
      line.erase(0, line.find(delimiter) + delimiter.length());
      liney = line.substr(0, line.find(delimiter));
      line.erase(0, line.find(delimiter) + delimiter.length());
      label2 = line.substr(0, line.find(delimiter));
      line.erase(0, line.find(delimiter) + delimiter.length());

    // error check x and y values
      if (linex[linex.length() -1] != '0'){
        cout << "Error: Invalid x2 entry\n";
        line.clear();
      } else if (liney[liney.length() -1] != '0'){
        cout << "Error: Invalid y2 entry\n";
        line.clear();
      } else{
        // if no errors calculate the distance and output them to the output file
        x2 = stod(linex);
        y2 = stod(liney);
        double manhattan = abs((x2-x)) + abs((y2 -y));
        double euclidean = sqrt(pow(x2-x, 2) + pow(y2-y, 2));
        outputFile << fixed << setprecision(1) << manhattan << " " << euclidean << " " << label2 << endl;
      }
    }

// allow datafile to be read from the top again.
    inData.clear();
    inData.seekg(0, ios::beg);
    outputFile << endl;

  }

// close open files and end the program.
  inData.close();
  inQuery.close();
  outputFile.close();
  return 0;
}
