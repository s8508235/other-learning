#include "Implement.h"
using namespace std;
string find_subtree(string str);
const char* Implement::getStudentID()const
{
    return "103062210";
}
void Implement::constructTree(TreeNode **proot, string treeStr)const
{
    TreeNode *curr;
    curr = new TreeNode(0);
    if(treeStr.length()==2)
    {
   //     cout<<"zz"<<endl;
        return ;
    }
    else
    {
        string z;
        z.assign(treeStr,1,treeStr.length()-2);
        cout<<z<<endl;
        int cnt= 0;
        int flag=0;
        if(z[0]=='-')
        {
            z = z.substr(1,z.length());
            flag = 1;
        }
      //  cout<<z<<endl;
        for ( string::iterator it=z.begin(); isdigit(*it); ++it)
        {
            curr->weight*=10;
            curr->weight+=*it-'0';
            cnt ++;
        }
        if(flag) curr->weight=(-1)*curr->weight;
     //   cout<<"flag w:"<<flag<<curr->weight<<endl;
        string w;
        w.assign(z,cnt,z.length()-cnt);
       // cout<<curr->weight<<endl;
        //root
        string n = find_subtree(w);
        constructTree(&curr->left,n);//給左邊
        int zz = n.length();
       //cout<<"sub:"<<w.substr(zz,w.length()-zz)<<endl;
        constructTree(&curr->right,w.substr(zz,w.length()-zz));//給右邊剩下的
    }
    *proot = curr;
}
string find_subtree(string str)
{
    int i = 1;
    int x  = 0;
    while(i)
    {
        x++;
        if(str[x]==')')i--;
        else if (str[x]=='(')i++;
        else{}
    }
    string z;
    z.append(str,0,x+1);
    return z;
}
void Implement::deleteTree(TreeNode **proot)const
{
    delete proot;
}
int Implement::treeHeight(const TreeNode *root)const
{
    if(root)
    {
        int lh,rh;
        lh = treeHeight(root->left) ;
        rh = treeHeight(root->right);
            return std::max(lh,rh)+1;
      //  cout<<root->weight<<" "<<lh<<" "<<rh<<endl;
    }
    return -1;
}
int Implement::treeWeight(const TreeNode *root)const
{
    int lw = 0,rw = 0;
    if(root)
    {
        lw += treeWeight(root->left) ;
        rw += treeWeight(root->right);
        return lw+rw+root->weight;
    }
    return 0;
}
int Implement::leafNum(const TreeNode *root)const
{
    int lln = 0,rln=0;
    if(root)
    {
        if(root->left==NULL && root->right==NULL&&root!=NULL)
        {
            return 1;
        }
        lln = leafNum(root->left) ;
        rln = leafNum(root->right);
        return lln + rln;
    }
    else if(root==NULL)
    {
        return 0;
    }

}
int Implement::maxPathWeight(const TreeNode *root)const
{
    int curr_sum = 0,lmpw=0,rmpw=0;
    if(root==NULL)
    {
        return 0;
    }
    if(root)
    {
        curr_sum+=root->weight;
        lmpw += maxPathWeight(root->left) ;
        rmpw += maxPathWeight(root->right);
    }
    return curr_sum+std::max(lmpw,rmpw);
}
