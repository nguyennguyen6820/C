#include <stdio.h>
#include <stdlib.h>
#include "bai1_dayso.h"

int NhapDaySo(float **a) {
    int n,i;
    printf("Nhap so luong phan tu n: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("So phan tu phai > 0. Nhap lai: ");
        scanf("%d", &n);
    }
    *a = (float *)malloc((n + 1) * sizeof(float));
    if (*a == NULL) {
        printf("Loi cap phat bo nho!\\n");
        exit(1);
    }
    for (i = 0; i < n; i++) {
        printf("Nhap a[%d]: ", i);
        scanf("%f", (*a) + i);
    }
    return n;
}

int MaxDuong(int n, float *a, float *max) {
    int flag = 0, i;
    for (i = 0; i < n; i++) {
        if (a[i] > 0) {
            if (flag == 0) {
                *max = a[i];
                flag = 1;
            } else {
                if (a[i] > *max) {
                    *max = a[i];
                }
            }
        }
    }
    return flag;
}

int Fibo(int n, float *a) {
	int i;
    if (n < 3) return 1;
    for (i = 2; i < n; i++) {
        if (a[i] != (a[i - 1] + a[i - 2])) {
            return 0;
        }
    }
    return 1;
}

void XuatDaySo(int n, float *a) {
	int i;
    printf("\nDay so dang co trong bo nho dong: ");
    for (i = 0; i < n; i++) {
        printf("%.2f  ", a[i]);
    }
    printf("\n");
}

int MenuDaySo() {
    int luaChon;
    printf("\n========= MENU BAI 1: QUAN LY DAY SO =========");
    printf("\n1. Nhap day");
    printf("\n2. Xuat day");
    printf("\n3. Tim max duong");
    printf("\n4. Kiem tra tinh Fibonacci");
    printf("\n5. Quay lai Menu chinh");
    printf("\n=============================================");
    printf("\nNhap lua chon cua ban (1-5): ");
    scanf("%d", &luaChon);
    return luaChon;
}

void MainDaySo() {
    float *a = NULL;
    int n = 0;
    float max_duong;
    int luaChon;

    do {
        luaChon = MenuDaySo();
        switch (luaChon) {
            case 1:
                if (a != NULL) { free(a); a = NULL; }
                n = NhapDaySo(&a);
                printf("\n=> Nhap du lieu thanh cong!\n");
                break;
            case 2:
                if (a == NULL || n == 0) printf("\n[!] Mang rong. Vui long nhap truoc!\n");
                else XuatDaySo(n, a);
                break;
            case 3:
                if (a == NULL || n == 0) printf("\n[!] Mang rong. Vui long nhap truoc!\n");
                else {
                    if (MaxDuong(n, a, &max_duong) == 1) printf("\\n=> Max duong: %.2f\n", max_duong);
                    else printf("\n=> Mang khong co so duong.\\n");
                }
                break;
            case 4:
                if (a == NULL || n == 0) printf("\n[!] Mang rong. Vui long nhap truoc!\n");
                else {
                    if (Fibo(n, a) == 1) printf("\n=> Day CO tinh chat Fibonacci.\n");
                    else printf("\n=> Day KHONG CO tinh chat Fibonacci.\n");
                }
                break;
            case 5:
                printf("\nQuay lai Menu chinh...\n");
                break;
            default:
                printf("\n[!] Lua chon khong hop le!\n");
                break;
        }
    } while (luaChon != 5);

    if (a != NULL) free(a);
}
