values = [5, 3, 2, 3, 1] profit / loss 
maxheap

priority_queue<int> pq;

int sum = arr[0];



0th will always be profit
2 -> 5 2




sum = 5;

maxheap

sum = 2 - 2 = 3 - 3 0

for (i = 1; i < arr.size(); i++) {

    while (!pq.empty() && sum <= 0) {
        sum += 2 * pq.top();
        pq.pop();
    }
    pq.push(arr[i]);
    sum -= arr[i];
}

return pq.size();




[5, -3, 2, -3, 1] has 2 loss days



5  2  4  1 2->cum profit
2 losses


[5, 3, -2, -3, -1] has 3 loss days.



-> maximum number of days where i can have loss
->given that from 0 to i profit > 0 (cumulative profit)

first item + ve 0th

there are 2 ways:
prefix sum culumulative sum
1) + ve->use positive
2) - ve(sum - a[i]) > 0 Negative->count++ loss right

dynamic programming

int maxLossDays(int i, int sum, vector<int> &arr, vector<vector<int>> &dp) {
    if (i == arr.size())
        return 0;
    if (dp[i][sum] != -1) return dp[i][sum];

    int pos = 0, neg = 0;
    if ((sum - arr[i]) > 0) {
        neg = 1 + maxLossDays(i + 1, sum - arr[i], arr, dp);
    }
    pos = maxLossDays(i + 1, sum + arr[i], arr, dp);
    return dp[i][sum] = max(neg, pos);
}

2 ^ n->recursion

n <= 10 * *5
maxsum <= 10 * *5



main() {

    int sum = arr[0];
    int maxSum = 0;
    for (i = 0; i < arr.size(); i++) maxSum += arr[i];
    vector<vector<int>> dp(arr.size() + 1, vector<int>(maxSum + 1, -1));
    maxLossDays(1, sum, arr, dp);
}


