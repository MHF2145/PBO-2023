#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int trapRainWater(vector<int> &height)
{
    int n = height.size();
    if (n <= 2)
        return 0; // Tidak dapat menjebak air dengan kurang dari 3 bar

    stack<int> st; // Membuat tumpukan (stack) untuk menyimpan indeks bar
    int water = 0; // Variabel untuk menghitung air yang terperangkap

    for (int i = 0; i < n; ++i)
    {
        while (!st.empty() && height[i] > height[st.top()])
        {
            int topIdx = st.top();
            st.pop();

            if (st.empty())
                break; // Tidak ada batas kiri

            int distance = i - st.top() - 1; // Menghitung jarak antara dua bar
            int boundedHeight = min(height[i], height[st.top()]) - height[topIdx]; // Menghitung tinggi air yang terperangkap
            water += distance * boundedHeight; // Menambahkan air yang terperangkap ke total air yang terperangkap
        }
        st.push(i); // Memasukkan indeks bar ke dalam stack
    }

    return water; // Mengembalikan jumlah total air yang terperangkap
}

int main()
{
    int n;
    cin >> n; // Membaca jumlah bar
    vector<int> elevationMap; // Vektor untuk menyimpan tinggi bar-bar

    for (int i = 0; i < n; ++i)
    {
        int height;
        cin >> height; // Membaca tinggi setiap bar dari input
        elevationMap.push_back(height);
    }

    int trappedWater = trapRainWater(elevationMap); // Menghitung air yang terperangkap
    cout << trappedWater << endl; // Menampilkan hasil jumlah air yang terperangkap ke layar

    return 0;
}
