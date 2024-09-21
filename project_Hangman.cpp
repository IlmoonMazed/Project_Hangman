# include "iGraphics.h"
#include <stdio.h>
#include<string.h>
#include<windows.h>
#include<mmsystem.h>
#include <winnt.h>


#pragma comment(lib,"winmm.lib") 


#define screenWidth 1200
#define screenHeight 672
#define boxTimerSpeed 25

int x = 300, y = 300, r = 20;
int gameStage = 0;
int menu = 1;
int level = 0;
int b_a_x=0, b_a_y=0;
int box_timer;
int clock_timer;
int alphabetNo=0;
int sizeOfTheWord=0;
int chance=6;
int ithLetterOfInputWord[4]={0};
int checkIfWordTaken[3][15]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int score=0;
int Time=300;
int m;
int WordInputMode=0;
int highScore[3];

bool sound = true;
bool box_timer_called = false;
bool clock_timer_called = false;
bool yes = true;
bool correctLetter = false;
bool showHint_1 = false, showHint_2 = false;
bool showHintInfo_1 = false, showHintInfo_2 = false;
bool WordInput = false;
bool WordInputTaken=false;
bool WordLimit=true;
bool HighestScore=false;


char chosenLetter;
char letter;



char chosenWord[20];
char completedWord[20]={' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '};
char inputWord [4][20], inputWordC[20];
char hint1[20], hint2[20];
char PlayerName[20];



char stand[6][20] = {"Stand/Stand_0.bmp","Stand/Stand_1.bmp","Stand/Stand_2.bmp","Stand/Stand_3.bmp","Stand/Stand_4.bmp","Stand/Stand_5.bmp"};
char hover_menu[5][30] = {"Pages/MenuOption.bmp", "Floating/Hover_Play.bmp", "Floating/Hover_Level.bmp", "Floating/Hover_Rules.bmp", "Floating/Hover_Credits.bmp"};
char hover_level[3][30] = {"Floating/Hover_Easy.bmp", "Floating/Hover_Medium.bmp", "Floating/Hover_Hard.bmp"};
char yes_no[2][20]={"Floating/No.bmp", "Floating/Yes.bmp"};
char hover_alphabets[26][20]={"LetterBox/a.bmp", "LetterBox/b.bmp", "LetterBox/c.bmp", "LetterBox/d.bmp", "LetterBox/e.bmp", "LetterBox/f.bmp", "LetterBox/g.bmp", "LetterBox/h.bmp", "LetterBox/i.bmp", "LetterBox/j.bmp", "LetterBox/k.bmp", "LetterBox/l.bmp", "LetterBox/m.bmp", "LetterBox/n.bmp", "LetterBox/o.bmp", "LetterBox/p.bmp", "LetterBox/q.bmp", "LetterBox/r.bmp", "LetterBox/s.bmp", "LetterBox/t.bmp", "LetterBox/u.bmp", "LetterBox/v.bmp", "LetterBox/w.bmp", "LetterBox/x.bmp", "LetterBox/y.bmp", "LetterBox/z.bmp"};
char alphabets[26] = {32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32,32};
char alphabetFonts[26][25] = {"wordFont/afont.bmp","wordFont/bfont.bmp","wordFont/cfont.bmp","wordFont/dfont.bmp","wordFont/efont.bmp","wordFont/ffont.bmp","wordFont/gfont.bmp","wordFont/hfont.bmp","wordFont/ifont.bmp","wordFont/jfont.bmp","wordFont/kfont.bmp","wordFont/lfont.bmp","wordFont/mfont.bmp","wordFont/nfont.bmp","wordFont/ofont.bmp","wordFont/pfont.bmp","wordFont/qfont.bmp","wordFont/rfont.bmp","wordFont/sfont.bmp","wordFont/tfont.bmp","wordFont/ufont.bmp","wordFont/vfont.bmp","wordFont/wfont.bmp","wordFont/xfont.bmp","wordFont/yfont.bmp","wordFont/zfont.bmp"};
char hnumberFonts[10][20] = {"Hint/0hfont.bmp","Hint/1hfont.bmp","Hint/2hfont.bmp","Hint/3hfont.bmp","Hint/4hfont.bmp","Hint/5hfont.bmp","Hint/6hfont.bmp","Hint/7hfont.bmp","Hint/8hfont.bmp","Hint/9hfont.bmp"};
char halphabetFonts[26][20] = {"Hint/ahfont.bmp","Hint/bhfont.bmp","Hint/chfont.bmp","Hint/dhfont.bmp","Hint/ehfont.bmp","Hint/fhfont.bmp","Hint/ghfont.bmp","Hint/hhfont.bmp","Hint/ihfont.bmp","Hint/jhfont.bmp","Hint/khfont.bmp","Hint/lhfont.bmp","Hint/mhfont.bmp","Hint/nhfont.bmp","Hint/ohfont.bmp","Hint/phfont.bmp","Hint/qhfont.bmp","Hint/rhfont.bmp","Hint/shfont.bmp","Hint/thfont.bmp","Hint/uhfont.bmp","Hint/vhfont.bmp","Hint/whfont.bmp","Hint/xhfont.bmp","Hint/yhfont.bmp","Hint/zhfont.bmp"};
char cnumberFonts[10][20] = {"Clock/0cfont.bmp","Clock/1cfont.bmp","Clock/2cfont.bmp","Clock/3cfont.bmp","Clock/4cfont.bmp","Clock/5cfont.bmp","Clock/6cfont.bmp","Clock/7cfont.bmp","Clock/8cfont.bmp","Clock/9cfont.bmp"};
char lbalphabetFonts[26][20] = {"LB/albfont.bmp","LB/blbfont.bmp","LB/clbfont.bmp","LB/dlbfont.bmp","LB/elbfont.bmp","LB/flbfont.bmp","LB/glbfont.bmp","LB/hlbfont.bmp","LB/ilbfont.bmp","LB/jlbfont.bmp","LB/klbfont.bmp","LB/llbfont.bmp","LB/mlbfont.bmp","LB/nlbfont.bmp","LB/olbfont.bmp","LB/plbfont.bmp","LB/qlbfont.bmp","LB/rlbfont.bmp","LB/slbfont.bmp","LB/tlbfont.bmp","LB/ulbfont.bmp","LB/vlbfont.bmp","LB/wlbfont.bmp","LB/xlbfont.bmp","LB/ylbfont.bmp","LB/zlbfont.bmp"};
char mistakeSounds[6][25] = {"Sounds/Mistake_1.wav","Sounds/Mistake_2.wav","Sounds/Mistake_3.wav","Sounds/Mistake_4.wav","Sounds/Mistake_5.wav"};
char highScorerName[3][25] = {"", "", ""};


FILE *words_file;
FILE *leaderBoard;



void StartPlay();

void move();

void checkLetter(char letter);

bool takeWord();

int checkWord(char word[]);

void restart();

void reinitialize();

void Clock();

void InputWord(char key);

bool checkScore();

void resetScore();



/* function iDraw() is called again and again by the system. */

void iDraw() {
	//place your drawing codes here
	iClear();
	
	// Showing GameStage 0 "Menu"
	if (gameStage == 0)
	{
		iShowBMP(0, 0, "Pages/MenuOption.bmp");
		if (menu)
			iShowBMP2(205, 445 - (menu - 1) * 85, hover_menu[menu], 0);
	}

	// Showing GameStage 1 before game
	if (gameStage == 1)
	{
		iShowBMP2(0, 0, "pages/Before_Start.bmp", 255);
		iShowBMP2(667 - (yes * 157), 137, yes_no[yes], 0);
	}

	// Showing GameStage 10 "Play"
	if (gameStage == 10)
	{
		iShowBMP(0, 0, "bg/Play_bg.bmp");
		iShowBMP2(b_a_x, b_a_y, "LetterBox/Box_Alphabet.bmp", 255);
		if (b_a_x >= 148)
		{									// letter box hover
			if (alphabetNo <= 4)
				iShowBMP(233 + alphabetNo * 48, 481, hover_alphabets[alphabetNo]);
			else if (alphabetNo <= 11)
				iShowBMP(185 + (alphabetNo - 5) * 48, 436, hover_alphabets[alphabetNo]);
			else if (alphabetNo <= 18)
				iShowBMP(185 + (alphabetNo - 12) * 48, 391, hover_alphabets[alphabetNo]);
			else if (alphabetNo <= 26)
				iShowBMP(185 + (alphabetNo - 19) * 48, 346, hover_alphabets[alphabetNo]);
		}

		for (int j = 0; j < strlen(chosenWord); j++)		// showing the word guessed
		{
			if (completedWord[j] != 32)
				iShowBMP(842 - (strlen(chosenWord) / 2) * 25 + j * 25, 570, alphabetFonts[completedWord[j] - 97]);
		}
		for (int j = 0; j < strlen(chosenWord); j++)		// showing the dashes
		{
			iShowBMP(840 - (strlen(chosenWord) / 2) * 25 + j * 25, 568, "wordFont/dash.bmp");
		}

		for (int j = 0; j < 26; j++)			// shhowing if the guessed letter is right or wrong 
		{
			if (alphabets[j] == '1')
			{
				if (j <= 4)
					iShowBMP2(228 + j * 48, 475, "Floating/right.bmp", 0);
				else if (j <= 11)
					iShowBMP2(180 + (j - 5) * 48, 431, "Floating/right.bmp", 0);
				else if (j <= 18)
					iShowBMP2(180 + (j - 12) * 48, 386, "Floating/right.bmp", 0);
				else if (j <= 26)
					iShowBMP2(180 + (j - 19) * 48, 341, "Floating/right.bmp", 0);
			}
			else if (alphabets[j] == '0')
			{
				if (j <= 4)
					iShowBMP2(228 + j * 48, 475, "Floating/wrong.bmp", 0);
				else if (j <= 11)
					iShowBMP2(180 + (j - 5) * 48, 431, "Floating/wrong.bmp", 0);
				else if (j <= 18)
					iShowBMP2(180 + (j - 12) * 48, 386, "Floating/wrong.bmp", 0);
				else if (j <= 26)
					iShowBMP2(180 + (j - 19) * 48, 341, "Floating/wrong.bmp", 0);
			}
		}

		//show clock
		iShowBMP2(1060, 552, "Clock/clock.bmp", 0);
		iShowBMP(1090, 605, cnumberFonts[0]);
		iShowBMP(1090 + 20, 605, cnumberFonts[Time / 60]);
		iShowBMP(1130, 605, "Clock/ccolon.bmp");
		iShowBMP(1093, 577, cnumberFonts[(Time % 60) / 10]);
		iShowBMP(1093 + 20, 577, cnumberFonts[(Time % 60) % 10]);

		// Showing hints
		if (showHint_1)
		{
			iShowBMP2(112, 160, "Hint/hint_box2.bmp", 0);
			int textBegin = 162;
			for (int i = 0; i < strlen(hint1); i++)
			{
				if (hint1[i] == 32)
					textBegin += 15;
				else
					iShowBMP(162 + i * 16, 185, halphabetFonts[hint1[i] - 97]);
			}
		}
		if (showHint_2)
		{
			iShowBMP2(112, 45, "Hint/hint_box2.bmp", 0);
			int textBegin = 162;
			for (int j = 0; j < strlen(hint2); j++)
			{
				if (hint2[j] == 32)
					textBegin += 15;
				else
					iShowBMP(162 + j * 16, 70, halphabetFonts[hint2[j] - 97]);
			}
		}
		iShowBMP2(0, 0, "Hint/hint_option.bmp", 0);

		if (showHintInfo_1)
			iShowBMP2(108, 228, "Hint/hint_info.bmp", 0);
		if (showHintInfo_2)
			iShowBMP2(108, 115, "Hint/hint_info.bmp", 0);

		// showing hangman
			iShowBMP(790,260,stand[6-chance]);

		if(Time<=0) gameStage = 11;		//keeps track of the time
	}

	// Showing GameStage 2 "Level"
	if (gameStage == 2)
	{
		iShowBMP(0, 0, "Pages/Level_Option.bmp");
		iShowBMP2(210, 430 - (level * 111), hover_level[level], 0);
	}

	// Showing GameStage 3 "Rules"
	if (gameStage == 3)
	{
		iShowBMP(0, 0, "Pages/Rules.bmp");
	}

	// Showing GameStage 4 "Credits"
	if (gameStage == 4)
	{
		iShowBMP(0, 0, "Pages/Credits.bmp");
	}

	// Showing GameSatge 5 "Against Who"
	if(gameStage==5) {
		iShowBMP(0,0,"Pages/againstWho.bmp");
	}

	// Showing GameSatge 6 "word and hints input taking"
	if(gameStage==6) {
		iShowBMP(0,0,"Pages/Input_word.bmp");

		//showing input text
		if(chosenWord[0] != ' ') {
			int textBegin1 = 530;
		for (int i = 0; i < strlen(chosenWord); i++)
		{
			if (chosenWord[i] == 32)
				textBegin1 += 15;
			else
				iShowBMP(530 + i * 18, 495, halphabetFonts[chosenWord[i] - 97]);
		}
		}
		
		if(hint1[0] !=' ') {
			int textBegin2 = 530;
		for (int i = 0; i < strlen(hint1); i++)
		{
			if (hint1[i] == 32)
				textBegin2 += 15;
			else
				iShowBMP(530 + i * 18, 390, halphabetFonts[hint1[i] - 97]);
		}
		}
		
		if(hint2[0] !=' ') {
			int textBegin3 = 530;
		for (int i = 0; i < strlen(hint2); i++)
		{
			if (hint2[i] == 32)
				textBegin3 += 15;
			else
				iShowBMP(530 + i * 18, 285, halphabetFonts[hint2[i] - 97]);
		}
		}
		
	}

	// Showing Input high scorer name
	if(gameStage==7)
	{
		iShowBMP(0, 0, "Pages/HighScorerName.bmp");

		// Showing Score
		int j = 0;
		int hs = score;
		while (hs)
		{
			iShowBMP(710 - j * 25, 410, hnumberFonts[hs % 10]);
			hs /= 10;
			j++;
		}

		// showing name
		int textBegin = 620;
		for (int i = 0; i < strlen(PlayerName); i++)
		{
			if (PlayerName[i] == 32)
				break;//textBegin += 15;
			else
				iShowBMP(640 + i * 34, 307, lbalphabetFonts[PlayerName[i] - 97]);
		}
	}

	// Showing Leaderboard
	if(gameStage==8)
	{
		iShowBMP(0, 0, "Pages/LeaderBoard.bmp");

		for (int i = 0; i < 3; i++)		// one iteration for each line
		{ 									
			int length = strlen(highScorerName[i]);
			int textBegin = 630 - length * 34;
			for (int j = 0; j < length; j++)		// player name
			{
				if (length)
					iShowBMP(textBegin + j * 34, 430 - i * 100, lbalphabetFonts[highScorerName[i][j] - 97]);
			}
			int j = 0;
			int hs = highScore[i];
			do										// high score
			{
				iShowBMP(760 - j * 25, 427 - i * 100, hnumberFonts[hs % 10]);
				hs /= 10;
				j++;
			} while (hs);
		}
		iShowBMP2(800, 0, "Floating/Reset.bmp", 0);
	}

	// Showing GameStage 11 "Dead"
	if (gameStage == 11)
	{
		iShowBMP(0, 0, "Pages/Dead.bmp");

		// Showing Score
		int j = 0;
		int hs = score;
		do
		{
			iShowBMP(788 - j * 25, 418, hnumberFonts[hs % 10]);
			hs /= 10;
			j++;
		} while (hs);

		// Showing High Score
		j = 0;
		hs = highScore[0];
		do
		{
			iShowBMP(792 - j * 25, 362, hnumberFonts[hs % 10]);
			hs /= 10;
			j++;
		} while (hs);
	}

	// Showing GameStage 12 "CorrectWord"
	if(gameStage==12) {
		iShowBMP(0,0,"Pages/CorrectWord.bmp");

		//showing score
		int showScore=score;
		int i=0;
		while(showScore!=0) {
			iShowBMP(680-i*21,405,hnumberFonts[showScore%10]);
			showScore/=10;
			i++;
		}

	}

	if (gameStage != 0)
		iShowBMP2(0, 547, "Floating/Back_Button.bmp", 0);		// back button

	if (sound)											// sound on / off
		iShowBMP2(1080, 0, "Floating/SoundOn.bmp", 0);		
	else
		iShowBMP2(1080, 0, "Floating/SoundOff.bmp", 0);
}

/*
	function iMouseMove() is called when the user presses and drags the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouseMove(int mx, int my) {
	printf("x = %d, y= %d\n",mx,my);
	//place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/
void iMouse(int button, int state, int mx, int my) {
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		//place your codes here
		//	printf("x = %d, y= %d\n",mx,my);
		if (gameStage == 0 && mx >= 205 && mx <= 490 && my >= 445 && my <= 510)
		{
			gameStage = 5;
			menu = 1;
		}
		else if (gameStage == 1 && mx >= 510 && mx <= 650 && my >= 135 && my <= 250)
			StartPlay();

		else if (gameStage == 1 && mx >= 665 && mx <= 805 && my >= 135 && my <= 250)
		{
			gameStage = 0; // show Play beforestart
			menu = 1;
		}
		else if (gameStage == 0 && mx >= 205 && mx <= 490 && my >= 360 && my <= 420)
		{
			gameStage = 2; // show Level
			menu = 2;
		}
		else if (gameStage == 0 && mx >= 205 && mx <= 490 && my >= 275 && my <= 330)
		{
			gameStage = 3; // show Rules
			menu = 3;
		}
		else if (gameStage == 0 && mx >= 205 && mx <= 490 && my >= 190 && my <= 245)
		{
			gameStage = 4; // show Credits
			menu = 4;
		}
		else if (gameStage == 2 && mx >= 210 && mx <= 480 && my >= 430 && my <= 480) 		// EASY level selected
		{
			level = 0;
			gameStage = 0;
			Time = 300;
		}
		else if (gameStage == 2 && mx >= 210 && mx <= 480 && my >= 320 && my <= 370)		// MEDIUM level selected
		{
			level = 1;
			gameStage = 0;
			Time = 180;
		}
		else if (gameStage == 2 && mx >= 210 && mx <= 480 && my >= 210 && my <= 260)		// HARD level selected
		{
			level = 2;
			gameStage = 0;
			Time = 120;
		}

		else if (gameStage == 5)
		{
			if (mx >= 485 && mx <= 770 && my >= 340 && my <= 425)		// RANDOM selected
				gameStage = 1;
			if (mx >= 485 && mx <= 770 && my >= 213 && my <= 300)		// CUSTOM selected
			{
				gameStage = 6;
				strcpy(chosenWord, " ");
				strcpy(hint1, " ");
				strcpy(hint2, " ");
			}
		}

		else if (gameStage == 6) 		// input word and hints
		{
			if (mx >= 495 && mx <= 865 && my >= 475 && my <= 560)		// input word
			{
				WordInput = true;
				WordInputMode = 1;
			}
			else if (mx >= 495 && mx <= 865 && my >= 370 && my <= 445)		// input hint 1 
			{
				WordInput = true;
				WordInputMode = 2;
			}
			else if (mx >= 495 && mx <= 865 && my >= 265 && my <= 340)		// input hint 1 
			{
				WordInput = true;
				WordInputMode = 3;
			}
			else
				WordInput = false;

			if (mx >= 485 && mx <= 585 && my >= 123 && my <= 205)		// Time selected 2 min
			{
				Time = 120;
				level = 0;
			}
			if (mx >= 645 && mx <= 745 && my >= 123 && my <= 205)		// Time selected 3 min
			{
				Time = 180;
				level = 1;
			}
			if (mx >= 795 && mx <= 895 && my >= 123 && my <= 205)		// Time selected 5 min
			{
				Time = 300;
				level = 2;
			}

			if (mx >= 85 && mx <= 212 && my >= 100 && my <= 230)		// CANCEL (X) Clicked
				gameStage = 5;		// against who page
			if ((mx >= 984 && mx <= 1085 && my >= 100 && my <= 190) || (mx >= 1044 && mx <= 1100 && my >= 190 && my <= 245))	// word and hints confirmed
			{
				WordInputTaken = true;
				gameStage = 1;
			}
		}

		else if (gameStage == 7)		// Name input for the high scorer
		{
			if (mx >= 390 && mx <= 590 && my >= 95 && my <= 220)		// Back Clicked
				gameStage = 12;
			if (mx >= 685 && mx <= 885 && my >= 95 && my <= 220)		// LB (LeaderBoard) selected
				gameStage = 8;
			if (mx >= 600 && mx <= 1005 && my >= 280 && my <= 365)		// Name input
			{
				WordInput = true;
				WordInputMode = 4;
			}
			else
				WordInput = false;
		}

		else if (gameStage == 8)		// LeaderBoard
		{
			if (mx >= 825 && mx <= 890 && my >= 85 && my <= 155)
				resetScore();
		}

		else if (gameStage == 11 && mx >= 550 && my >= 140 && mx <= 735 && my <= 260)
		{
			gameStage = 0;
			reinitialize();
		}

		else if (gameStage == 12)
		{
			if (mx >= 510 && my >= 137 && mx <= 642 && my <= 248)
			{
				StartPlay();
			}
			else if (mx >= 670 && my >= 140 && mx <= 803 && my <= 247)
			{
				gameStage = 0;
				reinitialize();
			}
		}

		else if(gameStage==10) {
			if (mx >= 231 && mx <= 452 && my >= 480 && my <= 508)
			{
				int k = (mx - 233) / 48;
				if (mx <= (233 + k * 48 + 24))
				{
					alphabetNo = k;
					chosenLetter = alphabetNo + 97;
					checkLetter(chosenLetter);
				}
			}

			else if (mx >= 183 && mx <= 497 && my >= 435 && my <= 463)
			{
				int k = (mx - 185) / 48;
				if (mx <= (185 + k * 48 + 24))
				{
					alphabetNo = k + 5;
					chosenLetter = alphabetNo + 97;
					checkLetter(chosenLetter);
				}
			}

			else if (mx >= 183 && mx <= 497 && my >= 390 && my <= 417)
			{
				int k = (mx - 185) / 48;
				if (mx <= (185 + k * 48 + 24))
				{
					alphabetNo = k + 12;
					chosenLetter = alphabetNo + 97;
					checkLetter(chosenLetter);
				}
			}

			else if (mx >= 183 && mx <= 497 && my >= 345 && my <= 372)
			{
				int k = (mx - 185) / 48;
				if (mx <= (185 + k * 48 + 24))
				{
					alphabetNo = k + 19;
					chosenLetter = alphabetNo + 97;
					checkLetter(chosenLetter);
				}
			}

			else if (mx>=105 && mx<=132 && my>=224 && my<=250)
			{
				showHintInfo_1 = true;
			}
			else if (mx>=395 && mx<=415 && my>=260 && my<=277)
			{
				showHintInfo_1 = false;
			}

			else if (mx>=105 && mx<=132 && my>=110 && my<=135)
			{
				showHintInfo_2 = true;
			}
			else if (mx>=395 && mx<=415 && my>=147 && my<=165)
			{
				showHintInfo_2 = false;
			}

			else if (mx >= 37 && my >= 152 && ((mx <= 130 && my <= 220) || (mx <= 102 && my <= 250)))
			{
				if (!showHint_1)
				{
					chance--;
					showHint_1 = true;
					PlaySound(TEXT("Sounds/WoodBreaking.wav"), NULL, SND_ASYNC | SND_FILENAME);
				}
			}

			else if (mx >= 37 && my >= 41 && ((mx <= 130 && my <= 105) || (mx <= 102 && my <= 135)))
			{
				if (!showHint_2)
				{
					chance--;
					showHint_2 = true;
					PlaySound(TEXT("Sounds/WoodBreaking.wav"), NULL, SND_ASYNC | SND_FILENAME);
				}
			}

			else if (mx >= 32 && mx <= 112 && my >= 555 && my <= 646)
			{
				reinitialize();
				gameStage = 0; // Back to homepage
			}
		} 


		// Back Button
		if (mx >= 37 && mx <= 112 && my >= 555 && my <= 635)
		{
			if (gameStage == 8)
				gameStage = 7;
			else if (gameStage == 10)
			{
				reinitialize();
				gameStage = 0;
			}
			else
				gameStage = 0; // Back to homepage
		}

		// Sound
		if (mx >= 1084 && mx <= 1160 && my >= 45 && my <= 125)
		{
			if (sound)
			{
				sound = false;
				PlaySound(NULL, NULL, SND_ASYNC);
			}
			else
			{
				sound = true;
				PlaySound(TEXT("Sounds/theme.wav"), NULL, SND_ASYNC | SND_LOOP);
			}
		}
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key) {

	if (WordInput)
		InputWord(key);

	if (gameStage == 1)
	{
		if (key == '\r')
		{
			if (yes)
			{
				StartPlay();
			}
			else if (!yes)
			{
				gameStage = 0; // show Play beforestart
				menu = 1;
			}
		}
	}

	else if (gameStage == 0)
	{
		if (key == '\r')
		{
			if (menu == 1)
				gameStage = 5;
			else
				gameStage = menu;
		}
	}

	else if (gameStage == 2)
	{
		if (key == '\r')
			gameStage = 0;
	}

	else if (gameStage == 10)
	{
		if (key == '\r')
		{
			chosenLetter = alphabetNo + 97;
			checkLetter(chosenLetter);
		}
		else if (key == ' ')
		{
			chosenLetter = alphabetNo + 97;
			checkLetter(chosenLetter);
		}

		else
		{
			alphabetNo = key - 97;
			chosenLetter = key;
		}
	}

	else if (gameStage==11)
	{
		if(key == '\r') gameStage=0;
	}
	

}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key) {

	if (key == GLUT_KEY_END) {
		exit(0);
	}
	//place your codes for other keys here

	if (key == GLUT_KEY_RIGHT)
	{
		if (gameStage == 1)
		{
			if (yes)
				yes = false;
			else
				yes = true;
		}

		if (gameStage == 10)
		{
			alphabetNo++;
			if (alphabetNo >= 26)
				alphabetNo = 0;
		}
	}

	if (key == GLUT_KEY_LEFT)
	{
		if (gameStage == 1)
		{
			if (yes)
				yes = false;
			else
				yes = true;
		}

		if (gameStage == 10)
		{
			alphabetNo--;
			if (alphabetNo < 0)
				alphabetNo = 25;
		}
	}

	if (key == GLUT_KEY_DOWN)
	{
		if (gameStage == 0)
		{
			menu++;
			if (menu > 4)
				menu = 1;
		}

		if (gameStage == 2)
		{
			level++;

			if (level > 2)
				level = 0;
		}
	}

	if (key == GLUT_KEY_UP)
	{
		if (gameStage == 0)
		{
			menu--;
			if (menu < 1)
				menu = 4;
		}

		if (gameStage == 2)
		{
			level--;

			if (level < 0)
				level = 2;
		}

		if (gameStage == 10)
		{
			if (alphabetNo == 5)
				alphabetNo = 20;
			else if (alphabetNo == 11)
				alphabetNo = 19;
			else if (alphabetNo > 11)
				alphabetNo -= 7;
			else if (alphabetNo >= 6)
				alphabetNo -= 6;
			else if (alphabetNo >= 0)
				alphabetNo += 21;
		}
	}

	if (key == GLUT_KEY_DOWN)
	{
		if (gameStage == 10)
		{
			if (alphabetNo == 24)
				alphabetNo = 11;
			else if (alphabetNo == 25)
				alphabetNo = 5;
			else if (alphabetNo < 5)
				alphabetNo += 6;
			else
				alphabetNo += 7;
			if (alphabetNo > 25)
				alphabetNo = alphabetNo % 26;
		}
	}

	if (key == GLUT_KEY_PAGE_DOWN)
	{
		if (gameStage != 10 && gameStage != 11)
			menu = gameStage;
		gameStage = 0;
	}
}

bool takeWord() {

	if (gameStage == 2)
	{
		gameStage = 0;
	}
	srand(time(0));
	int checker = 0;
	do
	{
		m = rand() % 15;
		checker++;

		if (checker > 10000)
		{
			break;
		}
	} while (checkIfWordTaken[level][m] == 1);
	checkIfWordTaken[level][m] = 1;
	if (checker > 10000)
	{
		return false;
	}

	int l = 0, j = 0;
	words_file = fopen("words_file.txt", "r");
	while (l < 3)
	{
		while (j < 15)
		{
			fscanf(words_file, "%s", chosenWord);
			fscanf(words_file, "%s", hint1);
			fscanf(words_file, "%s", hint2);
			j++;
			if (l == level && j == (m + 1))
				break;
		}
		if (l == level && j == (m + 1))
			break;
		j = 0;
		l++;
	}
	fclose(words_file);
	l = 0, j = 0;

	sizeOfTheWord=strlen(chosenWord);
	return true;
}

void move()
{
	if (b_a_x <= 150 && b_a_y <= 300)
	{
		b_a_x += 10;
		b_a_y += 20;
	}
	else
		iPauseTimer(box_timer);
}

int checkWord(char word[])
{
	int c = 0;
	for (int j = 0; j < strlen(chosenWord); j++)
	{
		if (word[j] == chosenWord[j])
			c++;
	}
	if (c == strlen(chosenWord))
		return 1;
	else
		return 0;
}

void StartPlay() 
{
	PlaySound(NULL, NULL, SND_ASYNC);
	gameStage = 10;
	if (!WordInputTaken)
		WordLimit = takeWord();
	if (WordLimit)
	{
		gameStage = 10; // show Play beforestart
		menu = 1;
		b_a_x = 0, b_a_y = 0;
		if (!box_timer_called)
			box_timer = iSetTimer(boxTimerSpeed, move);
		else
			iResumeTimer(box_timer);
		box_timer_called = true;

		if (!clock_timer_called)
			clock_timer = iSetTimer(1000, Clock);
		else
			iResumeTimer(clock_timer);
		clock_timer_called = true;
	}
	else
	{
		gameStage = 2;
		for (int k = 0; k < 3; k++)
		{
			for (int l = 0; l < 15; l++)
			{
				checkIfWordTaken[k][l] = 0;
			}
		}
		iText(600, 306, "CHOOSE ANOTHER LEVEL");
	}

	leaderBoard = fopen("leaderboard.txt", "r");
	for (int t = 0; t < 3; t++)
	{
		fscanf(leaderBoard, "%s %d", &highScorerName[t], &highScore[t]);
	}
	fclose(leaderBoard);
}

void restart()
{
	WordInputTaken = false;
	alphabetNo = 0;
	chance = 6;
	b_a_x = 0, b_a_y = 0;
	iPauseTimer(clock_timer);
	showHint_1 = false, showHint_2 = false;
	showHintInfo_1 = false, showHintInfo_2 = false;
	switch (level)
	{
	case 0:
		Time = 300;
		break;
	case 1:
		Time = 180;
		break;
	case 2:
		Time = 120;
		break;
	default:
		break;
	}
	for (int j = 0; j < 20; j++)
	{
		completedWord[j] = ' ';
	}
	for (int j = 0; j < 26; j++)
	{
		alphabets[j] = ' ';
	}
}

void reinitialize()
{
	restart();
	if (sound)
	{
		PlaySound(TEXT("Sounds/theme.wav"), NULL, SND_ASYNC | SND_LOOP);
	}
	score = 0;
	for (int k = 0; k < 3; k++)
	{
		for (int l = 0; l < 15; l++)
		{
			checkIfWordTaken[k][l] = 0;
		}
	}
	for(int i=0; i<4; i++) {
		for(int j=0; j<20; j++) {
			inputWord[i][j]='\0';
		}
		ithLetterOfInputWord[i]=0;
	}
	HighestScore = false;
}

void checkLetter(char letter)
{
	correctLetter = false;
	if (alphabets[letter - 97] == ' ')
	{
		for (int j = 0; j < sizeOfTheWord; j++)
		{
			if (letter == chosenWord[j])
			{
				alphabets[letter - 97] = '1';
				correctLetter = true;
				completedWord[j] = letter;
				if (sound)
					PlaySound(TEXT("Sounds/correct-choice.wav"), NULL, SND_ASYNC | SND_FILENAME);
			}
		}
		if (!correctLetter)
		{
			chance--;
			PlaySound(TEXT("Sounds/WoodBreaking.wav"), NULL, SND_ASYNC | SND_FILENAME);
			alphabets[letter - 97] = '0';
		}
	}

	if (chance <= 0)
	{
		gameStage = 11;
		restart();
	}

	if (checkWord(completedWord))
	{
		if (level == 0)
			score += chance + (Time / 50);
		else if (level == 1)
			score += chance + (Time / 30);
		else if (level == 2)
			score += chance + (Time / 20);
		if (checkScore())
			gameStage = 7;
		else
			gameStage = 12;
		restart();
	}
}

void Clock()
{
	if (Time >= 0)
		Time--;
	else
	{
		iPauseTimer(clock_timer);
	}
}

void InputWord(char key)
{
	if (key == '\r')
	{
		strcpy(inputWordC, inputWord[WordInputMode]);
		ithLetterOfInputWord[WordInputMode] = 0;
		WordInput = false;
	}
	else if (key == 8)
	{
		ithLetterOfInputWord[WordInputMode]--;
		inputWord[WordInputMode][ithLetterOfInputWord[WordInputMode]] = ' ';
	}
	else
	{
		alphabetNo = key - 97;
		inputWord[WordInputMode][ithLetterOfInputWord[WordInputMode]] = key;
		ithLetterOfInputWord[WordInputMode]++;
	}

	if (WordInputMode == 1)
	{
		strcpy(chosenWord, inputWord[1]);
		sizeOfTheWord = ithLetterOfInputWord[1];
	}
	else if (WordInputMode == 2)
		strcpy(hint1, inputWord[2]);
	else if (WordInputMode == 3)
		strcpy(hint2, inputWord[3]);
	else if (WordInputMode == 4)
	{
		strcpy(PlayerName, inputWord[4]);
		checkScore();
	}
}

bool checkScore()
{
	if (score >= highScore[2])
	{
		if (score >= highScore[0])
		{
			if (!HighestScore)
			{
				highScore[1] = highScore[0];
				strcpy(highScorerName[1], highScorerName[0]);
				highScore[0] = score;
				strcpy(highScorerName[0], PlayerName);
				HighestScore = true;
			}

			else
			{
				highScore[0] = score;
				strcpy(highScorerName[0], PlayerName);
			}
		}
		else if (score >= highScore[1])
		{
			highScore[2] = highScore[1];
			strcpy(highScorerName[2], highScorerName[1]);
			highScore[1] = score;
			strcpy(highScorerName[1], PlayerName);
		}
		else if (score >= highScore[2])
		{
			highScore[2] = score;
			strcpy(highScorerName[2], PlayerName);
		}

		leaderBoard = fopen("leaderboard.txt", "w");
		for (int i = 0; i < 3; i++)
		{
			fprintf(leaderBoard, "%s %d\n", highScorerName[i], highScore[i]);
		}
		fclose(leaderBoard);
		return true;
	}
	else
		return false;
}

void resetScore()
{
	for (int i = 0; i < 3; i++)
	{
		highScore[i] = 0;
		strcpy(highScorerName[i], "nobody");
	}
	leaderBoard = fopen("leaderboard.txt", "w");
	fprintf(leaderBoard, "%s %d \n%s %d \n%s %d", "nobody", 0, "nobody", 0, "nobody", 0);
	fclose(leaderBoard);
}

int main()
{
	// place your own initialization codes here.
	PlaySound(TEXT("Sounds/theme.wav"), NULL, SND_ASYNC | SND_LOOP | SND_NOSTOP);
	iInitialize(screenWidth, screenHeight, "Hangman");
}


// gamestage 0 - home
// gamestage 1 - before play
// gamestage 2 - level
// gamestage 3 - rules
// gamestage 4 - credits		
// gamestage 5 - against who
// gamestage 6 - input word and hints
// gameStage 7 - highscore
// gameStage 8 - leaderboard
// gamestage 10 - gameplay
// gamestage 11 - dead
// gamestage 12 - correctword 
