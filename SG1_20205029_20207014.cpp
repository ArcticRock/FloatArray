#include <iostream>
#include <fstream>
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
            this -> size = size;
            arr = new float [size];
            // set array default values = 0
            for (int i=0; i < size; i++) {arr[i] = 0;}
            printArray();
        }
    }

    ~FloatArray() {delete [] arr;}


    // setters
    void setElement(int index, float element){
        if (indexVerfiy(index))
            {arr[index] = element;}
    }

    void setArray(float* newarray)
    {arr=newarray;}

    void setSize(int new_size)  // segmentation error: create  a new array to fit the size
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
        if ( (size >= index) && (index>=0))
            {return true;}
        return false;
    }

    void printArray(){
            cout << "[#] Printing the requested array" << endl;
            for (int i=0; i<size; i++)
            {cout << " " << arr[i];}
            cout << endl;
    }

    void append(float num){
        // create new array
        float* newarr = new float [size+1];
        for (int i=0; i < size; i++)
        {newarr[i] = arr[i];}
        // append value at the end of the array
        newarr[-1] = num;
        // set pointer to new array
        float* tmp = arr;
        arr = newarr;
        cout << "enter a number: ";
        cin >> arr[size];
        delete [] tmp;
        cout << "[#] new element appended" << endl; // testing
    }


    // overloading
    friend ostream& operator << (ostream& out, const FloatArray& arr  );        // read array from file
    friend istream& operator >> (istream& in,FloatArray arr);        // append array to file

    friend class SortedArray;
    friend class FrontArray;
};


class SortedArray: public FloatArray
{

public:
    // constructors
    SortedArray(int size): FloatArray(size){
        keepSorted();
        cout << "[~] Sorted Float Array created" << endl;
    }
    // setters
        void setElement(int index, float element){
            FloatArray::setElement(index, element);
            keepSorted();
    }

    // methods
    void keepSorted(){         // ascending order
        sort(arr, arr+size, less<float>());
        // sort( float arr,  array + size, greater<float>()); for decending order
        cout << "[~] Array resorted" <<endl; // testing
    }

    bool isPositive(float value){
        if (value>=0) {return true;}
    else return false;
    }

    // error in add function: adding at any index ruins the elements after it excluding the last


    void add(float num) {
        // create bigger array
        float* newarr = new float [size+1];
        int counter = 0;
        for (int i = 0; i < size; i++){
            // adds new value if its smaller than the old array value once
            
            if (num <= arr[i]){
                newarr[i] = num; // i = 2  - i = 3
                newarr[i+1] = arr[i]; //newarr[3] = arr[2](4)
                counter++;
                break;
            }
            else {newarr[i]= arr[i]; counter++;} //newarr[4] =
        
        }
        cout<<"counter is: "<<counter<<endl;
        for (int k = size; k >= counter; k--) { // k = 6 || counter = 3 || size = 5
            newarr[k] = arr[k-1];
        }
        
        // set pointer to new array
        size++;
        //delete [] arr;
        arr = newarr;
        //delete [] tmp;
        //delete [] newarr;
        cout << "[#] new element appended" << endl; // testing
    }
};
/*

[1, 2, 4, 7, 9]
                10
[1, 2, 3, 4, 7, 9]
add(3)

if new value < arr[i] -> set arr[i] = new value
if new value > arr[i] -> set arr[i] = old value

*/

class FrontArray: public FloatArray
{
    public:
    // constructors
    FrontArray(int size): FloatArray(size)
    {cout << "[!] front array created" << endl;}


    // methods
    bool add(float value){
        // create new array
        float* newarr = new float [size+1];
        for (int i=0; i < size; i++)
        {newarr[i+1] = arr[i];}
        // add value at the start of the array
        newarr[0] = value;
        // set pointer to new array
        float* tmp = arr;
        arr = newarr;
        delete [] tmp;
        // testing
        if (arr[0] == value){
            std::cout << "[#] element appended" << endl;
            return true;
        }
        return false;
    }
};




class PositiveArray: public SortedArray
{
    // constructors
    PositiveArray(int size): SortedArray(size){
        cout << "[!] positive array created" << endl;
    }
    // methods
    bool add(float value){
        // if value is positive add value
        if (isPositive(value))
        {add (value); return true;}
        return false;
    }
};


class NegativeArray : public SortedArray
{
    // constructors
    NegativeArray(int size): SortedArray(size)
    { cout << "Negative array created"<< endl;}
    // methods
    bool add(float value){
        if (!isPositive(value)){
            add (value);
            return true;
        }
        else return false;
    }
};



int main ()
{
    SortedArray here(5);
    float n[5] = {2,0.6,4,10,8};
    here.setArray(n);
    here.keepSorted();
    here.printArray();
    
    //add where is right test
    here.add(1);
    here.printArray();
    return 0;
}


/*
    NOTE: this need to be done taking into considration using polymorphism in main function
*/
