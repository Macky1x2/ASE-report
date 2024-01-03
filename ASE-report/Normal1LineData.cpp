#include "Normal1LineData.h"
#include "GameManager.h"

Normal1LineData::Normal1LineData(string text) {
	this->text = text;
}

string Normal1LineData::GetText() {
	return text;
}

void Normal1LineData::Operate(GameManager& gm) {
	//�e�L�X�g�\��
	cout << text << endl;

	//���[�U�[����
	string input;
	getline(cin, input);
	gm.SetRecentInput(input);	//���͂�GameManager�ɒʒm
}