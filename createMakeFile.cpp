#include<iostream>
#include<fstream>
#include<iomanip>

using std::cout;
using std::cin;
using std::endl;

int main() {
  std::string fileName;
  cout << "Name of makefile: ";
  cin >> fileName;

  int size;
  cout << "1 or 3 files: ";
  cin >> size;

  std::ofstream fout;
  fout.open(fileName.c_str());
  std::string main;

  if (fout.is_open()) {
    fout << "#makefile" << endl << endl;
    cout << "Main: ";
    cin >> main;

    if (size == 1) {
      fout << "a.out: " + main + ".o\n\tg++ " + main + ".cpp\n\n";
    }
    else if (size == 3) {
      std::string header;
      cout << "Header: ";
      cin >> header;

      std::string implementer;
      cout << ".h implementer (.cpp): ";
      cin >> implementer;

      fout << "a.out: " + main + ".o " + header
           + ".o\n\tg++ " + main + ".o " + header + ".o\n\n";
      fout << main + ".o: " + main + ".cpp " + header
           + ".h\n\tg++ -std=c++11 -c " + main + ".cpp\n\n";
      fout << header + ".o: " + implementer + ".cpp " + header
           + ".h\n\tg++ -std=c++11 -c " + implementer + ".cpp\n\n";
    }
    fout << "clean:\n\trm *.o\n\trm a.out\n";
  }
  else {
    std::cout << "ERROR: output file not opened!" << endl;
  }

  fout.close();
  return 0;
}
