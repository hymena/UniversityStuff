import requests
import json


def mapBranchesAndGetDiffs(repo, header):
    url = f"http://url/repos/{repo}/"
    response = requests.get(url=url, headers=header)
    parsedResponse = json.loads(response.text)
    branchList = parsedResponse['values']
    master = findBranch("master", branchList)
    development = findBranch("dev", branchList)
    deadBranchesForDev = []
    deadBranchesForMaster = []
    for branch in branchList:
        if(development):
            ahead, behind = compareTwoCommits(branch["latestCommit"],development["latestCommit"], header)
            if ahead <= 0 and behind > 0:
                deadBranchesForDev.append(branch) 
            ahead, behind = compareTwoCommits(branch["latestCommit"],master["latestCommit"], header)
            deadBranchesForMaster.append(branch)

    return deadBranchesForMaster, deadBranchesForDev


def compareTwoCommits(fromCommitId, toCommitId, header):
    url1 = f"http://company/api/{toCommitId}/{fromCommitId}"
    url2 = f"http://company/api/{fromCommitId}/{toCommitId}"
    response1 = requests.get(url1, headers=header)
    response2 = requests.get(url2, headers=header)
    parsedResponse1 = json.loads(response1.text)
    parsedResponse2 = json.loads(response2.text)
    ahead = parsedResponse1["size"]
    behind = parsedResponse2["size"]
    
    return ahead, behind


def findBranch(name, branchList):
    for branch in branchList:
        if(branch["displayId"] == name):
            return branch
    else:
        return 0
