#include "pch.h"
#include "CppUnitTest.h"
#include "../OOP-SA01-TextAnalyser/Analyser.hpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestAnalyser
{
	TEST_CLASS(UnitTestAnalyser)
	{
	private:
		Analyser textAnalyser;

		std::vector<std::string> sourceTextNoComplex
			= {
			"Complex short Complex short Complex short Complex short Complex short Complex short Complex short Complex short",
			"Complex short Complex short Complex short Complex short Complex short Complex short Complex short Complex short",
			"Complex short Complex short Complex short Complex short Complex short Complex short Complex short Complex short",
			"Complex short Complex short Complex short Complex short Complex short Complex short Complex short Complex short",
			"Complex short Complex short Complex short Complex short Complex short Complex short Complex short Complex short" };

		std::vector<std::string> sourceTextFiftyPercent
			= {
			 "many requirements many requirements many requirements many requirements many requirements many requirements many requirements",
			 "many requirements many requirements many requirements many requirements many requirements many requirements many requirements",
			 "many requirements many requirements many requirements many requirements many requirements many requirements many requirements",
			 "many requirements many requirements many requirements many requirements many requirements many requirements many requirements",
			 "many requirements many requirements many requirements many requirements many requirements many requirements many requirements"
		};

		std::vector<std::string> sourceText8Years
			= {
			"Before time was time there was a Great Hill",
			"And on the Great Hill there lived the Yolks",
			"The Yolks spent their entire lives climbing the Great Hill trying to reach the top",
			"Some Yolks climbed fast",
			"Some Yolks climbed slowly",
			"One Yolk in particular was a very slow climber",
			"He was different than the rest of the Yolks",
			"When he climbed, all the other Yolks passed him",
			"It was hard for him to watch them pass by",
			"He felt like the worst climber in the world",
			"Some Yolks made fun of him as they passed",
			"Others didnt",
			"Some Yolks wanted to help him climb but he didnt let them",
			"It was hard for him to climb.", "It was even harder when it rained because the ground got slippery",
			"Sometimes it seemed like it was only raining on him",
			"But it wasnt",
			"There were times when he felt like he wasnt moving at all",
			"But he was",
			"Then one day he met another Yolk who climbed even slower than he did",
			"He helped the slower Yolk climb",
			"Thank You said the slower Yolk",
			"Youre Welcome said the slow Yolk I cant be of much help to anyone else since I climb so slowly",
			"Slowly asked the slower Yolk",
			"Well yes I watch other Yolks pass me all the time",
			"I do not know if you are slow or fast but I do know that you helped me and that you are still climbing",
			"The slow Yolk said goodbye to the slower Yolk and kept climbing",
			"Still climbing he thought to himself",
			"That is true",
			"And he smiled",
			"So the Yolk kept climbing",
			"He climbed when it was nice out he climbed when it rained, and he even climbed when it snowed",
			"As he kept climbing he got better and better",
			"Sometimes he would pass other Yolks and sometimes they would pass him",
			"He had stopped paying attention",
			"He also noticed that some Yolks were no longer climbing",
			"When a yolk stops climbing it stays where it is",
			"Some Yolks stop climbing because they are happy with how far they have gone",
			"Others stop climbing because they dont want to climb anymore",
			"The Yolks that had stopped climbing did not like to be passed and they made it harder to get by",
			"But the Yolk kept climbing, right over them",
			"There were still times when the Yolk thought he was climbing an impossible hill but he kept climbing",
			"Always always climbing",
			"Do you think he made the top"
		};

		std::vector<std::string> sourceTextGuardian
			= {
			"Casimiro 23 has become the first person on a seasonal worker visa to take a farm to an employment tribunal",
			"Her claim against Haygrove farm for unlawful deduction of wages unfair dismissal discrimination and harassment was filed last week and a preliminary hearing is expected in March",
			"Haygrove which supplies cherries and berries to most leading supermarket chains rejected her allegations and intends to defend the claim robustly",
			"The case has been brought by the United Voices of the World union which represents some of Britains most vulnerable low-paid workers",
			"Casimiro grew up in Bolivia where she worked from the age of 11 doing jobs to prop up the familys income as smallscale farmers",
			"She was one of 134 Latin American workers who came to the farm but is alone in taking it to tribunal",
			"We were all used to working really hard but we wanted to make money she said",
			"When Casimiro arrived on the farm terrible weather meant there was initially no work",
			"For 12 days she sat in a rain-hammered caravan wondering how she would make back the cost of the flight and visas",
			"The farm lent her and the others between 50 and 100 for essentials and did not charge for accommodation during this period but did not pay them",
			"When work finally began in July Casimiro said the conditions were not what she expected",
			"There was constant shouting at us she claimed saying that one supervisor in particular would often raise their voice",
			"Haygrove disputed her account and said no grievances had been raised previously about the supervisor",
			"Casimiro said there was no drinking water available where they picked cherries and that she ended up eating the fruit to quench her thirst for which she was reprimanded",
			"Haygrove said water was provided in all picking fields by team leaders and that this was regularly audited",
			"It added that eating fruit was forbidden for hygiene reasons"
		};

	public:
		
		TEST_METHOD(GetTotalWords_3rd)
		{
			textAnalyser.analyseWordsAndLettersInSourceText(sourceTextFiftyPercent);
			Assert::AreEqual<long>(70, textAnalyser.getTotalWords(), 
				L"getTotalWords method did not return total the words correctly.");
		}

		TEST_METHOD(GetTotalSyllables_3rd)
		{
			textAnalyser.analyseWordsAndLettersInSourceText(sourceTextFiftyPercent);
			Assert::AreEqual<long>(210, textAnalyser.getTotalSyllables(), 
				L"getTotalSyllables method did not return total the words correctly.");
		}

		TEST_METHOD(GetTotalComplexWords_3rd)
		{
			textAnalyser.analyseWordsAndLettersInSourceText(sourceTextFiftyPercent);
			Assert::AreEqual<long>(35, textAnalyser.getTotalComplexWords(), 
				L"getTotalComplexWords method did not return total the words correctly.");
		}

		TEST_METHOD(GetTotalLetters_3rd)
		{
			textAnalyser.analyseWordsAndLettersInSourceText(sourceTextFiftyPercent);
			Assert::AreEqual<std::size_t>(560, textAnalyser.getTotalLetters(), 
				L"getTotalLetters method did not return total the words correctly.");
		}

		TEST_METHOD(GetTotalSentences_3rd)
		{
			textAnalyser.analyseWordsAndLettersInSourceText(sourceTextFiftyPercent);
			Assert::AreEqual<std::size_t>(5, textAnalyser.getTotalSentences(), 
				L"getTotalSentences method did not return total the words correctly.");
		}

		TEST_METHOD(WordsAndLettersInSourceText_3rd)
		{
			textAnalyser.analyseWordsAndLettersInSourceText(sourceText8Years);

			Assert::AreEqual<long>(417, textAnalyser.getTotalWords(), 
				L"getTotalWords method did not return total the words correctly.");
			Assert::AreEqual<long>(568, textAnalyser.getTotalSyllables(), 
				L"getTotalSyllables method did not return total the words correctly.");
			Assert::AreEqual<long>(18, textAnalyser.getTotalComplexWords(), 
				L"getTotalComplexWords method did not return total the words correctly.");
			Assert::AreEqual<std::size_t>(1710, textAnalyser.getTotalLetters(), 
				L"getTotalLetters method did not return total the words correctly.");
			Assert::AreEqual<std::size_t>(44, textAnalyser.getTotalSentences(), 
				L"getTotalSentences method did not return total the words correctly.");
		}

		TEST_METHOD(FleschReadingEaseScore_2_2nd)
		{
			double result = textAnalyser.calculateFleschReadingEaseScore(sourceText8Years);
			Assert::AreEqual(81.98, result, 0.01, 
				L"calculateFleschReadingEaseScore method did not calculate the value correctly.");
		}

		TEST_METHOD(FleschKincaidGradeLevel_2_2nd)
		{
			double result = textAnalyser.calculateFleschKincaidGradeLevel(sourceText8Years);
			Assert::AreEqual(4.17, result, 0.01,
				L"calculateFleschReadingEaseScore method did not calculate the value correctly.");
		}


		TEST_METHOD(GunningFogIndex_2_1nd)
		{
			double result = textAnalyser.calculateGunningFogIndex(sourceText8Years);
			Assert::AreEqual(5.51, result, 0.01,
				L"calculateFleschReadingEaseScore method did not calculate the value correctly.");
		}

		TEST_METHOD(ColemanLiauIndex_2_1nd)
		{
			double result = textAnalyser.calculateColemanLiauIndex(sourceText8Years);
			Assert::AreEqual(5.18, result, 0.01,
				L"calculateFleschReadingEaseScore method did not calculate the value correctly.");
		}

		TEST_METHOD(WordLengthFrequencyInSourceText_1st)
		{
			std::map<std::size_t, std::size_t> result =
			textAnalyser.analyseWordLengthFrequencyInSourceText(sourceTextGuardian);
			std::string resultMapAsString = "";
			std::wstring resultMessage;
			std::wstring guardianResultMessage;
			std::string guardianMapAsString;

			std::map<std::size_t, std::size_t> guardianResult = { {1,4},{2,47}, {3,78}, {4,50}, {5,36}, {6,26}, {7,24}, {8,29}, {9,7}, {10,12}, {11,4},  {13,2}, {14,1} };

			for (auto i : result)
			{
				resultMapAsString += std::to_string(i.first) + " : " + std::to_string(i.second) + "\n";
			}
			resultMessage.assign(resultMapAsString.begin(), resultMapAsString.end());

			for (auto i : guardianResult)
			{
				guardianMapAsString += std::to_string(i.first) + " : " + std::to_string(i.second) + "\n";
			}
			guardianResultMessage.assign(guardianMapAsString.begin(), guardianMapAsString.end());
			
			resultMessage = L"analyseWordLengthFrequencyInSourceText method returned the data:\n" 
				+ resultMessage + L"Correct result data should be:\n" + guardianResultMessage;

			Assert::IsTrue(result == guardianResult,
				(resultMessage.c_str()));
		}

	};
}
