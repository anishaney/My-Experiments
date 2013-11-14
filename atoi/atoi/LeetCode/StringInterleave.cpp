#include <iostream>
#include <string>

using namespace std;

bool isInterleave(string s1, string s2, string s3) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.    
        if (s1.empty()){
            if (!s3.compare(s2)){
                return true;
            }
            else{
                return false;
            }
        }
        if (s2.empty()){
	    cout << "hello" << endl;
            if (!s3.compare(s1)){
                return true;
            }
            else{
                return false;
            }
        }

	if (s3.size() < s1.size()+s2.size()){
            return false;
        }

	//Need to check what happens if s3.at() matches both s1.at() and s2.at()
        char *ends1 = &(s1.at(s1.size()-1)), *ends2 = &(s2.at(s2.size()-1)), *ends3 = &(s3.at(s3.size()-1));
        
        /*while (ends3 >= s3.begin()){
            if (*ends3 == *ends2){
                ends2--;
            }
            else if(*ends3 == *ends1){
                ends1--;
            }
            else{
                return false;
            }
            ends3--;
        }*/

	for (string::iterator it = s3.end()-1, jt = s2.end()-1, kt = s1.end()-1; it >= s3.begin(); it--){
		if (*it == *jt){
			jt--;
		}
		else if (*it == *kt){
			kt--;
		}
		else{
			return false;
		}
	}
        return true;
    }

int main(){
	string s1, s2, s3;
	s1 = "aabcc";
	s2 = "";
	s3 = "aabcc";
	
	//bool interleave;
	for (string::iterator it = s3.end()-1; it >= s3.begin(); it--){
		cout << *it;
	}
	cout << endl;

	if (isInterleave(s1,s2,s3))
		cout << "S3 is an interleave of S1 and S2" << endl;
	else
		cout << "S3 is not an interleave of S1 and S2" << endl;

	return 0;
}
