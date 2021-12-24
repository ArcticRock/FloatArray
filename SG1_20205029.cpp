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
            // set array default values = 0
            for (int i=0; i < size; i++) {arr[i] = 0;}
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

    void append(float num){
        // create new array
        float* newarr = new float [size+1];
        for (int i=0; i < size; i++)
        {newarr[i] = arr[i];}
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
    //friend classes
    friend class SortedArray;
};


class SortedArray: public FloatArray
{
private:
    float tmp_2;
    float tmp_3;

public:
    // constructors
    SortedArray(int size): FloatArray(size){
        keepSorted();
        cout << "[~] Sorted Float Array created" << endl;
    }
    
    // methods
    void keepSorted()         // ascending order
    {
        sort(arr, arr+size, less<float>());
        // sort( float arr,  array + size, greater<float>()); for decending order
        cout << "[~] Array Sorted" <<endl; // testing
    }

    bool isPositive(float value){
        if (value>=0) {return true;}
	else return false;
    }		


    void append(float num) {
        float* newarr = new float [size+1];
        for (int i=0; i < size; i++)
        {newarr[i] = arr[i];}
        // set pointer to new array
        float* tmp = arr;
        arr = newarr;
        cout << "enter a number: ";
        cin >> tmp_2;
        for (int i = 0 ; i < size+1; i++) {
            if(tmp_2 < arr[i]) //condition to find the right position of the input number
            {
                for (int j = i; j < size+1; j++) { /* if the right position of number found move the position of each number after the right                                         position in arr by 1 */
                    tmp_3 = arr[i];
                    arr[i+1] = tmp_3;
                }
                arr[i] = tmp_2;
                break;
            }
        }
        delete [] tmp;
        cout << "[#] new element appended" << endl; // testing
           
    }
};



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
		for (int i=1; i < size; i++)
		{newarr[i] = arr[i];}
		// add value at the start of the array
		newarr[0] = value;
		// set pointer to new array
		float* tmp = arr;
		arr = newarr;
		delete [] tmp;
		// testing
		if (arr[-1] == value){
			std::cout << "[#] element appended" << endl;
			return true;
		}
		return false
	}
};




class PositiveArray: public SortedArray
{
	// constructors
	PositiveArray(int size): SortedArray(size){
		cout << "[!] positive array created" << endl;
	}
	// methods
	bool add(float value){						// required method
		// if value is positive add value
		if (isPositive(value)) 
		{add (value); return true;}
		return false;
	}
};


class NegativeArray : SortedArray(size)
{
	// constructors
	NegativeArray(int size): SortedArray(size)
	{ cout << "Negative array created"<< endl;}
	// methods
	bool add(float value){
		if (!isPositive(value)
		{add (value); return true;}
		return false;
	}
};


/*
    NOTE: this need to be done taking into considration using polymorphism in main function
          using virtual functions is a MUST.
*/
