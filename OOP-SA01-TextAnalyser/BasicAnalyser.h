#pragma once

#include <vector>
#include <map>
#include <string>

/// <summary>
/// Basic analyser abstract class requiring implementation in Analyser.hpp .
/// </summary>
class BasicAnalyser
{
public:

    // Helper method

	/// <summary>
	/// A basic function with a simple methodoloy aproximating the number of syllables in a word using vowel and vowel pair
    /// counting
	/// </summary>
	/// <param name="word">A single word</param>
	/// <returns>the number of vowels in the word</returns>
	int virtual countSyllables(const std::string& word);

    // 3rd Methods

    /// <summary>
    /// Return the total number of sentences from the last text analysed by analyseWordsAndLettersInSourceText
    /// </summary>
    /// <returns>total number of sentences</returns>
    std::size_t virtual getTotalSentences() = 0;

    /// <summary>
    /// Return the total number of words from the last text analysed by analyseWordsAndLettersInSourceText
    /// </summary>
    /// <returns>Total number of words</returns>
    long virtual getTotalWords() = 0;

    /// <summary>
    /// Return the total number of syllables from the last text analysed by analyseWordsAndLettersInSourceText
    /// </summary>
    /// <returns>Total number of syllables</returns>
    long virtual getTotalSyllables() = 0;

    /// <summary>
    /// Return the total number of complex words (words with 3 or more syllables) from the last text analysed 
    /// by analyseWordsAndLettersInSourceText
    /// </summary>
    /// <returns>Total number of complex words</returns>
    long virtual getTotalComplexWords() = 0;

    /// <summary>
    /// Return the total number of letters from the last text analysed by analyseWordsAndLettersInSourceText
    /// </summary>
    /// <returns>Total number of letters</returns>
    std::size_t virtual getTotalLetters() = 0;

    /// <summary>
    /// Analyses the words and letters in source text and internally stores the following values for access by the associated getters
    /// totalSentences, totalWords, totalSyllables, totalComplexWords (words with 3 or more syllables), totalLetters
    /// </summary>
    /// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
    void virtual analyseWordsAndLettersInSourceText(const std::vector<std::string>& sentences) = 0;
  
    /// <summary>
    /// Calculates the average number of words per sentence in source text based on data 
    /// stored in the class by analyseWordsAndLettersInSourceText
    /// e.g. 5 sentences with 2, 3, 5, 5, 5 would return 4 as the average
    /// </summary>
    /// <returns>Average number of words per sentence</returns>
    double virtual averageWordsPerSentence() = 0;

    /// <summary>
    /// Calculates the average number of letters in the words in source text based on data 
    /// stored in the class by analyseWordsAndLettersInSourceText
    /// </summary>
    /// <returns>Average number of letters per word</returns>
    double virtual averageLettersPerWord() = 0;

    /// <summary>
    /// Calculates the average number of syllables in the words in source text based on data 
    /// stored in the class by analyseWordsAndLettersInSourceText
    /// </summary>
    /// <returns>Average number of syllables per words</returns>
    double virtual averageSyllablesPerWord() = 0;

    // 2.2 Methods

	/// <summary>
	/// Flesch Reading Ease Score: Measures the readability of a text based on sentence length and word length, 
	/// you can calculate the Flesch Reading Ease Score by counting the number of sentences and words in a given text and applying the formula:
	/// Flesch Reading Ease Score = 206.835 - (1.015 * (total_words / total_sentences)) - (84.6 * (total_syllables / total_words))
	/// </summary>
	/// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
	/// <returns>Flesch Reading Ease Score</returns>
	double virtual calculateFleschReadingEaseScore(const std::vector<std::string>& sentences) = 0;

    /// <summary>
    /// Flesch-Kincaid Grade Level: Estimates the U.S. grade level required to understand the text, 
    /// you can calculate the Flesch-Kincaid Grade Level by using the formula:
    /// Flesch-Kincaid Grade Level = (0.39 * (total_words / total_sentences)) + (11.8 * (total_syllables / total_words)) - 15.59
    /// </summary>
    /// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
    /// <returns>Flesch-Kincaid Grade Level</returns>
    double virtual calculateFleschKincaidGradeLevel(const std::vector<std::string>& sentences) = 0;

    // 2.1 Methods

    /// <summary>
    /// Gunning Fog Index: Measures the years of formal education needed to understand the text. 
    /// In C++, you can calculate the Gunning Fog Index by counting the number of words, sentences, and complex words 
    /// (words with three or more syllables) in a given text and applying the formula:
    /// Gunning Fog Index = 0.4 * ((total_words / total_sentences) + (100 * (total_complex_words / total_words)))
    /// </summary>
    /// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
    /// <returns>Gunning Fog Index</returns>
    double virtual calculateGunningFogIndex(const std::vector<std::string>& sentences) = 0;

    /// <summary>
    /// Coleman-Liau Index: Evaluates the text's grade level using characters per word and words per sentence, 
    /// you can calculate the Coleman-Liau Index by counting the number of letters, words, and sentences 
    /// in a given text and applying the formula:
    /// Coleman-Liau Index = (0.0588 * (total_letters / total_words * 100)) - (0.296 * (total_sentences / total_words * 100)) - 15.8
    /// </summary>
    /// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
    /// <returns>Coleman-Liau Index</returns>
    double virtual calculateColemanLiauIndex(const std::vector<std::string>& sentences) = 0;  

    // 1st Method

    /// <summary>
    /// Analyses the length of each of the words in source text and returns a map with the word lengths as the key 
    /// and the count of the number of words in the text of each specific length
    /// e.g. "The cat sat on the mat example text"
    /// would return a map
    /// 2, 1
    /// 3, 5
    /// 4, 1
    /// 7, 1
    /// Throws std::invalid_argument if the vector is empty.
    /// </summary>
    /// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
    /// <returns>std::map<std::size_t, std::size_t> with the word lengths as the key and the count of the number 
    /// of words in the text of each specific length</returns>
    std::map<std::size_t, std::size_t> virtual analyseWordLengthFrequencyInSourceText(const std::vector<std::string>& sentences) = 0;

};

// Helper Method

int BasicAnalyser::countSyllables(const std::string& word) {
    int count = 0;
    bool isPrevVowel = false;

    for (char c : word) {
        c = std::tolower(c);

        if (std::isalpha(c)) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
                if (!isPrevVowel) {
                    count++;
                    isPrevVowel = true;
                }
            }
            else {
                isPrevVowel = false;
            }
        }
    }

    if (count == 0) {
        count = 1; // At least one syllable in a word
    }

    return count;
}

