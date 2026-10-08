#include <iostream>
#include <string>
using namespace std;

// Fungsi dari database / sistem eksternal
Customer getCustomerData(string customerNumber);

int main() {

    string customerInput;
    string pinInput;
    int pilihan;
    long long jumlahTarik;

    cout << "====================================\n";
    cout << "              ATM BANK\n";
    cout << "====================================\n";

    // =========================
    // LOGIN CUSTOMER
    // =========================
    cout << "Nomor Customer : ";
    cin >> customerInput;

    // Ambil data customer dari database
    auto customer = getCustomerData(customerInput);

    // =========================
    // VALIDASI CUSTOMER
    // =========================
    if (!customer.found) {
        cout << "\nCustomer tidak ditemukan.\n";
        cout << "Transaksi dibatalkan.\n";
        return 0;
    }

    // =========================
    // INPUT PIN
    // =========================
    cout << "PIN            : ";
    cin >> pinInput;

    if (pinInput != customer.pin) {
        cout << "\nPIN salah!\n";
        cout << "Transaksi dibatalkan.\n";
        return 0;
    }

    cout << "\nLogin berhasil.\n";

    // =========================
    // MENU ATM
    // =========================
    do {
        cout << "\n====================================\n";
        cout << "              MENU ATM\n";
        cout << "====================================\n";
        cout << "1. Cek Saldo\n";
        cout << "2. Tarik Tunai\n";
        cout << "3. Keluar\n";
        cout << "====================================\n";
        cout << "Pilih menu : ";
        cin >> pilihan;

        switch (pilihan) {

            case 1:
                cout << "\nSaldo Anda: Rp "
                     << customer.saldo << endl;
                break;

            case 2:

                cout << "\nSaldo tersedia: Rp "
                     << customer.saldo << endl;

                cout << "Jumlah penarikan: Rp ";
                cin >> jumlahTarik;

                if (jumlahTarik <= 0) {
                    cout << "Jumlah penarikan tidak valid.\n";
                }
                else if (jumlahTarik > customer.saldo) {
                    cout << "Saldo tidak mencukupi.\n";
                }
                else {
                    customer.saldo -= jumlahTarik;

                    cout << "\n------------------------------------\n";
                    cout << "       PENARIKAN BERHASIL\n";
                    cout << "------------------------------------\n";
                    cout << "Customer       : " << customerInput << endl;
                    cout << "Jumlah tarik   : Rp " << jumlahTarik << endl;
                    cout << "Sisa saldo     : Rp " << customer.saldo << endl;
                    cout << "------------------------------------\n";
                }

                break;

            case 3:
                cout << "\nTerima kasih telah menggunakan ATM.\n";
                break;

            default:
                cout << "\nPilihan tidak valid.\n";
        }

    } while (pilihan != 3);

    return 0;
}
