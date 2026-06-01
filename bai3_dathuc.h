// Ð?nh nghia c?u trúc 1 Node trong danh sách liên k?t don da th?c
typedef struct Node {
    float heSo;
    int soMu;
    struct Node *next;
} Node;

// Các hàm x? lý da th?c theo yêu c?u d? bài
Node* TaoNode(float heSo, int soMu);
void ThemHangTu(Node **head, float heSo, int soMu); // Thêm và t? d?ng s?p x?p/c?ng d?n s? mu
void NhapDaThuc(Node **head);
void XuatDaThuc(Node *head);
float TinhGiaTri(Node *head, float x);
Node* DaoHam(Node *head);
Node* CongDaThuc(Node *P, Node *Q);
void GiaiPhongDaThuc(Node **head);

// Hàm di?u khi?n menu bài 3
int MenuDaThuc();
void MainDaThuc();
