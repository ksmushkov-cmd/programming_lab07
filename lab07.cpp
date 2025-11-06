/************************* 
 * Автор: Смушков Кирилл *
 * Вариант:отсутствует   *
 *                       *
 *************************/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    
  ifstream file("text.TXT");

  // Для подсчёта частот для букв a-z
  int letterCounts[26] = {0};
    
  // Используем массив для учета двухбуквенных сочетаний
  int bigramCounts[26][26] = {0};

  char ch;
  // Для хранения предыдущей буквы
  char prevChar = 0; 
  
  while (file.get(ch)) {
    if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
      ch = tolower(ch);
      int index = ch - 'a';
      ++letterCounts[index];

        if (prevChar != 0) {
          ++bigramCounts[prevChar - 'a'][index];
        }
          prevChar = ch;
    } else {
        prevChar = 0;
      }
  }
  
  int limit = 26;

  // Выводим частоты букв
  cout << "Частоты букв:\n";
  for (int letterIndex = 0; letterIndex < limit; ++letterIndex) {
    if (letterCounts[letterIndex] > 0) {
      char letterChar = 'a' + letterIndex;
      cout << letterChar << ": " << letterCounts[letterIndex] << endl;
    }
  }

  // Выводим частоты двухбуквенных сочетаний
  cout << "\nЧастоты двухбуквенных сочетаний:\n";
  for (int firstLetterIndex = 0; firstLetterIndex < limit; ++firstLetterIndex) {
    for (int secondLetterIndex = 0; secondLetterIndex < limit; secondLetterIndex++) {
      if (bigramCounts[firstLetterIndex][secondLetterIndex] > 0) {
        char firstLetter = 'a' + firstLetterIndex;
        char secondLetter = 'a' + secondLetterIndex;
        cout << firstLetter << secondLetter
        << ": " << bigramCounts[firstLetterIndex][secondLetterIndex]
        << endl;
      }
    }
  }

  return 0;
}