//one by one del each element and see if o_sum==e_sum,,, 
// do maths to interchange both sums;
//leetcode-1664 ways to make fair array
#define ll int
class Solution {
public:
	int waysToMakeFair(vector<int>& v) {
		ll i, n = v.size();
		ll cur_o = 0, cur_e = 0, e_sum = 0, o_sum = 0;
		for (i = 0; i < n; i++) {
			if (i % 2 == 0) o_sum += v[i];
			else e_sum += v[i];
		}
		ll ways = 0;
		for (i = 0; i < n; i++) {
			e_sum -= cur_e;
			o_sum -= cur_o;
			e_sum += cur_o;
			o_sum += cur_e;
			if (i % 2 == 0) o_sum -= v[i];
			else e_sum -= v[i];
			if (o_sum == e_sum) ways++;
			o_sum -= cur_e; e_sum += cur_e;
			e_sum -= cur_o; o_sum += cur_o;
			if (i % 2 == 0) { cur_o += v[i]; o_sum += v[i]; }
			else { cur_e += v[i]; e_sum += v[i]; }
		}
		return ways;
	}
};