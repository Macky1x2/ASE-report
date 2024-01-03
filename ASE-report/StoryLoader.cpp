#include "StoryLoader.h"
#include "Branch1LineData.h"
#include "Normal1LineData.h"
#include "define.h"

StoryLoader::StoryLoader() {
    try {
        //ファイル読み込み, データ変換・保存
        SetFileOfText(FIRST_FILE);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

string StoryLoader::GetNameAddedTxt(string fileName) {
    return fileName + ".txt";   //拡張子追加
}

void StoryLoader::SetFileOfText(string fileName) {
    string loadFileName = GetNameAddedTxt(fileName);        //拡張子追加
    string line;       //1行テキスト用

    //ファイル読み込み
    ifstream input_file = ifstream(loadFileName);
    if (!input_file.is_open()) {
        throw runtime_error(loadFileName+"というファイルが見つかりませんでした.");
    }

    //1行ずつデータ変換・保存
    while (getline(input_file, line)) {
        if (line.find(STORY_BRANCH) == 0) {     //分岐行の場合
            auto addData = make_shared<Branch1LineData>(line);

            //分岐先もデータ変換・保存する
            vector<string> branches = addData->GetBranchNames();
            for (int i = 0; i < branches.size(); i++) {
                SetFileOfText(branches[i]);
            }

            //保存
            loadedTexts[fileName].push_back(addData);
        }
        else {      //通常行の場合
            //保存
            loadedTexts[fileName].push_back(make_shared<Normal1LineData>(line));        }
    }

    //ファイル閉じる
    input_file.close();
}

vector<shared_ptr<Normal1LineData> > StoryLoader::GetLoadedText(string fileName) {
    return loadedTexts[fileName];
}