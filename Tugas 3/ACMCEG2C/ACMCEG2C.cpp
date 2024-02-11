#include <stdio.h>
#include <deque>
#include <vector>
using namespace std;
#define gc getchar_unlocked

template <typename T>
void Getnum(T &val) {
    char ch; bool bo = 0; val = 0;
    for (ch = gc(); ch < '0' || '9' < ch; ch = gc()) if (ch == '-') bo = 1;
    for (; '0' <= ch && ch <= '9'; val = (val << 3) + (val << 1) + ch - 48, ch = gc());
    if (bo) val = -val;
}

int main() {
    int t, n, k;
    Getnum(t);  // Membaca jumlah kasus uji

    while (t--) {
        Getnum(n);  // Membaca jumlah jenis permen dan jumlah permen yang ditampilkan
        Getnum(k);
        vector<int> sweetness(n);

        // Membaca nilai tingkat manis dari jenis permen
        for (int i = 0; i < n; i++) {
            Getnum(sweetness[i]);
        }

        deque<int> window;  // Membuat deque untuk mengelola jendela geser
        int max_index = 0;  // Indeks dengan tingkat manis tertinggi dalam jendela

        // Inisialisasi jendela untuk kasus pertama
        for (int i = 1; i < k; i++) {
            if (sweetness[i] > sweetness[max_index]) {
                max_index = i;
            }
        }
        window.push_back(max_index);  // Menambahkan indeks ke deque

        // Menampilkan pilihan permen untuk anak pertama
        printf("%d ", sweetness[max_index]);

        for (int i = 1; i < n - k + 1; i++) {
            // Memeriksa apakah permen dengan tingkat manis tertinggi keluar dari jendela
            if (max_index == i - 1) {
                // Jika ya, hitung ulang indeks permen dengan tingkat manis tertinggi dalam jendela saat ini
                max_index = i;
                for (int j = i + 1; j < i + k; j++) {
                    if (sweetness[j] > sweetness[max_index]) {
                        max_index = j;
                    }
                }
            } else {
                // Jika tidak, bandingkan permen baru yang masuk jendela dengan tingkat manis tertinggi saat ini
                if (sweetness[i + k - 1] > sweetness[max_index]) {
                    max_index = i + k - 1;
                }
            }

            window.push_back(max_index);  // Menambahkan indeks ke deque

            // Menampilkan pilihan permen untuk anak saat ini
            printf("%d ", sweetness[max_index]);
        }

        printf("\n");  // Pindah ke baris berikutnya untuk kasus berikutnya
    }

    return 0;
}
