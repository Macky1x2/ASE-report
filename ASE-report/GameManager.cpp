#include "GameManager.h"
#include "StoryLoader.h"
#include "Normal1LineData.h"
#include "define.h"

GameManager::GameManager(StoryLoader& loader) {
	recentInput = "";			//最初は空行を直前の入力とする
	nextFile = loader.GetFirstFile();		//最初に読み込むファイル

	while (true) {
		if (nextFile == "") {	//次ファイル以降時、nextFileが空文字列であればゲーム終了
			break;
		}
		auto firstData = loader.GetLoadedText(nextFile);	//StoryLoaderで変換されたデータを取得
		nextFile = "";			//PlayOneFileにおいてnextFileに何か入ればもう1回ループ
		PlayOneFile(firstData);	//1ファイル分のストーリー実行
	}
}

GameManager::~GameManager() {

}

void GameManager::PlayOneFile(vector<shared_ptr<Normal1LineData> > fileData) {
	//各行に対し、プレイヤーが操作	fileData[i]はBranch1LineData型の場合もある
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