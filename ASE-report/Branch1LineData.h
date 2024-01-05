#pragma once
#include <iostream>
#include <vector>
#include "Normal1LineData.h"

class Branch1LineData :public Normal1LineData {
private:
	vector<string> branchNames;		//���ׂĂ̕����̃t�@�C�������X�g	vector�̕W�����C�u������string����������\�������邽�ߗv�f�ɃX�}�[�g�|�C���^�͗p���Ȃ�(����Ƀf�X�g���N�^�ŉ�����邱��)
public:
	Branch1LineData(string);
	~Branch1LineData();
	vector<string> GetBranchNames();
	void Operate(GameManager&)override;					//���[�U�[����
};