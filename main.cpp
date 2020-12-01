#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
 
 
 
struct Tree
{
    int x;
    int count = 1;
    Tree* l, * r;
};
 
void add_node(int x, Tree*& MyTree)
{
    if (MyTree == NULL)
    {
        MyTree = new Tree;
        MyTree->x = x;
        MyTree->l = MyTree->r = NULL;
    }
 
    else if (x < MyTree->x)
    {
        if (MyTree->l != NULL) add_node(x, MyTree->l);
        else
        {
            MyTree->l = new Tree;
            MyTree->l->l = MyTree->l->r = NULL;
            MyTree->l->x = x;
        }
    }
 
    else if (x > MyTree->x)
    {
        if (MyTree->r != NULL) add_node(x, MyTree->r);
        else
        {
            MyTree->r = new Tree;
            MyTree->r->l = MyTree->r->r = NULL;
            MyTree->r->x = x;
        }
    }
    else if (x == MyTree->x) {
        MyTree->count++;
    }
}
int countHomeForm(int x, Tree*& tree) {
    if (tree == NULL) {
        return 0;
    }
    else if (x == tree->x) {
        return tree->count;
    }
    else if (x > tree->x) {
        countHomeForm(x, tree->r);
    }
    else {
        countHomeForm(x, tree->l);
    }
}
int main() {
    int n;
    std::cin>>n;
    int x, y;
    Tree* tree = NULL;
    std::vector<std::pair<int, int>> form(n);
    for (int i = 0; i < n; i++) {
        std::cin>>x;
        std::cin>>y;
        form[i] = std::pair<int, int>(x,y);
        add_node(x, tree);
    }
    for (int i = 0; i < n; i++) {
        int home = (n - 1) + countHomeForm(form[i].second, tree);
        std::cout << home << ' ';
        std::cout << 2 * (n - 1) - home << '\n';
    }
 
    return 0;
}
