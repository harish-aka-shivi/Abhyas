#include <iostream>
#include "map.h"
#include <cstring>
#include <unordered_map>
using namespace std;
void printIntersection(int* a, int sizeA, int*b , int sizeB) {
	unordered_map<int,bool> map;

	for(int i = 0; i < sizeA; i++) {
		map[a[i]] = true;
	}

	for(int i = 0; i < sizeB; i++) {
		if(map[b[i]]) {
			cout << b[i] << endl;
		}
	}

}

void printMaxFreqWord(char* input) {
	map<int> freqMap;
	int currentWordStart = 0;
	int currentWordEnd = 0;
	char* bestWord = NULL;
	int bestWordFreq = 0;
	while (input[currentWordEnd] != '\0') {
		if (input[currentWordEnd] == ' ' ) {
			int currentWordLength = currentWordEnd - currentWordStart;
			char* currentWord = new char[currentWordLength + 1];
			strncpy(currentWord, input + currentWordStart,
					currentWordLength);
			currentWord[currentWordLength] = '\0';
			int freq = freqMap.get(currentWord);
			freqMap.set(currentWord, freq + 1);

			if (bestWordFreq < freq + 1) {
				bestWordFreq = freq + 1;
				bestWord = currentWord;
			}

			currentWordStart = currentWordEnd + 1;
			currentWordEnd = currentWordStart;
		} else {
			currentWordEnd++;
		}
	}
	cout << bestWord << endl;
	cout << bestWordFreq << endl;
}

int main() {
	char a[1000];
	cin >> a ;;
	printMaxFreqWord(a);
}
