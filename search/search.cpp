// search.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <sstream>
#include <iostream>
#include <time.h>
#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;
ofstream resultt("result.txt");
//计时器
clock_t t_start, t_end;
char* src_fileList[] = {
	"data.aj.txt",
	"data.bb.txt",
	"data.be.txt",
	"data.bf.txt",
	"data.bs.txt",
	"data.by.txt",
	"data.cf.txt",
	"data.cn.txt",
	"data.co.txt",
	"data.cq.txt",
	"data.cz.txt",
	"data.dg.txt",
	"data.ee.txt",
	"data.ek.txt",
	"data.en.txt",
	"data.ep.txt",
	"data.ev.txt",
	"data.ew.txt",
	"data.fe.txt",
	"data.ff.txt",
	"data.fj.txt",
	"data.fp.txt",
	"data.ft.txt",
	"data.fz.txt",
	"data.ga.txt",
	"data.gk.txt",
	"data.gw.txt",
	"data.gz.txt",
	"data.ha.txt",
	"data.hc.txt",
	"data.hg.txt",
	"data.hp.txt",
	"data.hu.txt",
	"data.hz.txt",
	"data.jd.txt",
	"data.jf.txt",
	"data.jj.txt",
	"data.ka.txt",
	"data.kq.txt",
	"data.kt.txt",
	"data.mi.txt",
	"data.mk.txt",
	"data.mo.txt",
	"data.mt.txt",
	"data.mu.txt",
	"data.mx.txt",
	"data.ng.txt",
	"data.nh.txt",
	"data.ok.txt",
	"data.op.txt",
	"data.pa.txt",
	"data.pn.txt",
	"data.pq.txt",
	"data.qb.txt",
	"data.qn.txt",
	"data.ry.txt",
	"data.sq.txt",
	"data.tj.txt",
	"data.to.txt",
	"data.tv.txt",
	"data.tz.txt",
	"data.ud.txt",
	"data.uz.txt",
	"data.vi.txt",
	"data.vm.txt",
	"data.vz.txt",
	"data.wc.txt",
	"data.wg.txt",
	"data.xe.txt",
	"data.xk.txt",
	"data.ye.txt",
	"data.yx.txt",
	"data.zabe.txt",
	"data.zabj.txt",
	"data.zabx.txt",
	"data.zacd.txt",
	"data.zacp.txt",
	"data.zacw.txt",
	"data.zadv.txt",
	"data.zaeh.txt",
	"data.zaej.txt",
	"data.zaet.txt",
	"data.zafe.txt",
	"data.zafi.txt",
	"data.zafk.txt",
	"data.zafl.txt",
	"data.zafq.txt",
	"data.zafu.txt",
	"data.zafv.txt",
	"data.zafy.txt",
	"data.zagb.txt",
	"data.zagr.txt",
	"data.zahd.txt",
	"data.zahp.txt",
	"data.zaic.txt",
	"data.zail.txt",
	"data.zaim.txt",
	"data.zaip.txt",
	"data.zair.txt",
	"data.zajh.txt",
	"data.zajn.txt",
	"data.zajo.txt",
	"data.zajr.txt",
	"data.zakb.txt",
	"data.zake.txt",
	"data.zako.txt",
	"data.zalc.txt",
	"data.zalj.txt",
	"data.zall.txt",
	"data.zalm.txt",
	"data.zalt.txt",
	"data.zamp.txt",
	"data.zamr.txt",
	"data.zane.txt",
	"data.zanh.txt",
	"data.zank.txt",
	"data.zanm.txt",
	"data.zaoc.txt",
	"data.zaoo.txt",
	"data.zaop.txt",
	"data.zaoy.txt",
	"data.zapf.txt",
	"data.zapl.txt",
	"data.zapr.txt",
	"data.zaqf.txt",
	"data.zaql.txt",
	"data.zaqp.txt",
	"data.zaqr.txt",
	"data.zaqw.txt",
	"data.zarc.txt",
	"data.zard.txt",
	"data.zarr.txt",
	"data.zasd.txt",
	"data.zasj.txt",
	"data.zasq.txt",
	"data.zasr.txt",
	"data.zass.txt",
	"data.zasw.txt",
	"data.zasy.txt",
	"data.zate.txt",
	"data.zatz.txt",
	"data.zaub.txt",
	"data.zaun.txt",
	"data.zauy.txt",
	"data.zavg.txt",
	"data.zavx.txt",
	"data.zawb.txt",
	"data.zawc.txt",
	"data.zawm.txt",
	"data.zawo.txt",
	"data.zawu.txt",
	"data.zawz.txt",
	"data.zaxj.txt",
	"data.zaxk.txt",
	"data.zaxp.txt",
	"data.zaxx.txt",
	"data.zayc.txt",
	"data.zayd.txt",
	"data.zayv.txt",
	"data.zazg.txt",
	"data.zazn.txt",
	"data.zazo.txt",
	"data.zazw.txt",
	"data.zazx.txt",
	"data.zbaf.txt",
	"data.zbaq.txt",
	"data.zbbt.txt",
	"data.zbcc.txt",
	"data.zbcj.txt",
	"data.zbcv.txt",
	"data.zbdb.txt",
	"data.zbds.txt",
	"data.zbdx.txt",
	"data.zbeb.txt",
	"data.zbel.txt",
	"data.zbem.txt",
	"data.zbes.txt",
	"data.zbfd.txt",
	"data.zbfg.txt",
	"data.zbfp.txt",
	"data.zbfr.txt",
	"data.zbfx.txt",
	"data.zbfz.txt",
	"data.zbga.txt",
	"data.zbgd.txt",
	"data.zbgu.txt",
	"data.zbgw.txt",
	"data.zbha.txt",
	"data.zbhd.txt",
	"data.zbhe.txt",
	"data.zbht.txt",
	"data.zbhv.txt",
	"data.zbia.txt",
	"data.zbil.txt",
	"data.zbjc.txt",
	"data.zbjh.txt",
	"data.zbjk.txt",
	"data.zbjq.txt",
	"data.zbkf.txt",
	"data.zbkj.txt",
	"data.zbkr.txt",
	"data.zbkv.txt",
	"data.zbla.txt",
	"data.zblh.txt",
	"data.zblq.txt",
	"data.zblr.txt",
	"data.zbls.txt",
	"data.zbmt.txt",
	"data.zbmw.txt",
	"data.zbnp.txt",
	"data.zbnx.txt",
	"data.zbof.txt",
	"data.zbor.txt",
	"data.zbot.txt",
	"data.zbpc.txt",
	"data.zbph.txt",
	"data.zbpm.txt",
	"data.zbpp.txt",
	"data.zbpx.txt",
	"data.zbqu.txt",
	"data.zbrd.txt",
	"data.zbre.txt",
	"data.zbrj.txt",
	"data.zbru.txt",
	"data.zbsd.txt",
	"data.zbse.txt",
	"data.zbsf.txt",
	"data.zbsl.txt",
	"data.zbsm.txt",
	"data.zbsu.txt",
	"data.zbta.txt",
	"data.zbtj.txt",
	"data.zbts.txt",
	"data.zbtx.txt",
	"data.zbua.txt",
	"data.zbuj.txt",
	"data.zbup.txt",
	"data.zbut.txt",
	"data.zbux.txt",
	"data.zbvf.txt",
	"data.zbvg.txt",
	"data.zbvm.txt",
	"data.zbvn.txt",
	"data.zbvp.txt",
	"data.zbwa.txt",
	"data.zbwq.txt",
	"data.zbxw.txt",
	"data.zbxy.txt",
	"data.zbyb.txt",
	"data.zbye.txt",
	"data.zbyv.txt",
	"data.zbzf.txt",
	"data.zbzg.txt",
	"data.zbzo.txt",
	"data.zcak.txt",
	"data.zcao.txt",
	"data.zcaq.txt",
	"data.zcbe.txt",
	"data.zcbm.txt",
	"data.zcby.txt",
	"data.zccl.txt",
	"data.zccu.txt",
	"data.zccx.txt",
	"data.zcda.txt",
	"data.zcdg.txt",
	"data.zcdl.txt",
	"data.zcdv.txt",
	"data.zcdy.txt",
	"data.zcdz.txt",
	"data.zcee.txt",
	"data.zcef.txt",
	"data.zcej.txt",
	"data.zcel.txt",
	"data.zcem.txt",
	"data.zcfn.txt",
	"data.zcft.txt",
	"data.zcfx.txt",
	"data.zcgi.txt",
	"data.zcgo.txt",
	"data.zchd.txt",
	"data.zchw.txt",
	"data.zcic.txt",
	"data.zcih.txt",
	"data.zciq.txt",
	"data.zcis.txt",
	"data.zciy.txt",
	"data.zcjd.txt",
	"data.zcjo.txt",
	"data.zcjy.txt",
	"data.zckd.txt",
	"data.zcko.txt",
	"data.zcku.txt",
	"data.zclh.txt",
	"data.zcli.txt",
	"data.zcll.txt",
	"data.zclm.txt",
	"data.zcln.txt",
	"data.zcls.txt",
	"data.zcmn.txt",
	"data.zcmv.txt",
	"data.zcmx.txt",
	"data.zcmy.txt",
	"data.zcni.txt",
	"data.zcnn.txt",
	"data.zcon.txt",
	"data.zcoy.txt",
	"data.zcpa.txt",
	"data.zcpb.txt",
	"data.zcpc.txt",
	"data.zcpx.txt",
	"data.zcqe.txt",
	"data.zcqg.txt",
	"data.zcql.txt",
	"data.zcqp.txt",
	"data.zcqs.txt",
	"data.zcrg.txt",
	"data.zcrk.txt",
	"data.zcrn.txt",
	"data.zcrv.txt",
	"data.zcse.txt",
	"data.zcsr.txt",
	"data.zcsu.txt",
	"data.zctm.txt",
	"data.zctn.txt",
	"data.zctp.txt",
	"data.zcts.txt",
	"data.zcue.txt",
	"data.zcuh.txt",
	"data.zcve.txt",
	"data.zcvi.txt",
	"data.zcvq.txt",
	"data.zcvt.txt",
	"data.zcwn.txt",
	"data.zcwq.txt",
	"data.zcww.txt",
	"data.zcxh.txt",
	"data.zcxp.txt",
	"data.zcxq.txt",
	"data.zcxr.txt",
	"data.zcyv.txt",
	"data.zcyx.txt",
	"data.zczb.txt",
	"data.zczj.txt",
	"data.zczl.txt",
	"data.zczp.txt",
	"data.zdaa.txt",
	"data.zdaq.txt",
	"data.zdar.txt",
	"data.zdaw.txt",
	"data.zdbf.txt",
	"data.zdby.txt",
	"data.zdcj.txt",
	"data.zdcw.txt",
	"data.zdcy.txt",
	"data.zddb.txt",
	"data.zddl.txt",
	"data.zddm.txt",
	"data.zddp.txt",
	"data.zdds.txt",
	"data.zddv.txt",
	"data.zddx.txt",
	"data.zdeb.txt",
	"data.zdep.txt",
	"data.zdeq.txt",
	"data.zdey.txt",
	"data.zdfl.txt",
	"data.zdga.txt",
	"data.zdgo.txt",
	"data.zdgp.txt",
	"data.zdgt.txt",
	"data.zdgv.txt",
	"data.zdhv.txt",
	"data.zdhw.txt",
	"data.zdib.txt",
	"data.zdic.txt",
	"data.zdil.txt",
	"data.zdji.txt",
	"data.zdju.txt",
	"data.zdkc.txt",
	"data.zdkk.txt",
	"data.zdkp.txt",
	"data.zdkv.txt",
	"data.zdle.txt",
	"data.zdlg.txt",
	"data.zdll.txt",
	"data.zdlm.txt",
	"data.zdlo.txt",
	"data.zdlw.txt",
	"data.zdme.txt",
	"data.zdmw.txt",
	"data.zdnc.txt",
	"data.zdnh.txt",
	"data.zdoc.txt",
	"data.zdod.txt",
	"data.zdof.txt",
	"data.zdoq.txt",
	"data.zdou.txt",
	"data.zdpf.txt",
	"data.zdpg.txt",
	"data.zdpw.txt",
	"data.zdpz.txt",
	"data.zdqk.txt",
	"data.zdqq.txt",
	"data.zdqx.txt",
	"data.zdqz.txt",
	"data.zdro.txt",
	"data.zdrq.txt",
	"data.zdsh.txt",
	"data.zdst.txt",
	"data.zdtr.txt",
	"data.zdtv.txt",
	"data.zduc.txt",
	"data.zdud.txt",
	"data.zduk.txt",
	"data.zduo.txt",
	"data.zdux.txt",
	"data.zdvl.txt",
	"data.zdwd.txt",
	"data.zdwk.txt",
	"data.zdwl.txt",
	"data.zdwn.txt",
	"data.zdwv.txt",
	"data.zdwz.txt",
	"data.zdxw.txt",
	"data.zdyv.txt",
	"data.zdzg.txt",
	"data.zdzi.txt",
	"data.zdzm.txt",
	"data.zdzn.txt",
	"data.zeac.txt",
	"data.zeaf.txt",
	"data.zeag.txt",
	"data.zeai.txt",
	"data.zeaj.txt",
	"data.zeam.txt",
	"data.zeay.txt",
	"data.zebc.txt",
	"data.zebf.txt",
	"data.zebn.txt",
	"data.zebv.txt",
	"data.zecf.txt",
	"data.zedd.txt",
	"data.zedk.txt",
	"data.zedo.txt",
	"data.zeds.txt",
	"data.zedx.txt",
	"data.zedy.txt",
	"data.zeec.txt",
	"data.zeeh.txt",
	"data.zeel.txt",
	"data.zeeq.txt",
	"data.zeew.txt",
	"data.zeez.txt",
	"data.zefd.txt",
	"data.zefp.txt",
	"data.zefs.txt",
	"data.zefu.txt",
	"data.zefv.txt",
	"data.zefw.txt",
	"data.zegk.txt",
	"data.zegl.txt",
	"data.zegn.txt",
	"data.zegz.txt",
	"data.zehb.txt",
	"data.zehj.txt",
	"data.zehp.txt",
	"data.zeid.txt",
	"data.zeik.txt",
	"data.zeil.txt",
	"data.zejk.txt",
	"data.zejn.txt",
	"data.zekw.txt",
	"data.zelj.txt",
	"data.zelt.txt",
	"data.zemb.txt",
	"data.zemf.txt",
	"data.zene.txt",
	"data.zenn.txt",
	"data.zenw.txt",
	"data.zeob.txt",
	"data.zeoh.txt",
	"data.zeoo.txt",
	"data.zeos.txt",
	"data.zeqh.txt",
	"data.zeqn.txt",
	"data.zeqv.txt",
	"data.zerh.txt",
	"data.zerv.txt",
	"data.zerw.txt",
	"data.zesi.txt",
	"data.zesq.txt",
	"data.zess.txt",
	"data.zeta.txt",
	"data.zete.txt",
	"data.zety.txt",
	"data.zeun.txt",
	"data.zeva.txt",
	"data.zeve.txt",
	"data.zevl.txt",
	"data.zevq.txt",
	"data.zevt.txt",
	"data.zevy.txt",
	"data.zewd.txt",
	"data.zewg.txt",
	"data.zewn.txt",
	"data.zewp.txt",
	"data.zewv.txt",
	"data.zexk.txt",
	"data.zexm.txt",
	"data.zexu.txt",
	"data.zexv.txt",
	"data.zexx.txt",
	"data.zeyg.txt",
	"data.zeyu.txt",
	"data.zeyy.txt",
	"data.zezf.txt",
	"data.zezh.txt",
	"data.zezm.txt",
	"data.zezn.txt",
	"data.zezy.txt",
	"data.zfae.txt",
	"data.zfai.txt",
	"data.zfaj.txt",
	"data.zfas.txt",
	"data.zfaw.txt",
	"data.zfaz.txt",
	"data.zfbr.txt",
	"data.zfby.txt",
	"data.zfcg.txt",
	"data.zfcj.txt",
	"data.zfcp.txt",
	"data.zfdk.txt"

};

//string 字符串按空格切分函数，切分结果存储在 vec 中
void StringSplit(string s, vector<string>& vec)
{
	if (vec.size() > 0)//保证vec是空的
		vec.clear();
	int length = s.length();
	int start = 0;
	for (int i = 0;i < length;i++)
	{
		if (s[i] == ' ' && i == 0)//第一个就遇到分割符
		{
			start += 1;
		}
		else if (s[i] == ' ')    //遇到空格，将已切分字符串存入vec
		{
			vec.push_back(s.substr(start, i - start));
			start = i + 1;
		}
		else if (i == length - 1)//到达尾部
		{
			vec.push_back(s.substr(start, i + 1 - start));
		}
	}
}
//两词或搜索
void orsearch(vector<string>& str1, vector<string>& str2)
{
	int number1, number2;
	int length1 = str1.size(), length2 = str2.size();
	vector<int> vec11, vec22;
	for (int i = 0;i < length1;i++)   //将传入的 string 向量转换为 int 向量
	{
		std::stringstream ss;
		ss << str1[i];
		ss >> number1;
		vec11.push_back(number1);
	}
	for (int i = 0;i < length2;i++)
	{
		std::stringstream ss;
		ss << str2[i];
		ss >> number2;
		vec22.push_back(number2);
	}
	sort(vec11.begin(), vec11.end());   //向量排序
	sort(vec22.begin(), vec22.end());
	std::vector<int>::iterator it;
	vector<int> vec(532);
	it = set_union(vec11.begin(), vec11.end(), vec22.begin(), vec22.end(), vec.begin());//求出向量并集
	vec.resize(it - vec.begin());
	cout << vec.size() << "个文件" << endl;
	for (it = vec.begin();it != vec.end();++it)  //输出向量并集，即查询结果
	{
		resultt<< src_fileList[*it] << endl;
	}
}
//两词与搜索
void andsearch(vector<string>& str1, vector<string>& str2)
{
	int number1,number2;
	int length1 = str1.size(),length2= str2.size();
	vector<int> vec11, vec22;
	for (int i = 0;i < length1;i++)
	{
		std::stringstream ss;
		ss << str1[i];
		ss >> number1;
		vec11.push_back(number1);	
	}
	for (int i = 0;i < length2;i++)
	{
		std::stringstream ss;
		ss << str2[i];
		ss >> number2;
		vec22.push_back(number2);
	}
	sort(vec11.begin(), vec11.end());
	sort(vec22.begin(), vec22.end());
	std::vector<int>::iterator it;
	vector<int> vec(532);
	it = set_intersection(vec11.begin(), vec11.end(), vec22.begin(), vec22.end(), vec.begin()); //求向量交集
	vec.resize(it - vec.begin());
	cout << vec.size() << "个文件" << endl;
	if ((it=vec.begin())==vec.end())
	{
		resultt << "there are no these words!" << endl;
	}
	else
	{
		for (;it != vec.end();++it)
		{
			resultt << src_fileList[*it] << endl;
		}
	}
	
}
//三词与搜索
void triandsearch(vector<string>& str1, vector<string>& str2, vector<string>& str3)
{
	int number1, number2,number3;
	int length1 = str1.size(), length2 = str2.size(), length3 = str3.size();
	vector<int> vec11, vec22, vec33;
	for (int i = 0;i < length1;i++)
	{
		std::stringstream ss;
		ss << str1[i];
		ss >> number1;
		vec11.push_back(number1);
	}
	for (int i = 0;i < length2;i++)
	{
		std::stringstream ss;
		ss << str2[i];
		ss >> number2;
		vec22.push_back(number2);
	}
	for (int i = 0;i < length3;i++)
	{
		std::stringstream ss;
		ss << str3[i];
		ss >> number3;
		vec33.push_back(number3);
	}
	sort(vec11.begin(), vec11.end());
	sort(vec22.begin(), vec22.end());
	sort(vec33.begin(), vec33.end());
	std::vector<int>::iterator it;
	vector<int> vec(532);
	it = set_intersection(vec11.begin(), vec11.end(), vec22.begin(), vec22.end(), vec.begin()); //两向量求交集
	vec.resize(it - vec.begin());
	sort(vec.begin(), vec.end());
	vector<int> vec1(532);
	it = set_intersection(vec.begin(), vec.end(), vec33.begin(), vec33.end(), vec1.begin()); //三向量交集
	vec1.resize(it - vec1.begin());
	cout << vec1.size() << "个文件" << endl;
	if ((it = vec1.begin()) == vec1.end())
	{
		resultt << "there are no these words!" << endl;
	}
	else
	{
		for (;it != vec1.end();++it)
		{
			resultt << src_fileList[*it] << endl;
		}
	}
	
}

//单个词语查询
void singleword(vector<string>& str)
{
	int number;
	int length = str.size();
	cout <<length << "个文件" << endl;
	for (int i=0;i < length;i++)
	{
		std::stringstream ss;
		ss << str[i];
		ss >> number;
		resultt << src_fileList[number] <<endl;
	}
}

int main()
{
	string wordd,inputt;
	vector<string>  query;
	vector<string> order;
	ifstream indict("dictionary.txt");
	map<string, vector<string>> dictionary;  //将整个词典存入 map<string, vector<string>> 中
	while (getline(indict, wordd))
	{
		StringSplit(wordd, order);
		string key= order[0];
		vector<string>::iterator it = order.begin();
		order.erase(it);
		dictionary.insert(pair<string, vector<string>>(key, order));
	}
	while (inputt!="N")  //循环输入，知道输入字符'N'
	{
		cout <<"\n"<< "请输入查询词语(多词查询用 ”or“ 或者 ”and“ 例：”你好 and  同学”、“你好 or 同学”,“输入 ”N“ 结束查询)：" << endl;
		getline(cin,inputt);
		resultt << inputt << endl;
		StringSplit(inputt, query);  //输入 string 切分
		t_start = clock();
		//含一个词语		
		if (query.size()==1)
		{
			if (dictionary.count(query[0]) > 0)
			{
				vector<string> tmp = dictionary[query[0]];
				singleword(tmp);
			}
			else
			{
				resultt << "there are no these word!" << endl;
			}
		}
		//含三个词语
		else if (query.size()==3)
		{
			vector<string>::iterator result= find(query.begin(), query.end(), "or");
			if (result==query.end())  //与操作，求交集
			{
				if ((dictionary.count(query[0]))>0&& (dictionary.count(query[2]))>0)//双词查询
				{
					vector<string> tmp1 = dictionary[query[0]];
					vector<string> tmp2 = dictionary[query[2]];
					andsearch(tmp1, tmp2);
				}
				else
				{
					resultt << "there  are no these words!" << endl;
				}
			}
			else  //或操作，求并集
			{
				
				if ((dictionary.count(query[0])) > 0 && (dictionary.count(query[2])) > 0)//双词查询
				{
					vector<string> tmp1 = dictionary[query[0]];
					vector<string> tmp2 = dictionary[query[2]];
					orsearch(tmp1, tmp2);				
				}
				else if ((dictionary.count(query[0])) > 0)
				{
					vector<string> tmp = dictionary[query[0]];
					singleword(tmp);
				}
				else if ((dictionary.count(query[2])) > 0)
				{
					vector<string> tmp = dictionary[query[0]];
					singleword(tmp);
				}
				else
				{
					resultt << "there  are no these words!" << endl;
				}
			}
		}
		//含五个词语
		else if (query.size()==5)
		{
			if ((dictionary.count(query[0]))>0 && (dictionary.count(query[2]))>0&& (dictionary.count(query[4]))>0)
			{
				vector<string> tmp1 = dictionary[query[0]];
				vector<string> tmp2 = dictionary[query[2]];
				vector<string> tmp3 = dictionary[query[4]];
				triandsearch(tmp1, tmp2,tmp3);
			}
			else 
			{
				resultt << "there  are no these words!" << endl;
			}

		}
		else
		{
			resultt << "你走~！" << endl;
		}	
		t_end = clock();
		//输出搜索时间
		resultt << "用时：" <<double(t_end-t_start)<< "ms" << endl;
	}
	
    return 0;
}

