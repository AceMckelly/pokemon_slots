// pokemon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <ctime>
#include <windows.h>

using namespace std;

struct Character{
	string name;
	int hit_points;
	int attack;
	int defense;
	int speed;
	int accuracy;
	int evasion;

	void create(){
		srand(time(0));
		hit_points = rand() % 10 + 20;
		attack = rand() % 100 + 10;
		defense = rand() % 10 + 5;
		speed = rand() % 10 + 10;
		accuracy = rand() % 10 + 1;
		evasion = rand() % 10 + 1;
	}

	bool take_attack(int opp_atk, int opp_acc){
		int hit = opp_acc + evasion;
		hit = rand() % hit;;
	    if (opp_acc > hit){
			int damage = opp_atk / defense;
			if (damage <= 0)
				damage = 1;
			hit_points = hit_points - damage;
			return true;
		
		}
		return false;
	}

	void increase_speed(){
		srand(time(0));
		int increase = rand() % 5 + 1;
		speed = speed + increase;
	}

	void increase_attack(){
		srand(time(0));
		int increase = rand() % 10 + 1;
		attack = attack + increase;
	}

	void increase_defense(){
		srand(time(0));
		int increase = rand() % 5 + 1;
		defense = defense + increase;
	}
};

Character player;
Character enemy;
bool gameOver;

void setup(){
	player.create();
	Sleep(1000);
	enemy.create();
	gameOver = false;
}

void draw(){
	system("cls");
	cout << "####################\n";
	cout << "RPG BATTLE SEQUENCE\n";
	cout << "####################\n";
	cout << "Enemy\t HP:" << enemy.hit_points << "\n";
	cout << "\n";
	cout << "Player\t HP:" << player.hit_points << "\n";
	cout << "1. Attack 2. Increase_atk 3. Increase_def 4. Increase_spd\n";
}

void player_move(){
	int player_choice;
	bool hit = false;
	cin >> player_choice;
	switch (player_choice){
	case 1:
		hit = enemy.take_attack(player.attack, player.accuracy);
		cout << "Player attacks\n";
		if (!hit)
			cout << "Miss\n";
		Sleep(2000);
		break;
	case 2:
		player.increase_attack();
		cout << "Player increase stats\n";
		Sleep(2000);
		break;
	case 3:
		player.increase_defense();
		cout << "Player increase stats\n";
		Sleep(2000);
		break;
	case 4:
		player.increase_speed();
		cout << "Player increase stats\n";
		Sleep(2000);
		break;
	default:
		cout << "If you didn't do anything that's your problem\n";
		Sleep(1000);
		break;
	}
	draw();
}

void enemy_move(){
	int cpu_choice = rand() % 4 + 1;
	bool hit = false;
	switch (cpu_choice){
	case 1:
		hit = player.take_attack(enemy.attack, enemy.accuracy);
		cout << "Enemy attacks\n";
		if (!hit)
			cout << "Miss\n";
		Sleep(2000);
		break;
	case 2:
		enemy.increase_attack();
		cout << "Enemy increase stats\n";
		Sleep(2000);
		break;
	case 3:
		enemy.increase_defense();
		cout << "Enemy increase stats\n";
		Sleep(2000);
		break;
	case 4:
		enemy.increase_speed();
		cout << "Enemy increase stats\n";
		Sleep(2000);
		break;
	default:
		break;
	}
	draw();
}

void battle(){
	if (player.speed >= enemy.speed){
		player_move();
		if (enemy.hit_points>0)
			enemy_move();
	}
	else{
		enemy_move();
		if (player.hit_points>0)
			player_move();
	}

	if (player.hit_points <= 0){
		gameOver = true;
		cout << "YOU LOSE\n";
	}

	if (enemy.hit_points <= 0){
		gameOver = true;
		cout << "YOU WIN\n";
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	setup();
	while (!gameOver){
		draw();
		battle();
	}
	system("pause");
	return 0;
}

