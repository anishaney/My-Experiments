#include <iostream>
#include <string.h>
#include <conio.h>

using namespace std;
int main(){
	char *a = "ac de f ed ca";
	bool palindromeflag  = true;
	int pivot1=0,pivot2=strlen(a)-1;
	while(pivot1<=pivot2){
		if(a[pivot1]!=' ' && a[pivot2]!=' '){
			if(a[pivot1]==a[pivot2]){
				++pivot1;--pivot2; continue;
			}else{
				palindromeflag = false;break;
			}
		}else if(a[pivot1]==' '){
			++pivot1; continue;
		}else if(a[pivot2]==' '){
			--pivot2; continue;
		}
	}
	if(palindromeflag)
		cout<<"Palindrome"<<endl;
	else
		cout<<"Not a palindrome"<<endl;

	getch();

	return 0;
}