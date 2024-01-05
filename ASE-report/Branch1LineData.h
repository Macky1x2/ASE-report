#pragma once
#include <iostream>
#include <vector>
#include "Normal1LineData.h"

class Branch1LineData :public Normal1LineData {
private:
	vector<string> branchNames;		//すべての分岐先のファイル名リスト	vectorの標準ライブラリのstring検索をする可能性があるため要素にスマートポインタは用いない(代わりにデストラクタで解放すること)
public:
	Branch1LineData(string);
	~Branch1LineData();
	vector<string> GetBranchNames();
	void Operate(GameManager&)override;					//ユーザー操作
};