#include "GameManager.h"
#include "StoryLoader.h"
#include "Normal1LineData.h"
#include "define.h"

GameManager::GameManager(StoryLoader& loader) {
	recentInput = "";
	nextFile = FIRST_FILE;

	while (true) {
		if (nextFile == "") {
			break;
		}
		auto firstData = loader.GetLoadedText(nextFile);
		nextFile = "";
		PlayOneFile(firstData);
	}
}

void GameManager::PlayOneFile(vector<shared_ptr<Normal1LineData> > fileData) {
	for (int i = 0; i < fileData.size(); i++) {
		fileData[i]->Operate(*this);
	}
}

void GameManager::SetRecentInput(string input) {
	recentInput = input;
}

string GameManager::GetRecentInput() {
	return recentInput;
}

void GameManager::SetNextFile(string fileName) {
	nextFile = fileName;
}