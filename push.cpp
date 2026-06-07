#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    string newfile,comment;
    cout<<"这次你更改了什么?"<<endl;
    cout<<"请输入更改的文件名，以方便推到远程仓库:";
    cin>>newfile;
    cout<<"本次修改的注释:";
    cin>>comment;
    cout<<"当前情况概览:"<<endl;
    cout<<"你更改了文件:"<<newfile<<endl;
    cout<<"你输入的注释是:"<<comment<<endl;
    cout<<"确认提交吗？(y/n):"<<endl;
    char choice;
    cin>>choice;
    if(choice=='y'||choice=='Y'){
        string cmd;
        cmd = string("git add ") + newfile;
        system(cmd.c_str());
        cmd = string("git commit -m \"") + comment + "\"";
        system(cmd.c_str());
        system("git push origin main");
        cout<<"提交成功！"<<endl;
    }else{
        cout<<"提交已取消。"<<endl;
    }
    return 0;
}