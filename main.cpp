#include <iostream>
#include <vector>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <array>

using namespace std;

struct MiRobot {
    string name;
    int bat{100};
    array<int, 2> coords;
};

string getRandomFilePath() {
    int n = rand() % 2 + 1;
    return to_string(n) + ".txt";
}

void initMap(vector<vector<char>> &map, MiRobot &robot) {
    ifstream file;
    string frase;
    file.open(getRandomFilePath());
    if (!file.is_open()) {
        cout << "Error al abrir el archivo.\n";
        throw exception();
    }
    int line{0};
    while(getline(file, frase)) {
        map.resize(line+1);
        for (char c : frase) {
            map.at(line).push_back(c);
        }
        line++;
    }
    file.close();

    for (int i{0}; i < map.size(); i++) {
        for (int j{0}; j < map.at(i).size(); j++) {
            if (map.at(i).at(j) == 'I') {
                robot.coords = {i, j};
                map.at(i).at(j) = '-';
                return;
            }
        }
    }
}

void lookAround(const vector<vector<char>> &map, const MiRobot &robot) {
    int x{robot.coords.at(0)}, y{robot.coords.at(1)};
    for (int i{0}; i < map.size(); i++) {
        for (int j{0}; j < map.at(i).size(); j++) {
            if (abs(i-x) > 1 || abs(j-y) > 1) {
                cout << "-";
            } else if (i == x && j == y) {
                cout << "R";
            } else {
                cout << map.at(i).at(j);
            }
        }
        cout << endl;
    }
}

bool move(const vector<vector<char>> &map, MiRobot &robot) {
    cout << "Te toca moverte.\n";
    char dir; cin >> dir; cin.ignore();
    system("cls");
    int ud{0}, rl{0};
    switch (dir) {
    case 'w':
        ud = -1;
        break;
    case 'a':
        rl = -1;
        break;
    case 's':
        ud = 1;
        break;
    case 'd':
        rl = 1;
        break;
    default:
        cout << "Direccion no valida\n";
        return false;
    }
    int newX{robot.coords.at(0) + ud}, newY{robot.coords.at(1) + rl};
    try {
        char lugar = map.at(newX).at(newY);
        if (lugar == 'X') {
            cout << "No puedes atravesar paredes!\n";
            robot.bat -= 10;
            cout << "Energia actual: " << robot.bat << "%\n";
            return false;
        }
        robot.coords.at(0) = newX;
        robot.coords.at(1) = newY;
        cout << "Movimiento ok";
        if (lugar == 'E') {
            cout << ". Cargando...\n";
            robot.bat = 100;
        } else {
            cout << endl;
            robot.bat--;
        }
        cout << "Energia actual: " << robot.bat << "%\n";
        return true;
    } catch (out_of_range) {
        cout << "No te puedes salir del mapa.\n";
        robot.bat -= 10;
        cout << "Energia actual: " << robot.bat << "%\n";
    }
    return false;
}

bool checkEnd(const vector<vector<char>> &map, const MiRobot &robot) {
    if (robot.bat == 0) {
        cout << "Te has quedado sin bateria!\nHas perdido!\n";
        return true;
    }
    if (map.at(robot.coords.at(0)).at(robot.coords.at(1)) != 'O') return false;
    cout << "You win!!!\n";
    return true;
}

int main()
{
    srand(time(NULL));

    MiRobot robot;
    vector<vector<char>> map;
    initMap(map, robot);

    bool end{0};
    while (!end) {
        lookAround(map, robot);
        move(map, robot);
        end = checkEnd(map, robot);
    }

    cout << "Tu puntuacion: " << robot.bat << endl;

    return 0;
}
