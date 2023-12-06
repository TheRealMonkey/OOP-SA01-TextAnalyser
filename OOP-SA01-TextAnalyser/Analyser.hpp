#include "BasicAnalyser.h";
#include <iostream>;

class Analyser :public BasicAnalyser {
private:
	std::vector<std::string> words;
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
std::size_t Analyser::getTotalSentences() {
	//returns the number of sentences stored in the private scope of the method.
	return this->totalSentences;
}

/// <summary>
/// Return the total number of words from the last text analysed by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Total number of words</returns>
long Analyser::getTotalWords() {
	//returns the number of words by using the size method that will return the number of elements in the vector stored in the private scope.
	return this->words.size();
}

/// <summary>
/// Return the total number of syllables from the last text analysed by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Total number of syllables</returns>
long Analyser::getTotalSyllables() {

	//used to store number of syllables.
	long numberOfSyllables = 0;

	//loops though every word in the word vector.
	for (std::string word : this->words) {
		//this will add the number of Syllables from each word which is returned by the countSyllables method defined in the basicAnalyser class
		numberOfSyllables += BasicAnalyser::countSyllables(word);
	}
	//returns the total number of Syllables
	return numberOfSyllables;
}

/// <summary>
/// Return the total number of complex words (words with 3 or more syllables) from the last text analysed 
/// by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Total number of complex words</returns>
long Analyser::getTotalComplexWords() {
	//used to store the number of complex words 
	long numbrOfComplexSyllables = 0;

	//used to count the Syllables for each worf
	long numberOfSyllables = 0;

	//loops through every word
	for (std::string word : this->words) {
		//number of Syllables returned by countSyllables and set to numberOfSyllables
		numberOfSyllables = BasicAnalyser::countSyllables(word);


		//if the number of Syllables is 3 or more, add 1 to numbrOfComplexSyllables
		if (numberOfSyllables >= 3) {
			numbrOfComplexSyllables++;
		}
	}

	//return the number of complex words.
	return numbrOfComplexSyllables;
}

/// <summary>
/// Return the total number of letters from the last text analysed by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Total number of letters</returns>
std::size_t Analyser::getTotalLetters() {
	//returns the number of letters which is stored in the private scope
	return this->numberOfLetters;
}

/// <summary>
/// Analyses the words and letters in source text and internally stores the following values for access by the associated getters
/// totalSentences, totalWords, totalSyllables, totalComplexWords (words with 3 or more syllables), totalLetters
/// </summary>
/// <param name="sentences">Vector of strings representings the source text as individual sentences</param>
void Analyser::analyseWordsAndLettersInSourceText(const std::vector<std::string>& sentences) {


	//this will store each word by adding each character untill a space which will indicate the word is finished and then
	//	put into the wrords and wordsInSentence vectors.
	std::string word;

	//the number of letters in the vector.
	int numberOfLetters;
	//loops though every sentence in sentences.
	for (std::string sentence : sentences) {
		//loops though every letter in the sentence.
		for (char letter : sentence) {
			//char 32 == space
			//if the character is a space, it will inditacte the word has been finshed and then add it to the words vector
			//	aswell as clearing the word variable.
			if (letter == char(32)) {
				this->words.push_back(word);

				word.clear();
			}
			else {
				//if the character is not a space, then the letter will be added to the word string. This will also count the number of letters
				//	in the phrase which will be used later.
				this->numberOfLetters++;
				word += letter;
			}
		}
		//we need to push the word to words because the last word in the sentence will not be cought in the for loop above
		//	therefor we need to push it ourself after the loop is over.
		words.push_back(word);


		//this will be cleared for the next sentence.
		word.clear();

	}



	//stets the number of sentences by getting the size of the vector as each element is a sentence.
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
	//devides total number of words by number of sentences.
	return this->words.size() / this->totalSentences;
}

/// <summary>
/// Calculates the average number of letters in the words in source text based on data 
/// stored in the class by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Average number of letters per word</returns>
double Analyser::averageLettersPerWord() {

	//devides total number of letters by number of words.
	return Analyser::getTotalLetters() / Analyser::getTotalWords();
}

/// <summary>
/// Calculates the average number of syllables in the words in source text based on data 
/// stored in the class by analyseWordsAndLettersInSourceText
/// </summary>
/// <returns>Average number of syllables per words</returns>
double Analyser::averageSyllablesPerWord() {

	//devides total number of syllables by number of words.
	return Analyser::getTotalSyllables() / Analyser::getTotalWords();
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
	//run the method so that we can get the values needed
	Analyser::analyseWordsAndLettersInSourceText(sentences);


	//assign the values needed for the equation.
	double wordtotal = Analyser::getTotalWords();
	double sentenceTotal = Analyser::getTotalSentences();
	double syllablesTotal = Analyser::getTotalSyllables();

	//using the equation in the summary, substatute the numbers with the values given by analyseWordsAndLettersInSourceText.
	double fleschReadingEaseScore = 206.835 - (1.015 * (wordtotal / sentenceTotal)) - (84.6 * (syllablesTotal / wordtotal));

	//returns the result of the equation.
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
	//run the method so that we can get the values needed
	Analyser::analyseWordsAndLettersInSourceText(sentences);

	//assign the values needed for the equation.
	double wordtotal = Analyser::getTotalWords();
	double sentenceTotal = Analyser::getTotalSentences();
	double syllablesTotal = Analyser::getTotalSyllables();

	//using the equation in the summary, substatute the numbers with the values given by analyseWordsAndLettersInSourceText.
	double fleschKincaidGradeLevel = (0.39 * (wordtotal / sentenceTotal)) + (11.8 * (syllablesTotal / wordtotal)) - 15.59;

	//returns the result of the equation.
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
	//run the method so that we can get the values needed
	Analyser::analyseWordsAndLettersInSourceText(sentences);

	//assign the values needed for the equation.
	double wordtotal = Analyser::getTotalWords();
	double sentenceTotal = Analyser::getTotalSentences();
	double complexWordTotal = Analyser::getTotalComplexWords();

	//using the equation in the summary, substatute the numbers with the values given by analyseWordsAndLettersInSourceText.
	double gunningFogIndex = 0.4 * ((wordtotal / sentenceTotal) + (100 * (complexWordTotal / wordtotal)));

	//returns the result of the equation.
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

	//assign the values needed for the equation.
	double wordtotal = Analyser::getTotalWords();
	double sentenceTotal = Analyser::getTotalSentences();
	double letterTotal = Analyser::getTotalLetters();

	//using the equation in the summary, substatute the numbers with the values given by analyseWordsAndLettersInSourceText.
	double colemanLiauIndex = (0.0588 * (letterTotal / wordtotal * 100)) - (0.296 * (sentenceTotal / wordtotal * 100)) - 15.8;

	//returns the result of the equation.
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
	
	//this is called so that we can get a vector of the words in the sentences
	Analyser::analyseWordsAndLettersInSourceText(sentences);
	// create an empty map that will be used to store the frequency of the words
	std::map<std::size_t, std::size_t> mapOfFrequency;

	//loops through every word in the sentences
	for (std::string word : this->words) {

		//using the length of the word as the key, we add 1 to the value of that key
		mapOfFrequency[word.size()]++;


	}
	//returns the map with the frequencies.
	return mapOfFrequency;
}

