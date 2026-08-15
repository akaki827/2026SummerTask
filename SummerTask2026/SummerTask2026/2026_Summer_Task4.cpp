#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int main(void)
{
	//定数
	const int MAXMASS = 9;
	const int MAXROUND = 8;
	const bool USINGFLAG = true;
	const int DICEMAX = 6;

	//変数
	int mass[MAXMASS];
	int player,player2;
	int playerinput,enemyinput;
	int enemy,enemy2;
	int playertotal,enemytotal;
	int playerpoint = 0, enemypoint = 0;

	//ゲームループ
	for (int i = 0;i < MAXROUND;i++)
	{
		//乱数の初期化
		srand((unsigned int)time(nullptr));

		//乱数の設定
		player = rand() % DICEMAX, player2 = rand() % DICEMAX;
		enemy = rand() % DICEMAX, enemy2 = rand() % DICEMAX;

		//total
		playertotal = player + player2;
		enemytotal = enemy + enemy2;

		//表示
		cout << "player:\nfairstdice " << player << "\nseconddice " << player2 << "\ntotal " << playertotal
			<< "\nenemy:\nfirstdice " << enemy << "\nseconddice " << enemy2 << "\ntotal " << enemytotal << "\n";

		//入力チェック
		while (true)
		{
			if (mass[player] == USINGFLAG && mass[player2] == USINGFLAG && mass[playertotal] == USINGFLAG)
			{
				cout << "You can't do a thing.\n";
				break;
			}

			cin >> playerinput;

			if ((player == playerinput && mass[player] != USINGFLAG) or
				(player2 == playerinput && mass[player2] != USINGFLAG) or
				(playertotal == playerinput && mass[playertotal] != USINGFLAG))break;

			else cout << "notnum \n";
		}
		//プレイヤーのマス判定
		if (player == playerinput)mass[player] = USINGFLAG,playerpoint++;
		else if (player2 == playerinput)mass[player2] = USINGFLAG,playerpoint++;
		else if (playertotal == playerinput)mass[playertotal] = USINGFLAG,playerpoint++;

		//敵のマス判定
		while (true)
		{
			enemyinput = rand() % DICEMAX;

			if (mass[enemy] == USINGFLAG && mass[enemy2] == USINGFLAG && mass[enemytotal] == USINGFLAG)
			{
				cout << "enemy can't do a thing.\n";
				break;
			}
			else if (enemy == enemyinput && mass[enemy] != USINGFLAG)
			{
				mass[enemy] = USINGFLAG;
				enemypoint++;
				break;
			}
			else if (enemy2 == enemyinput && mass[enemy2] != USINGFLAG)
			{
				mass[enemy2] = USINGFLAG;
				enemypoint++;
				break;
			}
			else if (enemytotal == enemyinput && mass[enemytotal] != USINGFLAG)
			{
				mass[enemytotal] = USINGFLAG;
				enemypoint++;
				break;
			}
		}
		cout << "enemyinput " << enemyinput << endl;
	}
	//結果の表示
	if (playerpoint > enemypoint)cout << "プレイヤーのポイントは" << playerpoint << "\n エネミーのポイントは " << enemypoint << "playerwin！！ ";
	if (playerpoint < enemypoint)cout << "プレイヤーのポイントは" << playerpoint << "\n エネミーのポイントは " << enemypoint << "enemywin！！ ";

	return 0;
}