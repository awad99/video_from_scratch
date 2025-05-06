#pragma once
#include <string>
#include <vector>
#include <sstream>

namespace Strings {
    // Returns the introduction string
    inline std::string introduction() {
        return "i know";
    }

    inline std::string introduction2(float elapsedTime, int maxWidthPixels = 600, int charWidth = 10) {
        std::string fullText = "What is i make this vidoe from program you mean write code and show this vidoe? yes literally i write the code to make this video";

        std::istringstream stream(fullText);
        std::string word;
        std::vector<std::string> words;

        while (stream >> word) {
            words.push_back(word);
        }

        int wordCount = static_cast<int>(elapsedTime * 5); // Show 5 words per second
        if (wordCount > words.size()) return ""; // Remove all words when done

        std::string output;
        int currentLineLength = 0;

        for (int i = 0; i < wordCount; ++i) {
            int wordPixelLength = words[i].length() * charWidth;
            if (currentLineLength + wordPixelLength > maxWidthPixels) {
                output += "\n";
                currentLineLength = 0;
            }
            output += words[i] + " ";
            currentLineLength += wordPixelLength + charWidth; // account for space
        }

        return output;
    }

    inline std::string introduction3(float elapsedTime, int maxWidthPixels = 600, int charWidth = 10) {
        static const std::string fullText3 =
            "for this be the video more short and not good editer without more introduction let's start";

        std::istringstream stream(fullText3);
        std::vector<std::string> words;
        std::string word;
        while (stream >> word) {
            words.push_back(word);
        }

        int wordCount = static_cast<int>(elapsedTime * 3); // 5 words per second
        if (wordCount > (int)words.size()) return "";

        std::string output;
        int currentLineLength = 0;
        for (int i = 0; i < wordCount; ++i) {
            int wLen = words[i].length() * charWidth;
            if (currentLineLength + wLen > maxWidthPixels) {
                output += "\n";
                currentLineLength = 0;
            }
            output += words[i] + " ";
            currentLineLength += wLen + charWidth;
        }
        return output;
    }

    inline std::string startdev(float elapsedTime, int maxWidthPixels = 600, int charWidth = 10)
    {
        static const std::string Text = "in start i need system grafical   program like adobe use grafical API like openGL for make grafical and effict then i use it";

        std::istringstream stream(Text);
        std::vector<std::string> words;
        std::string word;
        while (stream >> word) {
            words.push_back(word);
        }

        int wordCount = static_cast<int>(elapsedTime * 3); // 5 words per second
        if (wordCount > (int)words.size()) return "";

        std::string output;
        int currentLineLength = 0;
        for (int i = 0; i < wordCount; ++i) {
            int wLen = words[i].length() * charWidth;
            if (currentLineLength + wLen > maxWidthPixels) {
                output += "\n";
                currentLineLength = 0;
            }
            output += words[i] + " ";
            currentLineLength += wLen + charWidth;
        }
        return output;
    }

    inline std::string videodev(float elapsedTime, int maxWidthPixels = 600, int charWidth = 10)
    {
        static const std::string Text =
            "Before starting, we need to prepare the video. First, I had no script. "
            "I wrote the video from scratch, so I needed lines. But the Arabic text looked ugly, "
            "so I made the script in English instead. "
            "Second, I needed images — this was easy since Raylib supports image loading. "
            "Third, I needed a short video — this was the hard part. "
            "The library is made for game development and doesn't support video playback...";

        std::istringstream stream(Text);
        std::vector<std::string> words;
        std::string word;
        while (stream >> word) {
            words.push_back(word);
        }

        int wordCount = static_cast<int>(elapsedTime * 3); // 5 words per second
        if (wordCount > (int)words.size()) return "";

        std::string output;
        int currentLineLength = 0;
        for (int i = 0; i < wordCount; ++i) {
            int wLen = words[i].length() * charWidth;
            if (currentLineLength + wLen > maxWidthPixels) {
                output += "\n";
                currentLineLength = 0;
            }
            output += words[i] + " ";
            currentLineLength += wLen + charWidth;
        }
        return output;
    }

};