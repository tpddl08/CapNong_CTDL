#pragma once

#ifndef DANHSACHHANGHOA_H
#define DANHSACHHANGHOA_H

#include "HangHoa.h"
#include "DonHang.h"
#include "Node.h"
#include "Constants.h"
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <algorithm>

using namespace std;

class DanhSachHangHoa {
private:
    Node<HangHoa>* _pHead;
    Node<HangHoa>* _pTail;
    int _soLuongMatHang;

public:
    DanhSachHangHoa() {
        _pHead = NULL;
        _pTail = NULL;
        _soLuongMatHang = 0;
    }

    void themCuoi(HangHoa hh) {
        Node<HangHoa>* _pNodeMoi = new Node<HangHoa>(hh);
        if (_pTail == NULL) {
            _pHead = _pTail = _pNodeMoi;
        }
        else {
            _pTail->_pNext = _pNodeMoi;
            _pTail = _pNodeMoi;
        }
        _soLuongMatHang++;
    }

    void nhapDuLieu(string duongDan) {
        ifstream fileNhap(duongDan);
        HangHoa hh;
        while (!fileNhap.eof()) {
            string dong;
            while (getline(fileNhap, dong)) {
                if (dong[0] == '/' && dong[1] == '/') continue;
                stringstream ss(dong);
                string tu;
                vector<string> hangHoa;
                while (!ss.eof()) {
                    getline(ss, tu, ';');
                    tu.erase(tu.find_last_not_of(" ") + 1);
                    tu.erase(0, tu.find_first_not_of(" "));
                    hangHoa.push_back(tu);
                }
                if (hangHoa.size() >= 7 && hangHoa[0].length() == 4 && hangHoa[1].length() && hangHoa[2].length() && hangHoa[3].length() && hangHoa[4].length()
                    && hangHoa[5].length() && hangHoa[6].length()) {
                    hh.setMaHang(hangHoa[0]);
                    hh.setTenHang(hangHoa[1]);
                    hh.setNoiSanXuat(hangHoa[2]);
                    hh.setMauSac(hangHoa[3]);
                    hh.setGiaBan(stoi(hangHoa[4]));
                    hh.setNgayNhapKho(hangHoa[5]);
                    hh.setSoLuong(stoi(hangHoa[6]));
                    themCuoi(hh);
                }
            }
        }
        fileNhap.close();
    }
    void updateDuLieu(string path) {
        ofstream output;
        output.open(path);
        if (output.is_open()) {
            Node<HangHoa>* pTmp = _pHead;
            while (pTmp != NULL) {
                output << pTmp->data.getMaHang() << "; ";
                output << pTmp->data.getTenHang() << "; ";
                output << pTmp->data.getNoiSanXuat() << "; ";
                output << pTmp->data.getMauSac() << "; ";
                output << pTmp->data.getGiaBan() << "; ";
                output << pTmp->data.getNgayNhapKho() << "; ";
                output << pTmp->data.getSoLuong() << endl;
                pTmp = pTmp->_pNext;
            }
        }
        output.close();
    }

    bool kiemTraNhapSoDauVao(int& value) {
        string input;
        cin >> input;

        // Kiểm tra nếu nhập có ký tự không phải số
        for (char c : input) {
            if (!isdigit(c)) {  // Kiểm tra nếu ký tự không phải số
                return false;
            }
        }

        // Chuyển chuỗi thành số nguyên và kiểm tra giá trị
        value = stoi(input);
        return value > 0;  // Ki?m tra s? ph?i l?n h?n 0
    }

    bool laNamNhuan(int nam) {
        return (nam % 4 == 0 && nam % 100 != 0) || (nam % 400 == 0);
    }

    bool kiemTraNgayHopLe(int ngay, int thang, int nam) {
        if (nam <= 0 || thang <= 0 || thang > 12 || ngay <= 0) {
            return false;
        }

        int soNgayTrongThang[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        // Nếu là năm nhuận, tháng 2 có 29 ngày.
        if (laNamNhuan(nam)) {
            soNgayTrongThang[1] = 29;
        }

        return ngay <= soNgayTrongThang[thang - 1];
    }

    void themHangHoa() {
        HangHoa hh;
        string maHang, tenHang, noiSanXuat, mauSac;
        int ngay, thang, nam;
        int giaBan, soLuong;

        cout << endl;
        cout << setw(35) << right << PINK << "======= THEM HANG HOA MOI =======" << RESET << endl;
        // Nhập và kiểm tra mã hàng.
        do {
            cout << setw(38) << right << "Nhap ma hang: ";
            cin >> maHang;
            if (maHang.length() != 4) {
                cout << setw(29) << right << RED << "Ma hang phai co 4 ky tu. Vui long nhap lai." << RESET << endl;
            }
            else if (TonTaiHangHoa(maHang)) {
                cout << setw(29) << right << RED << "Ma hang da ton tai. Vui long nhap lai." << RESET << endl;
            }
            else {
                break;
            }
        } while (true);

        // Nhập thông tin còn lại.
        cin.ignore();
        cout << setw(39) << right << "Nhap ten hang: ";
        getline(cin, tenHang);
        cout << setw(43) << right << "Nhap noi san xuat: ";
        getline(cin, noiSanXuat);
        cout << setw(38) << right << "Nhap mau sac: ";
        getline(cin, mauSac);
        do {
            cout << setw(44) << right << "Nhap ngay nhap kho: " << endl;
            cout << setw(35) << right << "Ngay: "; kiemTraNhapSoDauVao(ngay);
            cout << setw(36) << right << "Thang: "; kiemTraNhapSoDauVao(thang);
            cout << setw(34) << right << "Nam: "; kiemTraNhapSoDauVao(nam);

            if (kiemTraNgayHopLe(ngay, thang, nam)) {
                break;
            }
            else {
                cout << setw(29) << right << RED << "Ngay nhap kho khong hop le. Vui long nhap lai." << RESET << endl;
            }
        } while (true);


        // Kiểm tra và nhập giá bán.
        do {
            cout << setw(38) << right << "Nhap gia ban: ";
            kiemTraNhapSoDauVao(giaBan);
            if (giaBan > 0) {
                break;
            }
            else {
                cout << setw(29) << right << RED << "Gia ban phai la so nguyen duong. Vui long nhap lai." << RESET << endl;
            }
        } while (true);

        // Kiểm tra và nhập số lượng.
        while (true) {
            string input;
            cout << setw(39) << right << "Nhap so luong: ";
            cin >> input;

            // Kiểm tra xem người dùng có nhập chữ hoặc ký tự không phải số
            bool isValid = true;
            for (char c : input) {
                if (!isdigit(c)) {  // Kiểm tra nếu ký tự không phải là số
                    isValid = false;
                    break;
                }
            }

            if (!isValid) {
                cout << setw(29) << right << RED << "Nhap sai! Vui long nhap so nguyen duong." << RESET << endl;
            }
            else {
                // Chuyển đổi từ chuỗi sang số nguyên
                soLuong = stoi(input);

                if (soLuong <= 0) {
                    cout << setw(29) << right << RED << "So luong phai la so nguyen duong. Vui long nhap lai." << RESET << endl;
                }
                else {
                    break; // Thoát vòng lặp khi nhập hợp lệ
                }
            }
        }

        // Cập nhật thông tin hàng hóa vào đối tượng.
        hh.setMaHang(maHang);
        hh.setTenHang(tenHang);
        hh.setNoiSanXuat(noiSanXuat);
        hh.setMauSac(mauSac);
        hh.setNgayNhapKho((ngay < 10 ? "0" : "") + to_string(ngay) + "/" + (thang < 10 ? "0" : "") + to_string(thang) + "/" + to_string(nam));
        hh.setGiaBan(giaBan);
        hh.setSoLuong(soLuong);

        // Thêm hàng hóa vào danh sách.
        themCuoi(hh);
        cout << setw(34) << GREEN << "Them hang hoa thanh cong!" << RESET << endl;
    }

    void searchHangHoa(string tuKhoa) {
        cout << "\nKet qua tim kiem:\n";
        cout << BOLD << YELLOW;
        cout << left << setw(10) << "Ma hang"
            << setw(25) << "Ten hang"
            << setw(20) << "Noi san xuat"
            << setw(15) << "Mau sac"
            << setw(15) << "Gia ban"
            << setw(15) << "Ngay nhap"
            << setw(10) << "So luong" << RESET << endl;
        cout << string(110, '-') << endl;

        bool timThay = false;
        Node<HangHoa>* _pTemp = _pHead;
        while (_pTemp != NULL) {
            if (_pTemp->data.getMaHang().find(tuKhoa) != string::npos || _pTemp->data.getTenHang().find(tuKhoa) != string::npos) {
                cout << left << setw(10) << _pTemp->data.getMaHang()
                    << setw(25) << _pTemp->data.getTenHang()
                    << setw(20) << _pTemp->data.getNoiSanXuat()
                    << setw(15) << _pTemp->data.getMauSac()
                    << setw(15) << _pTemp->data.getGiaBan()
                    << setw(15) << _pTemp->data.getNgayNhapKho()
                    << setw(10) << _pTemp->data.getSoLuong() << endl;
                cout << string(110, '-') << endl;
                timThay = true;
            }
            _pTemp = _pTemp->_pNext;
        }

        if (!timThay) {
            cout << "Hang hoa khong ton tai." << endl;
        }
    }

    void HienThiDanhSach() {
        cout << BOLD << PINK << setw(60) << right << "BANG HANG HOA" << RESET << endl;
        cout << BOLD << YELLOW;
        cout << left << setw(10) << "Ma hang"
            << setw(25) << "Ten hang"
            << setw(20) << "Noi san xuat"
            << setw(15) << "Mau sac"
            << setw(15) << "Gia ban"
            << setw(15) << "Ngay nhap kho"
            << setw(10) << "So luong" << RESET << endl;
        cout << string(110, '-') << endl;

        Node<HangHoa>* _pTemp = _pHead;
        while (_pTemp != NULL) {
            cout << left << setw(10) << _pTemp->data.getMaHang()
                << setw(25) << _pTemp->data.getTenHang()
                << setw(20) << _pTemp->data.getNoiSanXuat()
                << setw(15) << _pTemp->data.getMauSac()
                << setw(15) << _pTemp->data.getGiaBan()
                << setw(15) << _pTemp->data.getNgayNhapKho()
                << setw(10) << _pTemp->data.getSoLuong() << endl;
            cout << string(110, '-') << endl;
            _pTemp = _pTemp->_pNext;
        }
    }

    void HienThiDanhMuc() {
        cout << GREEN;
        cout << setw(60) << right << string(40, '_') << endl;
        cout << setw(21) << right << "|" << CYAN << "    CHUONG TRINH QUAN LY HANG HOA     " << GREEN << "|" << endl;
        cout << GREEN;
        cout << GREEN << setw(21) << right << "|" << YELLOW << "    1. Hien thi thong tin hang hoa    " << GREEN << "|" << endl;
        cout << GREEN << setw(21) << right << "|" << YELLOW << "    2. Tim kiem thong tin hang hoa    " << GREEN << "|" << endl;
        cout << GREEN << setw(21) << right << "|" << YELLOW << "    3. Dat hang                       " << GREEN << "|" << endl;
        cout << GREEN << setw(21) << right << "|" << YELLOW << "    4. Quan li                        " << GREEN << "|" << endl;
        cout << GREEN << setw(21) << right << "|" << YELLOW << "    0. Thoat                          " << GREEN << "|" << endl;
        cout << setw(60) << right << string(40, '-') << RESET << endl;
        cout << setw(43) << right << "Nhap lua chon: ";
    }

    bool TonTaiHangHoa(string maHang) {
        Node<HangHoa>* _pTemp = _pHead;
        while (_pTemp != NULL) {
            if (_pTemp->data.getMaHang() == maHang) {
                return true;
            }
            _pTemp = _pTemp->_pNext;
        }
        return false;
    }

    void Xoa(string x) {
        if (_pHead != nullptr && _pHead->data.getMaHang() == x) {
            Node<HangHoa>* pTemp = _pHead;
            _pHead = _pHead->_pNext;
            delete pTemp;
            _soLuongMatHang--;
            return;
        }
        else {
            Node<HangHoa>* pWalker = _pHead;
            Node<HangHoa>* pTemp = NULL;

            while (pWalker != NULL && pWalker->data.getMaHang() != x) {
                pTemp = pWalker;
                pWalker = pWalker->_pNext;
            }

            if (pWalker == NULL) return;

            if (pTemp != NULL) {
                if (pWalker == _pTail) {
                    _pTail = pTemp;
                    _pTail->_pNext = NULL;
                }
                pTemp->_pNext = pWalker->_pNext;
                delete pWalker;
                _soLuongMatHang--;
            }
        }
    }

    void updateSoLuong(string x, int soluong) {
        Node<HangHoa>* pTemp = _pHead;
        while (pTemp != NULL) {
            if (pTemp->data.getMaHang() == x) {
                pTemp->data.setSoLuong(soluong);
                return;
            }
            pTemp = pTemp->_pNext;
        }
    }

    void datHang() {
        DonHang dh;
        string _strtenKhachHang, _strdiaChi, _strsoDienThoai, _strngayDatHang;
        vector<string> _vtdanhSachMaHang;
        vector<int> _vtdanhSachSoLuong;
        int _itongTien = 0;
        int iSoLuongDon = 0;

        cin.ignore(); // Xóa b? ??m
        cout << "Nhap ten khach hang: ";
        getline(cin, _strtenKhachHang);
        while (true) {
            cout << "Nhap dia chi: ";
            getline(cin, _strdiaChi);
            if (validateAddress(_strdiaChi)) {
                break;  // ??a ch? h?p l?
            }
            else {
                cout << "Chung toi cho giao cac tinh o Viet Nam. Vui long ghi chinh xac ten tinh thanh co khoang cach voi nhau.\n";
            }
        }
        while (true) {
            cout << "Nhap so dien thoai: ";
            getline(cin, _strsoDienThoai);
            if (_strsoDienThoai.length() == 10 && all_of(_strsoDienThoai.begin(), _strsoDienThoai.end(), ::isdigit)) {
                break;
            }
            else {
                cout << "So dien thoai khong hop le.\n";
            }
        }

        // Kiểm tra ngày đặt hàng
        while (true) {
            cout << "Nhap ngay dat hang (dd/mm/yyyy): ";
            getline(cin, _strngayDatHang);
            if (validateDate(_strngayDatHang)) {
                break;
            }
            else {
                cout << "Ngay dat hang khong hop le.\n";
            }
        }

        dh.setTenKhachHang(_strtenKhachHang);
        dh.setDiaChi(_strdiaChi);
        dh.setSoDienThoai(_strsoDienThoai);
        dh.setNgayDatHang(_strngayDatHang);

        while (true) {
            string maHang;
            int soLuong;
            cout << "\nNhap ma hang (nhap \"x\" de ngung dat hang): ";
            cin >> maHang;
            if (maHang == "x" || maHang == "X") { break; }
            else { iSoLuongDon++; };
            Node<HangHoa>* pSave;
            if (searchPointer(maHang) == NULL) {
                cout << "Ma hang khong ton tai! Vui long nhap lai.\n";
                continue;
            }
            else {
                pSave = searchPointer(maHang);
            }

            cout << "Ma hang hoa: " << pSave->data.getMaHang() << endl;
            cout << "Ten hang hoa: " << pSave->data.getTenHang() << endl;
            cout << "Gia: " << pSave->data.getGiaBan() << endl;

            do {
                cout << "Nhap so luong: ";
                cin >> soLuong;
                if (soLuong <= 0) {
                    cout << "So luong phai la so nguyen duong. Vui long nhap lai.\n";
                }
                else if (soLuong > pSave->data.getSoLuong()) {
                    cout << "So luong vuot qua hang ton kho (" << pSave->data.getSoLuong() << "). Vui long nhap lai.\n";
                }
                else {
                    break;
                }
            } while (true);

            if (iSoLuongDon > 0) {
                _vtdanhSachMaHang.push_back(maHang);
                _vtdanhSachSoLuong.push_back(soLuong);
                _itongTien += soLuong * pSave->data.getGiaBan();
                pSave->data.setSoLuong(pSave->data.getSoLuong() - soLuong);


                dh.setLoaiHang(_vtdanhSachMaHang);
                dh.setSoLuong(_vtdanhSachSoLuong);
                dh.setTongTien(_itongTien);

                cout << "\nThong tin don hang:\n";
                cout << "Ten khach hang: " << dh.getTenKhachHang() << endl;
                cout << "Dia chi: " << dh.getDiaChi() << endl;
                cout << "So dien thoai: " << dh.getSoDienThoai() << endl;
                cout << "Ngay dat hang: " << dh.getNgayDatHang() << endl;
                cout << "Tong tien: " << dh.getTongTien() << " VND\n";
                cout << "Danh sach hang da dat:\n";
                for (size_t i = 0; i < _vtdanhSachMaHang.size(); i++) {
                    cout << " - Ma hang: " << _vtdanhSachMaHang[i] << ", So luong: " << _vtdanhSachSoLuong[i] << endl;
                }


                ofstream file("DonHang.txt", ios::app);
                if (file.is_open()) {
                    file << "Thong tin don hang:\n";
                    file << "Ten khach hang: " << dh.getTenKhachHang() << endl;
                    file << "Dia chi: " << dh.getDiaChi() << endl;
                    file << "So dien thoai: " << dh.getSoDienThoai() << endl;
                    file << "Ngay dat hang: " << dh.getNgayDatHang() << endl;
                    file << "Tong tien: " << dh.getTongTien() << " VND\n";
                    file << "Danh sach hang da dat:\n";
                    for (size_t i = 0; i < _vtdanhSachMaHang.size(); i++) {
                        file << " - Ma hang: " << _vtdanhSachMaHang[i] << ", So luong: " << _vtdanhSachSoLuong[i] << endl;
                    }
                    file << "----------------------------------------\n";
                    file.close();
                    cout << "\nDon hang da duoc luu vao file DonHang.txt\n";
                }
                else {
                    cout << "Khong the mo file! Vui long kiem tra quyen truy cap file.\n";
                }

                cout << "\nDon hang da duoc dat thanh cong!\n";
                cout << "\nDon hang dang cho xu li\n";
                cout << "Nhan phim bat ki de thoat khoi phan dat hang";
                system("PAUSE");
            }
        }
    }
    /*----------------  Kiểm tra hàng tồn tại ------------------- */
    Node<HangHoa>* searchPointer(string maHang) {
        Node<HangHoa>* pWalker = _pHead;
        Node<HangHoa>* pSave = NULL;
        while (pWalker != NULL) {
            if (pWalker->data.getMaHang() == maHang) {
                pSave = pWalker;
                return pSave;
            }
            pWalker = pWalker->_pNext;
        }
        return NULL;
    }

    /*Kiểm tra ngày*/
    bool validateDate(const string& date) {
        time_t now = time(0);
        tm ltm;
        localtime_s(&ltm, &now);
        int currentDay = ltm.tm_mday;
        int currentMonth = ltm.tm_mon + 1;
        int currentYear = ltm.tm_year + 1900;
        int day, month, year;
        if (sscanf_s(date.c_str(), "%d/%d/%d", &day, &month, &year) != 3) {
            return false;
        }
        if (year > currentYear) {
            return true;
        }
        if (year == currentYear && month > currentMonth) {
            return true;
        }
        if (year == currentYear && month == currentMonth && day >= currentDay) {
            return true;
        }
        return false;
    }
    /*Kiểm tra địa chỉ ở Việt Nam*/
    bool validateAddress(const string& address) {
        for (const auto& Tinh : TinhThanh) {
            if (address.find(Tinh) != string::npos) {
                return true;
            }
        }
        return false;
    }
    const vector<string> TinhThanh = {
        "Tinh An Giang", "Tinh Bac Ninh", "Tinh Ca Mau", "TP Can Tho", "Tinh Cao Bang",
        "TP Da Nang", "Tinh Dak Lak", "Tinh Dien Bien", "Tinh Dong Nai", "Tinh Dong Thap",
        "Tinh Gia Lai", "TP Ha Noi", "Tinh Ha Tinh", "TP Hai Phong", "TP Ho Chi Minh",
        "TP Hue", "Tinh Hung Yen", "Tinh Khanh Hoa", "Tinh Lai Chau", "Tinh Lam Dong",
        "Tinh Lang Son", "Tinh Lao Cai", "Tinh Nghe An", "Tinh Ninh Binh", "Tinh Phu Tho",
        "Tinh Quang Ngai", "Tinh Quang Ninh", "Tinh Quang Tri", "Tinh Son La",
        "Tinh Tay Ninh", "Tinh Thai Nguyen", "Tinh Thanh Hoa", "Tinh Tuyen Quang",
        "Tinh Vinh Long"
    };
    /*-------------------------------------------------------------------------------*/
    int getGiaMatHang(string x) {
        Node<HangHoa>* pTemp = _pHead;
        while (pTemp != NULL) {
            if (pTemp->data.getMaHang() == x) {
                return pTemp->data.getGiaBan();
            }
            pTemp = pTemp->_pNext;
        }
        return 0;
    }


    int getSoLuongMatHang(string x) {
        Node<HangHoa>* pTemp = _pHead;
        while (pTemp != NULL) {
            if (pTemp->data.getMaHang() == x) {
                return pTemp->data.getSoLuong();
            }
            pTemp = pTemp->_pNext;
        }
        return 0;
    }
};


#endif