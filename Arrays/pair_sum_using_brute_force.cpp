#include <iostream>
#include <vector>
using namespace std;

vector<int> pairSum(vector<int> nums, int n, int target) {
    vector<int> ans;
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(nums[i]+nums[j] == target) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return ans;
}

int main() {

    vector<int> nums = {2, 7, 11, 15};
    int n = 4;
    int target = 17;

    vector<int> ans = pairSum(nums, n, target);
    cout << "Index: (" << ans[0] << ", " << ans[1] << ")" << endl;
    cout << nums[ans[0]] << " + " << nums[ans[1]] << " = " << nums[ans[0]]+nums[ans[1]] << endl;


    return 0;
}