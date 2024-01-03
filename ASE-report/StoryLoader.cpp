#include "StoryLoader.h"
#include "Branch1LineData.h"
#include "Normal1LineData.h"
#include "define.h"

StoryLoader::StoryLoader() {
    try {
        //�t�@�C���ǂݍ���, �f�[�^�ϊ��E�ۑ�
        SetFileOfText(FIRST_FILE);
    }
    catch (const runtime_error& e) {
        cout << e.what() << endl;
    }
}

string StoryLoader::GetNameAddedTxt(string fileName) {
    return fileName + ".txt";   //�g���q�ǉ�
}

void StoryLoader::SetFileOfText(string fileName) {
    string loadFileName = GetNameAddedTxt(fileName);        //�g���q�ǉ�
    string line;       //1�s�e�L�X�g�p

    //�t�@�C���ǂݍ���
    ifstream input_file = ifstream(loadFileName);
    if (!input_file.is_open()) {
        throw runtime_error(loadFileName+"�Ƃ����t�@�C����������܂���ł���.");
    }

    //1�s���f�[�^�ϊ��E�ۑ�
    while (getline(input_file, line)) {
        if (line.find(STORY_BRANCH) == 0) {     //����s�̏ꍇ
            auto addData = make_shared<Branch1LineData>(line);

            //�������f�[�^�ϊ��E�ۑ�����
            vector<string> branches = addData->GetBranchNames();
            for (int i = 0; i < branches.size(); i++) {
                SetFileOfText(branches[i]);
            }

            //�ۑ�
            loadedTexts[fileName].push_back(addData);
        }
        else {      //�ʏ�s�̏ꍇ
            //�ۑ�
            loadedTexts[fileName].push_back(make_shared<Normal1LineData>(line));        }
    }

    //�t�@�C������
    input_file.close();
}

vector<shared_ptr<Normal1LineData> > StoryLoader::GetLoadedText(string fileName) {
    return loadedTexts[fileName];
}