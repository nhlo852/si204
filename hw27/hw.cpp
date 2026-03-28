/******************************************************************************
 * Author:      Nathan Lo
 * Alpha:       m283852
 * Title:       Course Section Search
 * Description: Reads course sections from a file and allows searching by 
 * course, section, or day.
 * Date:        2026-03-26
 ******************************************************************************/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Section {
    string course;
    int sectionNum;
    string schedule;
};

// Function Prototypes
Section* read(ifstream* fin, int* n);
void searchByCourse(Section* sections, int n);
void searchBySection(Section* sections, int n);
void searchByDay(Section* sections, int n);

int main()
{
  string fname;
  cout << "Filename: ";
  cin >> fname;
  ifstream fin(fname);

  int n;
  Section* sections = read(&fin, &n);

  string cmd;
  cout << "> ";
  while( (cin >> cmd) && (cmd != "quit") )
  {
    if( cmd == "course" )
      searchByCourse(sections, n);
    else if ( cmd == "section" )
      searchBySection(sections, n);
    else if ( cmd == "day" )
      searchByDay(sections, n);

    cout << endl << "> ";
  }


  delete [] sections;
  return 0;
}

// Read the file and build the array of structs
Section* read(ifstream* fin, int* n) {
    string junk;
    
    // Read the "N = 17" header
    // *fin dereferences the file pointer 
    *fin >> junk >> junk >> *n;
    
    // Make the array of Sections
    Section* arr = new Section[*n];
    
    // Read the data into the array
    for (int i = 0; i < *n; i++) {
        *fin >> arr[i].course >> arr[i].sectionNum >> arr[i].schedule;
    }
    
    return arr;
}

// Search and print matching courses
void searchByCourse(Section* sections, int n) {
    string target;
    cin >> target;
    
    for (int i = 0; i < n; i++) {
        if (sections[i].course == target) {
            cout << sections[i].course << " " << sections[i].sectionNum << " " << sections[i].schedule << endl;
        }
    }
}

// Search and print matching section numbers
void searchBySection(Section* sections, int n) {
    int target;
    cin >> target;
    
    for (int i = 0; i < n; i++) {
        if (sections[i].sectionNum == target) {
            cout << sections[i].course << " " << sections[i].sectionNum << " " << sections[i].schedule << endl;
        }
    }
}

// Search and print matches for a specific day character
void searchByDay(Section* sections, int n) {
    char target;
    cin >> target;
    
    for (int i = 0; i < n; i++) {
        bool found = false;
        
        // Loop through every character in the schedule string
        for (int j = 0; j < (int)sections[i].schedule.length(); j++) {
            if (sections[i].schedule[j] == target) {
                found = true;
                break; // Found i
            }
        }
        
        // If the day was found in the string, print the whole course
        if (found) {
            cout << sections[i].course << " " << sections[i].sectionNum << " " << sections[i].schedule << endl;
        }
    }
}