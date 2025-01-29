//sort and group and in that group elemnet will be picked according to the smallest remaining for swap

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int l) {
        int i, n = nums.size();
        vector<pair<int, int>> vp(n);
        for (i = 0; i < n; i++) {
            vp[i].first = nums[i];
            vp[i].second = i;
        }
        sort(vp.begin(), vp.end());
        //for(i=0;i<n;i++) cout<<vp[i].first<<" ";
        i = 0;
        while (i < n) {
            int j = i + 1;
            priority_queue<int, vector<int>, greater<int>> pq;
            pq.push(vp[i].second);
            //cout<<j<<" ";
            while (j < n && (abs(vp[j].first - vp[j - 1].first)) <= l) {
                // cout<<"vbjn";
                pq.push(vp[j].second);
                j++;
            }
            while (!pq.empty()) {
                nums[pq.top()] = vp[i].first;
                i++;
                pq.pop();
            }
        }
        return nums;
    }
};

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        vector<int> numsSorted(nums);
        sort(numsSorted.begin(), numsSorted.end());

        int currGroup = 0;
        unordered_map<int, int> numToGroup;
        numToGroup.insert(pair<int, int>(numsSorted[0], currGroup));

        unordered_map<int, list<int>> groupToList;
        groupToList.insert(
            pair<int, list<int>>(currGroup, list<int>(1, numsSorted[0])));

        for (int i = 1; i < nums.size(); i++) {
            if (abs(numsSorted[i] - numsSorted[i - 1]) > limit) {
                // new group
                currGroup++;
            }

            // assign current element to group
            numToGroup.insert(pair<int, int>(numsSorted[i], currGroup));

            // add element to sorted group list
            if (groupToList.find(currGroup) == groupToList.end()) {
                groupToList[currGroup] = list<int>();
            }
            groupToList[currGroup].push_back(numsSorted[i]);
        }

        // iterate through input and overwrite each element with the next
        // element in its corresponding group
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            int group = numToGroup[num];
            nums[i] = *groupToList[group].begin();
            groupToList[group].pop_front();
        }

        return nums;
    }
};