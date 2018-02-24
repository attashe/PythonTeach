// Поле
// заполнеие
//првоерка
// функция проверки
// кол-во кораблей
// границы заполнения
// ход
// убийство
// промахи
// конец игры

#include <iostream>
#include <assert.h>
#include <string>
struct Point{
	int x;
	int y;
};
class Ship{
public:
int hull; //сколько прочности осталось
int size;
bool isAlive = true;

Ship(int s) 
{
	hull = size = s;
}
Ship() { }

};
class Field{
public:
	int **FieldFirst;
	Ship ships[11];
	Field()
	{
		std::cout << "Constructor";
		FieldFirst = new int* [13];
		for(int i = 0; i < 12; i++){
			FieldFirst[i] = new int [13];
			for (int j = 0; j < 12; ++j)
			{
				FieldFirst[i][j] = 0;
			}
		}
	}
	bool Test(Point point);
	bool addShip(char dir, Point point,int size);
	bool fieldFill(std::string Str);
	int strike(Point point); //0 - промах, 1 - ранение, 2 - уничтожил
	bool isEnd();
	void Print();
};
bool Field::Test(Point point){ /*Проверка на спорикосновение кораблей*/
	if(FieldFirst[point.x][point.y] != 0) return false;
	if(point.x - 1 < 0 || point.x + 1 > 12 || point.y - 1< 0 || point.y + 1 > 12) return false;
	if(FieldFirst[point.x - 1][point.y] != 0 ||
		FieldFirst[point.x + 1][point.y] != 0 ||
		FieldFirst[point.x][point.y - 1] != 0 ||
		FieldFirst[point.x][point.y +1] != 0 ||
		FieldFirst[point.x - 1][point.y - 1] != 0 ||
		FieldFirst[point.x - 1][point.y + 1] != 0 ||
		FieldFirst[point.x + 1][point.y - 1] != 0 ||
		FieldFirst[point.x + 1][point.y + 1] != 0)
		return false;
	return true;
}

bool Field::addShip(char dir, Point point,int size){
	if(point.x < 1 && point.x > 11 && point.y < 1 && point.y > 11 && Test(point))
		return false;
	int dx = 0, dy = 0;
	if(dir == 'L' || dir == 'l')
	{
		// if(point.x == 1) return false;
		dx = -1;
		dy = 0;
	}
	if(dir == 'R' || dir == 'r')
	{	
		// if(point.x == 11) return false;
		dx = 1;
		dy = 0;
	}
	if(dir == 'U' || dir == 'u')
	{
		// if(point.y == 1) return false;
		dx = 0;
		dy = 1;
	} 
	if(dir == 'D' || dir == 'd')
	{	
		// if(point.y == 9) return false;
		dx = 0;
		dy = -1;	
	}


	for(int i = 0; i < size;i++){
		if(FieldFirst[point.x + dx][point.y + dy] != 0 && FieldFirst[point.x +dx][point.y + dy] > 11 &&
			FieldFirst[point.x + dx][point.y + dy] < 1){
			return false;
		}
		if(!Test(point)) return false;
	}

	std::cout << size << std::endl;
	FieldFirst[point.x][point.y] = size;
	for(int i = 0; i  < size; i++){
		std::cout << point.x + dx*i << " " << point.y + dy*i << std::endl;
		FieldFirst[point.x + dx*i][point.y + dy*i] = size;
	}
	return true;
}
 char* MyParsing(std::string Str){
 		char *A = new char[30];
 		int j = 0;
 		for(int i = 0; i < Str.size(); i++){
 			if(Str[i] != ' '){
 				A[j++] = Str[i];
 			}
 		}
 		return A;
 }
bool Field::fieldFill(std::string Str) {
//.. parsing
	char *A;
	A = MyParsing(Str);
	int s;
	Point point;
	for (int i = 0; i < 10; ++i)
	{	
		switch(i){
			case 0: s = 4; break;
			case 1:
			case 2: s = 3; break;
			case 3:
			case 4:
			case 5: s = 2; break;
			default: s = 1;
			}
		Ship S(s);
		point.x = A[i*3] - '0' + 1;
		point.y = A[i*3 + 1] - '0' + 1;
		addShip(A[i*3 + 2], point, s);
		ships[i] = S;
	}	
	return true;
}
//0 - промах, 1 - ранение, 2 - уничтожил
 int Field::strike(Point point){
 	int p = FieldFirst[point.x][point.y];
 	if(point.x < 1 || point.x > 11 || point.y < 1 || point.y > 11) return -1;
 	if(p == -1) return -1;
 	if(p != 0){
		ships[p].hull--;
		if(ships[p].hull == 0){
			ships[p].isAlive = false;
			FieldFirst[point.x][point.y] = -1;
			return 2;
		}
		else{
			FieldFirst[point.x][point.y] = -1;
			return 1;
		}
 	}
 	else{
 		FieldFirst[point.x][point.y] = -1;
 		return 0;
 	}       
 }
bool Field::isEnd(){
	for(int i = 0; i < 10; i++){
		if(ships[i].isAlive == true) return false;
	}
	return true;
}	
void Field::Print(){
	for(int i = 1; i < 11;i++){
		for(int j = 1; j < 11;j++){
			std::cout << FieldFirst[i][j];
		}
		std::cout << std::endl;
	}
}

int main(){
	std::cout << "Start";
	std::string A = "1 1 r 3 3 l 4 4 r 9 9 l 8 8 u 6 6 d 7 9 d 7 1 d 3 9 d 5 5 u";
	Field First, Second;
	std::cout << "Field was created";
	assert(First.fieldFill(A));
	assert(Second.fieldFill(A));
	std::cout << "Field was filled" << std::endl;
	Point target;
	while(!First.isEnd() && !Second.isEnd()){
		First.Print();
		std::cin >> target.x >> target.y;
		First.strike(target);
		//system("cls");
		Second.Print();
		std::cin >> target.x >> target.y;
		Second.strike(target);
		//system("cls");
	}
	system("cls");
	std::cout << "\n";
	return 0;
}


