#include <iostream>
#include <string>

using namespace std;


bool isKPeriodic(const string& text, const int k) {

    //Проводим проверки входных данных
    if (text.empty()) {
        return false;
    }

    if (k < 1) {
        return false;
    }

    int lenght{ 1 };
    //вычисляем длинну уникальной строки из которой состоит text
    for (size_t i = 1; i < text.size(); ++i) {

        if (text[i] != text[0]) {           
            ++lenght;
        }
        else {
            break;
        }
    }

    //выполняем быструю  проверку на кратность
    if ((text.size() / lenght) != k) {
        return false;
    }

    //проводим проверку что остальной text состоит из уникальной строки полученной ранее
    for (size_t i = lenght; i < text.size(); i += lenght) {
        for (size_t j = 0; j < lenght; ++j) {
            if (text[j] == text[j + i]) {
                continue;
            }
            else {
                return false;
            }
        }
    }

    return true;
}

int main()
{
    //немного примеров для тестирования
    bool result = isKPeriodic("adcadcadc", 3);
    result != 0 ? cout << "true" << endl : cout << "false" << endl;

    result = isKPeriodic("adcadcadcd", 3);
    result != 0 ? cout << "true" << endl : cout << "false" << endl;

    result = isKPeriodic("adcadcadd", 3);
    result != 0 ? cout << "true" << endl : cout << "false" << endl;

    result = isKPeriodic("aadcadcadd", 2);
    result != 0 ? cout << "true" << endl : cout << "false" << endl;

    result = isKPeriodic("adcadc", 2);
    result != 0 ? cout << "true" << endl : cout << "false" << endl;

    result = isKPeriodic("", 1);
    result != 0 ? cout << "true" << endl : cout << "false" << endl;

    result = isKPeriodic("adc", 1);
    result != 0 ? cout << "true" << endl : cout << "false" << endl;

    return 0;
}