#include <iostream>
#include <conio.h>
#include<bitset>
#include<string>
int x[16] = { NULL }, count1[288] = { NULL }, count2[288] = { NULL }, tmp[96] = { NULL }, p[96] = { NULL }, o[96] = { NULL }; // 1.추출할 2진수를 선택하는 값 , 2. 같은수 값 3. 다른수 값 4. 머징 안된 2진수테이블 갯수 4.겹치는 머징 지우는 배열 5.머징된값의 갯수
int num = 0, xl = 0, sw = 0, key = 0, y = 0, b = 0, g = 0, h = 0; //1, 머징 여부 ,2. 선택 수 갯수,3. 최종적으로 머징된 pi 전단계에서 번호비교 후 나오는 pi갯수, 4. 키값 ,5. 페이지 번호 , 6. h는 xl의 값을 넣기위한 변수,7. g는 sw의 값을 넣기위한 변수
int number[16] = { NULL }, re[100][100] = { NULL }, number2[100][9] = { NULL }, number3[100][9] = { NULL }, wp[100][100] = { NULL }, wp1[100][100] = { NULL }, qt[4][7] = { NULL }, ass[60][2] = { NULL }, re1[20][20] = { NULL };
// 1. 선택한 수가 들어가있는배열 2,10. 최종적으로 머징된 pi 전단계에서 번호비교 후 나오는 pi의 번호 3~4 . 머징된 2진수의 번호 5~6. 테이블 그리는 배열 8. 머징된 2진수 테이블 갯수가 들어가있는 배열 9. 최종적으로나온 pi번호가 들어가있는 배열
using namespace std;
#define UP 72
#define DOWN 80
void sel() {                   //배열 출력 및 x값 입력
	for (int i = 0; i < 16; i++)
	{
		if (i < 10) {
			cout << i << ".  ";
		}
		else {
			cout << i << ". ";
		}
		cout << bitset<4>(i) << "  ";
		cin >> x[i];
	}
}
void arr(string binary[4] = { }, string binary1[12] = { }, string binary2[12] = { }, string binary3[4] = { }, string binary4[2] = { }) {// 1갯수로 2진수 묶기
	int c = 0, bin = 0, e = 0;
	for (int i = 0; i < 16; i++) {  //1의 갯수가 0개인 2진수
		if (x[i] == 1) {
			if (i == 0) {
				cout << "1의 갯수 0 \n";
				cout << bitset<4>(i) << "  " << i << endl;
				binary[0] = bitset<4>(i).to_string();
				number[xl] = i;
				xl++;
			}
			if (i == 1 || i == 2 || i == 4 || i == 8)//1의 갯수가 1개인 2진수
			{
				if (bin != 1) {
					cout << "1의 갯수 1 \n";
					bin = 1;
				}
				cout << bitset<4>(i) << "  " << i << endl;
				binary1[c] = bitset<4>(i).to_string();
				number[xl] = i;
				xl++, c++;
			}
		}
	}
	c = 0;
	for (int i = 0; i < 16; i++) { //1의 갯수가 2개인 2진수
		if (x[i] == 1) {
			if (bin != 2) {
				cout << "1의 갯수 2 \n";
				bin = 2;
			}
			if (i == 3 || i == 5 || i == 6 || i == 9 || i == 10 || i == 12) {
				cout << bitset<4>(i) << "  " << i << endl;
				binary2[c] = bitset<4>(i).to_string();
				number[xl] = i;
				xl++, c++;
			}
		}
	}
	c = 0;
	for (int i = 0; i < 16; i++) {
		if (x[i] == 1) {   //1의 갯수가 3개인 2진수
			if (i == 7 || i == 11 || i == 13 || i == 14)
			{
				if (bin != 3) {
					cout << "1의 갯수 3 \n";
					bin = 3;
				}
				cout << bitset<4>(i) << "  " << i << endl;
				binary3[c] = bitset<4>(i).to_string();
				number[xl] = i;
				xl++, c++;
			}
			if (i == 15) { //1의 갯수가 4개인 2진수
				cout << "1의 갯수 4 \n";
				cout << bitset<4>(i) << "  " << i << endl;
				binary4[0] = bitset<4>(i).to_string();
				number[xl] = i;
				xl++;
			}
		}
	}
}
void pi1(string binary[4] = { }, string binary1[12] = { }, string binary2[12] = { }, string binary3[4] = { }, string binary4[2] = { }, string str[24] = { }, string fbinary[4] = { }, string fbinary1[24] = { }, string fbinary2[24] = { }, string fbinary3[4] = { }) { //1차 pi추출
	int bin = 0, min = 0, z = 0, al = 0, ml = 0, bim = 0, bl = 0, bl1 = 0, bl2 = 0, bl3 = 0, c = 0, d1 = 0, d2 = 1, bl4 = 0, t = 0;
	g = xl;
	for (int i = 0; i < 6; i++) {
		if (binary1[i].empty() == 0) { //1의 갯수가 1개인 2진수 갯수
			bl1++;
		}
		if (binary2[i].empty() == 0) { //1의 갯수가 2개인 2진수 갯수
			bl2++;
		}
		if (binary3[i].empty() == 0) { //1의 갯수가 3개인 2진수 갯수
			bl3++;
		}
	}
	if (binary[0].empty() == 0) { //1의 갯수가 0개인 2진수 갯수
		bl = 1;
	}
	if (binary4[0].empty() == 0) { //1의 갯수가 4개인 2진수 갯수
		bl4 = 1;
	}
	qt[0][0] = bl, qt[0][1] = bl1, qt[0][2] = bl2, qt[0][3] = bl3, qt[0][4] = bl4; //최종 pi 추출할 때 사용하기위해 2진수 갯수 배열에 넣음
	if (binary[0].empty() == 0) {
		for (int j = 0; j < bl1; j++) { //1의 갯수가 1개인 2진수그룹
			bin = 0, min = 0;
			for (int i = 0; i < 4; i++) { //각 2진수의 자릿수
				if (binary[0][i] == binary1[j][i])
				{
					bin++;
				}
				else {
					min = i;
				}
			}
			count1[j] = bin; // 같은 숫자 갯수
			count2[j] = min; // 다른 숫자 자릿수 
			if (count1[j] == 3) {
				bim++;   //머징 횟수
			}
		}
	}
	if (bim != 0) {
		num += 1;
		for (int i = 0; i < bl1; i++) { // 머징된 값들을 str 배열에 넣어줌

			if (count1[i] == 3) {
				str[z] = binary1[i];
				str[z][count2[i]] = '_';
				number2[d1][0] = number[0];
				number2[d1][1] = number[d2];
				z++;
				d1++;
				d2++;
			}
		}
		for (int i = 0; i < z; i++) { //str에있는 머징값들을 binary1에 넣어줌
			fbinary[i] = str[i];
			str[i].clear();
		}
	}
	z = 0, ml = 0, bim = 0;
	for (int l = 0; l < bl1; l++) { //1의 갯수가 1개인 2진수그룹
		for (int j = 0; j < bl2; j++) { //1의 갯수가 2개인 2진수그룹
			bin = 0, min = 0;
			for (int i = 0; i < 4; i++) { // 각 2진수의 자릿수
				if (binary1[l][i] == binary2[j][i])
				{
					bin++;
				}
				else {
					min = i;
				}
			}
			count1[al] = bin;
			count2[al] = min;
			if (count1[al] == 3) {
				bim++;
			}
			al++;
		}
	}
	if (bim != 0) {
		d2 = bl + bl1;
		t = bl;
		num += 1;
		c = bl2;
		for (int i = 0; i < 24; i++) { // 머징된 값들을 str 배열에 넣어줌
			if (count1[i] == 3) {
				str[z] = binary1[ml];
				str[z][count2[i]] = '_';
				number2[d1][0] = number[t];
				number2[d1][1] = number[d2];
				z++;
				d1++;
			}
			d2++;
			c--;
			if (c == 0) {
				ml++;
				c = bl2;
				t++;
				d2 = bl + bl1;
			}
		}
		for (int i = 0; i < z; i++) { // str에있는 머징값들을 binary1에 넣어줌
			fbinary1[i].clear();
			fbinary1[i] = str[i];
			str[i].clear();
		}

	}
	al = 0, ml = 0, z = 0, bim = 0;
	for (int i = 0; i < 100; i++) {
		count1[i] = { NULL };
		count2[i] = { NULL };
	}
	for (int l = 0; l < bl2; l++) { //1의 갯수가 2개인 2진수그룹
		for (int j = 0; j < bl3; j++) { //1의 갯수가 3개인 2진수그룹
			bin = 0, min = 0;
			for (int i = 0; i < 4; i++) { // 각 2진수의 자릿수
				if (binary2[l][i] == binary3[j][i])
				{
					bin++;
				}
				else {
					min = i;
				}
			}
			count1[al] = bin;
			count2[al] = min;
			if (count1[al] == 3) {
				bim++;
			}
			al++;
		}
	}
	if (bim != 0) {
		t = bl + bl1;
		d2 = bl + bl1 + bl2;
		c = bl3;
		num += 1;
		for (int i = 0; i < 24; i++) {
			if (count1[i] == 3) { // 머징된 값들을 str 배열에 넣어줌
				str[z] = binary2[ml];
				str[z][count2[i]] = '_';
				number2[d1][0] = number[t];
				number2[d1][1] = number[d2];
				z++;
				d1++;
			}
			d2++;
			c--;
			if (c == 0) {
				ml++;
				c = bl3;
				t++;
				d2 = bl + bl1 + bl2;
			}
		}
		for (int i = 0; i < z; i++) { //str에있는 머징값들을 fbinary2에 넣어줌
			fbinary2[i].clear();
			fbinary2[i] = str[i];
			str[i].clear();
		}
	}
	for (int i = 0; i < 100; i++) {
		count1[i] = { NULL };
		count2[i] = { NULL };
	}
	al = 0, ml = 0, z = 0, bim = 0;;
	if (binary4[0].empty() == 0) {
		for (int j = 0; j < bl3; j++) { //1의 갯수가 3개인 2진수그룹
			bin = 0, min = 0;
			for (int i = 0; i < 4; i++) { //각 2진수의 자릿수
				if (binary3[j][i] == binary4[0][i])
				{
					bin++;
				}
				else {
					min = i;
				}
			}
			count1[j] = bin;
			count2[j] = min;
			if (count1[j] == 3) {
				bim++;
			}
		}
	}
	if (bim != 0) {
		t = bl + bl1 + bl2 + bl3;
		num += 1;
		for (int i = 0; i < 4; i++) {
			if (count1[i] == 3) { // 머징된 값들을 str 배열에 넣어줌
				str[z] = binary3[i];
				str[z][count2[i]] = '_';
				number2[d1][0] = number[t];
				number2[d1][1] = number[d2];
				z++;
				d1++;
			}
			d2++;
		}
		for (int i = 0; i < z; i++) { // str에있는 머징값들을 fbinary3에 넣어줌
			fbinary3[i] = str[i];
			str[i].clear();
		}
	}
}
void pi2(string binary[12] = { }, string binary1[24] = { }, string binary2[12] = { }, string binary3[4] = { }, string str[24] = { }, string fbinary[12] = { }, string fbinary1[24] = { }, string fbinary2[12] = { }, string fbinary3[12] = { }, string fabinary1[6] = { }, string fabinary2[14] = { }, string fabinary3[14] = { }, string fabinary4[6] = { }) {   // 2차 pi 추출
	int bin = 0, min = 0, z = 0, al = 0, ml = 0, bim = 0, bl1 = 0, bl2 = 0, bl3 = 0, bl4 = 0, c = 0, ctl = 0, n = 0, d1 = 0, d2 = 0, t = 0, k = 0, q = 0;
	for (int i = 0; i < 12; i++) {
		if (fbinary[i].empty() == 0) {
			bl1++;
		}
		if (fbinary1[i].empty() == 0) {
			bl2++;
		}
		if (fbinary2[i].empty() == 0) {
			bl3++;
		}
		if (fbinary3[i].empty() == 0) {
			bl4++;
		}
	}
	qt[1][0] = bl1, qt[1][1] = bl2, qt[1][2] = bl3, qt[1][3] = bl4;
	for (int i = 0; i < qt[1][0]; i++) {
		fabinary1[i] = fbinary[i];
		for (int j = 0; j < 2; j++) {
			ass[i][j] = number2[i][j];
		}
	}
	for (int i = 0; i < qt[1][1]; i++) {
		fabinary2[i] = fbinary1[i];
		for (int j = 0; j < 2; j++) {
			ass[i + qt[1][0]][j] = number2[i + qt[1][0]][j];
		}
	}
	for (int i = 0; i < qt[1][2]; i++) {
		fabinary3[i] = fbinary2[i];
		for (int j = 0; j < 2; j++) {
			ass[i + qt[1][0] + qt[1][1]][j] = number2[i + qt[1][0] + qt[1][1]][j];
		}
	}
	for (int i = 0; i < qt[1][3]; i++) {
		fabinary4[i] = fbinary3[i];
		for (int j = 0; j < 2; j++) {
			ass[i + qt[1][0] + qt[1][1] + qt[1][2]][j] = number2[i + qt[1][0] + qt[1][1] + qt[1][2]][j];
		}
	}
	for (int i = 0; i < 4; i++) {
		tmp[i] = { NULL };
		o[i] = { NULL };
	}
	for (int i = 0; i < 100; i++) {
		count1[i] = { NULL };
		count2[i] = { NULL };
	}
	if (fbinary1[0].empty() == 0) {
		for (int l = 0; l < bl1; l++) { //1차 머징후 1의 갯수가 0개인 2진수그룹
			for (int j = 0; j < bl2; j++) { //1차 머징후 1의 갯수가 1개인 2진수그룹
				bin = 0, min = 0;
				for (int i = 0; i < 4; i++) { // 각 2진수의 자릿수
					if (fbinary[l][i] == fbinary1[j][i])
					{
						bin++;
					}
					else {
						min = i;
					}
				}
				count1[al] = bin;
				count2[al] = min;
				if (count1[al] == 3) {
					bim++;
					ctl++;
				}
				al++;
			}
		}
	}
	if (bim != 0) {
		for (int i = 0; i < 24; i++) {
			binary[i].clear();
		}
		tmp[0] = 1;
		c = bl2;
		num += 1;
		for (int i = 0; i < 48; i++) { // 머징된 값들을 str 배열에 넣어줌
			if (count1[i] == 3) {
				int d3 = 2;
				str[z] = fbinary[ml];
				str[z][count2[i]] = '_';
				o[0] += 1;
				for (int i = 0; i < 2; i++) {
					number3[t][i] = number2[d2][i];
				}
				for (int i = 0; i < 2; i++) {
					number3[t][d3] = number2[d1 + bl1][i];
					d3++;
				}
				t++;
				z++;
			}
			d1++;
			c--;
			if (c == 0) {
				d1 = 0, c = bl2;
				ml++, d2++;
			}
		}
		for (int i = 0; i < z; i++) { // str에있는 머징값들을 binary에 넣어줌
			binary[i] = str[i];
			str[i].clear();
		}
	}
	bin = 0, min = 0, z = 0, al = 0, ml = 0, bim = 0, c = 0;
	for (int i = 0; i < 144; i++) {
		count1[i] = { NULL };
		count2[i] = { NULL };
	}
	if (fbinary2[0].empty() == 0) {
		for (int l = 0; l < bl2; l++) { //1차 머징후 1의 갯수가 1개인 2진수그룹
			for (int j = 0; j < bl3; j++) { //1차 머징후 1의 갯수가 2개인 2진수그룹
				bin = 0, min = 0;
				for (int i = 0; i < 4; i++) { // 각 2진수의 자릿수
					if (fbinary1[l][i] == fbinary2[j][i])
					{
						bin++;
					}
					else {
						min = i;
					}
				}
				count1[al] = bin;
				count2[al] = min;
				if (count1[al] == 3) {
					bim++;
					ctl++;
				}
				al++;
			}
		}
	}
	if (bim != 0) {
		for (int i = 0; i < 24; i++) {
			binary1[i].clear();
		}
		tmp[1] = 1, d1 = 0, d2 = bl1;
		c = bl3;
		num += 1;
		for (int i = 0; i < 144; i++) { // 머징된 값들을 str 배열에 넣어줌
			if (count1[i] == 3) {
				int d3 = 2;
				str[z] = fbinary1[ml];
				str[z][count2[i]] = '_';
				o[1] += 1;
				for (int i = 0; i < 2; i++) {
					number3[t][i] = number2[d2][i];
				}
				for (int i = 0; i < 2; i++) {
					number3[t][d3] = number2[d1 + bl1 + bl2][i];
					d3++;
				}
				t++;
				z++;
			}
			d1++;
			c--;
			if (c == 0) {
				d1 = 0,
					c = bl3;
				ml++;
				d2++;
			}
		}
		for (int i = 0; i < z; i++) { // str에있는 머징값들을 binary1에 넣어줌
			binary1[i] = str[i];
			str[i].clear();
		}
	}
	bin = 0, min = 0, z = 0, al = 0, ml = 0, bim = 0, c = 0;
	for (int i = 0; i < 144; i++) {
		count1[i] = { NULL };
		count2[i] = { NULL };
	}
	if (fbinary3[0].empty() == 0) {
		for (int l = 0; l < bl3; l++) { //1차 머징후 1의 갯수가 2개인 2진수그룹
			for (int j = 0; j < bl4; j++) { //1차 머징후 1의 갯수가 3개인 2진수그룹
				bin = 0, min = 0;
				for (int i = 0; i < 4; i++) { // 각 2진수의 자릿수
					if (fbinary2[l][i] == fbinary3[j][i])
					{
						bin++;
					}
					else {
						min = i;
					}
				}
				count1[al] = bin;
				count2[al] = min;
				if (count1[al] == 3) {
					bim++;
					ctl++;
				}
				al++;
			}
		}
	}
	if (bim != 0) {
		tmp[2] = 1, d1 = 0, d2 = bl2 + bl1;
		for (int i = 0; i < 24; i++) {
			binary2[i].clear();
		}
		c = bl4;
		num += 1;
		for (int i = 0; i < 48; i++) { // 머징된 값들을 str 배열에 넣어줌
			if (count1[i] == 3) {
				int d3 = 2;
				str[z] = fbinary2[ml];
				str[z][count2[i]] = '_';
				o[2] += 1;
				for (int i = 0; i < 2; i++) {
					number3[t][i] = number2[d2][i];
				}
				for (int i = 0; i < 2; i++) {
					number3[t][d3] = number2[d1 + bl1 + bl2 + bl3][i];
					d3++;
				}
				t++;
				z++;
			}
			d1++;
			c--;
			if (c == 0) {
				d1 = 0,
					c = bl4;
				ml++;
				d2++;
			}
		}
		for (int i = 0; i < z; i++) { // str에있는 머징값들을 binary2에 넣어줌
			binary2[i] = str[i];
			str[i].clear();
		}
	}
	if (ctl != 0) {
		if (tmp[0] == 0) {
			for (int i = 0; i < 12; i++)
			{
				binary[i].clear();
			}
		}
		else {
			for (int j = 0; j < o[0]; j++) {
				for (int i = 0; i < o[0]; i++) {
					if (i != j) {
						if (binary[i] == binary[j]) {
							p[j] = 1;
						}
					}
				}
				if (p[j] == 1) {
					binary[j].clear();
					for (int i = 0; i < 4; i++) {
						number3[j][i] = { NULL };
					}
					p[j] = { NULL };
				}
			}
			z = 0;
			for (int i = 0; i < o[0]; i++) {
				if (binary[i].empty() == 0) {
					str[z] = binary[i];
					binary[i].clear();
					for (int j = 0; j < 4; j++) {
						number3[z][j] = number3[i][j];
					}
					z++;
				}
			}
			for (int i = z; i < o[0]; i++) {
				for (int j = 0; j < 4; j++) {
					number3[i][j] = { NULL };
				}
			}
			for (int i = 0; i < z; i++) {
				binary[i] = str[i];
				str[i].clear();
			}
			k = z;
		}
		if (tmp[1] == 0) {
			for (int i = 0; i < 24; i++)
			{
				binary1[i].clear();
			}
		}
		else {
			for (int j = 0; j < o[1]; j++) {
				for (int i = 0; i < o[1]; i++) {
					if (i != j) {
						if (binary1[i] == binary1[j]) {
							p[j] = 1;
						}
					}
				}
				if (p[j] == 1) {
					binary1[j].clear();
					for (int i = 0; i < 4; i++) {
						number3[j + o[0]][i] = { NULL };
					}
					p[j] = { NULL };
				}
			}
			z = 0;
			for (int i = 0; i < o[1]; i++) {
				if (binary1[i].empty() == 0) {
					str[z] = binary1[i];
					for (int j = 0; j < 4; j++) {
						wp[z][j] = number3[i + o[0]][j];
						number3[i + o[0]][j] = { NULL };
					}
					z++;
				}
				binary1[i].clear();
			}
			for (int i = 0; i < z; i++) {
				binary1[i] = str[i];
				str[i].clear();
				for (int j = 0; j < 4; j++) {
					number3[i + k][j] = wp[i][j];
					wp[i][j] = { NULL };
				}
			}
			k += z;
		}
		if (tmp[2] == 0) {
			for (int i = 0; i < 12; i++)
			{
				binary2[i].clear();
			}
		}
		else {
			for (int j = 0; j < o[2]; j++) {
				for (int i = 0; i < o[2]; i++) {
					if (i != j) {
						if (binary2[i] == binary2[j]) {
							p[j] = 1;
						}
					}
				}
				if (p[j] == 1) {
					binary2[j].clear();
					for (int i = 0; i < 4; i++) {
						number3[j + o[0] + o[1]][i] = { NULL };
					}
					p[j] = { NULL };
				}
			}
			z = 0;
			for (int i = 0; i < o[2]; i++) {
				if (binary2[i].empty() == 0) {
					str[z] = binary2[i];
					binary2[i].clear();
					for (int j = 0; j < 4; j++) {
						wp[z][j] = number3[i + o[0] + o[1]][j];
						number3[i + o[0] + o[1]][j] = { NULL };
					}
					z++;
				}
			}
			for (int i = 0; i < z; i++) {
				binary2[i] = str[i];
				str[i].clear();
				for (int j = 0; j < 4; j++) {
					number3[i + k][j] = wp[i][j];
					wp[i][j] = { NULL };
				}
			}
		}
	}
}
void pi3(string binary[50] = { }, string binary1[25] = { }, string binary2[24] = { }, string str[50] = { }, string fbinary[50] = { }, string fbinary1[25] = { }, string fbinary2[12] = { }, string abinary1[12] = { }, string abinary2[12] = { }, string abinary3[12] = { }) { //3차 pi추출
	int bin = 0, min = 0, z = 0, al = 0, ml = 0, bim = 0, bl1 = 0, bl2 = 0, bl3 = 0, c = 0, ctl = 0, t = 0, d1 = 0, d2 = 0, k = 0, q = 0;
	for (int i = 0; i < 24; i++) {
		if (binary[i].empty() == 0) {
			bl1++;
		}
		if (binary1[i].empty() == 0) {
			bl2++;
		}
		if (binary2[i].empty() == 0) {
			bl3++;
		}
	}
	qt[2][0] = bl1, qt[2][1] = bl2, qt[2][2] = bl3;
	for (int i = 0; i < qt[2][0]; i++) {
		abinary1[i] = binary[i];
	}
	for (int i = 0; i < qt[2][1]; i++) {
		abinary2[i] = binary1[i];
	}
	for (int i = 0; i < qt[2][2]; i++) {
		abinary3[i] = binary2[i];
	}
	for (int i = 0; i < 100; i++) {
		count1[i] = { NULL };
		count2[i] = { NULL };
		if (i < 8) {
			tmp[i] = { NULL };
			o[i] = { NULL };
		}
	}
	if (binary1[0].empty() == 0) {
		for (int l = 0; l < bl1; l++) { //2차 머징후 1의 갯수가 0개인 2진수그룹
			for (int j = 0; j < bl2; j++) { //2차 머징후 1의 갯수가 1개인 2진수그룹
				bin = 0, min = 0;
				for (int i = 0; i < 4; i++) { // 각 2진수의 자릿수
					if (binary[l][i] == binary1[j][i])
					{
						bin++;
					}
					else {
						min = i;
					}
				}
				count1[al] = bin;
				count2[al] = min;
				if (count1[al] == 3) {
					bim++;
					ctl++;
				}
				al++;
			}
		}
	}
	if (bim != 0) {
		tmp[0] = 1;
		c = bl2;
		num += 1;
		for (int i = 0; i < 24; i++) {
			fbinary[i].clear();
		}
		for (int i = 0; i < 288; i++) { // 머징된 값들을 str 배열에 넣어줌
			if (count1[i] == 3) {
				int d3 = 4;
				str[z] = binary[ml];
				str[z][count2[i]] = '_';
				for (int i = 0; i < 4; i++) {
					number2[t][i] = number3[d2][i];
				}
				for (int i = 0; i < 4; i++) {
					number2[t][d3] = number3[d1 + bl1][i];
					d3++;
				}
				t++;
				z++;
				o[0] += 1;
			}
			d1++;
			c--;
			if (c == 0) {
				d1 = 0, c = bl2;
				ml++, d2++;
			}
		}
		for (int i = 0; i < z; i++) { // str에있는 머징값들을 fbinary에 넣어줌
			fbinary[i] = str[i];
			str[i].clear();
		}
	}
	bin = 0, min = 0, z = 0, al = 0, ml = 0, bim = 0;
	for (int i = 0; i < 288; i++) {
		count1[i] = { NULL };
		count2[i] = { NULL };
	}
	if (binary1[0].empty() == 0) {
		for (int l = 0; l < bl2; l++) { //2차 머징후 1의 갯수가 1개인 2진수그룹
			for (int j = 0; j < bl3; j++) { //2차 머징후 1의 갯수가 2개인 2진수그룹
				bin = 0, min = 0;
				for (int i = 0; i < 4; i++) { // 각 2진수의 자릿수
					if (binary1[l][i] == binary2[j][i])
					{
						bin++;
					}
					else {
						min = i;
					}
				}
				count1[al] = bin;
				count2[al] = min;
				if (count1[al] == 3) {
					bim++;
					ctl++;
				}
				al++;
			}
		}
	}
	if (bim != 0) {
		tmp[1] = 1, d2 = bl1;
		c = bl3;
		for (int i = 0; i < 24; i++) {
			fbinary1[i].clear();
		}
		num += 1;
		for (int i = 0; i < 288; i++) { // 머징된 값들을 str 배열에 넣어줌
			if (count1[i] == 3) {
				int d3 = 4;
				str[z] = binary1[ml];
				str[z][count2[i]] = '_';
				for (int i = 0; i < 4; i++) {
					number2[t][i] = number3[d2][i];
				}
				for (int i = 0; i < 4; i++) {
					number2[t][d3] = number3[d1 + bl1 + bl2][i];
					d3++;
				}
				t++;
				z++;
				o[1] += 1;
			}
			d1++;
			c--;
			if (c == 0) {
				d1 = 0, c = bl3;
				ml++, d2++;
			}
		}
		for (int i = 0; i < z; i++) { // str에있는 머징값들을 fbinary1에 넣어줌
			fbinary1[i] = str[i];
			str[i].clear();
		}
	}
	if (ctl != 0) {
		if (tmp[0] == 0) {
			for (int i = 0; i < 12; i++)
			{
				fbinary[i].clear();
			}
		}
		else {
			for (int j = 0; j < o[0]; j++) {
				for (int i = 0; i < o[0]; i++) {
					if (i != j) {
						if (fbinary[i] == fbinary[j]) {
							p[j] = 1;
						}
					}
				}
				if (p[j] == 1) {
					fbinary[j].clear();
					for (int i = 0; i < 8; i++) {
						number2[j][j] = { NULL };
					}
					p[j] = { NULL };
				}
			}
			z = 0;
			for (int i = 0; i < o[0]; i++) {
				if (fbinary[i].empty() == 0) {
					str[z] = fbinary[i];
					fbinary[i].clear();
					for (int j = 0; j < 8; j++) {
						number2[z][j] = number2[i][j];
					}
					z++;
				}
			}
			for (int i = 0; i < z; i++) {
				fbinary[i] = str[i];
				str[i].clear();
			}
			for (int j = z; j < o[0]; j++) {
				for (int i = 0; i < 8; i++) {
					number2[j][i] = { NULL };
				}
			}
			k = z;
		}
		if (tmp[1] == 0) {
			for (int i = 0; i < 24; i++)
			{
				fbinary1[i].clear();
			}
		}
		else {
			for (int j = 0; j < o[1]; j++) {
				for (int i = 0; i < o[1]; i++) {
					if (i != j) {
						if (fbinary1[i] == fbinary1[j]) {
							p[j] = 1;
						}
					}
				}
				if (p[j] == 1) {
					fbinary1[j].clear();
					for (int i = 0; i < 8; i++) {
						number2[j + o[0]][i] = { NULL };
						p[j] = { NULL };
					}
				}
			}
			z = 0;
			for (int i = 0; i < o[1]; i++) {
				if (fbinary1[i].empty() == 0) {
					str[z] = fbinary1[i];
					fbinary1[i].clear();
					for (int j = 0; j < 8; j++) {
						wp[z][j] = number2[i + o[0]][j];
						number2[i + o[0]][j] = { NULL };
					}
					z++;
				}
			}
			for (int i = 0; i < z; i++) {
				fbinary1[i] = str[i];
				str[i].clear();
				for (int j = 0; j < 8; j++) {
					number2[i + k][j] = wp[i][j];
					wp[i][j] = { NULL };
				}
			}
		}
	}
}
void pia2(string fabinary1[6] = { }, string fabinary2[14] = { }, string fabinary3[14] = { }, string fabinary4[6] = { }) { //1차 머징한 2진수
	if (fabinary1[0].empty() == 0) {
		cout << "\n1의 갯수 0 \n";
		for (int i = 0; i < qt[1][0]; i++) {
			cout << fabinary1[i] << "  ";
			for (int j = 0; j < 2; j++) {
				cout << ass[i][j] << "  ";
			}
			cout << endl;
		}
	}
	if (fabinary2[0].empty() == 0) {
		cout << "\n1의 갯수 1 \n";
		for (int i = 0; i < qt[1][1]; i++) {
			cout << fabinary2[i] << "  ";
			for (int j = 0; j < 2; j++) {
				cout << ass[i + qt[1][0]][j] << "  ";
			}
			cout << endl;
		}
	}
	if (fabinary3[0].empty() == 0) {
		cout << "\n1의 갯수 2 \n";
		for (int i = 0; i < qt[1][2]; i++) {
			cout << fabinary3[i] << "  ";
			for (int j = 0; j < 2; j++) {
				cout << ass[i + qt[1][0] + qt[1][1]][j] << "  ";
			}
			cout << endl;
		}
	}
	if (fabinary4[0].empty() == 0) {
		cout << "\n1의 갯수 3 \n";
		for (int i = 0; i < qt[1][3]; i++) {
			cout << fabinary4[i] << "  ";
			for (int j = 0; j < 2; j++) {
				cout << ass[i + qt[1][0] + qt[1][1] + qt[1][2]][j] << "  ";
			}
			cout << endl;
		}
	}
}
void pia3(string abinary1[12] = { }, string abinary2[12] = { }, string abinary3[12] = { }) { //2차 머징한 수
	if (abinary1[0].empty() == 0) {
		cout << "\n1의 갯수 0 \n";
		for (int i = 0; i < qt[2][0]; i++) {
			cout << abinary1[i] << "  ";
			for (int j = 0; j < 4; j++) {
				cout << number3[i][j] << "  ";
			}
			cout << endl;
		}
	}
	if (abinary2[0].empty() == 0) {
		cout << "\n1의 갯수 1 \n";
		for (int i = 0; i < qt[2][1]; i++) {
			cout << abinary2[i] << "  ";
			for (int j = 0; j < 4; j++) {
				cout << number3[i + qt[2][0]][j] << "  ";
			}
			cout << endl;
		}
	}
	if (abinary3[0].empty() == 0) {
		cout << "\n1의 갯수 2 \n";
		for (int i = 0; i < qt[2][2]; i++) {
			cout << abinary3[i] << "  ";
			for (int j = 0; j < 4; j++) {
				cout << number3[i + qt[2][0] + qt[2][1]][j] << "  ";
			}
			cout << endl;
		}
	}
}
void pia4(string abinary1[12] = { }, string abinary2[12] = { }, string abinary3[12] = { }, string fabinary1[6] = { }, string fabinary2[14] = { }, string fabinary3[14] = { }, string fabinary4[6] = { }, string str[96] = { }, string fbinary[50] = { }, string fbinary1[25] = { }) { // 최종머징한 수를 전단계 수랑 비교한 값
	int u = 1;
	if (num == 1) {
		cout << endl;
		for (int i = 0; i < h; i++) {
			cout << str[i] << "  ";
			cout << re1[i][0] << endl;
		}
		cout << "     ▲          \n";
		cout << "  최종 PI값 " << endl;
	}
	if (num == 2) {
		cout << "  최종 PI값  " << endl;
		for (int i = 0; i < qt[2][0]; i++) {
			cout << u << ". " << abinary1[i] << "  ";
			for (int j = 0; j < 4; j++) {
				cout << number3[i][j] << "  ";
			}
			cout << endl;
			u++;
		}
		for (int i = 0; i < qt[2][1]; i++) {
			cout << u << ". " << abinary2[i] << "  ";
			for (int j = 0; j < 4; j++) {
				cout << number3[i + qt[2][0]][j] << "  ";
			}
			cout << endl;
			u++;
		}
		for (int i = 0; i < qt[2][2]; i++) {
			cout << u << ". " << abinary3[i] << "  ";
			for (int j = 0; j < 4; j++) {
				cout << number3[i + qt[2][0] + qt[2][1]][j] << "  ";
			}
			cout << endl;
			u++;
		}
		cout << endl;
		for (int i = 0; i < h; i++) {
			cout << u << ". " << str[i] << "  ";
			for (int j = 0; j < 2; j++) {
				cout << re1[i][j] << "  ";
			}
			cout << endl;
			u++;
		}
	}
	if (num == 3) {
		cout << "  최종 PI값  " << endl;
		for (int i = 0; i < qt[3][0]; i++) {
			cout << u << ". " << fbinary[i] << "  ";
			for (int j = 0; j < 8; j++) {
				cout << number2[i][j] << "  ";
			}
			cout << endl;
			u++;
		}
		for (int i = 0; i < qt[3][1]; i++) {
			cout << u << ". " << fbinary1[i] << "  ";
			for (int j = 0; j < 8; j++) {
				cout << number2[i + qt[3][0]][j] << "  ";
			}
			cout << endl;
			u++;
		}
		cout << endl;
		for (int i = 0; i < h; i++) {
			cout << u << ". " << str[i] << "  ";
			for (int j = 0; j < 4; j++) {
				cout << re1[i][j] << "  ";
			}
			cout << endl;
			u++;
		}
	}
}
void pi3number(string binary[96] = { }, string binary1[48] = { }, string str[96] = { }, string fbinary[96] = { }, string fbinary1[48] = { }) { //3차 머징한 수
	int  bl1 = 0, bl2 = 0;
	for (int i = 0; i < 24; i++) {
		if (fbinary[i].empty() == 0) {
			bl1++;
		}
		if (fbinary1[i].empty() == 0) {
			bl2++;
		}
	}
	qt[3][0] = bl1, qt[3][1] = bl2;
	if (fbinary[0].empty() == 0) {
		cout << "\n1의 갯수 0 \n";
		for (int i = 0; i < qt[3][0]; i++) {
			cout << fbinary[i] << "  ";
			for (int j = 0; j < 8; j++) {
				cout << number2[i][j] << "  ";
			}
			cout << endl;
		}
	}
	if (fbinary1[0].empty() == 0) {
		cout << "\n1의 갯수 1 \n";
		for (int i = 0; i < qt[3][1]; i++) {
			cout << fbinary1[i] << "  ";
			for (int j = 0; j < 8; j++) {
				cout << number2[i + qt[3][0]][j] << "  ";
			}
			cout << endl;
		}
	}
}
void printmap(string epi[16] = { }, string bow[16] = { }) { // 테이블 출력 및 결과값 출력
	if (num == 0) {
		for (int j = 0; j < qt[0][0] + qt[0][3] + qt[0][1] + qt[0][2] + qt[0][4] + 1; j++) {  //별 테이블 출력
			for (int i = 0; i < g + 1; i++) {
				if (wp[0][i] < 10) {
					if (wp[j][i] == 17) {
						cout << "* ";
					}
					else {
						cout << wp[j][i] << " ";
					}
				}
				else {
					if (wp[j][i] == 17) {
						cout << " * ";
					}
					else {
						if (j == 0) {
							cout << wp[j][i] << " ";
						}
						else {
							cout << " " << wp[j][i] << " ";
						}
					}
				}
			}
			cout << endl;
		}
		cout << " \n        ▼    \n\n";
		for (int j = 0; j < qt[0][0] + qt[0][3] + qt[0][1] + qt[0][2] + qt[0][4] + 1; j++) { //숨겨진 epi 찾는 테이블 출력
			for (int i = 0; i < g + 1; i++) {
				if (wp1[0][i] < 10) {
					if (wp1[j][i] == 17) {
						cout << "* ";
					}
					else if (wp1[j][i] == 18) {
						cout << "+ ";
					}
					else if (wp1[j][i] == 21) {
						cout << "@ ";
					}
					else {
						cout << wp1[j][i] << " ";
					}
				}
				else {
					if (wp1[j][i] == 17) {
						cout << " * ";
					}
					else if (wp1[j][i] == 18) {
						cout << " + ";
					}
					else if (wp1[j][i] == 21) {
						cout << " @ ";
					}
					else {
						if (j == 0) {
							cout << wp1[j][i] << " ";
						}
						else {
							cout << " " << wp1[j][i] << " ";
						}
					}
				}
			}
			cout << endl;
		}
	}
	if (num == 1) {
		for (int j = 0; j < h + qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2] + 1; j++) {  //별 테이블 출력
			for (int i = 0; i < g + 1; i++) {
				if (wp[0][i] < 10) {
					if (wp[j][i] == 17) {
						cout << "* ";
					}
					else {
						cout << wp[j][i] << " ";
					}
				}
				else {
					if (wp[j][i] == 17) {
						cout << " * ";
					}
					else {
						if (j == 0) {
							cout << wp[j][i] << " ";
						}
						else {
							cout << " " << wp[j][i] << " ";
						}
					}
				}
			}
			cout << endl;
		}
		cout << " \n        ▼      \n\n";
		for (int j = 0; j < h + qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2] + 1; j++) { //숨겨진 epi 찾는 테이블 출력
			for (int i = 0; i < g + 1; i++) {
				if (wp1[0][i] < 10) {
					if (wp1[j][i] == 17) {
						cout << "* ";
					}
					else if (wp1[j][i] == 18) {
						cout << "+ ";
					}
					else if (wp1[j][i] == 21) {
						cout << "@ ";
					}
					else {
						cout << wp1[j][i] << " ";
					}
				}
				else {
					if (wp1[j][i] == 17) {
						cout << " * ";
					}
					else if (wp1[j][i] == 18) {
						cout << " + ";
					}
					else if (wp1[j][i] == 21) {
						cout << " @ ";
					}
					else {
						if (j == 0) {
							cout << wp1[j][i] << " ";
						}
						else {
							cout << " " << wp1[j][i] << " ";
						}
					}
				}
			}
			cout << endl;
		}
	}
	if (num == 2) {
		for (int j = 0; j < h + qt[2][0] + qt[2][1] + qt[2][2] + 1; j++) {  //별 테이블 출력
			for (int i = 0; i < g + 1; i++) {
				if (wp[0][i] < 10) {
					if (wp[j][i] == 17) {
						cout << "* ";
					}
					else {
						cout << wp[j][i] << " ";
					}
				}
				else {
					if (wp[j][i] == 17) {
						cout << " * ";
					}
					else {
						if (j == 0) {
							cout << wp[j][i] << " ";
						}
						else {
							cout << " " << wp[j][i] << " ";
						}
					}
				}
			}
			cout << endl;
		}
		cout << " \n        ▼      \n\n";
		for (int j = 0; j < h + qt[2][0] + qt[2][1] + qt[2][2] + 1; j++) { //숨겨진 epi 찾는 테이블 출력
			for (int i = 0; i < g + 1; i++) {
				if (wp1[0][i] < 10) {
					if (wp1[j][i] == 17) {
						cout << "* ";
					}
					else if (wp1[j][i] == 18) {
						cout << "+ ";
					}
					else if (wp1[j][i] == 21) {
						cout << "@ ";
					}
					else {
						cout << wp1[j][i] << " ";
					}
				}
				else {
					if (wp1[j][i] == 17) {
						cout << " * ";
					}
					else if (wp1[j][i] == 18) {
						cout << " + ";
					}
					else if (wp1[j][i] == 21) {
						cout << " @ ";
					}
					else {
						if (j == 0) {
							cout << wp1[j][i] << " ";
						}
						else {
							cout << " " << wp1[j][i] << " ";
						}
					}
				}
			}
			cout << endl;
		}
	}
	if (num == 3) {
		for (int j = 0; j < h + qt[3][0] + qt[3][1] + 1; j++) {  //별 테이블 출력
			for (int i = 0; i < g + 1; i++) {
				if (wp[0][i] < 10) {
					if (wp[j][i] == 17) {
						cout << "* ";
					}
					else {
						cout << wp[j][i] << " ";
					}
				}
				else {
					if (wp[j][i] == 17) {
						cout << " * ";
					}
					else {
						if (j == 0) {
							cout << wp[j][i] << " ";
						}
						else {
							cout << " " << wp[j][i] << " ";
						}
					}
				}
			}
			cout << endl;
		}
		cout << " \n        ▼      \n\n";
		for (int j = 0; j < h + qt[3][0] + qt[3][1] + 1; j++) { //숨겨진 epi 찾는 테이블 출력
			for (int i = 0; i < g + 1; i++) {
				if (wp1[0][i] < 10) {
					if (wp1[j][i] == 17) {
						cout << "* ";
					}
					else if (wp1[j][i] == 18) {
						cout << "+ ";
					}
					else if (wp1[j][i] == 21) {
						cout << "@ ";
					}
					else {
						cout << wp1[j][i] << " ";
					}
				}
				else {
					if (wp1[j][i] == 17) {
						cout << " * ";
					}
					else if (wp1[j][i] == 18) {
						cout << " + ";
					}
					else if (wp1[j][i] == 21) {
						cout << " @ ";
					}
					else {
						if (j == 0) {
							cout << wp1[j][i] << " ";
						}
						else {
							cout << " " << wp1[j][i] << " ";
						}
					}
				}
			}
			cout << endl;
		}
	}
	if (num == 4) {
		for (int i = 0; i < 16; i++) {    // 가로축테이블에 수 넣기
			wp[0][i + 1] = number[i];
		}
		wp[1][0] = 1;    // 가로축테이블에 수 넣기
		for (int j = 0; j < 16; j++) {
			wp[1][j + 1] = 17;
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 17; j++) {

				if (wp[0][j] < 10) {
					if (wp[i][j] == 17) {
						cout << "* ";
					}
					else {
						cout << wp[i][j] << " ";
					}
				}
				else {
					if (wp[i][j] == 17) {
						cout << " * ";
					}
					else {
						cout << wp[i][j] << " ";
					}
				}
			}
			cout << endl;
		}
		cout << " \n                   ▼    \n\n";
		for (int j = 0; j < 16; j++) {
			wp[1][j + 1] = 21;
		}
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 17; j++) {

				if (wp[0][j] < 10) {
					if (wp[i][j] == 21) {
						cout << "@ ";
					}
					else {
						cout << wp[i][j] << " ";
					}
				}
				else {
					if (wp[i][j] == 21) {
						cout << " @ ";
					}
					else {
						cout << wp[i][j] << " ";
					}
				}\
			}
			cout << endl;
		}
		cout << "\n\n 최종 결과값  \n";
		cout << "\n____\n";
		cout << "\n 논리식 표현  \n";
		cout << "\n 1 \n";
	}
	if (num != 4) {
		cout << "최종 결과값 \n\n";
		for (int i = 0; i < b; i++) { //최종 EPI 값
			cout << epi[i] << endl;
		}
		cout << "논리식 값 \n\n";
		for (int i = 0; i < b; i++) {  //epi값들을 논리회로식으로 출력
			if (epi[i][0] == '0') {
				cout << "A'";
				if (epi[i][1] == '_' && epi[i][2] == '_' && epi[i][3] == '_') {
					if (epi[i + 1].empty() == 1) {
						cout << endl;
					}
					else {
						cout << "+";
					}
				}
			}
			if (epi[i][0] == '1') {
				cout << "A";
				if (epi[i][1] == '_' && epi[i][2] == '_' && epi[i][3] == '_') {
					if (epi[i + 1].empty() == 1) {
						cout << endl;
					}
					else {
						cout << "+";
					}
				}
			}
			if (epi[i][1] == '0') {
				cout << "B'";
				if (epi[i][2] == '_' && epi[i][3] == '_') {
					if (epi[i + 1].empty() == 1) {
						cout << endl;
					}
					else {
						cout << "+";
					}
				}
			}
			if (epi[i][1] == '1') {
				cout << "B";
				if (epi[i][2] == '_' && epi[i][3] == '_') {
					if (epi[i + 1].empty() == 1) {
						cout << endl;
					}
					else {
						cout << "+";
					}
				}
			}
			if (epi[i][2] == '0') {
				cout << "C'";
				if (epi[i][3] == '_') {
					if (epi[i + 1].empty() == 1) {
						cout << endl;
					}
					else {
						cout << "+";
					}
				}
			}
			if (epi[i][2] == '1') {
				cout << "C";
				if (epi[i][3] == '_') {
					if (epi[i + 1].empty() == 1) {
						cout << endl;
					}
					else {
						cout << "+";
					}
				}
			}
			if (epi[i][3] == '0') {
				cout << "D'";
				if (epi[i + 1].empty() == 1) {
					cout << endl;
				}
				else {
					cout << "+";
				}
			}
			if (epi[i][3] == '1') {
				cout << "D";
				if (epi[i + 1].empty() == 1) {
					cout << endl;
				}
				else {
					cout << "+";
				}
			}
		}
	}
}
void EPI(string binary[96] = { }, string binary1[25] = { }, string binary2[25] = { }, string binary3[4] = { }, string binary4[1] = { }, string str[96] = { }, string fbinary[96] = { }, string fbinary1[25] = { }, string fbinary2[25] = { }, string fbinary3[4] = { }, string epi[16] = { }, string bow[16] = { }) { //최종 epi 값 추출
	int bin = 0, a = 0, m[10] = { NULL }, pe[15] = { NULL }, ui[15] = { NULL };
	if (num == 0) {
		for (int i = 0; i < xl; i++) { //테이블 가로축에 선택수 입력
			wp[0][i + 1] = number[i];
		}
		for (int j = 0; j < qt[0][0] + qt[0][3] + qt[0][1] + qt[0][2] + qt[0][4]; j++) { //테이블 세로축에 최종적으로 뽑힌 epi값 번호 입력
			wp[j + 1][0] = j + 1;
		}
		for (int i = 0; i < qt[0][0]; i++) { //최종 pi 값 임의의 배열에 넣기
			bow[a] = binary[i];
			a++;
		}
		for (int i = 0; i < qt[0][1]; i++) {//최종 pi 값 임의의 배열에 넣기
			bow[a] = binary1[i];
			a++;
		}
		for (int i = 0; i < qt[0][2]; i++) {//최종 pi 값 임의의 배열에 넣기
			bow[a] = binary2[i];
			a++;
		}
		for (int i = 0; i < qt[0][3]; i++) {//최종 pi 값 임의의 배열에 넣기
			bow[a] = binary3[i];
			a++;
		}
		for (int i = 0; i < qt[0][4]; i++) {//최종 pi 값 임의의 배열에 넣기
			bow[a] = binary4[i];
			a++;
		}
		for (int i = 0; i < qt[0][0] + qt[0][3] + qt[0][1] + qt[0][2] + qt[0][4]; i++) {   //테이블에 별찍기
			for (int j = 0; j < xl; j++) {
				if (number[i] == wp[0][j + 1]) {
					wp[i + 1][j + 1] = 17;
				}
			}
		}
		for (int i = 0; i < qt[0][0] + qt[0][3] + qt[0][1] + qt[0][2] + qt[0][4] + 1; i++) {
			for (int j = 0; j < xl + 1; j++) {
				wp1[i][j] = wp[i][j];
			}
		}
		for (int j = 1; j < xl + 1; j++) {     // 1차 epi 찾기
			for (int i = 0; i < qt[0][0] + qt[0][3] + qt[0][1] + qt[0][2] + qt[0][4]; i++) {
				bin = 0;
				if (wp1[i + 1][j] == 17) {
					for (int z = 0; z < qt[0][0] + qt[0][3] + qt[0][1] + qt[0][2] + qt[0][4] + 1; z++) {
						if (wp1[z + 1][j] == 17)
							bin++;
					}
				}
				if (bin == 1) {
					if (i == 0) {
						ui[b] = 20;  //0값은 INT 형에서 NULL값과 같으므로 구분을 위해 20을 0대신 넣음
					}
					else {
						ui[b] = i;
					}
					m[b] = j;
					b++;
				}
			}
		}
		for (int i = 0; i < b; i++) { //찾은 EPI위치 체크
			if (ui[i] == 20) {
				wp1[1][m[i]] = 21;
			}
			else {
				wp1[ui[i] + 1][m[i]] = 21;
			}
		}
		for (int i = 0; i < sw + qt[0][0] + qt[0][3] + qt[0][1] + qt[0][2] + qt[0][4]; i++) {  //숨겨진 EPI 가로축 찾기
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 21) {
					for (int z = 1; z < xl + 1; z++) {
						if (wp1[i + 1][z] == 17) {
							wp1[i + 1][z] = 18;
						}
					}
				}
			}
		}
		for (int i = 0; i < sw + qt[0][0] + qt[0][3] + qt[0][1] + qt[0][2] + qt[0][4]; i++) {  //숨겨진 EPI 세로축 찾기
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 18) {
					for (int l = 0; l < sw + qt[2][0] + qt[2][1] + qt[2][2]; l++) {
						if (wp1[l + 1][j] == 17) {
							wp1[l + 1][j] = 18;
						}
					}
				}
			}
		}
		a = 0;
		for (int i = 0; i < b; i++) { //1차 epi 중복값 찾기
			bin = 0;
			for (int j = i; j < b; j++) {
				if (i != j) {
					if (ui[i] == ui[j]) {
						ui[i] = { NULL };
					}
				}
			}
		}
		for (int i = 0; i < b; i++) {
			if (ui[i] != 0) {
				pe[a] = ui[i];
				a++;
			}
		}
		for (int i = 0; i < a; i++) {
			if (pe[i] == 20) {
				pe[i] = 0;
			}
			ui[i] = pe[i];
			pe[i] = { NULL };
		}
		b = a, a = 0;;
		for (int z = 0; z < b; z++) {  //숨겨진 epi 가로축 찾기
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[ui[z] + 1][j] == 17) {
					if (j != m[z]) {
						wp1[ui[z] + 1][j] = 18;
					}
				}
			}
			for (int j = 1; j < xl + 1; j++) { //숨겨진 epi 세로축 찾기
				if (wp1[ui[z] + 1][j] == 18) {
					for (int i = 0; i < qt[0][0] + qt[0][3] + qt[0][1] + qt[0][2] + qt[0][4]; i++) {
						if (wp1[i + 1][j] == 17) {
							wp1[i + 1][j] = 18;
						}
					}
				}
			}
		}
		a = 0;
		for (int i = 0; i < qt[0][0] + qt[0][3] + qt[0][1] + qt[0][2] + qt[0][4]; i++) {  //숨겨진 epi 찾기
			bin = 0;
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 18) {
					bin++;
				}
			}
			if (bin == 0) {
				pe[a] = i;
				a++;
			}
		}
		int w = b;
		for (int i = 0; i < a; i++) {   // 숨겨진 epi값이 1차 epi값과 같은지 확인
			bin = 0;
			for (int j = 0; j < w; j++) {
				if (ui[j] == pe[i]) {
					bin++;
				}
			}
			if (bin == 0) {
				ui[b] = pe[i];
				b++;
			}
		}
	}
	if (num == 1) {
		for (int i = 0; i < xl; i++) {   //테이블 가로축 선택수 입력
			wp[0][i + 1] = number[i];
		}
		for (int j = 0; j < sw + qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; j++) { // 테이블 세로축에 최종 pi값 번호 입력
			wp[j + 1][0] = j + 1;
		}
		for (int i = 0; i < qt[1][0]; i++) {    //최종 pi값 임의의 배열에 넣기
			bow[a] = fbinary[i];
			a++;
		}
		for (int i = 0; i < qt[1][1]; i++) { //최종 pi값 임의의 배열에 넣기
			bow[a] = fbinary1[i];
			a++;
		}
		for (int i = 0; i < qt[1][2]; i++) { //최종 pi값 임의의 배열에 넣기
			bow[a] = fbinary2[i];
			a++;
		}
		for (int i = 0; i < qt[1][3]; i++) { //최종 pi값 임의의 배열에 넣기
			bow[a] = fbinary3[i];
			a++;
		}
		for (int i = 0; i < sw; i++) { //최종 pi값 임의의 배열에 넣기
			bow[a] = str[i];
			a++;
		}
		for (int i = 0; i < sw + qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; i++) {   //테이블에 별 찍기
			for (int j = 0; j < xl; j++) {
				for (int z = 0; z < 2; z++) {
					if (i < qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]) {
						if (number2[i][z] == wp[0][j + 1]) {
							wp[i + 1][j + 1] = 17;
						}
					}
					else {
						if (re[bin][0] == wp[0][j + 1]) {
							wp[i + 1][j + 1] = 17;
						}
					}
				}
			}
			if (i >= qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]) {
				bin++;
			}
		}
		for (int i = 0; i < sw + qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2] + 1; i++) {  // 결과값 옮기기
			for (int j = 0; j < xl + 1; j++) {
				wp1[i][j] = wp[i][j];
			}
		}
		for (int j = 1; j < xl + 1; j++) {
			for (int i = 0; i < sw + qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; i++) {    // 1차 epi 값 찾기
				bin = 0;
				if (wp1[i + 1][j] == 17) {
					for (int z = 0; z < sw + qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2] + 1; z++) {
						if (wp1[z + 1][j] == 17)
							bin++;
					}
				}
				if (bin == 1) {
					if (i == 0) {
						ui[b] = 20;  //0값은 INT 형에서 NULL값과 같으므로 구분을 위해 20을 0대신 넣음
					}
					else {
						ui[b] = i;
					}
					m[b] = j;
					b++;
				}
			}
		}
		for (int i = 0; i < b; i++) { //찾은 EPI위치 체크
			if (ui[i] == 20) {
				wp1[1][m[i]] = 21;
			}
			else {
				wp1[ui[i] + 1][m[i]] = 21;
			}
		}
		for (int i = 0; i < sw + qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; i++) {  //숨겨진 EPI 가로축 찾기
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 21) {
					for (int z = 1; z < xl + 1; z++) {
						if (wp1[i + 1][z] == 17) {
							wp1[i + 1][z] = 18;
						}
					}
				}
			}
		}
		for (int i = 0; i < sw + qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; i++) {  //숨겨진 EPI 세로축 찾기
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 18) {
					for (int l = 0; l < sw + qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; l++) {
						if (wp1[l + 1][j] == 17) {
							wp1[l + 1][j] = 18;
						}
					}
				}
			}
		}
		a = 0;
		for (int i = 0; i < b; i++) {  //1차 epi값중 중복값 제거
			bin = 0;
			for (int j = i; j < b; j++) {
				if (i != j) {
					if (ui[i] == ui[j]) {
						ui[i] = { NULL };
					}
				}
			}
		}
		for (int i = 0; i < b; i++) {
			if (ui[i] != 0) {
				pe[a] = ui[i];
				a++;
			}
		}
		for (int i = 0; i < a; i++) {
			if (pe[i] == 20) {
				pe[i] = 0;
			}
			ui[i] = pe[i];
			pe[i] = { NULL };
		}
		b = a, a = 0;
		for (int i = 0; i < sw + qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; i++) {  //숨겨진 epi찾기
			bin = 0;
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 18) {
					bin++;
				}
			}
			if (bin == 0) {
				pe[a] = i;
				a++;
			}
		}
		int w = b;
		for (int i = 0; i < a; i++) {    //숨겨진 epi 값이 1차 epi값이랑 같은지 확인
			bin = 0;
			for (int j = 0; j < w; j++) {
				if (ui[j] == pe[i]) {
					bin++;
				}
			}
			if (bin == 0) {
				ui[b] = pe[i];
				b++;
			}
		}
	}
	if (num == 2) {
		for (int i = 0; i < xl; i++) {              //테이블에 수놓기
			wp[0][i + 1] = number[i];
		}
		for (int j = 0; j < sw + qt[2][0] + qt[2][3] + qt[2][1] + qt[2][2]; j++) {
			wp[j + 1][0] = j + 1;
		}
		for (int i = 0; i < qt[2][0]; i++) { //임의의 문자열배열에 최종적으로 나온 pi값들 넣기
			bow[a] = binary[i];
			a++;
		}
		for (int i = 0; i < qt[2][1]; i++) {
			bow[a] = binary1[i];
			a++;
		}
		for (int i = 0; i < qt[2][2]; i++) {
			bow[a] = binary2[i];
			a++;
		}
		for (int i = 0; i < sw; i++) {
			bow[a] = str[i];
			a++;
		}
		for (int i = 0; i < sw + qt[2][0] + qt[2][1] + qt[2][2]; i++) {  // 테이블에 별찍기
			for (int j = 0; j < xl; j++) {
				for (int z = 0; z < 4; z++) {
					if (i < qt[2][0] + qt[2][3] + qt[2][1] + qt[2][2]) {
						if (number3[i][z] == wp[0][j + 1]) {
							wp[i + 1][j + 1] = 17;
						}
					}
					else {
						for (int l = 0; l < 2; l++) {
							if (re[bin][l] == wp[0][j + 1]) {
								wp[i + 1][j + 1] = 17;
							}
						}
					}
				}
			}
			if (i >= qt[2][0] + qt[2][1] + qt[2][2]) {
				bin++;
			}
		}
		for (int i = 0; i < sw + qt[2][0] + qt[2][1] + qt[2][2] + 1; i++) {  // 결과값 옮기기
			for (int j = 0; j < xl + 1; j++) {
				wp1[i][j] = wp[i][j];
			}
		}
		for (int j = 1; j < xl + 1; j++) {      //EPI 찾기
			for (int i = 0; i < sw + qt[2][0] + qt[2][1] + qt[2][2]; i++) {
				bin = 0;
				if (wp1[i + 1][j] == 17) {
					for (int z = 0; z < sw + qt[2][0] + qt[2][1] + qt[2][2] + 1; z++) {
						if (wp1[z + 1][j] == 17)
							bin++;
					}
				}
				if (bin == 1) {
					if (i == 0) {
						ui[b] = 20;  //0값은 INT 형에서 NULL값과 같으므로 구분을 위해 20을 0대신 넣음
					}
					else {
						ui[b] = i;
					}
					m[b] = j;
					b++;
				}
			}
		}
		for (int i = 0; i < b; i++) { //찾은 EPI위치 체크
			if (ui[i] == 20) {
				wp1[1][m[i]] = 21;
			}
			else {
				wp1[ui[i] + 1][m[i]] = 21;
			}
		}
		for (int i = 0; i < sw + qt[2][0] + qt[2][1] + qt[2][2]; i++) {  //숨겨진 EPI 가로축 찾기
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 21) {
					for (int z = 1; z < xl + 1; z++) {
						if (wp1[i + 1][z] == 17) {
							wp1[i + 1][z] = 18;
						}
					}
				}
			}
		}
		for (int i = 0; i < sw + qt[2][0] + qt[2][1] + qt[2][2]; i++) {  //숨겨진 EPI 세로축 찾기
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 18) {
					for (int l = 0; l < sw + qt[2][0] + qt[2][1] + qt[2][2]; l++) {
						if (wp1[l + 1][j] == 17) {
							wp1[l + 1][j] = 18;
						}
					}
				}
			}
		}
		a = 0;
		for (int i = 0; i < b; i++) { //중복된 epi 제거
			bin = 0;
			for (int j = i; j < b; j++) {
				if (i != j) {
					if (ui[i] == ui[j]) {
						ui[i] = { NULL };
					}
				}
			}
		}
		for (int i = 0; i < b; i++) {
			if (ui[i] != 0) {
				pe[a] = ui[i];
				a++;
			}
		}
		for (int i = 0; i < a; i++) {
			if (pe[i] == 20) {
				pe[i] = 0;
			}
			ui[i] = pe[i];
			pe[i] = { NULL };
		}
		b = a, a = 0;
		for (int i = 0; i < sw + qt[2][0] + qt[2][1] + qt[2][2]; i++) {  //숨겨진 EPI 값 확인
			bin = 0;
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 18) {
					bin++;
				}
			}
			if (bin == 0) {
				pe[a] = i;
				a++;
			}
		}
		int w = b;
		for (int i = 0; i < a; i++) {  //숨겨진 EPI값 최종 EPI값에 넣기
			bin = 0;
			for (int j = 0; j < w; j++) {
				if (ui[j] == pe[i]) {
					bin++;
				}
			}
			if (bin == 0) {
				ui[b] = pe[i];
				b++;
			}
		}
	}
	if (num == 3) {
		for (int i = 0; i < xl; i++) {    // 가로축테이블에 수 넣기
			wp[0][i + 1] = number[i];
		}
		for (int j = 0; j < sw + qt[3][0] + qt[3][1] + qt[3][2]; j++) {  //세로축 번호 넣기
			wp[j + 1][0] = j + 1;
		}
		for (int i = 0; i < qt[3][0]; i++) {   // 최종적으로 뽑힌 pi값들을 임의의 문자열배열에 넣기
			bow[a] = fbinary[i];
			a++;
		}
		for (int i = 0; i < qt[3][1]; i++) {  // 최종적으로 뽑힌 pi값들을 임의의 문자열배열에 넣기
			bow[a] = fbinary1[i];
			a++;
		}
		for (int i = 0; i < sw; i++) {  // 최종적으로 뽑힌 pi값들을 임의의 문자열배열에 넣기
			bow[a] = str[i];
			a++;
		}
		for (int i = 0; i < sw + qt[3][0] + qt[3][1]; i++) {  //테이블에 별찍기
			for (int j = 0; j < xl; j++) {
				for (int z = 0; z < 8; z++) {
					if (i < qt[3][0] + qt[3][1]) {
						if (number2[i][z] == wp[0][j + 1]) {
							wp[i + 1][j + 1] = 17;
						}
					}
					else {
						for (int l = 0; l < 4; l++) {
							if (re[bin][l] == wp[0][j + 1]) {
								wp[i + 1][j + 1] = 17;
							}
						}
					}
				}
			}
			if (i >= qt[3][0] + qt[3][1]) {
				bin++;
			}
		}
		for (int i = 0; i < sw + qt[2][0] + qt[2][1] + qt[2][2] + 1; i++) {  // 결과값 옮기기
			for (int j = 0; j < xl + 1; j++) {
				wp1[i][j] = wp[i][j];
			}
		}
		for (int j = 1; j < xl + 1; j++) {     // 1차 epi 뽑기
			for (int i = 0; i < sw + qt[3][0] + qt[3][1]; i++) {
				bin = 0;
				if (wp1[i + 1][j] == 17) {
					for (int z = 0; z < sw + qt[3][0] + qt[3][1] + 1; z++) {
						if (wp1[z + 1][j] == 17)
							bin++;
					}
				}
				if (bin == 1) {
					if (i == 0) {
						ui[b] = 20;  //0값은 INT 형에서 NULL값과 같으므로 구분을 위해 20을 0대신 넣음
					}
					else {
						ui[b] = i;
					}
					m[b] = j;
					b++;
				}
			}
		}
		for (int i = 0; i < b; i++) { //찾은 EPI위치 체크
			if (ui[i] == 20) {
				wp1[1][m[i]] = 21;
			}
			else {
				wp1[ui[i] + 1][m[i]] = 21;
			}
		}
		for (int i = 0; i < sw + qt[3][0] + qt[3][1]; i++) {  //숨겨진 EPI 가로축 찾기
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 21) {
					for (int z = 1; z < xl + 1; z++) {
						if (wp1[i + 1][z] == 17) {
							wp1[i + 1][z] = 18;
						}
					}
				}
			}
		}
		for (int i = 0; i < sw + qt[3][0] + qt[3][1]; i++) {  //숨겨진 EPI 세로축 찾기
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 18) {
					for (int l = 0; l < sw + qt[3][0] + qt[3][1]; l++) {
						if (wp1[l + 1][j] == 17) {
							wp1[l + 1][j] = 18;
						}
					}
				}
			}
		}
		for (int i = 0; i < b; i++) {   //1차 epi값들중 중복값 제거
			bin = 0;
			for (int j = i; j < b; j++) {
				if (i != j) {
					if (ui[i] == ui[j]) {
						ui[i] = { NULL };
					}
				}
			}
		}
		a = 0;
		for (int i = 0; i < b; i++) {
			if (ui[i] != 0) {
				pe[a] = ui[i];
				a++;
			}
		}
		for (int i = 0; i < a; i++) {
			if (pe[i] == 20) {
				pe[i] = 0;
			}
			ui[i] = pe[i];
			pe[i] = { NULL };
		}
		b = a, a = 0;
		for (int i = 0; i < sw + qt[3][0] + qt[3][1]; i++) {  // 숨겨진 epu 찾기
			bin = 0;
			for (int j = 1; j < xl + 1; j++) {
				if (wp1[i + 1][j] == 18) {
					bin++;
				}
			}
			if (bin == 0) {
				pe[a] = i;
				a++;
			}
		}
		int w = b;
		for (int i = 0; i < a; i++) {   //숨겨진 epi 값이 1차 epi 값이랑 다른지 확인
			bin = 0;
			for (int j = 0; j < w; j++) {
				if (ui[j] == pe[i]) {
					bin++;
				}
			}
			if (bin == 0) {
				ui[b] = pe[i];
				b++;
			}
		}
	}
	for (int i = 0; i < b; i++) { //최종 EPI 값
		epi[i] = bow[ui[i]];
	}
}
void rpi(string binary[96] = { }, string binary1[25] = { }, string binary2[25] = { }, string binary3[4] = { }, string binary4[1] = { }, string str[96] = { }, string fbinary[96] = { }, string fbinary1[25] = { }, string fbinary2[25] = { }, string fbinary3[4] = { }, string epi[16] = { }, string bow[16] = { }, string abinary1[12] = { }, string abinary2[12] = { }, string abinary3[12] = { }) { //번호 비교 후 추출
	int min = 0, bin = 0, cm = 0, e = 0, u = 0;
	if (num == 0) {
		EPI(binary, binary1, binary2, binary3, binary4, str, fbinary, fbinary1, fbinary2, fbinary3, epi, bow);
	}
	if (num == 1) {
		for (int z = 0; z < qt[0][0]; z++) {
			bin = 0;
			for (int i = 0; i < qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; i++) {
				for (int j = 0; j < 2; j++) {
					if (number2[i][j] == number[z]) {
						bin++;
					}
				}
			}
			if (bin == 0) {
				re[sw][0] = number[z];
				str[sw] = binary[min];
				sw++;
			}
			min++;
		}
		cout << endl;
		for (int z = qt[0][0]; z < qt[0][0] + qt[0][1]; z++) {
			bin = 0;
			for (int i = 0; i < qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; i++) {
				for (int j = 0; j < 2; j++) {
					if (number2[i][j] == number[z]) {
						bin++;
					}
				}
			}
			if (bin == 0) {
				re[sw][0] = number[z];
				str[sw] = binary1[min];
				sw++;
			}
			min++;
		}
		min = 0;
		for (int z = qt[0][0] + qt[0][1]; z < qt[0][0] + qt[0][1] + qt[0][2]; z++) {
			bin = 0;
			for (int i = 0; i < qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; i++) {
				for (int j = 0; j < 2; j++) {
					if (number2[i][j] == number[z]) {
						bin++;
					}
				}
			}
			if (bin == 0) {
				re[sw][0] = number[z];
				str[sw] = binary2[min];
				sw++;
			}
			min++;
		}
		min = 0;
		for (int z = qt[0][0] + qt[0][1] + qt[0][2]; z < qt[0][0] + qt[0][1] + qt[0][2] + qt[0][3]; z++) {
			bin = 0;
			for (int i = 0; i < qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; i++) {
				for (int j = 0; j < 2; j++) {
					if (number2[i][j] == number[z]) {
						bin++;
					}
				}
			}
			if (bin == 0) {
				re[sw][0] = number[z];
				str[sw] = binary3[min];
				sw++;
			}
			min++;
		}
		min = 0;
		for (int z = qt[0][0] + qt[0][1] + qt[0][2] + qt[0][3]; z < qt[0][0] + qt[0][1] + qt[0][2] + qt[0][3] + qt[0][4]; z++) {
			bin = 0;
			for (int i = 0; i < qt[1][0] + qt[1][3] + qt[1][1] + qt[1][2]; i++) {
				for (int j = 0; j < 2; j++) {
					if (number2[i][j] == number[z]) {
						bin++;
					}
				}
			}
			if (bin == 0) {
				re[sw][0] = number[z];
				str[sw] = binary4[min];
				sw++;
			}
			min++;
		}
		for (int i = 0; i < sw; i++) {
			for (int j = 0; j < 2; j++) {
				re1[i][j] = re[i][j];
			}
		}
		EPI(binary, binary1, binary2, binary3, binary4, str, fbinary, fbinary1, fbinary2, fbinary3, epi, bow);
	}
	if (num == 2) {
		for (int z = 0; z < qt[1][0]; z++) {
			cm = 0;
			for (int i = 0; i < qt[2][0] + qt[2][1] + qt[2][2]; i++) {
				bin = 0;
				for (int l = 0; l < 2; l++) {
					for (int j = 0; j < 4; j++) {
						if (number3[i][j] == number2[z][l]) {
							bin++;
						}
					}
				}
				if (bin >= 2) {
					cm++;
				}
			}
			if (cm == 0) {
				for (int i = 0; i < 2; i++) {
					re[sw][i] = number2[z][i];
				}
				str[sw] = fbinary[min];
				sw++;
			}
			min++;
		}
		min = 0;
		for (int z = qt[1][0]; z < qt[1][0] + qt[1][1]; z++) {
			cm = 0;
			for (int i = 0; i < qt[2][0] + qt[2][1] + qt[2][2]; i++) {
				bin = 0;
				for (int l = 0; l < 2; l++) {
					for (int j = 0; j < 4; j++) {
						if (number3[i][j] == number2[z][l]) {
							bin++;
						}
					}
				}
				if (bin >= 2) {
					cm++;
				}
			}
			if (cm == 0) {
				for (int i = 0; i < 2; i++) {
					re[sw][i] = number2[z][i];
				}
				str[sw] = fbinary1[min];
				sw++;
			}
			min++;
		}
		min = 0;
		for (int z = qt[1][0] + qt[1][1]; z < qt[1][0] + qt[1][1] + qt[1][2]; z++) {
			cm = 0;
			for (int i = 0; i < qt[2][0] + qt[2][1] + qt[2][2]; i++) {
				bin = 0;
				for (int l = 0; l < 2; l++) {
					for (int j = 0; j < 4; j++) {
						if (number3[i][j] == number2[z][l]) {
							bin++;
						}
					}
				}
				if (bin >= 2) {
					cm++;
				}
			}
			if (cm == 0) {
				for (int i = 0; i < 2; i++) {
					re[sw][i] = number2[z][i];
				}
				str[sw] = fbinary2[min];
				sw++;
			}
			min++;
		}
		min = 0;
		for (int z = qt[1][0] + qt[1][1] + qt[1][2]; z < qt[1][0] + qt[1][1] + qt[1][2] + qt[1][3]; z++) {
			cm = 0;
			for (int i = 0; i < qt[2][0] + qt[2][1] + qt[2][2]; i++) {
				bin = 0;
				for (int l = 0; l < 2; l++) {
					for (int j = 0; j < 4; j++) {
						if (number3[i][j] == number2[z][l]) {
							bin++;
						}
					}
				}
				if (bin >= 2) {
					cm++;
				}
			}
			if (cm == 0) {
				for (int i = 0; i < 2; i++) {
					re[sw][i] = number2[z][i];
				}
				str[sw] = fbinary3[min];
				sw++;
			}
			min++;
		}
		for (int i = 0; i < sw; i++) {
			for (int j = 0; j < 2; j++) {
				re1[i][j] = re[i][j];
			}
		}
		EPI(binary, binary1, binary2, binary3, binary4, str, fbinary, fbinary1, fbinary2, fbinary3, epi, bow);
	}
	if (num == 3) {
		for (int z = 0; z < qt[2][0]; z++) {
			cm = 0;
			for (int i = 0; i < qt[3][0] + qt[3][1]; i++) {
				bin = 0;
				for (int l = 0; l < 4; l++) {
					for (int j = 0; j < 8; j++) {
						if (number2[i][j] == number3[z][l]) {
							bin++;
						}
					}
				}
				if (bin >= 4) {
					cm++;
				}
			}
			if (cm == 0) {
				for (int i = 0; i < 4; i++) {
					re[sw][i] = number3[z][i];
				}
				str[sw] = binary[min];
				sw++;
			}
			min++;
		}
		min = 0;
		for (int z = qt[2][0]; z < qt[2][0] + qt[2][1]; z++) {
			cm = 0;
			for (int i = 0; i < qt[3][0] + qt[3][1]; i++) {
				bin = 0;
				for (int l = 0; l < 4; l++) {
					for (int j = 0; j < 8; j++) {
						if (number2[i][j] == number3[z][l]) {
							bin++;
						}
					}
				}
				if (bin >= 4) {
					cm++;
				}
			}
			if (cm == 0) {
				for (int i = 0; i < 4; i++) {
					re[sw][i] = number3[z][i];
				}
				str[sw] = binary1[min];
				sw++;
			}
			min++;
		}
		min = 0;
		for (int z = qt[2][0] + qt[2][1]; z < qt[2][0] + qt[2][1] + qt[2][2]; z++) {
			cm = 0;
			for (int i = 0; i < qt[3][0] + qt[3][1]; i++) {
				bin = 0;
				for (int l = 0; l < 4; l++) {
					for (int j = 0; j < 8; j++) {
						if (number2[i][j] == number3[z][l]) {
							bin++;
						}
					}
				}
				if (bin >= 4) {
					cm++;
				}
			}
			if (cm == 0) {
				for (int i = 0; i < 4; i++) {
					re[sw][i] = number3[z][i];
				}
				str[sw] = binary2[min];
				sw++;
			}
			min++;
		}
		for (int i = 0; i < sw; i++) {
			for (int j = 0; j < 4; j++) {
				re1[i][j] = re[i][j];
			}
		}
		EPI(binary, binary1, binary2, binary3, binary4, str, fbinary, fbinary1, fbinary2, fbinary3, epi, bow);
	}
	h = sw;
}
void print(string binary[96] = { }, string binary1[25] = { }, string binary2[25] = { }, string binary3[4] = { }, string binary4[1] = { }, string str[96] = { }, string fbinary[96] = { }, string fbinary1[25] = { }, string fbinary2[25] = { }, string fbinary3[4] = { }, string epi[16] = { }, string bow[16] = { }, string abinary1[12] = { }, string abinary2[12] = { }, string abinary3[12] = { }, string fabinary1[6] = {}, string fabinary2[14] = {}, string fabinary3[14] = { }, string fabinary4[6] = { })
{
	int bin = 0;
	if (y == 0) {
		system("cls");
		arr(binary, binary1, binary2, binary3, binary4);// 선택한 2진수들을 1의 갯수로 나누기
	}
	key = _getch();
	if (key == UP) {
		if (y > 0) {
			y--;
		}
	}
	if (key == DOWN) {
		if (num == 0) {
			if (y < 2) {
				y++;
			}
		}
		if (num == 1) {
			if (y < 4) {
				y++;
			}
		}
		if (num == 2) {
			if (y < 5) {
				y++;
			}
		}
		if (num == 3 || num == 4) {
			if (y < 6) {
				y++;
			}
		}
	}
	if (num == 0) {
		if (y == 1) {
			system("cls");
			printmap(epi, bow);
		}
	}
	if (num == 1) {
		if (y == 1) {
			system("cls");
			pia2(fabinary1, fabinary2, fabinary3, fabinary4); //1차 pi추출 값
		}
		if (y == 2) {
			system("cls");
			pia2(fabinary1, fabinary2, fabinary3, fabinary4);
			pia4(abinary1, abinary2, abinary3, fabinary1, abinary2, fabinary3, fabinary4, str, fbinary, fbinary1);// 번호 비교후 나오는 최종 pi 값
		}
		if (y == 3) {
			system("cls");
			printmap(epi, bow);
		}
	}
	if (num == 2) {
		if (y == 1) {
			system("cls");
			pia2(fabinary1, fabinary2, fabinary3, fabinary4); //1차 pi추출 값
		}
		if (y == 2) {
			system("cls");
			pia3(abinary1, abinary2, abinary3); //2차 pi 추출 값
		}
		if (y == 3) {
			system("cls");
			pia4(abinary1, abinary2, abinary3, fabinary1, abinary2, fabinary3, fabinary4, str, fbinary, fbinary1); // 번호 비교후 나오는 최종 pi 값
		}
		if (y == 4) {
			system("cls");
			printmap(epi, bow); //출력
		}
	}
	if (num == 3) {
		if (y == 1) {
			system("cls");
			pia2(fabinary1, fabinary2, fabinary3, fabinary4);
		}
		if (y == 2) {
			system("cls");
			pia3(abinary1, abinary2, abinary3); //3차 pi 추출
		}
		if (y == 3) {
			system("cls");
			pi3number(binary, binary1, str, fbinary, fbinary1);//3차 추출 pi 갯수세기
		}
		if (y == 4) {
			system("cls");
			pia4(abinary1, abinary2, abinary3, fabinary1, abinary2, fabinary3, fabinary4, str, fbinary, fbinary1);
		}
		if (y == 5) {
			system("cls");
			printmap(epi, bow);
		}
	}
	if (num == 4) { //전부다 1일 때
		if (y == 1) {
			system("cls");
			pia2(fabinary1, fabinary2, fabinary3, fabinary4);
		}
		if (y == 2) {
			system("cls");
			pia3(abinary1, abinary2, abinary3); //3차 pi 추출
		}
		if (y == 3) {
			system("cls");
			pi3number(binary, binary1, str, fbinary, fbinary1);//3차 pi 추출 값 
		}
		if (y == 4) {
			system("cls");
			cout << "____  0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16" << endl; //전부다 1일때 최종 값
		}
		if (y == 5) {
			system("cls");
			printmap(epi, bow);
		}
	}
}
void print1(string binary[96] = { }, string binary1[25] = { }, string binary2[25] = { }, string binary3[4] = { }, string binary4[1] = { }, string str[96] = { }, string fbinary[96] = { }, string fbinary1[25] = { }, string fbinary2[25] = { }, string fbinary3[4] = { }, string epi[16] = { }, string bow[16] = { }, string abinary1[12] = {}, string abinary2[12] = {}, string abinary3[12] = { }, string fabinary1[6] = {}, string fabinary2[14] = {}, string fabinary3[14] = { }, string fabinary4[6] = { }) {
	arr(binary, binary1, binary2, binary3, binary4);// 선택한 2진수들을 1의 갯수로 나누기
	pi1(binary, binary1, binary2, binary3, binary4, str, fbinary, fbinary1, fbinary2, fbinary3);//1차 pi추출		
	if (num != 0) {
		num = 0;
		pi2(binary, binary1, binary2, binary3, str, fbinary, fbinary1, fbinary2, fbinary3, fabinary1, fabinary2, fabinary3, fabinary4); //2차 pi 추출
		if (num != 0) {
			num = 0;
			pi3(binary, binary1, binary2, str, fbinary, fbinary1, fbinary2, abinary1, abinary2, abinary3); //3차 pi 추출
			if (num != 0) {
				pi3number(binary, binary1, str, fbinary, fbinary1);//3차 추출 pi 갯수세기
				if (xl == 16) {
					num = 4;
				}
				else {
					num = 3;
					rpi(binary, binary1, binary2, binary3, binary4, str, fbinary, fbinary1, fbinary2, fbinary3, epi, bow, abinary1, abinary2, abinary3);
				}
			}
			else {
				num = 2;
				rpi(binary, binary1, binary2, binary3, binary4, str, fbinary, fbinary1, fbinary2, fbinary3, epi, bow, abinary1, abinary2, abinary3);
			}
		}
		else {
			num = 1;
			rpi(binary, binary1, binary2, binary3, binary4, str, fbinary, fbinary1, fbinary2, fbinary3, epi, bow, abinary1, abinary2, abinary3);
		}
	}
	else {
		num = 0;
		rpi(binary, binary1, binary2, binary3, binary4, str, fbinary, fbinary1, fbinary2, fbinary3, epi, bow, abinary1, abinary2, abinary3);
	}
}
int main() {
	string binary[50] = {  }, binary1[25] = { }, binary2[25] = { }, binary3[6] = { }, binary4[1] = { }, str[50] = { }, fbinary[50] = { }, fbinary1[25] = { }, fbinary2[25] = { }, fbinary3[12] = { }, epi[16] = { }, bow[16] = { }, abinary1[12] = {}, abinary2[12] = {}, abinary3[12] = {}, fabinary1[6] = {}, fabinary2[14] = {}, fabinary3[14] = {}, fabinary4[6] = {}; // 1의 갯수별로 선언한 1차추출 배열		
	sel(); // 2진수 선택 		
	print1(binary, binary1, binary2, binary3, binary4, str, fbinary, fbinary1, fbinary2, fbinary3, epi, bow, abinary1, abinary2, abinary3, fabinary1, fabinary2, fabinary3, fabinary4);

	while (1) {
		print(binary, binary1, binary2, binary3, binary4, str, fbinary, fbinary1, fbinary2, fbinary3, epi, bow, abinary1, abinary2, abinary3, fabinary1, fabinary2, fabinary3, fabinary4); //PI추출 함수
	}

	return 0;
}
