/**
 *
 * Time Complexity: O(K) where K is number of keys
 *
 * Runtime: 12 ms, Faster than 66.25%
 * Memory: 10.8 MB, Less than 60.00%
 */

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {

        int num_rooms {(int) rooms.size()};
        int current_room {0};
        stack<int> keys;
        set<int> already_explored;
        bool exploring {true};

        while (exploring) {
            already_explored.insert(current_room);
            for (auto key : rooms[current_room]) {
                // Ignore keys for rooms already explored.
                if (already_explored.count(key)) continue;
                keys.push(key);
            }

            // Endcases: Either ran out of keys or explored all rooms.
            if (keys.empty() && already_explored.size() != num_rooms) return false;
            if (already_explored.size() == num_rooms) break;

            current_room = keys.top();
            keys.pop();
        }
        return true;
    }
};