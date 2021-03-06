#pragma once

// workshop 1 - Modular Programming
// graph.h
//Hongback Son( 133181163 , hbson1@myseneca.ca)



#ifndef SICT_GRAPH_H
#define SICT_GRAPH_H


namespace sict{

// Fills the samples array with the statistic samples
void getSamples(int samples[], int noOfSamples);

// Finds the largest sample in the samples array, if it is larger than 70,
// therwise it will return 70.
int findMax(int samples[], int noOfSamples);

// Prints a scaled bar relevant to the maximum value in samples array
void printBar(int val, int max);

// Prints a graph comparing the sample values visually
void printGraph(int samples[], int noOfSamples);

// Performs a fool-proof integer entry
int getInt(int min, int max);

}

#endif

