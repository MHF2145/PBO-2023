#include <cstdio>
#include <cmath>
#include <stack>
#include <cstring>
#include <string>

// Ukuran grid yang digunakan untuk pola
constexpr int gridSize = 21;
// Konstanta untuk ukuran buffer
constexpr int maxExpressionSize = 1000;

// Kelas fungsipola untuk melakukan pola fungsi dan turunannya
class fungsipola
{
public:
    // Konstruktor menerima ekspresi dalam notasi Polandia terbalik
    fungsipola(const char *rpn) : rpn(rpn) {}

    // Fungsi untuk melakukan pola pada grid
    void pola(char polaGrid[gridSize][gridSize])
    {
        for (int x = 0; x < gridSize; ++x)
        {
            // Menghitung nilai fungsi dan turunannya untuk setiap titik x pada grid
            double value = caclRPN(x);          // Menghitung nilai fungsi pada titik x
            double derivative = calcTurunan(x); // Menghitung turunan fungsi pada titik x

            // Menetapkan titik pada grid untuk nilai fungsi dan turunannya
            setGridPoint(polaGrid, x, nilaibulat(value), '*');      // Jika titik adalah fungsi maka tulis *
            setGridPoint(polaGrid, x, nilaibulat(derivative), '+'); // Jika titik adalah turunan maka tulis +
        }
    }

    // Fungsi untuk menampilkan grid
    void cetak(char polaGrid[gridSize][gridSize])
    {
        for (int y = gridSize - 1; y >= 0; --y)
        {
            for (int x = 0; x < gridSize; ++x)
            {
                printf("%c", polaGrid[y][x]);
            }
            printf("\n");
        }
    }

private:
    // Ekspresi dalam notasi Polandia terbalik
    const char *rpn;

    // Fungsi untuk membulatkan nilai double ke integer
    int nilaibulat(double value)
    {
        return static_cast<int>(value + (value < 0 ? -0.5 : 0.5));
    }

    // Fungsi untuk menghitung nilai fungsi pada titik x
    double caclRPN(double x)
    {
        std::stack<double> RPNstack;
        char expression[maxExpressionSize];
        strcpy(expression, rpn);
        char *token = strtok(expression, " ");

        while (token != NULL)
        {
            if (isdigit((unsigned char)token[0]) || (token[0] == '-' && isdigit((unsigned char)token[1])))
            {
                RPNstack.push(atof(token)); // Menggunakan atof sebagai pengganti std::stod
            }
            else if (strcmp(token, "x") == 0)
            {
                RPNstack.push(x);
            }
            else
            {
                performOperation(token, RPNstack);
            }

            token = strtok(NULL, " ");
        }

        return RPNstack.top();
    }

    // Fungsi untuk menghitung turunan fungsi pada titik x
    double calcTurunan(double x)
    {
        const double h = 0.0001;
        return (caclRPN(x + h) - caclRPN(x - h)) / (2 * h);
    }

    // Fungsi untuk menetapkan titik pada grid dengan simbol tertentu
    void setGridPoint(char polaGrid[gridSize][gridSize], int x, int y, char symbol)
    {
        if (y >= 0 && y < gridSize)
        {
            polaGrid[y][x] = symbol;
        }
    }

    // Fungsi untuk melakukan operasi yang ditentukan dalam ekspresi Polandia terbalik
    void performOperation(const char *token, std::stack<double> &RPNstack)
    {
        double operand2 = RPNstack.top();
        RPNstack.pop();
        double operand1 = RPNstack.top();
        RPNstack.pop();

        if (strcmp(token, "+") == 0)
        {
            RPNstack.push(operand1 + operand2);
        }
        else if (strcmp(token, "-") == 0)
        {
            RPNstack.push(operand1 - operand2);
        }
        else if (strcmp(token, "*") == 0)
        {
            RPNstack.push(operand1 * operand2);
        }
        else if (strcmp(token, "/") == 0)
        {
            RPNstack.push(operand1 / operand2);
        }
        else if (strcmp(token, "^") == 0)
        {
            RPNstack.push(pow(operand1, operand2));
        }
        else
        {
            RPNstack.push(0.0); // Menangani operasi yang tidak dikenal dengan baik
        }
    }
};

// Fungsi utama
int main()
{
    // Membaca jumlah fungsi yang akan diplot untuk membentuk pola
    int functions;
    scanf("%d", &functions);

    // Membersihkan buffer input
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;

    // Matriks grid untuk setiap plot fungsi
    char grid[gridSize][gridSize];

    // Loop untuk setiap fungsi yang akan diplot
    for (int i = 0; i < functions; ++i)
    {
        // Membaca ekspresi fungsi dalam notasi Polandia terbalik
        char expression[maxExpressionSize];
        scanf("%999[^\n]", expression);
        getchar(); // Mengonsumsi karakter newline

        // Membuat objek plotter untuk fungsi tersebut
        fungsipola plotter(expression);

        // Menginisialisasi grid dengan titik-titik awal
        for (int y = 0; y < gridSize; ++y)
        {
            for (int x = 0; x < gridSize; ++x)
            {
                grid[y][x] = '.';
            }
        }

        // Melakukan pola fungsi pada grid
        plotter.pola(grid);

        // Menampilkan hasil pola pada grid
        plotter.cetak(grid);
    }

    return 0;
}
