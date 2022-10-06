#include <iostream>
#include <vector>
using namespace std;

void printAllPermutations(int index, vector<string> &output, string &str)
{
    // base case
    if (index == str.length())
    {
        output.push_back(str);
        return;
    }

    for (int j = index; j < str.length(); j++)
    {
        swap(str[index], str[j]);

        printAllPermutations(index + 1, output, str);

        // backtrack
        swap(str[index], str[j]);
    }
}
int main()
{
    vector<string> output;
    string str = "abc";
    int index = 0;

    printAllPermutations(index, output, str);

    // printing
    cout<<"printing all permutations"<<endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout <<i+1<<". "<< output[i] << endl;
    }
    cout << endl;

    return 0;
}