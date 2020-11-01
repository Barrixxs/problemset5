# problemset5
This problem set will introduce you to nested loops, the break and continue keywords, and file input/output. In this problem set,
you will Improve on the program you have been developing in the previous assignments by adding the ability to input/output
with files. This will allow you to process more information as the user will have to interact with your program less as they will
provide their input as data in a file. Be sure to read this problem set thoroughly, especially the sections of Collaboration and the
Hand-in Procedure.
Collaboration
Collaboration amongst students is allowed to the extent outlined in the syllabus. That being the case, the goal of these
assignments is not to share code, but to learn the tools you need to succeed as a computer scientist. Students are expected to
write their own code free of plagiarism from any other student past or current. All assignments will be cross referenced across
all sections of CS135 using the Measure Of Software Similarity (Moss) to automatically determine the similarity of programs.
Refer to the syllabus for further details and consequences of breaking this policy.
Program: Calculating Distance From Airplanes To Multiple Airports
Problem 1
The pilots at the airplane company are upset they have to manually input all of this data so the airplane company wants to
update your program to automatically calculate distance from their airplanes to airports from logs their inflight systems create.
The data your program will take in will come in the form of .txt files with ‘ ‘ being the delimiter to the data. Your program will
now need to take in 4 command line arguments: ./a.out and 3 user specified arguments. The 3 arguments specified by the user
should be 3 .txt files. The first .txt file will contain points where airports are located which you want to locate distance to. The
second .txt file will contain points representing where the airplanes are during their flight paths. The third .txt file will be the file
you want to output the distances to after calculations.
Just as in the previous assignment you will have to display a usage message as shown below if only ./a.out is entered by the user
as shown below. You will also have to display an error if either 1 or 4 command line arguments are not entered as shown below.
No error checking needs to be done on the files yet as they will be error checked in the next problem. Build a program that:
1. Gets 4 command line arguments from the user as described above.
a. If “./a.out” is entered display, “Usage: ./a.out dataFile queryFile outputFile" and terminate the program.
b. If # command line args != 1 or 4 an error, "Error: Incorrect amount of command line arguments," should
occur and the program should terminate.
To check that this problem is complete, verify your program is printing as shown in the example output.
Problem 2
Now that you have verified you have the correct amount of inputs from the pilot, you must verify that the files they want to read
from actually exist. The first thing we need to do to accomplish this is to include the fstream library so that we can perform file
input/output. We will then need to create 3 separate variables to hold the 3 files the pilot enters in problem 1, 2 input files and 1
output file. We then need to try to open each file into their respective ifstream/ofstream variables and error if they fail to open.
Each file should display an appropriate error as shown in the example output if a file fails to open. Add to your program:
1. 3 variables to hold your input and output files.
2. Error checking on each file entered to make sure the user entered a file that is actually there. If the file fails to open an
error should be displayed exactly as shown in the example output, and the program should be terminated.
To check that this problem is complete, enter in file names that do not exist for the 2nd/3rd command line arguments. These
incorrect file names should trigger errors as shown in the example output and terminate your program. The output file will not
show an error if an incorrect file name is entered as it will just create the file, but make sure to add error checking on the
opening of the output file in case something does go wrong and it does fail.
Problem 3
Now that we have files to read data from we need to read from those files and perform calculations on the data read in. In this
example, as in many examples in life, we have nicely structured data so we can take in our data from the file in the form of
rows. Each row in the query file will represent an (x, y) pair which is the location of an airplane currently flying. Each row in
the data file will represent an (x, y) pair followed by a label for the pair which is the location of an airport and the airport code,
or name, of the airport.
You will need to calculate the distance from each query point (airplane locations .txt file) to each data point (airport locations
.txt file). To do this you will need to add nested loops. A general flow of your nested loops is as follows:
1. Get a point S from the query file (AirplaneLocations.txt).
2. Calculate the man/euc distance from S to point 0 in the data file (AirportLocations.txt) and output it to a file.
3. Calculate the man/euc distance from S to point 1 in the data file and output it to a file.
…
4. Calculate the man/euc distance from S to point n in the data file and output it to a file.
5. Reset the data file to be read from the beginning.
6. Continue with the next point in the query file from 1 until all query points have been read.
Note: Step 1 is the outer loop, and steps 2-5 is the nested loop
To reset the data file to be read from the beginning use the code:
ifstream.clear();1
ifstream.seekg(0, ios::beg);2
You must make sure that if there is an error reading in data at any point you display an appropriate error as shown in the
example output and skip the row. If the error is in the query file (airplane locations) the skipped row should not only skip
inputting the query data point, but also running the nested loop for that iteration. If the error is in the data file (airport locations)
the skipped row should only skip that one row of input/calculations. Add to your program:
1. The ability to take in query points in one by one in an outer loop. If invalid input is received while taking in the query
point, an appropriate error should be displayed as shown in the example output.
2. The ability to take in data points one by one in a loop nested in the outer loop in part 1. If invalid input is received
while taking in the data point, an appropriate error should be displayed as shown in the example output.
3. The ability to run manhattan distance and euclidean distance on each query point with each data point.
4. The ability to output these calculations to an output file along with their label as shown in the example output.
