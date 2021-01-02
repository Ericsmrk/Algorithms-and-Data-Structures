//CSCi 115 --Lab 3.1
//Insertion sort program
//Eric Smrkovsky
//9/13/2020

//This program performs the selection sort searching algorithm with a half
//sorted array of size 'n' for input. you can uncomment a different 'arr[]' array
//if you want to test the best(sorted) or worst(backwards) case inputs.
//this program will display the time taken for the cpu to run the algorithm.
//for best results, close all running background programs.

#include <iostream>
#include <ctime> //needed for the clock function
using namespace std;

//selection sort function
void selSort(int arr[], int n){

    int temp;
    //loop through the list once for each index
    for(int minimum = 0; minimum < n-1; minimum++){

        //for each index,loop through the remaining array
        for(int i = minimum+1; i < n; i++){

            //for each iteration of the inner for loop,
            //compare the remaining array contents and swap min with smallest
            if(arr[i] < arr[minimum]){
                temp = arr[minimum];
                arr[minimum] = arr[i];
                arr[i] = temp;
            }
        }
    }
}

main(){

    //Variables

    //int arr[] = {399,398,397,396,395,394,393,392,391,390,389,388,387,386,385,384,383,382,381,380,379,378,
    //377,376,375,374,373,372,371,370,369,368,367,366,365,364,363,362,361,360,359,358,357,356,355,354,353,
    //352,351,350,349,348,347,346,345,344,343,342,341,340,339,338,337,336,335,334,333,332,331,330,329,328,
    //327,326,325,324,323,322,321,320,319,318,317,316,315,314,313,312,311,310,309,308,307,306,305,304,303,
    //302,301,300,299,298,297,296,295,294,293,292,291,290,289,288,287,286,285,284,283,282,281,280,279,278,
    //277,276,275,274,273,272,271,270,269,268,267,266,265,264,263,262,261,260,259,258,257,256,255,254,253,
    //252,251,250,249,248,247,246,245,244,243,242,241,240,239,238,237,236,235,234,233,232,231,230,229,228,
    //227,226,225,224,223,222,221,220,219,218,217,216,215,214,213,212,211,210,209,208,207,206,205,204,203,
    //202,201,200,199,198,197,196,195,194,193,192,191,190,189,188,187,186,185,184,183,182,181,180,179,178,
    //177,176,175,174,173,172,171,170,169,168,167,166,165,164,163,162,161,160,159,158,157,156,155,154,153,
    //152,151,150,149,148,147,146,145,144,143,142,141,140,139,138,137,136,135,134,133,132,131,130,129,128,
    //127,126,125,124,123,122,121,120,119,118,117,116,115,114,113,112,111,110,109,108,107,106,105,104,103,
    //102,101,100,99,98,97,96,95,94,93,92,91,90,89,88,87,86,85,84,83,82,81,80,79,78,77,76,75,74,73,72,71,
    //70,69,68,67,66,65,64,63,62,61,60,59,58,57,56,55,54,53,52,51,50,49,48,47,46,45,44,43,42,41,40,39,38,
    //37,36,35,34,33,32,31,30,29,28,27,26,25,24,23,22,21,20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2
    //,1,0};//worst case

    //int arr[] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,
    //31,32,33,34,35,36,37,38,39,40,41,42,43,44,45,46,47,48,49,50,51,52,53,54,55,56,57,58,59,60,61,62,63,
    //64,65,66,67,68,69,70,71,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,88,89,90,91,92,93,94,95,96,
    //97,98,99,100,101,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,120,121,122,
    //123,124,125,126,127,128,129,130,131,132,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,
    //148,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,171,172,
    //173,174,175,176,177,178,179,180,181,182,183,184,185,186,187,188,189,190,191,192,193,194,195,196,197,
    //198,199,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,217,218,219,220,221,222,
    //223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,242,243,244,245,246,247,
    //248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,266,267,268,269,270,271,272,
    //273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,291,292,293,294,295,296,297,
    //298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,316,317,318,319,320,321,322,
    //323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,341,342,343,344,345,346,347,
    //348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,366,367,368,369,370,371,372,373,
    //374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,392,393,394,395,396,397,
    //398,399};//sorted input(best)

    int arr[] = {46,19,61,59,74,147,85,190,148,35,2,11,90,73,62,82,112,124,116,30,15,166,23,143,79,
    58,36,3,160,193,165,176,4,170,138,121,34,6,29,20,39,42,72,183,5,70,103,128,181,196,80,16,71,150,
    25,105,164,56,50,168,174,146,159,114,154,91,67,28,37,123,194,186,68,88,149,197,161,172,199,48,187,
    41,189,1,155,156,9,83,134,57,167,104,140,32,152,22,93,54,45,27,198,95,18,100,24,102,60,84,12,145,
    65,55,7,31,108,151,89,153,109,192,11,97,144,120,0,94,76,115,64,77,75,184,163,52,157,96,101,117,
    44,110,43,21,180,51,125,86,131,122,78,17,195,130,33,177,173,139,92,99,113,162,38,142,137,10,185,
    13,53,26,126,107,81,132,47,178,14,136,87,135,158,182,127,66,106,169,191,171,8,175,129,179,98,69,
    188,119,40,133,118,141,49,63,200,201,202,203,204,205,206,207,208,209,210,211,212,213,214,215,216,
    217,218,219,220,221,222,223,224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239,240,241,
    242,243,244,245,246,247,248,249,250,251,252,253,254,255,256,257,258,259,260,261,262,263,264,265,
    266,267,268,269,270,271,272,273,274,275,276,277,278,279,280,281,282,283,284,285,286,287,288,289,290,
    291,292,293,294,295,296,297,298,299,300,301,302,303,304,305,306,307,308,309,310,311,312,313,314,315,
    316,317,318,319,320,321,322,323,324,325,326,327,328,329,330,331,332,333,334,335,336,337,338,339,340,
    341,342,343,344,345,346,347,348,349,350,351,352,353,354,355,356,357,358,359,360,361,362,363,364,365,
    366,367,368,369,370,371,372,373,374,375,376,377,378,379,380,381,382,383,384,385,386,387,388,389,390,391,
    392,393,394,395,396,397,398,399};////half sorted input(average)

    int n = sizeof(arr)/sizeof(arr[0]);//provides the size of the input array
    clock_t func_time;         //create variable of arithmetic type 'clock_t'

    //display name, class, date and small description
    cout << "----------------------------------------------------------------\n";
    cout << "----------------------------------------------------------------\n";
    cout << "-----------        An Insertion Sort Program         -----------\n";
    cout << "----------------------------------------------------------------\n";
    cout << "-------------------------------------------- Eric Smrkovsky ----\n";
    cout << "--------------------------------------------    9/13/2020   ----\n";
    cout << "--------------------------------------------    CSCi 115    ----\n";
    cout << "----------------------------------------------------------------\n";
    cout << "----------------------------------------------------------------\n\n\n\n\n";

    //display the array to sort
    cout << "Unsorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i];
        if(i != n-1){cout  << ", ";}
    }
    cout << "\n\n";

    //record start time of algorithm
    func_time = (float)clock();

    //call the selection sort function
    selSort(arr, n);

    //record execution time of algorithm
    func_time = (clock() - func_time);

    //display the sorted array
    cout << "Sorted array: ";
    for(int i = 0; i < n; i++){
        cout << arr[i];
        if(i != n-1){cout  << ", ";}
    }
    cout << endl;

    //display the execution time of the algorithim
    cout << "Time: " << (float)func_time/CLOCKS_PER_SEC; //display execution time
    cout << " seconds.\n\n\n";

}
