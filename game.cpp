#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

// header for game
void op();
void printW();
void printA();
void printR();
void printZ();
void printO();
void printN();
void printE();
void header();
void cls();
void soliders();
void SolidersActive();
void salute();
void anim();

// opening menu for game
int menu();

// Screen after player loses
void playerLose();
void youWin();

// levels
void level1(char &box, char playerPrint[], char playerPrint2[], char playerPrint3[], char enemy1Print[], char enemy1Print2[], char enemy2Print[], char enemy2Print2[], int &pX, int &pY, int &e1X, int &e1Y, int &e2X, int &e2Y, string &enemy1Direction, string &enemy2Direction, int &enemy1Health, int &enemy2Health, int &playerHealth, int &Score, bool &enemy1Dead, bool &enemy2Dead, bool &playerDead, bool &e1Alive, bool &e2Alive, int &count, int &count2, int &totalPlayerLives);

void level2(char &box, char playerPrint[], char playerPrint2[], char playerPrint3[], char enemy1Print[], char enemy1Print2[], char enemy2Print[], char enemy2Print2[], int &pX, int &pY, int &e1X, int &e1Y, int &e2X, int &e2Y, string &enemy1Direction, string &enemy2Direction, int &enemy1Health, int &enemy2Health, int &playerHealth, int &Score, bool &enemy1Dead, bool &enemy2Dead, bool &playerDead, bool &e1Alive, bool &e2Alive, int &count, int &count2, int &totalPlayerLives);

void level3(char &box, char playerPrint[], char playerPrint2[], char playerPrint3[], char enemy1Print[], char enemy1Print2[], char enemy2Print[], char enemy2Print2[], int &pX, int &pY, int &e1X, int &e1Y, int &e2X, int &e2Y, string &enemy1Direction, string &enemy2Direction, int &enemy1Health, int &enemy2Health, int &playerHealth, int &Score, bool &enemy1Dead, bool &enemy2Dead, bool &playerDead, bool &e1Alive, bool &e2Alive, int &count, int &count2, int &totalPlayerLives);

// Player movement built in functions
void gotoxy(int x, int y);
char getCharAtxy(short int x, short int y);
void loadingFunction();
int arrowMovement(int x, int y, int minOption, int maxOption);

// Display and erase player for all levels
void displayPlayer(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[]);
void erasePlayer(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[]);

// print maze for
void printMaze();
void mazeLvl1();
void mazeLv();

// moving player up,down,left and right
void movePlayerUp(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[], int &playerHealth);
void movePlayerDown(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[], int &playerHealth);
void movePlayerLeft(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[], int &playerHealth);
void movePlayerRight(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[], int &playerHealth);

// moving Enemy 1
void printEnemy(int &e1X, int &e1Y, char enemy1Print[], char enemy1Print2[]);
void eraseEnemy(int &e1X, int &e1Y, char enemy1Print[], char enemy1Print2[]);
void moveEnemy(int &e1X, int &e1Y, char enemy1Print[], char enemy1Print2[], string &enemy1Direction);
string conditionsEnemy1(int e1Y, string &directionEnemy1);

// moving Enemy 2
void printEnemy2(int &e2X, int &e2Y, char enemy2Print[], char enemy2Print2[]);
void eraseEnemy2(int &e2X, int &e2Y, char enemy2Print[], char enemy2Print2[]);
void moveEnemy2(int &e2X, int &e2Y, char enemy2Print[], char enemy2Print2[], string &enemy2Direction);
string conditionsEnemy2(int e2Y, string &directionEnemy2);

// moving enemy 3
void enemy3Movement(); // moves enemy 3
void enemy3Direction(int pX, int pY);
void eraseEnemy3(int x, int y);
void displayEnemy3Left(int x, int y);
void displayEnemy3Right(int x, int y);
void printEnemy3(char enemy3Print1[3], char enemy3Print2[3], char enemy3Print3[3], int x, int y);

// Score increment and health decrement functions
void scoreIncrement(int &Score);
void deductEnemy1Health(int &enemy1Health);
void deductEnemy2Health(int &enemy2Health);
void deductEnemy3Health();
void deductPlayerHealth(int &playerHealth);

void printScore(int &Score);
void printPlayerHealth(int &playerHealth);
void printEnemy1Health(int &enemy1Health);
void printEnemy2Health(int &enemy2Health);

void printEnemy3Health();

// player bullet functions
void printPlayerBullet(int &x, int &y);
void erasePlayerBullet(int &x, int &y);
void generatePlayerBullet(int &pX, int &pY, int bX[], int bY[], int &bulletCount);
void movePlayerBullet(int bX[], int bY[], int &bulletCount);
void removePlayerBulletFromArray(int bX[], int bY[], int &bulletCount, int i);
void playerBulletDamage(int &e1X, int &e1Y, int &e2X, int &e2Y, int bX[], int bY[], int &bulletCount, bool &e1Alive, bool &e2Alive, int &Score, int &enemy1Health, int &enemy2Health);

// enemy 1 bullet functions
void printEnemy1Bullet(int &x, int &y);
void generateEnemy1Bullet(int &e1X, int &e1Y, int &enemy1BulletCount, int e1bX[], int e1bY[]);
void moveEnemy1Bullet(int e1bX[], int e1bY[], int &enemy1BulletCount);
void removeEnemy1BulletFromArray(int e1bX[], int e1bY[], int &enemy1BulletCount, int &i);
void enemy1BulletDamage(int &pX, int &pY, int e1bX[], int e1bY[], int &enemy1BulletCount, int &playerHealth);

// enemy 2 bullet functions
void printEnemy2Bullet(int &x, int &y);
void generateEnemy2Bullet(int &e2X, int &e2Y, int &enemy2BulletCount, int e2bX[], int e2bY[]);
void moveEnemy2Bullet(int e2bX[], int e2bY[], int &enemy2BulletCount);
void removeEnemy2BulletFromArray(int e2bX[], int e2bY[], int &enemy2BulletCount, int &i);
void Enemy2BulletDamage(int &pX, int &pY, int e2bX[], int e2bY[], int &enemy2BulletCount, int &playerHealth);

void enemy3Damage(int &pX, int &pY, int &playerHealth);
// erasing enemy bullets  and 2
void eraseEnemyBullet(int &x, int &y);
void printLives(int &totalPlayerLives);

void enemy3Die(int e3X, int e3Y);

void hideCursor();

void mazeBoxes(int x, int y, int size);
void verticalmazeBoxes(int x, int y, int width, int height);
void mazeLvl3();
// Lvls

int e3X = 60, e3Y = 20;
int e3Count = 0;
string enemy3direction = "right";
int enemy3Health = 0;
bool enemy3Dead = false;
bool e3Alive = true;

char playerInTake;

int main()
{
    hideCursor();
    system("cls");
    op();
    Sleep(2500);
    system("cls");
    anim();
    char box = 219;
    // player
    char playerPrint[3] = {' ', 'O', ' '};
    char playerPrint2[3] = {'(', 'L', '='};
    char playerPrint3[3] = {'/', ')', ' '};

    // enemy1 and enemy2 of
    char enemy1Print[5] = {'<', '-', box, box, box};
    char enemy1Print2[5] = {' ', ' ', '0', ' ', '0'};

    char enemy2Print[5] = {'<', '-', box, box, box};
    char enemy2Print2[5] = {' ', ' ', '0', ' ', '0'};

    char enemy3Print[5] = {'<', '-', box, box, box};
    char enemy3Print2[5] = {' ', ' ', '0', ' ', '0'};

    // player co-ordinates
    int pX = 5;
    int pY = 5;

    // enemy 1 co-ordinates
    int e1X = 90;
    int e1Y = 30;

    // enemy 2 co-ordinates
    int e2X = 100;
    int e2Y = 3;

    // enemy 1 and 2 directions
    string enemy1Direction = "Up";
    string enemy2Direction = "Down";

    // Players and enemies health Variables
    int enemy1Health = 0;
    int enemy2Health = 0;
    int playerHealth = 0;

    // Score variable
    int Score = 0;
    bool enemy1Dead = false, enemy2Dead = false, playerDead = false;
    bool e1Alive = true, e2Alive = true;
    int count = 0, count2 = 0;
    int totalPlayerLives = 0;

    // Bullet count of player
    int bX[10000];
    int bY[10000];
    int bulletCount = 0;

    // Bullet count of enemy 1
    int e1bX[10000];
    int e1bY[10000];
    int enemy1BulletCount = 0;

    // Bullet count of enemy 2
    int e2bX[10000];
    int e2bY[10000];
    int enemy2BulletCount = 0;

    int maxBullets = 10000; //

    while (true)
    {
        int option = menu();

        if (option == 1)
        {
            pX = 5, pY = 5, e1Alive = true, e2Alive = true, e3Alive = true, enemy1Dead = false, enemy2Dead = false, enemy3Dead = false, playerDead = false, enemy1Health = 0, enemy2Health = 0, enemy3Health = 0, Score = 0;
            level1(box, playerPrint, playerPrint2, playerPrint3, enemy1Print, enemy1Print2, enemy2Print, enemy2Print2, pX, pY, e1X, e1Y, e2X, e2Y, enemy1Direction, enemy2Direction, enemy1Health, enemy2Health, playerHealth, Score, enemy1Dead, enemy2Dead, playerDead, e1Alive, e2Alive, count, count2, totalPlayerLives);
        }
        else if (option == 2)
        {
            pX = 5, pY = 5, e1Alive = true, e2Alive = true, enemy1Dead = false, enemy2Dead = false, playerDead = false, enemy1Health = 0, enemy2Health = 0, Score = 0;
            level2(box, playerPrint, playerPrint2, playerPrint3, enemy1Print, enemy1Print2, enemy2Print, enemy2Print2, pX, pY, e1X, e1Y, e2X, e2Y, enemy1Direction, enemy2Direction, enemy1Health, enemy2Health, playerHealth, Score, enemy1Dead, enemy2Dead, playerDead, e1Alive, e2Alive, count, count2, totalPlayerLives);
        }
        else if (option == 3)
        {
            pX = 5, pY = 5, e1Alive = true, e2Alive = true, e3Alive = true, enemy1Dead = false, enemy2Dead = false, enemy3Dead = false, playerDead = false, enemy1Health = 0, enemy2Health = 0, enemy3Health = 0, Score = 0;
            level3(box, playerPrint, playerPrint2, playerPrint3, enemy1Print, enemy1Print2, enemy2Print, enemy2Print2, pX, pY, e1X, e1Y, e2X, e2Y, enemy1Direction, enemy2Direction, enemy1Health, enemy2Health, playerHealth, Score, enemy1Dead, enemy2Dead, playerDead, e1Alive, e2Alive, count, count2, totalPlayerLives);
        }
        else
        {
            exit(0);
        }
    }
}

void header()
{
    SetConsoleTextAttribute(hConsole, 4);
    char box = 219;
    gotoxy(60, 3);
    cout << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box;
    gotoxy(60, 4);
    cout << box
         << "                                                 " << box;
    gotoxy(60, 5);
    cout << box
         << " \\ \\      / /__ _  _ __  ____ ___   _ __    ___  " << box;
    gotoxy(60, 6);
    cout << box
         << "  \\ \\ /\\ / // _` || '__||_  // _ \\ | '_ \\  / _ \\ " << box;
    gotoxy(60, 7);
    cout << box
         << "   \\ V  V /| (_| || |    / /| (_) || | | ||  __/ " << box;
    gotoxy(60, 8);
    cout << box
         << "    \\_/\\_/  \\__,_||_|   /___|\\___/ |_| |_| \\___| " << box;
    gotoxy(60, 9);
    cout << box
         << "                                                 " << box;
    gotoxy(60, 10);
    cout << box
         << "                                                 " << box;
    gotoxy(60, 11);
    cout << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box << box;
    SetConsoleTextAttribute(hConsole, 7);
}

int menu()
{
    system("cls");
    header();
    gotoxy(70, 17);
    cout << "\33[33m"
         << "1. Play Easy Difficulty Level\n";
    gotoxy(70, 18);
    cout << "2. Play Medium Difficulty Level\n";
    gotoxy(70, 19);
    cout << "3. Play Hard Difficulty Level"
         << "\33[0m";
    gotoxy(70, 20);
    cout << "\33[31m"
         << "4. Exit"
         << "\33[0m";
    gotoxy(67, 21);
    int option = arrowMovement(67, 17, 1, 4);
    loadingFunction();
    return option;
}

int arrowMovement(int x, int y, int minOption, int maxOption)
{
    int key;
    gotoxy(x, y);
    cout << "\33[32m"
         << "o>";

    do
    {
        key = _getch();

        gotoxy(x, y);
        cout << "  ";

        if (key == 72 && minOption > 1)
        {
            minOption--;
            y = y - 1;
        }
        else if (key == 80 && minOption < maxOption)
        {
            minOption++;
            y = y + 1;
        }

        gotoxy(x, y);
        cout << "o>";

    } while (key != 13); 
    return minOption;
}
void loadingFunction()
{
    int x = 48, y = 3;
    char box = 219; // ASCII code for a filled box

    gotoxy(x + 29, y + 28);
    cout << "Loading...";

    // Position the loading cursor at the start
    gotoxy(x, y + 30);
    cout << box;

    for (int i = 0; i < 72; i++)
    {
        Sleep(20);
        x++;
        gotoxy(x, y + 30);
        cout << box;
    }
}

void cls()
{
    cout << "\33[31m"
         << "\t\t\t\t\t\tPress any key to continue.";
    char ch = getch();
}

void playerLose()
{
    SetConsoleTextAttribute(hConsole, 4);
    gotoxy(60, 11);
    cout << " _____                                         _____ ";
    gotoxy(60, 12);
    cout << "( ___ )                                       ( ___ )";
    gotoxy(60, 13);
    cout << " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ";
    gotoxy(60, 14);
    cout << " |   | __   __            _                    |   | ";
    gotoxy(60, 15);
    cout << " |   | \\ \\ / /__  _   _  | |    ___  ___  ___  |   | ";
    gotoxy(60, 16);
    cout << " |   |  \\ V / _ \\| | | | | |   / _ \\/ __|/ _ \\ |   | ";
    gotoxy(60, 17);
    cout << " |   |   | | (_) | |_| | | |__| (_) \\__ \\  __/ |   | ";
    gotoxy(60, 18);
    cout << " |   |   |_|\\___/ \\__,_| |_____\\___/|___/\\___| |   | ";
    gotoxy(60, 19);
    cout << " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| ";
    gotoxy(60, 20);
    cout << "(_____)                                       (_____)\n";
    Sleep(3000);
    SetConsoleTextAttribute(hConsole, 7);
}

void level1(char &box, char playerPrint[], char playerPrint2[], char playerPrint3[], char enemy1Print[], char enemy1Print2[], char enemy2Print[], char enemy2Print2[], int &pX, int &pY, int &e1X, int &e1Y, int &e2X, int &e2Y, string &enemy1Direction, string &enemy2Direction, int &enemy1Health, int &enemy2Health, int &playerHealth, int &Score, bool &enemy1Dead, bool &enemy2Dead, bool &playerDead, bool &e1Alive, bool &e2Alive, int &count, int &count2, int &totalPlayerLives)
{
    bool playerWin = false;
    totalPlayerLives = 3;

    // Bullet count of player
    while (true)
    {
        int bX[10000];
        int bY[10000];
        int bulletCount = 0;

        // Bullet count of enemy 1
        int e1bX[10000];
        int e1bY[10000];
        int enemy1BulletCount = 0;

        // Bullet count of enemy 2
        int e2bX[10000];
        int e2bY[10000];
        int enemy2BulletCount = 0;

        int maxBullets = 10000; //

        playerHealth = 0;
        count = 0, count2 = 0;
        bool aliveAgain = false;

        system("cls");
        mazeLvl1();
        displayPlayer(pX, pY, playerPrint, playerPrint2, playerPrint3);
        printEnemy(e1X, e1Y, enemy1Print, enemy1Print2);
        printEnemy2(e2X, e2Y, enemy2Print, enemy2Print2);
        while (true)
        {
            if (enemy1Health <= 100)
            {
                moveEnemy(e1X, e1Y, enemy1Print, enemy1Print2, enemy1Direction);
                printEnemy1Health(enemy1Health);
            }
            else
            {
                eraseEnemy(e1X, e1Y, enemy1Print, enemy1Print2);
                enemy1Dead = true;
                e1Alive = false;
            }
            if (enemy2Health <= 100)
            {
                moveEnemy2(e2X, e2Y, enemy2Print, enemy2Print2, enemy2Direction);
                printEnemy2Health(enemy2Health);
            }
            else
            {
                eraseEnemy2(e2X, e2Y, enemy2Print, enemy2Print2);
                enemy2Dead = true;
                e2Alive = false;
            }
            if (enemy3Health <= 100)
            {
                enemy3Direction(pX, pY);
                printEnemy3Health();
            }
            else
            {
                enemy3Dead = true;
                e3Alive = false;
                enemy3Die(e3X, e3Y);
            }
            if (enemy1Dead && enemy2Dead && enemy3Dead)
            {
                playerWin = true;
                break;
            }
            if (playerHealth <= 100)
            {
                printScore(Score);
                printPlayerHealth(playerHealth);
                printLives(totalPlayerLives);
            }
            else
            {
                if (totalPlayerLives == 1)
                {
                    playerDead = true;
                    break;
                }
                totalPlayerLives = totalPlayerLives - 1;
                pX = 5, pY = 5;
                aliveAgain = true;
                break;
            }
            if (GetAsyncKeyState(VK_LEFT))
            {
                movePlayerLeft(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_RIGHT))
            {
                movePlayerRight(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_UP))
            {
                movePlayerUp(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                movePlayerDown(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_SPACE))
            {
                generatePlayerBullet(pX, pY, bX, bY, bulletCount);
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                return;
            }
            if (count == 7 && enemy1Dead == 0)
            {
                generateEnemy1Bullet(e1X, e1Y, enemy1BulletCount, e1bX, e1bY);
                count = 0;
            }
            if (count2 == 7 && enemy2Dead == 0)
            {
                generateEnemy2Bullet(e2X, e2Y, enemy2BulletCount, e2bX, e2bY);
                count2 = 0;
            }
            movePlayerBullet(bX, bY, bulletCount);
            playerBulletDamage(e1X, e1Y, e2X, e2Y, bX, bY, bulletCount, e1Alive, e2Alive, Score, enemy1Health, enemy2Health);
            moveEnemy1Bullet(e1bX, e1bY, enemy1BulletCount);
            enemy1BulletDamage(pX, pY, e1bX, e1bY, enemy1BulletCount, playerHealth);
            moveEnemy2Bullet(e2bX, e2bY, enemy2BulletCount);
            Enemy2BulletDamage(pX, pY, e2bX, e2bY, enemy2BulletCount, playerHealth);
            enemy3Damage(pX, pY, playerHealth);
            count++;
            count2++;
            Sleep(35);
        }
        if (aliveAgain)
        {
            continue;
        }
        if (playerDead)
        {
            system("cls");
            playerLose();
            break;
        }
        if (playerWin)
        {
            system("cls");
            youWin();
            cls();
            return;
        }
    }
}

void printMaze()
{
    fstream file;
    file.open("maze.txt", ios::in);

    if (!file.is_open())
    {
        cerr << "Unable to open file: " << endl;
        return;
    }

    string line;
    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();
}

void mazeBoxes(int x, int y, int size)
{
    char box = 219;
    for (int i = 0; i < size; i++)
    {
        gotoxy(x + i, y);
        cout << "\33[92m" << box << "\33[0m";
    }
}

void verticalmazeBoxes(int x, int y, int width, int height)
{
    for (int i = 0; i < height; i++)
    {
        mazeBoxes(x, y + i, width);
    }
}

void mazeLvl1()
{
    // boundaries
    mazeBoxes(1, 2, 124);
    mazeBoxes(1, 35, 124);
    verticalmazeBoxes(1, 2, 2, 34);
    verticalmazeBoxes(124, 2, 2, 34);

    mazeBoxes(23, 6, 20);
    mazeBoxes(24, 6, 20);

    mazeBoxes(40, 15, 20);
    mazeBoxes(41, 15, 20);

    verticalmazeBoxes(36, 20, 2, 10);
    verticalmazeBoxes(81, 25, 2, 10);
}

void mazeLv()
{
    // boundaries
    mazeBoxes(1, 2, 124);
    mazeBoxes(1, 35, 124);
    verticalmazeBoxes(1, 2, 2, 34);
    verticalmazeBoxes(124, 2, 2, 34);

    verticalmazeBoxes(23, 25, 2, 9);
    verticalmazeBoxes(24, 25, 2, 9);
    verticalmazeBoxes(25, 25, 2, 9);

    verticalmazeBoxes(43, 8, 2, 10);
    verticalmazeBoxes(44, 8, 2, 10);
    verticalmazeBoxes(45, 8, 2, 10);

    verticalmazeBoxes(59, 16, 5, 12);

    mazeBoxes(59, 21, 19);
    mazeBoxes(59, 22, 19);
    mazeBoxes(59, 23, 19);

    verticalmazeBoxes(78, 6, 4, 6);

    verticalmazeBoxes(84, 26, 4, 5);
}

void displayPlayer(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[])
{
    gotoxy(pX, pY);
    for (int i = 0; i < 3; i++)
    {
        cout << "\33[32m" << playerPrint[i];
    }
    gotoxy(pX, pY + 1);
    for (int i = 0; i < 3; i++)
    {
        cout << "\33[32m" << playerPrint2[i];
    }
    gotoxy(pX, pY + 2);
    for (int i = 0; i < 3; i++)
    {
        cout << "\33[32m" << playerPrint3[i];
    }
    cout << "\33[0m";
}

void erasePlayer(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[])
{
    gotoxy(pX, pY);
    for (int i = 0; i < 3; i++)
    {
        cout << "\33[32m"
             << " ";
    }
    gotoxy(pX, pY + 1);
    for (int i = 0; i < 3; i++)
    {
        cout << "\33[32m"
             << " ";
    }
    gotoxy(pX, pY + 2);
    for (int i = 0; i < 3; i++)
    {
        cout << "\33[32m"
             << " ";
    }
}

void movePlayerLeft(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[], int &playerHealth)
{
    if (getCharAtxy(pX - 2, pY) == ' ' && getCharAtxy(pX - 2, pY + 1) == ' ' && getCharAtxy(pX - 2, pY + 2) == ' ') /*getCharAtxy(pX - 2, pY) == ' ' && getCharAtxy(pX - 2, pY) == ' ' && getCharAtxy(pX - 2, pY + 1) == ' ' && getCharAtxy(pX - 2, pY + 1) == ' ' && getCharAtxy(pX - 2, pY + 1) == ' ' && getCharAtxy(pX - 2, pY + 1) == ' ' && getCharAtxy(pX - 2, pY + 2) == ' ' && getCharAtxy(pX - 2, pY + 2) == ' ')*/
    {
        erasePlayer(pX, pY, playerPrint, playerPrint2, playerPrint3);
        pX = pX - 1;
        displayPlayer(pX, pY, playerPrint, playerPrint2, playerPrint3);
    }
}

void movePlayerRight(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[], int &playerHealth)
{
    if (getCharAtxy(pX + 6, pY) == ' ' && getCharAtxy(pX + 6, pY + 1) == ' ' && getCharAtxy(pX + 6, pY + 2) == ' ') //&& getCharAtxy(pX + 7, pY) == ' ' && getCharAtxy(pX + 8, pY) == ' ' && getCharAtxy(pX + 6, pY) + 1 == ' ' && getCharAtxy(pX + 7, pY + 1) == ' ' && getCharAtxy(pX + 8, pY + 1) == ' ' && getCharAtxy(pX + 6, pY + 2) == ' ' && getCharAtxy(pX + 7, pY + 2) == ' ' && getCharAtxy(pX + 8, pY + 2) == ' ')
    {
        erasePlayer(pX, pY, playerPrint, playerPrint2, playerPrint3);
        pX = pX + 1;
        displayPlayer(pX, pY, playerPrint, playerPrint2, playerPrint3);
    }
}

void movePlayerUp(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[], int &playerHealth)
{
    char box = 219;
    if (getCharAtxy(pX, pY - 1) == ' ' && getCharAtxy(pX + 1, pY - 1) == ' ' && getCharAtxy(pX + 2, pY - 1 == ' ') && getCharAtxy(pX + 3, pY - 1 == ' ') && getCharAtxy(pX + 4, pY - 1) == ' ' && getCharAtxy(pX, pY - 1) && getCharAtxy(pX + 1, pY - 1) == ' ' && getCharAtxy(pX + 2, pY - 1) == ' ' && getCharAtxy(pX, pY - 1) && getCharAtxy(pX + 1, pY - 1) == ' ' && getCharAtxy(pX + 2, pY - 1) == ' ' && getCharAtxy(pX + 3, pY - 1) == ' ')
    {
        erasePlayer(pX, pY, playerPrint, playerPrint2, playerPrint3);
        pY = pY - 1;
        displayPlayer(pX, pY, playerPrint, playerPrint2, playerPrint3);
    }
}

void movePlayerDown(int &pX, int &pY, char playerPrint[], char playerPrint2[], char playerPrint3[], int &playerHealth)
{
    if (getCharAtxy(pX, pY + 3) == ' ' && getCharAtxy(pX + 1, pY + 3) == ' ' && getCharAtxy(pX + 2, pY + 3 == ' ') && getCharAtxy(pX + 3, pY + 3 == ' ') && getCharAtxy(pX + 4, pY + 3 == ' ') && getCharAtxy(pX, pY + 4) && getCharAtxy(pX + 1, pY + 4) == ' ' && getCharAtxy(pX + 2, pY + 4) == ' ' && getCharAtxy(pX + 3, pY + 4) == ' ' && getCharAtxy(pX + 4, pY + 4) == ' ') //&& getCharAtxy(pX, pY + 5) && getCharAtxy(pX + 1, pY + 5) == ' ' && getCharAtxy(pX + 2, pY + 5) == ' ' && getCharAtxy(pX + 3, pY + 5) == ' ' && getCharAtxy(pX + 4, pY + 5) == ' ')
    {
        erasePlayer(pX, pY, playerPrint, playerPrint2, playerPrint3);
        pY = pY + 1;
        displayPlayer(pX, pY, playerPrint, playerPrint2, playerPrint3);
    }
}

void printPlayerBullet(int &x, int &y)
{
    gotoxy(x, y);
    cout << "\33[32m"
         << ".";
}

void erasePlayerBullet(int &x, int &y)
{
    gotoxy(x, y);
    cout << "\33[32m"
         << " ";
}

void generatePlayerBullet(int &pX, int &pY, int bX[], int bY[], int &bulletCount)
{
    bX[bulletCount] = pX + 4;
    bY[bulletCount] = pY + 1;
    gotoxy(pX + 4, pY + 1);
    cout << "\33[32m"
         << ".";
    bulletCount++;
}

void removePlayerBulletFromArray(int bX[], int bY[], int &bulletCount, int i)
{
    for (int x = i; x < bulletCount - 1; x++)
    {
        bX[x] = bX[x + 1];
        bY[x] = bY[x + 1];
    }
    bulletCount--;
}

void movePlayerBullet(int bX[], int bY[], int &bulletCount)
{
    for (int x = 0; x < bulletCount; x++)
    {
        char next = getCharAtxy(bX[x] + 1, bY[x]);
        if ((next != ' ') || (next == '#') || (next == '-'))
        {
            erasePlayerBullet(bX[x], bY[x]);
            removePlayerBulletFromArray(bX, bY, bulletCount, x);
        }
        else
        {
            erasePlayerBullet(bX[x], bY[x]);
            bX[x] = bX[x] + 1;
            printPlayerBullet(bX[x], bY[x]);
        }
    }
}

void playerBulletDamage(int &e1X, int &e1Y, int &e2X, int &e2Y, int bX[], int bY[], int &bulletCount, bool &e1Alive, bool &e2Alive, int &Score, int &enemy1Health, int &enemy2Health)
{
    for (int x = 0; x < bulletCount; x++)
    {
        if (e1Alive == true)
        {
            if (((bX[x] >= e1X && bX[x] <= e1X + 4) && (bY[x] >= e1Y && bY[x] <= e1Y + 1)) ||
                ((bX[x] + 1 >= e1X && bX[x] + 1 <= e1X + 4) && (bY[x] >= e1Y && bY[x] <= e1Y + 1)))
            {
                deductEnemy1Health(enemy1Health);
                scoreIncrement(Score);
                erasePlayerBullet(bX[x], bY[x]);
                removePlayerBulletFromArray(bX, bY, bulletCount, x);
            }
        }
        if (e2Alive == true)
        {
            if (((bX[x] >= e2X && bX[x] <= e2X + 4) && (bY[x] >= e2Y && bY[x] <= e2Y + 1)) ||
                ((bX[x] + 1 >= e2X && bX[x] + 1 <= e2X + 4) && (bY[x] >= e2Y && bY[x] <= e2Y + 1)))
            {
                deductEnemy2Health(enemy2Health);
                scoreIncrement(Score);
                erasePlayerBullet(bX[x], bY[x]);
                removePlayerBulletFromArray(bX, bY, bulletCount, x);
            }
        }
        if (e3Alive == true)
        {
            if (((bX[x] >= e3X && bX[x] <= e3X + 2) && (bY[x] >= e3Y && bY[x] <= e3Y + 2)) ||
                ((bX[x] + 1 >= e3X && bX[x] + 1 <= e3X + 2) && (bY[x] >= e3Y && bY[x] <= e3Y + 2)))
            {
                deductEnemy3Health();
                scoreIncrement(Score);
                erasePlayerBullet(bX[x], bY[x]);
                removePlayerBulletFromArray(bX, bY, bulletCount, x);
            }
        }
    }
}

void deductEnemy1Health(int &enemy1Health)
{
    enemy1Health = enemy1Health + 5;
}

void printEnemy1Health(int &enemy1Health)
{
    gotoxy(127, 7);
    cout << "\33[33m"
         << "Enemy health is: " << enemy1Health << "/100";
}

void deductEnemy2Health(int &enemy2Health)
{
    enemy2Health = enemy2Health + 5;
}

void printEnemy2Health(int &enemy2Health)
{
    gotoxy(127, 8);
    cout << "\33[31m"
         << "Enemy 2 health is: " << enemy2Health << "/100";
}

void deductEnemy3Health()
{
    enemy3Health = enemy3Health + 5;
}

void printEnemy3Health()
{
    gotoxy(127, 9);
    cout << "\33[35m"
         << "Enemy 3 health is: " << enemy3Health << "/100";
}

void printEnemy(int &e1X, int &e1Y, char enemy1Print[], char enemy1Print2[])
{
    gotoxy(e1X, e1Y);
    for (int i = 0; i < 5; i++)
    {
        cout << "\33[33m" << enemy1Print[i];
    }
    gotoxy(e1X, e1Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << "\33[33m" << enemy1Print2[i];
    }
}

void eraseEnemy(int &e1X, int &e1Y, char enemy1Print[], char enemy1Print2[])
{
    gotoxy(e1X, e1Y);
    for (int i = 0; i < 5; i++)
    {
        cout << "\33[33m"
             << " ";
    }
    gotoxy(e1X, e1Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << "\33[33m"
             << " ";
    }
}

void moveEnemy(int &e1X, int &e1Y, char enemy1Print[], char enemy1Print2[], string &enemy1Direction)
{
    eraseEnemy(e1X, e1Y, enemy1Print, enemy1Print2);
    enemy1Direction = conditionsEnemy1(e1Y, enemy1Direction);
    if (enemy1Direction == "Up" && getCharAtxy(e1X, e1Y - 2) && getCharAtxy(e1X, e1Y - 2) == ' ' && getCharAtxy(e1X + 1, e1Y - 2) == ' ' && getCharAtxy(e1X + 2, e1Y - 2) == ' ' && getCharAtxy(e1X + 3, e1Y - 2) == ' ' &&
        getCharAtxy(e1X + 4, e1Y - 2) == ' ' && getCharAtxy(e1X + 5, e1Y - 2) == ' ' && getCharAtxy(e1X + 6, e1Y - 2) == ' ' && getCharAtxy(e1X - 1, e1Y - 2) == ' ')
    {
        e1Y--;
    }
    if (enemy1Direction == "Down" && getCharAtxy(e1X, e1Y + 2) == ' ' && getCharAtxy(e1X + 1, e1Y + 2) == ' ' && getCharAtxy(e1X + 2, e1Y + 2) == ' ' && getCharAtxy(e1X + 3, e1Y + 2) == ' ' &&
        getCharAtxy(e1X + 4, e1Y + 2) == ' ' && getCharAtxy(e1X + 5, e1Y + 2) == ' ' && getCharAtxy(e1X + 6, e1Y + 2) == ' ' && getCharAtxy(e1X - 1, e1Y + 2) == ' ')
    {
        e1Y++;
    }
    printEnemy(e1X, e1Y, enemy1Print, enemy1Print2);
}

string conditionsEnemy1(int e1Y, string &enemy1Direction)
{
    if (e1Y == 29)
    {
        enemy1Direction = "Up";
    }
    else if (e1Y == 16)
    {
        enemy1Direction = "Down";
    }
    return enemy1Direction;
}

void printEnemy2(int &e2X, int &e2Y, char enemy2Print[], char enemy2Print2[])
{
    gotoxy(e2X, e2Y);
    for (int i = 0; i < 5; i++)
    {
        cout << "\33[31m" << enemy2Print[i];
    }
    gotoxy(e2X, e2Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << "\33[31m" << enemy2Print2[i];
    }
}

void eraseEnemy2(int &e2X, int &e2Y, char enemy2Print[], char enemy2Print2[])
{
    gotoxy(e2X, e2Y);
    for (int i = 0; i < 5; i++)
    {
        cout << "\33[34m"
             << " ";
    }
    gotoxy(e2X, e2Y + 1);
    for (int i = 0; i < 5; i++)
    {
        cout << "\33[34m"
             << " ";
    }
}

void moveEnemy2(int &e2X, int &e2Y, char enemy2Print[], char enemy2Print2[], string &enemy2Direction)
{
    eraseEnemy2(e2X, e2Y, enemy2Print, enemy2Print2);
    enemy2Direction = conditionsEnemy2(e2Y, enemy2Direction);
    if (enemy2Direction == "Up" && getCharAtxy(e2X, e2Y - 2) && getCharAtxy(e2X, e2Y - 2) == ' ' && getCharAtxy(e2X + 1, e2Y - 2) == ' ' && getCharAtxy(e2X + 2, e2Y - 2) == ' ' && getCharAtxy(e2X + 3, e2Y - 2) == ' ' &&
        getCharAtxy(e2X + 4, e2Y - 2) == ' ' && getCharAtxy(e2X + 5, e2Y - 2) == ' ' && getCharAtxy(e2X + 6, e2Y - 2) == ' ' && getCharAtxy(e2X - 1, e2Y - 2) == ' ')
    {
        e2Y--;
    }
    if (enemy2Direction == "Down" && getCharAtxy(e2X, e2Y + 2) == ' ' && getCharAtxy(e2X + 1, e2Y + 2) == ' ' && getCharAtxy(e2X + 2, e2Y + 2) == ' ' && getCharAtxy(e2X + 3, e2Y + 2) == ' ' &&
        getCharAtxy(e2X + 4, e2Y + 2) == ' ' && getCharAtxy(e2X + 5, e2Y + 2) == ' ' && getCharAtxy(e2X + 6, e2Y + 2) == ' ' && getCharAtxy(e2X - 1, e2Y + 2) == ' ')
    {
        e2Y++;
    }
    printEnemy2(e2X, e2Y, enemy2Print, enemy2Print2);
}

string conditionsEnemy2(int e2Y, string &enemy2Direction)
{
    if (e2Y == 16)
    {
        enemy2Direction = "Up";
    }
    else if (e2Y == 4)
    {
        enemy2Direction = "Down";
    }
    return enemy2Direction;
}

void scoreIncrement(int &Score)
{
    Score++;
}

void printScore(int &Score)
{
    gotoxy(127, 4);
    cout << "\33[32m"
         << "Score: " << Score;
}

void printEnemy1Bullet(int &x, int &y)
{
    gotoxy(x, y);
    cout << "\33[33m"
         << "-";
}

void eraseEnemyBullet(int &x, int &y)
{
    gotoxy(x, y);
    cout << "\33[33m"
         << " ";
}

void generateEnemy1Bullet(int &e1X, int &e1Y, int &enemy1BulletCount, int e1bX[], int e1bY[])
{
    e1bX[enemy1BulletCount] = e1X - 1;
    e1bY[enemy1BulletCount] = e1Y;
    gotoxy(e1X - 1, e1Y);
    cout << "\33[33m"
         << "-";
    enemy1BulletCount++;
}

void removeEnemy1BulletFromArray(int e1bX[], int e1bY[], int &enemy1BulletCount, int &i)
{
    for (int x = i; x < enemy1BulletCount - 1; x++)
    {
        e1bX[x] = e1bX[x + 1];
        e1bY[x] = e1bY[x + 1];
    }
    enemy1BulletCount--;
}

void moveEnemy1Bullet(int e1bX[], int e1bY[], int &enemy1BulletCount)
{
    for (int x = 0; x < enemy1BulletCount; x++) 
    {
        char next = getCharAtxy(e1bX[x] - 1, e1bY[x]);
        if ((next != ' ') || (next == '#') || (next == '.'))
        {
            eraseEnemyBullet(e1bX[x], e1bY[x]);
            removeEnemy1BulletFromArray(e1bX, e1bY, enemy1BulletCount, x);
        }
        else
        {
            eraseEnemyBullet(e1bX[x], e1bY[x]);
            e1bX[x] = e1bX[x] - 1; 
            printEnemy1Bullet(e1bX[x], e1bY[x]);
        }
    }
}
void enemy1BulletDamage(int &pX, int &pY, int e1bX[], int e1bY[], int &enemy1BulletCount, int &playerHealth)
{
    for (int x = 0; x < enemy1BulletCount; x++)
    {
        // Check if the enemy bullet coordinates overlap with the player's area
        if (((e1bX[x] >= pX && e1bX[x] <= pX + 3) && (e1bY[x] >= pY + 2 && e1bY[x] <= pY + 2)) ||
            ((e1bX[x] >= pX && e1bX[x] <= pX + 3) && ((e1bY[x] + 1) >= pY + 2 && (e1bY[x] + 1) <= (pY + 2))) ||
            ((e1bX[x] >= pX && e1bX[x] <= pX + 3) && ((e1bY[x] + 2) >= pY + 2 && (e1bY[x] + 2) <= (pY + 2))))
        {
            deductPlayerHealth(playerHealth);
            eraseEnemyBullet(e1bX[x], e1bY[x]);
            removeEnemy1BulletFromArray(e1bX, e1bY, enemy1BulletCount, x);
        }
    }
}
void printEnemy2Bullet(int &x, int &y)
{
    gotoxy(x, y);
    cout << "\33[31m"
         << "-";
}

void eraseEnemy2Bullet(int &x, int &y)
{
    gotoxy(x, y);
    cout << "\33[34m"
         << " ";
}

void generateEnemy2Bullet(int &e2X, int &e2Y, int &enemy2BulletCount, int e2bX[], int e2bY[])
{
    e2bX[enemy2BulletCount] = e2X - 1;
    e2bY[enemy2BulletCount] = e2Y;
    gotoxy(e2X - 1, e2Y);
    cout << "\33[31m"
         << "-";
    enemy2BulletCount++;
}

void removeEnemy2BulletFromArray(int e2bX[], int e2bY[], int &enemy2BulletCount, int &i)
{
    for (int x = i; x < enemy2BulletCount - 1; x++)
    {
        e2bX[x] = e2bX[x + 1]; // Fix assignment to the correct enemy bullet array
        e2bY[x] = e2bY[x + 1]; // Fix assignment to the correct enemy bullet array
    }
    enemy2BulletCount--;
}

void moveEnemy2Bullet(int e2bX[], int e2bY[], int &enemy2BulletCount)
{
    for (int x = 0; x < enemy2BulletCount; x++) // Iterate based on Enemy2BulletCount
    {
        char next = getCharAtxy(e2bX[x] - 1, e2bY[x]); // Check the next position to the left for the enemy bullet
        if ((next != ' ' || (next == '#') || (next == '.')))
        {
            eraseEnemyBullet(e2bX[x], e2bY[x]);
            removeEnemy2BulletFromArray(e2bX, e2bY, enemy2BulletCount, x);
        }
        else
        {
            eraseEnemyBullet(e2bX[x], e2bY[x]);
            e2bX[x] = e2bX[x] - 1; // Move the enemy bullet to the left
            printEnemy2Bullet(e2bX[x], e2bY[x]);
        }
    }
}
void Enemy2BulletDamage(int &pX, int &pY, int e2bX[], int e2bY[], int &enemy2BulletCount, int &playerHealth)
{
    for (int x = 0; x < enemy2BulletCount; x++)
    {
        // Check if the enemy bullet coordinates overlap with the player's area
        if (((e2bX[x] >= pX && e2bX[x] <= pX + 3) && (e2bY[x] >= pY + 2 && e2bY[x] <= pY + 2)) ||
            ((e2bX[x] >= pX && e2bX[x] <= pX + 3) && ((e2bY[x] + 1) >= pY + 2 && (e2bY[x] + 1) <= (pY + 2))) ||
            ((e2bX[x] >= pX && e2bX[x] <= pX + 3) && ((e2bY[x] + 2) >= pY + 2 && (e2bY[x] + 2) <= (pY + 2))))
        {
            deductPlayerHealth(playerHealth);
            eraseEnemyBullet(e2bX[x], e2bY[x]);
            removeEnemy2BulletFromArray(e2bX, e2bY, enemy2BulletCount, x);
        }
    }
}

void deductPlayerHealth(int &playerHealth)
{
    playerHealth = playerHealth + 1;
}

void printPlayerHealth(int &playerHealth)
{
    gotoxy(127, 6);
    cout << "\33[32m"
         << "Player health is: " << playerHealth << "/100";
}

void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}

char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar : ' ';
}

void hideCursor()
{
    HANDLE consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(consoleHandle, &info);
}

void level2(char &box, char playerPrint[], char playerPrint2[], char playerPrint3[], char enemy1Print[], char enemy1Print2[], char enemy2Print[], char enemy2Print2[], int &pX, int &pY, int &e1X, int &e1Y, int &e2X, int &e2Y, string &enemy1Direction, string &enemy2Direction, int &enemy1Health, int &enemy2Health, int &playerHealth, int &Score, bool &enemy1Dead, bool &enemy2Dead, bool &playerDead, bool &e1Alive, bool &e2Alive, int &count, int &count2, int &totalPlayerLives)
{
    bool playerWin = false;
    totalPlayerLives = 3;

    e1X = 115;
    // Bullet count of player
    while (true)
    {

        int bX[10000];
        int bY[10000];
        int bulletCount = 0;

        // Bullet count of enemy 1
        int e1bX[10000];
        int e1bY[10000];
        int enemy1BulletCount = 0;

        // Bullet count of enemy 2
        int e2bX[10000];
        int e2bY[10000];
        int enemy2BulletCount = 0;

        int maxBullets = 10000;
        playerHealth = 0; //
        count = 0;
        count2 = 0;
        bool aliveAgain = false;

        system("cls");
        mazeLv();
        displayPlayer(pX, pY, playerPrint, playerPrint2, playerPrint3);
        printEnemy(e1X, e1Y, enemy1Print, enemy1Print2);
        printEnemy2(e2X, e2Y, enemy2Print, enemy2Print2);
        while (true)
        {
            if (enemy1Health <= 100)
            {
                moveEnemy(e1X, e1Y, enemy1Print, enemy1Print2, enemy1Direction);
                printEnemy1Health(enemy1Health);
            }
            else
            {
                eraseEnemy(e1X, e1Y, enemy1Print, enemy1Print2);
                enemy1Dead = true;
                e1Alive = false;
            }
            if (enemy2Health <= 100)
            {
                moveEnemy2(e2X, e2Y, enemy2Print, enemy2Print2, enemy2Direction);
                printEnemy2Health(enemy2Health);
            }
            else
            {
                eraseEnemy2(e2X, e2Y, enemy2Print, enemy2Print2);
                enemy2Dead = true;
                e2Alive = false;
            }
            if (enemy1Dead && enemy2Dead)
            {
                playerWin = true;
                break;
            }
            if (playerHealth <= 100)
            {
                printScore(Score);
                printPlayerHealth(playerHealth);
                printLives(totalPlayerLives);
            }
            else
            {

                if (totalPlayerLives == 1)
                {
                    playerDead = true;
                    break;
                }
                totalPlayerLives = totalPlayerLives - 1;
                pX = 5, pY = 5;
                aliveAgain = true;
                break;
            }
            if (GetAsyncKeyState(VK_LEFT))
            {
                movePlayerLeft(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_RIGHT))
            {
                movePlayerRight(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_UP))
            {
                movePlayerUp(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                movePlayerDown(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_SPACE))
            {
                generatePlayerBullet(pX, pY, bX, bY, bulletCount);
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                return;
            }
            if (count == 5 && enemy1Dead == 0)
            {
                generateEnemy1Bullet(e1X, e1Y, enemy1BulletCount, e1bX, e1bY);
                count = 0;
            }
            if (count2 == 5 && enemy2Dead == 0)
            {
                generateEnemy2Bullet(e2X, e2Y, enemy2BulletCount, e2bX, e2bY);
                count2 = 0;
            }
            movePlayerBullet(bX, bY, bulletCount);
            playerBulletDamage(e1X, e1Y, e2X, e2Y, bX, bY, bulletCount, e1Alive, e2Alive, Score, enemy1Health, enemy2Health);
            moveEnemy1Bullet(e1bX, e1bY, enemy1BulletCount);
            enemy1BulletDamage(pX, pY, e1bX, e1bY, enemy1BulletCount, playerHealth);
            moveEnemy2Bullet(e2bX, e2bY, enemy2BulletCount);
            Enemy2BulletDamage(pX, pY, e2bX, e2bY, enemy2BulletCount, playerHealth);
            count++;
            count2++;
            Sleep(20);
        }
        if (aliveAgain)
        {
            continue;
        }
        if (playerDead)
        {
            system("cls");
            playerLose();
            break;
        }
        if (playerWin)
        {
            system("cls");
            youWin();
            cls();
            return;
        }
    }
}

void level3(char &box, char playerPrint[], char playerPrint2[], char playerPrint3[], char enemy1Print[], char enemy1Print2[], char enemy2Print[], char enemy2Print2[], int &pX, int &pY, int &e1X, int &e1Y, int &e2X, int &e2Y, string &enemy1Direction, string &enemy2Direction, int &enemy1Health, int &enemy2Health, int &playerHealth, int &Score, bool &enemy1Dead, bool &enemy2Dead, bool &playerDead, bool &e1Alive, bool &e2Alive, int &count, int &count2, int &totalPlayerLives)
{
    bool playerWin = false;
    totalPlayerLives = 3;
    while (true)
    {
        int bX[10000];
        int bY[10000];
        int bulletCount = 0;

        // Bullet count of enemy 1
        int e1bX[10000];
        int e1bY[10000];
        int enemy1BulletCount = 0;

        // Bullet count of enemy 2
        int e2bX[10000];
        int e2bY[10000];
        int enemy2BulletCount = 0;

        int maxBullets = 10000; //

        playerHealth = 0;
        count = 0, count2 = 0;
        bool aliveAgain = false;

        system("cls");
        printMaze();
        displayPlayer(pX, pY, playerPrint, playerPrint2, playerPrint3);
        printEnemy(e1X, e1Y, enemy1Print, enemy1Print2);
        printEnemy2(e2X, e2Y, enemy2Print, enemy2Print2);
        while (true)
        {
            if (enemy1Health <= 100)
            {
                moveEnemy(e1X, e1Y, enemy1Print, enemy1Print2, enemy1Direction);
                printEnemy1Health(enemy1Health);
            }
            else
            {
                eraseEnemy(e1X, e1Y, enemy1Print, enemy1Print2);
                enemy1Dead = true;
                e1Alive = false;
            }
            if (enemy2Health <= 100)
            {
                moveEnemy2(e2X, e2Y, enemy2Print, enemy2Print2, enemy2Direction);
                printEnemy2Health(enemy2Health);
            }
            else
            {
                eraseEnemy2(e2X, e2Y, enemy2Print, enemy2Print2);
                enemy2Dead = true;
                e2Alive = false;
            }
            if (enemy3Health <= 100)
            {
                enemy3Direction(pX, pY);
                printEnemy3Health();
            }
            else
            {
                enemy3Dead = true;
                e3Alive = false;
                enemy3Die(e3X, e3Y);
            }
            if (enemy1Dead && enemy2Dead && enemy3Dead)
            {
                playerWin = true;
                break;
            }
            if (playerHealth <= 100)
            {
                printScore(Score);
                printPlayerHealth(playerHealth);
                printLives(totalPlayerLives);
            }
            else
            {
                if (totalPlayerLives == 1)
                {
                    playerDead = true;
                    break;
                }
                totalPlayerLives = totalPlayerLives - 1;
                pX = 5, pY = 5;
                aliveAgain = true;
                break;
            }
            if (GetAsyncKeyState(VK_LEFT))
            {
                movePlayerLeft(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_RIGHT))
            {
                movePlayerRight(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_UP))
            {
                movePlayerUp(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_DOWN))
            {
                movePlayerDown(pX, pY, playerPrint, playerPrint2, playerPrint3, playerHealth);
            }
            if (GetAsyncKeyState(VK_SPACE))
            {
                generatePlayerBullet(pX, pY, bX, bY, bulletCount);
            }
            if (GetAsyncKeyState(VK_ESCAPE))
            {
                return;
            }
            if (count == 3 && enemy1Dead == 0)
            {
                generateEnemy1Bullet(e1X, e1Y, enemy1BulletCount, e1bX, e1bY);
                count = 0;
            }
            if (count2 == 3 && enemy2Dead == 0)
            {
                generateEnemy2Bullet(e2X, e2Y, enemy2BulletCount, e2bX, e2bY);
                count2 = 0;
            }
            movePlayerBullet(bX, bY, bulletCount);
            playerBulletDamage(e1X, e1Y, e2X, e2Y, bX, bY, bulletCount, e1Alive, e2Alive, Score, enemy1Health, enemy2Health);
            moveEnemy1Bullet(e1bX, e1bY, enemy1BulletCount);
            enemy1BulletDamage(pX, pY, e1bX, e1bY, enemy1BulletCount, playerHealth);
            moveEnemy2Bullet(e2bX, e2bY, enemy2BulletCount);
            Enemy2BulletDamage(pX, pY, e2bX, e2bY, enemy2BulletCount, playerHealth);
            enemy3Damage(pX, pY, playerHealth);
            count++;
            count2++;
            Sleep(35);
        }
        if (aliveAgain)
        {
            continue;
        }
        if (playerDead)
        {
            system("cls");
            playerLose();
            break;
        }
        if (playerWin)
        {
            system("cls");
            youWin();
            cls();
            return;
        }
    }
}

void printLives(int &totalPlayerLives)
{
    gotoxy(127, 5);
    cout << "\33[35m"
         << "Total player Lives: " << totalPlayerLives;
}

void youWin()
{
    SetConsoleTextAttribute(hConsole, 10);
    gotoxy(60, 11);
    cout << " _____                                        _____ ";
    gotoxy(60, 12);
    cout << "( ___ )                                      ( ___ )";
    gotoxy(60, 13);
    cout << " |   |~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|   | ";
    gotoxy(60, 14);
    cout << " |   | __   __           __        ___        |   | ";
    gotoxy(60, 15);
    cout << " |   | \\ \\ / /__  _   _  \\ \\      / (_)_ __   |   | ";
    gotoxy(60, 16);
    cout << " |   |  \\ V / _ \\| | | |  \\ \\ /\\ / /| | '_ \\  |   | ";
    gotoxy(60, 17);
    cout << " |   |   | | (_) | |_| |   \\ V  V / | | | | | |   | ";
    gotoxy(60, 18);
    cout << " |   |   |_|\\___/ \\__,_|    \\_/\\_/  |_|_| |_| |   | ";
    gotoxy(60, 19);
    cout << " |___|~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~|___| ";
    gotoxy(60, 20);
    cout << "(_____)                                      (_____)\n";
    Sleep(4000);
    SetConsoleTextAttribute(hConsole, 7);
}

void displayEnemy3Right(int x, int y) 
{
    char box = 219;
    char enemy3Right1[5] = {' ', 'O', ' '};
    char enemy3Right2[5] = {'(', '|', '/'};
    char enemy3Right3[5] = {'/', ' ', '\\'};
    printEnemy3(enemy3Right1, enemy3Right2, enemy3Right3, x, y);
}

void displayEnemy3Left(int x, int y) 
{
    char box = 219;
    char enemy3Left1[3] = {' ', 'O', ' '};
    char enemy3Left2[3] = {'\\', '|', ')'};
    char enemy3Left3[3] = {'/', ' ', '\\'};
    printEnemy3(enemy3Left1, enemy3Left2, enemy3Left3, x, y);
}

void eraseEnemy3(int x, int y)
{
    char enemy3Erase1[3] = {' ', ' ', ' '};
    char enemy3Erase2[3] = {' ', ' ', ' '};
    char enemy3Erase3[3] = {' ', ' ', ' '};
    printEnemy3(enemy3Erase1, enemy3Erase2, enemy3Erase3, x, y);
}

void enemy3Die(int x, int y) // enemy 3 death
{
    char enemy3Dead1[3] = {' ', '!', ' '};
    char enemy3Dead2[3] = {'-', 'X', '-'};
    char enemy3Dead3[3] = {' ', 'X', ' '};
    printEnemy3(enemy3Dead1, enemy3Dead2, enemy3Dead3, x, y);
}

void enemy3Direction(int pX, int pY) // control direction of enemy 3
{
    int randomValue = 0;
    randomValue = rand() % 4;
    if ((e3Y == pY || e3Y == pY - 1 || e3Y == pY - 2 || e3Y == pY + 3 || e3Y == pY + 1 || e3Y == pY + 2) && e3Count <= 60)
    {
        if (e3X > pX)
        {
            displayEnemy3Left(e3X, e3Y);
        }
        else if (e3X < pX)
        {
            displayEnemy3Right(e3X, e3Y);
        }
        if (e3Count == 60)
        {
            e3Count = 100;
        }
    }
    else
    {
        if (randomValue == 0)
        {
            enemy3direction = "left";
        }
        else if (randomValue == 1)
        {
            enemy3direction = "right";
        }
        else if (randomValue == 2)
        {
            enemy3direction = "up";
        }
        else if (randomValue == 3)
        {
            enemy3direction = "down";
        }
        enemy3Movement();
    }
}

void enemy3Movement() 
{
    if (enemy3direction == "right")
    {
        if (getCharAtxy(e3X + 5, e3Y) == ' ' && getCharAtxy(e3X + 5, e3Y + 1) == ' ' && getCharAtxy(e3X + 5, e3Y + 2) == ' ')
        {
            eraseEnemy3(e3X, e3Y);
            e3X++;
            displayEnemy3Right(e3X, e3Y);
        }
        else
        {
            enemy3direction = "left";
        }
    }
    else if (enemy3direction == "left")
    {
        if (getCharAtxy(e3X - 1, e3Y) == ' ' && getCharAtxy(e3X - 1, e3Y + 1) == ' ' && getCharAtxy(e3X - 1, e3Y + 2) == ' ')
        {
            eraseEnemy3(e3X, e3Y);
            e3X--;
            displayEnemy3Left(e3X, e3Y);
        }
        else
        {
            enemy3direction = "right";
        }
    }
    else if (enemy3direction == "up")
    {
        if (getCharAtxy(e3X, e3Y - 1) == ' ' && getCharAtxy(e3X + 2, e3Y - 1) == ' ' && getCharAtxy(e3X + 3, e3Y - 1) == ' ')
        {
            eraseEnemy3(e3X, e3Y);
            e3Y--;
            displayEnemy3Left(e3X, e3Y);
        }
        else
        {
            enemy3direction = "down";
        }
    }
    else if (enemy3direction == "down")
    {
        if (getCharAtxy(e3X, e3Y + 3) == ' ' && getCharAtxy(e3X + 2, e3Y + 3) == ' ' && getCharAtxy(e3X + 3, e3Y + 3) == ' ' && getCharAtxy(e3X + 4, e3Y + 3) == ' ')
        {
            eraseEnemy3(e3X, e3Y);
            e3Y++;
            displayEnemy3Left(e3X, e3Y);
        }
        else
        {
            enemy3direction = "up";
        }
    }
}

void printEnemy3(char enemy3Print1[3], char enemy3Print2[3], char enemy3Print3[3], int x, int y)
{
    gotoxy(e3X, e3Y);
    for (int i = 0; i < 3; i++)
    {
        cout << "\33[35m" << enemy3Print1[i];
    }
    gotoxy(e3X, e3Y + 1);
    for (int i = 0; i < 3; i++)
    {
        cout << "\33[35m" << enemy3Print2[i];
    }
    gotoxy(e3X, e3Y + 2);
    for (int i = 0; i < 3; i++)
    {
        cout << "\33[35m" << enemy3Print3[i];
    }
}

void anim()
{
    SetConsoleTextAttribute(hConsole, 14);
    soliders();
    Sleep(100);
    system("cls");
    SolidersActive();
    Sleep(100);
    system("cls");
    salute();
    Sleep(100);
    SetConsoleTextAttribute(hConsole, 7);
}
void soliders()
{
    gotoxy(50, 12);
    cout << "      .---.             .---.             .---.             .---.       ";
    gotoxy(50, 13);
    Sleep(50);
    cout << "     /_____\\           /_____\\           /_____\\           /_____\\     ";
    gotoxy(50, 14);
    Sleep(50);
    cout << "     ( '.' )           ( '.' )           ( '.' )           ( '.' )      ";
    gotoxy(50, 15);
    Sleep(50);
    cout << "      \\_-_/_            \\_-_/_            \\_-_/_            \\_-_/_      ";
    gotoxy(50, 16);
    Sleep(50);
    cout << "   .- `'V'///-.       .- `'V'//-.       .- `'V'//-.       .- `'V'//-.    ";
    gotoxy(50, 17);
    Sleep(50);
    cout << "  / ,   |// , \\     / ,   |// , \\     / ,   |// , \\     / ,   |// , \\   ";
    gotoxy(50, 18);
    Sleep(50);
    cout << " / /|Ll //Ll|\\ \\   / /|Ll //Ll|\\ \\   / /|Ll //Ll|\\ \\   / /|Ll //Ll|\\ \\  ";
    gotoxy(50, 19);
    Sleep(50);
    cout << "/ / |__//   | \\_\\ / / |__//   | \\_\\ / / |__//   | \\_\\ / / |__//   | \\_\\ ";
    gotoxy(50, 20);
    Sleep(50);
    cout << "\\ \\/---|[]==| / / \\ \\/---|[]==| / / \\ \\/---|[]==| / / \\ \\/---|[]==| / / ";
    gotoxy(50, 21);
    Sleep(50);
    cout << " \\/\\__/ |   \\/\\/   \\/\\__/ |   \\/\\/   \\/\\__/ |   \\/\\/   \\/\\__/ |   \\/\\/  ";
    gotoxy(50, 22);
    Sleep(50);
    cout << "  |/_   | Ll_\\|     |/_   | Ll_\\|     |/_   | Ll_\\|     |/_   | Ll_\\|   ";
    gotoxy(50, 23);
    Sleep(50);
    cout << "    |`^'''^`|         |`^'''^`|         |`^'''^`|         |`^'''^`|    ";
    gotoxy(50, 24);
    Sleep(50);
    cout << "    |   |   |         |   |   |         |   |   |         |   |   |     ";
    gotoxy(50, 25);
    Sleep(50);
    cout << "    |   |   |         |   |   |         |   |   |         |   |   |     ";
    gotoxy(50, 26);
    Sleep(50);
    cout << "    |   |   |         |   |   |         |   |   |         |   |   |     ";
    gotoxy(50, 27);
    Sleep(50);
    cout << "    |   |   |         |   |   |         |   |   |         |   |   |     ";
    gotoxy(50, 28);
    Sleep(50);
    cout << "    L___l___J         L___l___J         L___l___J         L___l___J     ";
    gotoxy(50, 29);
    Sleep(50);
    cout << "     |_ | _|           |_ | _|           |_ | _|           |_ | _|      ";
    gotoxy(50, 30);
    Sleep(50);
    cout << "    (___|___)         (___|___)         (___|___)         (___|___)     ";
    gotoxy(50, 31);
    Sleep(50);
    cout << "     ^^^ ^^^           ^^^ ^^^           ^^^ ^^^           ^^^ ^^^      ";
}

void SolidersActive()
{
    gotoxy(50, 12);
    cout << "|\\                |\\                |\\                |\\               ";
    gotoxy(50, 13);
    Sleep(50);
    cout << "   || .---.          || .---.          || .---.          || .---.      ";
    gotoxy(50, 14);
    Sleep(50);
    cout << "   ||/_____\\         ||/_____\\         ||/_____\\         ||/_____\\     ";
    gotoxy(50, 15);
    Sleep(50);
    cout << "   ||( '.' )         ||( '.' )         ||( '.' )         ||( '.' )     ";
    gotoxy(50, 16);
    Sleep(50);
    cout << "   || \\_-_/_         || \\_-_/_         || \\_-_/_         || \\_-_/_     ";
    gotoxy(50, 17);
    Sleep(50);
    cout << "   :- `'V'//-.       :- `'V'//-.       :- `'V'//-.       :- `'V'//-.   ";
    gotoxy(50, 18);
    Sleep(50);
    cout << "  / ,   |// , `\\    / ,   |// , `\\    / ,   |// , `\\    / ,   |// , `\\ ";
    gotoxy(50, 19);
    Sleep(50);
    cout << " / /|Ll //Ll|| |   / /|Ll //Ll|| |   / /|Ll //Ll|| |   / /|Ll //Ll|| | ";
    gotoxy(50, 20);
    Sleep(50);
    cout << "/_/||__//   || |  /_/||__//   || |  /_/||__//   || |  /_/||__//   || | ";
    gotoxy(50, 21);
    Sleep(50);
    cout << "\\ \\/---|[]==|| |  \\ \\/---|[]==|| |  \\ \\/---|[]==|| |  \\ \\/---|[]==|| | ";
    gotoxy(50, 22);
    Sleep(50);
    cout << " \\/\\__/ |   \\| |   \\/\\__/ |   \\| |   \\/\\__/ |   \\| |   \\/\\__/ |   \\| | ";
    gotoxy(50, 23);
    Sleep(50);
    cout << " /\\|_   | Ll_\\ |   /|/_   | Ll_\\ |   /|/_   | Ll_\\ |   /|/_   | Ll_\\ | ";
    gotoxy(50, 24);
    Sleep(50);
    cout << " `--|`^   ^`||_|   `--|`^   ^`||_|   `--|`^   ^`||_|   `--|`^   ^`||_| ";
    gotoxy(50, 25);
    Sleep(50);
    cout << "    |   |   ||/       |   |   ||/       |   |   ||/       |   |   ||/  ";
    gotoxy(50, 26);
    Sleep(50);
    cout << "    |   |   |         |   |   |         |   |   |         |   |   |    ";
    gotoxy(50, 27);
    Sleep(50);
    cout << "    |   |   |         |   |   |         |   |   |         |   |   |    ";
    gotoxy(50, 28);
    Sleep(50);
    cout << "    |   |   |         |   |   |         |   |   |         |   |   |    ";
    gotoxy(50, 29);
    Sleep(50);
    cout << "    L___l___J         L___l___J         L___l___J         L___l___J    ";
    gotoxy(50, 30);
    Sleep(50);
    cout << "     |_ | _|           |_ | _|           |_ | _|           |_ | _|     ";
    gotoxy(50, 31);
    Sleep(50);
    cout << "    (___|___)         (___|___)         (___|___)         (___|___)    ";
    gotoxy(50, 32);
    Sleep(50);
    cout << "     ^^^ ^^^           ^^^ ^^^           ^^^ ^^^           ^^^ ^^^     ";
}

void salute()
{
    gotoxy(50, 12);
    cout << "       .---.              .---.               .---.              .---.        ";
    gotoxy(50, 13);
    Sleep(50);
    cout << "  ___ /_____\\        ___ /_____\\         ___ /_____\\        ___ /_____\\       ";
    gotoxy(50, 14);
    Sleep(50);
    cout << " /\\.-`( '.' )       /\\.-`( '.' )        /\\.-`( '.' )       /\\.-`( '.' )       ";
    gotoxy(50, 15);
    Sleep(50);
    cout << "/ /    \\_-_/_      / /    \\_-_/_       / /    \\_-_/_      / /    \\_-_/_       ";
    gotoxy(50, 16);
    Sleep(50);
    cout << "\\ `-.- `'V'//-.    \\ `-.- `'V'//-.     \\ `-.- `'V'//-.    \\ `-.- `'V'//-.     ";
    gotoxy(50, 17);
    Sleep(50);
    cout << " `.__,   |// , \\    `.__,   |// , \\     `.__,   |// , \\    `.__,   |// , \\    ";
    gotoxy(50, 18);
    Sleep(50);
    cout << "     |Ll //Ll|\\ \\       |Ll //Ll|\\ \\        |Ll //Ll|\\ \\       |Ll //Ll|\\ \\   ";
    gotoxy(50, 19);
    Sleep(50);
    cout << "     |__//   | \\_\\      |__//   | \\_\\       |__//   | \\_\\      |__//   | \\_\\  ";
    gotoxy(50, 20);
    Sleep(50);
    cout << "    /---|[]==| / /     /---|[]==| / /      /---|[]==| / /     /---|[]==| / /  ";
    gotoxy(50, 21);
    Sleep(50);
    cout << "    \\__/ |   \\/\\/      \\__/ |   \\/\\/       \\__/ |   \\/\\/      \\__/ |   \\/\\/   ";
    gotoxy(50, 22);
    Sleep(50);
    cout << "    /_   | Ll_\\|       /_   | Ll_\\|        /_   | Ll_\\|       /_   | Ll_\\|    ";
    gotoxy(50, 23);
    Sleep(50);
    cout << "     |`^   ^`|          |`^   ^`|           |`^   ^`|          |`^   ^`|      ";
    gotoxy(50, 24);
    Sleep(50);
    cout << "     |   |   |          |   |   |           |   |   |          |   |   |      ";
    gotoxy(50, 25);
    Sleep(50);
    cout << "     |   |   |          |   |   |           |   |   |          |   |   |      ";
    gotoxy(50, 26);
    Sleep(50);
    cout << "     |   |   |          |   |   |           |   |   |          |   |   |      ";
    gotoxy(50, 27);
    Sleep(50);
    cout << "     |   |   |          |   |   |           |   |   |          |   |   |      ";
    gotoxy(50, 28);
    Sleep(50);
    cout << "     L___l___J          L___l___J           L___l___J          L___l___J      ";
    gotoxy(50, 29);
    Sleep(50);
    cout << "      |_ | _|            |_ | _|             |_ | _|            |_ | _|       ";
    gotoxy(50, 30);
    Sleep(50);
    cout << "     (___|___)          (___|___)           (___|___)          (___|___)      ";
    gotoxy(50, 31);
    Sleep(50);
    cout << "      ^^^ ^^^            ^^^ ^^^             ^^^ ^^^            ^^^ ^^^       ";
}

void op()
{
    SetConsoleTextAttribute(hConsole, 4);
    printW();
    Sleep(40);
    printA();
    Sleep(40);
    printR();
    Sleep(40);
    printZ();
    Sleep(40);
    printO();
    Sleep(40);
    printN();
    Sleep(40);
    printE();
    Sleep(40);
    SetConsoleTextAttribute(hConsole, 7);
}

void printW()
{
    gotoxy(48, 13);
    cout << "____    __    ____";
    Sleep(60);
    gotoxy(48, 14);
    cout << "\\   \\  /  \\  /   /";
    Sleep(60);
    gotoxy(48, 15);
    cout << " \\   \\/    \\/   / ";
    Sleep(60);
    gotoxy(48, 16);
    cout << "  \\            /  ";
    Sleep(60);
    gotoxy(48, 17);
    cout << "   \\    /\\    /   ";
    Sleep(60);
    gotoxy(48, 18);
    cout << "    \\__/  \\__/    ";
}

void printA()
{

    gotoxy(59, 13);
    cout << "     ___     ";
    Sleep(60);
    gotoxy(59, 14);
    cout << "    /   \\    ";
    Sleep(60);
    gotoxy(59, 15);
    cout << "   /  ^  \\   ";
    Sleep(60);
    gotoxy(59, 16);
    cout << "  /  /_\\  \\  ";
    Sleep(60);
    gotoxy(59, 17);
    cout << " /  _____  \\ ";
    Sleep(60);
    gotoxy(59, 18);
    cout << "/__/     \\__\\";
}

void printR()
{

    gotoxy(72, 13);
    cout << ".______      ";
    Sleep(60);
    gotoxy(72, 14);
    cout << "|   _  \\     ";
    Sleep(60);
    gotoxy(72, 15);
    cout << "|  |_)  |    ";
    Sleep(60);
    gotoxy(72, 16);
    cout << "|      /     ";
    Sleep(60);
    gotoxy(72, 17);
    cout << "|  |\\  \\----.";
    Sleep(60);
    gotoxy(72, 18);
    cout << "| _| `._____|";
}

void printZ()
{

    gotoxy(82, 13);
    cout << " ________  ";
    Sleep(60);
    gotoxy(82, 14);
    cout << "|       /  ";
    Sleep(60);
    gotoxy(82, 15);
    cout << "`---/  /   ";
    Sleep(60);
    gotoxy(82, 16);
    cout << "   /  /    ";
    Sleep(60);
    gotoxy(82, 17);
    cout << "  /  /----.";
    Sleep(60);
    gotoxy(82, 18);
    cout << " /________|";
}

void printO()
{

    gotoxy(92, 13);
    cout << "  ______  ";
    Sleep(60);
    gotoxy(92, 14);
    cout << " /  __  \\ ";
    Sleep(60);
    gotoxy(92, 15);
    cout << "|  |  |  |";
    Sleep(60);
    gotoxy(92, 16);
    cout << "|  |  |  |";
    Sleep(60);
    gotoxy(92, 17);
    cout << "|  `--'  |";
    Sleep(60);
    gotoxy(92, 18);
    cout << " \\______/ ";
}

void printN()
{

    gotoxy(101, 13);
    cout << ".__   __.";
    Sleep(60);
    gotoxy(101, 14);
    cout << "|  \\ |  |";
    Sleep(60);
    gotoxy(101, 15);
    cout << "|   \\|  |";
    Sleep(60);
    gotoxy(101, 16);
    cout << "|  . `  |";
    Sleep(60);
    gotoxy(101, 17);
    cout << "|  |\\   |";
    Sleep(60);
    gotoxy(101, 18);
    cout << "|__| \\__|";
}

void printE()
{
    gotoxy(109, 13);
    cout << " _______ ";
    Sleep(60);
    gotoxy(109, 14);
    cout << "|   ____|";
    Sleep(60);
    gotoxy(109, 15);
    cout << "|  |__   ";
    Sleep(60);
    gotoxy(109, 16);
    cout << "|   __|  ";
    Sleep(60);
    gotoxy(109, 17);
    cout << "|  |____ ";
    Sleep(60);
    gotoxy(109, 18);
    cout << "|_______|";
}

void enemy3Damage(int &pX, int &pY, int &playerHealth)
{
    // if player and enemy 3
    if (((e3X >= pX && e3X <= pX + 3) && (e3Y >= pY && e3Y <= pY + 2)) || ((e3X >= pX && e3X <= pX + 3) && ((e3Y + 1) >= pY + 2 && (e3Y + 1) <= (pY + 2))) || ((e3X >= pX && e3X <= pX + 3) && ((e3Y + 2) >= pY + 2 && (e3Y + 2) <= (pY + 2))))
    {
        deductPlayerHealth(playerHealth);
    }
}