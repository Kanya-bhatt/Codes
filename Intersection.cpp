#include <bits/stdc++.h>

using namespace std;

struct Points{
    
	int x;
	int y;
};

bool onSegment(Points x1, Points y1, Points z1){
    
	if((min(x1.x, y1.x) <= z1.x && max(x1.x, y1.x) >= z1.x) && (min(x1.y, y1.y) <= z1.y <= max(x1.y, y1.y))){
    	return true;
	}
	return false;
    
}

int direction(Points x1, Points y1, Points z1){
	int a1 = z1.x - x1.x;
	int a2 = z1.y - x1.y;
    
	int b1 = y1.x - x1.x;
	int b2 = y1.y - x1.y;
    
	int determinant = (a1 * b2) - (a2 * b1);
	cout << a1 << " " << a2 << " " << b1 << " " << b2 << endl;
	cout << "determinant " << determinant << endl;
    
	return determinant;
}



bool Intersecting(Points p1, Points p2, Points p3, Points p4){
	int d1 = direction(p1, p2, p3);
	int d2 = direction(p1, p2, p4);
	int d3 = direction(p3, p4, p1);
	int d4 = direction(p3, p4, p2);
    
	if((d1 * d2) < 0 && (d3 * d4) < 0){
    	return true;
	}
    
	else if(d1 == 0 && onSegment(p1, p2, p3) == true){
    	return true;
	}
    
	else if(d2 == 0 && onSegment(p1, p2, p4) == true){
    	return true;
	}
    
	else if(d3 == 0 && onSegment(p3, p4, p1) == true){
    	return true;
	}
    
	else if(d4 == 0 && onSegment(p3, p4, p2) == true){
    	return true;
	}
    
	else{
    	return false;
	}
    
    
}

int main()
{
	struct Points p1, p2, p3, p4;
    
	p1.x = 1;
	p1.y = 1;
    
	p2.x = 5;
	p2.y = 5;
    
	p3.x = 3;
	p3.y = 3;
    
	p4.x = 8;
	p4.y = 8;
    
	// cout << "enter first coordinated" << endl;
	// cin >> p1.x >> p1.y;
	// cout << "enter first coordinated" << endl;
	// cin >> p2.x >> p2.y;
	// cout << "enter first coordinated" << endl;
	// cin >> p3.x >> p3.y;
	// cout << "enter first coordinated" << endl;    
	// cin >> p4.x >> p4.y;
    
	if(Intersecting(p1, p2, p3, p4))
	cout << "true" << endl;
    
	else{
    	cout <<"false" << endl;
	}
    
    
    
    
	return 0;
}
