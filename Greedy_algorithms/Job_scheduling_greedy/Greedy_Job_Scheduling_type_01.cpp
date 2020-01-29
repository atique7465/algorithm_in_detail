/*
Few jobs are given with their weight & length.have to find the minimum weighted sum completion time.
01. their is no time limit to complete a job.
02. weighted_sum_completion_time += job_list[i].job_weight * curr_time;
idea: sort the jobs according to weight/length ratio.
*/

#include<bits/stdc++.h>
using namespace std;

struct job
{
    int job_weight, job_length;
    job(int w = 0, int l = 0)
    {
        job_weight = w;
        job_length = l;
    }

    bool operator < (job &ob)const
    {
        double r1 = (double)job_weight / job_length;
        double r2 = (double)ob.job_weight / ob.job_length;
        return r1 > r2;
    }
};

int greedy_job_schedule(job job_list[], int number_of_jobs)
{
    sort(job_list, job_list + number_of_jobs); /// main time complexity here (n log n)

    int weighted_sum_completion_time = 0;
    int curr_time = 0;

    for(int i = 0; i<number_of_jobs; i++)
    {
        curr_time += job_list[i].job_length;
        weighted_sum_completion_time += job_list[i].job_weight * curr_time;
    }
    return weighted_sum_completion_time;
}

int main()
{
    freopen("dataset_job_scheduling_type_01.txt","r",stdin);
    int number_of_jobs,w,l;
    cin>>number_of_jobs; /// Enter the number of jobs
    job job_list[number_of_jobs];

    for(int i = 0; i < number_of_jobs; i++)
    {
        cin>>w>>l;
        job ob(w, l);
        job_list[i] = ob;
    }

    cout<<"Minimum weighted sum completion time is : "<<greedy_job_schedule(job_list, number_of_jobs);

    return 0;
}

