/* Name: Grace Flores
 * Date: September 9th, 2022
 * Program Description:     This program analyzes data collected in a corn field
 *                          using a Baumer radar sensor.
 * Inputs and Outputs:  The user will input a number that defines height of a corn plant. The program
 *                      will compute and return the mean and standard deviation values of the following data:
 *                      speed of the sprayer (mph)
                        altitude above mean sea level (meters)
                        number of satellites being received
                        temperature (degrees Celcius)
                        height of corn plant (inches)
                        relative humidity above a corn plant (%)
                        relative humidity below a corn plant (%)
 */

#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>

using namespace std;

// initializing functions (elaborate)
double averageVector(vector<double> & data);
double stdVector(vector<double> & data);

int main() {

    //attempt to open file
    ifstream fin("baumerRadarSensorData.csv");
    //67ifstream fin("test_file.txt"); //UNDO
    //what does "s:" mean?

    //if file fails
    if (fin.fail()) {
        cout << "Error: could not open data.txt";
        return -1;
    }

#if true
    /* Data Needed:
     * speed of sprayer
     * altitude above mean sea level in meters
     * number of satellites
     * temperature in C
     * height of corn plant in inches (difference between canopy height and ground height)
     * relative humidity above corn plant
     * relative humidity below corn plant
     */

    // initializing vectors;
    // vectors automatically resize to fit incoming information
    vector<double> Speed; //mph
    vector<double> Altitude; //meters above mean sea level
    vector<double> Num_of_satellites;
    vector<double> Temperature; //C
    vector<double> Humidity; //%
    vector<double> Canopy_height; //inches
    vector<double> Ground_height; //inches

    // throw away first line
    string line;
    getline(fin, line);
    // while loop
    // for each line, read in each string portion with getline and "," delimiter
    // only save string portions that are necessary
    // convert string portions to doubles
    // add double value to respective vector
    while(!fin.eof()) {

        // for loop
        // 17 columns , 16 getline() with delimiter
        string data;
        for (int i=0; i < 16; i++) {
            getline(fin, data, ',');

            // speed data
            if (i==4) {
              Speed.push_back(stod(data));
            }

            // altitude data
            else if (i==6) {
              Altitude.push_back(stod(data));
            }

            // number of satellites data
            else if (i==7) {
                Num_of_satellites.push_back(stod(data));
            }

            // humidity data
            else if (i==8) {
                Humidity.push_back(stod(data));
            }

            // temperature data
            else if (i==9) {
                Temperature.push_back(stod(data));
            }

            // canopy height data
            else if (i==12) {
                Canopy_height.push_back(stod(data));
            }

            // ground height data
            else if (i==15) {
                Ground_height.push_back(stod(data));
            }
        }

        // account for last value without "," delimiter
        getline(fin,line);

    }

    // Corn Height Definition
    // prompt user to enter minimum corn height in inches
    // only the values equal to or above the minimum height will be used
    double corn_height;
    cout << "Define the minimum height of a corn plant (in inches): ";
    cin >> corn_height;

    // some new vectors with new values will be made from the original vectors
    // corn height
    // initializing new vectors
    vector<double> Height; //meters
    vector<double> Humidity_above_height;
    vector<double> Humidity_below_height;

    // creating new vectors
    // subtract ground height from canopy height to make Height vector
    // this will have to be a for loop
    for(int i=0; i<Canopy_height.size(); i++) {
        Height.push_back(fabs(Canopy_height[i]-Ground_height[i]));
    }

    // new vector for humidity above corn_height
    // for loop, if statement
    for(int i=0; i<Height.size(); i++) {
        if (Height[i]>corn_height) {
          Humidity_above_height.push_back(Humidity[i]);
        }
    }

    // new vector for humidity below corn_height
    // for loop, if statement
    for(int i=0; i<Height.size(); i++) {
        if (Height[i]<corn_height) {
            Humidity_below_height.push_back(Humidity[i]);
        }
    }

    // closing the file
#endif
fin.close();

    // once all the necessary vectors are present, use average and standard  78
    // ... deviation functions on each
    // don't save these values as variables, skip to cout
    // print statement
    cout << "\nThe average speed of the sprayer was " << averageVector(Speed) << " mph with standard deviation " << stdVector(Speed) << " mph.\n";
    cout << "The average altitude above mean sea level was " << averageVector(Altitude) << " meters with standard deviation " << stdVector(Altitude) << " meters.\n";
    cout << "The average number of satellites was " << averageVector(Num_of_satellites) << " with standard deviation " << stdVector(Num_of_satellites) << ".\n";
    cout << "The average temperature was " << averageVector(Temperature) << " C with standard deviation " << stdVector(Temperature) << " C.\n";
    cout << "The average height of the corn plants was " << averageVector(Height) << " inches with standard deviation " << stdVector(Height) << " inches.\n";
    cout << "The average relative humidity when above corn plants was " << averageVector(Humidity_above_height) << "% with standard deviation " << stdVector(Humidity_above_height) << "%.\n";
    cout << "The average relative humidity when below corn plants was " << averageVector(Humidity_below_height) << "% with standard deviation " << stdVector(Humidity_below_height) << "%.\n";

    return 0;
}

// Functions (elaborate)

// average vector function: After inputting a vector, this function will return the average value
//                          of that vector.
double averageVector(vector<double> & data) {
    double sum = 0;
    for(int i=0; i<data.size(); i++) {
           sum += data[i];
    }
    return sum/data.size();
}

// standard deviation vector function:  After inputting a vector, this function will return the standard
//                                      deviation of the vector.
double stdVector(vector<double> & data) {
    // find the mean of the data
    double mean = averageVector(data);
    // for each data point, find the square of its distance to the mean
    // and sum these values
    double sum = 0;
    for(int i=0; i<data.size(); i++) {
        sum += (mean-data[i])*(mean-data[i]);
    }
    // square root of (sum/number of data points)
    return sqrt(sum/data.size());
}