#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
using namespace std;

void enter_decimal();
string enter_decimal(int decimal);

void enter_binary();
int binary_to_int(string);

void enter_hex();

string binary_to_hex(string);
void binary_to_hex();

void calculate_2ToN();
string add_comma(string);
void week_1_video_code();

int main()
{
    char again = 'y';
    int choice;

    do
    {
        cout << "\n*******************************"
                "\n1. Enter decimal"
                "\n2. Enter binary"
                "\n3. Enter hex"
                "\n4. Calculate 2^n"
                "\n*******************************\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            enter_decimal();
            break;
        case 2:
            enter_binary();
            break;
        case 3:
            enter_hex();
            break;
        case 4:
            calculate_2ToN();
            break;
        default:
            break;
        }
        cout << "again? y/n ";
        cin >> again;
    } while (again != 'n');
    return 0;
}

string add_comma(string input)
{
    reverse(input.begin(), input.end());
    for (int i = 4; i < input.size(); i += 5)
    {
        input.insert(input.begin() + i, ',');
    }
    reverse(input.begin(), input.end());
    return input;
}

void calculate_2ToN()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    long long int answer = pow(2, n);
    cout << "2^" << n << ": " << answer << endl;
    string binary = enter_decimal(answer);
    cout << "binary: " << binary << endl;
    string hex = binary_to_hex(binary);
    cout << "hex: " << hex << endl;
}

void enter_hex()
{
    string hex; // 207719
    cout << "Enter hex number without 0x: ";
    cin >> hex;
    int size = hex.size();
    string binary;
    for (int i = 0; i < size; i++)
    {
        string temp;
        if (isdigit(hex[i]))
            temp = enter_decimal(hex[i] - '0');
        else if (hex[i] >= 'A' && hex[i] <= 'F')
            temp = enter_decimal(hex[i] - 'A' + 10);
        else
        {
            cout << "double check your hex please. " << endl;
            return;
        }

        while (temp.size() < 4)
            temp.insert(temp.begin(), '0');
        binary += temp;
    }
    cout << "binary: " << add_comma(binary) << endl;
    cout << "decimal: " << binary_to_int(binary) << endl;
}

void enter_decimal()
{
    int decimal = 433;
    cout << "Enter decimal number: ";
    cin >> decimal;
    string binary;
    while (decimal > 0)
    {
        binary.push_back((decimal % 2 ? '1' : '0'));
        decimal = decimal / 2;
    }
    reverse(binary.begin(), binary.end());
    cout << "binary: " << add_comma(binary) << endl;
    cout << "hex: " << add_comma(binary_to_hex(binary)) << endl;
}

string enter_decimal(int decimal)
{
    string binary;
    while (decimal > 0)
    {
        binary.push_back((decimal % 2 ? '1' : '0'));
        decimal = decimal / 2;
    }
    reverse(binary.begin(), binary.end());

    return binary;
}

void enter_binary()
{
    string binary = "1111011100110101100100111111111";
    cout << "Enter binary number: ";
    cin >> binary;

    long long int decimal{0};
    int power = 1;
    for (int i = binary.size() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
            decimal += power;
        power = power * 2;
    }
    cout << "you entered: " << add_comma(binary) << endl;
    cout << "decimal: " << decimal << endl;
    cout << "hex: " << add_comma(binary_to_hex(binary)) << endl;
}

int binary_to_int(string binary)
{
    int decimal = 0;
    int power = 1;
    for (int i = binary.size() - 1; i >= 0; i--)
    {
        if (binary[i] == '1')
            decimal += power;
        power = power * 2;
    }
    return decimal;
}

void binary_to_hex()
{
    std::string binary;
    std::cout << "Enter a binary number: ";
    std::cin >> binary;

    // Ensure the binary string length is a multiple of 4 by padding with leading zeros
    while (binary.size() % 4 != 0)
    {
        binary.insert(binary.begin(), '0');
    }

    std::string hex;
    for (size_t i = 0; i < binary.size(); i += 4)
    {
        std::string fourBits = binary.substr(i, 4);
        int decimalValue = binary_to_int(fourBits);

        // Convert the decimal value to its hexadecimal representation
        if (decimalValue < 10)
            hex.push_back('0' + decimalValue); // '0' + 0 to 9 gives '0' to '9'
        else
            hex.push_back('A' + (decimalValue - 10)); // 'A' + 0 to 5 gives 'A' to 'F'
    }

    std::cout << "hex: 0x" << hex << std::endl;
}

string binary_to_hex(string binary)
{
    string hex;
    while (binary.size() % 4 != 0)
        binary.insert(binary.begin(), '0');

    for (int i = 0; i < binary.size(); i += 4)
    {
        string part = binary.substr(i, 4);
        int decimal = binary_to_int(part);
        if (decimal < 10)
            hex.push_back(decimal + '0');
        else
            hex.push_back(decimal - 10 + 'A');
    }
    return hex;
}

void week_1_video_code()
{
    char c;
    c = 'A';

    int mask;
    mask = 0b10000000;
    for (int i = 0; i < 8; i++)
    {
        printf("%c", c & mask ? '1' : '0');
        mask >>= 1;
    }
}