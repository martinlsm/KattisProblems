#include <stdio.h>

#define MIN(x,y) (((x) < (y)) ? (x) : (y))
#define MAX(x,y) (((x) > (y)) ? (x) : (y))

int main()
{
	int N_cases;
	int length;
	int N_ants;

	scanf("%d", &N_cases);
	for (int i = 0; i < N_cases; ++i) {
		scanf("%d", &length);
		scanf("%d", &N_ants);
		int ant;
		int earliest = 0;
		int latest = 0;
		for (int j = 0; j < N_ants; ++j) {
			scanf("%d", &ant);
			earliest = MAX(earliest, MIN(ant, length - ant));
			latest = MAX(latest, MAX(ant, length - ant));
		}
		printf("%d %d\n", earliest, latest);
	}
	return 0;
}
