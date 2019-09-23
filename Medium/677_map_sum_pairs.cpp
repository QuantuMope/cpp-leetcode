/**
 * Algorithm would probably be more efficient using
 * a trie data structure but performance seemed
 * satisfactory with a brute force method.
 *
 * Time Complexity: O(N*P) where N is total entries and
 *                         P is length of the prefix for
 *                         the sum operation
 *
 *                  O(1) for insert
 *
 * Runtime: 4 ms, Faster than 76.29%
 * Memory: 9.3 MB, Less than 100.00%
 */

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
class MapSum {
public:
    /** Initialize your data structure here. */
    unordered_map<string, int> hash_table;
    MapSum() {}

    void insert(string key, int val) {
        hash_table[key] = val;
    }

    int sum(string prefix) {
        int sum {0};
        for (auto &entry : hash_table) {
            if (entry.first.substr(0, prefix.size()) == prefix) sum += entry.second;
        }
        return sum;
    }
};

