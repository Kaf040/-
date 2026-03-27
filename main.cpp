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
            && inp <= 57 || inp == 46 || inp == 44) {
        return 1;
    }
    return 0;
}

int znak(char inp)
{
    if(inp == 42) {
        return 3;
    }
    else if(inp == 47) {
        return 4;
    }
    else if(inp == 43) {
        return 1;
    }
    else if(inp == 45) {
        return 2;
    }
    else {
        return 0;
    }
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

double fac(double x)
{
    double h = 1;
    for(double i = x; i > 0; i--)
    {
        h = h * i;
    }
    return h;
}

void viboriz()
{
    double x;
    double y;
    std::cout << "k = ";
    std::cin >> x;
    std::cout << "n = ";
    std::cin >> y;
    double v = fac(y);
    double n1 = fac(x);
    double n2 = fac(y-x);
    double n = n1 * n2;
    double otv = v / n;
    std::cout << "Ответ: " << otv << endl;
    return;
}

string calculator(string inp)
{
    string temp;
    string front, back;
    string pointer;
    int bracket = 0;
    int cznak = 0;
    int negativ = 0, chislo = 0;
    double a = 0, b = 0;
    int pointa = 0, pointb = 0;
    vector<string> divided;
    vector<double> chdiv;
    vector<int> zndiv;
    vector<string> brackets;

    /*
    for(int i = 0; i < inp.length(); i++){

    }
    */

    while(true)
    //for(int j; j < 4; j++)
    {
        if(debug) {
            cout << "Started debracketing loop" << endl;
        }
        a = 0;
        for(int i = 0; i < inp.length(); i++)
        {
            back.clear();
            temp.clear();
            front.clear();
            pointer = inp.at(i);
            if(debug) {
                cout << "Pointer: " << pointer << endl;
            }
            if(pointer.compare("(") == 0) {
                if(i > 0) {
                    if(isn(inp.at(i - 1)))
                    {
                        pointa = 1;
                    }
                }
                bracket = i;
                if(debug) {
                    cout << "скобка обнаружена " << bracket << endl;
                }
                a = 1;
            }



            if(pointer == ")") {
                if(!i == inp.length() - 1) {
                    if(isn(inp.at(i + 1))) {
                        pointb = 1;
                    }
                }
                if(debug) {
                    cout << ") at " << i << endl;
                }
                back.clear();
                for(int j = 0; j < bracket; j++)
                {
                    back = back + inp.at(j);
                }
                front.clear();
                for(int j = i + 1; j < inp.length(); j++)
                {
                    front = front + inp.at(j);
                }
                temp.clear();
                for(int j = bracket + 1; j < i ; j++)
                {
                    temp = temp + inp.at(j);
                }
                if(debug) {
                    cout << "going deeper with " + temp << endl;
                }


                temp = calculator(temp);
                if(pointa) {
                    temp = "*" + temp;
                }
                if(pointb) {
                    temp = temp + "*";
                }
                inp = back + temp + front;
                if(debug) {
                    cout << "after no-bracketing: " + inp << endl;
                }
                pointa = 0;
                pointb = 0;
                a = 1;
                break;
            }
        }
        if(a == 0) {
            break;
        }

    }

    bracket = 0;
    temp.clear();
    if(debug) {
        cout << "Start calculating" << endl;
    }
    for(int i = 0; i < inp.length(); i++)
    {
        // absolutely not great divider

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
        if(debug) {
            cout << "inp: " + inp << endl;
        };
        if(isn(inp.at(i))) {
            temp = temp + inp.at(i);
            if(debug) {
                cout << "temp: " << temp << endl;
            }
        }
        // запись чисел
        else {
            if(!temp.empty()) {
                if(negativ) {
                    if(debug) {
                        cout << "temp(" + temp + ") pushed to chdiv and cleared as negativ" << endl;
                    }
                    chdiv.push_back(stod(temp + ".0") * -1);
                }
                else {
                    if(debug) {
                        cout << "temp(" + temp + ") pushed to chdiv and cleared" << endl;
                    }
                    chdiv.push_back(stod(temp + ".0"));
                }
            }
            negativ = 0;
            temp.clear();
        }
        if(i == inp.length() - 1 && !temp.empty()) {
            if(debug) {
                cout << "temp(" + temp + ") pushed to chdiv and cleared as last" << endl;
            }
            if(negativ) {
                chdiv.push_back(stod(temp + ".0") * -1);
            }
            else {
                chdiv.push_back(stod(temp + ".0"));
            }
            negativ = 0;
            temp.clear();
        }
        // запись знаков
        if(znak(inp.at(i))) {
            temp = inp.at(i);
            negativ = 0;
            if(znak(inp.at(i)) == 2) {
                negativ = 1;
                temp = "+";
            }
            if(i > 0) {
                if(debug) {
                    cout << "temp(" + temp + ") is znak pushed to zndiv" << endl;
                }
                if(znak(inp.at(i)) != 3) {
                    zndiv.push_back(znak(inp.at(i)));
                }
                else if(znak(inp.at(i+1)) != 3 && znak(inp.at(i-1)) != 3 && znak(inp.at(i)) == 3) {
                    zndiv.push_back(3);
                }
                else if(znak(inp.at(i)) == 3 && znak(inp.at(i+1)) == 3) {
                    zndiv.push_back(5);
                }
            }
            temp.clear();
        }

    }
    // cleaning


    if(debug) {
        cout << "Content of chdiv after division" << endl;
        for(int i = 0; i < chdiv.size(); i++)
        {
            cout << chdiv.at(i) << endl;
        }
        cout << "Content of zndiv after division" << endl;
        for(int i = 0; i < zndiv.size(); i++)
        {
            cout << zndiv.at(i) << endl;
        }
    }
// отрицание чисел
    /*
    for(int i = 0; i < zndiv.size()){
        temp = zndiv.at(i)
        if(znak(temp) == 2){
            if(i == 1){
                chdiv.at(i) = chdiv.at(i) * -1;
                zndiz.erase(i);
            }
            else{
                chdiv.at(i + 1) = chdiv.at(i + 1) * -1;
                zndiz.at(i) = "+";
            }
        }
    }
    */
// Counter
    while(true) {
        //kak dumati?
        cznak = 0;
        bracket = 0;
        // нахождение знака
        // степень
        for(int i = 0; i < zndiv.size(); i++) {
            if(zndiv.at(i) > 4 && (cznak >= i || cznak == 0)) {
                cznak = i;
                bracket = 1;
            }
        }
        // умножение или деление
        if(!cznak) {
            for(int i = 0; i < zndiv.size(); i++) {
                if(zndiv.at(i) > 2 && (cznak >= i || cznak == 0)) {
                    cznak = i;
                    bracket = 1;
                }
            }
        }
        // хоть что-нибудь
        if(!cznak) {
            for(int i = 0; i < zndiv.size(); i++) {
                if(zndiv.at(i) > 0 && (cznak >= i || cznak == 0)) {
                    cznak = i;
                    bracket = 1;
                }
            }
        }
        if(debug) {
            cout << "cznak:" << cznak << " bracket: " << bracket << endl;
        }
        // Нахождение чисел с которыми проводим операцию

        if(bracket) {
            //a = 0;
            //b = 0;
            chislo = cznak;
            while(true) {
                if(chdiv.at(chislo)) {
                    a = chdiv.at(chislo);
                    pointa = chislo;
                    break;
                }
                --chislo;
            }
            chislo = cznak + 1;
            while(true) {
                if(chdiv.at(chislo)) {
                    b = chdiv.at(chislo);
                    pointb = chislo;
                    break;
                }
                ++chislo;
            }
            if(debug) {
                cout << "a: " << a << "  b: " << b << endl;
                cout << "pointa: " << pointa << "  pointb: " << pointb << endl;
            }
            // счёт
            // сложение
            if(zndiv.at(cznak) == 1) {
                a = a + b;
                chdiv.at(pointa) = a;
                chdiv.at(pointb) = 0;
            }
            // умножение
            else if(zndiv.at(cznak) == 3) {
                a = a * b;
                chdiv.at(pointa) = a;
                chdiv.at(pointb) = 0;
            }
            // деление
            else if(zndiv.at(cznak) == 4) {
                a = a / b;
                chdiv.at(pointa) = a;
                chdiv.at(pointb) = 0;
            }
            //
            else if(zndiv.at(cznak) == 5) {
                a = pow(a, b);
                chdiv.at(pointa) = a;
                chdiv.at(pointb) = 0;
            }
            zndiv.at(cznak) = 0;
        }
        else {
            break;
        }
    }
    for(int i = 0; i < chdiv.size(); i++) {
        if(chdiv.at(i)) {
            a = chdiv.at(i);
        }
    }
    return to_string(a);
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


void tringle()
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
    }
    return;
}




int main()
{
    int vibor;
    string inp;
    while(true) {
        vibor = 0;
        cout << "Выберете программу" << endl
             << "1) Количество выборов k из n" << endl
             << "2) Вычесление треугольника" << endl
             << "3) Калькулятор" << endl
             << "0) Завершить работу" << endl;
        cin >> vibor;
        clrscr();

        if(vibor == 0) {
            break;
        }

        if(vibor == 1) {
            viboriz();
        }
        
        else if(vibor == 2) {
            tringle();
        }
        
        if(vibor == 3) {
            cout << "Введите пример: ";
            cin >> inp;
            cout << "Ответ: " + calculator(inp) << endl;
            
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


    