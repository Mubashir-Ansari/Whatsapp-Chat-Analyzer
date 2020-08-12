#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<iostream>
#include<string>
#include<QMessageBox>
#include<QFile>
#include<QTextStream>
#include<stack>
#include<QDebug>
#include<QStringList>
#include <bits/stdc++.h>
#include <iostream>
#include <sstream>  // for string streams
#include <string>  // for string
#include <float.h>
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
    int freqSum();
    TreeNode<T> * findMaxFreq();// gives sum of frequencies of all elements in a tree
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
TreeNode<T> * Tree<T>::findMaxFreq()
{


    TreeNode<T> *maxNode= NULL;
    int max=0;
    TreeNode<T> *temp = root;
    queue<TreeNode<T> *> q;

    q.push(temp);

    while (!q.empty() && temp != NULL)
    {
        temp = q.front();
        q.pop();

    {
        if(temp->frequency>max)
        {
            max=temp->frequency;
            maxNode = temp;
         }
     }
        if(temp->leftNode != NULL)
            q.push(temp->leftNode);

        if(temp->rightNode != NULL)
        q.push(temp->rightNode);

    }

    return maxNode;

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


string traverse;
template<class T>
void TreeNode<T>::traverseInOrder()
    {
        if(leftNode != NULL)
        leftNode->traverseInOrder();

        traverse = traverse + "Date: " + data + "  " +
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
//cout<<"Hello frm analysis"<<percent;
return percent;


}
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("H:/MUBASHIR/4sem/DS project/Qr.png");
    ui->label_pic->setPixmap(pix);

    QPixmap pix2("H:/MUBASHIR/4sem/DS project/WP.jpg");
    ui->label_pic2->setPixmap(pix2);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    string coutt;
    Tree<string> *chatTree1 , *chatTree2 , *dataTree;
        chatTree1 = new Tree<string>();
        chatTree2 = new Tree<string>();
        dataTree = new Tree<string>();
        ifstream file("H:/MUBASHIR/4sem/DS project/chat2.txt");
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

            if( (element.length() == 9 || element.length() == 8 || element.length() == 7||element.length()==11) && (element[1] == '/' || element[2] == '/' ) && (element[4] == '/' || element[5] == '/' || element[3] == '/'))
            {
                string date = element;
                for(int i = 0 ; i < 2 ; i++) file>>element;
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
    // cout<<element<<" ";
            }
    else
    {

              //  cout<<element<<endl;
    chatTree2->insert(element , user2);
    }
            }
        }



    TreeNode<string> *temp;
//    cout<<"Messages for each date:"<<endl;
//    dataTree->traverseInOrder();
    stack<TreeNode<string> *> s;
        TreeNode<string> *curr = dataTree->root;
        QString qstr;
        while (curr != NULL || s.empty() == false)
        {

            while (curr !=  NULL)
            {

                s.push(curr);
                curr = curr->leftNode;
            }
            curr = s.top();
                    s.pop();
                    stringstream ss;
                      ss<<curr->frequency;;
                      string s;
                      ss>>s;
                    coutt = coutt + "Date: " + curr->data + " Frequency: "+s +"\n";
//                    cout << "Date: "<<curr->data << " Frequency:"<<curr->frequency<<endl;
                    qstr = QString::fromStdString(coutt);


                    curr = curr->rightNode;

                }

            QMessageBox::information(0, "Statistics By Date", qstr);
}
void MainWindow::on_pushButton_2_clicked()
{
    Tree<string> *chatTree1 , *chatTree2 , *dataTree;
    chatTree1 = new Tree<string>();
    chatTree2 = new Tree<string>();
    dataTree = new Tree<string>();
    ifstream file("H:/MUBASHIR/4sem/DS project/chat2.txt");
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

        if( (element.length() == 9 || element.length() == 8 || element.length() == 7||element.length()==11) && (element[1] == '/' || element[2] == '/' ) && (element[4] == '/' || element[5] == '/' || element[3] == '/'))
        {
            string date = element;
            for(int i = 0 ; i < 2 ; i++) file>>element;
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

        }
else
{

chatTree2->insert(element , user2);
}
        }
    }
    string coutt;
    stringstream ss,ss2,ss3,ss4;
      ss<<chatTree1->freqSum();
      ss2<<chatTree2->freqSum();
      ss3<<chatTree1->getCount();
      ss4<<chatTree2->getCount();
      string s,s2,s3,s4;
      ss>>s;
      ss2>>s2;
      ss3>>s3;
      ss4>>s4;
    coutt = coutt + "Word statistics for: "+chatTree1->root->user +" \n" + "Total Words Typed:"+s +"\n"+"Unique words:"+s3+"\n\n\n";
    coutt = coutt + "Word statistics for: "+chatTree2->root->user+":"+"\n"+"Total Words Typed:"+s2+"\n"+"Unique words:"+s4+"\n\n";

    QString qstr = QString::fromStdString(coutt);
    QMessageBox::information(0, "Word Statistics", qstr);

}

void MainWindow::on_pushButton_3_clicked()
{
    Tree<string> *chatTree1 , *chatTree2 , *dataTree;
    chatTree1 = new Tree<string>();
    chatTree2 = new Tree<string>();
    dataTree = new Tree<string>();
    ifstream file("H:/MUBASHIR/4sem/DS project/chat2.txt");
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

        if( (element.length() == 9 || element.length() == 8 || element.length() == 7||element.length()==11) && (element[1] == '/' || element[2] == '/' ) && (element[4] == '/' || element[5] == '/' || element[3] == '/'))
        {
            string date = element;
            for(int i = 0 ; i < 2 ; i++) file>>element;
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
// cout<<element<<" ";
        }
else
{

          //  cout<<element<<endl;
chatTree2->insert(element , user2);
}
        }
    }


    ifstream friendFile;
        friendFile.open("H:/MUBASHIR/4sem/DS project/friendsWords.txt");
        ifstream homeFile("H:/MUBASHIR/4sem/DS project/homeWords.txt");
        ifstream studentFile("H:/MUBASHIR/4sem/DS project/studentWords.txt");
        ifstream teacherFile("H:/MUBASHIR/4sem/DS project/teacherWords.txt");

//        homeFile.open("new_file_write.txt",ios::in);
        if(!homeFile)
        cout<<"No such file";

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
//        cout << "Student : "<< percent1 << "%" << endl;


       // homeAnalysis(chatTree1 , chatTree2 , Home);
       float percent2 =  makeAnalysis(chatTree1 , chatTree2 , Home );
        if(percent2 < 1)
        percent2 = 0;
//        cout << "Family person  : "<< percent2 << "%" << endl;

        //friendAnalysis(chatTree1 , chatTree2 , Friend);
        float percent3 =  makeAnalysis(chatTree1 , chatTree2 , Friend );
        if(percent3 < 1)
        percent3 = 0;
//        cout << "Friend : "<< percent3 << "%" << endl;


       // teacherAnalysis(chatTree1 , chatTree2 , Teacher);
       float percent4 =  makeAnalysis(chatTree1 , chatTree2 , Teacher );
        if(percent4 < 1)
        percent4 = 0;
//        cout << "Teacher : "<< percent4 << "%" << endl;

        std::ostringstream ss, ss2,ss3 ,ss4;
        ss << percent1;
        ss2<<percent2;
        ss3<<percent3;
        ss4<<percent4;
        std::string s(ss.str());
        std::string s2(ss2.str());
        std::string s3(ss3.str());
        std::string s4(ss4.str());
        string cout1,cout2, cout3,cout4;
        cout1=cout1+"Student : "+s+"%"+"\n";
         cout2=cout2+"Family person  : "+s2+"%"+"\n";
         cout3=cout3+"Friend : "+s3+"%"+"\n";
         cout4=cout4+"Teacher : "+s4+"%"+"\n";
        cout1 = cout1+cout2+cout3+cout4;
        QString qstr = QString::fromStdString(cout1);
        QMessageBox::information(0, "Topic Prediction", qstr);
        friendFile.close();
        homeFile.close();
        studentFile.close();
        teacherFile.close();

}

void MainWindow::on_pushButton_4_clicked()
{

    Tree<string> *chatTree1 , *chatTree2 , *dataTree;
    chatTree1 = new Tree<string>();
    chatTree2 = new Tree<string>();
    dataTree = new Tree<string>();
    ifstream file("H:/MUBASHIR/4sem/DS project/chat2.txt");
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

        if( (element.length() == 9 || element.length() == 8 || element.length() == 7||element.length()==11) && (element[1] == '/' || element[2] == '/' ) && (element[4] == '/' || element[5] == '/' || element[3] == '/'))
        {
            string date = element;
            for(int i = 0 ; i < 2 ; i++) file>>element;
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
// cout<<element<<" ";
        }
else
{

          //  cout<<element<<endl;
chatTree2->insert(element , user2);
}
        }
    }

    TreeNode<string> *temp = chatTree1->findMaxFreq();
    string coutt;
stringstream ss,ss2;
    ss<<temp->frequency;
//     ss2<<temp->frequency;
    string s,s2;
    ss>>s;
//    ss2>>s2;
    if(temp!=NULL){
    coutt = coutt + "Word Used Word for: "+chatTree1->root->user +" \n" + "Word: "+temp->data +" \n" + "Frequency: "+s +"\n\n\n";
  // cout<<"Most used word for "<<chatTree1->root->user<<": "<<temp->data<<endl<<"Frequency: "<<temp->frequency<<"."<<endl<<endl;
}
temp = chatTree2->findMaxFreq();
ss2<<temp->frequency;
ss2>>s2;
if(temp!=NULL){
    coutt = coutt + "Word Used Word for: "+chatTree2->root->user +" \n" + "Word: "+temp->data +" \n" + "Frequency: "+s2 +"\n\n\n";
    //cout<<"Most used word for "<<chatTree2->root->user<<": "<<temp->data<<endl<<"Frequency: "<<temp->frequency<<"."<<endl<<endl;
}
QString qstr = QString::fromStdString(coutt);
QMessageBox::information(0, "Most Used Word", qstr);

}
