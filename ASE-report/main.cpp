#include <iostream>
#include "StoryLoader.h"
#include "GameManager.h"
#include "define.h"

using namespace std;

int main() {
	//�X�g�[���[�f�[�^�ǂݍ���, �ϊ�
	StoryLoader loader = StoryLoader();

	//�X�g�[���[�Q�[���i�s
	GameManager manager = GameManager(loader);

	return 0;
}