class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        vector<int> freqSecret(10, 0);
        vector<int> freqGuess(10, 0);

        // Count bulls and store non-bull digits
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
            } else {
                freqSecret[secret[i] - '0']++;
                freqGuess[guess[i] - '0']++;
            }
        }

        // Count cows
        for (int digit = 0; digit <= 9; digit++) {
            cows += min(freqSecret[digit], freqGuess[digit]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};