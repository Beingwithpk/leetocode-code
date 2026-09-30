class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreater;
        stack<int> st;

        for (int i = nums2.size() - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }

            if (!st.empty()) {
                nextGreater[nums2[i]] = st.top();
            } else {
                nextGreater[nums2[i]] = -1;
            }

            st.push(nums2[i]);
        }

        vector<int> answer;

        for (int num : nums1) {
            answer.push_back(nextGreater[num]);
        }

        return answer;
    }
};