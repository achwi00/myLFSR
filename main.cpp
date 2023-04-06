#include <iostream>
#include <cmath>
using namespace std;
int a,f;

int* Shift(int *array, int n)//executes the shifts
{
    f=array[n-1];//save the last element as it'll be next element of generated sequence
    //next is just an xor gate for last 2 elements, save the result in variable a
    if(((array[n-1]==1)&&(array[n-2]==0))||((array[n-1]==0)&&(array[n-2]==1)))
    {
        a=1;
    }
    else a=0;
    //move each element to the right by changing the index to the one of the previous element
    for (int i = n-1; i >0; --i)
    {
        array[i]=array[i-1];
    }
    array[0]=a;//a becomest first element of our array
//    for (int i = 0; i < n; ++i) {
//        cout<<array[i];
//    }
    return array;
}

void Display(int* array, int n)//just prints the elemets of the array of size n
{
    for (int i = 0; i < n; ++i) {
        cout<<array[i];
    }
}
void GenerateRand(int* array, int m)//next element is our current f
{
    array[m]=f;
}

int main()
{
    int n=4;//size of register/ 5number of bits in register
    string initial_state="1101";//initial state of length n, you can change it but leave the length of 4
    int * TAB=new int[n-1];
    //check if length of initial state== n
    int j=0;
    while(initial_state[j])
    {
        j++;//increase j by 1 to calculate how long is initial state
    }
    //checks if the initial state is of entered lenght n
    if(j!=n)//compare to n
    {
        cout<<"size of initial state differs from the entered one\n";
        exit(0);//stop working if length of initial state !=n
    }
    //checking if initial state consists of 1s and 0s only, stop if it's not
    for (int i = 0; i < n; ++i)
    {
        TAB[i]=initial_state[i]-'0';
        //checks if initial state is correct
        if ((TAB[i]>1)||(TAB[i]<0))
        {
            cout<<"incorrect value of initial state"<<"in element "<<i+1<<", of value "<<TAB[i]<<endl;
            break;
        }
    }
    cout<<"states of the register:\n";
    Display(TAB,n);//display first state, we have to do this prior to changing state
    cout<<endl;

    //actual shifting part
    int size=pow(2,n)-1;//we should have generated sequence of length (2^n)-1
    int * Rand= new int[size];//array for generated pseudorandom sequence

    for (int i = 0; i <size; ++i)
    {
        Shift(TAB,n);//shift
        Display(TAB,n);//display current state
        GenerateRand(Rand,i);//initialise new element of random sequence
        cout<<endl;
    }
    cout<<endl<<endl<<"generated sequence: "<<endl;

    Display(Rand, size);//display generated sequence

}
