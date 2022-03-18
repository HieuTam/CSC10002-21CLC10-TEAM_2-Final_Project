#include <iostream>
#include <fstream>
#include <windows.h>
#include <string.h>
#include <string>
#include <cstring>
#define MAX 100
using namespace std;
//Khai bao struct date
struct HoTen
{
    int MS;
    char Name[MAX];
};
struct date
{
    int ngay, thang, nam;
};
struct DanhSach
{
    date ngaynhiem; //Ngay ghi nhan
    int num; //So ca nhiem
    HoTen arr[MAX];
};
//Prototype
void NhapDanhSach(DanhSach* ds, int& n);
void XuatDanhSach(DanhSach* ds, int n);
void SapXepCaNhiem(DanhSach* ds, int n);
void GhiVaoFile(DanhSach* ds, int n);
void DocTuFile(DanhSach* ds, int &n);
void Menu();
int ChonMenu();
void GiaiPhongBoNho(DanhSach* ds);

//Cho phep nguoi dung tiep tuc thuc hien chuong trinh neu muon
char choice[10] = "\0";
char co[10] = "co";
char khong[10] = "khong";
void Continue(DanhSach* ds);
void ThucHienChuongTrinh(DanhSach* ds, int& n);
//Ham main
int main()
{
    DanhSach* ds;
    int n = 0;
    ds = (DanhSach*)malloc(MAX * sizeof(DanhSach));
    while (1 == 1)
    {
        ThucHienChuongTrinh(ds, n);
        Continue(ds);
    }
    free(ds);
    return 0;
}

void ThucHienChuongTrinh(DanhSach* ds, int& n)
{
    system("cls");
    Menu();
    int x = ChonMenu();
    switch (x)
    {
    case 1:
        cout << "1.Tao mang dong va nhap danh sach vao mang.\n";
        NhapDanhSach(ds, n);
        break;
    case 2:
        cout << "2. Sap xep danh sach theo thu tu so ca F0 (giam dan).\n";
        SapXepCaNhiem(ds, n);
        XuatDanhSach(ds, n);
        break;
    case 3:
        cout << "3. Them mot phan tu vao danh sach\n";
        NhapDanhSach(ds, n);
        break;
    case 4:
        cout << "4. Xuat danh sach\n";
        XuatDanhSach(ds, n);
        break;
    case 5:
        cout << "5. Luu danh sach vao file:\n";
        GhiVaoFile(ds, n);
        break;
    case 6:
        cout << "6. Nap danh sach tu file:\n";
        DocTuFile(ds, n);
        break;
    case 7:
        GiaiPhongBoNho(ds);
        break;
    default:
        system("pause");
    }
}

void NhapDanhSach(DanhSach* ds, int& n)
{
    cout << "Nhap ngay ghi nhan(cach nhau boi dau cach): ";
    cin >> (ds + n)->ngaynhiem.ngay >> (ds + n)->ngaynhiem.thang >> (ds + n)->ngaynhiem.nam;
    cout << "So ca nhiem: ";
    cin >> (ds + n)->num;
    cout << "Danh sach ca nhiem: \n";
    for (int i = 0; i < (ds + n)->num; i++)
    {
        cout << "Ma so: ";
        cin >> (ds + n)->arr[i].MS;
        cout << "Ho va ten: ";
        getchar();
        cin.getline((ds + n)->arr[i].Name, MAX);
    }
    n++;
}

void XuatDanhSach(DanhSach* ds, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Ngay ghi nhan: " << (ds + i)->ngaynhiem.ngay << "/" << (ds + i)->ngaynhiem.thang << "/" << (ds + i)->ngaynhiem.nam << endl;
        cout << "So ca nhiem: " << (ds + i)->num << endl;
        cout << "Danh sach nguoi nhiem: " << endl;
        for (int j = 0; j < (ds + i)->num; j++)
        {
            cout << (ds + i)->arr[j].MS << " - " << (ds + i)->arr[j].Name << endl;
        }
    }
    system("pause");
}


void HoanVi(DanhSach& a, DanhSach& b)
{
    DanhSach temp = a;
    a = b;
    b = temp;
}

void SapXepCaNhiem(DanhSach* ds, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((ds + i)->num < (ds + j)->num)
            {
                HoanVi(*(ds + i), *(ds + j));
            }
        }
    }
}

void GhiVaoFile(DanhSach* ds, int n)
{
    ofstream fileOut;
    fileOut.open("OUTPUT.txt", ios_base::out);
    for (int i = 0; i < n; i++)
    {
        fileOut << "Ngay ghi nhan: " << (ds + i)->ngaynhiem.ngay << "/" << (ds + i)->ngaynhiem.thang << "/" << (ds + i)->ngaynhiem.nam << endl;
        fileOut << "So ca nhiem: " << (ds + i)->num << endl;
        fileOut << "Danh sach nguoi nhiem: " << endl;
        for (int j = 0; j < (ds + i)->num; j++)
        {
            fileOut << (ds + i)->arr[j].MS << " - " << (ds + i)->arr[j].Name << endl;
        }
    }
    fileOut.close();
}

void DocTuFile(DanhSach* ds, int &n)
{
    ifstream fileIn;
    string temp;
    fileIn.open("INPUT.txt", ios_base::in);
    while (!fileIn.eof())
    {
        fileIn >> (ds + n)->ngaynhiem.ngay >> (ds + n)->ngaynhiem.thang >> (ds + n)->ngaynhiem.nam;
        fileIn >> (ds + n)->num;
        for (int i = 0; i < (ds + n)->num; i++)
        {
            fileIn >> (ds + n)->arr[i].MS;
            fileIn.getline((ds + n)->arr[i].Name, MAX, ',');
        }
        n++;
    }
    fileIn.close();
}

void Continue(DanhSach* ds)
{
    getchar();
    cout << "\nBan co muon tiep tuc chuong trinh khong? (co/khong): ";
    cin >> choice;
    while (strcmp(choice, co) != 0 && strcmp(choice, khong) != 0)
    {
        getchar();
        cout << "\nBan nhap sai! Ban co muon nhap lai khong (co/khong): ";
        cin >> choice;
    }
    if (strcmp(choice, khong) == 0)
    {
        GiaiPhongBoNho(ds);
    }
}

//Noi dung Menu chon
void Menu()
{
    cout << "=============MENU============\n" << endl;
    cout << "1. Tao mang dong va nhap danh sach vao mang" << endl;
    cout << "2. Sap xep danh sach theo thu tu so ca F0 (giam dan)" << endl;
    cout << "3. Them mot phan tu vao danh sach" << endl;
    cout << "4. Xuat danh sach" << endl;
    cout << "5. Luu danh sach vao file" << endl;
    cout << "6. Nap danh sach tu file " << endl;
    cout << "7. Giai phong bo nho va ket thuc chuong trinh\n" << endl;
    cout << "=============================" << endl;
}


//Cho phep nguoi dung chon Menu
int ChonMenu()
{
    int i;
    cout << "\nMoi ban chon: ";
    cin >> i;
    if (i < 1 || i > 7)
        cout << "\nBan da nhap sai. Xin moi ban nhap lai!\n";
    return i;
}

void GiaiPhongBoNho(DanhSach* ds)
{
    cout << "\nChuong trinh se giai phong bo nho va ket thuc!\n";
    free(ds);
    cout << "..." << endl;
    Sleep(1000);
    cout << "Giai phong bo nho thanh cong!\n";
    exit(0);
}