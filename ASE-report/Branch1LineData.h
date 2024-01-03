#pragma once
#include <iostream>
#include <vector>
#include "Normal1LineData.h"

class Branch1LineData :public Normal1LineData {
private:
	vector<string> branchNames;		//すべての分岐先のファイル名リスト
public:
	Branch1LineData(string);
	vector<string> GetBranchNames();
	void Operate(GameManager&)override;					//ユーザー操作
};