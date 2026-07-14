class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        long long tcost = 0;
        long long itr = 0;
        long long rem = k;
        const long long MOD = 1e9 + 7;

        for (int i = 0; i < nums.size(); i++) {
            if (rem >= nums[i]) {
                rem = rem - nums[i];
            } else {
                long long need = nums[i] - rem;
                long long cnt = (need + k - 1) / k;

                __int128 add = (__int128)(2 * itr + cnt + 1) * cnt / 2;
                tcost = (tcost + (long long)(add % MOD)) % MOD;

                itr += cnt;
                rem += cnt * k;
                rem -= nums[i];
            }
        }
        return tcost;
    }
};