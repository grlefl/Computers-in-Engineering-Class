#include <iostream>
#include <vector>

using namespace std;

double averageArray(const double data[], int size);
double averageVector(vector<double> & data);
double averageArray2(const double data[], int size);

int main() {
    double values[] = {1.0, 3.5, 2.0, 4.3};
    vector<double> values2 = {1.0, 3.0, 4, 5};

    cout << "average1 = " << averageArray(values, 4) << endl;
    cout << "average2 = " << averageVector(values2);

    return 0;
}

double averageArray(const double data[], int size){
    double sum=0;
    for(int i = 0; i < size; i++){
        sum += data[i];
    }
    return sum/size;
}

double averageArray2(const double data[], int size){
    double sum=0;
    for(int i = 0; i < size; i++){
        sum += data[i];
    }
    return sum/size;
}

double averageVector(vector<double> & data){
    double sum=0;
    for(int i = 0; i < data.size(); i++){
        sum += data[i];
    }
    return sum/data.size();
}