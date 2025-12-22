#include <fstream>
#include <vector>
#include <string>
#include <iostream>

std::vector<std::string> ReadFile(std::ifstream& file){
    std::vector<std::string> lines;
    if(!file.is_open()){
        throw "Error: File is not open";
    }
    if(file.peek() == EOF){
        throw "Error: File is empty";
    }

    std::string line;
    while(std::getline(file, line)){
        lines.push_back(line);
    }

    file.close();

    return lines;
}

std::vector<std::string> SeparateLine(const std::string& line, const std::vector<char>& separators){
    std::vector<std::string> words;
    std::string word;
    bool is_sep = false;

    for(char c : line){
        for(char sep : separators){
            if(c == sep){
                is_sep = true;
                if(!word.empty()){
                    words.push_back(word);
                }
                word = "";
            }
        }
        if(!is_sep){
            word += c;
        }
        else{
            is_sep = false;
        }
    }
    if(!word.empty()){
        words.push_back(word);
    }

    return words;
}

bool IsNatural(std::string word){
    for(char c : word){
        if(!std::isdigit(c)){
            return false;
        }
    }
    return true;
}

std::vector<int> FindDividers(int n){
    std::vector<int> dividers;
    for(int i=1;i<n;++i){
        if(n%i == 0){
            dividers.push_back(i);
        }
    }
    return dividers;
}

bool IsPerfect(int n){
    int sum = 0;
    for(int d : FindDividers(n)){
        sum += d;
    }

    return sum == n;
}

int main(){
    const std::string INPUTFILENAME = "input.txt";
    const std::string OUTPUTFILENAME = "output.txt";

    std::ifstream input_file(INPUTFILENAME);
    std::ofstream output_file(INPUTFILENAME);

    std::vector<std::string> lines;

    try{
        lines = ReadFile(input_file);
    }
    catch(const char* msg){
        output_file << msg;
        std::exit(1);
    }

    std::vector<char> separators;
    for(char c : lines[0]){
        separators.push_back(c);
    }

    std::vector<std::string> words;
    for(int i = 1;i < lines.size();++i){
        for(std::string word : SeparateLine(lines[i], separators)){
            words.push_back(word);
        }
    }

    std::vector<int> numbers, perfect_nums, not_perfect_nums;

    for(std::string word : words){
        if(IsNatural(word)){
            int i_word = std::stoi(word);
            numbers.push_back(i_word);
            if(IsPerfect(i_word)){
                perfect_nums.push_back(i_word);
            }
            else{
                not_perfect_nums.push_back(i_word);
            }
        }
    }

    for(int num : numbers){
        output_file << num << ",";
    }
    output_file << std::endl;

    for(int num : perfect_nums){
        output_file << "Perfect: " << num << " = ";
        std::vector<int> dividers = FindDividers(num);
        for(int i = 0;i < dividers.size();++i){
            output_file << dividers[i];
            if(i != dividers.size()-1){
                output_file << " + ";
            }
        }
        output_file << std::endl;
    }

    output_file << "Not perfect: ";
    for(int i=0;i<not_perfect_nums.size();++i){
        output_file << not_perfect_nums[i];
        if(i != not_perfect_nums.size()-1){
            output_file << ", ";
        }
    }

    std::cout << "Program runned succesfully";
    return 0;
}