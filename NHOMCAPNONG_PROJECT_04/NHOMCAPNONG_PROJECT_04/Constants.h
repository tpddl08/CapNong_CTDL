#pragma once

#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <string>
#include <vector>

using namespace std;

// ANSI Color Codes
#define RESET "\033[0m"
#define BOLD "\033[1m"
#define PINK "\033[38;5;207m"
#define YELLOW "\033[38;5;226m"
#define GREEN "\033[38;5;46m"
#define CYAN "\033[36m"
#define RED "\033[31m"

// Input constants
enum IN {
    IN_BACK = 8,
    IN_RET = 13
};

const short cntHidePassword = 25;

// Danh sách tỉnh thành Việt Nam
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

#endif 
