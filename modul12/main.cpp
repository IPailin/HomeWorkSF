#include <iostream>
#include <string>

using namespace std;


bool isKPeriodic(const string &text, int k){

    
    // int n = str.size();
    // char arr[n] = {0};

    string str;
    str.append(1,text[0]);

    int lenght {1};

    //char start_simbol = text[0];

    for(size_t i = 1; i < text.size(); ++i){

        if(text[i] != str[0]){
            str.append(1,text[i]);
            ++lenght;
        }
        else{
            break;
        }
    }

    if((text.size() / lenght) != k){
        return false;
    }

    for(size_t i = lenght; i < text.size(); i+=lenght){
        for(size_t j = 0; j < lenght; ++j){
            if(str[j] == text[j + i]){
                continue;
            }
            else{
                return false;
            }
        }
    }

    return true;
}
 
int main()
{
    isKPeriodic("adcadcadc", 3);

    return 0;
}