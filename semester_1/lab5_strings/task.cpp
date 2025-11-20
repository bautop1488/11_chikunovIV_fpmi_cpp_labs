#include <iostream>
#include <string>

void splitString(const std::string& input, std::string words[], int& wordCount){
    wordCount = 0;
    bool inWord = false;
    std::string currentWord = "";
    
    char c;
    for(int i = 0;i <= input.length();++i){
        c = (i < input.length()) ? input[i] : ' ';

        if(c != ' '){
            if(!inWord){
                inWord = true;
                currentWord = "";
            }
            currentWord += c;
        }else{
            if(inWord){
                words[wordCount++] = currentWord;
                inWord = false;
            }
        }
    }
}

bool isWord(const std::string& word){
    for(char c : word){
        if(!std::isdigit(c)){
            return false;
        }
    }
    return !word.empty();
}

std::string processString(const std::string& input){
    const int MAX_WORDS = 100;
    std::string words[MAX_WORDS];
    int wordCount;
    
    splitString(input, words, wordCount);
    
    if(wordCount == 0){
        throw "Error: you should enter something";
    }
    
    int maxNumber = -1;
    for(int i = 0;i < wordCount;++i){
        if(isWord(words[i])){
            if(maxNumber == -1 || std::stoi(words[i]) >= maxNumber){
                maxNumber = std::stoi(words[i]);
            }
        }
    }
    
    if(maxNumber == -1){
        return input;
    }
    
    int targetIndex = -1;
    int maxCount = 0;
    
    for(int i = 0;i < wordCount;++i){
        if(isWord(words[i]) && std::stoi(words[i]) == maxNumber){
            maxCount++;
        }
    }
    
    if(maxCount > 1){
        int currentCount = 0;
        for(int i = 0;i < wordCount;++i){
            if(isWord(words[i]) && std::stoi(words[i]) == maxNumber){
                currentCount++;
                if(currentCount == maxCount-1){
                    targetIndex = i;
                    break;
                }
            }
        }
    }else{
        for(int i = 0;i < wordCount;++i){
            if(isWord(words[i]) && std::stoi(words[i]) == maxNumber){
                targetIndex = i;
                break;
            }
        }
    }
    
    std::string result;
    
    if(targetIndex != -1){
        result += words[targetIndex];
    }
    
    for(int i = 0;i < wordCount;++i){
        if(i != targetIndex){
            if(!result.empty()){
                result += " ";
            }
            result += words[i];
        }
    }
    
    return result;
}

int main(){
    std::string input;
    
    std::cout << "Enter a string: ";
    std::getline(std::cin, input);
    
    try{
        std::cout << processString(input) << std::endl;
    }catch(const char* e){
        std::cout << e;
    }
    
    return 0;
}