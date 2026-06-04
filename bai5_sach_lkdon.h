#ifndef BAI5_SACH_LKDON_H
#define BAI5_SACH_LKDON_H

// 1. Khai bao cau truc Node Sach (danh sach moc noi don)
typedef struct NodeSach {
    char TenSach[100];
    int SoLuong;
    char LoaiSach; // Chi nhan gia tri 'A', 'B', 'C'
    int NamXuatBan;
    struct NodeSach *next;
} NodeSach;

// 2. Khai bao cac ham xu ly theo yeu cau de bai
NodeSach* TaoSach(char ten[], int sl, char loai, int nam);
void BoSungDauDS(NodeSach **head, NodeSach *moi);
void BoSungCuoiDS(NodeSach **head, NodeSach *moi);
void NhapDSMoNoi(NodeSach **head);
void InDSMoNoi(NodeSach *head);
void XoaSach2010(NodeSach **head);
void TongSoLuongTungLoai(NodeSach *head);
void SapXepSoLuongTang(NodeSach *head);
void GiaiPhongDS(NodeSach **head);

// 3. Ham dieu khien Menu cho bai nay
int MenuSachLKDon();
void MainSachLKDon();

#endif
