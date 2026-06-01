#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bai2_sach.h"

void NhapSach(int *n, Sach **A) {
    printf("Nhap so luong cuon sach n: ");
    scanf("%d", n);
    while (*n <= 0) {
        printf("So luong phai > 0. Nhap lai: ");
        scanf("%d", n);
    }

    // C?p phát d?ng cho m?ng c?u trúc Sach thông qua con tr? c?p 2
    *A = (Sach *)malloc((*n + 1) * sizeof(Sach));
    if (*A == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    
    int i;

    for (i = 0; i < *n; i++) {
        getchar(); // Xóa b? nh? d?m tránh trôi l?nh khi dùng fgets
        printf("\nNhap thong tin cuon sach thu %d:\n", i + 1);
        printf("+ Ten Sach: ");
        fgets((*A)[i].TenSach, sizeof((*A)[i].TenSach), stdin);
        (*A)[i].TenSach[strcspn((*A)[i].TenSach, "\n")] = 0; // Lo?i b? d?u xu?ng dòng

        printf("+ Tac Gia: ");
        fgets((*A)[i].TacGia, sizeof((*A)[i].TacGia), stdin);
        (*A)[i].TacGia[strcspn((*A)[i].TacGia, "\n")] = 0;

        printf("+ Nam Xuat Ban: ");
        scanf("%d", &(*A)[i].NamXuatBan);
    }
}

void XuatSach(int n, Sach A[]) {
	int i; 
    printf("\n================ DANH SACH SACH ================\n");
    printf("%-5s %-30s %-20s %-12s\n", "STT", "Ten Sach", "Tac Gia", "Nam XB");
    for (i = 0; i < n; i++) {
        printf("%-5d %-30s %-20s %-12d\n", i + 1, A[i].TenSach, A[i].TacGia, A[i].NamXuatBan);
    }
    printf("================================================\n");
}

int DemSach(int n, Sach *a) {
    char tg[100];
    getchar(); // Xóa b? nh? d?m
    printf("Nhap ten tac gia can dem: ");
    fgets(tg, sizeof(tg), stdin);
    tg[strcspn(tg, "\n")] = 0;

    int dem = 0, i;
    for (i = 0; i < n; i++) {
        // Hàm strcasecmp dùng d? so sánh chu?i không phân bi?t ch? hoa ch? thu?ng
        if (strcasecmp(a[i].TacGia, tg) == 0) { 
            dem++;
        }
    }
    return dem;
}

void ThongKe(int n, Sach *a) {
    // M?ng dánh d?u d? tránh th?ng kê trùng l?p m?t nam nhi?u l?n
    int *namDaXet = (int *)calloc(n, sizeof(int));
    int i, j;
    printf("\nThong ke so luong sach theo nam xuat ban:\n");
    
    for (i = 0; i < n; i++) {
        if (namDaXet[i] == 0) {
            int namHienTai = a[i].NamXuatBan;
            int dem = 1;
            namDaXet[i] = 1;
            
            for (j = i + 1; j < n; j++) {
                if (a[j].NamXuatBan == namHienTai) {
                    dem++;
                    namDaXet[j] = 1;
                }
            }
            printf("%d: %d cuon\n", namHienTai, dem);
        }
    }
    free(namDaXet);
}

int MenuSach() {
    int luaChon;
    printf("\n========= MENU BAI 2: QUAN LY SACH =========");
    printf("\n1. Nhap n cuon sach");
    printf("\n2. Xuat n cuon sach");
    printf("\n3. Dem theo tac gia");
    printf("\n4. Thong ke theo nam xuat ban");
    printf("\n5. Quay lai Menu chinh");
    printf("\n============================================");
    printf("\nNhap lua chon cua ban (1-5): ");
    scanf("%d", &luaChon);
    return luaChon;
}

void MainSach() {
    Sach *A = NULL;
    int n = 0;
    int luaChon;

    do {
        luaChon = MenuSach();
        switch (luaChon) {
            case 1:
                if (A != NULL) { free(A); A = NULL; }
                NhapSach(&n, &A);
                printf("\n=> Nhap thong tin sach thanh cong!\n");
                break;
            case 2:
                if (A == NULL || n == 0) printf("\n[!] Danh sach trong. Vui long nhap truoc!\n");
                else XuatSach(n, A);
                break;
            case 3:
                if (A == NULL || n == 0) printf("\n[!] Danh sach trong. Vui long nhap truoc!\n");
                else {
                    int sl = DemSach(n, A);
                    printf("=> Tac gia nay co: %d cuon sach.\\n", sl);
                }
                break;
            case 4:
                if (A == NULL || n == 0) printf("\n[!] Danh sach trong. Vui long nhap truoc!\n");
                else ThongKe(n, A);
                break;
            case 5:
                printf("\nQuay lai Menu chinh...\n");
                break;
            default:
                printf("\n[!] Lua chon khong hop le!\n");
                break;
        }
    } while (luaChon != 5);

    if (A != NULL) free(A);
}
