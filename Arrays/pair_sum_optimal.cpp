#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int n, int target) {
    int i = 0; 
    int j = n-1;
    vector<int> ans;
    while(i<j) {
        if(nums[i]+nums[j] == target) {
            ans.push_back(i);
            ans.push_back(j);
            return ans;
        }
        if(nums[i]+nums[j] > target) {
            j--;
        }
        if(nums[i]+nums[j] < target) {
            i++;
        }
    }
    return ans;
}

int main() {

    vector<int> nums = {2, 7, 11, 15};
    int n = 4;
    int target = 18;

    vector<int> ans = pairSum(nums, 4, target);
    cout << "Index: (" << ans[0] << ", " << ans[1] << ")" << endl;
    cout << nums[ans[0]] << " + " << nums[ans[1]] << " = " << nums[ans[0]]+nums[ans[1]] << endl;

    return 0;
}