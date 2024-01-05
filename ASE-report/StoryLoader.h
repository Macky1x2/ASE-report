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
	string firstFile;		//�X�g�[���[�ŏ��̃t�@�C��
	map<string, vector<shared_ptr<Normal1LineData> > > loadedTexts;		//����<�t�@�C����, 1�s�f�[�^���X�g>

	string GetNameAddedTxt(string);
	void SetFileOfText(string, vector<string>&);		//vector�̕W�����C�u������string���������������߁A�v�f���X�}�[�g�|�C���^�^�ɂ��Ȃ�(�������̓��[�J���ϐ��ŁA���[�J���ϐ��͎����I�ɉ�������)
public:
	StoryLoader(string);
	~StoryLoader();
	vector<shared_ptr<Normal1LineData> > GetLoadedText(string);
	string GetFirstFile();
};