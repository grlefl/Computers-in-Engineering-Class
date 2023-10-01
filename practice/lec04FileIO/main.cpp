#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("data.txt"); // Attempt to open file

    if (fin.fail()){ // check if file opened
        cout << "Error: could not open data.txt";
        return -1;
    }

    int num, sum=0, count=0;

#if false // false means the computer will skip this portion of code
    fin >> num;
    while (fin.good()){
        sum += num;
        count++;
        fin >> num;
    }
    // x.good() checks that stream has not raised any errors
    // I guess if file is "bad" (meaning it ends), the loop will stop
    // if there is no space after the last value, this code will not work

#else
    while (!fin.eof()){ // checks for end of file
        fin >> num;
        if(!fin.fail()) { // if previous stream doesn't fail, proceed
            sum += num;
            count++;
        }
    }
    // !fin.fail() means not failing, so as long as file is "good"
    // !fin.eof() means !no more data to be read in the file; use in hw
    // no trickiness for whitespace when using this code
#endif
    fin.close(); // close file

    cout << "ave = " << static_cast<float>(sum)/count << endl;
    return 0;
}