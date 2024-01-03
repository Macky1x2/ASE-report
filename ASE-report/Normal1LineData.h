#pragma once
#include <iostream>
#include <string>

using namespace std;

class GameManager;

class Normal1LineData {
private:
	string text;		//1行テキストリソースそのまま
public:
	Normal1LineData(string);		//引数(1行テキストリソース)
	string GetText();				//表示テキスト取得
	virtual void Operate(GameManager&);					//ユーザー操作
};