#pragma once
#include <iostream>
#include <vector>
#include "Normal1LineData.h"

using namespace std;

class StoryLoader;

class GameManager {
private:
	string recentInput;		//最も最近のユーザー入力
	string nextFile;		//1つのファイル読破後の、次のファイル。　@branchによって指定されるが、@branchがない場合ゲームは終了する。

	void PlayOneFile(vector<shared_ptr<Normal1LineData> >);
public:
	GameManager(StoryLoader&);
	void SetRecentInput(string);
	string GetRecentInput();
	void SetNextFile(string);
};