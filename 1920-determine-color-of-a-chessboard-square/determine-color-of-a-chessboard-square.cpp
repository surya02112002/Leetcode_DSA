class Solution {
public:
    bool squareIsWhite(string coordinates) {
        if (((coordinates[0] == 'a' || coordinates[0] == 'c' ||
              coordinates[0] == 'e' || coordinates[0] == 'g') &&
             !(((int)coordinates[1]) & 1)) ||
            ((coordinates[0] == 'b' || coordinates[0] == 'd' ||
              coordinates[0] == 'f' || coordinates[0] == 'h') &&
             (((int)coordinates[1]) & 1))) {
            return true;
        }
        return false;
    }
};