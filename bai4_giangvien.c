#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bai4_giangvien.h"

// Ham xoa bo dem nhap lieu
static void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// 1. Ham tao 1 node Giang Vien moi
GiangVien* TaoGiangVien() {
    GiangVien *p = (GiangVien*)malloc(sizeof(GiangVien));
    if (p == NULL) {
        printf("Loi cap phat bo nho!\n");
        return NULL;
    }
    
    printf("Nhap ho ten: ");
    fgets(p->hoTen, 50, stdin);
    p->hoTen[strcspn(p->hoTen, "\n")] = '\0';
    
    printf("Nhap hoc vi (TS / ThS / CN): ");
    fgets(p->hocVi, 20, stdin);
    p->hocVi[strcspn(p->hocVi, "\n")] = '\0';
    
    printf("Nhap so tiet day: ");
    scanf("%d", &p->soTietDay);
    
    printf("Nhap don gia: ");
    scanf("%f", &p->donGia);
    clearBuffer(); // Xoa bo dem cho lan nhap sau
    
    p->next = NULL;
    return p;
}

// 2. Bo sung vao dau danh sach
void BoSungDau(GiangVien **head, GiangVien *p) {
    if (p == NULL) return;
    p->next = *head;
    *head = p;
}

// 3. Bo sung vao cuoi danh sach
void BoSungCuoi(GiangVien **head, GiangVien *p) {
    if (p == NULL) return;
    if (*head == NULL) {
        *head = p;
    } else {
        GiangVien *temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = p;
    }
}

// 4. Nhap danh sach n giang vien
void NhapDanhSach(GiangVien **head) {
    int n, i;
    printf("Nhap so luong giang vien n: ");
    scanf("%d", &n);
    clearBuffer();
    
    for (i = 0; i < n; i++) {
        printf("\n--- Nhap giang vien thu %d ---\n", i + 1);
        GiangVien *p = TaoGiangVien();
        
        // Ban co the chon BoSungDau hoac BoSungCuoi o day. 
        // Bo sung cuoi de danh sach dung thu tu nhap vao.
        BoSungCuoi(head, p);
    }
    printf("\n=> Nhap danh sach thanh cong!\n");
}

// 5. In danh sach giang vien ra man hinh
void InDanhSach(GiangVien *head) {
    if (head == NULL) {
        printf("\n[!] Danh sach rong!\n");
        return;
    }
    
    printf("\n%-25s %-10s %-12s %-12s\n", "Ho Ten", "Hoc Vi", "So Tiet", "Don Gia");
    printf("------------------------------------------------------------\n");
    
    GiangVien *temp = head;
    while (temp != NULL) {
        printf("%-25s %-10s %-12d %-12.2f\n", 
               temp->hoTen, temp->hocVi, temp->soTietDay, temp->donGia);
        temp = temp->next;
    }
}

// 6. Tim va in ra cac giang vien co hoc vi la "ThS"
void TimGiangVienThS(GiangVien *head) {
    int count = 0;
    GiangVien *temp = head;
    
    printf("\n=== DANH SACH GIANG VIEN THAC SI (ThS) ===\n");
    while (temp != NULL) {
        if (strcasecmp(temp->hocVi, "ThS") == 0) {
            if (count == 0) {
                printf("%-25s %-10s %-12s %-12s\n", "Ho Ten", "Hoc Vi", "So Tiet", "Don Gia");
                printf("------------------------------------------------------------\n");
            }
            printf("%-25s %-10s %-12d %-12.2f\n", 
                   temp->hoTen, temp->hocVi, temp->soTietDay, temp->donGia);
            count++;
        }
        temp = temp->next;
    }
    
    if (count == 0) {
        printf("[!] Khong co giang vien nao co hoc vi 'ThS'.\n");
    }
}

// 7. Tinh tien giang day = SoTietDay * DonGia * HeSo
void InTienGiangDay(GiangVien *head) {
    if (head == NULL) {
        printf("\n[!] Danh sach rong!\n");
        return;
    }
    
    printf("\n=== BANG TINH TIEN GIANG DAY ===\n");
    printf("%-25s %-10s %-10s %-15s\n", "Ho Ten", "Hoc Vi", "He So", "Thanh Tien");
    printf("------------------------------------------------------------\n");
    
    GiangVien *temp = head;
    while (temp != NULL) {
        float heSo = 0.5; // Mac dinh la CN (Cu nhan)
        if (strcasecmp(temp->hocVi, "TS") == 0) {
            heSo = 1.5;
        } else if (strcasecmp(temp->hocVi, "ThS") == 0) {
            heSo = 1.0;
        }
        
        float thanhTien = temp->soTietDay * temp->donGia * heSo;
        printf("%-25s %-10s %-10.1f %-15.2f\n", 
               temp->hoTen, temp->hocVi, heSo, thanhTien);
        
        temp = temp->next;
    }
}

// 8. Sap xep giang vien theo so tiet day giam dan (Thuat toan Doi cho truc tiep)
void SapXepSoTietGiamDan(GiangVien **head) {
    if (*head == NULL || (*head)->next == NULL) return; // Danh sach co 0 hoac 1 node thi khong can sap xep
    
    GiangVien *i, *j;
    // Dung phuong phap hoan doi du lieu (data swapping) cho don gian va an toan
    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->soTietDay < j->soTietDay) {
                // Hoan doi Ho Ten
                char tempTen[50];
                strcpy(tempTen, i->hoTen);
                strcpy(i->hoTen, j->hoTen);
                strcpy(j->hoTen, tempTen);
                
                // Hoan doi Hoc Vi
                char tempHocVi[20];
                strcpy(tempHocVi, i->hocVi);
                strcpy(i->hocVi, j->hocVi);
                strcpy(j->hocVi, tempHocVi);
                
                // Hoan doi So tiet day
                int tempTiet = i->soTietDay;
                i->soTietDay = j->soTietDay;
                j->soTietDay = tempTiet;
                
                // Hoan doi Don gia
                float tempGia = i->donGia;
                i->donGia = j->donGia;
                j->donGia = tempGia;
            }
        }
    }
    printf("\n=> Da sap xep danh sach theo so tiet giam dan!\n");
}

// Giai phong bo nho khi thoat
void GiaiPhongDanhSach(GiangVien **head) {
    GiangVien *current = *head;
    GiangVien *next = NULL;
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

// Module Menu dieu khien rieng cua bai 4
void MainGiangVien() {
    GiangVien *DSLKD = NULL;
    int luaChon;
    
    do {
        printf("\n========= MENU BAI 4: QUAN LY GIANG VIEN =========");
        printf("\n1. Nhap danh sach giang vien");
        printf("\n2. In danh sach giang vien");
        printf("\n3. Tim kiem giang vien hoc vi 'ThS'");
        printf("\n4. Tinh tien giang day");
        printf("\n5. Sap xep so tiet day giam dan");
        printf("\n6. Thoat ra Menu chinh");
        printf("\n==================================================");
        printf("\nNhap lua chon cua ban (1-6): ");
        scanf("%d", &luaChon);
        clearBuffer();
        
        switch (luaChon) {
            case 1:
                GiaiPhongDanhSach(&DSLKD); // Xoa sach danh sach cu neu co
                NhapDanhSach(&DSLKD);
                break;
            case 2:
                InDanhSach(DSLKD);
                break;
            case 3:
                TimGiangVienThS(DSLKD);
                break;
            case 4:
                InTienGiangDay(DSLKD);
                break;
            case 5:
                SapXepSoTietGiamDan(&DSLKD);
                InDanhSach(DSLKD); // In lai xem luon ket qua sau sap xep
                break;
            case 6:
                printf("\nQuay lai Menu chinh...\n");
                break;
            default:
                printf("\n[!] Lua chon khong hop le!\n");
                break;
        }
    } while (luaChon != 6);
    
    GiaiPhongDanhSach(&DSLKD); // Don sach bo nho truoc khi thoat han h m
}

