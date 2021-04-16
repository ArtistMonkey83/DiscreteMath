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

/*Function to swap two elements
void swaped(int &y, int &r)
{
    int temp = y;
    y = r;
    r = temp;
}
*/

// Recursive function to find and print all permutations of a string
void permutes(string str, int i, int n)
{

    if (i == n - 1)                             // Base condition if index is equal to the last element in the string
    {
        cout << str[0] << str[1] <<str[2] << endl;                    // Cout the string as is and return to calling function
        return;
    }

    for (int j = i; j < n; j++)                 // Process each character of the remaining string
    {
        //swaped(str[i], str[j]);                 // Swap a character at index with the current character using swaped method

        int temp = str[i];
            str[i] = str[j];
            str[j] = temp;


        permutes(str, i + 1, n);                // Recursive call for substring starting at element 2 and ending before the last element

            temp = str[i];
            str[i] = str[j];
            str[j] = temp;

        //swaped(str[i], str[j]);                 // Restoring the string to its original state using backtracking method
    }
}

// Main function gets input from commandline and calls permutes function
int main(int argc, const char **argv)
{
    string str = argv[2];  // Initializing str to the value of the argv variable, which was passed via command line
    permutes(str, 0, str.length());             // Calling permutation function with the local copy of the argv[2] string, the starting point of 0 element and the end of the string

    return 0;
}
