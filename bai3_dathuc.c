#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "bai3_dathuc.h"

// Hàm t?o m?i m?t Node h?ng t?
Node* TaoNode(float heSo, int soMu) {
    Node *moi = (Node*)malloc(sizeof(Node));
    if (moi == NULL) {
        printf("Loi cap phat bo nho!\n");
        exit(1);
    }
    moi->heSo = heSo;
    moi->soMu = soMu;
    moi->next = NULL;
    return moi;
}

// Hàm thêm h?ng t? và t? d?ng s?p x?p s? mu gi?m d?n / c?ng d?n n?u trùng s? mu
void ThemHangTu(Node **head, float heSo, int soMu) {
    if (heSo == 0) return;
    Node *moi = TaoNode(heSo, soMu);

    if (*head == NULL || (*head)->soMu < soMu) {
        moi->next = *head;
        *head = moi;
        return;
    }

    Node *curr = *head;
    while (curr->next != NULL && curr->next->soMu >= soMu) {
        curr = curr->next;
    }

    if (curr->soMu == soMu) {
        curr->heSo += heSo;
        free(moi);
    } else if (curr->next != NULL && curr->next->soMu == soMu) {
        curr->next->heSo += heSo;
        free(moi);
    } else {
        moi->next = curr->next;
        curr->next = moi;
    }
}

// Hàm nh?p da th?c
void NhapDaThuc(Node **head) {
    int n, sm, i;
    float hs;
    printf("Nhap so luong hang tu: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("  Hang tu %d (He so, So mu): ", i + 1);
        scanf("%f %d", &hs, &sm);
        ThemHangTu(head, hs, sm);
    }
}

// Hàm xu?t da th?c theo d?nh d?ng chu?n tr?c quan
void XuatDaThuc(Node *head) {
    if (head == NULL) {
        printf("0\n");
        return;
    }
    Node *curr = head;
    int isFirst = 1;
    while (curr != NULL) {
        if (curr->heSo > 0) {
            if (!isFirst) printf(" + ");
            printf("%.2fx^%d", curr->heSo, curr->soMu);
        } else if (curr->heSo < 0) {
            if (!isFirst) printf(" ");
            else printf("-");
            printf("%.2fx^%d", fabs(curr->heSo), curr->soMu);
        }
        isFirst = 0;
        curr = curr->next;
    }
    printf("\n");
}

// Tính giá tr? c?a da th?c t?i x
float TinhGiaTri(Node *head, float x) {
    float ketQua = 0;
    Node *curr = head;
    while (curr != NULL) {
        ketQua += curr->heSo * pow(x, curr->soMu);
        curr = curr->next;
    }
    return ketQua;
}

// Tính d?o hàm c?a da th?c t?i x (Tr? v? danh sách da th?c d?o hàm)
Node* DaoHam(Node *head) {
    Node *kq = NULL;
    Node *curr = head;
    while (curr != NULL) {
        if (curr->soMu > 0) {
            ThemHangTu(&kq, curr->heSo * curr->soMu, curr->soMu - 1);
        }
        curr = curr->next;
    }
    return kq;
}

// Tính t?ng hai da th?c
Node* CongDaThuc(Node *P, Node *Q) {
    Node *kq = NULL;
    Node *curr = P;
    while (curr != NULL) {
        ThemHangTu(&kq, curr->heSo, curr->soMu);
        curr = curr->next;
    }
    curr = Q;
    while (curr != NULL) {
        ThemHangTu(&kq, curr->heSo, curr->soMu);
        curr = curr->next;
    }
    return kq;
}

// Gi?i phóng b? nh?
void GiaiPhongDaThuc(Node **head) {
    Node *curr = *head;
    while (curr != NULL) {
        Node *temp = curr;
        curr = curr->next;
        free(temp);
    }
    *head = NULL;
}

// HÀM CH?Y CHÍNH C?A BÀI 3 (Ðu?c g?i t? main.c t?ng)
void MainDaThuc() {
    Node *P = NULL;
    Node *Q = NULL;
    Node *Tong = NULL;
    Node *DhP = NULL;
    float x;

    printf("\n--- 1. NHAP HAI DA THUC ---\n");
    printf("Nhap da thuc P(x):\n"); NhapDaThuc(&P);
    printf("Nhap da thuc Q(x):\n"); NhapDaThuc(&Q);

    printf("\n--- 2. HIEN THI DA THUC VUA NHAP ---\n");
    printf("P(x) = "); XuatDaThuc(P);
    printf("Q(x) = "); XuatDaThuc(Q);

    printf("\n--- 3. TINH GIA TRI VA DAO HAM ---\n");
    printf("Nhap gia tri x = ");
    scanf("%f", &x);
    printf("Gia tri P(%.2f) = %.2f\n", x, TinhGiaTri(P, x));
    
    DhP = DaoHam(P);
    printf("Dao ham P'(x) = "); XuatDaThuc(DhP);
    printf("Gia tri dao ham P'(%.2f) = %.2f\n", x, TinhGiaTri(DhP, x));

    printf("\n--- 4. TINH TONG HAI DA THUC P(x) + Q(x) ---\n");
    Tong = CongDaThuc(P, Q);
    printf("P(x) + Q(x) = "); XuatDaThuc(Tong);

    // D?n d?p b? nh? d?ng tru?c khi rút lui v? Menu chính
    GiaiPhongDaThuc(&P);
    GiaiPhongDaThuc(&Q);
    GiaiPhongDaThuc(&Tong);
    GiaiPhongDaThuc(&DhP);
    
    printf("\n=> Hoan thanh Bai 3. Bam phim bat ky de quay lai Menu tong...\n");
    getchar(); getchar(); // Ch? ngu?i dùng nh?n enter d? quay l?i s?nh chính
}
