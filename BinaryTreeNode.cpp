#include<iostream>
#include<stdlib.h>
#include<stack>
#include<vector>

#define null 999

using namespace std;
vector<vector<int>> TreeTraverseResults;
struct TreeNode
{
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int _value):val(_value),left(NULL),right(NULL)
    {

    }
};
void ConnectTreeNodes(TreeNode* pParent,TreeNode* pLeft,TreeNode* pRight)
{
    if(pParent)
    {
        pParent->left=pLeft;
        pParent->right=pRight;
    }
}
int TreeDepth(TreeNode* root)
{
    if(!root)
        return 0;
    int left=1;
    int right=1;
    left +=TreeDepth(root->left);
    right+=TreeDepth(root->right);

    return left>right?left:right;
}
void TreePreOrderRecur(TreeNode* root)
{
    if(root==NULL)
        return;
    cout<<root->val<<endl;
    TreePreOrderRecur(root->left);
    TreePreOrderRecur(root->right);
}
void TreePreOrderNoRecur(TreeNode* root)
{
    if(root==NULL)
        return;
    TreeNode* P=root;
    stack<TreeNode*> S;
    while(P||!S.empty())
    {
        while(P)
        {
            cout<<P->val<<endl;
            S.push(P);
            P=P->left;
        }
        if(!S.empty())
        {
            P=S.top();
            S.pop();
            P=P->right;
        }
    }
}

bool FindSubOfTree(TreeNode* pRoot1,TreeNode* pRoot2)
{
    if(pRoot1==NULL)
        return false;
    if(pRoot2==NULL)
        return true;
    if(pRoot1->val!=pRoot2->val)
        return false;
    return FindSubOfTree(pRoot1->left,pRoot2->left)&&FindSubOfTree(pRoot1->right,pRoot2->right);
}

bool FindRootOfTree(TreeNode* pRoot1,TreeNode* pRoot2)
{
    bool result=false;
    if(pRoot1!=NULL&&pRoot2!=NULL)
    {
        if(pRoot1->val==pRoot2->val)
            result=FindSubOfTree(pRoot1,pRoot2);
        if(!result)
            result=FindRootOfTree(pRoot1->left,pRoot2);
        if(!result)
            result=FindRootOfTree(pRoot1->right,pRoot2);
    }
    return result;
}
void TreeTraverse(TreeNode* p,vector<int> s)
{
    if(p->left==NULL&&p->right==NULL)
    {
        TreeTraverseResults.push_back(s);
    }
    if(p->left!=NULL)
    {
        vector<int> temp(s.begin(),s.end());
        temp.push_back(p->left->val);
        TreeTraverse(p->left,temp);
    }
    if(p->right!=NULL)
    {
        vector<int> temp(s.begin(),s.end());
        temp.push_back(p->right->val);
        TreeTraverse(p->right,temp);
    }
}
void AllOfSubTree(TreeNode* root)
{
    vector<int> s;
    if(root==NULL)
        return ;
    s.push_back(root->val);
    TreeTraverse(root,s);
}

vector<TreeNode*> CreateFromArrayToTree(vector<int> &arrays)
{
    if(arrays.size()==0)
        return {NULL};
    vector<int> V{0};
    V[0]=arrays[0];
    for(int i=1,j=1;j<arrays.size();i++)
    {
        if(V[(i-1)/2]==null)
            V.push_back(null);
        else
            V.push_back(arrays[j++]);
    }
    vector<TreeNode*> PointerOfTree(V.size(),NULL);
    for(int i=0;i<V.size();i++)
    {
        if(V[i]!=null)
            PointerOfTree[i]=new TreeNode(V[i]);
    }
    for(int i=0;;i++)
    {
        if((2*i+2)<V.size())
            ConnectTreeNodes(PointerOfTree[i],PointerOfTree[2*i+1],PointerOfTree[2*i+2]);
        else if((2*i+1)<V.size())
            ConnectTreeNodes(PointerOfTree[i],PointerOfTree[2*i+1],NULL);
        else
            break;
    }
    return PointerOfTree;
}

int main()
{

    vector<int> V={1,-2,-3,1,3,-2,null,-1};
    vector<TreeNode*> test=CreateFromArrayToTree(V);
    cout<<TreeDepth(test[0])<<endl;
    //cout<<hasPathSum(test[0],3)<<endl;
    return 0;
}
