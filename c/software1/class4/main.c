#include <stdio.h>

void insertion_sort(int nums[], int size) {
	int index = 1;

	while (index < size) {
		int tmp_index = index - 1;
		int tmp = nums[index];
		while (tmp_index >= 0) {
			if (tmp < nums[tmp_index]) {
				nums[tmp_index + 1] = nums[tmp_index];
				--tmp_index;
			} else if (tmp >= nums[tmp_index]) {
				break;
			}
		}
		nums[tmp_index + 1] = tmp;
		++index;
	}
}

int main() {
	int nums[] = {41,1, 10, 1241, 1513,541,5,14,13,41,425,25};
	int size = sizeof(nums) / sizeof(int);

	insertion_sort(nums, size);
	for (int i = 0; i < size; ++i) {
		printf("%d\n", nums[i]);
	}
}

