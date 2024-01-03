#include "Branch1LineData.h"
#include "Normal1LineData.h"
#include "GameManager.h"

Branch1LineData::Branch1LineData(string text) :Normal1LineData(text){
	text = text.substr(text.find(" ") + 1);	//@branch q1_1 q1_2 q1_3 => q1_1 q1_2 q1_3
	
	int spaceNum;
	while ((spaceNum = text.find(" ")) != string::npos) {		//q1_1 q1_2 q1_3 : 4
		branchNames.push_back(text.substr(0, spaceNum));		//q1_1 q1_2 q1_3 ���� q1_1�����o��
		text = text.substr(spaceNum + 1);						//q1_1 q1_2 q1_3 => q1_2 q1_3
	}
	branchNames.push_back(text);		//�Ō�̗v�f��ǉ�
}

vector<string> Branch1LineData::GetBranchNames() {
	return branchNames;
}

void Branch1LineData::Operate(GameManager& gm) {
	string input = gm.GetRecentInput();

	while (true) {
		//���[�U�[�̓��͂��L�����`�F�b�N	���[�U�[�̓��͂�int�Ƃ��Ĉ����Ɨ�O�������邽�߁Astring�Ƃ��Ĉ����Ă���
		bool inputTypeIs = false;
		for (int i = 0; i < branchNames.size(); i++) {
			if (input == to_string(i + 1)) {	//�I�����̐��́Aint�^���I�[�o�[�t���[���Ȃ��Ɖ���
				inputTypeIs = true;
				break;
			}
		}

		if (inputTypeIs) {
			gm.SetNextFile(branchNames[stoi(input) - 1]);		//inputTypeIs��true�̂Ƃ��Astoi(input) - 1���͈͊O�ƂȂ邱�Ƃ͂Ȃ�
			break;
		}
		else {
			cout << "���������͌`��������������܂���B������" << endl;
			cin >> input;
		}
	}
}