#pragma once

#ifndef ADMIN_H
#define ADMIN_H

#include "DanhSachHangHoa.h"
#include <string>
#include <conio.h>

using namespace std;

class Admin {
private:
    string _user, _password;
    int _soLanThu;
public:
    Admin() : _soLanThu(0) {}
    string getUser() {
        return _user;
    }
    void setUser(const string& user) {
        _user = user;
    }
    string getPassword() {
        return _password;
    }
    void setPassword(const string& password) {
        _password = password;
    }
    int getSoLanThu() {
        return _soLanThu;
    }
    void setSoLanThu(const int& soLanThu) {
        _soLanThu = soLanThu;
    }

    bool kiemTraDangNhap(const string& user, const string& password) {
        ifstream file("Admin.txt");
        if (!file) {
            cout << "Khong the mo file Admin.txt de kiem tra dang nhap.\n";
            return false;
        }

        string fileUser, filePassword;
        while (file >> fileUser >> filePassword) {
            if (fileUser == user && filePassword == password) {
                return true;
            }
        }

        file.close();
        return false;
    }

    string nhapMatKhau() {
        string password;
        char ch;
        while (true) {
            ch = _getch();
            if (ch == 27) {
                return "EXIT";
            }
            else if (ch == '\r') {
                break;
            }
            else if (ch == '\b') {
                if (!password.empty()) {
                    cout << "\b \b";
                    password.pop_back();
                }
            }
            else {
                password += ch;
                cout << '*';
            }
        }
        cout << endl;
        return password;
    }

    void hienThiMenuQuanLy(DanhSachHangHoa& danhSachHangHoa, string duongDanFile) {
        char luaChon;
        do {
            system("cls");
            cout << GREEN;
            cout << setw(60) << right << string(40, '*') << endl;
            cout << setw(21) << right << "*" << RED << "            MENU QUAN LY              " << GREEN << "*" << endl;
            cout << GREEN;
            cout << setw(21) << right << "*" << YELLOW << "      1. Xu li don hang               " << GREEN << "*" << endl;
            cout << setw(21) << right << "*" << YELLOW << "      2. Quan li hang hoa             " << GREEN << "*" << endl;
            cout << setw(21) << right << "*" << YELLOW << "      0. ESC/Quay lai menu chinh      " << GREEN << "*" << endl;
            cout << setw(60) << right << string(40, '*') << RESET << endl;
            cout << setw(46) << right << "Nhap lua chon: ";

            luaChon = _getch();

            if (luaChon == 27 || luaChon == '0') break; // ESC hoặc 0 thoát

            switch (luaChon) {
            case '1':
                xuLyDonHang(danhSachHangHoa);
                break;
            case '2':
                hienThiMenuQuanLy2(danhSachHangHoa, duongDanFile);
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                system("PAUSE");
                break;
            }

        } while (true);
    }

    void hienThiMenuQuanLy2(DanhSachHangHoa& danhSachHangHoa, string duongDanFile) {
        char luaChon;
        do {
            system("cls");
            cout << GREEN << setw(60) << right << string(40, '*') << endl;
            cout << setw(21) << right << "*" << RED << "         QUAN LI HANG HOA             " << GREEN << "*" << endl;
            cout << setw(21) << right << "*" << YELLOW << "     1. Them hang hoa moi             " << GREEN << "*" << endl;
            cout << setw(21) << right << "*" << YELLOW << "     2. Xoa hang hoa theo ma          " << GREEN << "*" << endl;
            cout << setw(21) << right << "*" << YELLOW << "     3. Cap nhat so luong hang hoa    " << GREEN << "*" << endl;
            cout << setw(21) << right << "*" << YELLOW << "     4. Hien thi danh sach            " << GREEN << "*" << endl;
            cout << setw(21) << right << "*" << YELLOW << "     0. ESC Quay lai menu quan ly     " << GREEN << "*" << endl;
            cout << setw(60) << right << string(40, '*') << RESET << endl;
            cout << setw(46) << right << "Nhap lua chon: ";

            luaChon = _getch();

            if (luaChon == 27 || luaChon == '0') break;

            switch (luaChon) {
            case '1':
                danhSachHangHoa.themHangHoa();
                danhSachHangHoa.updateDuLieu(duongDanFile);
                break;
            case '2': {
                string maHang;
                cout << "Nhap ma hang muon xoa: ";
                cin >> maHang;
                if (danhSachHangHoa.TonTaiHangHoa(maHang)) {
                    danhSachHangHoa.Xoa(maHang);
                    danhSachHangHoa.updateDuLieu(duongDanFile);
                    cout << "Xoa hang hoa thanh cong!\n";
                }
                else cout << "Ma hang khong ton tai!\n";
                system("PAUSE");
                break;
            }
            case '3': {
                string maHang;
                int soLuongMoi;
                cout << "Nhap ma hang muon cap nhat: ";
                cin >> maHang;
                if (danhSachHangHoa.TonTaiHangHoa(maHang)) {
                    cout << "Nhap so luong moi: ";
                    cin >> soLuongMoi;
                    danhSachHangHoa.updateSoLuong(maHang, soLuongMoi);
                    danhSachHangHoa.updateDuLieu(duongDanFile);
                    cout << "Cap nhat so luong thanh cong!\n";
                }
                else cout << "Ma hang khong ton tai!\n";
                system("PAUSE");
                break;
            }
            case '4':
                danhSachHangHoa.HienThiDanhSach();
                system("PAUSE");
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                system("PAUSE");
                break;
            }

        } while (true);
    }

    void xuLyDonHang(DanhSachHangHoa& danhSachHangHoa) {
        char luaChon;
        do {
            system("cls");
            cout << GREEN << setw(60) << right << string(40, '_') << endl;
            cout << setw(21) << right << "|" << CYAN << "         XU LY DON HANG               " << GREEN << "|" << endl;
            cout << setw(21) << right << "|" << YELLOW << "   4. Hien thi danh sach don hang     " << GREEN << "|" << endl;
            cout << setw(21) << right << "|" << YELLOW << "   0. ESC/Quay lai menu quan ly       " << GREEN << "|" << endl;
            cout << setw(60) << right << string(40, '-') << RESET << endl;
            cout << setw(46) << right << "Nhap lua chon: ";

            luaChon = _getch();

            if (luaChon == 27 || luaChon == '0') break;

            switch (luaChon) {
            case '4':
                danhSachHangHoa.HienThiDanhSach();
                system("PAUSE");
                break;
            default:
                cout << "Lua chon khong hop le.\n";
                system("PAUSE");
                break;
            }

        } while (true);
    }



    bool dangNhap() {
        string user, password;
        int soLanThu = 0;
        char key;

        while (soLanThu < 3) {
            system("cls");
            cout << YELLOW;
            cout << setw(60) << right << string(40, '_') << endl;
            cout << setw(21) << right << "|" << RESET;
            cout << GREEN << "           DANG NHAP HE THONG         " << RESET;
            cout << YELLOW << "|" << endl;
            cout << setw(60) << right << string(40, '-');
            cout << RESET << endl;
            cout << GREEN;

            cout << setw(38) << right << "User: " << RESET;
            key = _getch();
            if (key == 27) {
                cout << "\nDang nhap that bai. Tro ve menu chinh.\n";
                cout << "Press any key to continue....";
                return false;
            }
            cin.putback(key);
            cin.ignore();
            cin >> user;
            cout << GREEN << setw(42) << right << "Password: " << RESET;
            password = nhapMatKhau();
            if (password == "EXIT") {
                cout << "\nDang nhap that bai. Tro ve menu chinh.\n";
                cout << "Press any key to continue....";
                return false;
            }

            if (kiemTraDangNhap(user, password)) {
                return true;
            }
            else {
                soLanThu++;
                if (soLanThu < 3) {
                    cout << RED << "Sai ten dang nhap hoac mat khau.\n" << RESET;
                    cout << "Nhan Enter de nhap lai...";
                    cin.ignore(10000, '\n');
                    key = _getch();
                    if (key == 27) {
                        cout << "\nDang nhap that bai. Tro ve menu chinh.\n";
                        cout << "Press any key to continue....";
                        return false;
                    }
                }
            }
        }
        if (soLanThu == 3) {
            cout << "Ban da dang nhap sai 3 lan. Dang nhap that bai. Tro ve menu chinh.\n";
        }
        return false;
    }
};


#endif