#include "Normal1LineData.h"
#include "GameManager.h"

Normal1LineData::Normal1LineData(string text) {
	this->text = text;
}

string Normal1LineData::GetText() {
	return text;
}

void Normal1LineData::Operate(GameManager& gm) {
	//テキスト表示
	cout << text << endl;

	//ユーザー入力
	string input;
	getline(cin, input);
	gm.SetRecentInput(input);	//入力をGameManagerに通知
}