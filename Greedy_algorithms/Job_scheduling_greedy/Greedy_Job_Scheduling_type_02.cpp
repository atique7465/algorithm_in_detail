/*
Few jobs are given with their profit or weight & time limit. have to find the job sequence and maximum profit.
01. consider every job length is 1 unit.
Resource: https://www.youtube.com/watch?v=zPtI8q9gvX8&list=PLDN4rrl48XKpZkf03iYFl-O29szjTrs_O&index=41
*/

#include<bits/stdc++.h>
using namespace std;

struct job
{
    int profit, time_limit;
    job(int p = 0, int t = 0)
    {
        profit = p;
        time_limit = t;
    }

    bool operator < (job &ob)const
    {
        return profit > ob.profit;
    }
};

void greedy_job_schedule(job job_list[], int number_of_jobs, int mx_time)
{
    sort(job_list, job_list + number_of_jobs); /// main time complexity here (n log n)
    int sequence[mx_time + 1];
    memset(sequence,-1,sizeof(sequence));

    int mx_profit = 0;

    for(int i = 0; i<number_of_jobs; i++)
    {
        int v = job_list[i].time_limit;
        while(v > 0)
        {
            if(sequence[v] == -1)
            {
                sequence[v] = i+1;
                mx_profit += job_list[i].profit;
                break;
            }
            v--;
        }
    }
    cout<<"Maximum Profit : "<<mx_profit<<endl;
    cout<<"Job sequence is : ";
    for(int i=0; i<=mx_time; i++)
        if(sequence[i] != -1)
          cout<<"job"<<sequence[i]<<" ";
}

int main()
{
    int number_of_jobs,p,t,mx_time = 0;
    cout<<"Enter the number of jobs : ";
    cin>>number_of_jobs;

    cout<<"Enter the jobs with profit time_limit pair : "<<endl;
    job job_list[number_of_jobs];
    for(int i = 0; i < number_of_jobs; i++)
    {
        cin>>p>>t;
        job ob(p, t);
        job_list[i] = ob;
        if(t>mx_time)
            mx_time = t;
    }

    greedy_job_schedule(job_list, number_of_jobs, mx_time);

    return 0;
}

/*
INPUT:
7
20 2
15 3
35 3
40 4
25 4
12 1
5 2
OUTPUT:
Maximum Profit : 120
Job sequence is : job4 job3 job2 job1
*/

