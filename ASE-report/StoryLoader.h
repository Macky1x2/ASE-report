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
	string firstFile;		//ストーリー最初のファイル
	map<string, vector<shared_ptr<Normal1LineData> > > loadedTexts;		//辞書<ファイル名, 1行データリスト>

	string GetNameAddedTxt(string);
	void SetFileOfText(string, vector<string>&);		//vectorの標準ライブラリのstring検索をしたいため、要素をスマートポインタ型にしない(第二引数はローカル変数で、ローカル変数は自動的に解放される)
public:
	StoryLoader(string);
	~StoryLoader();
	vector<shared_ptr<Normal1LineData> > GetLoadedText(string);
	string GetFirstFile();
};