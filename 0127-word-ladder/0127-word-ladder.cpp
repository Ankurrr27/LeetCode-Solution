 class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        // Create a set of all words in the word list for quick lookup.
        unordered_set<string> wordSet(wordList.begin(), wordList.end());

        // If endWord is not in the word set, no valid transformation exists.
        if (wordSet.find(endWord) == wordSet.end()) {
            return 0;
        }

        // Use a queue to perform BFS (Breadth-First Search).
        queue<string> wordQueue;
        wordQueue.push(beginWord);

        // Distance from the beginWord (initially 1 since beginWord is counted).
        int distance = 1;

        while (!wordQueue.empty()) {
            int levelSize = wordQueue.size();

            for (int i = 0; i < levelSize; ++i) {
                string currentWord = wordQueue.front();
                wordQueue.pop();

                // If the current word is the endWord, return the distance.
                if (currentWord == endWord) {
                    return distance;
                }

                // Try changing each character in the current word.
                for (int j = 0; j < currentWord.length(); ++j) {
                    char originalChar = currentWord[j];

                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == originalChar) continue; // Skip same character

                        currentWord[j] = c;
                        // If the new word is in the word set, add it to the queue.
                        if (wordSet.find(currentWord) != wordSet.end()) {
                            wordQueue.push(currentWord);
                            wordSet.erase(currentWord); // Remove to prevent revisiting
                        }
                    }

                    // Restore the original character.
                    currentWord[j] = originalChar;
                }
            }

            // Increment distance after processing the current level.
            distance++;
        }

        // If no transformation sequence leads to the endWord, return 0.
        return 0;
    }
};