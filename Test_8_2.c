int rob(vector<int>& nums) {
	
	int sz = nums.size();
	if (sz == 0) return 0;
	if (sz == 1) return nums[0];
	if (sz == 2) return max(nums[0], nums[1]);

	vector<int> dp(sz, 0);
	dp[0] = nums[0];
	dp[1] = nums[1];
	dp[2] = nums[0] + nums[2];
	int imax = max(dp[1], dp[2]);
	for (int i = 3; i < sz; i++) {
		dp[i] = max(dp[i - 2], dp[i - 3]) + nums[i];
		imax = max(imax, dp[i]);
	}
	return imax;
}