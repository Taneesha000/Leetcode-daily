class Solution {
public:
    // Method that converts a string into a 'fancy string'.
    // A 'fancy string' is a string where no three consecutive characters are equal.
    string makeFancyString(string s) {
        string result; // Initialize an empty string to store the 'fancy string'.

        // Iterate through each character in the input string.
        for (char& currentChar : s) {
            int currentLength = result.size(); // Get the current length of the 'fancy string'.

            // Check if the last two characters in the 'fancy string' are the same as the current character.
            if (currentLength > 1 && result[currentLength - 1] == currentChar && result[currentLength - 2] == currentChar) {
                // If the last two characters are the same as the current character, skip adding this character.
                continue;
            }

            // Append the current character to the 'fancy string' if no three consecutive characters are the same.
            result.push_back(currentChar);
        }
      
        // Return the 'fancy string'.
        return result;
    }
};