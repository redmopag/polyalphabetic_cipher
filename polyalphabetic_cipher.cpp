#include <iostream>
#include <map>
#include <Windows.h>
#include <string>

using namespace std;

class Code
{
private:
    map<char, char> alp1, alp2, alp5;
    map<char, char> rev_alp1, rev_alp2, rev_alp5;
    const int Register_convert = 32;

    void alphabet_reverse()
    {
        for (const auto& el : alp1)
            rev_alp1[el.second] = el.first;
        for (const auto& el : alp2)
            rev_alp2[el.second] = el.first;
        for (const auto& el : alp5)
            rev_alp5[el.second] = el.first;
    }
    void lower(string& data)
    {
        // А = -64
        // Я = -33
        // а = -32
        // я = -1
        for (int i = 0; i < data.length(); ++i)
            if (data[i] >= 'А' && data[i] <= 'Я')
            {
                data[i] = data[i] + Register_convert;
            }
    }
public:
    Code() {
        // {} added for comfort view
        // First alphabet
        {
            alp1['а'] = 'б';
            alp1['б'] = 'ю';
            alp1['в'] = 'г';
            alp1['г'] = 'ы';
            alp1['д'] = 'е';
            alp1['е'] = 'ь';
            alp1['ё'] = 'з';
            alp1['ж'] = 'ш';
            alp1['з'] = 'й';
            alp1['и'] = 'ц';
            alp1['й'] = 'л';
            alp1['к'] = 'ф';
            alp1['л'] = 'н';
            alp1['м'] = 'т';
            alp1['н'] = 'п';
            alp1['о'] = 'р';
            alp1['п'] = 'с';
            alp1['р'] = 'о';
            alp1['с'] = 'у';
            alp1['т'] = 'м';
            alp1['у'] = 'х';
            alp1['ф'] = 'к';
            alp1['х'] = 'ч';
            alp1['ц'] = 'и';
            alp1['ч'] = 'щ';
            alp1['ш'] = 'ж';
            alp1['щ'] = 'ъ';
            alp1['ъ'] = 'д';
            alp1['ь'] = 'э';
            alp1['ы'] = 'в';
            alp1['э'] = 'я';
            alp1['ю'] = ' ';
            alp1['я'] = 'а';
            alp1[' '] = 'ё';
        }

        // Second alphabet
        {
            alp2['а'] = 'с';
            alp2['б'] = 'о';
            alp2['в'] = 'у';
            alp2['г'] = 'м';
            alp2['д'] = 'к';
            alp2['е'] = 'х';
            alp2['ё'] = 'ч';
            alp2['ж'] = 'и';
            alp2['з'] = 'щ';
            alp2['и'] = 'ж';
            alp2['й'] = 'ъ';
            alp2['к'] = 'д';
            alp2['л'] = 'э';
            alp2['м'] = 'в';
            alp2['н'] = 'я';
            alp2['о'] = 'а';
            alp2['п'] = 'б';
            alp2['р'] = 'ю';
            alp2['с'] = 'г';
            alp2['т'] = ' ';
            alp2['у'] = 'е';
            alp2['ф'] = 'ь';
            alp2['х'] = 'з';
            alp2['ц'] = 'ш';
            alp2['ч'] = 'й';
            alp2['ш'] = 'ц';
            alp2['щ'] = 'ё';
            alp2['ъ'] = 'ф';
            alp2['ь'] = 'н';
            alp2['ы'] = 'т';
            alp2['э'] = 'п';
            alp2['ю'] = 'р';
            alp2['я'] = 'ы';
            alp2[' '] = 'л';
        }

        // Fifth alphabet
        {
            alp5['а'] = 'м';
            alp5['б'] = 'н';
            alp5['в'] = 'о';
            alp5['г'] = 'п';
            alp5['д'] = 'р';
            alp5['е'] = 'с';
            alp5['ё'] = 'т';
            alp5['ж'] = 'у';
            alp5['з'] = 'ф';
            alp5['и'] = 'х';
            alp5['й'] = 'ц';
            alp5['к'] = 'ч';
            alp5['л'] = 'ш';
            alp5['м'] = 'щ';
            alp5['н'] = 'ъ';
            alp5['о'] = 'ь';
            alp5['п'] = 'ы';
            alp5['р'] = 'э';
            alp5['с'] = 'ю';
            alp5['т'] = 'я';
            alp5['у'] = ' ';
            alp5['ф'] = 'а';
            alp5['х'] = 'б';
            alp5['ц'] = 'в';
            alp5['ч'] = 'г';
            alp5['ш'] = 'д';
            alp5['щ'] = 'е';
            alp5['ъ'] = 'ё';
            alp5['ь'] = 'ж';
            alp5['ы'] = 'з';
            alp5['э'] = 'и';
            alp5['ю'] = 'й';
            alp5['я'] = 'к';
            alp5[' '] = 'л';
        }

        alphabet_reverse();
    }
    void showAlp()
    {
        for (const auto& p : alp1)
            cout << p.first << " -> " << p.second << '\n';
        for (const auto& el : rev_alp1)
            cout << el.first << " -> " << el.second << '\n';
    }

    void do_code(string& str)
    {
        lower(str);
        for (int i = 0; i < str.length(); i++)
        {
            switch (i % 3)
            {
            case 0:
                if (alp1.find(str[i]) != alp1.end())
                    str[i] = alp1.at(str[i]);
                break;
            case 1:
                if (alp2.find(str[i]) != alp2.end())
                    str[i] = alp2.at(str[i]);
                break;
            case 2:
                if (alp5.find(str[i]) != alp5.end())
                    str[i] = alp5.at(str[i]);
            default:
                break;
            }
        }
    }
    void do_uncode(string& str)
    {
        lower(str);
        for (int i = 0; i < str.length(); i++)
        {
            switch (i % 3)
            {
            case 0:
                if (rev_alp1.find(str[i]) != rev_alp1.end())
                    str[i] = rev_alp1.at(str[i]);
                break;
            case 1:
                if (rev_alp2.find(str[i]) != rev_alp2.end())
                    str[i] = rev_alp2.at(str[i]);
                break;
            case 2:
                if (rev_alp5.find(str[i]) != rev_alp5.end())
                    str[i] = rev_alp5.at(str[i]);
            default:
                break;
            }
        }
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Code code;
    cout << "Введите строку: ";
    string str;
    getline(cin, str);

    code.do_code(str);
    cout << "Закодированная строка: " << str << endl;

    code.do_uncode(str);
    cout << "Раскодированная строка: " << str << endl;
}