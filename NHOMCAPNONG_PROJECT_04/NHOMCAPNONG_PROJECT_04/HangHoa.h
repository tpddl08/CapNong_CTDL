#pragma once

#ifndef HANGHOA_H
#define HANGHOA_H

#include <iostream>
#include <string>

using namespace std;

class HangHoa {
private:
    string _strMaHang, _strTenHang, _strNoiSanXuat, _strMauSac, _strNgayNhapKho;
    int _iGiaBan, _iSoLuong;
public:
    HangHoa() {
        _strMaHang = "";
        _strTenHang = "";
        _strNoiSanXuat = "";
        _strMauSac = "";
        _iGiaBan = 0;
        _strNgayNhapKho = "";
        _iSoLuong = 0;
    }
    /*Hàm get cho tất cả*/
    string getMaHang() {
        return _strMaHang;
    }
    string getTenHang() {
        return _strTenHang;
    }
    string getNoiSanXuat() {
        return _strNoiSanXuat;
    }
    string getMauSac() {
        return _strMauSac;
    }

    int getGiaBan() {
        return _iGiaBan;
    }
    string getNgayNhapKho() {
        return _strNgayNhapKho;
    }
    int getSoLuong() {
        return _iSoLuong;
    }
    /*Hàm set cho tất cả*/
    void setMaHang(string strMaHang) {
        _strMaHang = strMaHang;
    }
    void setTenHang(string strTenHang) {
        _strTenHang = strTenHang;
    }
    void setNoiSanXuat(string strNoiSanXuat) {
        _strNoiSanXuat = strNoiSanXuat;
    }
    void setMauSac(string strMauSac) {
        _strMauSac = strMauSac;
    }
    void setGiaBan(int iGiaBan) {
        _iGiaBan = iGiaBan;
    }
    void setNgayNhapKho(string strNgayNhapKho) {
        _strNgayNhapKho = strNgayNhapKho;
    }
    void setSoLuong(int iSoLuong) {
        _iSoLuong = iSoLuong;
    }
    /*Nhập Xuất*/
    friend istream& operator >>(istream& is, HangHoa& in) {
        is >> in._strMaHang;
        getline(is, in._strTenHang);
        is >> in._strNoiSanXuat >> in._strMauSac >> in._iGiaBan >> in._strNgayNhapKho >> in._iSoLuong;
        return is;
    }
    friend ostream& operator << (ostream& os, HangHoa out) {
        cout << "XAC NHAN THONG TIN: ";
        os << out._strMaHang << " -> " << out._strTenHang << " -> " << out._strNoiSanXuat << " -> " << out._strMauSac << " -> " << out._iGiaBan << " -> " << out._strNgayNhapKho << " -> " << out._iSoLuong;
        return os;
    }

};


#endif