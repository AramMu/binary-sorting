#include <iostream>
#include <algorithm>
#include "timemeasure.h"
#include "randomgenerator.h"

using namespace std;


/*
struct Node {
    Node() : ch{nullptr, nullptr} {}
    //int cnt;
    vector<int> ind;
    Node* ch[2];

    ~Node() {
        if (ch[0]) {
            delete ch[0];
            ch[0] = nullptr;
        }
        if (ch[1]) {
            delete ch[1];
            ch[1] = nullptr;
        }
    }
};
*/

struct Node {
    Node() : ch{-1, -1}, cnt(0) {}
    int ch[2];
    //vector<int> ind;
    int cnt;
};

struct Tree {
    Tree () {// : nodes{Node()} {
        nodes.resize(1);
        nodes.reserve(40000000);
        //nodes.resize(40000000);
        //sz = 1;
    }
    vector<Node> nodes;
    //int sz;
};

/*
void inorder(Node* cur, const vector<unsigned int>& vec, vector<unsigned int>& res) {
    for (int i = 0; i < cur->ind.size(); ++i) {
        res.push_back(vec[cur->ind[i]]);
    }
    if (cur->ch[0]) {
        inorder(cur->ch[0], vec, res);
    }
    if (cur->ch[1]) {
        inorder(cur->ch[1], vec, res);
    }
}
*/

int pow2(int x) {
    if (x==0) return 1;
    if (x==1) return 2;
    int r = pow2(x/2);
    return r*r*(x%2+1);
    /*
    int r=1;
    for (int i = 0; i < x; ++i)
        r *= 2;
    return r;
    */
}

vector<unsigned int> binarySort(const vector<unsigned int>& vec) {
    Tree t;
    int n = vec.size();
    //const unsigned int* vec = vecA.data();
    for (int i = 0; i < n; ++i) {
        int cur = 0;
        for (int j = 31; j >= 0; --j) {
            int bit = (vec[i]>>j) & 1;
            /*
            Node* tmp = &(t.nodes[cur]);
            if (tmp->ch[bit] < 0) {
                tmp->ch[bit] = t.sz;
                t.sz++;
            }
            cur = tmp->ch[bit];
            */

            if (t.nodes[cur].ch[bit] < 0) {
                t.nodes[cur].ch[bit] = t.nodes.size();
//                t.nodes[cur].ch[bit] = t.sz;
                t.nodes.emplace_back();
//                t.sz++;
            }
            cur = t.nodes[cur].ch[bit];
        }
        t.nodes[cur].cnt++;
    }
    vector<unsigned int> res;
    /*
    vector<Node*> st;
    st.push_back(root);
    while (!st.empty()) {
        Node* t = st.back();
    }
    */

    //inorder(root, vec, res);
    //delete root;
    cout << "Nodes final count " << t.nodes.size() << endl;
    //cout << "Nodes final count " << t.sz << endl;
    return res;
}

int main() {
    //vector<unsigned int> vec = {54, 36, 114, 12, 9};
    const int SIZE(3000000);
    vector<unsigned int> vec(SIZE);
    for (int i = 0; i < SIZE; ++i) {
        //vec[i] = RandomGenerator::randInt(0, 1000);
        vec[i] = RandomGenerator::randInt(INT_MIN/2, INT_MAX/2);
//        cout << vec[i] << endl;
//        vec[i] = int(rand())*rand()%10000;
    }
    cout << "Ready" << endl;
    TimeMeasure bs;
    bs.start();
    vector<unsigned int> res = binarySort(vec);
    bs.finish();
    cout << "Binary " << bs.getDif() << endl;

    TimeMeasure ss;
    ss.start();
    sort(vec.begin(), vec.end());
    ss.finish();
    cout << "Standard " << ss.getDif() << endl;
//    for (int i = 0; i < res.size(); ++i) {
//        cout << res[i] << " ";
//    }
    return 0;
}
