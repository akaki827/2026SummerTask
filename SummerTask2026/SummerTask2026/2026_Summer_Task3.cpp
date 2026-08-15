#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
	//定数
	const int CARD = 3;
	const int CARD_NUMBER = 10;

	//変数
	int i, hit = 0;
	int playerCard[CARD];
	int enemyCard[CARD];
	int plyChoice[CARD];
	int emyChoice[CARD];

	//フラグ管理
	bool trunFlag = true;
	bool judgementFlag = false;

	//乱数の初期化
	srand((unsigned int)time(NULL));

	//乱数
	for (i = 0; i < CARD; i++)
	{
		playerCard[i] = rand() % CARD_NUMBER;
		enemyCard[i] = rand() % CARD_NUMBER;
	}

	//表示
	cout << "===================   Hit & Blow   ============================" << "\n";
	cout << "3マスの数字あてゲームプレイヤーとCPUが、お互いに隠し持った3つの数字を当てるターン制のゲーム" << "\n";
	cout << "あなたの配られてカードは," << "\n";

	//手札の表示
	for (i = 0; i < CARD; i++)
	{
		cout << i + 1 << "番目" << playerCard[i] << "\n";
	}

	cout << "===================   GAME STRAT   ============================" << "\n";

	//ゲームループ
	while (true)
	{

		if (trunFlag)
		{

			hit = 0;
			cout << "PLAYER TRUN 「数字の0から9までの数字を3つ選んでください」\n";
			for (i = 0; i < CARD; i++)
			{
				//入力チェック
				while (true)
				{
					cin >> plyChoice[i];
					if (0 > plyChoice[i] || 9 < plyChoice[i])
					{
						cout << "入力に誤りがあります。再度入力してください。\n";
					}
					else
					{
						break;
					}

				}
			}

			//カードが当たっているかを判定する
			for (i = 0; i < CARD; i++)
			{
				if (plyChoice[i] == enemyCard[i])
				{
					cout << "Hit,";
					hit++;
				}
				else
				{
					cout << "Blow,";
				}
			}
			//全て当たっていたらループ終了
			cout << "\n";
			if (hit == 3)
			{
				cout << "3Hit!!\n";
				judgementFlag = true;
				break;
			}

			cout << "\n";
			trunFlag = false;
		}
		//turnフラグがfalseなら敵のターン
		else
		{
			hit = 0;

			cout << "ENEMY TRUN \n";
			//エネミーの予想の表示
			for (i = 0; i < CARD; i++)
			{
				emyChoice[i] = rand() % CARD_NUMBER;

				cout << i + 1 << "番目" << emyChoice[i] << "\n";
			}
			//カードが当たっているかを判定する
			for (i = 0; i < CARD; i++)
			{
				if (emyChoice[i] == playerCard[i])
				{
					cout << "Hit,";
					hit++;
				}
				else
				{
					cout << "Blow,";
				}
			}
			//全て当たっていたらループ終了
			cout << "\n";
			if (hit == 3)
			{
				cout << "3Hit!!\n";
				break;
			}
			//trunフラグをtrueにする（プレイヤーのターン）
			cout << "\n";
			trunFlag = true;
		}
	}
	//結果の表示
	if (judgementFlag)
	{
		cout << "PLAYER WINNER\n";
	}
	else
	{
		cout << "ENEMY WINNER\n";
	}

	return 0;
}