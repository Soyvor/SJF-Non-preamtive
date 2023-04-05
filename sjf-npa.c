#include <stdio.h>

void main() {
  int n, i, j, temp, temp2, total_time = 0;
  float avg_wait_time = 0, avg_turnaround_time = 0;

  printf("Enter the number of processes: ");
  scanf("%d", &n);

  int burst_time[n], process_id[n], waiting_time[n], turnaround_time[n];

  for(i = 0; i < n; i++) {
    printf("Enter the burst time for process %d: ", i + 1);
    scanf("%d", &burst_time[i]);
    process_id[i] = i + 1;
  }

  // Sort processes by burst time in ascending order using selection sort
  for(i = 0; i < n - 1; i++) {
    for(j = i + 1; j < n; j++) {
    	
      if(burst_time[i] > burst_time[j]) {
        temp = burst_time[i];
        burst_time[i] = burst_time[j];
        burst_time[j] = temp;

        temp2 = process_id[i];
        process_id[i] = process_id[j];
        process_id[j] = temp2;
      }
    }
  }

  waiting_time[0] = 0;

  // Calculate waiting and turnaround time for each process
  for(i = 1; i < n; i++) {
    waiting_time[i] = 0;
    for(j = 0; j < i; j++) {
      waiting_time[i] += burst_time[j];
    }
    total_time += waiting_time[i];
  }

  // Calculate average waiting and turnaround time
  avg_wait_time = (float) total_time / n;
  total_time = 0;
  printf("\nProcess ID\tBurst Time\tWaiting Time\tTurnaround Time\n");
  for(i = 0; i < n; i++) {
    turnaround_time[i] = burst_time[i] + waiting_time[i];
    total_time += turnaround_time[i];
    printf("%d\t\t%d\t\t%d\t\t%d\n", process_id[i], burst_time[i], waiting_time[i], turnaround_time[i]);
  }

  avg_turnaround_time = (float) total_time / n;

  printf("Average Waiting Time: %0.2f\n", avg_wait_time);
  printf("Average Turnaround Time: %0.2f\n", avg_turnaround_time);
}
