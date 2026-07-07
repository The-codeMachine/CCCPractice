#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

struct Job
{
    int duration;
    int deadline;
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N;
    std::cin >> N;

    std::vector<Job> jobs(N);

    for (int i = 0; i < N; i++)
    {
        std::cin >> jobs[i].duration >> jobs[i].deadline;
    }

    std::sort(jobs.begin(), jobs.end(),
        [](const Job& a, const Job& b)
        {
            return a.deadline < b.deadline;
        });

    std::priority_queue<int> longestJobs;

    long long currentTime = 0;

    for (const Job& job : jobs)
    {
        currentTime += job.duration;
        longestJobs.push(job.duration);

        if (currentTime > job.deadline)
        {
            currentTime -= longestJobs.top();
            longestJobs.pop();
        }
    }

    std::cout << longestJobs.size() << '\n';
}