#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int binary_search(uint32_t arr[], size_t len, uint32_t item)
{
	uint32_t high = len - 1;
	uint32_t low = 0, mid = 0;
	while (low <= high) {
		uint32_t mid = ((high - low) / 2) + low;
		uint32_t value = arr[mid];

		if (value == item) {
			return mid;
		}
		else if (value > item) {
			high = mid - 1;
			continue;
		}
		else if (value < item) {
			low = mid + 1;
			continue;
		}
	}

	return -1;
}

int main(int argc, char* argv[])
{
	(void)argc;
	(void)argv;

	time_t start, end;

	uint32_t max_item_count = 1000000000;

	uint32_t *arr = (uint32_t*) malloc(max_item_count * sizeof(uint32_t));

	for (uint32_t i = 0; i < max_item_count; i++) {
		arr[i] = i;
	}

	uint32_t item = 5;

	//uint32_t len = sizeof arr / sizeof arr[0];
	uint32_t len = max_item_count;

	start = time(NULL);
	binary_search(arr, len, item);
	end = time(NULL);

	free(arr);

	printf("%f\n", difftime(end, start));

	return 0;
}
