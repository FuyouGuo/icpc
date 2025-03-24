#include<stdio.h>
#include<math.h>
#define size 100
#define bool _Bool
#define true 1
#define false 0
int prime_nums[size];
void init() {
	int ind = 0;
	int prime = 0;
	int num = 0;
	for (int i = 2; i < size; i++) {
		bool isprime = true;
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				isprime = false;
			}
		}
		if (isprime) {
			prime = i;
			num = 0;
			for (int k = i; k < size; k = k * prime) {
				num += size / k;
			}
			prime_nums[ind++] = num;
		}
	}
	for (int i = 0; i < size; i++) {
		printf("%d\n", prime_nums[i]);
	}
}
int main() {
	init();
}