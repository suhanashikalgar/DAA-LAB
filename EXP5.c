#include <stdio.h>
#include <stdlib.h>

// Define the structure for an interval
typedef struct {
    int start;
    int end;
} Interval;

// Function to compare intervals by their end times for qsort
int compareIntervals(const void *a, const void *b) {
    Interval *intervalA = (Interval *)a;
    Interval *intervalB = (Interval *)b;
    return (intervalA->end - intervalB->end);
}

// Function to perform interval scheduling using the greedy approach
void intervalScheduling(Interval intervals[], int n) {
    // Step 1: Sort the intervals by their end times
    qsort(intervals, n, sizeof(Interval), compareIntervals);

    // Step 2: Select the first interval
    int last_end_time = intervals[0].end;
    printf("Selected interval: [%d, %d]\n", intervals[0].start, intervals[0].end);

    // Step 3: Iterate and select non-overlapping intervals
    for (int i = 1; i < n; i++) {
        if (intervals[i].start >= last_end_time) {
            printf("Selected interval: [%d, %d]\n", intervals[i].start, intervals[i].end);
            last_end_time = intervals[i].end;
        }
    }
}

int main() {
    int n;
    printf("Enter the number of intervals: ");
    scanf("%d", &n);

    Interval intervals[n];

    for (int i = 0; i < n; i++) {
        printf("Enter start and end time for interval %d: ", i + 1);
        scanf("%d %d", &intervals[i].start, &intervals[i].end);
    }

    intervalScheduling(intervals, n);

    return 0;
}
