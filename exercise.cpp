// #include <iomanip>
// #include <ios>
// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// using std::cin;
// using std::cout;
// using std::endl;

// using std::setprecision;
// using std::string;
// using std::streamsize;
// using std::vector;
// using std::sort;

// int main() {
//     cout << "Enter name: ";
//     string name;
//     cin >> name;
//     cout << "Hello " << name << endl;

//     cout << "Enter midterm and final exam grades";

//     double midterm, final;
//     cin >> midterm >> final;

//     cout << "Enter hw grades, " "endoffile";

//     // int count = 0;
//     // double sum = 0;

//     double x;
//     vector<double> homework;

//     while (cin >> x)
//         homework.push_back(x);

//     typedef vector<double>::size_type vec_sz;
//     vec_sz size = homework.size();
//     if (size == 0) {
//         cout << endl << "You must enter grades. "
//                         "Try again";
//         return 1;
//     }

//     sort(homework.begin(), homework.end());

//     vec_sz mid = size/2;
//     double median;
//     median = size % 2 == 0 ? (homework[mid] + homework[mid-1]) / 2 :
//     homework[mid];

//     streamsize prec = cout.precision();
//     cout << "Your grade is" << setprecision(3)
//         << 0.2 * midterm + 0.4 * final + 0.4 * median
//         << setprecision(prec) << endl;

//         return 0;
// }

// #include <algorithm>
// #include <iomanip>
// #include <ios>
// #include <iostream>
// #include <stdexcept>
// #include <string>
// #include <vector>
// #include "grade.h"
// #include "Student_info.h"

// using std::cin;
// using std::cout;
// using std::domain_error;
// using std::endl;
// using std::max;
// using std::setprecision;
// using std::sort;
// using std::streamsize;
// using std::string;
// using std::vector;

// int main() {
//     vector<Student_info> students;
//     Student_info record;
//     string::size_type maxlen = 0;

//     while (read(cin, record)) {
//         maxlen = max(maxlen, record.namesize());
//         students.push_back(record);
//     }

//     sort(students.begin(), students.end(), compare);

//     for (vector<Student_info>::size_type i = 0;
//         i != students.size(); ++1) {
//         cout << students[i].name
//             << string(maxlen + 1 - students[i].name.size(), ' ');
//             try {
//                 double final_grade = grade(students[i]);
//                 streamsize prec = cout.precision();
//                 cout << setprecision(3) << final_grade
//                     << setprecision(prec);
//                 } catch (domain_error e) {
//                     cout << e.what();
//                 }
//                 cout << endl;
//             }
//             return 0;
//     }
