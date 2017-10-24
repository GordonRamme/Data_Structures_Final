/* 
 * File:   main.cpp
 * Author: o_o, KILL 65,
 *
 * Created on October 4, 2017, 9:14 PM
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include <list>
#include <ctime>

#include "customheaders.h"

using namespace std;
using namespace custom;

List < double > make_random_list ();    //creates a linked list of random numbers

List < double > Sort_alg_1 ( List < double > in );  //first algorithm that sorts the list

List < double > Sort_alg_2 ( List < double > in );  //second algorithm that sorts the list

int main(int argc, char** argv) 

{
    
    List < double > random = make_random_list ();
    
    return 0;
    
}

List < double > make_random_list ()

{
    
    srand ( 1 );    //makes random number generator
    
    List < double > out;    //initializes linked list
    
    for ( int i = 0; i < 500000; i ++ ) //linked list is going to be half a million nodes long
        
    {
    
    out.Push ( rand () );  //adds a random number to the linked list
    
    }
    
    return out;
    
}

List < double > Sort_alg_1 ( List < double > in )

{
    
    
    
}

List < double > Sort_alg_2 ( List < double > in )

{
    
    
    
}