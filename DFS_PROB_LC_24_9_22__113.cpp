#include<bits/stdc++.h>
using namespace std;

/*
Given the root of a binary tree and an integer targetSum, return all root-to-leaf paths where the sum of the node values in the path equals targetSum. Each path should be returned as a list of the node values, not node references.

A root-to-leaf path is a path starting from the root and ending at any leaf node. A leaf is a node with no children.

Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
Explanation: There are two paths whose sum equals targetSum:
5 + 4 + 11 + 2 = 22
5 + 8 + 4 + 5 = 2

Input: root = [1,2,3], targetSum = 5
Output: []

*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    //DFS Problem
public:
    
    vector<vector<int>> paths;
    vector<int> curr;
    
    void allPaths(TreeNode* root,int sum,int targetSum){
        if(root==NULL) return;
        
        sum += root->val;
        curr.push_back(root->val);
        
        if(root->left==NULL && root->right==NULL){
            if(sum == targetSum )
                paths.push_back(curr);
        }
        
        
        allPaths(root->left,sum,targetSum);
        allPaths(root->right,sum,targetSum);
        curr.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        allPaths(root,0,targetSum);
        
        return paths;
        
    }
};

int main(){
	int x;cin>>x;
	int temp = x;
        int x2 = 0;
        int d = 0;
        while(x>0){
            d = x%10;
            x2 = x2*10+d;
            x /= 10;
        }
        cout<<x2<<temp;
        if(temp == x)
            cout<< true;
        else
            cout<< false;

}