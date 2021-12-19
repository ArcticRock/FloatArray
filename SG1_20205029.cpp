#include <iostream>
#include <fstream>
#include <string>
#include <array>
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
		}
		
		int getSize() {return size;}
		

		// methods
		bool indexVerfiy(int index){
			if (size >= index && index>0) 
				{return true;}  
		}
		
		void append(float num){
			// create new array
			float* newarr = new float [size+1];
			for (int i=0; i < size; i++)
			{newarr[i] = arr[i];}
			// set pointer to new array
			float* tmp = arr;
			arr = newarr;
			delete [] tmp;
			std::cout << "[#] element appended" << endl; // testing
		}


		// overloading
		//friend classes
		friend class SortedArray;
};


class SortedArray: public FloatArray
{
	private:
		void keepSorted() 		// ascending order
		{
			std::sort(arr, arr+size, std::less<float>());
			// sort( float arr,  array + size, greater<float>()); for decending order
			std::cout << "[~] Array Sorted" << std::endl; // testing
		}
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
