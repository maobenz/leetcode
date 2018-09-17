
/*
思想：
       每次从数据集中根据最大信息增益选取一个最好特征，将数据进行划分，每次划分都会消耗一个特征，
    使得特征越来越少，当所有数据集都是同一类，或者消耗完所有特征时，划分结束。
  
	信息熵：  Entropy(D) = -sum( p_i * log_2(p_i) )   
			  D为样本集合
	          1<= i <= 样本D中所包含的类别数
			  p_i 为第i个类别在D中所占的比例
	信息增益：Gain(D_all) = Entropy(D_all) - sum( D_i / D_all * Entorpy(D_i) )
	          D_all 为总数据集
			  D_i 为第i个子数据集
	          1<= i <= 子数据集数
*/
 
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <map>
#include <math.h>
using namespace std;
 
#define N 14
#define feature 4
 
vector< vector<string> > X; 
string x[N][feature+1] = 
{
	{"Sunny",    "Hot",  "High",   "Weak",    "no"},   //反例，不打网球
	{"Sunny",    "Hot",  "High",   "Strong",  "no"},
	{"Overcast", "Hot",  "High",   "Weak",    "yes"},
	{"Rain",     "Mild", "High",   "Weak",    "yes"},
	{"Rain",     "Cool", "Normal", "Weak",    "yes"},
	{"Rain",     "Cool", "Normal", "Strong",  "no"},
	{"Overcast", "Cool", "Normal", "Strong",  "yes"},
	{"Sunny",    "Mild", "High",   "Weak",    "no"},
	{"Sunny",    "Cool", "Normal", "Weak",    "yes"},
	{"Rain",     "Mild", "Normal", "Weak",    "yes"},
	{"Sunny",    "Mild", "Normal", "Strong",  "yes"},
	{"Overcast", "Mild", "High",   "Strong",  "yes"},
	{"Overcast", "Hot",  "Normal", "Weak",    "yes"},
	{"Rain",     "Mild", "High",   "Strong",  "no"},
};
 
string attribute[] =   //特征的名称，比如 Outlook取值：Sunny, Overcast, Rain
	{"Outlook", "Temperature", "Humidity", "Wind"};
vector<string> attributes;
 
//创建数据集
void createDataset()
{
	//创建数据集
	X = vector< vector<string> >(N, vector<string>(feature+1));
	int i, j;
	for(i=0; i<N; i++)
	{
		for(int j=0; j<feature+1; j++)
		{
			X[i][j] = x[i][j];
		}
	}
 
	//创建特征
	for(i=0; i<feature; i++)
		attributes.push_back(attribute[i]);
}
 
//计算给定数据集的香农熵
double calcShanno(vector< vector<string> > &data)
{
	 int n = data.size();
	 map<string, int> classCounts;
	 int i;
	 int label = data[0].size() - 1;
	 for(i=0; i<n; i++)  //初始为0
	 {
		classCounts[ data[i][label] ] = 0;
	 }
	 for(i=0; i<data.size(); i++)  //每当出现一次，+1
	 {
		classCounts[ data[i][label] ] += 1;
	 }
 
	 //计算香农熵
	 double shanno = 0;
	 map<string, int>::iterator it;
	 for(it = classCounts.begin(); it != classCounts.end(); it++)
	 {
		 double prob = (double)(it->second) / (double)n;
		 shanno -= prob * ( log(prob) / log(2) );
	 }
	 return shanno;
}
 
//按照给定特征划分数据集，划分后的数据集中不包含给定特征，即新的数据集的维度少了一个
//axis ：特征下标
//value：特征值
vector< vector<string> > splitDataSet(vector< vector<string> > data, int axis, string value)
{
	vector< vector<string> > result;
	for(int i=0; i<data.size(); i++)
	{
		if(data[i][axis] == value)
		{
			//将“当前特征”这个维度去掉
			vector<string> removed(data[i].begin(), data[i].begin()+axis);
			removed.insert(removed.end(), data[i].begin()+axis+1, data[i].end());
			result.push_back(removed);
		}
	}
	return result;
}
 
//创建特征列表
vector<string> createFeatureList(vector< vector<string> > &data, int axis)
{
	int n = data.size();
	vector<string>featureList;   //特征的所有取值
	set<string> s;
	for(int j=0; j<n; j++)    //寻找该特征的所有可能取值
		s.insert(data[j][axis]);
	set<string>::iterator it;
	for(it = s.begin(); it != s.end(); it++)
	{
		featureList.push_back(*it);
	}
	return featureList;
}
 
//选择最好的数据集划分方式
int chooseBestFeatureToSplit(vector< vector<string> > &data)
{
	int n = data[0].size() - 1; 
	double bestEntropy = calcShanno(data);  //初始香农熵
	double bestInfoGain = 0;   //最大的信息增益
	int bestFeature = 0;       //最好的特征
	for(int i=0; i<n; i++)     //所有特征
	{
		double newEntropy = 0;
		vector<string> featureList = createFeatureList(data, i);  //该特征的所有可能取值
		for(int j=0; j<featureList.size(); j++)
		{
			vector< vector<string> > subData = splitDataSet(data, i, featureList[j]);
			double prob = (double)subData.size() / (double)data.size();
			newEntropy += prob * calcShanno(subData);   
		}
		double infoGain = bestEntropy - newEntropy;  //信息增益，即熵的减少，或数据无序度的减少
		if(infoGain > bestInfoGain)
		{
			bestInfoGain = infoGain;
			bestFeature = i;
		}
	}
	return bestFeature;
}
 
//返回出现次数最多的分类名称
//如果数据集已处理了所有属性，但类标签依然不是唯一的，采用多数表决的方法定义叶子节点的分类
string majorityCnt(vector<string> &classList)
{
	int n = classList.size();
	map<string, int> classCount;
	int i;
	for(i=0; i<n; i++)
	{
		classCount[classList[i]] = 0;
	}
	for(i=0; i<n; i++)
	{
		classCount[classList[i]] += 1;
	}
 
	int maxCnt = 0;
	map<string, int>::iterator it;
	string result = "";
	for(it = classCount.begin(); it != classCount.end(); it++)
	{
		if(it->second > maxCnt)
		{
			maxCnt = it->second;
			result = it->first;
		}
	}
	return result;
}
 
struct Node
{
	string attribute; 
	string val; 
	bool isLeaf;
	vector<Node*> childs;
 
	Node()
	{
		val = "";
		attribute = "";
		isLeaf = false;
	}
};
 
Node *root = NULL;
 
//递归构建决策树
Node* createTree(Node *root, vector< vector<string> > &data, vector<string> &attribute)
{
	if(root == NULL)
		root = new Node();
	vector<string> classList;
	set<string> classList1;
	int i, j;
	int label = data[0].size() - 1;
	int n = data.size();
	for(i=0; i<n; i++)
	{
		classList.push_back(data[i][label]);
		classList1.insert(data[i][label]);
	}
	if(classList1.size() == 1)  //如果所有实例都属于同一类，停止划分
	{
		if(classList[0] == "yes")
			root->attribute = "yes";
		else
			root->attribute = "no";
		root->isLeaf = true;
		return root;
	}
	if(data[0].size() == 1)  //遍历完所有特征，返回出现次数最多的类别
	{
		root->attribute = majorityCnt(classList);
		return root;
	}
 
	int bestFeatureIndex = chooseBestFeatureToSplit(data);
	vector<string> featureList = createFeatureList(data, bestFeatureIndex);  //得到属性的所有可能值
	string bestFeature = attribute[bestFeatureIndex];
 
	root->attribute = bestFeature;   //记录要划分的属性
 
	for(i=0; i<featureList.size(); i++)  //对于当前属性的每个可能值，创建新的分支
	{
		vector<string> subAttribute;  //新的属性列表，不包含当前要划分的属性，即消耗了一个特征，特征的维度少了一个
		for(j=0; j<attribute.size(); j++)
		{
			if(bestFeature != attribute[j])
				subAttribute.push_back(attribute[j]);
		}
		Node *newNode = new Node();
		newNode->val = featureList[i];   //记录属性的取值
		vector< vector<string> > result=splitDataSet(data, bestFeatureIndex, featureList[i]);
		newNode=createTree(newNode, result, subAttribute);
		root->childs.push_back(newNode);
	}
	return root;
}
 
//打印
void print(Node *root, int depth)
{
	int i;
	for(i=0; i<depth; i++)
		cout << "\t";
	
	if(root->val != "")
	{
		cout << root->val << endl;
		for(i=0; i<depth+1; i++)
			cout << "\t";
	}
	cout << root->attribute << endl;
	vector<Node*>::iterator it;
	for(it = root->childs.begin(); it != root->childs.end(); it++)
	{
		print(*it, depth+1);
	}
}
 
//预测x
string classify(Node *root, vector<string> &attribute, string *test)
{
	string firstFeature = root->attribute;
	int firstFeatureIndex;
	int i;
	for(i=0; i<feature; i++)  //找到根节点是第几个特征
	{
		if(firstFeature == attribute[i])
		{
			firstFeatureIndex = i;
			break;
		}
	}
	if(root->isLeaf)  //如果是叶子节点，直接输出结果
		return root->attribute;
	for(i=0; i<root->childs.size(); i++)
	{
		if(test[firstFeatureIndex] == root->childs[i]->val)
		{
			return classify(root->childs[i], attribute, test);
		}
	}
}
 
//释放节点
void freeNode(Node *root)
{
	if(root == NULL)
		return;
	vector<Node*>::iterator it;
	for(it=root->childs.begin(); it != root->childs.end(); it++)
		freeNode(*it);
	delete root;
}
 
int main(void)
{	

	createDataset();
	root =  createTree(root, X, attributes);
	print(root, 0);

	string test[] = {"Sunny", "Hot",  "High", "Strong"};
	int i;
	cout << endl << "属性：";
	for(i=0; i<feature; i++)
		cout << attributes[i] << "\t";
	cout << endl << "例子：";
	for(i=0; i<feature; i++)
		cout << test[i] << "\t";
	cout << endl << "预测：";
	cout << classify(root, attributes, test) << endl;
	freeNode(root);

	return 0;
}
