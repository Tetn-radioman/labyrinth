#include <iostream>
#include <thread>
#include <chrono>

#include <stdlib.h>   //!!!!!!!!!!!!!!!!!!!!!!!!!Лабиринт 1.3.1.5 !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!//
#include <string>

#include <windows.h>

#pragma comment(lib, "winmm.lib")

using namespace std;


string pixel[64], x, r = "Y";
string naz = "RRRRRRRRRRRRRRRRR   77777777777777777777BBBBBBBBBBBBBBBBB   DDDDDDDDDDDDD       \nR::::::::::::::::R  7::::::::::::::::::7B::::::::::::::::B  D::::::::::::DDD     \nR::::::RRRRRR:::::R 7::::::::::::::::::7B::::::BBBBBB:::::B D:::::::::::::::DD   \nRR:::::R     R:::::R777777777777:::::::7BB:::::B     B:::::BDDD:::::DDDDD:::::D  \n  R::::R     R:::::R           7::::::7   B::::B     B:::::B  D:::::D    D:::::D \n  R::::R     R:::::R          7::::::7    B::::B     B:::::B  D:::::D     D:::::D\n  R::::RRRRRR:::::R          7::::::7     B::::BBBBBB:::::B   D:::::D     D:::::D\n  R:::::::::::::RR          7::::::7      B:::::::::::::BB    D:::::D     D:::::D\n  R::::RRRRRR:::::R        7::::::7       B::::BBBBBB:::::B   D:::::D     D:::::D\n  R::::R     R:::::R      7::::::7        B::::B     B:::::B  D:::::D     D:::::D\n  R::::R     R:::::R     7::::::7         B::::B     B:::::B  D:::::D     D:::::D\n  R::::R     R:::::R    7::::::7          B::::B     B:::::B  D:::::D    D:::::D \nRR:::::R     R:::::R   7::::::7         BB:::::BBBBBB::::::BDDD:::::DDDDD:::::D  \nR::::::R     R:::::R  7::::::7          B:::::::::::::::::B D:::::::::::::::DD   \nR::::::R     R:::::R 7::::::7           B::::::::::::::::B  D::::::::::::DDD     \nRRRRRRRR     RRRRRRR77777777            BBBBBBBBBBBBBBBBB   DDDDDDDDDDDDD        \n";

void wait(float seconds) // доступно для int. Если сделать double seconds(будет работать, но есть варнинг)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}

//--- звуки
 
//фоновый звук
void backS()
{
		mciSendString(L"play background_sound.mp3 repeat", NULL, 0, NULL);
}
//заставка
void ScreenS()
{	
		mciSendString(L"play Screensaver.mp3 wait", NULL, 0, NULL);
}
//передвижение
void mov()
{
	mciSendString(L"play M.mp3 wait", NULL, 0, NULL);
}
//мина
void BOMB()
{
	mciSendString(L"play B.mp3 wait", NULL, 0, NULL);
}
//капкан
void TRAP()
{
	mciSendString(L"play T.mp3 wait", NULL, 0, NULL);
}
//победа
void WIN()
{
	mciSendString(L"play W.mp3 wait", NULL, 0, NULL);
}
//проигрыш
void GO()
{
	mciSendString(L"play GO.mp3 wait", NULL, 0, NULL);
}
//Эффект двойного здоровья
void HPP()
{
	mciSendString(L"play HP.mp3 wait", NULL, 0, NULL);
}

//---

void output()//вывод изображения
{
	system("cls");
	cout << "##########\n"
		<< "#" << pixel[0] << pixel[1] << pixel[2] << pixel[3] << pixel[4] << pixel[5] << pixel[6] << pixel[7] << "#" << endl
		<< "#" << pixel[8] << pixel[9] << pixel[10] << pixel[11] << pixel[12] << pixel[13] << pixel[14] << pixel[15] << "#" << endl
		<< "#" << pixel[16] << pixel[17] << pixel[18] << pixel[19] << pixel[20] << pixel[21] << pixel[22] << pixel[23] << "#" << endl
		<< "#" << pixel[24] << pixel[25] << pixel[26] << pixel[27] << pixel[28] << pixel[29] << pixel[30] << pixel[31] << "#" << endl
		<< "#" << pixel[32] << pixel[33] << pixel[34] << pixel[35] << pixel[36] << pixel[37] << pixel[38] << pixel[39] << "#" << endl
		<< "#" << pixel[40] << pixel[41] << pixel[42] << pixel[43] << pixel[44] << pixel[45] << pixel[46] << pixel[47] << "#" << endl
		<< "#" << pixel[48] << pixel[49] << pixel[50] << pixel[51] << pixel[52] << pixel[53] << pixel[54] << pixel[55] << "#" << endl
		<< "#" << pixel[56] << pixel[57] << pixel[58] << pixel[59] << pixel[60] << pixel[61] << pixel[62] << pixel[63] << "#" << endl
		<< "##########\n";
}

int main()
{
	thread th(backS);// выполняем в отдельном потоке звук
	th.detach(); // не привязываем к программе 
	
	cout << naz;

	ScreenS();
	wait(2);
	system("cls");
	while (r == "Y") {
		int p_p = 2, f = 1, HP = 2, c = 0, cc = 0, acc = 1, bcc = 1, ccc = 1, amc = 1, bmc = 1, cmc = 1, aHP = 1, bHP = 1, dmc = 0, dcc = 0, xx = 1;
		//карта
		pixel[0] = "#";
		pixel[1] = "#";
		pixel[2] = "@";
		pixel[3] = "#";
		pixel[4] = "#";
		pixel[5] = " ";
		pixel[6] = " ";
		pixel[7] = " ";
		//2
		pixel[8] = "#";
		pixel[9] = " ";
		pixel[10] = " ";
		pixel[11] = " ";
		pixel[12] = "#";
		pixel[13] = " ";
		pixel[14] = "#";
		pixel[15] = " ";
		//3
		pixel[16] = "#";
		pixel[17] = " ";
		pixel[18] = "#";
		pixel[19] = " ";
		pixel[20] = "#";
		pixel[21] = " ";
		pixel[22] = "#";
		pixel[23] = "#";
		//4
		pixel[24] = " ";
		pixel[25] = " ";
		pixel[26] = "#";
		pixel[27] = " ";
		pixel[28] = " ";
		pixel[29] = " ";
		pixel[30] = " ";
		pixel[31] = " ";
		//5
		pixel[32] = " ";
		pixel[33] = "#";
		pixel[34] = "#";
		pixel[35] = " ";
		pixel[36] = "#";
		pixel[37] = " ";
		pixel[38] = " ";
		pixel[39] = "#";
		//6
		pixel[40] = " ";
		pixel[41] = " ";
		pixel[42] = " ";
		pixel[43] = " ";
		pixel[44] = " ";
		pixel[45] = " ";
		pixel[46] = " ";
		pixel[47] = "#";
		//7
		pixel[48] = " ";
		pixel[49] = "#";
		pixel[50] = "#";
		pixel[51] = "#";
		pixel[52] = " ";
		pixel[53] = "#";
		pixel[54] = " ";
		pixel[55] = "#";
		//8
		pixel[56] = " ";
		pixel[57] = " ";
		pixel[58] = " ";
		pixel[59] = " ";
		pixel[60] = " ";
		pixel[61] = "#";
		pixel[62] = "F";
		pixel[63] = "#";
		//Кадр
		output();
		while (f == 1) {//сама игра
			cout << "your health:" << HP << "/2\n";
			if (HP > 2) {
				cout << "double health effect\n";
			}
			else {
				cout << "no effects\n";
			}
			cout << "Please enter your move:";
			cin >> x;
			if (HP <= 0) {
				f = 0;
			}
			if (f == 0) {
				x = "e";
			}
			thread th2(mov);// выполняем в отдельном потоке звук
			th2.detach(); 
			
			switch (p_p) {//ходы
			case 2:
				if (x == "s") {
					pixel[2] = " ";
					pixel[10] = "@";
					p_p = 10;
				}
				break;
			case 5:
				if (x == "d") {
					pixel[5] = " ";
					pixel[6] = "@";
					p_p = 6;
				}
				if (x == "s") {
					pixel[5] = " ";
					pixel[13] = "@";
					p_p = 13;
				}
				break;
			case 6:
				if (x == "a") {
					pixel[6] = " ";
					pixel[5] = "@";
					p_p = 5;
				}
				if (x == "d") {
					pixel[6] = " ";
					pixel[7] = "@";
					p_p = 7;
				}
				break;
			case 9:
				if (x == "d") {
					pixel[9] = " ";
					pixel[10] = "@";
					p_p = 10;
				}
				if (x == "s") {
					pixel[9] = " ";
					pixel[17] = "@";
					p_p = 17;
				}
				break;
			case 10:
				if (x == "w") {
					pixel[10] = " ";
					pixel[2] = "@";
					p_p = 2;
				}
				if (x == "a") {
					pixel[10] = " ";
					pixel[9] = "@";
					p_p = 9;
				}
				if (x == "d") {
					pixel[10] = " ";
					pixel[11] = "@";
					p_p = 11;
				}
				break;
			case 11:
				if (x == "s") {
					pixel[11] = " ";
					pixel[19] = "@";
					p_p = 19;
				}
				if (x == "a") {
					pixel[11] = " ";
					pixel[10] = "@";
					p_p = 10;
				}
				break;
			case 7:
				if (x == "s") {
					pixel[7] = " ";
					if (bmc == 1) {
						c = 5;
					}
					else {
						pixel[15] = "@";
						p_p = 15;
					}
				}
				if (x == "s") {
					pixel[7] = " ";
					pixel[15] = "@";
					p_p = 15;
				}
				if (x == "a") {
					pixel[7] = " ";
					pixel[6] = "@";
					p_p = 6;
				}
				break;
			case 13:
				if (x == "w") {
					pixel[13] = " ";
					if (aHP == 1) {

						thread th13(HPP);// выполняем в отдельном потоке звук
						th13.detach(); // не привязываем к программе 

						HP = HP + 2;
						aHP = 0;
						dcc = 1;
						dmc = 1;
						pixel[5] = "@";
						p_p = 5;
					}
					else {
						pixel[13] = " ";
						pixel[5] = "@";
						p_p = 5;
					}
				}
				if (x == "s") {
					pixel[13] = " ";
					if (dcc == 1) {
						c = 8;
					}
					else {
						pixel[21] = "@";
						p_p = 21;
					}
				}
				break;
			case 15:
				if (x == "w") {
					pixel[15] = " ";
					pixel[7] = "@";
					p_p = 7;
				}
				break;
			case 17:
				if (x == "w") {
					pixel[17] = " ";
					pixel[9] = "@";
					p_p = 9;
				}
				if (x == "s") {
					pixel[17] = " ";
					if (acc == 1) {
						c = 1;
					}
					else {
						pixel[25] = "@";
						p_p = 25;
					}
				}
				break;
			case 19:
				if (x == "w") {
					pixel[19] = " ";
					pixel[11] = "@";
					p_p = 11;
				}
				if (x == "s") {
					pixel[19] = " ";
					pixel[27] = "@";
					p_p = 27;
				}
				break;
			case 21:
				if (x == "w") {
					pixel[21] = " ";
					pixel[13] = "@";
					p_p = 13;
				}
				if (x == "s") {
					pixel[21] = " ";
					pixel[29] = "@";
					p_p = 29;
				}
				break;
			case 24:
				if (x == "s") {
					pixel[24] = " ";
					pixel[32] = "@";
					p_p = 32;
				}
				if (x == "d") {
					pixel[24] = " ";
					if (acc == 1) {
						c = 1;
					}
					else {
						pixel[25] = "@";
						p_p = 25;
					}
				}
				break;
			case 25:
				if (x == "w") {
					pixel[25] = " ";
					pixel[17] = "@";
					p_p = 17;
				}
				if (x == "a") {
					pixel[25] = " ";
					pixel[24] = "@";
					p_p = 24;
				}
				break;
			case 27:
				if (x == "w") {
					pixel[27] = " ";
					pixel[19] = "@";
					p_p = 19;
				}
				if (x == "d") {
					pixel[27] = " ";
					pixel[28] = "@";
					p_p = 28;
				}
				if (x == "s") {
					pixel[27] = " ";
					if (bcc == 1) {
						c = 2;
					}
					else {
						pixel[35] = "@";
						p_p = 35;
					}
				}
				break;
			case 28:
				if (x == "a") {
					pixel[28] = " ";
					pixel[27] = "@";
					p_p = 27;
				}
				if (x == "d") {
					pixel[28] = " ";
					pixel[29] = "@";
					p_p = 29;
				}
				break;
			case 29:
				if (x == "w") {
					pixel[29] = " ";
					pixel[21] = "@";
					p_p = 21;
				}
				if (x == "d") {
					pixel[29] = " ";
					pixel[30] = "@";
					p_p = 30;
				}
				if (x == "a") {
					pixel[29] = " ";
					pixel[28] = "@";
					p_p = 28;
				}
				if (x == "s") {
					pixel[29] = " ";
					pixel[37] = "@";
					p_p = 37;
				}
				break;
			case 30:
				if (x == "d") {
					pixel[30] = " ";
					pixel[31] = "@";
					p_p = 31;
				}
				if (x == "a") {
					pixel[30] = " ";
					pixel[29] = "@";
					p_p = 29;
				}
				if (x == "s") {
					pixel[30] = " ";
					pixel[38] = "@";
					p_p = 38;
				}
				break;
			case 31:
				if (x == "a") {
					pixel[31] = " ";
					pixel[30] = "@";
					p_p = 30;
				}
				break;
			case 32:
				if (x == "w") {
					pixel[32] = " ";
					pixel[24] = "@";
					p_p = 24;
				}
				if (x == "s") {
					pixel[32] = " ";
					pixel[40] = "@";
					p_p = 40;
				}
				break;
			case 35:
				if (x == "w") {
					pixel[35] = " ";
					pixel[27] = "@";
					p_p = 27;
				}
				if (x == "s") {
					pixel[35] = " ";
					if (cmc == 1) {
						c = 6;
					}
					else {
						pixel[43] = "@";
						p_p = 43;
					}
				}
				break;
			case 37:
				if (x == "w") {
					pixel[37] = " ";
					pixel[29] = "@";
					p_p = 29;
				}
				if (x == "d") {
					pixel[37] = " ";
					pixel[38] = "@";
					p_p = 38;
				}
				if (x == "s") {
					pixel[37] = " ";
					pixel[45] = "@";
					p_p = 45;
				}
				break;
			case 38:
				if (x == "w") {
					pixel[38] = " ";
					pixel[30] = "@";
					p_p = 30;
				}
				if (x == "a") {
					pixel[38] = " ";
					pixel[37] = "@";
					p_p = 37;
				}
				if (x == "s") {
					pixel[45] = " ";
					if (amc == 1) {
						c = 4;
					}
					else {
						pixel[46] = "@";
						p_p = 46;
					}
				}
				break;
			case 40:
				if (x == "w") {
					pixel[40] = " ";
					pixel[32] = "@";
					p_p = 32;
				}
				if (x == "d") {
					pixel[40] = " ";
					pixel[41] = "@";
					p_p = 41;
				}
				if (x == "s") {
					pixel[40] = " ";
					pixel[48] = "@";
					p_p = 48;
				}
				break;
			case 41:
				if (x == "a") {
					pixel[41] = " ";
					pixel[40] = "@";
					p_p = 40;
				}
				if (x == "d") {
					pixel[41] = " ";
					if (bHP == 1) {

						thread th15(HPP);// выполняем в отдельном потоке звук
						th15.detach(); // не привязываем к программе 

						HP = HP + 2;
						bHP = 0;
						pixel[42] = "@";
						p_p = 42;
					}
					else {
						pixel[41] = " ";
						pixel[42] = "@";
						p_p = 42;
					}
				}
				break;
			case 42:
				if (x == "d") {
					pixel[42] = " ";
					if (cmc == 1) {
						c = 6;
					}
					else {
						pixel[43] = "@";
						p_p = 43;
					}
				}
				if (x == "a") {
					pixel[42] = " ";
					pixel[41] = "@";
					p_p = 41;
				}
				break;
			case 43:
				if (x == "w") {
					pixel[43] = " ";
					if (bcc == 1) {
						c = 2;
					}
					else {
						pixel[35] = "@";
						p_p = 35;
					}
				}
				if (x == "a") {
					pixel[41] = " ";
					if (bHP == 1) {

						thread th14(HPP);// выполняем в отдельном потоке звук
						th14.detach(); // не привязываем к программе 

						HP = HP + 2;
						bHP = 0;
						pixel[42] = "@";
						p_p = 42;
					}
					else {
						pixel[41] = " ";
						pixel[42] = "@";
						p_p = 42;
					}
				}
				if (x == "d") {
					pixel[43] = " ";
					pixel[44] = "@";
					p_p = 44;
				}
				break;
			case 44:
				if (x == "a") {
					pixel[44] = " ";
					if (cmc == 1) {
						c = 6;
					}
					else {
						pixel[43] = "@";
						p_p = 43;
					}
				}
				if (x == "d") {
					pixel[44] = " ";
					pixel[45] = "@";
					p_p = 45;
				}
				if (x == "s") {
					pixel[44] = " ";
					pixel[52] = "@";
					p_p = 52;
				}
				break;
			case 45:
				if (x == "w") {
					pixel[45] = " ";
					pixel[37] = "@";
					p_p = 37;
				}
				if (x == "a") {
					pixel[45] = " ";
					pixel[44] = "@";
					p_p = 44;
				}
				if (x == "d") {
					pixel[45] = " ";
					if (amc == 1) {
						c = 4;
					}
					else {
						pixel[46] = "@";
						p_p = 46;
					}
				}
				break;
			case 46:
				if (x == "w") {
					pixel[46] = " ";
					pixel[38] = "@";
					p_p = 38;
				}
				if (x == "a") {
					pixel[46] = " ";
					pixel[45] = "@";
					p_p = 45;
				}
				if (x == "s") {
					pixel[46] = " ";
					if (ccc == 1) {
						c = 3;
					}
					else {
						pixel[54] = "@";
						p_p = 54;
					}
				}
				break;
			case 48:
				if (x == "w") {
					pixel[48] = " ";
					pixel[40] = "@";
					p_p = 40;
				}
				if (x == "s") {
					pixel[48] = " ";
					pixel[56] = "@";
					p_p = 56;
				}
				break;
			case 52:
				if (x == "w") {
					pixel[52] = " ";
					pixel[44] = "@";
					p_p = 44;
				}
				if (x == "s") {
					pixel[52] = " ";
					pixel[60] = "@";
					p_p = 60;
				}
				break;
			case 54:
				if (x == "w") {
					pixel[54] = " ";
					pixel[46] = "@";
					p_p = 46;
				}
				if (x == "s") {//победа
					pixel[54] = " ";
					pixel[62] = "@";
					p_p = 62;
					f = 2;
				}
				break;
			case 56:
				if (x == "w") {
					pixel[56] = " ";
					pixel[48] = "@";
					p_p = 48;
				}
				if (x == "d") {
					pixel[56] = " ";
					pixel[57] = "@";
					p_p = 57;
				}
				break;
			case 57:
				if (x == "a") {
					pixel[57] = " ";
					pixel[56] = "@";
					p_p = 56;
				}
				if (x == "d") {
					pixel[57] = " ";
					pixel[58] = "@";
					p_p = 58;
				}
				break;
			case 58:
				if (x == "a") {
					pixel[58] = " ";
					pixel[57] = "@";
					p_p = 57;
				}
				if (x == "d") {
					pixel[58] = " ";
					if (dmc == 1) {
						c = 7;
					}
					else {
						pixel[59] = "@";
						p_p = 59;
					}
				}
				if (x == "d") {
					pixel[58] = " ";
					pixel[59] = "@";
					p_p = 59;
				}
				break;
			case 59:
				if (x == "a") {
					pixel[59] = " ";
					pixel[58] = "@";
					p_p = 58;
				}
				if (x == "d") {
					pixel[59] = " ";
					pixel[60] = "@";
					p_p = 60;
				}
				break;
			case 60:
				if (x == "w") {
					pixel[60] = " ";
					pixel[52] = "@";
					p_p = 52;
				}
				if (x == "a") {
					pixel[60] = " ";
					if (dmc == 1) {
						c = 7;
					}
					else {
						pixel[59] = "@";
						p_p = 59;
					}
				}
				break;
			}
			output();
			switch (c) {//спец функции
			case 1://+
				while (c == 1) {

					thread th3(TRAP);// выполняем в отдельном потоке звук
					th3.detach(); // не привязываем к программе 

					if (cc == 5) {
						pixel[25] = "@";
						pixel[24] = " ";
						pixel[26] = "#";
						pixel[17] = " ";
						pixel[33] = "#";
						c = 0;
						wait(0.5);
					}
					if (cc == 4) {
						pixel[17] = "|";
						pixel[33] = "|";
						pixel[24] = "-";
						pixel[26] = "-";
						pixel[25] = "@";
						cc = 5;
						wait(0.5);
					}
					if (cc == 3) {
						pixel[25] = "+";
						pixel[24] = " ";
						pixel[26] = "#";
						pixel[17] = " ";
						pixel[33] = "#";
						cc = 4;
						wait(0.5);
					}
					if (cc == 2) {
						pixel[17] = "|";
						pixel[33] = "|";
						cc = 3;
						wait(0.5);
					}
					if (cc == 1) {
						pixel[24] = "-";
						pixel[26] = "-";
						cc = 2;
						wait(0.5);
					}
					if (cc == 0) {
						pixel[25] = "@";
						cc = 1;
						wait(0.5);
					}
					output();
					cout << "trap" << endl;
				}
				cc = 0;
				p_p = 25;
				acc = 0;
				HP = HP - 1;
				break;
			case 2://+
				while (c == 2) {

					thread th4(TRAP);// выполняем в отдельном потоке звук
					th4.detach(); // не привязываем к программе 

					if (cc == 5) {
						pixel[35] = "@";
						pixel[43] = " ";
						pixel[34] = "#";
						pixel[27] = " ";
						pixel[36] = "#";
						c = 0;
						wait(0.5);
					}
					if (cc == 4) {
						pixel[27] = "|";
						pixel[43] = "|";
						pixel[34] = "-";
						pixel[36] = "-";
						pixel[35] = "@";
						cc = 5;
						wait(0.5);
					}
					if (cc == 3) {
						pixel[35] = "+";
						pixel[43] = " ";
						pixel[34] = "#";
						pixel[27] = " ";
						pixel[36] = "#";
						cc = 4;
						wait(0.5);
					}
					if (cc == 2) {
						pixel[27] = "|";
						pixel[43] = "|";
						cc = 3;
						wait(0.5);
					}
					if (cc == 1) {
						pixel[34] = "-";
						pixel[36] = "-";
						cc = 2;
						wait(0.5);
					}
					if (cc == 0) {
						pixel[35] = "@";
						cc = 1;
						wait(0.5);
					}
					output();
					cout << "trap" << endl;
				}
				cc = 0;
				p_p = 35;
				bcc = 0;
				HP = HP - 1;
				break;
			case 3://+
				while (c == 3) {

					thread th5(TRAP);// выполняем в отдельном потоке звук
					th5.detach(); // не привязываем к программе 

					if (cc == 5) {
						pixel[54] = "@";
						pixel[46] = " ";
						pixel[53] = "#";
						pixel[62] = "F";
						pixel[55] = "#";
						c = 0;
						wait(0.5);
					}
					if (cc == 4) {
						pixel[62] = "|";
						pixel[46] = "|";
						pixel[53] = "-";
						pixel[55] = "-";
						pixel[54] = "@";
						cc = 5;
						wait(0.5);
					}
					if (cc == 3) {
						pixel[54] = "+";
						pixel[46] = " ";
						pixel[53] = "#";
						pixel[62] = "F";
						pixel[55] = "#";
						cc = 4;
						wait(0.5);
					}
					if (cc == 2) {
						pixel[62] = "|";
						pixel[46] = "|";
						cc = 3;
						wait(0.5);
					}
					if (cc == 1) {
						pixel[53] = "-";
						pixel[55] = "-";
						cc = 2;
						wait(0.5);
					}
					if (cc == 0) {
						pixel[54] = "@";
						cc = 1;
						wait(0.5);
					}
					output();
					cout << "trap" << endl;
				}
				cc = 0;
				p_p = 54;
				ccc = 0;
				HP--;
				break;
			case 4://+
				while (c == 4) {

					thread th6(BOMB);// выполняем в отдельном потоке звук
					th6.detach(); // не привязываем к программе 

					if (cc == 5) {
						pixel[37] = " ";
						pixel[39] = "#";
						pixel[53] = "#";
						pixel[55] = "#";
						pixel[46] = "-";
						pixel[38] = " ";
						pixel[45] = " ";
						pixel[47] = "#";
						pixel[54] = " ";
						c = 0;
						wait(0.4);
					}
					if (cc == 4) {
						pixel[37] = " ";
						pixel[39] = " ";
						pixel[53] = " ";
						pixel[55] = " ";
						pixel[46] = "+";
						pixel[38] = "-";
						pixel[45] = "-";
						pixel[47] = "-";
						pixel[54] = "-";
						cc = 5;
						wait(0.4);
					}
					if (cc == 3) {
						pixel[38] = "+";
						pixel[45] = "+";
						pixel[47] = "+";
						pixel[54] = "+";
						pixel[37] = "-";
						pixel[39] = "-";
						pixel[53] = "-";
						pixel[55] = "-";
						cc = 4;
						wait(0.4);
					}
					if (cc == 2) {
						pixel[37] = "+";
						pixel[39] = "+";
						pixel[53] = "+";
						pixel[55] = "+";
						cc = 3;
						wait(0.4);
					}
					if (cc == 1) {
						pixel[37] = "*";
						pixel[39] = "*";
						pixel[53] = "*";
						pixel[55] = "*";
						cc = 2;
						wait(0.4);
					}
					if (cc == 0) {
						pixel[46] = "*";
						pixel[38] = "*";
						pixel[45] = "*";
						pixel[47] = "*";
						pixel[54] = "*";
						cc = 1;
						wait(0.4);
					}
					output();
					cout << "bomb" << endl;
				}
				cc = 0;
				p_p = 46;
				amc = 0;
				HP = HP - 2;
				break;
			case 5://+
				while (c == 5) {

					thread th7(BOMB);// выполняем в отдельном потоке звук
					th7.detach(); // не привязываем к программе 

					if (cc == 5) {
						pixel[7] = " ";
						pixel[14] = "#";
						pixel[23] = "#";
						pixel[15] = "-";

						c = 0;
						wait(0.4);
					}
					if (cc == 4) {
						pixel[6] = " ";
						pixel[22] = "#";
						pixel[7] = "-";
						pixel[14] = "-";
						pixel[23] = "-";
						pixel[15] = "+";
						cc = 5;
						wait(0.4);
					}
					if (cc == 3) {
						pixel[6] = "-";
						pixel[22] = "-";
						pixel[7] = "+";
						pixel[14] = "+";
						pixel[23] = "+";
						cc = 4;
						wait(0.4);
					}
					if (cc == 2) {
						pixel[6] = "+";
						pixel[22] = "+";
						cc = 3;
						wait(0.4);
					}
					if (cc == 1) {
						pixel[6] = "*";
						pixel[22] = "*";

						cc = 2;
						wait(0.4);
					}
					if (cc == 0) {
						pixel[7] = "*";
						pixel[15] = "*";
						pixel[14] = "*";
						pixel[23] = "*";
						cc = 1;
						wait(0.4);
					}
					output();
					cout << "bomb" << endl;
				}
				cc = 0;
				p_p = 15;
				bmc = 0;
				HP = HP - 2;
				break;
			case 6://+
				while (c == 6) {

					thread th8(BOMB);// выполняем в отдельном потоке звук
					th8.detach(); // не привязываем к программе 

					if (cc == 5) {
						pixel[35] = " ";
						pixel[42] = " ";
						pixel[44] = " ";
						pixel[51] = "#";
						pixel[43] = "-";
						c = 0;
						wait(0.4);
					}
					if (cc == 4) {
						pixel[43] = "+";
						pixel[34] = "#";
						pixel[36] = "#";
						pixel[50] = "#";
						pixel[52] = " ";
						pixel[35] = "-";
						pixel[42] = "-";
						pixel[44] = "-";
						pixel[51] = "-";
						cc = 5;
						wait(0.4);
					}
					if (cc == 3) {
						pixel[34] = "-";
						pixel[36] = "-";
						pixel[50] = "-";
						pixel[52] = "-";
						pixel[35] = "+";
						pixel[42] = "+";
						pixel[44] = "+";
						pixel[51] = "+";
						cc = 4;
						wait(0.4);
					}
					if (cc == 2) {
						pixel[34] = "+";
						pixel[36] = "+";
						pixel[50] = "+";
						pixel[52] = "+";
						cc = 3;
						wait(0.4);
					}
					if (cc == 1) {
						pixel[34] = "*";
						pixel[36] = "*";
						pixel[50] = "*";
						pixel[52] = "*";
						cc = 2;
						wait(0.4);
					}
					if (cc == 0) {
						pixel[43] = "*";
						pixel[35] = "*";
						pixel[42] = "*";
						pixel[44] = "*";
						pixel[51] = "*";
						cc = 1;
						wait(0.4);
					}
					output();
					cout << "bomb" << endl;
				}
				cc = 0;
				p_p = 43;
				cmc = 0;
				HP = HP - 2;
				break;
				//работуют после активации
			case 7://+
				while (c == 7) {

					thread th9(BOMB);// выполняем в отдельном потоке звук
					th9.detach(); // не привязываем к программе 

					if (cc == 5) {
						pixel[58] = " ";
						pixel[51] = "#";
						pixel[60] = " ";
						pixel[59] = "-";

						c = 0;
						wait(0.4);
					}
					if (cc == 4) {
						pixel[50] = "#";
						pixel[52] = " ";
						pixel[58] = "-";
						pixel[51] = "-";
						pixel[60] = "-";
						pixel[59] = "+";
						cc = 5;
						wait(0.4);
					}
					if (cc == 3) {
						pixel[50] = "-";
						pixel[52] = "-";
						pixel[51] = "+";
						pixel[58] = "+";
						pixel[60] = "+";
						cc = 4;
						wait(0.4);
					}
					if (cc == 2) {
						pixel[50] = "+";
						pixel[52] = "+";
						cc = 3;
						wait(0.4);
					}
					if (cc == 1) {
						pixel[50] = "*";
						pixel[52] = "*";

						cc = 2;
						wait(0.4);
					}
					if (cc == 0) {
						pixel[59] = "*";
						pixel[51] = "*";
						pixel[58] = "*";
						pixel[60] = "*";
						cc = 1;
						wait(0.4);
					}
					output();
					cout << "bomb" << endl;
				}
				cc = 0;
				p_p = 59;
				dmc = 0;
				HP = HP - 2;
				break;
			case 8://+
				while (c == 8) {

					thread th10(TRAP);// выполняем в отдельном потоке звук
					th10.detach(); // не привязываем к программе 

					if (cc == 5) {
						pixel[13] = " ";
						pixel[29] = " ";
						pixel[20] = "#";
						pixel[22] = "#";
						c = 0;
						wait(0.5);
					}
					if (cc == 4) {
						pixel[20] = "-";
						pixel[22] = "-";
						pixel[13] = "|";
						pixel[29] = "|";
						pixel[21] = "@";
						cc = 5;
						wait(0.5);
					}
					if (cc == 3) {
						pixel[21] = "+";
						pixel[13] = " ";
						pixel[29] = " ";
						pixel[20] = "#";
						pixel[22] = "#";
						cc = 4;
						wait(0.5);
					}
					if (cc == 2) {
						pixel[13] = "|";
						pixel[29] = "|";
						cc = 3;
						wait(0.5);
					}
					if (cc == 1) {
						pixel[20] = "-";
						pixel[22] = "-";
						cc = 2;
						wait(0.5);
					}
					if (cc == 0) {
						pixel[21] = "@";
						cc = 1;
						wait(0.5);
					}
					output();
					cout << "trap" << endl;
				}
				cc = 0;
				p_p = 21;
				dcc = 0;
				HP--;
				break;
			}
		}
		if (f == 2) {//победил
			system("cls");
			//Y
			cout << "__   __\n\\ \\ / /\n \\ V / \n  \\ /  \n  | |  \n  \\_/  ";
			wait(0.7);
			system("cls");
			//Yo
			cout << "__   __    \n\\ \\ / /    \n \\ V /___  \n  \\ // _ \\ \n  | | (_) |\n  \\_/\\___/ ";
			wait(0.7);
			system("cls");
			//You
			cout << "__   __          \n\\ \\ / /          \n \\ V /___  _   _ \n  \\ // _ \\| | | |\n  | | (_) | |_| |\n  \\_/\\___/ \\__,_|";
			wait(0.7);
			system("cls");
			//You win!

			thread th11(WIN);// выполняем в отдельном потоке звук
			th11.detach(); // не привязываем к программе 

			cout << "__   __                     _         _ \n\\ \\ / /                    (_)       | |\n \\ V /___  _   _  __      ___ _ __   | |\n  \\ // _ \\| | | | \\ \\ /\\ / / | '_ \\  | |\n  | | (_) | |_| |  \\ V  V /| | | | | |_|\n  \\_/\\___/ \\__,_|   \\_/\\_/ |_|_| |_| (_)\n";
		}
		if (f == 0) {//проиграл
			system("cls");
			//Y
			cout << "__   __\n\\ \\ / /\n \\ V / \n  \\ /  \n  | |  \n  \\_/  ";
			wait(0.7);
			system("cls");
			//Yo
			cout << "__   __    \n\\ \\ / /    \n \\ V /___  \n  \\ // _ \\ \n  | | (_) |\n  \\_/\\___/ ";
			wait(0.7);
			system("cls");
			//You
			cout << "__   __          \n\\ \\ / /          \n \\ V /___  _   _ \n  \\ // _ \\| | | |\n  | | (_) | |_| |\n  \\_/\\___/ \\__,_|";
			wait(0.7);
			system("cls");

			thread th12(GO);// выполняем в отдельном потоке звук
			th12.detach(); // не привязываем к программе 

			//You lose!
			cout << "__   __            _                  _ \n\\ \\ / /           | |                | |\n \\ V /___  _   _  | | ___  ___  ___  | |\n  \\ // _ \\| | | | | |/ _ \\/ __|/ _ \\ | |\n  | | (_) | |_| | | | (_) \\__ \\  __/ |_|\n  \\_/\\___/ \\__,_| |_|\\___/|___/\\___| (_)\n";
		}
		
		cout << "Start the game again?\nEnter (Y/N):";
		cin >> r;
	}
}