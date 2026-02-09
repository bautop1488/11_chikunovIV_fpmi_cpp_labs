#pragma once

#include <string>
#include <vector>
#include <map>

struct Mark {
    std::string subject_;
    size_t mark_;
};

struct StudentData {
    std::string name_;
    size_t number_;
    std::vector<Mark> marks_;

    double average() const;
    size_t sum_marks() const;
    bool has_bad_marks() const;
    bool has_subject(const std::string& subject) const;
};

std::map<size_t, StudentData> read_from_file(const std::string& filename);

void print_by_record_book(const std::map<size_t, StudentData>& students);
void print_alphabetical(const std::map<size_t, StudentData>& students);
void print_by_avg_range(const std::map<size_t, StudentData>& students, double l, double r);
void print_by_subject(const std::map<size_t, StudentData>& students, const std::string& subject);
void count_subjects(const std::map<size_t, StudentData>& students);
void avg_by_subject(const std::map<size_t, StudentData>& students);
void best_by_sum(const std::map<size_t, StudentData>& students);
void print_bad_students(const std::map<size_t, StudentData>& students);
double input_double(const std::string& prompt);
bool cmp(const StudentData& a, const StudentData& b);