/*
 @file    phomnemonics.cpp
 @brief   The program generates all the possible mnemonics for a phone number.
*/

#include <cmath>
#include <fstream>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

long calcPermComb(char *, int);
void genMnemonics(char *, string);
bool isValidFilename(string);
bool isValidPhoneNumber(string);
void showHelp();
void showVersion();

const int MAX = 17;

int main(int argc, char const *argv[]) {
  // check if the argument is passed
  if (argc == 4) {
    // compare the argument with the telephone number and output filename
    if (strcmp(argv[2], "-o") == 0 || strcmp(argv[2], "--output") == 0) { 
      if (isValidFilename(argv[3])) {
        if (isValidPhoneNumber(argv[1])) {
          char itn[MAX];
          strcpy(itn, argv[1]);
          genMnemonics(itn, argv[3]);
        } else {
          cout << "Error: Invalid phone number." << endl;
        }
      } else {
        cout << "Error: Invalid output filename." << endl;  
      }
    } else {
      cout << "Error: Unknown parameter is passed." << endl;
    }
  } else if (argc == 3) {
    cout << "Error: Few missing parameters." << endl;
  } else if (argc == 2) {
    if (strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
      showHelp();
    } else if (strcmp(argv[1], "-v") == 0 || strcmp(argv[1], "--version") == 0) {
      showVersion();
    } else {
      // compare the argument with the telephone number
      if (isValidPhoneNumber(argv[1])) {
        char itn[MAX];
        strcpy(itn, argv[1]);
        genMnemonics(itn, "output.txt");
      } else {
        cout << "Error: Invalid phone number." << endl;
      }
    }
  } else {
    cout << "Error: Missing parameters." << endl;
  }

  return 0;
}

void genMnemonics(char *tn, string ofp) {
  ofstream out;

  char a[MAX], bos[MAX];
  int y[MAX];
  int ltn, ctr = 0;

  int ktr = 0;
  ltn = strlen(tn);
  for (int kctri = 0; kctri < ltn; kctri++) {
    if ((tn[kctri] >= '0' && tn[kctri] <= '9') || tn[kctri] == '-')
      bos[ktr++] = tn[kctri];
  }
  for (int kctrj = 0; kctrj < ktr; kctrj++) {
    tn[kctrj] = bos[kctrj];
  }
  ltn = ktr;

  cout << "The entered phone number is: ";
  for (int i = 0; i < ltn; i++) {
    cout << tn[i];
  }
  cout << "\nThe total number of possible mnemonics for this phone number is: " << calcPermComb(tn, ltn) << endl;
  cout << "The length of the phone number is: " << ltn << endl;
  cout << "All the possible mnemonics are saved in the '" << ofp << "' file." << endl;

  for (int x = 0; x <= MAX; x++) {
    y[x] = 1;
  }

  for (int z = ltn - 1; z >= 0; --z) {
    int i = 15 - ltn + z;
    switch (tn[z]) {
      case '2':
        a[i] = 65;
        y[i] = 3;
        break;
      case '3':
        a[i] = 68;
        y[i] = 3;
        break;
      case '4':
        a[i] = 71;
        y[i] = 3;
        break;
      case '5':
        a[i] = 74;
        y[i] = 3;
        break;
      case '6':
        a[i] = 77;
        y[i] = 3;
        break;
      case '7':
        a[i] = 80;
        y[i] = 4;
        break;
      case '8':
        a[i] = 84;
        y[i] = 3;
        break;
      case '9':
        a[i] = 87;
        y[i] = 4;
        break;
      case '0':
      case '1':
        a[i] = tn[z];
        y[i] = 1;
        break;
      default:
        a[i] = tn[z];
        y[i] = 1;
    }
  }

  out.open(ofp);

  for (int b = 0; b < y[0]; b++) {
    a[0] += b;
    for (int c = 0; c < y[1]; c++) {
      a[1] += c;
      for (int d = 0; d < y[2]; d++) {
        a[2] += d;
        for (int e = 0; e < y[3]; e++) {
          a[3] += e;
          for (int f = 0; f < y[4]; f++) {
            a[4] += f;
            for (int g = 0; g < y[5]; g++) {
              a[5] += g;
              for (int h = 0; h < y[6]; h++) {
                a[6] += h;
                for (int j = 0; j < y[7]; j++) {
                  a[7] += j;
                  for (int k = 0; k < y[8]; k++) {
                    a[8] += k;
                    for (int l = 0; l < y[9]; l++) {
                      a[9] += l;
                      for (int m = 0; m < y[10]; m++) {
                        a[10] += m;
                        for (int n = 0; n < y[11]; n++) {
                          a[11] += n;
                          for (int o = 0; o < y[12]; o++) {
                            a[12] += o;
                            for (int p = 0; p < y[13]; p++) {
                              a[13] += p;
                              for (int q = 0; q < y[14]; q++) {
                                a[14] += q;
                                for (int r = 0; r < y[15]; r++) {
                                  a[15] += r;
                                  for (int i = 15 - ltn; i < 15; i++)
                                    out << a[i];
                                  ctr++;
                                  if (ctr % 9 == 0)
                                    out << "\n";
                                  else
                                    out << "\t";
                                  a[15] -= r;
                                }
                                a[14] -= q;
                              }
                              a[13] -= p;
                            }
                            a[12] -= o;
                          }
                          a[11] -= n;
                        }
                        a[10] -= m;
                      }
                      a[9] -= l;
                    }
                    a[8] -= k;
                  }
                  a[7] -= j;
                }
                a[6] -= h;
              }
              a[5] -= g;
            }
            a[4] -= f;
          }
          a[3] -= e;
        }
        a[2] -= d;
      }
      a[1] -= c;
    }
    a[0] -= b;
  }

  out.close();
}

long calcPermComb(char *tn, int l) {
  int i, c1 = 0, c2 = 0;
  long double N;
  for (i = 0; i <= l; i++) (tn[i] == '1' || tn[i] == '0') ? c1++ : c1;
  l = l - c1;
  for (i = 0; i <= l; i++) (tn[i] == '7' || tn[i] == '9') ? c2++ : c2;
  l = l - c2;
  N = pow(3, l) * pow(4, c2);
  return N;
}

// A function to check if the filename is valid and have some extension
bool isValidFilename(string filename) {
  // If the filename is empty, return false
  if (filename.empty()) {
    return false;
  }
  // Find the position of the last dot in the filename
  size_t dotPos = filename.find_last_of('.');
  // If there is no dot, return false
  if (dotPos == string::npos) {
    return false;
  }
  // Get the extension of the filename
  string ext = filename.substr(dotPos + 1);
  // If the extension is empty, return false
  if (ext.empty()) {
    return false;
  }
  // Loop through each character of the extension
  for (char c : ext) {
    // If the character is not alphanumeric, return false
    if (!isalnum(c)) {
      return false;
    }
  }
  // If none of the above conditions are met, return true
  return true;
}

// A function to check the input string for valid phone number
bool isValidPhoneNumber(string s) {
  // If the string is empty, return false
  if (s.empty()) {
    return false;
  }
  // If the string is not 10 characters long, return false
  if (s.length() != 10) {
    return false;
  }
  // Loop through each character of the string
  for (char c : s) {
    // If the character is not a digit, return false
    if (!isdigit(c)) {
      return false;
    }
  }
  // If none of the above conditions are met, return true
  return true;
}

void showHelp() {
  // show the help menu
  cout << "Usage:" << endl;
  cout << " phomnemonic <phone_number>" << endl;
  cout << " phomnemonic <phone_number> --output <output_filename>" << endl << endl;
  cout << "Options:" << endl;
  cout << "-h, --help       Show this help message and exit" << endl;
  cout << "-v, --version    Show the program version and exit" << endl;
  cout << "-o, --output     Filename to save the output." << endl << endl;
}

void showVersion() {
  // show the version info
  cout << "Phomnemonic (v1.0.0)" << endl;
  cout << "It creates all the possible alphanumeric mnemonics that correspond to a phone number." << endl;
  cout << "Copyright (c) 2005 Abhishek Kumar. This work is licensed under the GNU GPL v3 or later." << endl << endl;
}