class Node {
public:
    int data;
    Node* next;

    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {}
};

class Solution {

    unordered_map<int, Node*> adjList;
    int nodes = 0;
    
    void addEdge(int u, int v) {
        if(adjList.find(u) == adjList.end()) {
            adjList[u] = nullptr;
            nodes++;
        }

        Node* newNodeU = new Node(v);
        newNodeU->next = adjList[u];
        adjList[u] = newNodeU;
    }

public:
    int findJudge(int n, vector<vector<int>>& trust) {
        for(const auto& t : trust) {
            addEdge(t[0], t[1]);
        }

        // Count how many people trust each person
        vector<int> trustedBy(n + 1, 0);

        for (const auto& [person, head] : adjList) {
            Node* temp = head;
            while (temp) {
                trustedBy[temp->data]++;
                temp = temp->next;
            }
        }

        // Now check judge condition
        for (int i = 1; i <= n; ++i) {
            if (adjList.find(i) == adjList.end() && trustedBy[i] == n - 1) {
                return i;
            }
        }

        return -1;
    }
};