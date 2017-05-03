// dictionary.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<iostream>  
#include<fstream>  
#include<stdio.h>  
#include<string>
#include<string.h>
#include<map>  
#include<vector>  
#include<string>  
#include<algorithm>  
using namespace std;

map <string, vector<int>> dictionary;  //倒排索引表

int main()
{
	//重定向从index.txt中读入文件ID号、文件路径，输出到result.txt
	freopen("index.txt", "r", stdin);
	freopen("result.txt", "w", stdout);
	dictionary.clear();  //初始化表
	int id;//文件ID号
	string filepath;//文件路径名
	while (cin >> id >> filepath) //从index中读入文件ID和文件路径名
	{
		ifstream fin(filepath.c_str());//打开文件路径下的文件
		string s;
		while (fin >> s) //一个词语一个词语读入
		{
			dictionary[s].push_back(id);//把当前单词对应的文件名加入到单词对应的id数组中
			vector<int>::iterator itt;   //去重
			itt = dictionary[s].end() - 1;
			if (*itt == *(itt - 1))
			{
				dictionary[s].pop_back();
			}
		}

	}
	map<string, vector<int>>::iterator map_it;
	map_it = dictionary.begin();
	while (map_it != dictionary.end())//遍历整个索引表输出，因为map的键值是严格若排序，因此输出的是字典序
	{
		string tmp = map_it->first;
		cout << tmp << " ";
		for (int i = 0;i != dictionary[tmp].size();i++)
			cout << dictionary[tmp][i] << " ";
		cout << endl;
		map_it++;

	}
	return 0;
}
