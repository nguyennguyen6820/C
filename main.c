#include <stdio.h>
#include <stdlib.h>
#include "bai1_dayso.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int MenuChinh() {
    int luaChon;
    printf("\n=============================================");
    printf("\n   HE THONG BAI TAP LAP TRINH NGUON NGU C    ");
    printf("\n=============================================");
    printf("\n1. Chay Bai 1: Cac ham xu ly Day So (Cap phat dong)");
    printf("\n2. Chay Bai 2: Quan ly cau truc Sach (Cap phat dong)");
    printf("\n3. Chay Bai 3: Da thuc (Danh sach lien ket don) - [Cho tiep tuc]");
    printf("\n4. Chay Bai 4: Giang vien (Danh sach lien ket don) - [Cho tiep tuc]");
    printf("\n5. Thoat chuong trinh");
    printf("\n=============================================");
    printf("\nNhap lua chon bai tap (1-5): ");
    scanf("%d", &luaChon);
    return luaChon;
}

int main(int argc, char *argv[]) {
	
	int luaChon;
    do {
        luaChon = MenuChinh();
        switch (luaChon) {
            case 1:
                MainDaySo(); // Chuy?n quy?n di?u khi?n sang mô-dun dãy s?
                break;
            case 2:
                MainSach();  // Chuy?n quy?n di?u khi?n sang mô-dun qu?n lý sách
                break;
            case 3:
                MainDaThuc();
                break;
//            case 4:
//                printf("\\n[!] Chuc nang dang cho tich hop logic Bai 4!\\n");
//                break;
//            case 5:
//                printf("\\nThoat chuong trinh tong. Tam biet!\\n");
//                break;
//            default:
//                printf("\\n[!] Lua chon khong hop le. Vui long chon lai!\\n");
//                break;
        }
    } while (luaChon != 5);
    return 0;
}
