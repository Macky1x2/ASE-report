#pragma once
#include <iostream>
#include <string>

using namespace std;

class GameManager;

class Normal1LineData {
private:
	string text;		//1�s�e�L�X�g���\�[�X���̂܂�
public:
	Normal1LineData(string);		//����(1�s�e�L�X�g���\�[�X)
	string GetText();				//�\���e�L�X�g�擾
	virtual void Operate(GameManager&);					//���[�U�[����
};