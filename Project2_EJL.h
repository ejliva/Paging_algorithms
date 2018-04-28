/*
Earl John Liva
CEG-4350-01 Spring 2018
Project 1: Producer / Consumer Problem
Project2_EJL.h 
This is the header file
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//global variables
int numPages;
int numFrames;


//functions
void FIFO(int pageArray[]);
void Optimal();
void LRU(int pageArray[]);
void LFU(int pageArray[]);
void MFU(int pageArray[]);
int checkArray(int array[], int arrayLength, int value);