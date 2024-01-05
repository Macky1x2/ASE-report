#pragma once
#include <iostream>
#include <vector>
#include "Normal1LineData.h"

using namespace std;

class StoryLoader;

class GameManager {
private:
	string recentInput;		//�ł��ŋ߂̃��[�U�[����
	string nextFile;		//1�̃t�@�C���ǔj��́A���̃t�@�C���B�@@branch�ɂ���Ďw�肳��邪�A@branch���Ȃ��ꍇ�Q�[���͏I������B

	void PlayOneFile(vector<shared_ptr<Normal1LineData> >);
public:
	GameManager(StoryLoader&);
	void SetRecentInput(string);
	string GetRecentInput();
	void SetNextFile(string);
};