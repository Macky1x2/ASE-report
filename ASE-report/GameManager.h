#pragma once
#include <iostream>
#include <vector>
#include "Normal1LineData.h"

using namespace std;

class StoryLoader;

class GameManager {
private:
	string recentInput;
	string nextFile;

	void PlayOneFile(vector<shared_ptr<Normal1LineData> >);
public:
	GameManager(StoryLoader&);
	void SetRecentInput(string);
	string GetRecentInput();
	void SetNextFile(string);
};