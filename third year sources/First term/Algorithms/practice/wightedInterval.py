class job:
    def __init__(self,i,s,e,p) -> None:
        self.id = i
        self.start = s
        self.end = e
        self.profit = p



numberOfJobs = int(input("give the number of jobs: "))
jobs = []
for i in range(numberOfJobs):
    s,e,p =  map(int,input().split())
    jobs.append(job(i,s,e,p))

def preJobFinder(index):
    pre = -1
    for i in range(index):
        if jobs[i].end <= jobs[index].start:
            pre = i
    return pre

def Opt(n):
    if n < 0:
        return 0
    pre = preJobFinder(n)

    if Opt(pre) + jobs[n].profit > Opt(n-1):
        return Opt(pre) + jobs[n].profit
    else:
        return Opt(n-1)

print(Opt(len(jobs)-1))