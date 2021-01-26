//Array ADT for multiple Data Types

//Change the typedef for accomodating multiple data type
typedef int infi;

//for higher dimensional array
typedef long long INT;

// Array ADT 
typedef struct array{
    INT total_size;
    INT used_size;
    infi* start;    
}array;

//Array Functions
void init(array *A1,int tsize); //Initialises the array with total size
void append(array *A1, infi data); //Inserts an element at end of array
void display(array A1); //Displays the entire array
void insert(array *A1,INT position,infi data); //Inserts an element at a specified index