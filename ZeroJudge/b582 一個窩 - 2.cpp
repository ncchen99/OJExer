#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cmath>
using namespace std;

long long totalDistance;
int times, number, medianX, medianY, mode, nth, level;

struct point {
	int coordinates[2];
} dots[1000010];

int FindNth(int left, int right) {
	int index = (right + left) >> 1;
	int pivot = dots[index].coordinates[mode], up = left, down = right - 1;
	swap(dots[index], dots[right - 1]);
	while (up < down)
		if (dots[up++].coordinates[mode] >= pivot)
			swap(dots[--up], dots[--down]);
	swap(dots[up], dots[right - 1]);
	index = up - left;
	if (index == nth - 1)
		return pivot;
	else if (nth <= index)
		return FindNth(left, up);
	nth -= index + 1;
	return FindNth(up + 1, right);
}

int main() {
	srand(time(NULL));
	scanf("%d", &times);
	while (times--) {
		scanf("%d", &number);
		for (int i = 0; i < number; i++)
			scanf("%d%d", &dots[i].coordinates[0], &dots[i].coordinates[1]);
		mode = 0, nth = (number >> 1) + 1, medianX = FindNth(0, number);
		mode = 1, nth = (number >> 1) + 1, medianY = FindNth(0, number);
		totalDistance = 0;
		for (int i = 0; i < number; i++)
			totalDistance += abs(medianX - dots[i].coordinates[0]) + abs(medianY - dots[i].coordinates[1]);
		cout << totalDistance << '\n';
	}
}
