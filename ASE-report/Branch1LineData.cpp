#include "Branch1LineData.h"
#include "Normal1LineData.h"
#include "GameManager.h"

Branch1LineData::Branch1LineData(string text) :Normal1LineData(text){
	text = text.substr(text.find(" ") + 1);	//@branch q1_1 q1_2 q1_3 => q1_1 q1_2 q1_3
	
	int spaceNum;
	while ((spaceNum = text.find(" ")) != string::npos) {		//q1_1 q1_2 q1_3 : 4
		branchNames.push_back(text.substr(0, spaceNum));		//q1_1 q1_2 q1_3 から q1_1を取り出す
		text = text.substr(spaceNum + 1);						//q1_1 q1_2 q1_3 => q1_2 q1_3
	}
	branchNames.push_back(text);		//最後の要素を追加
}

vector<string> Branch1LineData::GetBranchNames() {
	return branchNames;
}

void Branch1LineData::Operate(GameManager& gm) {
	string input = gm.GetRecentInput();

	while (true) {
		//ユーザーの入力が有効かチェック	ユーザーの入力をintとして扱うと例外が増えるため、stringとして扱っている
		bool inputTypeIs = false;
		for (int i = 0; i < branchNames.size(); i++) {
			if (input == to_string(i + 1)) {	//選択肢の数は、int型をオーバーフローしないと仮定
				inputTypeIs = true;
				break;
			}
		}

		if (inputTypeIs) {
			gm.SetNextFile(branchNames[stoi(input) - 1]);		//inputTypeIsがtrueのとき、stoi(input) - 1が範囲外となることはない
			break;
		}
		else {
			cout << "※※※入力形式が正しくありません。※※※" << endl;
			cin >> input;
		}
	}
}