#include "student.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include <numeric>
#include <set>

bool cmp(const StudentData& a, const StudentData& b) {
    if (a.name_ < b.name_) {
        return true;
    }
    if (a.name_ > b.name_) {
        return false;
    }

    return a.average() > b.average();
}

double StudentData::average() const {
    if (marks_.empty()) {
        return 0.0;
    }

    size_t sum = 0;
    for (Mark m : marks_) {
        sum += m.mark_;
    }
    return static_cast<double>(sum) / marks_.size();
}

size_t StudentData::sum_marks() const {
    size_t s = 0;
    for (Mark m : marks_) {
        s += m.mark_;
    }
    return s;
}

bool StudentData::has_bad_marks() const {
    for (Mark m : marks_) {
        if (m.mark_ <= 3) {
            return true;
        }
    }
    return false;
}

bool StudentData::has_subject(const std::string& subject) const {
    for (Mark m : marks_) {
        if (m.subject_ == subject) {
            return true;
        }
    }
    return false;
}

std::map<size_t, StudentData> read_from_file(const std::string& filename) {
    std::ifstream fin(filename);
    std::map<size_t, StudentData> students;

    std::string name;
    size_t number;

    while (fin >> name) {
        StudentData st;

        std::string initials;
        fin >> initials;
        st.name_ = name + " " + initials;

        fin >> number;
        st.number_ = number;

        std::string subject;
        size_t mark;

        while (fin >> subject >> mark) {
            st.marks_.push_back({subject, mark});
            if (fin.peek() == '\n'){
                break;
            }
        }

        students[st.number_] = st;
    }

    return students;
}

void print_by_record_book(const std::map<size_t, StudentData>& students) {
    for (const auto s : students) {
        std::cout << s.second.number_ << " " << s.second.name_ << "\n";
    }
}

void print_alphabetical(const std::map<size_t, StudentData>& students) {
    std::vector<StudentData> v;
    for (const auto s : students) {
        v.push_back(s.second);
    }

    std::sort(v.begin(), v.end(), cmp);

    size_t i = 1;
    for (const auto s : v) {
        std::cout << i++ << ". " << s.name_ << ", " << s.number_ << ", " << s.average() << "\n";
    }
}

void print_by_avg_range(const std::map<size_t, StudentData>& students, double l, double r) {
    std::vector<StudentData> v;

    for (const auto s : students) {
        if (s.second.average() >= l && s.second.average() <= r){
            v.push_back(s.second);
        }
    }
    std::sort(v.begin(), v.end(),
            [](const auto a, const auto b) {
                return a.average() > b.average();
            });

    for (const auto s : v) {
        std::cout << s.name_ << " " << s.average() << "\n";
    }
}

void print_by_subject(const std::map<size_t, StudentData>& students,const std::string& subject) {
    for (const auto s : students) {
        if (s.second.has_subject(subject)) {
            std::cout << s.second.name_ << " (" << s.second.number_ << ")\n";
        }
    }
}

void count_subjects(const std::map<size_t, StudentData>& students) {
    std::map<std::string, size_t> cnt;

    for (const auto s : students) {
        std::set<std::string> unique;
        for (const auto m : s.second.marks_) {
            unique.insert(m.subject_);
        }
        for (const auto sub : unique) {
            cnt[sub]++;
        }
    }

    for (const auto c : cnt) {
        std::cout << c.first << ": " << c.second << "\n";
    }
}

void avg_by_subject(const std::map<size_t, StudentData>& students) {
    std::map<std::string, std::vector<size_t>> mp;

    for (const auto s : students) {
        for (const auto m : s.second.marks_) {
            mp[m.subject_].push_back(m.mark_);
        }
    }

    std::vector<std::pair<std::string, double>> res;
    for (const auto m : mp) {
        double avg = std::accumulate(m.second.begin(), m.second.end(), 0.0) / m.second.size();
        res.push_back({m.first, avg});
    }

    std::sort(res.begin(), res.end(),
            [](const auto a, const auto b) {
                return a.second > b.second;
            });

    for (const auto r : res) {
        std::cout << r.first << " " << r.second << "\n";
    }
}

void best_by_sum(const std::map<size_t, StudentData>& students) {
    size_t mx = 0;
    for (const auto s : students) {
        mx = std::max(mx, s.second.sum_marks());
    }

    for (const auto s : students) {
        if (s.second.sum_marks() == mx) {
            std::cout << s.second.name_ << "\n";
        }
    }
}

void print_bad_students(const std::map<size_t, StudentData>& students) {
    for (const auto s : students) {
        if (s.second.has_bad_marks()) {
            std::cout << s.second.name_ << "\n";
        }
    }
}

double input_double(const std::string& prompt) {
    double x;

    std::cout << prompt;
    std::cin >> x;

    while (!std::cin) {
        std::cin.clear();
        std::cin.ignore(10000, '\n');

        std::cout << "Error, enter a number: ";
        std::cin >> x;
    }

    return x;
}