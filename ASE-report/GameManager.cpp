#include "GameManager.h"
#include "StoryLoader.h"
#include "Normal1LineData.h"
#include "define.h"

GameManager::GameManager(StoryLoader& loader) {
	recentInput = "";			//�ŏ��͋�s�𒼑O�̓��͂Ƃ���
	nextFile = loader.GetFirstFile();		//�ŏ��ɓǂݍ��ރt�@�C��

	while (true) {
		if (nextFile == "") {	//���t�@�C���ȍ~���AnextFile���󕶎���ł���΃Q�[���I��
			break;
		}
		auto firstData = loader.GetLoadedText(nextFile);	//StoryLoader�ŕϊ����ꂽ�f�[�^���擾
		nextFile = "";			//PlayOneFile�ɂ�����nextFile�ɉ�������΂���1�񃋁[�v
		PlayOneFile(firstData);	//1�t�@�C�����̃X�g�[���[���s
	}
}

GameManager::~GameManager() {

}

void GameManager::PlayOneFile(vector<shared_ptr<Normal1LineData> > fileData) {
	//�e�s�ɑ΂��A�v���C���[������	fileData[i]��Branch1LineData�^�̏ꍇ������
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