#ifndef BAI4_GIANGVIEN_H
#define BAI4_GIANGVIEN_H

// Khai bao cau truc Giang Vien
typedef struct GiangVien {
    char hoTen[50];
    char hocVi[20]; // TS, ThS, CN
    int soTietDay;
    float donGia;
    struct GiangVien *next; // Con tro tro den giang vien tiep theo
} GiangVien;

// Khai bao cac ham xu ly
GiangVien* TaoGiangVien();
void BoSungDau(GiangVien **head, GiangVien *p);
void BoSungCuoi(GiangVien **head, GiangVien *p);
void NhapDanhSach(GiangVien **head);
void InDanhSach(GiangVien *head);
void TimGiangVienThS(GiangVien *head);
void InTienGiangDay(GiangVien *head);
void SapXepSoTietGiamDan(GiangVien **head);
void GiaiPhongDanhSach(GiangVien **head);
void MainGiangVien();

#endif

