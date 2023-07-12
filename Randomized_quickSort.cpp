#include <iostream>
#include <cstdlib>
using namespace std;

int num;
int comps = 0, swaps = 0;


int partition(int *arr, int p, int r){
	int i = p - 1;
    int x = arr[r];
    for(int j = p; j < r; j++){
    comps++;
   	 if(arr[j] <= x){
   		 i++;
   		 swaps++;
   		 swap(arr[i], arr[j]);
   	 }
    }
    swaps++;
    swap(arr[i+1], arr[r]);
    return (i+1);
}

int random_part(int *arr, int p, int r){
	int i = (rand() % (r - p + 1)) + p;
	swaps++;
	swap(arr[i], arr[r]);
    
	return(partition(arr, p, r));
}


void random_quick(int *arr, int p, int r){
	if(p < r){
    	int q = random_part(arr, p, r);
    	random_quick(arr, p, q - 1);
    	random_quick(arr, q + 1, r);
	}
    
}


int main()
{
	int arr[] = {4, 3, 6, 8, 5, 9, 20, 50, 12, 30, 432, 12, 69, 29, 40, 50, 10, 4, 23, 34, 45, 45, 24,
89, 799, 45, 80, 50, 10, 30, 43,54,65,76,87, 98, 21, 32, 43, 78, 98, 57, 29, 91, 34,
54, 64, 19, 82, 87, 65};
;
	srand(time(0));
	random_quick(arr, 0, sizeof(arr)/sizeof(int) - 1);
	for(int i = 0; i < sizeof(arr)/sizeof(int); i++){
    	cout << arr[i] << " ";
	}
	cout << endl;
	cout << "comparisons: " << comps << endl;
	cout << "swaps: " << swaps;

	return 0;
}
