#include <iostream>
#include "DanhSachHangHoa.h"
#include "Admin.h"
#include "Constants.h"
#include <Windows.h>

using namespace std;

int main() {
    DanhSachHangHoa danhSachHangHoa;
    char luaChon;
    string duongDanFile = "HangHoa.txt";
    danhSachHangHoa.nhapDuLieu(duongDanFile);
    DonHang dh;
    Admin ad;
    do {
        system("CLS");
        danhSachHangHoa.HienThiDanhMuc();
        cin >> luaChon;

        switch (luaChon) {
        case '1':
            danhSachHangHoa.HienThiDanhSach();
            system("PAUSE");
            break;
        case '2': {
            string tuKhoa;
            cout << "Nhap ma hang hoac ten hang muon tim kiem: ";
            cin.ignore();
            getline(cin, tuKhoa);
            if (tuKhoa.length() < 4) {
                cout << "Ma hang hoa can co 4 ki tu\n";
            }
            else {
                danhSachHangHoa.searchHangHoa(tuKhoa);
            }

            system("PAUSE");
            break;
        }

        case '3':
            cout << "Dat hang" << endl;
            danhSachHangHoa.datHang();
            break;
        case '4':
            system("cls");
            if (!ad.dangNhap()) {
                cin.ignore();
                cin.get();
                break;
            }
            ad.hienThiMenuQuanLy(danhSachHangHoa, duongDanFile);
            break;
        case '0':
            cout << "Cam on ban da su dung chuong trinh. Tam biet!\n";
            break;
        default:
            cout << "Lua chon khong hop le. Vui long nhap lai.\n";
            system("PAUSE");
            break;
        }
    } while (luaChon != '0');

    return 0;
}
