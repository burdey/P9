//
// Created by Satori on 2022/10/23.
//

#include "PolishPrefix.h"

PolishPrefix::PolishPrefix() {
    prefix = "";

}

PolishPrefix::PolishPrefix(string Polish) {
    prefix = Polish;

}

int PolishPrefix::PrefixNotation() {
    stack<int> val;
    int valid = 1;
    int value = 0;
    int digit = 0;
    int notation = 0;
    for(int i = prefix.length()-1; i>=0 && valid == 1; i--) {
        char array = prefix[i];
        if(isdigit(array)){
            digit++;
            if (digit != 1){
                value = value + (array-'0')*10;
                val.pop();
            }
            else if (digit == 1){
                value = array-'0';
            }
            val.push(value);
        }
        else if(array == '+' && val.size() >=2){
            int num1 = val.top();
            val.pop();
            int num2 = val.top();
            val.pop();
            val.push(num1 + num2);
            digit = 0;
        }
        else if(array == '-' && val.size() >=2){
            int num1 = val.top();
            val.pop();
            int num2 = val.top();
            val.pop();
            val.push(num1 - num2);
            digit = 0;
        }
        else if(array == '*' && val.size() >=2){
            int num1 = val.top();
            val.pop();
            int num2 = val.top();
            val.pop();
            val.push(num1 * num2);
            digit = 0;
        }
        else if(array == '/' && val.size() >=2){
            int num1 = val.top();
            val.pop();
            int num2 = val.top();
            val.pop();
            val.push(num1 / num2);
            digit = 0;
        }
        else if(array == ' '){
            digit = 0;
        }
        else{
            valid = 0;
        }
    }

    if(valid == 1 && !val.empty()){
        notation = val.top();
        val.pop();
    }
}

void PolishPrefix::setPrefixNotation(string Polish) {
    prefix = Polish;
}

string PolishPrefix::PrintPrefix() {
    stack<int> val;
    int valid = 1;
    int value = 0;
    int digit = 0;
    string print = "";
    for(int i = prefix.length()-1; i>=0 && valid == 1; i--){
        char array = prefix[i];
        if(isdigit(array)){
            digit++;
            if (digit != 1){
                value = value + (array - '0') * 10;
                val.pop();
            }
            else if (digit == 1){
                value = array - '0';
            }
            val.push(value);
        }
        else if (array == '+'||array == '-'||array == '*'||array == '/'){
            if(val.size() >= 2 && print.length() == 0){
                int num1 = val.top();
                val.pop();
                int num2 = val.top();
                val.pop();
                ostringstream rig;
                rig << print << "(" << num1 << " " << array << " " << num2 << ")";
                print = rig.str();
                digit = 0;
            }
            else if(val.size() >= 2 && print.length() > 0){
                int num3 = val.top();
                val.pop();
                ostringstream rig;
                rig << "(" << print << " " << array << " " << num3 << ")";
                print = rig.str();
                digit = 0;
            }
            else if(val.size() == 1 && print.length() > 0){
                int num4 = val.top();
                val.pop();
                ostringstream rig;
                rig << print << " " << array << " " << num4;
                print = rig.str();
                digit = 0;
            }
            else{
                valid = 0;
            }
        }
        else if(array == ' '){
            digit = 0;
        }
    }
    if(valid == 0 || val.size() > 0){
        print = "Error";
    }
    return print;
}

PolishPrefix::~PolishPrefix() {


}
