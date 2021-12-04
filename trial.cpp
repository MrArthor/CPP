/*
File: Implementation.cpp
Author: Mr Arthor
Procedures:

-uniform - provides a random uniform number
-scan - simulates the scan search policy
-cscan - simulates the cscan search policy
-fifo - simulates the first in first out policy
-sstf - simulates the sstf policy
 */

#include <iostream>      //cin, cout
#include <stdio.h>       //printf
#include <stdlib.h>      //srand, rand
#include <time.h>        //time
#include <cstddef>       //size_t
#include <bits/stdc++.h> //
#include <vector>        //vector
#include <fstream>       //ifstream
using namespace std;

int uniform(int, int);             //provides a random uniform number
int scan(int, int[], int[], int);  //simulates the scan scheduling policy
int cscan(int, int[], int[], int); //simulates the cscan scheduling policy
int fifo(int, int[], int[], int);  //simulates the first in first out policy
int sstf(int, int[], int[], int);  //simulates the sstf policy

int main() //
{
    srand(time(NULL));                                     //seed the random number generator
    int InitialHeadLocation = 5000 / 2;                    //initial head location
    int scanSeekTimeAverage = 0, cscanSeekTimeAverage = 0; //average seek time for scan policy
    int fifoSeekTimeAverage = 0, sstfSeekTimeAverage = 0;  //average seek time for fifo policy

    for (int i = 0; i < 10; i++)
    {
        int Requests = uniform(500, 1000); //number of Requests
        int TracksRequested[Requests];     //array of requested tracks
        int SectorsRequested[Requests];    //array of requested sectors
        for (int y = 0; y < Requests; y++) //populate the arrays
        {
            TracksRequested[y] = uniform(0, 5000);   //populate the track array
            SectorsRequested[y] = uniform(0, 12000); //populate the sector array
        }

        cout << "Number of Requests: " << Requests << endl; //print the number of Requests

        scanSeekTimeAverage += scan(Requests, TracksRequested, SectorsRequested, InitialHeadLocation);                                 //calculate the average seek time for scan policy
        cout << "Scan Avg Seek " << i + 1 << " :" << scan(Requests, TracksRequested, SectorsRequested, InitialHeadLocation) << endl;   //print the average seek time for scan policy
        cscanSeekTimeAverage += cscan(Requests, TracksRequested, SectorsRequested, InitialHeadLocation);                               //calculate the average seek time for cscan policy
        cout << "cScan Avg Seek " << i + 1 << " :" << cscan(Requests, TracksRequested, SectorsRequested, InitialHeadLocation) << endl; //print the average seek time for cscan policy
        fifoSeekTimeAverage += fifo(Requests, TracksRequested, SectorsRequested, InitialHeadLocation);                                 //calculate the average seek time for fifo policy
        cout << "Fifo Avg Seek " << i + 1 << " :" << scan(Requests, TracksRequested, SectorsRequested, InitialHeadLocation) << endl;   //print the average seek time for fifo policy
        sstfSeekTimeAverage += sstf(Requests, TracksRequested, SectorsRequested, InitialHeadLocation);                                 //calculate the average seek time for sstf policy
        cout << "SSTF Avg Seek " << i + 1 << " :" << sstf(Requests, TracksRequested, SectorsRequested, InitialHeadLocation) << endl;   //print the average seek time for sstf policy

        cout << "------------------------" << endl; //print a line
    }

    scanSeekTimeAverage = scanSeekTimeAverage / 10;                          //calculate the average seek time for scan policy
    cscanSeekTimeAverage = cscanSeekTimeAverage / 10;                        //calculate the average seek time for cscan policy
    fifoSeekTimeAverage = fifoSeekTimeAverage / 10;                          //calculate the average seek time for fifo policy
    sstfSeekTimeAverage = sstfSeekTimeAverage / 10;                          //calculate the average seek time for sstf policy
    cout << "Scan Overall Avg Seek Time: " << scanSeekTimeAverage << endl;   //print the average seek time for scan policy
    cout << "cScan Overall Avg Seek Time: " << cscanSeekTimeAverage << endl; //print the average seek time for cscan policy
    cout << "Fifo Overall Avg Seek Time: " << fifoSeekTimeAverage << endl;   //print the average seek time for fifo policy
    cout << "SSTF Overall Avg Seek Time: " << sstfSeekTimeAverage << endl;   //print the average seek time for sstf policy

    return 0; //end program
}

int uniform(int low, int high) //provides a random uniform number
{
top:
    int x;
    int y = high - low + 1;
    int z = rand() / y;

    if (z == 0)
    {
        goto top;
    }

    while (y <= (x = (rand() / z)))
        ;

    return x + low;
}

int scan(int Requests, int TracksRequested[], int SectorsRequested[], int InitialHeadLocation) //simulates the scan scheduling policy
{

    vector<int> TrackTemp;
    vector<int> TrackTemp2;

    for (int i = 0; i < Requests; i++)
    {
        if (TracksRequested[i] >= InitialHeadLocation)
        {
            TrackTemp.push_back(TracksRequested[i]);
        }
        else
        {
            TrackTemp2.push_back(TracksRequested[i]);
        }
    }
    int Size1 = TrackTemp.size();
    int Size2 = TrackTemp2.size();
    vector<int> mergedTracks(Requests);

    sort(TrackTemp.begin(), TrackTemp.end());//sort the vector
    sort(TrackTemp2.begin(), TrackTemp2.end(), greater<int>());//sort the vector

    for (int i = 0; i < Size1; i++)

    {
        mergedTracks[i] = TrackTemp[i];
    }
    int mergeSize = mergedTracks.size();

    int x = 0;
    for (int i = Size1; i < mergeSize; i++)
    {
        mergedTracks[i] = TrackTemp2[x];
        x++;
    }

    vector<int> TraversedTracks(Requests);
    vector<int> TraversedSectors(Requests);
    vector<int> STimes(Requests);

    for (int i = 0; i < Size1; i++)
    {

        if (i != Size1)
        {
            TraversedTracks[i] = TrackTemp[i + 1] - TrackTemp[i];

            for (int y = 0; y < SectorsRequested[i]; y++)
            {
                TraversedSectors[i] = SectorsRequested[i];
            }
        }
    }
    for (int i = 0; i < Size2; i++)
    {
        if (i != Size2)
        {
            TraversedTracks[i + Size1] = TrackTemp2[i] - TrackTemp2[i + 1];

            for (int y = 0; y < SectorsRequested[i + Size1]; y++)
            {
                TraversedSectors[i + Size1] = SectorsRequested[i + Size1];
            }
        }
    }

    for (int i = 0; i < Requests; i++)
    {

        STimes[i] = TraversedTracks[i] + TraversedSectors[i];
    }
    long SeekTimeAverage = 0;

    for (int i = 0; i < Requests; i++)
    {
        SeekTimeAverage += STimes[i];
    }

    if (Requests != 0)
    {
        SeekTimeAverage = SeekTimeAverage / Requests;
    }
    else
    {
        cout << "Number Of Requests Is Hardcoded Is 0" << endl;
    }
    return SeekTimeAverage;
}

int cscan(int Requests, int TracksRequested[], int SectorsRequested[], int InitialHeadLocation)//simulates the cscan
{
    vector<int> TrackTemp;
    vector<int> TrackTemp2;

    for (int i = 0; i < Requests; i++)
    {
        if (TracksRequested[i] >= InitialHeadLocation)//if the track is greater than the initial head location
        {
            TrackTemp.push_back(TracksRequested[i]);//push the track to the vector
        }
        else
        {
            TrackTemp2.push_back(TracksRequested[i]);//push the track to the vector
        }
       
    }

    int Size1 = TrackTemp.size();//get the size of the vector
    int Size2 = TrackTemp2.size();//get the size of the vector
    vector<int> mergedTracks(Requests);//create a vector of the size of the requests

    sort(TrackTemp.begin(), TrackTemp.end());//sort the vector
    sort(TrackTemp2.begin(), TrackTemp2.end());

    for (int i = 0; i < Size1; i++)
    {
        mergedTracks[i] = TrackTemp[i];//push the track to the vector
    }

    int x = 0;//set x to 0
    int mergedSize = mergedTracks.size();//get the size of the vector

    for (int i = Size1; i < mergedSize; i++)
    {
        mergedTracks[i] = TrackTemp2[x];
        x++;
    }

    vector<int> TraversedTracks(Requests);
    vector<int> TraversedSectors(Requests);
    vector<int> STimes(Requests);

    for (int i = 0; i < Size1; i++)
    {
        if (i != Size1)
        {
            TraversedTracks[i] = TrackTemp[i + 1] - TrackTemp[i];

            for (int y = 0; y < SectorsRequested[i]; y++)
            {
                TraversedSectors[i] = SectorsRequested[i];
            }
        }
    }

    for (int i = 0; i < Size2; i++)
    {
        if (i != Size2)
        {
            TraversedTracks[i + Size1] = TrackTemp2[i + 1] - TrackTemp2[i];

            for (int y = 0; y < SectorsRequested[i + Size1]; y++)
            {
                TraversedSectors[i + Size1] = SectorsRequested[i] + Size1;
            }
        }
    }

    for (int i = 0; i < Requests; i++)
    {
        STimes[i] = TraversedTracks[i] + TraversedSectors[i];
    }

    long SeekTimeAverage = 0;

    for (int i = 0; i < Requests; i++)
    {
        SeekTimeAverage += STimes[i];
    }

    if (Requests != 0)
    {
        SeekTimeAverage = SeekTimeAverage / Requests;
    }
    else
    {
        cout << "Number Of Requests Is Hardcoded Is 0" << endl;
    }
    return SeekTimeAverage;
}

int fifo(int Requests, int TracksRequested[], int SectorsRequested[], int InitialHeadLocation)//simulate the fifo scheduling policy
{
    vector<int> TrackTemp(Requests);
    vector<int> TraversedTracks(Requests);
    vector<int> TraversedSectors(Requests);
    vector<int> seekTime(Requests);
    for (int i = 0; i < Requests; i++)
    {
        TrackTemp[i] = TracksRequested[i];
        TraversedSectors[i] = SectorsRequested[i];
    }

    for (int i = 0; i < Requests; i++)
    {
        if (i != Requests)
        {
            if (TrackTemp[i] - (TrackTemp[i + 1]) >= 0)
            {
                TraversedTracks[i] = TrackTemp[i] - TrackTemp[i + 1];
            }
            else if (TrackTemp[i + 1] - (TrackTemp[i]) >= 0)
            {
                TraversedTracks[i] = TrackTemp[i + 1] - TrackTemp[i];
            }
        }
    }

    for (int i = 0; i < Requests; i++)
    {
        seekTime[i] = TraversedTracks[i] + TraversedSectors[i];
    }

    long SeekTimeAverage = 0;

    for (int i = 0; i < Requests; i++)
    {
        SeekTimeAverage += seekTime[i];
    }

    if (Requests != 0)
    {
        SeekTimeAverage = SeekTimeAverage / Requests;
    }
    else
    {
        cout << "Number Of Requests Is Hardcoded Is 0" << endl;
    }
    return SeekTimeAverage;
}

int sstf(int Requests, int TracksRequested[], int SectorsRequested[], int InitialHeadLocation)
{
    vector<int> TrackTemp(Requests);
    vector<int> tempSector(Requests);
    int currentDifference = 2500;
    vector<int> TraversedTracks(Requests);
    for (int i = 0; i < Requests; i++)
    {
        TrackTemp[i] = TracksRequested[i];
        tempSector[i] = SectorsRequested[i];
    }

    for (int i = 0; i < Requests; i++)
    {

        currentDifference = 2500;
        for (int y = i + 1; y < Requests; y++)
        {
            if (y != Requests)
            {
                if ((TrackTemp[i] - TrackTemp[y]) >= 0)
                {
                    if ((TrackTemp[i] - TrackTemp[y]) < currentDifference)
                    {
                        currentDifference = TrackTemp[i] - TrackTemp[y];
                    }
                }
                else if ((TrackTemp[y] - TrackTemp[i]) >= 0)
                {
                    if ((TrackTemp[y] - TrackTemp[i]) < currentDifference)
                    {
                        currentDifference = TrackTemp[y] - TrackTemp[i];
                    }
                }
            }
        }
        TraversedTracks[i] = currentDifference;
    }

    vector<int> seekTime(Requests);

    for (int i = 0; i < Requests; i++)
    {
        seekTime[i] = TraversedTracks[i] + tempSector[i];
    }

    long SeekTimeAverage = 0;

    for (int i = 0; i < Requests; i++)
    {
        SeekTimeAverage += seekTime[i];
    }

    if (Requests != 0)
    {
        SeekTimeAverage = SeekTimeAverage / Requests;
    }
    else
    {
        cout << "Number Of Requests Is Hardcoded Is 0" << endl;
    }
    return SeekTimeAverage;
}