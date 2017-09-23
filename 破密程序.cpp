#include<iostream>
#include<cstdlib>
//ÃÜÔ¿1£ºÄ£9Óà1¡¢5¡¢7
#define secret_key1 -28903287 
//ÃÜÔ¿2£ºÄ£9Óà0¡¢2¡¢3 
#define secret_key2 468374
//ÃÜÔ¿3£ºÄ£9Óà4¡¢6¡¢8
#define secret_key3 957928929
using namespace std;
int main(){ 
	int password,passby;
	AAAA: cout<<"input idcard number: ";
	cin>>password;
	switch(password%9){
		case 1:
		case 5:
		case 7: passby=password^secret_key1; break;
		case 0:
		case 2:
		case 3: passby=password^secret_key2; break;
		case 4:
		case 6:
		case 8: passby=password^secret_key3; break;
		default: cout<<"ERROR"<<endl; break;
	}
	cout<<"password: "<<passby<<endl;
	char T;
	cout<<"'B' for again"<<endl;
	cin>>T;
	if(T=='B'){
		goto AAAA;
	} 
	system("pause");
}
