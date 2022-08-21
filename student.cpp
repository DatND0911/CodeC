#include <iostream>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <fstream>
#include <stdlib.h>

using namespace std;
 
typedef struct SinhVien{
    char ten[30];
    char gt[5];
    int age;
    float dT, dL, dH;
    float dtb = 0.0;
} SV;
  
void nhap(SV &sv);
void nhapN(SV a[], int n);
void xuat(SV sv);
void xuatN(SV a[], int n);
void tinhDTB(SV &sv);
void sapxep(SV a[], int n);
void xeploai(SV a);
void xeploaiN(SV a[], int n);
void xuatFile(SV a[], int n, char fileName[]);
 
int main(){
    int key;
    char fileName[] = "DSSV.txt";
    int n;
    bool daNhap = false;
    do {
        cout << "Nhap so luong SV: ";
        cin >> n;
    } while(n <= 0);
    SV a[n];
    while(true){
        printf("******************************************\n");
        printf("**    CHUONG TRINH QUAN LY SINH VIEN    **\n");
        printf("**      1. Nhap du lieu                 **\n");
        printf("**      2. In danh sach sinh vien       **\n");
        printf("**      3. Sap xep sinh vien theo DTB   **\n");
        printf("**      4. Xep loai sinh vien           **\n");
        printf("**      5. Xuat DS sinh vien            **\n");
        printf("**      0. Thoat                        **\n");
        printf("******************************************\n");
        
        printf("Nhap lua chon cua ban tu 0 - 5: ");
        cin >> key;
        switch(key){
            case 1:
                printf("\nBan da chon nhap DS sinh vien!");
                nhapN(a, n);
                printf("\nBan da nhap thanh cong!");
                daNhap = true;
                break;
            case 2:
                if(daNhap){
                    printf("\nBan da chon xuat DS sinh vien!");
                    xuatN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                break;
            case 3:
                if(daNhap){
                    printf("\nBan da chon sap xep SV theo STB!");
                    sapxep(a, n);
                    xuatN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                break;
            case 4:
                if(daNhap){
                    printf("\nBan da chon xep loai SV!");
                    xeploaiN(a, n);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                break;
            case 5:
                if(daNhap){
                    printf("\nBan da chon xuat DS SV!");
                    xuatFile(a, n, fileName);
                }else{
                    printf("\nNhap DS SV truoc!!!!");
                }
                printf("\nXuat DSSV thanh cong vao file %s!", fileName);
                break;
            case 0:
                printf("\nBan da chon thoat chuong trinh!");
                return 0;
            default:
                printf("\nKhong co chuc nang nay!");
                printf("\nBam phim bat ky de tiep tuc!\n");
                break;
        }
    }
}
 
void tinhDTB(SV &sv){
    sv.dtb = (sv.dH + sv.dL + sv.dT)/3;    
}
 
void nhap(SV &sv){
    cout << "Nhap ten: ";
    cin.ignore(); 
    cin.getline(sv.ten, 50);
    cout << "Nhap gioi tinh: ";
    cin.getline(sv.gt, 30);
    fflush(stdin);
    cout << "Nhap tuoi: ";
    cin >> sv.age;
    cout << "Nhap diem 3 mon: "; 
    cin >> sv.dT >> sv.dL >> sv.dH;
    tinhDTB(sv);
}
 
void nhapN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i< n; ++i){
        printf("\nNhap SV thu %d:\n", i+1);
        nhap(a[i]);
    }
    printf("\n____________________________________\n");
}
 
void xuat(SV sv){
    cout << "Ho ten SV: " << sv.ten << "\n";
    cout << "Gioi tinh: " << sv.gt << "\n";
    cout << "Tuoi SV: " << sv.age << "\n";
    printf("Diem Toan - Ly - Hoa: %.2f - %.2f - %.2f", sv.dT, sv.dL, sv.dH);
    cout << "\n";
    printf("Diem TB: %.2f", sv.dtb);
    cout << "\n";
}
 
void xuatN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0; i < n; ++i){
        printf("\nThong tin SV thu %d:\n", i+1);
        xuat(a[i]);
    }
    printf("\n____________________________________\n");
}
 
void sapxep(SV a[], int n){
    //Sap xep theo DTB tang dan
    SV tmp;
    for(int i = 0;i < n;++i){
        for(int j = i+1; j < n;++j){
            if(a[i].dtb > a[j].dtb){
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}
 
void xeploai(SV sv){
    if(sv.dtb >= 8) printf("Gioi");
    else if(sv.dtb >= 6.5) printf("Kha");
    else if(sv.dtb >= 4) printf("Trung binh");
    else printf("Yeu");
}
 
void xeploaiN(SV a[], int n){
    printf("\n____________________________________\n");
    for(int i = 0;i < n;++i){
        printf("\nXep loai cua SV thu %d la: ", i+1);
        xeploai(a[i]);
    }
    printf("\n____________________________________\n");
}
 
void xuatFile(SV a[], int n, char fileName[]) {
    std::ofstream outFile;
    outFile.open(fileName);

    if (ofs.is_open()) {
            outFile << std::left << std::setw(10) << "Ho Ten" << std::setw(15) << "Gioi tinh"
            << std::setw(10) << "Tuoi" << std::setw(10) << "DT" << std::setw(10) << "DL" 
            << std::setw(10) << "DH" << std::setw(10) << "DTB" << std::endl;
            for (int i = 0; i < n; i++) {
                outFile << std::left << std::setw(10) << a[i].ten << std::setw(15) << a[i].gt
                << std::setw(10) << a[i].age << std::setw(10) << a[i].dT << std::setw(10) << a[i].dL 
                << std::setw(10) << a[i].dH << std::setw(10) << a[i].dtb << std::endl;
            }
        }
    outFile.close();
}