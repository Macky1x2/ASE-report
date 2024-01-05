#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

class Normal1LineData;

class StoryLoader {
private:
	map<string, vector<shared_ptr<Normal1LineData> > > loadedTexts;		//����<�t�@�C����, 1�s�f�[�^���X�g>

	string GetNameAddedTxt(string);
	void SetFileOfText(string);
public:
	StoryLoader(string);
	vector<shared_ptr<Normal1LineData> > GetLoadedText(string);
};