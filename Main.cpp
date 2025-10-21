#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int id, burst, waiting, turnaround;
};

bool compareByBurst(Process a, Process b) {
    return a.burst < b.burst;
}

void FCFS(Process p[], int n) {
    p[0].waiting = 0;
    for (int i = 1; i < n; i++)
        p[i].waiting = p[i - 1].waiting + p[i - 1].burst;

    for (int i = 0; i < n; i++)
        p[i].turnaround = p[i].waiting + p[i].burst;

    cout << "----------------- FCFS -----------------\n";
    cout << "Process ID | Waiting Time | Turnaround Time\n";

    float totalWait = 0, totalTurn = 0;
    for (int i = 0; i < n; i++) {
        cout << "    " << p[i].id << "        |     "
             << p[i].waiting << "         |       "
             << p[i].turnaround << endl;
        totalWait += p[i].waiting;
        totalTurn += p[i].turnaround;
    }

    cout << "Average Waiting Time: " << totalWait / n << endl;
    cout << "Average Turnaround Time: " << totalTurn / n << endl;
}

void SJF(Process p[], int n) {
    sort(p, p + n, compareByBurst);

    p[0].waiting = 0;
    for (int i = 1; i < n; i++)
        p[i].waiting = p[i - 1].waiting + p[i - 1].burst;

    for (int i = 0; i < n; i++)
        p[i].turnaround = p[i].waiting + p[i].burst;

    cout << "\n----------------- SJF -----------------\n";
    cout << "Process ID | Waiting Time | Turnaround Time\n";

    float totalWait = 0, totalTurn = 0;
    for (int i = 0; i < n; i++) {
        cout << "    " << p[i].id << "        |     "
             << p[i].waiting << "         |       "
             << p[i].turnaround << endl;
        totalWait += p[i].waiting;
        totalTurn += p[i].turnaround;
    }

    cout << "Average Waiting Time: " << totalWait / n << endl;
    cout << "Average Turnaround Time: " << totalTurn / n << endl;
}

int main() {
    Process p[] = {
        {1, 2, 0, 0},
        {2, 1, 0, 0},
        {3, 8, 0, 0},
        {4, 4, 0, 0},
        {5, 5, 0, 0}
    };
    int n = sizeof(p) / sizeof(p[0]);

    FCFS(p, n);
    SJF(p, n);

    return 0;
}
