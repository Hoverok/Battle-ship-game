//this was my first crack at classes and objects
//a fully working BattleShip game
//NPC's ships are set automatically
//player sets ships himself at the start of the program

#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>                                     // rand() funkcijos
#include <ctime>										//  srand(time(0))
using namespace std;




class ship {											// zaidejui matomi laukai
private:
	char p1[10][10];                                   // zaidejo laivai
	char p2[10][10];
	// s- 4x1, m- 3x2, l- 2x3, xl- 1x4
	int s1[2][2], s2[2][2], s3[2][2], s4[2][2];                               // visu laivu koordinates (Y X) irasau i dvimacius masyvus, kuriu pirma "eilute" laiko
	int m1[3][2], m2[3][2], m3[3][2];										  // info ar laivas [gyvas/nuskendo][sveikas/suzeistas], kaip 1/0
	int l1[4][2], l2[4][2];
	int xl1[5][2];
	int suzeisti = 0;


public:
	ship(char c, int x) {                                                             //konstruktorius siuncia chara ir int is maino uzpildyti laukus ir pirmos laivu eilutes
		emptyfill(c);
		aliveNhealthy(x);
	}

	void emptyfill(char c) {                                                          //pildo laukus, gauna parametra is konstruktoriaus
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				p1[i][j] = c;
				p2[i][j] = c;
			}
		}
	}

	void aliveNhealthy(int x) {                                                        //pildo laivu masyvu pirma "statuso" eilute
		for (int i = 0; i < 2; i++) {
			s1[0][i] = x;
			s2[0][i] = x;
			s3[0][i] = x;
			s4[0][i] = x;

			m1[0][i] = x;
			m2[0][i] = x;
			m3[0][i] = x;

			l1[0][i] = x;
			l2[0][i] = x;

			xl1[0][i] = x;
		}
	}
	void showfield() {                                                        //rodo p1 lauka
		cout << "                         Player";
		cout << '\n' << "  0 1 2 3 4 5 6 7 8 9           0 1 2 3 4 5 6 7 8 9" << '\n';   //10 + 1 tarpas
		for (int i = 0; i < 10; i++) {
			cout << i << " ";
			for (int j = 0; j < 10; j++) {
				cout << p1[i][j] << " ";
			}
			cout << "          ";                         //10 tarpu
			for (int k = 0; k < 10; k++) {
				cout << p2[i][k] << " ";
			}
			cout << '\n';
		}
		cout << '\n';
	}


	void p1s(int y1, int x1) { p1[y1][x1] = 'O'; }					//  laivai isdesdami p1 lauke



	void sactual(vector <int>& smallcoord) {						// ranka ivesiu kiekvieno small (mazu laivu koord)
		s1[1][0] = smallcoord[0];
		s1[1][1] = smallcoord[1];
		s2[1][0] = smallcoord[2];
		s2[1][1] = smallcoord[3];
		s3[1][0] = smallcoord[4];
		s3[1][1] = smallcoord[5];
		s4[1][0] = smallcoord[6];
		s4[1][1] = smallcoord[7];

		cout << "small ship coordinates:" << s1[1][0] << s1[1][1] << " " << s2[1][0] << s2[1][1] << " " << s3[1][0] << s3[1][1] << " " << s4[1][0] << s4[1][1] << '\n';
	}

	void mactual(vector <int>& mediumcoord) {						// ranka ivesiu kiekvieno medium (vidutinu laivu koord)
		m1[1][0] = mediumcoord[0];
		m1[1][1] = mediumcoord[1];
		m1[2][0] = mediumcoord[2];
		m1[2][1] = mediumcoord[3];

		m2[1][0] = mediumcoord[4];
		m2[1][1] = mediumcoord[5];
		m2[2][0] = mediumcoord[6];
		m2[2][1] = mediumcoord[7];

		m3[1][0] = mediumcoord[8];
		m3[1][1] = mediumcoord[9];
		m3[2][0] = mediumcoord[10];
		m3[2][1] = mediumcoord[11];

		cout << "mid ship coordinates:" << m1[1][0] << m1[1][1] << m1[2][0] << m1[2][1] << " " << m2[1][0] << m2[1][1] << m2[2][0] << m2[2][1] << " ";
		cout << m3[1][0] << m3[1][1] << m3[2][0] << m3[2][1] << '\n';
	}

	void lactual(vector <int>&largecoord) {                           // ranka ivesiu kiekvieno large (dideliu laivu koord)
		l1[1][0] = largecoord[0];
		l1[1][1] = largecoord[1];
		l1[2][0] = largecoord[2];
		l1[2][1] = largecoord[3];
		l1[3][0] = largecoord[4];
		l1[3][1] = largecoord[5];

		l2[1][0] = largecoord[6];
		l2[1][1] = largecoord[7];
		l2[2][0] = largecoord[8];
		l2[2][1] = largecoord[9];
		l2[3][0] = largecoord[10];
		l2[3][1] = largecoord[11];

		cout << "big ship coordinates:" << l1[1][0] << l1[1][1] << l1[2][0] << l1[2][1] << l1[3][0] << l1[3][1] << " ";
		cout << l2[1][0] << l2[1][1] << l2[2][0] << l2[2][1] << l2[3][0] << l2[3][1] << '\n';


	}

	void xlactual(vector <int>&xlargecoord) {                           // ranka ivesiu xl (didziausio laivo koord)
		xl1[1][0] = xlargecoord[0];
		xl1[1][1] = xlargecoord[1];
		xl1[2][0] = xlargecoord[2];
		xl1[2][1] = xlargecoord[3];
		xl1[3][0] = xlargecoord[4];
		xl1[3][1] = xlargecoord[5];
		xl1[4][0] = xlargecoord[6];
		xl1[4][1] = xlargecoord[7];

		cout << "giant coordinates:" << xl1[1][0] << xl1[1][1] << xl1[2][0] << xl1[2][1] << xl1[3][0] << xl1[3][1] << xl1[4][0] << xl1[4][1] << '\n';
	}

	int tiknpcpat(int y, int x) {                 // tikrina ar pataike zaidejas
		if (p1[y][x] == 'O') {                     //pataike!
			p1[y][x] = '#';
			return 1;
		}
		else {
			p1[y][x] = 'X';
			return 0;
		}                            //nepataike
	}

	void updatep2(int y, int x, char c) {
		p2[y][x] = c;
	}



};


class npcship {
private:
	char npc[10][10];                    // npc laukas su laivais
	char npcmato[10][10];
	vector <int> vnoshoot;                // kur npc JAU nereikia saudyti

public:
	npcship(char c) {
		emptyfills(c);

	}
	void emptyfills(char c) {                                                          //pildo laukus, gauna parametra is konstruktoriaus
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				npc[i][j] = c;
				npcmato[i][j] = c;
			}
		}
	}

	void placingnpc(vector <int>& visi) {
		for (int i = 0; i < visi.size(); i += 2) {
			npc[visi[i]][visi[i + 1]] = 'O';                                          // iraso laivus, gauna koordinates is main
		}
	}

	void shownpcfield() {                                      //rodo p1 lauka
		cout << "                     COMPUTER";
		cout << '\n' << "  0 1 2 3 4 5 6 7 8 9           0 1 2 3 4 5 6 7 8 9" << '\n';   //10 + 1 tarpas
		for (int i = 0; i < 10; i++) {
			cout << i << " ";
			for (int j = 0; j < 10; j++) {
				cout << npc[i][j] << " ";
			}
			cout << "          ";                         //10 tarpu
			for (int k = 0; k < 10; k++) {
				cout << npcmato[i][k] << " ";
			}
			cout << '\n';
		}
		cout << '\n';
	}

	int tikzaidpat(int y, int x) {                 // tikrina ar pataike zaidejas


		if (npc[y][x] == 'O') {                     //pataike!   
			npc[y][x] = '#';
			return 1;
		}

		else {
			npc[y][x] = 'X';
			return 0;
		}                            //nepataike
	}

	void npcmatoupdate(int y, int x, char c) {
		npcmato[y][x] = c;
	}


	void jausaude(int y, int x) {
		vnoshoot.push_back(y);
		vnoshoot.push_back(x);
	}

	int argalima(int y, int x) {
		int rez = 1;

		for (int i = 0; i < vnoshoot.size(); i += 2) {
			if (vnoshoot[i] == y && vnoshoot[i + 1] == x) {
				rez = 0;
				break;
			}
			else {
				rez = 1;
			}
		}




		return rez;
	}


};


void npcsaudrand(int *x, int *y, int damage);

void playersmall(ship &ob1, vector <int>& smallcoord) {                       // siunciu rodykles i ob1 smallcoord vektoriaus

	cout << "Input 4 small 1 tile ships cooridnates (Y X format) :" << '\n';      // pasirinkti kur zaidejas stato 4  x 1 laivus
	for (int i = 0; i < 8; i++) {
		cin >> smallcoord[i];
	}
	for (int i = 0; i < 7; i += 2) {
		ob1.p1s(smallcoord[i], smallcoord[i + 1]);
	}

	ob1.showfield();
}


void playermid(ship &ob1, vector <int>& mediumcoord) {
	cout << "Input 3 mid 2 tile ships cooridnates (Y1 X1 Y2 X2 format) :" << '\n';     // pasirinkti kur zaidejas stato 3 x 2 laivus
	for (int i = 0; i < 12; i++) {
		cin >> mediumcoord[i];
	}
	for (int i = 0; i < 11; i += 2) {
		ob1.p1s(mediumcoord[i], mediumcoord[i + 1]);
	}
	ob1.showfield();
}


void playerlarge(ship &ob1, vector <int>& largecoord) {
	cout << "Input 2 big 3 tile ships cooridnates (Y1 X1 Y2 X2 Y3 X3 format):" << '\n';     // pasirinkti kur zaidejas stato 2 x 3 laivus
	for (int i = 0; i < 12; i++) {
		cin >> largecoord[i];
	}
	for (int i = 0; i < 11; i += 2) {
		ob1.p1s(largecoord[i], largecoord[i + 1]);
	}
	ob1.showfield();
}


void playerxlarge(ship &ob1, vector <int>& xlargecoord) {                             // siunciu adresus i ob1 smallcoord vektoriaus

	cout << "Input 1 giant 4 tile ship cooridnates (Y1 X1 Y2 X2 Y3 X3 Y4 X4 format) :" << '\n';      // pasirinkti kur zaidejas stato 1 x 4 laiva
	for (int i = 0; i < 8; i++) {
		cin >> xlargecoord[i];
	}
	for (int i = 0; i < 7; i += 2) {
		ob1.p1s(xlargecoord[i], xlargecoord[i + 1]);
	}
	ob1.showfield();
}


void randgen(int* y, int* x, int check) { // sita funkcija generuoja pradines koordinates npc laivu


	if (check == 1) {                      //jei laivas yra 1 lasteles

		*y = rand() % 9;
		*x = rand() % 9;

	}
	else if (check == 2) {
		*y = rand() % 9;
		if (*y <= 8) {
			*x = rand() % 9;          // yra vietos statyti laiva zemyn
		}
		else *x = rand() % 8;         // nera vietos statyti laiva zemyn, reikia ISITYKINTI kad yra vietos is des puses
	}


	else if (check == 3) {

		*y = rand() % 9;
		if (*y <= 7) {
			*x = rand() % 9;          // yra vietos statyti laiva zemyn
		}
		else *x = rand() % 7;         // nera vietos statyti laiva zemyn, reikia ISITYKINTI kad yra vietos is des puses

	}

	else if (check == 4) {
		*y = rand() % 9;
		if (*y <= 6) {
			*x = rand() % 9;          // yra vietos statyti laiva zemyn
		}
		else *x = rand() % 6;         // nera vietos statyti laiva zemyn, reikia ISITYKINTI kad yra vietos is des puses
	}


}


void updatenothere(vector <int>& nothere, int y, int x) {                 //vectorius laiko koordinates kur npc negali statyti laivu
	for (int i = y - 1; i <= y + 1; i++) {
		for (int j = x - 1; j <= x + 1; j++) {
			nothere.push_back(i);
			nothere.push_back(j);
		}
	}
}


int checkplace(vector <int>& nothere, int y, int x) {                    // pries statant laiva, npc tikrina ar galima ten pastatyti
	int checkers = 1;                                                    // jei galima grazina 1, jei ne 0
	for (int i = 0; i < nothere.size(); i += 2) {
		if (y == nothere[i] && x == nothere[i + 1]) {
			checkers = 0;
		}

	}

	return checkers;
}


void fourplacenpc(int coordY, int coordX, vector <int>& xlargenpc, vector <int>& visi, vector <int>& nothere) {
	randgen(&coordY, &coordX, 4);                                              //start koordinate

	for (int i = 0, j = 0; i < 4; i++, j += 2) {

		if (coordY <= 6) {
			xlargenpc.push_back(coordY + i);
			xlargenpc.push_back(coordX);
			updatenothere(nothere, coordY + i, coordX);
		}
		else if (coordY > 6) {
			xlargenpc.push_back(coordY);
			xlargenpc.push_back(coordX + i);
			updatenothere(nothere, coordY, coordX + i);
		}
		visi.push_back(xlargenpc[j]);
		visi.push_back(xlargenpc[j + 1]);
	}
}


void threeplacenpc(int coordY, int coordX, vector <int>& largenpc, vector <int>& visi, vector <int>& nothere) {

	bool ok(0);
	while (!ok) {
		randgen(&coordY, &coordX, 3);                                        //start koordinate

		for (int i = 0, j = 0; i < 3; i++, j += 2) {

			if (coordY <= 7) {
				largenpc[j] = coordY + i;
				largenpc[j + 1] = coordX;
			}

			else if (coordY > 7) {
				largenpc[j] = coordY;
				largenpc[j + 1] = coordX + i;

			}

		}
		if (checkplace(nothere, largenpc[0], largenpc[1]) == 0 || checkplace(nothere, largenpc[2], largenpc[3]) == 0 || checkplace(nothere, largenpc[4], largenpc[5]) == 0) {
			ok = 0;
		}
		else ok = 1;


		if (ok == 1) {
			for (int i = 0; i < 6; i += 2) {
				updatenothere(nothere, largenpc[i], largenpc[i + 1]);
				visi.push_back(largenpc[i]);
				visi.push_back(largenpc[i + 1]);
			}
		}
	}

}


void twoplacenpc(int coordY, int coordX, vector <int>& mediumnpc, vector <int>& visi, vector <int>& nothere) {
	bool ok(0);
	while (!ok) {
		randgen(&coordY, &coordX, 2);                                        //start koordinate

		for (int i = 0, j = 0; i < 2; i++, j += 2) {

			if (coordY <= 8) {
				mediumnpc[j] = coordY + i;
				mediumnpc[j + 1] = coordX;
			}

			else if (coordY > 8) {
				mediumnpc[j] = coordY;
				mediumnpc[j + 1] = coordX + i;

			}

		}
		if (checkplace(nothere, mediumnpc[0], mediumnpc[1]) == 0 || checkplace(nothere, mediumnpc[2], mediumnpc[3]) == 0) {
			ok = 0;
		}
		else ok = 1;


		if (ok == 1) {
			for (int i = 0; i < 4; i += 2) {
				updatenothere(nothere, mediumnpc[i], mediumnpc[i + 1]);
				visi.push_back(mediumnpc[i]);
				visi.push_back(mediumnpc[i + 1]);
			}
		}
	}



}

void oneplacenpc(int coordY, int coordX, vector <int>& smallnpc, vector <int>& visi, vector <int>& nothere) {
	for (int i = 0; i < 4; i++) {
		randgen(&coordY, &coordX, 1);				               //funkcija atsiuncia 2 random numbers is "randgen"

		if (checkplace(nothere, coordY, coordX) == 1) {		                // checkplace tikrina, ar galima ten padeti laiva, 1- galima, 0- ne
			smallnpc.push_back(coordY);                                            //i mazu laivu vektoriu irasome koordinates
			smallnpc.push_back(coordX);
			updatenothere(nothere, coordY, coordX);                         // irasome i vectoriu laivo koordinates ir salia laivo koordinates kur pastatyti laivo jau negalima    
			visi.push_back(coordY);
			visi.push_back(coordX);
		}

		else i--;                                                            // jeigu tuoje vietoje statyti laivo negalima, npc kartoja bandyma 
	}
}

void zaidsaud(npcship &obnpc, ship &ob1) {
	int x, y, tik = 1;
	while (tik == 1) {
		ob1.showfield();
		obnpc.shownpcfield();
		cout << "Player turn! Enter Y X shooting coordinates:\n";
		cin >> y >> x;
		if (obnpc.tikzaidpat(y, x) == 1) {
			cout << "Player hit!  " << '\n';
			ob1.updatep2(y, x, '#');
		}
		else {
			cout << "Player missed! Computers turn. . . " << '\n';
			ob1.updatep2(y, x, 'X');
			tik = 0;
		}
	}
}


void npcsaud(npcship& obnpc, ship& ob1) {                         //ship& ob1
	int y = 0, x = 0;
	int tik = 1;
	while (tik == 1) {
		npcsaudrand(&y, &x, 0);
		if (obnpc.argalima(y, x) == 1) {                              // tikrinimas ar npc i ta vieta galima saudyti
			cout << "Computer turn! Computer shot coordinates: " << y << " " << x << '\n';
			if (ob1.tiknpcpat(y, x) == 1) {                            //tikrinimas ar npc pataike
				obnpc.npcmatoupdate(y, x, '#');                        //updatina desini langa
				cout << "Computer hit!" << '\n';
			}

			else {
				cout << "NPC nmissed! Player turn \n";
				obnpc.npcmatoupdate(y, x, 'X');
				tik = 0;

			}
			obnpc.jausaude(y, x);                                           //irasome koordinates i vektoriu kur jau saudyta
		}
		else if (obnpc.argalima(y, x) == 0) {
			tik = 1;
		}
	}
}

void npcsaudrand(int *x, int *y, int damage) {                  //generuoja skaicius kur npc saudys
	if (damage == 0) {
		*y = rand() % 9;
		*x = rand() % 9;
	}
}




int main() {
	srand(time(0));
	npcship obnpc('~');													//npc place small ships
	int coordY(0), coordX(0);                                           // i situos funkcijos generuos random skaicius
	vector <int> smallnpc;												// sitie vektoriai laikys npc laivu koordinates
	vector <int> mediumnpc1(6);                                         // visi yra atskyrai isskyrus maziausiu, jie viename vektoriuje
	vector <int> mediumnpc2(6);
	vector <int> mediumnpc3(6);
	vector <int> largenpc1(6);
	vector <int> largenpc2(6);
	vector <int> xlargenpc;
	vector <int> nothere;
	vector <int> visi;

	fourplacenpc(coordY, coordX, xlargenpc, visi, nothere);                      // idedu 4 last laiva

	threeplacenpc(coordY, coordX, largenpc1, visi, nothere);
	threeplacenpc(coordY, coordX, largenpc2, visi, nothere);

	twoplacenpc(coordY, coordX, mediumnpc1, visi, nothere);
	twoplacenpc(coordY, coordX, mediumnpc2, visi, nothere);
	twoplacenpc(coordY, coordX, mediumnpc3, visi, nothere);

	oneplacenpc(coordY, coordX, smallnpc, visi, nothere);

	obnpc.placingnpc(visi);                                                      //pildau kompo lauka
	obnpc.shownpcfield();                                                        //rodom kompo lauka


	vector <int> smallcoord(8);                                           //coord vectoriai padeda irasyti zaidejo koordinates
	vector <int> mediumcoord(12);
	vector <int> largecoord(12);
	vector <int> xlargecoord(8);
	bool vykstazaid(1);
	ship ob1('~', 1);                                                          // nauduosiu ~ zymeti tuscius laukus, 1 kad mano laivai sveiki
	ob1.showfield();														  // ship classes metodas, rodo zaidejui matomus laukus
	cout << "Ship coordinates are in the 0-9 range\n";


	playersmall(ob1, smallcoord);                                         // ne klasine funkcija, pildo 4x1 laivus
	playermid(ob1, mediumcoord);                                          // ne klasine funkcija, pildo 3x2 laivus ir t.t.
	playerlarge(ob1, largecoord);
	playerxlarge(ob1, xlargecoord);

	ob1.sactual(smallcoord);                                              //iraso kiekvieno mazo laivo koordinates i atskyrus masyvus ob1
	ob1.mactual(mediumcoord);
	ob1.lactual(largecoord);
	ob1.xlactual(xlargecoord);



	while (vykstazaid) {
		zaidsaud(obnpc, ob1);
		npcsaud(obnpc, ob1);
	}






	return 0;
}
