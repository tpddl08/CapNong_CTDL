#pragma once

#ifndef DONHANG_H
#define DONHANG_H

#include <string>
#include <vector>

using namespace std;

class DonHang {
private:
    vector<string> _vtMaHang;
    vector<int> _vtSoLuong;
    int _iTongTien;
    string _strTenKhachHang, _strDiaChi, _strSoDienThoai, _strNgayDatHang;
public:
    DonHang() {
        _strTenKhachHang = "";
        _strDiaChi = "";
        _strSoDienThoai = "";
        _strNgayDatHang = "";
        _iTongTien = 0;
    }
    /*Hàm get cho tất cả*/
    string getTenKhachHang() {
        return _strTenKhachHang;
    }
    string getDiaChi() {
        return _strDiaChi;
    }
    string getSoDienThoai() {
        return _strSoDienThoai;
    }
    string getNgayDatHang() {
        return _strNgayDatHang;
    }
    int getTongTien() {
        return _iTongTien;
    }
    vector<string> getLoaiHang() {
        return _vtMaHang;
    }
    vector<int> getSoLuong() {
        return _vtSoLuong;
    }
    /*Hàm set cho tất cả*/
    void setTenKhachHang(string strName) {
        _strTenKhachHang = strName;
    }
    void setDiaChi(string strAddress) {
        _strDiaChi = strAddress;
    }
    void setSoDienThoai(string strNumber) {
        _strSoDienThoai = strNumber;
    }
    void setNgayDatHang(string strDate) {
        _strNgayDatHang = strDate;
    }
    void setTongTien(int iSum) {
        _iTongTien = iSum;
    }
    void setLoaiHang(vector<string> vtMaHang) {
        _vtMaHang = vtMaHang;
    }
    void setSoLuong(vector<int> vtSoLuong) {
        _vtSoLuong = vtSoLuong;
    }
};


#endif
