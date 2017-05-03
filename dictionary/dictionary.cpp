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

map <string, vector<int>> dictionary;  //����������

int main()
{
	//�ض����index.txt�ж����ļ�ID�š��ļ�·���������result.txt
	freopen("index.txt", "r", stdin);
	freopen("result.txt", "w", stdout);
	dictionary.clear();  //��ʼ����
	int id;//�ļ�ID��
	string filepath;//�ļ�·����
	while (cin >> id >> filepath) //��index�ж����ļ�ID���ļ�·����
	{
		ifstream fin(filepath.c_str());//���ļ�·���µ��ļ�
		string s;
		while (fin >> s) //һ������һ���������
		{
			dictionary[s].push_back(id);//�ѵ�ǰ���ʶ�Ӧ���ļ������뵽���ʶ�Ӧ��id������
			vector<int>::iterator itt;   //ȥ��
			itt = dictionary[s].end() - 1;
			if (*itt == *(itt - 1))
			{
				dictionary[s].pop_back();
			}
		}

	}
	map<string, vector<int>>::iterator map_it;
	map_it = dictionary.begin();
	while (map_it != dictionary.end())//���������������������Ϊmap�ļ�ֵ���ϸ������������������ֵ���
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
