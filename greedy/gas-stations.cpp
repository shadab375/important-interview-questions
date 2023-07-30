class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int totalKamai = accumulate(gas.begin(), gas.end(), 0);
        int totalKharch = accumulate(cost.begin(), cost.end(), 0);
        if (totalKamai < totalKharch) return -1;

        int result_index = 0, total_gas = 0;
        for (int i=0; i<n; i++) {
            total_gas += gas[i] - cost[i];
            if (total_gas < 0) {
                result_index = i + 1;
                total_gas = 0;
            }
        }
        return result_index;
    }
};