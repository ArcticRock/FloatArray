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
		}
		
		int getSize() {return size;}
		

		// methods
		bool indexVerfiy(int index){
			if (size >= index && index>0) 
				{return true;}  
		}
		
		void printArray(){
				std::cout << "[#] Printing the requested array" << endl;
				for (int i=0; i<size; i++)
				{std::cout << " " << arr[i];}
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
			std::cout << "[#] new element appended" << endl; // testing
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
	public:
		// constructors
		SortedArray(int size): FloatArray(size){
			keepSorted();
			std::cout << "[~] Sorted Float Array created" << std::endl;
		}
		
		
		// methods
		void append(float num) {
			FloatArray::append(num);
		   	keepSorted();
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

/*
	NOTE: this need to be done taking into considration using polymorphism in main function
		  using virtual functions is a MUST.
*/
