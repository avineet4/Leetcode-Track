constexpr int UNSEEN = 100001;
constexpr int DUPLICATE = 100002;

array<int, 26> indices;
auto x = [](){ indices.fill(UNSEEN); return 0; }();

class Solution {
public:
    int firstUniqChar(const string& s) {
        int n = s.size();
        for (int i = 0; i < n; i++) {
            int c = s[i] - 'a';
            if (indices[c] == UNSEEN)
                indices[c] = i;
            else
                indices[c] = DUPLICATE;
        }
        int j = UNSEEN;
        for (int& z : indices) {
            if (z < j)
                j = z;
            z = UNSEEN;  // reset for reuse
        }
        return j != UNSEEN ? j : -1;
    }
};
