#include "student.h"
#include <iostream>

int main() {
    auto students = read_from_file("students.txt");

    std::cout << "\nSorting by record book number\n";
    print_by_record_book(students);

    std::cout << "\nAlphabetical list + average score\n";
    print_alphabetical(students);

    std::cout << "\nAverage score in range\n";
    double l = input_double("Enter lower limit: ");
    double r = input_double("Enter upper limit: ");

    if (l > r) std::swap(l, r);
    print_by_avg_range(students, l, r);

    std::cout << "\nStudents who took subject\n";
    std::string subject;
    std::cout << "Enter subject: ";
    std::cin >> subject;
    print_by_subject(students, subject);

    std::cout << "\nHow many students took each subject\n";
    count_subjects(students);

    std::cout << "\nAverage grade for subjects\n";
    avg_by_subject(students);

    std::cout << "\nStudents with the highest scores\n";
    best_by_sum(students);

    std::cout << "\nStudents with unsatisfactory grades\n";
    print_bad_students(students);

    return 0;
}