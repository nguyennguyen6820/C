#include <stdio.h>
#include <stdlib.h>
#include "bai1_dayso.h"
#include "bai2_sach.h"
#include "bai4_giangvien.h"
#include "bai5_sach_lkdon.h"

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int MenuChinh() {
    int luaChon;
    printf("\n=============================================");
    printf("\n   HE THONG BAI TAP LAP TRINH NGUON NGU C    ");
    printf("\n=============================================");
    printf("\n1. Chay Bai 1: Cac ham xu ly Day So (Cap phat dong)");
    printf("\n2. Chay Bai 2: Quan ly cau truc Sach (Cap phat dong)");
    printf("\n4. Chay Bai 4: Giang vien (Danh sach lien ket don) - [Cho tiep tuc]");
    printf("\n5. Chay Bai 5: Quan ly Sach (Danh sach lien ket don)");
    printf("\n6. Thoat chuong trinh");
    printf("\n=============================================");
    printf("\nNhap lua chon bai tap (1-6): ");
    scanf("%d", &luaChon);
    return luaChon;
}

int main(int argc, char *argv[]) {
	
	int luaChon;
    do {
        luaChon = MenuChinh();
        switch (luaChon) {
            case 1:
                MainDaySo();
                break;
            case 2:
                MainSach();
                break;
	        case 4:
                MainGiangVien();
                break;
            case 5:
                MainSachLKDon();
                break;
            case 6:
                printf("\nThoat chuong trinh tong. Tam biet!\n");
                break;
            default:
                printf("\n[!] Lua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (luaChon != 6);
    return 0;
}

