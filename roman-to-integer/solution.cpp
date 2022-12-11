#include <string>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int sum = 0;
        for(int i=0; i<s.size()-1; i++){
            switch(s.at(i)){
                case 'I':
                    if(s.at(i+1) == 'V' || s.at(i+1) == 'X'){
                        sum--;
                    } else{
                        sum++;
                    }
                    break;
                case 'V':
                    sum+=5;
                    break;
                case 'X':
                    if(s.at(i+1) == 'L' || s.at(i+1) == 'C'){
                        sum-=10;
                    } else{
                        sum+=10;
                    }
                    break;
                case 'L':
                    sum+=50;
                    break;
                case 'C':
                    if(s.at(i+1) == 'D' || s.at(i+1) == 'M'){
                        sum-=100;
                    } else{
                        sum+=100;
                    }
                    break;
                case 'D':
                    sum+=500;
                    break;
                case 'M':
                    sum+=1000;
                    break;
                default:
                    break;
            }
        }
    
        switch(s.at(s.size()-1)){
            case 'I': sum+=1; break;
            case 'V': sum+=5; break;
            case 'X': sum+=10; break;
            case 'L': sum+=50;  break;
            case 'C': sum+=100; break;
            case 'D': sum+=500; break;
            case 'M': sum+=1000; break;
            default: break;
        }
        return sum;
    }

    
};
