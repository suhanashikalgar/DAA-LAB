#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char name[10];
    int resources; // resources required for the job
    int profit;    // profit from the job
    float ratio;   // profit-to-resource ratio
} Job;

// Comparison function for sorting jobs based on profit-to-resource ratio
int compare(const void *a, const void *b) {
    Job *jobA = (Job *)a;
    Job *jobB = (Job *)b;
    if (jobA->ratio < jobB->ratio) return 1; // Sort in descending order
    if (jobA->ratio > jobB->ratio) return -1;
    return 0;
}

void allocateResources(Job jobs[], int n, int totalResources) {
    // Calculate profit-to-resource ratio for each job
    for (int i = 0; i < n; i++) {
        jobs[i].ratio = (float)jobs[i].profit / jobs[i].resources;
    }
    
    // Sort jobs based on profit-to-resource ratio
    qsort(jobs, n, sizeof(Job), compare);

    int totalProfit = 0;
    int resourcesUsed = 0;
    printf("Allocated Jobs: [");

    for (int i = 0; i < n; i++) {
        if (resourcesUsed + jobs[i].resources <= totalResources) {
            resourcesUsed += jobs[i].resources;
            totalProfit += jobs[i].profit;
            printf("'%s'", jobs[i].name);
            if (i < n - 1) {
                printf(", ");
            }
        }
    }
    printf("]\n");
    printf("Total Profit: %d\n", totalProfit);
}

int main() {
    int n, totalResources;

    // Input total resources
    printf("Enter total available resources: ");
    scanf("%d", &totalResources);

    // Input number of jobs
    printf("Enter the number of jobs: ");
    scanf("%d", &n);

    Job *jobs = (Job *)malloc(n * sizeof(Job)); // Dynamically allocate memory for jobs

    // Input job details
    for (int i = 0; i < n; i++) {
        printf("Enter name, resources required, and profit for Job %d: ", i + 1);
        scanf("%s %d %d", jobs[i].name, &jobs[i].resources, &jobs[i].profit);
    }

    // Call the function to allocate resources
    allocateResources(jobs, n, totalResources);

    free(jobs); // Free the allocated memory
    return 0;
}
