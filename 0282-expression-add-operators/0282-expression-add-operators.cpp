class Solution {
public:

    void f(vector<string>& ans, string& num, string expr,
           int pos, long long value, long long last, int target) {

        if (pos == num.size()) {
            if (value == target)
                ans.push_back(expr);
            return;
        }

        long long number = 0;

        for (int i = pos; i < num.size(); i++) {

            // Don't allow 05, 005, etc.
            if (i > pos && num[pos] == '0')
                break;

            number = number * 10 + (num[i] - '0');

            string cur = num.substr(pos, i - pos + 1);

            // First number
            if (pos == 0) {
                f(ans, num, cur, i + 1,
                  number, number, target);
            }
            else {

                // +
                f(ans, num, expr + "+" + cur, i + 1,
                  value + number, number, target);

                // -
                f(ans, num, expr + "-" + cur, i + 1,
                  value - number, -number, target);

                // *
                f(ans, num, expr + "*" + cur, i + 1,
                  value - last + last * number,
                  last * number, target);
            }
        }
    }

    vector<string> addOperators(string num, int target) {
        vector<string> ans;

        f(ans, num, "", 0, 0, 0, target);

        return ans;
    }
};