#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <cmath>

constexpr int gridSize = 21;

class fungsipola
{
public:
    // Konstruktor untuk inisialisasi ekspresi berbentuk Notasi Polandia Terbalik (RPN)
    fungsipola(const std::string &rpnExpression) : rpnExpression(rpnExpression) {}

    // Fungsi untuk mempola fungsi ke dalam grid 2D
    void pola(std::vector<std::vector<char>> &polaGrid)
    {
        for (int x = 0; x < gridSize; ++x)
        {
            // Evaluasi nilai fungsi dan turunannya pada titik x 
            double value = calcRPN(x); //hitung Reverse Polish notation
            double derivative = calcTurunan(x); //hitung turunan

            // Bulatkan nilai dan turunan fungsi ke integer
            int y_value = bulatkan(value);
            int dy_value = bulatkan(derivative);

            // pola titik fungsi pada grid
            if (y_value >= 0 && y_value < gridSize)
            {
                polaGrid[y_value][x] = '*';
            }

            // pola titik turunan fungsi pada grid
            if (dy_value >= 0 && dy_value < gridSize)
            {
                polaGrid[dy_value][x] = '+';
            }
        }
    }

private:
    std::string rpnExpression;

    // Fungsi untuk pembulatan nilai double ke integer
    int bulatkan(double value)
    {
        return static_cast<int>(std::round(value));
    }

    // Fungsi untuk mengevaluasi ekspresi RPN pada titik x
    double calcRPN(double x)
    {
        std::stringstream iss(rpnExpression);
        std::stack<double> stack;
        std::string token;

        while (iss >> token)
        {
            if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1])))
            {
                stack.push(std::stod(token));
            }
            else if (token == "x")
            {
                stack.push(x);
            }
            else
            {
                double operand2 = stack.top();
                stack.pop();
                double operand1 = stack.top();
                stack.pop();

                // Melakukan operasi matematika sesuai dengan operator
                if (token == "+")
                {
                    stack.push(operand1 + operand2);
                }
                else if (token == "-")
                {
                    stack.push(operand1 - operand2);
                }
                else if (token == "*")
                {
                    stack.push(operand1 * operand2);
                }
                else if (token == "/")
                {
                    stack.push(operand1 / operand2);
                }
                else if (token == "^")
                {
                    stack.push(pow(operand1, operand2));
                }
                else
                {
                    return 0.0;
                }
            }
        }

        return stack.top();
    }

    // Fungsi untuk menghitung turunan fungsi pada titik x
    double calcTurunan(double x)
    {
        constexpr double h = 0.0001;
        return static_cast<int>(std::round((calcRPN(x + h) - calcRPN(x - h)) / (2 * h)));
    }
};

// Fungsi utama
int main()
{
    // Input jumlah fungsi yang akan dipola
    int functions;
    std::cin >> functions;
    std::cin.ignore();

    // Input ekspresi RPN untuk setiap fungsi
    std::vector<std::string> rpnExpressions(functions);
    for (int i = 0; i < functions; ++i)
    {
        std::getline(std::cin, rpnExpressions[i]);
    }

    // Inisialisasi grid untuk mempola fungsi-fungsi
    std::vector<std::vector<char>> polaGrid(gridSize, std::vector<char>(gridSize, '.'));

    // Iterasi melalui setiap ekspresi RPN dan mempola fungsi pada grid
    for (const auto &rpnExpression : rpnExpressions)
    {
        fungsipola pattern(rpnExpression);
        pattern.pola(polaGrid);

        // Menampilkan grid ke layar
        for (int y = gridSize - 1; y >= 0; --y)
        {
            for (int x = 0; x < gridSize; ++x)
            {
                std::cout << polaGrid[y][x];
            }
            std::cout << std::endl;
        }

        // Mengosongkan grid pola untuk fungsi berikutnya
        for (auto &row : polaGrid)
        {
            std::fill(row.begin(), row.end(), '.');
        }
    }

    return 0;
}
