#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    //1.����֮�� �����ⷨ
    vector<int> twoSum1(vector<int>& nums, int target) {
        vector<int> res(2, 0);
        int index1 = 0, index2 = 0;
        int diff = 0;
        for (int i = 0; i < nums.size(); i++) {
            diff = target - nums[i];
            index1 = i;
            for (int j = i + 1; j < nums.size(); j++) {
                if (diff == nums[j]) {
                    index2 = j;
                    res[0] = index1;
                    res[1] = index2;
                    return res;
                }
            }
        }
        return res;
    }

    //1.����֮�� ��ѽⷨ ��ϣӳ��
    vector<int> twoSum2(vector<int>& nums, int target) {
        unordered_map<int, int> hashtable;
        for (int i = 0; i < nums.size(); ++i) {
            int diff = target - nums[i];
            auto it = hashtable.find(diff);
            //�ҵ���,˵����ϣ��������ֵ��nums[i]����������target
            if (it != hashtable.end()) {
                return { it->second, i };
            }
            //û�ҵ����ڹ�ϣ���в���
            hashtable[nums[i]] = i;
        }
        return {};
    }
};

int main() {
    Solution s;
    vector<int> test = { -1, -2, -3, -4, -5 };
    vector<int> res(2, 0);
    int target = -8;
    //res = s.twoSum1(test, target);
    res = s.twoSum2(test, target);
    return 0;
}