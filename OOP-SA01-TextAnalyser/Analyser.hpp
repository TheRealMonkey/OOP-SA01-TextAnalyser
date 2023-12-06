#include "BasicAnalyser.h";
#include <iostream>;

class Analyser :public BasicAnalyser {
private:
	std::vector<std::string> words;
	std::vector<std::vector<std::string>> wordsInSentences;
	int totalSentences;
	int numberOfLetters;


public:


	int countSyllables(const std::string& word);

	std::size_t getTotalSentences();

	long getTotalWords();

	long getTotalSyllables();

	long getTotalComplexWords();

	std::size_t getTotalLetters();

	void analyseWordsAndLettersInSourceText(const std::vector<std::string>& sentences);

	double averageWordsPerSentence();

	double averageLettersPerWord();

	double averageSyllablesPerWord();

	double calculateFleschReadingEaseScore(const std::vector<std::string>& sentences);

	double calculateFleschKincaidGradeLevel(const std::vector<std::string>& sentences);

	double calculateGunningFogIndex(const std::vector<std::string>& sentences);

	double calculateColemanLiauIndex(const std::vector<std::string>& sentences);

	std::map<std::size_t, std::size_t> analyseWordLengthFrequencyInSourceText(const std::vector<std::string>& sentences);

};



// 3rd Methods

/// <summary>
/// Return the total number of sentences from the last text analysed by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>total number of sentences</returns>
std::size_t Analyser::getTotalSentences() { return this->totalSentences; }

/// <summary>
/// Return the total number of words from the last text analysed by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Total number of words</returns>
long Analyser::getTotalWords() {
	return this->words.size();
}

/// <summary>
/// Return the total number of syllables from the last text analysed by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Total number of syllables</returns>
long Analyser::getTotalSyllables() {

	long numberOfSyllables = 0;
	for (std::string word : this->words) {
		numberOfSyllables += BasicAnalyser::countSyllables(word);
	}

	return numberOfSyllables;
}

/// <summary>
/// Return the total number of complex words (words with 3 or more syllables) from the last text analysed 
/// by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Total number of complex words</returns>
long Analyser::getTotalComplexWords() {

	long numbrOfComplexSyllables = 0;
	long numberOfSyllables = 0;
	for (std::string word : this->words) {

		numberOfSyllables = BasicAnalyser::countSyllables(word);

		if (numberOfSyllables >= 3) {
			numbrOfComplexSyllables++;
		}
	}
	return numbrOfComplexSyllables;
}

/// <summary>
/// Return the total number of letters from the last text analysed by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Total number of letters</returns>
std::size_t Analyser::getTotalLetters() { return this->numberOfLetters; }

/// <summary>
/// Analyses the words and letters in source text and internally stores the following values for access by the associated getters
/// totalSentences, totalWords, totalSyllables, totalComplexWords (words with 3 or more syllables), totalLetters
/// </summary>
/// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
void Analyser::analyseWordsAndLettersInSourceText(const std::vector<std::string>& sentences) {


	//the number of words will be counted by counting the number of spaces in the sentence.
	std::string word;

	//the number of letters in the vector.
	int numberOfLetters;
	
	std::vector<std::string> wordsInSentence;


	for (std::string sentence : sentences) {
		for (char letter : sentence) {
			//char 32 == space
			if (letter == char(32)) {
				this->words.push_back(word);
				wordsInSentence.push_back(word);
				word = "";
			}
			else {
				this->numberOfLetters++;
				word += letter;
			}
		}
		words.push_back(word);
		wordsInSentence.push_back(word);
		this->wordsInSentences.push_back(wordsInSentence);


		word = "";
		wordsInSentence.clear();
	}




	this->totalSentences = sentences.size();

	return;


}

/// <summary>
/// Calculates the average number of words per sentence in source text based on data 
/// stored in the class by analyseWordsAndLettersInSourceText
/// e.g. 5 sentences with 2, 3, 5, 5, 5 would return 4 as the average
/// </summary>
/// <returns>Average number of words per sentence</returns>
double Analyser::averageWordsPerSentence() {
	
	int numberOfWordsInSentence = 0;
	for (auto sentence : this->wordsInSentences) {
		numberOfWordsInSentence += sentence.size();
	
	}
	return numberOfWordsInSentence / this->totalSentences;
}

/// <summary>
/// Calculates the average number of letters in the words in source text based on data 
/// stored in the class by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Average number of letters per word</returns>
double Analyser::averageLettersPerWord() {


	int lettersInWords = 0;
	for (std::string word : this->words) {
		lettersInWords += word.size();
	}

	return lettersInWords / Analyser::getTotalWords();
}

/// <summary>
/// Calculates the average number of syllables in the words in source text based on data 
/// stored in the class by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Average number of syllables per words</returns>
double Analyser::averageSyllablesPerWord() { 


	int syllablesInWords = 0;
	for (std::string word : this->words) {
		syllablesInWords += BasicAnalyser::countSyllables(word);
	}

	return syllablesInWords / Analyser::getTotalWords();
}

// 2.2 Methods

/// <summary>
/// Flesch Reading Ease Score: Measures the readability of a text based on sentence length and word length, 
/// you can calculate the Flesch Reading Ease Score by counting the number of sentences and words in a given text and applying the formula:
/// Flesch Reading Ease Score = 206.835 - (1.015 * (total_words / total_sentences)) - (84.6 * (total_syllables / total_words))
/// </summary>
/// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
/// <returns>Flesch Reading Ease Score</returns>
double Analyser::calculateFleschReadingEaseScore(const std::vector<std::string>& sentences) {

	Analyser::analyseWordsAndLettersInSourceText(sentences);

	double wordtotal = Analyser::getTotalWords();
	double sentenceTotal = Analyser::getTotalSentences();
	double syllablesTotal = Analyser::getTotalSyllables();


	double fleschReadingEaseScore = 206.835 - (1.015 * (wordtotal / sentenceTotal)) - (84.6 * (syllablesTotal / wordtotal));

	return fleschReadingEaseScore;

}

/// <summary>
/// Flesch-Kincaid Grade Level: Estimates the U.S. grade level required to understand the text, 
/// you can calculate the Flesch-Kincaid Grade Level by using the formula:
/// Flesch-Kincaid Grade Level = (0.39 * (total_words / total_sentences)) + (11.8 * (total_syllables / total_words)) - 15.59
/// </summary>
/// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
/// <returns>Flesch-Kincaid Grade Level</returns>
double Analyser::calculateFleschKincaidGradeLevel(const std::vector<std::string>& sentences) {
	Analyser::analyseWordsAndLettersInSourceText(sentences);
	double wordtotal = Analyser::getTotalWords();
	double sentenceTotal = Analyser::getTotalSentences();
	double syllablesTotal = Analyser::getTotalSyllables();


	double fleschKincaidGradeLevel = (0.39 * (wordtotal / sentenceTotal)) + (11.8 * (syllablesTotal / wordtotal)) - 15.59;

	return fleschKincaidGradeLevel;

}

// 2.1 Methods

/// <summary>
/// Gunning Fog Index: Measures the years of formal education needed to understand the text. 
/// In C++, you can calculate the Gunning Fog Index by counting the number of words, sentences, and complex words 
/// (words with three or more syllables) in a given text and applying the formula:
/// Gunning Fog Index = 0.4 * ((total_words / total_sentences) + (100 * (total_complex_words / total_words)))
/// </summary>
/// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
/// <returns>Gunning Fog Index</returns>
double Analyser::calculateGunningFogIndex(const std::vector<std::string>& sentences) {

	Analyser::analyseWordsAndLettersInSourceText(sentences);
	double wordtotal = Analyser::getTotalWords();
	double sentenceTotal = Analyser::getTotalSentences();
	double complexWordTotal = Analyser::getTotalComplexWords();


	double gunningFogIndex = 0.4 * ((wordtotal / sentenceTotal) + (100 * (complexWordTotal / wordtotal)));

	return gunningFogIndex;
}

/// <summary>
/// Coleman-Liau Index: Evaluates the text's grade level using characters per word and words per sentence, 
/// you can calculate the Coleman-Liau Index by counting the number of letters, words, and sentences 
/// in a given text and applying the formula:
/// Coleman-Liau Index = (0.0588 * (total_letters / total_words * 100)) - (0.296 * (total_sentences / total_words * 100)) - 15.8
/// </summary>
/// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
/// <returns>Coleman-Liau Index</returns>
double Analyser::calculateColemanLiauIndex(const std::vector<std::string>& sentences) { 

	Analyser::analyseWordsAndLettersInSourceText(sentences);
	double wordtotal = Analyser::getTotalWords();
	double sentenceTotal = Analyser::getTotalSentences();
	double letterTotal = Analyser::getTotalLetters();


	double colemanLiauIndex = (0.0588 * (letterTotal / wordtotal * 100)) - (0.296 * (sentenceTotal / wordtotal * 100)) - 15.8;

	return colemanLiauIndex;
}

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
std::map<std::size_t, std::size_t> Analyser::analyseWordLengthFrequencyInSourceText(const std::vector<std::string>& sentences) {
	Analyser::analyseWordsAndLettersInSourceText(sentences);

	std::map<std::size_t, std::size_t> mapOfFrequency;


	for (std::string word: this->words) {

		mapOfFrequency[word.size()]++;


	}

	return mapOfFrequency;
}

