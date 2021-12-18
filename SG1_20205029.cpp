#include <ostream>
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
		float* array;
		int size;
	public:
		// consturctors
		FloatArray(int size);
		~FloatArray(){delete [] array;};
		// setters
		void setElement(int index, float element);
		void setSize(int new_size);
		// getters
		float getElement(int index);
		int getSize(){return size;}
		// methodsa
		bool indexVerfiy(int num);		
		// overloading
		friend ostream& operator << (FloatArray array, ostream& data);		// read array from file	
		friend istream& operator >> (FloatArray array, istream& data);		// append array to file
		//friend classes
		friend class SortedArray;
};


class SortedArray: public FloatArray
{
	private:
		void keepSorted()
		{sort(array, array + array.size, greater<float>());} 	// sort( float* arr, int array_size, greater<float>());

};



class FrontArray
{

};



class PositiveArray
{

};



class NegativeArray
{

};
