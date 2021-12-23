#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
using namespace std;

/*
file formate:-
array1size element1 element2.....
array2size element4 element5.....
*/

class FloatArray
{
private:
    float* arr;
    int size;
public:
    // consturctors
    FloatArray(int size){
        if (size > 0){
            arr = new float [size];
            // set array default values = 99999999
            for (int i=0; i < size; i++) {arr[i] = 99999999;}
        }
    }
    
    ~FloatArray() {delete [] arr;}
    

    // setters
    void setElement(int index, float element){
        if (indexVerfiy(index))
            {arr[index] = element;}
    }
    
    void setSize(int new_size)
    {size = new_size;}
    

    // getters
    float getElement(int index){
            if ( indexVerfiy(index) )
            {return arr[index];}
        return 0;
    }
    
    int getSize() {return size;}
    

    // methods
    bool indexVerfiy(int index){
        if (size >= index && index>0)
            {return true;}
        return false;
    }
    
    void printArray(){
            cout << "[#] Printing the requested array" << endl;
            for (int i=0; i<size; i++)
            {cout << " " << arr[i];}
    }

    void add(float num){
        // create new array
        float* newarr = new float [size+1];
        for (int i=0; i < size; i++)
        {newarr[i] = arr[i];}
        // set pointer to new array
        float* tmp = arr;
        arr = newarr;
        for (int i = 0; i < size + 1; i++)
        {cout << "enter a number: "; cin >> arr[size];}
        
        delete [] tmp;
        cout << "[#] new element appended" << endl; // testing
    }


    // overloading
    friend ostream& operator << (ostream& out, const FloatArray& arr  );        // read array from file
    friend istream& operator >> (istream& in,FloatArray arr);        // append array to file
    //friend classes
    friend class SortedArray;
};


class SortedArray: public FloatArray
{
private:
    
public:
    // constructors
    SortedArray(int size): FloatArray(size){
        cout << "[~] Sorted Float Array created" << endl;
    }
    
    // methods
    void add(float num) {
        
        float input_num = 0;
        
        
        cout << "Enter size of the array: ";
        cin >> size;

        
        
        /*for (int i = 0; i < size; i++) {
            arr[i] = 99999;                  Maybe not needed as array is intialazed in parent class
        }*/
        
        for (int k = 0; k < size; k++) {
            
            cout<<"Enter a number: ";
            cin>>input_num;
            
            
            for (int i = 0; i < size; i++) {
                if(input_num < arr[i])
                {
                    for (int n = size - 1; n > i-1; n--) {
                        arr[n+1] = arr[n];
                    }
                    arr[i] = input_num;
                    
                    for (int f = 0; f < size; f++) {
                        cout<<"number "<<f+1<<" "<<arr[f]<<endl;
                    }
                    
                    break;
                }
            }
            
        }
};



class FrontArray: public FloatArray
{
    void append(float num){
        
    }
};



class PositiveArray
{

};



class NegativeArray
{

};


  /*  NOTE: this need to be done taking into considration using polymorphism in main function
          using virtual functions is a MUST.
*/
