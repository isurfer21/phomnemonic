// This software finds an all possible equivalent string of characters for a telephone number.

#include <cmath>
#include <fstream>
#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

long pc(char *, int);
const int MAX = 17;

int main(int argc, char const *argv[]) {
  ofstream out;
  ifstream infile;

  char tn[MAX], a[MAX], bos[MAX];
  int y[MAX];
  int ltn, ctr = 0;

  infile.open(".\\input.txt");
  if (!infile) {
    cout << "Can't open the file!";
    exit(0);
  }
  while (!infile.eof()) {
    for (int i = 0; i < 15; i++) {
      infile >> tn[i];
    }
  }
  infile.close();
  
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

  out.open(".\\output.txt");

  out << "\nThis software finds an all possible equivalent string of characters for a telephone number.\n";
  out << "\nCopyright(c)-2005 by Abhishek Kumar\n";
  out << "\nTel no : ";
  for (int i = 0; i < ltn; i++) out << tn[i];
  out << "\nPossible permutation-combination: " << pc(tn, ltn);
  out << "\nLength of tel.ph.no.: " << ltn;
  for (int x = 0; x <= MAX; x++) {
    y[x] = 1;
  }
  out << "\nPosible string of characters for the given tel.ph.no.: \n" << endl;

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
  return 0;
}

long pc(char *tn, int l) {
  int i, c1 = 0, c2 = 0;
  long double N;
  for (i = 0; i <= l; i++) (tn[i] == '1' || tn[i] == '0') ? c1++ : c1;
  l = l - c1;
  for (i = 0; i <= l; i++) (tn[i] == '7' || tn[i] == '9') ? c2++ : c2;
  l = l - c2;
  N = pow(3, l) * pow(4, c2);
  return N;
}