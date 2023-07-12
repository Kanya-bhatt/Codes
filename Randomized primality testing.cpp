#include <iostream>

using namespace std;
int count = 0;
//TC - gcd takes log(a + b) time and doing it k times hence klog(n)
int power(long int a, unsigned long int x, long int n){
	long long int res = 1;
	while(x > 0){
		if(x % 2 == 1){
			res = (res * a) % n;
		}
		x = x / 2;
		a = (a * a) % n;
	}
    
	return res;
}
int gcd(long int a, long int b){
	while(b > 0){
    	long int r = a % b;
    	a = b;
    	b = r;
	}
	return a;
}

string isPrime(long int n){
	long int i = 1, k = 10;
	if(n <= 1 || n == 4){
    	return "not prime";
	}
    
	if(n <= 3){
    	return "prime";
	}
	while(i <= k){
   	 
    	long int a = 2 + rand() % (n - 3);
    	if(gcd(a, n) != 1){
        	return "not prime";
    	}
    	if(power(a, n-1, n) != 1){
        	return "not prime";
    	}
    	k--;
	}
	return "prime";
}

int main()
{
	srand(time(0));
	string value = isPrime(10000000007);
	cout << value;
	return 0;
}

