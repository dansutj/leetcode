//
//  LongestCommonPrefix.cpp
//  learning
//
//  Created by 苏丹 on 16/5/16.
//  Copyright © 2016年 苏丹. All rights reserved.
//

#include <vector>
#include <string>
using namespace std;

struct TrieNode
{
    int num;
    TrieNode* child[26];
    
    TrieNode(){
        num = 0;
        for(int i = 0; i < 26; i++)
            child[i] = NULL;
    }
};

void addWord(TrieNode* node, string word)
{
    TrieNode* temp = node;
    temp->num++;
    
    for(char c : word)
    {
        int index = c - 'a';
        if(!temp->child[index])
            temp->child[index] = new TrieNode;
        temp = temp->child[index];
        temp->num++;
    }
}

class Solution
{
public:
    string longestCommonPrefix(vector<string>& strs)
    {
        TrieNode* node = new TrieNode;
        for(string str : strs) addWord(node, str);
        dfs(node, (int)strs.size());
        return prefix;
    }
    
    void dfs(TrieNode* node, int size)
    {
        for(int i = 0; i < 26; i++)
        {
            TrieNode* temp = node->child[i];
            if(temp && temp->num == size){
                prefix += i + 'a';
                dfs(temp, size);
                return;
            }
        }
    }
    
private:
    string prefix;
};
