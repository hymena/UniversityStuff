import json
import requests
import sys

projectKeyRepoPairs = sys.argv[1]
fromBranch = sys.argv[2]
toBranch = sys.argv[3]
tokenForRequester = sys.argv[4]
tokenForRewiever = sys.argv[5]
nameOfRewiever = sys.argv[6]

headerForRequest ={
    "Accept":"application/json",
    "Content-Type":"application/json",
    "Authorization":f"Bearer {tokenForRequester}"
}


hearderForApprove ={
    "Accept":"application/json",
    "Content-Type":"application/json",
    "Authorization":f"Bearer {tokenForRewiever}"
}


def parseProjectRepoPairs(val):
    firstParse = val.split(",")
    listOfPairs = []
    for index in range(len(firstParse)):
        pair = firstParse[index].split(":")
        listOfPairs.append(pair)
    
    return listOfPairs

def mapProjectRepoPairs(listOfPairs):
    for pair in listOfPairs:
        pullRequestUrl = f"http://url/{pair[0]}/repos/{pair[1]}/pull-requests"
        headerForRequest ={
            "Accept":"application/json",
            "Content-Type":"application/json",
            "Authorization":f"Bearer {tokenForRequester}"
        }
        dataForPR ={
            "title": "Title of Pull Request",
            "description": "Description of Pull Request.",
            "state": "OPEN",
            "open": True,
            "closed": False,
            "fromRef": {
                "id": f"refs/heads/{fromBranch}",
                "repository": {
                    "slug": pair[0],
                    "name": None,
                    "project": {
                        "key": pair[1]
                    }
                }
            },
            "toRef": {
                "id": f"refs/heads/{toBranch}",
                "repository": {
                    "slug": pair[0],
                    "name": None,
                    "project": {
                        "key": pair[1]
                    }
                }
            },
            "locked": False,
            "reviewers": [
                {
                    "user": {
                        "name": nameOfRewiever    
                    }
                }
            ]
        }       
        responseFromPR = requests.post(url=pullRequestUrl,
                                       headers=headerForRequest,
                                       json=dataForPR)
        responseFromPRInDictionary = json.loads(responseFromPR)
        approveUrl = f"http://url/{pair[0]}/repos/{pair[1]}/pull-requests/{responseFromPRInDictionary['id']}"
        responseForApprove = requests.post(approveUrl, headers=hearderForApprove)
        payloadForMerge = json.dumps({
            "message": f"merge from {fromBranch} to {toBranch}",
            "close_source_branch":1,
            "merge_strategy":"merge_commit"
        })
        mergeUrl = f"http://url/{pair[0]}/repos/{pair[1]}/pull-requests/{responseFromPRInDictionary['id']}/merge"
        requests.post(mergeUrl, headers=hearderForApprove, data=payloadForMerge)