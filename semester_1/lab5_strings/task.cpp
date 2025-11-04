#include <iostream>
#include <string>

void splitString(const std::string& input, std::string words[], int& wordCount){
    wordCount = 0;
    bool inWord = false;
    std::string currentWord = "";
    
    for(int i=0;i<=input.length();i++){
        char c = (i<input.length()) ? input[i] : ' ';
        
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
    for(char c:word){
        if(!std::isdigit(c)){
            return false;
        }
    }
    return !word.empty();
}

std::string processString(const std::string& input){
    const int MAX_WORDS = 100;
    std::string words[MAX_WORDS];
    int wordCount = 0;
    
    splitString(input,words,wordCount);
    
    if(wordCount==0){
        return input;
    }
    
    std::string maxNumber = "";
    for(int i=0;i<wordCount;i++){
        if(isWord(words[i])){
            if(maxNumber.empty() || words[i].length() >= maxNumber.length()){
                maxNumber=words[i];
            }
        }
    }
    
    if(maxNumber.empty()){
        return input;
    }
    
    int targetIndex=-1;
    int maxCount=0;
    
    for(int i=0;i<wordCount;i++){
        if(isWord(words[i])&&words[i]==maxNumber){
            maxCount++;
        }
    }
    
    if(maxCount >= 2){
        int currentCount=0;
        for(int i=0;i<wordCount;i++){
            if(isWord(words[i])&&words[i] == maxNumber){
                currentCount++;
                if(currentCount == maxCount-1){
                    targetIndex = i;
                    break;
                }
            }
        }
    }else{
        for(int i=0;i<wordCount;i++){
            if(isWord(words[i]) && words[i] == maxNumber){
                targetIndex = i;
                break;
            }
        }
    }
    
    std::string result;
    
    if(targetIndex != -1){
        result += words[targetIndex];
    }
    
    for(int i=0;i<wordCount;i++){
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
    
    std::cout<<"Type a string: ";
    std::getline(std::cin,input);
    
    std::string result=processString(input);
    
    std::cout<<"Result: "<<result<<std::endl;
    
    return 0;
}