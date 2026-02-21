#define _CRT_SECURE_NO_WARNINGS 1

////01.2235.两整数相加
//int sum(int num1, int num2) {
//    return num1 + num2;
//}


////02.2469.温度转换
//double* convertTemperature(double celsius, int* returnSize) {
//    double* res = (double*)malloc(sizeof(double) * 2);
//
//    res[0] = celsius + 273.15;
//    res[1] = celsius * 1.80 + 32.00;
//
//    *returnSize = 2;
//
//    return res;
//}


////03.2413.最小偶倍数
//int smallestEvenMultiple(int n) {
//    //return (n % 2 == 0)? n : 2 * n; 
//    //return (n % 2 + 1) * n; 
//    return n << (n & 1); //n为偶左移0位，n为奇左移1位
//}


//04.2236.判断根节点是否等于子节点之和
///**
// * Definition for a binary tree node.
// * struct TreeNode {
// *     int val;
// *     struct TreeNode *left;
// *     struct TreeNode *right;
// * };
// */
//bool checkTree(struct TreeNode* root) {
//    return root->val == root->left->val + root->right->val;
//}

////05.1486.数组异或操作
//int xorOperation(int n, int start) {
//    int res = 0;
//
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        res ^= (start + 2 * i);
//    }
//
//    return res;
//}
////优化


////06.1512.好数对的数目
//int numIdenticalPairs(int* nums, int numsSize) {
//    int count = 0;
//
//    int i = 0;
//    for (i = numsSize - 1; i >= 0; i--)
//    {
//        int j = 0;
//        for (j = 0; j < i; j++)
//        {
//            if (nums[i] == nums[j])
//            {
//                count++;
//            }
//        }
//    }
//
//    return count;
//}
//优化