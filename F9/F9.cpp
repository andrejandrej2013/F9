/*******************************************
Andrejs Griņevičs, ag21199
F9. Read text from given text file. Print in output text file a table of letters used in input file (not case sensitive) and number how many times each letter is used. Order output file alphabetically. For example, output file can contain text: a 100 b 23 c 87
Program created: 2022/02/15
*******************************************/

#include <iostream>
#include <fstream>

using namespace std;

char convert_to_letter(int index) {
    return char(index+'a');
}
char convert_to_index(char ch) {
    return (int)(tolower(ch)-'a');
}

void write_to_file(ofstream& fout, int letter_counter[], const int alphabet_size)
{
    for (int i = 0; i < alphabet_size; i++)
    {
        //removes empty values 
        if (letter_counter[i] != 0)
        {
            fout << convert_to_letter(i) << ' ' << letter_counter[i] << '\n';
        }
    }
}


int main()
{
    //set path for files
    string path_initial_file = "initial_file.txt";
    string path_output_file = "output_file.txt";

    //initialize variables
    ifstream fin;
    ofstream fout;
    const int alphabet_size = 26;
    int letter_counter[alphabet_size] = {0};

    //open files with different tasks
    fin.open(path_initial_file);
    fout.open(path_output_file);

    //check if files are open
    if(fin.is_open() and fout.is_open())
    {
        char ch;
        while (fin.get(ch))
        {
            if (isalpha(tolower(ch)))
            {
                letter_counter[convert_to_index(ch)]++;
            }
        }
        write_to_file(fout, letter_counter, alphabet_size);
    }
    else 
    {
        cout << "Files can't be open" << endl;
    }


    //close files and release memory
    fin.close();
    fout.close();


    return 0;
}
