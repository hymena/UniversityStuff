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
    jobs[index].pre = pre

for i in range(len(jobs)):
    preJobFinder(i)

M = {-1:0}
for i in range(len(jobs)):
    M[i] = max(M[i-1],M[jobs[i].pre] + jobs[i].profit)

print(M[len(jobs)-1])