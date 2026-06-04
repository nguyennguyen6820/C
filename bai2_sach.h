typedef struct {
    char TenSach[100];
    char TacGia[100];
    int NamXuatBan;
} Sach;

void NhapSach(int *n, Sach **A);
void XuatSach(int n, Sach A[]);
int DemSach(int n, Sach *a);
void ThongKe(int n, Sach *a);
int MenuSach();
void MainSach(); // Ham chiu trach nhiem chay vong lap menu cua rieng bai 2
