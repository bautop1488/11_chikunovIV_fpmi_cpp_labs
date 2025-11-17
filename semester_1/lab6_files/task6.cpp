#include <iostream>
#include <fstream>
#include <vector>
#include <string>


std::vector<std::string> readFile(const std::string& filename){
    std::vector<std::string> lines;
    std::ifstream file(filename);
    
    if(!file.is_open()){
        throw ("Error: Could not open file \"" + filename + "\"");
    }
    if(file.peek() == EOF){
        throw ("Error: file \"" + filename + "\" is empty!");
    }
    
    std::string line;
    while(std::getline(file, line)){
        lines.push_back(line);
    }
    
    file.close();
    return lines;
}

std::string findLongestDigitSubstring(const std::string& str){
    std::string maxDigits = "";
    std::string currentDigits = "";
    
    for(char c : str){
        if(std::isdigit(c)){
            currentDigits += c;
        }else{
            if(currentDigits.length() > maxDigits.length()){
                maxDigits = currentDigits;
            }
            currentDigits = "";
        }
    }
    
    if(currentDigits.length() > maxDigits.length()){
        maxDigits = currentDigits;
    }
    
    return maxDigits;
}

int main(){
    std::vector<std::string> lines;

    try{
        lines = readFile("input.txt");
    }catch(const std::exception e){
        std::cout << e.what();
    }
    
    size_t maxLength = 0;
    std::vector<std::string> resultLines;
    
    for(const std::string& line : lines){
        std::string digitStr = findLongestDigitSubstring(line);
        if(digitStr.length() > maxLength){
            maxLength = digitStr.length();
            resultLines.clear();
            resultLines.push_back(digitStr);
        }else if(digitStr.length() == maxLength && maxLength > 0){
            resultLines.push_back(digitStr);
        }
    }
    
    if(maxLength == 0){
        std::cout << "The are no digit substrings";
        std::exit(1);
    }
    
    if(resultLines.size() == 1){
        std::cout << resultLines[0];
    }else{
        int count = std::min(10, (int)resultLines.size());
        for(int i = 0;i < count;++i){
            std::cout << resultLines[i];
            if(i < count-1){
                std::cout << std::endl;
            }
        }
    }
    
    return 0;
}