#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bai5_sach_lkdon.h"

// Ham tao mot node sach moi
NodeSach* TaoSach(char ten[], int sl, char loai, int nam) {
    NodeSach *moi = (NodeSach*)malloc(sizeof(NodeSach));
    if (moi == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    strcpy(moi->TenSach, ten);
    moi->SoLuong = sl;
    moi->LoaiSach = loai;
    moi->NamXuatBan = nam;
    moi->next = NULL;
    return moi;
}

// Bo sung vao dau danh sach
void BoSungDauDS(NodeSach **head, NodeSach *moi) {
    if (moi == NULL) return;
    moi->next = *head;
    *head = moi;
}

// Bo sung vao cuoi danh sach
void BoSungCuoiDS(NodeSach **head, NodeSach *moi) {
    if (moi == NULL) return;
    if (*head == NULL) {
        *head = moi;
        return;
    }
    NodeSach *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = moi;
}

// Nhap danh sach moc noi n cuon sach tu ban phim
void NhapDSMoNoi(NodeSach **head) {
    int n, i, sl, nam;
    char ten[100], loai;

    printf("Nhap so luong cuon sach n: ");
    scanf("%d", &n);
    while (n <= 0) {
        printf("So luong phai > 0. Nhap lai: ");
        scanf("%d", &n);
    }

    for (i = 0; i < n; i++) {
        getchar(); // Xoa bo nho dem
        printf("\nNhap thong tin cuon sach thu %d:\n", i + 1);
        printf("+ Ten Sach: ");
        fgets(ten, sizeof(ten), stdin);
        ten[strcspn(ten, "\n")] = 0; // Loai bo dau xuong dong

        printf("+ So Luong: ");
        scanf("%d", &sl);

        // Kiem tra rang buoc chi nhan loai A, B, C
        do {
            getchar();
            printf("+ Loai Sach (Chi nhap A, B hoac C): ");
            scanf("%c", &loai);
            if (loai != 'A' && loai != 'B' && loai != 'C' && loai != 'a' && loai != 'b' && loai != 'c') {
                printf("[!] Loai sach khong hop le. Vui long nhap lai!\n");
            }
        } while (loai != 'A' && loai != 'B' && loai != 'C' && loai != 'a' && loai != 'b' && loai != 'c');
        
        // Chuan hoa thanh chu hoa
        if (loai >= 'a' && loai <= 'c') loai -= 32;

        printf("+ Nam Xuat Ban: ");
        scanf("%d", &nam);

        NodeSach *moi = TaoSach(ten, sl, loai, nam);
        
        // Ban co the chon BoSungDau hoac BoSungCuoi. O day dung BoSungCuoi de dung thu tu nhap
        BoSungCuoiDS(head, moi);
    }
}

// In danh moc noi cac sach ra man hinh
void InDSMoNoi(NodeSach *head) {
    if (head == NULL) {
        printf("\n[!] Danh sach trong!\n");
        return;
    }
    printf("\n======================== DANH SACH SACH MOC NOI ========================\n");
    printf("%-5s %-30s %-12s %-10s %-12s\n", "STT", "Ten Sach", "So Luong", "Loai", "Nam XB");
    NodeSach *curr = head;
    int stt = 1;
    while (curr != NULL) {
        printf("%-5d %-30s %-12d %-10c %-12d\n", stt++, curr->TenSach, curr->SoLuong, curr->LoaiSach, curr->NamXuatBan);
        curr = curr->next;
    }
    printf("========================================================================\n");
}

// Xoa tat ca nhung cuon sach xuat ban nam 2010
void XoaSach2010(NodeSach **head) {
    if (*head == NULL) return;

    NodeSach *curr = *head;
    NodeSach *prev = NULL;
    int dem = 0;

    while (curr != NULL) {
        if (curr->NamXuatBan == 2010) {
            NodeSach *temp = curr;
            if (prev == NULL) {
                // Xoa nut o dau danh sach
                *head = curr->next;
                curr = *head;
            } else {
                // Xoa nut o giua hoac cuoi danh sach
                prev->next = curr->next;
                curr = curr->next;
            }
            free(temp);
            dem++;
        } else {
            prev = curr;
            curr = curr->next;
        }
    }
    if (dem > 0) printf("\n=> Da xoa %d cuon sach xuat ban nam 2010.\n", dem);
    else printf("\n=> Khong tim thay cuon sach nao xuat ban nam 2010.\n");
}

// Tinh tong so cuon sach tung loai sach A, B, C va in luon trong ham
void TongSoLuongTungLoai(NodeSach *head) {
    int tongA = 0, tongB = 0, tongC = 0;
    NodeSach *curr = head;
    
    while (curr != NULL) {
        if (curr->LoaiSach == 'A') tongA += curr->SoLuong;
        else if (curr->LoaiSach == 'B') tongB += curr->SoLuong;
        else if (curr->LoaiSach == 'C') tongC += curr->SoLuong;
        curr = curr->next;
    }

    printf("\n========== TONG SO LUONG SACH TUNG LOAI ==========\n");
    printf("+ Loai A: %d cuon\n", tongA);
    printf("+ Loai B: %d cuon\n", tongB);
    printf("+ Loai C: %d cuon\n", tongC);
    printf("==================================================\n");
}

// Sap xep sach theo so luong tang dan (Su dung InterChange Sort cau truc du lieu)
void SapXepSoLuongTang(NodeSach *head) {
    if (head == NULL || head->next == NULL) return;

    NodeSach *i, *j;
    // Bien tam de hoan vi du lieu trong node
    char tempTen[100];
    int tempSL, tempNam;
    char tempLoai;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->SoLuong > j->SoLuong) {
                // Hoán doi thong tin giua node i và node j
                strcpy(tempTen, i->TenSach);
                strcpy(i->TenSach, j->TenSach);
                strcpy(j->TenSach, tempTen);

                tempSL = i->SoLuong; i->SoLuong = j->SoLuong; j->SoLuong = tempSL;
                tempLoai = i->LoaiSach; i->LoaiSach = j->LoaiSach; j->LoaiSach = tempLoai;
                tempNam = i->NamXuatBan; i->NamXuatBan = j->NamXuatBan; j->NamXuatBan = tempNam;
            }
        }
    }
    printf("\n=> Da sap xep danh sach sach theo so luong tang dan!\n");
}

// Giai phong bo nho dong cua danh sach lien ket
void GiaiPhongDS(NodeSach **head) {
    NodeSach *curr = *head;
    while (curr != NULL) {
        NodeSach *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *head = NULL;
}

// Menu con cua bai toan moc noi don
int MenuSachLKDon() {
    int luaChon;
    printf("\n========= MENU BAI 5: SACH MOC NOI DON =========");
    printf("\n1. Nhap danh sach n cuon sach");
    printf("\n2. In danh sach sach");
    printf("\n3. Xoa tat ca sach xuat ban nam 2010");
    printf("\n4. Tinh tong so luong tung loai A, B, C");
    printf("\n5. Sap xep sach theo so luong tang dan");
    printf("\n6. Quay lai Menu chinh");
    printf("\n================================================");
    printf("\nNhap lua chon cua ban (1-6): ");
    scanf("%d", &luaChon);
    return luaChon;
}

// Hàm Main cua module dieu khien chinh
void MainSachLKDon() {
    NodeSach *head = NULL;
    int luaChon;

    do {
        luaChon = MenuSachLKDon();
        switch (luaChon) {
            case 1:
                GiaiPhongDS(&head); // Xoa danh sach cu neu co truoc khi nhap moi
                NhapDSMoNoi(&head);
                printf("\n=> Nhap du lieu thanh cong!\n");
                break;
            case 2:
                InDSMoNoi(head);
                break;
            case 3:
                if (head == NULL) printf("\n[!] Danh sach trong. Vui long nhap truoc!\n");
                else XoaSach2010(&head);
                break;
            case 4:
                if (head == NULL) printf("\n[!] Danh sach trong. Vui long nhap truoc!\n");
                else TongSoLuongTungLoai(head);
                break;
            case 5:
                if (head == NULL) printf("\n[!] Danh sach trong. Vui long nhap truoc!\n");
                else {
                    SapXepSoLuongTang(head);
                    InDSMoNoi(head); // In lai ra de nguoi dung doi chieu
                }
                break;
            case 6:
                printf("\nQuay lai Menu chinh...\n");
                break;
            default:
                printf("\n[!] Lua chon khong hop le!\n");
                break;
        }
    } while (luaChon != 6);

    GiaiPhongDS(&head); // Giai phong bo nho truoc khi thoat hoan toan module
}
