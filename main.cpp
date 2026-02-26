#include <iostream>
#include <conio.h>
#include <cmath>
#include <string>
#include <vector>

#define PI 3.141592653589793238462643383279502884197169399375105820974944592307816406286208998628034825342117067982148086513282306647093844609550582231725359408128481117450284102701938521105559644622948954930381964428810975665933446128475648233786783165271201909145648566923460348610454326648213393607260249141273724587006606315588174881520920962829254091715364367892590360011330530548820466521384146951941511609433057270365759591953092186117381932611793105118548074462

using namespace std;

bool debug = false;

int isn(char inp) {
    if(inp >= 48
            && inp <= 57) {
        return 1;
    }
    return 0;
}

int znak(char inp)
{
    if(inp == 42){
        return 3;
    }
    else if(inp == 47){
        return 4;
    }
    else if(inp == 43){
        return 1;
    }
    else if(inp == 45){
        return 2;
    }
    else{return 0;}
}

void draw() {
    cout
            << "     C      " << endl
            << "     /\\     " << endl
            << " b  /  \\  a " << endl
            << "   /    \\   " << endl
            << "  /  c   \\  " << endl
            << "A -------- B" << endl;
}

string calculator(string inp)
{
    string temp;
    string front, back;
    string pointer;
    int bracket = 1;
    vector<string> divided;
    vector<string> brackets;

    string::iterator it;
    while(bracket != 0)
    {
        bracket = 0;
        for(int i = 0; i < inp.length(); i++)
        {
            back.clear();
            temp.clear();
            front.clear();
            pointer = inp.at(i);
            if(pointer.compare("(") == 0) {
                bracket = i;
                if(debug) {
                    cout << "скобка обнаружена " << bracket << endl;
                }
            }
            if(pointer.compare(")") == 0 && bracket != 0) {
                for(int j = 0; j < bracket; j++)
                {
                    back = back + inp.at(j);
                }
                for(int j = bracket + 1; j < i ; j++)
                {
                    temp = temp + inp.at(j);
                }
                for(int j = i + 1; j < inp.length(); j++)
                {
                    front = front + inp.at(j);
                }
                inp = back + calculator(temp) + front;
                if(debug) {
                    cout << inp << endl;
                }
            }
        }
    }
    bracket = 0;
    temp.clear();
    for(int i = 0; i < inp.length(); i++)
    {
        /*
        if(isn(inp.at(i))) {
            temp = temp + inp.at(i);
        }
        else if(znak(inp.at(i))){
            divided.push_back(temp);
            temp.clear();
            temp = inp.at(i);
            divided.push_back(temp);
        }
        if(i = inp.length() - 1){
            divided.push_back(temp);
            temp.clear();
        }
        */
        // THE GREAT DIVIDER
        if(isn(inp.at(i))){
            temp = temp + inp.at(i);
            // if(debug){cout << "temp: " << temp << endl;}
        }
        else{
            if(debug){cout << "temp(" + temp + ") pushed to divided and cleared" << endl;}
            divided.push_back(temp);
            temp.clear();
        }
        if(i == inp.length() - 1){
            if(debug){cout << "temp(" + temp + ") pushed to divided and cleared as last" << endl;}
            divided.push_back(temp);
            temp.clear();
        }
        if(znak(inp.at(i))){
            temp = inp.at(i);
            if(debug){cout << "temp(" + temp + ") is znak pushed to divided" << endl;}
            divided.push_back(temp);
            temp.clear(); 
        }
    }
    if(debug){
        cout << "Content of divided after division" << endl;
        for(int i = 0; i < divided.size(); i++)
        {
            cout << divided.at(i) << endl;
        }
    }
    while(false) {

    }
    return inp;
}

void vivod_znachenii(double num[6])
{
    if(num[0] != 0) {
        cout << "A = " << num[0] << "°" <<endl;
    }
    if(num[1] != 0) {
        cout << "B = " << num[1] << "°" <<endl;
    }
    if(num[2] != 0) {
        cout << "C = " << num[2] << "°" <<endl;
    }
    if(num[3] != 0) {
        cout << "a = " << num[3] <<endl;
    }
    if(num[4] != 0) {
        cout << "b = " << num[4] <<endl;
    }
    if(num[5] != 0) {
        cout << "c = " << num[5] <<endl;
    }
    return;
}



int calc(double num[6]) {
    double m = 0, n = 0, k = 0, M = 0, N = 0, K = 0, otv = 0, temp = 0;
    int checkA = 0, checka = 0;
    for(int i = 0; i < 6; i++) {
        if(i < 2) {
            if(num[i] != 0) {
                checkA++;
            }
        }
        else {
            if(num[i] != 0) {
                checka++;
            }
        }
        cout << num[i] << checkA << checka << endl;
    }
    if(checka + checkA < 2 && checka < 1) {
        cout << "Недостатачно данных" << endl
             << "Нажмите Enter для возврата" << endl;
        cin;
        return 0;
    }

    while(true) {
        //cos

        //sides
        if(num[0] != 0
                && num[4] != 0
                && num[5] != 0) {
            K = num[0];
            m = num[4];
            n = num[5];
            temp = 2 * m * n * cos(K * PI / 180.0 );
            temp = pow(m, 2) + pow(n, 2) + temp;
            num[3] = sqrt(temp);
            temp = 0;
        }
        if(num[1] != 0
                && num[3] != 0
                && num[5] != 0) {
            K = num[1];
            m = num[3];
            n = num[5];
            temp = 2 * m * n * cos(K * PI / 180.0  );
            temp = pow(m, 2) + pow(n, 2) + temp;
            num[4] = sqrt(temp);
            temp = 0;
        }
        if(num[2] != 0
                && num[4] != 0
                && num[3] != 0) {
            K = num[2];
            m = num[4];
            n = num[3];
            temp = 2 * m * n * cos(K * PI / 180.0 );
            temp = pow(m, 2) + pow(n, 2) + temp;
            num[5] = sqrt(temp);
            temp = 0;
        }
        //

        if(num[3] != 0 && num[4] != 0 && num[5] != 0) {
            m = num[3];
            n = num[4];
            k = num[5];

            if(num[2] == 0) {
                temp = pow(m, 2) + pow(n, 2) - pow(k, 2);
                temp = temp / (2 * m * n);
                num[2] = acos(temp) * 180.0 / PI;
            }
            else if(num[1] == 0) {
                temp = pow(m, 2) + pow(k, 2) - pow(n, 2);
                temp = temp / (2 * m * k);
                num[1] = acos(temp) * 180.0 / PI;
            }
            else if(num[0] == 0) {
                temp = pow(k, 2) + pow(n, 2) - pow(m, 2);
                temp = temp / (2 * k * n);
                num[2] = acos(temp) * 180.0 / PI;
            }
        }

        m = 0;
        n = 0;
        k = 0;
        M = 0;
        N = 0;
        K = 0;
        //sin
        for(int i = 0; i < 3; i++) {
            if(num[i] != 0 && num[i + 3] != 0 && m == 0) {
                M = sin(num[i] * PI / 180.0);
                m = num[i + 3];
            }
        }
        if(m != 0) {
            for(int i = 0; i < 3; i++) {
                if(num[i] != 0 && num[i + 3] == 0) {
                    num[i + 3] = (sin(num[i] * PI / 180) * m) / M;
                }
                else if(num[i + 3] != 0 && num[i] == 0) {
                    num[i] = asin((num[i + 3] * M) / m) * 180.0 / PI;
                }
            }
        }

        //angles
        K = 0;
        for(int i = 0; i < 3; i++) {
            if(num[i] != 0) {
                K++;
            }
        }
        if(K = 2) {
            temp = 180 - num[1] - num[2] - num[3];
            for(int i = 0; i < 3; i++) {
                if(num[i] == 0) {
                    num[i] = temp;
                }
            }
        }
        k = 0;
        for(int i = 0; i < 6; i++) {
            if(num[i] != 0) {
                k++;
            }
        }
        if(k > 5) {
            break;
        }
        k = 0;
        cout << "a" << endl;
    }

    draw();
    vivod_znachenii(num);
    cout << endl << "Нажмите Enter для возврата" << endl;
    cin;
    clrscr();

    return 0;
}



int main()
{
    int vibor, vibor2;
    double A, B, C, a, b, c;
    double num[6] = {0, 0, 0, 0, 0, 0};
    while(true) {
        vibor = 0;
        vibor2 = 0;
        draw();
        vivod_znachenii(num);
        cout << "Выберите действие " << endl
             << "1) Задать значение" << endl
             << "2) Отчистить значение" << endl
             << "3) Счёт" << endl
             << "4) Отчистить всё" << endl
             << "0) Завершить работу" << endl;
        cin >> vibor;

        if(vibor == 0) {
            break;
        }

        if(vibor == 1 || vibor == 2) {
            cout << "Выберите значение:" << endl
                 << "1) A" << endl
                 << "2) B" << endl
                 << "3) C" << endl
                 << "4) a" << endl
                 << "5) b" << endl
                 << "6) c" << endl;
            cin >> vibor2;
        }
        if(vibor == 1) {
            cout << "Введите значение: ";
            cin >> num[vibor2 - 1];
        }
        else if(vibor == 2) {
            num[vibor2 - 1] = 0;
        }
        clrscr();
        if(vibor == 3) {
            calc(num);
        }

        if(vibor == 4) {
            for(int i = 0; i < 6; i++) {
                num[i] = 0;
            }
        }

        if(vibor == 1942) {
            num[3] = 4;
            num[4] = 3;
            num[2] = 90;
        }

        if(vibor == 40)
        {
            string inp;
            cout << "Введите пример: ";
            cin >> inp;
            cout << calculator(inp);
        }
        if(vibor == 7476) {
            if(!debug) {
                debug = true;
                cout << "tududu" << endl;
                continue;
            }
            if(debug) {
                debug = false;
                cout << "Ne hehe" << endl;
                continue;
            }
        }

    }
    return 0;
}


