#include "huffmantree.h"

const int width = 25;//���������� 

bool cmp::operator()(BiNode* n1, BiNode* n2)
{
	return n1->weight > n2->weight;
}

BiNode::BiNode(char c, int w): data(c), weight(w)
{
	left = right = NULL;
}

BiNode::BiNode(int w): weight(w)
{
	left = right = NULL;
}

BiNode::~BiNode()
{
	if (left != NULL)
	{
		delete left;
		left = NULL;
	}
	if (right != NULL)
	{
		delete right;
		right = NULL;
	}
}

void BiNode::show()
{
	cout << "char: " << data
		 << setw(width) << "frequency: " << weight
		 << setw(width) << "codes: " << codes
		 << endl;
}

HuffmanTree::HuffmanTree(CharTable& charTable)
{
	//������С�� 
	priority_queue<BiNode*, vector<BiNode*>, cmp> minHeap;

	auto iter = charTable.table.begin();
	for (; iter != charTable.table.end(); iter++)
	{
		BiNode* p = new BiNode(iter->first, iter->second);
		minHeap.push(p);
	}
	
	//���� 
	BiNode* min1;
	BiNode* min2;
	while (minHeap.size() != 1) 
	{
		min1 = minHeap.top();
		minHeap.pop();
		min2 = minHeap.top();
		minHeap.pop();
		
		BiNode* root = new BiNode(min1->weight + min2->weight);
		root->left = min1;
		root->right = min2;
		
		minHeap.push(root);
	}
	
	//��¼���� 
	root = minHeap.top();
	
	//��ÿ�������루���ڲ�������� 
	queue<BiNode*> queue;
	BiNode* p = root;
	
	if (p == NULL)
		return;
		
	queue.push(p);
	while (!queue.empty())
	{
		p = queue.front();
		queue.pop();
		
		if (p->left != NULL){
			p->left->codes = p->codes + "0";
			queue.push(p->left);
		}
		if (p->right != NULL){
			p->right->codes = p->codes + "1";
			queue.push(p->right);
		}
		
		//��Ҷ���������� 
		if ((p->left == NULL) && (p->right == NULL)) 
		{
			codeTable.insert(pair<char, string>(p->data, p->codes));
		}
	}
}

HuffmanTree::~HuffmanTree()
{
	if (root != NULL)
	{
		delete root;//�ݹ�ʵ�� 
		root = NULL;
	}
}

void HuffmanTree::show(const string& filename)
{
	fstream file(filename.data(), ios::out);
	if (file.bad()){
		cout << "cann't open " << filename << endl;
		return;
	}
	
	queue<BiNode*> queue;
	BiNode* p = root;
	
	if (p == NULL)
		return;
	
	cout << "�ַ��� "
		 << setw(width) << "��Ƶ��     "
		 << setw(width) << "���룺"
		 << endl;
	file << "�ַ��� "
		 << setw(width) << "��Ƶ��     "
		 << setw(width) << "���룺"
		 << endl;

	queue.push(p);
	while (!queue.empty())
	{
		p = queue.front();
		queue.pop();
		
		if (p->left != NULL){
			queue.push(p->left);
		}
		if (p->right != NULL){
			queue.push(p->right);
		}
		
		//ֻ��Ҷ��������� 
		if ((p->left == NULL) && (p->right == NULL)) 
		{
			//��ӡ 
			p->show();
			//д���ļ�
			file << "char: " << p->data
				 << setw(width) << "frequency: " << p->weight
				 << setw(width) << "codes: " << p->codes
				 << endl;
		}
	}
	
	file.close();
}

void HuffmanTree::encode(const string& filename1, const string& filename2)
{
	fstream sourceFile(filename1.data(), ios::in);//��ԭ�ı��ļ� 
	if (sourceFile.bad()){
		cout << "cann't open " << filename1 << endl;
		return;
	}
	fstream desFile(filename2.data(), ios::out | ios::binary);//����Ŀ��������ļ� 
	if (desFile.bad()){
		cout << "cann't open " << filename2 << endl;
		return;
	}
	
	string codes;//���б��� 
	//ÿ�ζ���һ���ַ����������׷����codes 
	char c1;
	while (sourceFile.get(c1))//ÿ�ζ���һ�ַ� 
	{
		auto iter = codeTable.find(c1);
		if (iter == codeTable.end())//c1���ڱ�����У����� 
		{
			cout << "ERROR!!!";
			return;
		}
		else//c1�ڱ������ 
			codes.append(iter->second);
	}
	
//	cout << "codes: " << codes << endl;//debug
	
	//�������ļ�ǰ�ĸ��ֽڴ�����ݵ���Чλ�� 
	int bitSize = codes.size();
	desFile.write((const char*)(&bitSize), sizeof(bitSize));
	
	//������ֽڿ�ʼ������� 
	int byteSize = codes.size()/8 + 1;
	
	for (int i = 0; i < byteSize; i++)
	{
		bitset<8> byte(codes.substr(i*8, 8));//ֱ����string��ʼ��byte
		
		//��һ�ֽڱ���д���ļ� 
		desFile.write((const char*)&byte, byte.size()/8);
	}
	
	sourceFile.close();
	desFile.close();
}

void HuffmanTree::decode(const string& filename1, const string& filename2)
{
	fstream sourceFile(filename1.data(), ios::in | ios::binary);//��ԭ�������ļ� 
	if (sourceFile.bad()){
		cout << "cann't open " << filename1 << endl;
		return;
	}
	fstream desFile(filename2.data(), ios::out);//����Ŀ���ı��ļ� 
	if (desFile.bad()){
		cout << "cann't open " << filename2 << endl;
		return;
	}
	
	//�ȶ���ǰ���ֽ� 
	int bitSize;
	sourceFile.read((char*)(&bitSize), sizeof(bitSize));
	int byteSize = bitSize/8 + 1;
	
	string codes;
	for (int i = 0; i < byteSize; i++)
	{
		//����һ�ֽ� 
		bitset<8> byte;
		sourceFile.read((char*)&byte, byte.size()/8);
		//����һ�ֽڱ���תΪstring 
		codes.append(byte.to_string());
	}
	
	//�Ƚ�����λȫ�����룬��ɾȥ���ಿ�� 
	int n = byteSize*8 - bitSize;
	cout << "n: " << n << endl;//debug
	codes.erase((byteSize-1)*8, n);
	
//	cout << "codes: " << codes << endl;//debug
//	return;
	
	string curCodes;
	char c;
	BiNode* p;
	int i = 0; 
	while (i < codes.size())
	{
		curCodes.clear();//������ϴεı��� 
		
		while (1)//һ��ѭ������һ�ַ�
		{
			if (i >= codes.size())//����������� 
				break;
			
			curCodes += codes.at(i++);
			p = root;
			int pos = 0;
			
			//Ѱ��curCodes��Ӧ��Ҷ��� 
			while ((p != NULL) && (pos < curCodes.size()))
			{
				if (curCodes.at(pos) == '0')
					p = p->left;
				else if (curCodes.at(pos) == '1')
					p = p->right;
				pos++;
			}
			
			//��pָ��Ҷ�����posָ��curCodesĩβ����ɽ���һ���ַ� 
			if ((p->left == NULL) && (p->right == NULL) &&
				(pos == curCodes.size()))
			{
				break;
			}
			//��֮����Ҫ��������������� 
		}
		
		desFile << p->data;//�ɹ�����һ���ַ� 
	}
	
	sourceFile.close();
	desFile.close();
}
