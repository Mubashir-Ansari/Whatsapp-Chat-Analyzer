
#include<iostream>
#include<bits/stdc++.h>
#include <queue>
#include<stack>
#include<fstream>


using namespace std;




template<class T>
class TreeNode;
template<class T>
class Tree;

template<class T>
class TreeNode{

    public:
    T data;
    T user ;
    int frequency;
    TreeNode<T> *leftNode;
    TreeNode<T> *rightNode;
    public:
    TreeNode(T data , T user);
    TreeNode(T data);
    void traverseInOrder();
};

template<class T>
class Tree{

    public:
    TreeNode<T> *root;
    long long int count;
    public:
    Tree();
    void insert(T data , T user = "");
    void traverseInOrder();
    void resetFreq();
    TreeNode<T>* getRoot();
    int freqSum();  // gives sum of frequencies of all elements in a tree
    TreeNode<T>* search(T value); // searches for a value, if it's already there, increments node's frequency.
	long long int getCount(); //gives number of elements in a tree
    void BFS(); 
    template<class U>
    friend ifstream & operator >> (ifstream& file  , Tree<T> &tree);
    template<class U>
    friend ofstream & operator << (ofstream &file , Tree<T> &tree );
};

template<class T>
TreeNode<T>::TreeNode(T data)
    {
        this->data = data;
        frequency = 0;
        leftNode = rightNode =  NULL;
    }
template<class T>
TreeNode<T>::TreeNode(T data, T user)
    {
        this->data = data;
        this->user = user;
        frequency = 0;
        leftNode = rightNode =  NULL;
    }

template<class T>
TreeNode<T>* Tree<T>::getRoot()
{
    return root;
}
template<class T>
void Tree<T>::BFS()
{
    TreeNode<T> *temp = root;
    queue<TreeNode<T> *> q;

    q.push(temp);

    while (!q.empty() && temp != NULL)
    {
        temp = q.front();
        q.pop();

        cout<<temp->data<<" ";
        if(temp->leftNode != NULL)
            q.push(temp->leftNode);

        if(temp->rightNode != NULL)
        q.push(temp->rightNode);    
        
    }
    cout<<endl;
}


template<class T>
void Tree<T>::resetFreq()
{
    TreeNode<T> *temp = root;
    queue<TreeNode<T> *> q;

    q.push(temp);

    while (!q.empty() && temp != NULL)
    {
        temp = q.front();
        q.pop();

 	temp->frequency=0;
        if(temp->leftNode != NULL)
            q.push(temp->leftNode);

        if(temp->rightNode != NULL)
        q.push(temp->rightNode);    
        
    }
    
}
template<class T>
int Tree<T>::freqSum()
{
	int sum =0;
    TreeNode<T> *temp = root;
    queue<TreeNode<T> *> q;

    q.push(temp);

    while (!q.empty() && temp != NULL)
    {
        temp = q.front();
        q.pop();

       sum+=temp->frequency;
        if(temp->leftNode != NULL)
            q.push(temp->leftNode);

        if(temp->rightNode != NULL)
        q.push(temp->rightNode);    
        
    }
    
    return sum;
}



template<class T>
void TreeNode<T>::traverseInOrder()
    {
        if(leftNode != NULL)
        leftNode->traverseInOrder();

        cout<<"Date: "<<data<<"  ";
        cout<<"Frequency: "<<this->frequency<<endl;

        if(rightNode != NULL)
        rightNode->traverseInOrder();
    }

template<class T>
Tree<T>::Tree()
    {
        root = NULL;
        count = 0;
    }
template<class T>
long long int Tree<T>::getCount()
{
    return count;
}

template<class T>
TreeNode<T>* Tree<T>::search(T value)
{
	stack<TreeNode<T> *> tempStack;
	TreeNode<T> *temp = root;

	while (temp != NULL || !tempStack.empty())
	{
		while (temp != NULL)
		{
			if(temp->data == value)
			{
				temp->frequency++;
                return temp;
				break;
			}
			tempStack.push(temp);
			temp = temp->leftNode;
		}
		if(!tempStack.empty())
		{
			temp = tempStack.top();
			tempStack.pop();
		}
		temp = temp->rightNode;
	}
    return NULL;
}
	



template<class T>
void Tree<T>::insert(T value , T user)
    {
       if(root == NULL)
       { 
		 root = new TreeNode<T>(value , user);
		 root->frequency++;
		 this->count++;
    }
        else if(this->search(value))
         	{
         		
         		return;
			 }
		else	 
        {
        
//		  	if(root->data == value)
//            {
//                ++ (root->frequency);
//                return;
//            }
            queue<TreeNode<T> * > q;
            q.push(root);
            while (!q.empty())
            {
                TreeNode<T> *temp = q.front();
				q.pop();
                if(temp->leftNode != NULL)
                q.push(temp->leftNode);
                else
                {
	                temp->leftNode = new TreeNode<T>(value , user);
	                temp->leftNode->frequency++;
                    ++count;
	                break;
                }
                if(temp->rightNode != NULL )
                q.push(temp->rightNode);
                else
                {
                    temp->rightNode = new TreeNode<T>(value , user);
                   temp->rightNode->frequency++;
                    ++count;
                    break;
                }
            }
        }
    }
template<class T>
void Tree<T>::traverseInOrder()
    {
        root->traverseInOrder();
    }
// read data from file
template<class T>
ifstream& operator >> (ifstream& file , Tree<T> &tree )
    {
        T element;
        while (file)
        {
            file>>element;
            tree.insert(element , " ");
        }
        return file;
    }
// write data into file
template<class T>
ofstream& operator << (ofstream &file , Tree<T> &root)
    {

        return file;
    }

//template<class T>
//void extractAnalysisData(Tree<T> *emptyObj , ifstream &file)
//{
//    string element;
//    while (file)
//    {
//        file>>element;
//        transform(element.begin() ,element.end() , element.begin() , ::tolower);
//        emptyObj->insert(element);
//    }
//}

//template<class T>
//void extractChatData(ifstream &file , Tree<T> *chatTree1 , Tree<T> *chatTree2 ,  Tree<T> *dataTree)
//{
//    string user1 = "";
//    string user2 = "";
//    string lastUser = "";
//    string element;
//    while (file)
//    {
//        file>>element;
//        if(element == "<Media" || element == "omitted>")
//        continue;
//        transform(element.begin() ,element.end() , element.begin() , ::tolower);
//
//        if( (element.length() == 9 || element.length() == 8 || element.length() == 7) && (element[1] == '/' || element[2] == '/' ) && (element[4] == '/' || element[5] == '/' || element[3] == '/'))
//        {
//            string date = element;
//            for(int i = 0 ; i < 3 ; i++) file>>element;
//            lastUser = "";
//            file>>element;
//            if(element[element.length()-1] != ':') //if user's name is more than than one word
//            {
//                lastUser = "";
//                while (element[element.length()-1] != ':')  //keep adding names(first middle... nth word of the long possible name) until there is colon)
//                {
//                    lastUser += element + " ";
//                    file>>element;
//                }
//                lastUser += element.substr(0 , element.length() -1 ); 
//            }
//            else
//            lastUser = element.substr(0 , element.length() - 1 );
//            
//            if(user1 == "" && user2 != lastUser)
//            {
//                user1 = lastUser;
//            }
//            else if(user2 == "" && user1 != lastUser)
//            {
//                user2 = lastUser;
//            }
//            dataTree->insert(date , lastUser);
//        }
//        else if (element.length() > 1 /*only words more than two letters are expected*/ || (element == "i" || element == "?") )
//        {
//            if(lastUser == user1)
//            {
//			
//            chatTree1->insert(element , user1); 
//		//	cout<<element<<" ";
//        }
//			else
//			{
//			
//          //  cout<<element<<endl;
//			chatTree2->insert(element , user2);
//		}
//        }
//    }
//}
//
//template<class T>
//void AnalysisData(Tree<T> *chatTree1 , Tree<T> *chatTree2 )
//{
//    ifstream friendFile("./data/analysis/friendsWords.txt");
//    ifstream homeFile("./data/analysis/homeWords.txt");
//    ifstream studentFile("./data/analysis/studentWords.txt");
//    ifstream teacherFile("./data/analysis/teacherWords.txt");
//
//    Tree<T> *Friend = new Tree<T>(); 
//    Tree<T> *Home = new Tree<T>(); 
//    Tree<T> *Student = new Tree<T>(); 
//    Tree<T> *Teacher = new Tree<T>();
//
//    extractAnalysisData(Friend , friendFile);
//    extractAnalysisData(Home , homeFile);
//    extractAnalysisData(Student , studentFile);
//    extractAnalysisData(Teacher , teacherFile);
//    
//    
//    
//
//    studentAnalysis(chatTree1 , chatTree2 , Student);
//    homeAnalysis(chatTree1 , chatTree2 , Home);
//    friendAnalysis(chatTree1 , chatTree2 , Friend);
//    teacherAnalysis(chatTree1 , chatTree2 , Teacher);
//
//
//    friendFile.close();
//    homeFile.close();
//    studentFile.close();
//    teacherFile.close();
//
//    
//}

//template<class T>
//void studentAnalysis(Tree<T> *chat1 ,Tree<T> *chat2 , Tree<T> *data)
//{
//    float percent =  makeAnalysis(chat1 , chat2 , data );
//    if(percent < 1)
//    percent = 0;
//    cout << "Student : "<< percent << "%" << endl;
//}
//
//template<class T>
//void homeAnalysis(Tree<T> *chat1 ,Tree<T> *chat2 , Tree<T> *data)
//{
//    float percent =  makeAnalysis(chat1 , chat2 , data );
//    if(percent < 1)
//    percent = 0;
//    cout << "Family person : "<< percent << "%" << endl;
//}
//
//template<class T>
//void friendAnalysis(Tree<T> *chat1 ,Tree<T> *chat2 , Tree<T> *data)
//{
//    float percent =  makeAnalysis(chat1 , chat2 , data );
//    if(percent < 1)
//    percent = 0;
//    cout << "Friend : "<< percent << "%" << endl;
//}
//
//template<class T>
//void teacherAnalysis(Tree<T> *chat1 ,Tree<T> *chat2 , Tree<T> *data)
//{
//    float percent =  makeAnalysis(chat1 , chat2 , data );
//    if(percent < 1)
//    percent = 0;
//    cout << "Teacher : "<< percent << "%" << endl;
//}


//void Pause()
//{
//    cout<<"press any key to continue";
//    cin.get();
//    cin.get();
//}



template<class T>

float makeAnalysis( Tree<T> *chat1 , Tree<T> *chat2 , Tree<T> *data )
{		
	
	data->resetFreq();

	  TreeNode<T> *temp1 = chat1->getRoot();
	   stack<TreeNode<T> *> tempStack;
	
	 while (temp1 != NULL || !tempStack.empty())
	{
		while (temp1 != NULL )
		{
            data->search(temp1->data);
         	tempStack.push(temp1);
			temp1 = temp1->leftNode;
		}
		
		if(!tempStack.empty())
		{
			temp1 = tempStack.top();
			tempStack.pop();
		}
		
		temp1 = temp1->rightNode;
	}
	
	
	temp1 = chat2->getRoot();
	
	  while (temp1 != NULL || !tempStack.empty())
	{
		while (temp1 != NULL )
		{
            data->search(temp1->data);
         	tempStack.push(temp1);
			temp1 = temp1->leftNode;
		}
		
		if(!tempStack.empty())
		{
			temp1 = tempStack.top();
			tempStack.pop();
		}
		
		temp1 = temp1->rightNode;
	}
	
	
	
	
	int totalFreq = data->freqSum();
	int count = data->getCount();
	float percent = ((float)totalFreq/(float)count)*100;

	return percent;
	
	
}


//template<class T>
//void welcome(Tree<T> *chatTree1 , Tree<T> *chatTree2, Tree<T> *dateTree)
//{
	

//	cout<<"*********************************************************************************************************************"<<endl;
//	cout<<"|"<<"\t\t\t\t\t"<<"Welcome to WhatsApp Chat Analyser"<<"\t\t\t\t\t\t    "<<"|"<<endl;
//	cout<<"*********************************************************************************************************************"<<endl;
//	
//	cout<<"\t\t\t\t\tFirst User: "<<chatTree1->root->user<<endl;
//    cout<<"\t\t\t\t\tSecond User: "<<chatTree2->root->user<<endl;
//    cout<<endl;
//	cout<<"*********************************************************************************************************************"<<endl;
//menu:
//	cout<<endl;
//	
//	cout<<"\t\t\t\t\t  ***********************************"<<endl;
//	cout<<"\t\t\t\t1.\t  * Conversation statistics by date *"<<endl;
//	cout<<"\t\t\t\t\t  ***********************************"<<endl;
//	cout<<"\t\t\t\t2.\t  *        Word statistics          *"<<endl;
//	cout<<"\t\t\t\t\t  ***********************************"<<endl;
//	cout<<"\t\t\t\t3.\t  *  Conversation Topic Prediction  *"<<endl;
//	cout<<"\t\t\t\t\t  ***********************************"<<endl;
//	cout<<"\t\t\t\t4.\t  *           Exit                 *"<<endl;
//	cout<<"\t\t\t\t\t  ***********************************"<<endl;
//	string choice;
//again:	
//	cin>>choice;
//	
//	
//	if(choice=="1")
//	{
//		TreeNode<string>* temp;
//		cout<<"Messages for each date:"<<endl;
//		dateTree->traverseInOrder();
//		
//		cout<<endl;
//	}
//	else if(choice=="2")
//	{
//		
//		cout<<"Word statistics for: "<<chatTree1->root->user<<":"<<endl;
//		cout<<"Total Words Typed:"<<chatTree1->freqSum()<<endl;
//		cout<<"Unique words:"<<chatTree1->getCount();
//		cout<<endl;
//		cout<<endl<<endl;
//		
//		cout<<"Word statistics for: "<<chatTree2->root->user<<":"<<endl;
//		cout<<"Total Words Typed:"<<chatTree2->freqSum()<<endl;
//		cout<<"Unique words:"<<chatTree2->getCount();
//		cout<<endl<<endl;
//		
//	}
//	
//	else if(choice=="3")
//		AnalysisData(chatTree1, chatTree2);
//	
//	else if(choice=="4")
//	{
//		exit(0);
//	}
//	else
//	{
//		cout<<"You have entered a wrong choice. Please enter again."<<endl;	
//		goto again;
//	}
//
//	
//	Pause();
//
////	clearScreen();
//	goto menu;
//}

int main()
{
	


    Tree<string> *chatTree1 , *chatTree2 , *dataTree;
    chatTree1 = new Tree<string>();
    chatTree2 = new Tree<string>();
    dataTree = new Tree<string>();
    ifstream file("./data/chat/chat.txt");
    //extractChatData(file , chatTree1 , chatTree2 , dateTree);
    
    
      string user1 = "";
    string user2 = "";
    string lastUser = "";
    string element;
    while (file)
    {
        file>>element;
        if(element == "<Media" || element == "omitted>")
        continue;
        transform(element.begin() ,element.end() , element.begin() , ::tolower);

        if( (element.length() == 9 || element.length() == 8 || element.length() == 7) && (element[1] == '/' || element[2] == '/' ) && (element[4] == '/' || element[5] == '/' || element[3] == '/'))
        {
            string date = element;
            for(int i = 0 ; i < 3 ; i++) file>>element;
            lastUser = "";
            file>>element;
            if(element[element.length()-1] != ':') //if user's name is more than than one word
            {
                lastUser = "";
                while (element[element.length()-1] != ':')  //keep adding names(first middle... nth word of the long possible name) until there is colon)
                {
                    lastUser += element + " ";
                    file>>element;
                }
                lastUser += element.substr(0 , element.length() -1 ); 
            }
            else
            lastUser = element.substr(0 , element.length() - 1 );
            
            if(user1 == "" && user2 != lastUser)
            {
                user1 = lastUser;
            }
            else if(user2 == "" && user1 != lastUser)
            {
                user2 = lastUser;
            }
            dataTree->insert(date , lastUser);
        }
        else if (element.length() > 1 /*only words more than two letters are expected*/ || (element == "i" || element == "?") )
        {
            if(lastUser == user1)
            {
			
            chatTree1->insert(element , user1); 
		//	cout<<element<<" ";
        }
			else
			{
			
          //  cout<<element<<endl;
			chatTree2->insert(element , user2);
		}
        }
    }
    
    
    
    //welcome(chatTree1, chatTree2, dateTree);
    
    	cout<<"*********************************************************************************************************************"<<endl;
	cout<<"|"<<"\t\t\t\t\t"<<"Welcome to WhatsApp Chat Analyser"<<"\t\t\t\t\t\t    "<<"|"<<endl;
	cout<<"*********************************************************************************************************************"<<endl;
	
	cout<<"\t\t\t\t\tFirst User: "<<chatTree1->root->user<<endl;
    cout<<"\t\t\t\t\tSecond User: "<<chatTree2->root->user<<endl;
    cout<<endl;
	cout<<"*********************************************************************************************************************"<<endl;
menu:
	cout<<endl;
	
	cout<<"\t\t\t\t\t  ***********************************"<<endl;
	cout<<"\t\t\t\t1.\t  * Conversation statistics by date *"<<endl;
	cout<<"\t\t\t\t\t  ***********************************"<<endl;
	cout<<"\t\t\t\t2.\t  *        Word statistics          *"<<endl;
	cout<<"\t\t\t\t\t  ***********************************"<<endl;
	cout<<"\t\t\t\t3.\t  *  Conversation Topic Prediction  *"<<endl;
	cout<<"\t\t\t\t\t  ***********************************"<<endl;
	cout<<"\t\t\t\t4.\t  *           Exit                 *"<<endl;
	cout<<"\t\t\t\t\t  ***********************************"<<endl;
	string choice;
again:	
	cin>>choice;
	
	
	if(choice=="1")
	{
		TreeNode<string>* temp;
		cout<<"Messages for each date:"<<endl;
		dataTree->traverseInOrder();
		
		cout<<endl;
	}
	else if(choice=="2")
	{
		
		cout<<"Word statistics for: "<<chatTree1->root->user<<":"<<endl;
		cout<<"Total Words Typed:"<<chatTree1->freqSum()<<endl;
		cout<<"Unique words:"<<chatTree1->getCount();
		cout<<endl;
		cout<<endl<<endl;
		
		cout<<"Word statistics for: "<<chatTree2->root->user<<":"<<endl;
		cout<<"Total Words Typed:"<<chatTree2->freqSum()<<endl;
		cout<<"Unique words:"<<chatTree2->getCount();
		cout<<endl<<endl;
		
	}
	
	else if(choice=="3"){
	
	//	AnalysisData(chatTree1, chatTree2);
	
	
	ifstream friendFile("./data/analysis/friendsWords.txt");
    ifstream homeFile("./data/analysis/homeWords.txt");
    ifstream studentFile("./data/analysis/studentWords.txt");
    ifstream teacherFile("./data/analysis/teacherWords.txt");

    Tree<string> *Friend = new Tree<string>(); 
    Tree<string> *Home = new Tree<string>(); 
    Tree<string> *Student = new Tree<string>(); 
    Tree<string> *Teacher = new Tree<string>();

    //extractAnalysisData(Friend , friendFile);
    
    
//    template<class T>
//void extractAnalysisData(Tree<T> *emptyObj , ifstream &file)
//{
    string element1;
    while (friendFile)
    {
        friendFile>>element1;
        transform(element1.begin() ,element1.end() , element1.begin() , ::tolower);
        Friend->insert(element1);
    }
//}
   // extractAnalysisData(Home , homeFile);
    string element2;
    while (homeFile)
    {
        homeFile>>element2;
        transform(element2.begin() ,element2.end() , element2.begin() , ::tolower);
        Home->insert(element2);
    }
    
    //extractAnalysisData(Student , studentFile);
    
    string element3;
    while (studentFile)
    {
        studentFile>>element3;
        transform(element3.begin() ,element3.end() , element3.begin() , ::tolower);
        Student->insert(element3);
    }
    
    
    //extractAnalysisData(Teacher , teacherFile);
    string element4;
    while (teacherFile)
    {
        teacherFile>>element4;
        transform(element4.begin() ,element4.end() , element4.begin() , ::tolower);
        Teacher->insert(element4);
    }
    
    

   // studentAnalysis(chatTree1 , chatTree2 , Student);

    float percent1 =  makeAnalysis(chatTree1 , chatTree2 , Student );
    if(percent1 < 1)
    percent1 = 0;
    cout << "Student : "<< percent1 << "%" << endl;

   
   // homeAnalysis(chatTree1 , chatTree2 , Home);
   float percent2 =  makeAnalysis(chatTree1 , chatTree2 , Home );
    if(percent2 < 1)
    percent2 = 0;
    cout << "Family person  : "<< percent2 << "%" << endl;
    
    //friendAnalysis(chatTree1 , chatTree2 , Friend);
    float percent3 =  makeAnalysis(chatTree1 , chatTree2 , Friend );
    if(percent3 < 1)
    percent3 = 0;
    cout << "Friend : "<< percent3 << "%" << endl;
    
    
   // teacherAnalysis(chatTree1 , chatTree2 , Teacher);
   float percent4 =  makeAnalysis(chatTree1 , chatTree2 , Teacher );
    if(percent4 < 1)
    percent4 = 0;
    cout << "Teacher : "<< percent4 << "%" << endl;


    friendFile.close();
    homeFile.close();
    studentFile.close();
    teacherFile.close();

    
}
	else if(choice=="4")
	{
		exit(0);
	}
	else
	{
		cout<<"You have entered a wrong choice. Please enter again."<<endl;	
		goto again;
	}

	
	//Pause();
	
	
	cout<<"press any key to continue";
    cin.get();
    cin.get();

//	clearScreen();
	goto menu;
	
	
	
	
    
    
	

    
//    dateTree->traverseInOrder();

//	chatTree1->traverseInOrder();
	
	return 0;
}
