#include <algorithm>
#include <cstring>
#include <climits>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <sstream>


// #include "../utils/VectorUtils.hpp"
#include "../utils/TreeUtils.hpp"

#include "../utils/PrintUtils.hpp"

using namespace std;

#pragma GCC diagnostic ignored "-Wunknown-pragmas"

// Live coding problems, watch at
// https://www.twitch.tv/yipcubed
// https://www.youtube.com/channel/UCTV_UOPu7EWXvYWsBFxMsSA/videos
//

// makes code faster, but larger. Just for LeetCode fun!
#pragma GCC optimise ("Ofast")

// makes stdin not synced so it is faster. Just for LeetCode fun!
static auto _no_sync_ = []() {              // NOLINT
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (!root) return nullptr;
        if (root->val < L)
            return trimBST(root->right, L, R);
        if (root->val > R) {
            return trimBST(root->left, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }
};

void test1() {
    vector<int> v1{1, 0, 2};
    auto t1 = new TreeNode(v1);

    cout << "[1, null, 2] ? \n" << Solution().trimBST(t1, 1, 2) << endl;

    vector<int> v2{3, 0, 4, -1, 2, -1, -1, -1, -1, 1};
    auto t2 = new TreeNode(v2);
    cout << "[3-2-1] ? \n" << Solution().trimBST(t2, 1, 3) << endl;

    // [3,1,4,null,2]
    //     3
    //    / \
    //   1   4
    //    \
    //     2
    vector<int> v3{3, 1, 4, -1, 2};
    auto t3 = new TreeNode(v3);
    cout << "[3,null,4] ? \n" << Solution().trimBST(t3, 3, 4) << endl;

    // [3,2,4,1]
    //1
    //1
    // expected [1]
    vector<int> v4{3, 2, 4, 1};
    auto t4 = new TreeNode(v4);
    cout << "[1] ? \n" << Solution().trimBST(t4, 1, 1) << endl;




}

void test2() {

}

void test3() {

}