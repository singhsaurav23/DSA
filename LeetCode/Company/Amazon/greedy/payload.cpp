Second one :

You are given an array payload of size n, where payload[i] represents the size of the(i) - th event payload.The task is to select a subset of events and rearrange them into a new array optimizedPayload that satisfies the following conditions :

The first segment is strictly increasing.
The second segment is strictly decreasing.
The third segment is strictly increasing.
The goal is to maximize the number of events included in optimizedPayload.

Function Specification :

Function Name : getMaximumEvents
Input :
int payload[n] : Array of payload sizes.
Output :
	int : Maximum number of events that can be selected.
	Constraints :

	2 ≤ n ≤ 2×10 ^ 5
	1 ≤ payload[i] ≤ 10 ^ 9
	payload contains at least 2 distinct elements.
	Example :

	Input :

	n = 9
	payload = [1, 3, 5, 4, 2, 6, 8, 7, 9]
	Output :

	9
	Explanation :
	The subset optimizedPayload = [1, 3, 5, 4, 2, 6, 7, 8, 9] satisfies the increasing - decreasing - increasing sequence configuration.

	Solution :
	Idea : minVal and maxVal can only appear twice and rest thrice at maximum.

	max < -/ \ / ->max
	/ \ /
	min < -/ \ / ->min
	Count of each element in increasing order(map<int, int>)

	ans = 0
	ans += min(count[minValue], 2)
	ans += min(count[maxValue], 2)

	for all mid values(iterate in map)
		ans += min(count[it], 3)