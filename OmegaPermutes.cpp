/*
Write a single source file program to do the following:

parse parameters (I will include this part in class) of the command in the following order:
argv[1] is a base-10 number as the number of trials per experiment
argv[2] is a null-terminated string where each UTF-8 character represents an element in the initial set of trial outcomes //This is the pool of things we have to choose from
All trials are without replacement, the number of outcomes of the initial trial is greater than or equal to the number of trials per experiment "the number of things out putting"
the output should be organized in lines
each line represents a possible experiment permutation outcome
each permutation outcome should appear once and only once in the output
each line contains characters representing elements of the trial outcome set without separators (no spaces, no commas, etc.)
remove any debugging messages from your program prior to turning it in, the output of the program should consists only of lines of experiment outcomes as described
Example:

./a.out 2 abc //abc is one string

output:

ab
ba
ac
ca
bc
cb

This program must be done in C or C++, the source code is to be turned in. Your code should not require any additional modules, libraries or extensions other than what the language natively supports. If you use CodeBlocks, please turn in a ZIP file of the project folder. If the whole program is in a single file, turn in that file. If the program is in various files, turn in a ZIP file of those individual files.

NO COMBINATION AT ALL a group of people and there are chairs
*/
#include <iostream>

using namespace std;


toPermute( int permCounter, const char permVariable)
{
  permVariable      //what am I doing with the first person? matching up with the left over options

}


int main(int argc, const char **argv)     //convert to a number, argc is counter for the number of choices and argv is the value pointer array
{
  string groupOfPeople; //to hold the data after permutation
  char toPermute; //to hold the character we are currently evaluating
  int seats, //number of choices
      counter = argc;
  groupOfPeople = argv[2];//assign the values we are passing
  seats = atoi(argv[1]);// value passed that represents the number of options

  for (int i = 0; i < groupOfPeople.length();i++)
    {
      //cout << groupOfPeople[i] << " groupOfPeople @ " << i << endl;
      toPermute = groupOfPeople[i];
      if(counter > 0)      // if the counter is not at the start of the string call permutation function recurisvely
        {
          perm(argc,toPermute);   //pass the counter and toPermute character to the permutation function to generate output
          counter--;              //we get here when we have permutated through all options decrement counter for some reason to keep track of how many times we have done this....is it required? feels extra

          cout << counter << " counter @ " << i << " \n;"
        }
      else              //if the counter is at the start of the string we are done return to calling function
        { return 1; }
    }
  return 0;
}
