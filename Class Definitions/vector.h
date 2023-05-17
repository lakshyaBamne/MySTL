/*
    vector containers in STL using raw C++

    header file
*/
#pragma once

#include<iostream>

using namespace std;

class vector{
private:
    int size;
    int capacity;
    int* array = NULL;

public:
    // default constructor
    vector() : size(0), capacity(0){
        array = new int[capacity];

        cout << "Default Constructor called !" << endl;

        // print the vector for checking
        this->print_vector();
    }

    // constructor with a given vector size
    vector(int size) : size(0), capacity(size){
        array = new int[capacity];

        cout << "Modified Constructor-1 called !" << endl;

        // print the vector for checking
        this->print_vector();
    }

    // constructor with a given vector size
    // as well as initial value for all the elements
    vector(int size, int value) : size(size), capacity(size){
        
        if(value){
            array = new int[capacity];

            for(int i=0 ; i<size ; i++){
                array[i] = value;
            }
        }
        else{
            array = new int[capacity]{};
        }

        cout << "Modified Constructor-2 called !" << endl;

        // print the vector for checking
        this->print_vector();
    }

    // method to get the size of the array
    // size is the number of elements entered into the array
    int get_size(){
        return size;
    }

    // method to get the capacity of the array
    // capacity is the number of elements that the vector can hold
    // without resizing
    int get_capacity(){
        return capacity;
    }

    bool empty(){
        if(size){
            return false;
        }
        else{
            return true;
        }
    }

    // method to print the vector in it's current state
    void print_vector(){
        cout << "--------------------------------------------------------------------" << endl;
        if(size){
            cout << "vector state :- ";
            for(int i=0 ; i<size ; i++){
                cout << array[i] << " ";
            }
            cout << endl;
        }
        else{
            cout << "vector is empty !!" << endl;
        }
        cout << "--------------------------------------------------------------------" << endl;
    }

    // method to resize the vector to a given size
    void resize(int new_size){
        cout << "Resized vector!!";
        cout << "Old vector :- ";
        for(int i=0 ; i<size ; i++){
            cout << array[i] << " ";
        }
        cout << endl;

        int* new_vector = new int[new_size];

        for(int i=0 ; i<size ; i++){
            new_vector[i] = array[i];
        }

        size = new_size;
        capacity = new_size*2;

        delete[] array;
        array = new_vector;

        cout << "New vector :- ";
        for(int i=0 ; i<size ; i++){
            cout << array[i] << " ";
        }
        cout << endl;


    }

    // overloading the subscript operator in C++ to be used by the vectors
    // overloading returns a reference to the element pointed to by the given index
    int& operator[](int index){
        // we can employ array out of bounds check using this overloading definition
        if(index>=size || index<(-1*size)){
            cout << "vector index out of bound! exiting";
            exit(EXIT_FAILURE);
        }

        if(index<0){
            return array[index+size];
        }

        return array[index];
    }

    // method to shrink the length of the vector to exactly the size
    // destroy all elements not used in the capacity
    void shrink_to_fit(){
        int* new_vector = new int[size];

        for(int i=0 ; i<size ; i++){
            new_vector[i] = array[i];
        }

        capacity = size;

        delete[] array;

        array = new_vector;
    }

    // another method to mimic the subscript operator
    int& at(int index){
        // we can employ array out of bounds check using this overloading definition
        if(index>=size || index<(-1*size)){
            cout << "vector index out of bound! exiting";
            exit(EXIT_FAILURE);
        }

        if(index<0){
            return array[index+size];
        }

        return array[index];
    }

    // method returns the reference to the first element in the vector
    int& front(){
        return array[0];
    }

    // method returns the reference to the last element in the vector
    int& back(){
        return this->at(-1);
    }

    // Returns a direct pointer to the memory array used internally by 
    // the vector to store its owned elements
    int* data(){
        return array;
    }

    

};

