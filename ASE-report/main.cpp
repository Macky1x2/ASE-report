#include <iostream>
#include "StoryLoader.h"
#include "GameManager.h"
#include "define.h"

using namespace std;

int main() {
	//ストーリーデータ読み込み, 変換
	StoryLoader loader = StoryLoader();

	//ストーリーゲーム進行
	GameManager manager = GameManager(loader);

	return 0;
}