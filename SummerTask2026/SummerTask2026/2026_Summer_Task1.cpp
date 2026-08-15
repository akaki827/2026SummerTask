#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    //変数宣言
    int answer = -1;      
    int question;         
    int count = 0;        

    //乱数の初期化
    srand((unsigned int)time(nullptr));

    //乱数の設定
    question = rand() % 101;
    
    //表示
    cout << "数字当てゲーム" << endl;
    cout << "0～100までの数字を当ててください。" << endl;


    //ゲームループ
    while (question != answer)
    {
        //回数のカウント
        count++;

        //入力チェック
        while (true)
        {
            cout << "0～100の数字を入力してください：" << endl;
            cin >> answer;

            if (answer < 0 || answer > 100)
            {
                cout << "入力に誤りがあります。再入力してください。" << endl;
            }
            else
            {
                break;
            }
        }

        //答えが間違っていた場合にヒントを出す
        if (question > answer)
        {
            cout << "もっと大きい数字です。" << endl;
        }
        else if (question < answer)
        {
            cout << "もっと小さい数字です。" << endl;
        }
    }
    //答えがあっていた場合に結果を表示して処理を終了する
    cout << endl;
    cout << "おめでとうございます！正解です！" << endl;
    cout << "正解：" << answer << endl;
    cout << count << "回目で当てることができました。" << endl;

    return 0;
}