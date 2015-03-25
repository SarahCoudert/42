#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// teste si small est une sous-chaine de big
int isSubstring(const char *small, int smallLength, const char *big, int bigLength) {
	int i, k, good;
	for (i=0; i<bigLength; i++) {
		// la petite chaine se trouve-t-elle en position i dans la grande ?
		good = 1;
		for (k=0; k<smallLength; k++) {
			if (i+k >= bigLength || small[k] != big[i+k]) {
				// non, la petite chaine n'est pas en position i dans la grande
				good = 0;
			}
		}
		if (good) {
			// la petite chaine se trouve en position i dans la grande
			return 1;
		}
	}
	// la petite chaine ne se trouve en aucune position dans la grande
	return 0;
}

int main(int argc, char *argv[]) {
	int start, end, len, k, bestLength=0, bestStart, triedLength, subStringInAll;
	if (argc < 2) {
		write(1, "\n", 1);
		return 1;
	}
	len = strlen(argv[1]);
	for (start=0; start<len; start++) {
		for (end=start; end<len; end++) {
			// on teste la sous-chaine de argv[1] qui va de start a end
			triedLength = end - start + 1;
			subStringInAll = 1;
			for (k=2; k<argc; k++) {
				// tester si la chaine argv[k] contient la sous-chaine de argv[1] en cours de test
				if (! isSubstring(argv[1]+start, triedLength, argv[k], strlen(argv[k]))) {
					subStringInAll = 0;
				}
			}
			if (subStringInAll) {
				// la sous-chaine en cours de test est "bonne" : elle est presente dans chacune des chaines.
				// Mais est-elle meilleure que la meilleure connue jusqu'a maintenant ?
				if (triedLength > bestLength) {
					bestLength = triedLength;
					bestStart = start;
				}
			}
		}
	}
	write(1, argv[1]+bestStart, bestLength);
	write(1, "\n", 1);
	return 0;
}
