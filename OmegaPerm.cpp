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

*/

#include <iostream>

using namespace std;

// A recursive function to print all permutations of a string with a selected number of trials supplied from command line by user
void permutes(string str, int i, int n, int choices)
{

    if (i == n - 1)                       // Base condition if index is equal to the last element in the string print it out
    {
      for(int i = 0; i < choices; i++)    // For loop to iterate through the trial's outcome using argv[1]'s value for choices
        {cout << str[i];}                   // Print the outcome of one trial using the string in argv[2] passed from command line

      cout << endl;                       // Starts a new line for the next trials outcome to be printed on

      return;                             // Return to the calling function, break out of this if statement
    }

    for (int j = i; j < n; j++)           // We execute this line of code if the base case is not met yet
    {                                     // Starting at element 0 and ending at the last element in the string
        int temp = str[i];                // Declare a local variable temp to hold the value of the argv[2] string at element i
            str[i] = str[j];              // Swap the string at element i with the element at j
            str[j] = temp;                // Swap the string at element j with the element i was initially


        permutes(str, i + 1, n, choices); // Recursive call for substring starting at element 2 and ending before the last element

            temp = str[i];                // Use local variable to temporairily hold the value of string at element i
            str[i] = str[j];              // Swap the string at element i with the element at j
            str[j] = temp;                // Swap string at element j with element i was initially after the permutes function call
    }
}

// Main function gets input from command line and calls the recursive permutes function
int main(int argc, const char **argv)
{
    string str = argv[2];         // Initializing to the value of the string passed via command line to argv variable
    permutes(str, 0, str.length(), atoi(argv[1]));  // Calling permutation function with the local copy of the argv[2] string

    return 0;
}
