/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

    unordered_map<Node*,Node*>mp; 

    void DFS(Node* node,Node* clone_node)
    {
        for(Node* n:node->neighbors)    // traversing the neighbours of th enode given
        {
            if(mp.find(n)==mp.end())  //if that node does not exist in the map , that means not cloned yet
            {
                Node* clone=new Node(n->val);    // then create the node
                mp[n]=clone;  // after creation updating that in the map
                clone_node->neighbors.push_back(clone);
                DFS(n,clone);
            }
            else  // if already cloned , then we will find the cloned node from the map
            {
                clone_node->neighbors.push_back(mp[n]);                
            }
        }
    }

    Node* cloneGraph(Node* node) {
        if(node==NULL)
        return NULL;

        //clone of the given node
        Node* clone_node=new Node(node->val);

        //now clone ots neighbours recursively , but if node reppars then we need to check or acess that node so we will store them in the hashmap

        mp[node]=clone_node; // oldNode : newNode

        DFS(node,clone_node);

        return clone_node;



    }
};