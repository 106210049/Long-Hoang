#include<iostream>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>

using namespace std;

class PERSON{
    protected:
    char *HoTen;
    char *Ngaysinh;
    char *Quequan;
    public:
    PERSON(const char *ten="Nguyen Huynh Nguyen Quang", const char *ns="14/03/2003", const char *que="Thanh pho Ho Chi Minh")
    {
        HoTen=new char[strlen(ten)+1];
        Ngaysinh=new char[strlen(ns)+1];
        Quequan=new char[strlen(que)+1];
        strcpy(HoTen,ten);
        strcpy(Ngaysinh,ns);
        strcpy(Quequan,que);
    }
};
class DIEM{
    protected:
    float toan,ly,hoa;
    public:
    DIEM()
    {
        toan=0;
        ly=0;
        hoa=0;
    }
};
class HOCSINH:public PERSON,public DIEM{
    private:
    char *lop;
    float tongdiem;
    static int siso;
    public:
    
    HOCSINH(const char *LOP="12/15"):PERSON(),DIEM()
    {
        lop=new char[strlen(LOP)+1];
        strcpy(lop,LOP);
        HOCSINH *hs;
        hs=new HOCSINH[20];
        Nhap(hs);
        tinhdiem(hs);
        xuat(hs);
    }
    void Nhap(HOCSINH *hs);
    void xuat(HOCSINH *hs);
    void tinhdiem(HOCSINH *hs);
    ~HOCSINH()
    {
        delete[]lop;
        delete[]HoTen;
        delete[]Quequan;
        delete[]Ngaysinh;
    }
   
};
int HOCSINH::siso=0;
void HOCSINH::Nhap(HOCSINH *hs)
{
    int temp=0;
    cout<<"******************** NHAP THONG TIN CUA HOC SINH ******************** "<<endl;
    do{
        ++siso;
        cout<<"Nhap ho ten: ";
        fflush(stdin);
        cin.getline(hs[siso].HoTen,30);
        cout<<"Nhap ngay sinh: ";
        fflush(stdin);
        cin.getline(hs[siso].Ngaysinh,30);
        cout<<"Nhap que quan: ";
        fflush(stdin);
        cin.getline(hs[siso].Quequan,30);
        cout<<"Nhap lop: ";
        fflush(stdin);
        cin.getline(hs[siso].lop,30);
        cout<<"Nhap diem toan: ";
        cin>>hs[siso].toan;
        cout<<"Nhap diem ly: ";
        cin>>hs[siso].ly;
        cout<<"Nhap diem hoa: ";
        cin>>hs[siso].hoa;
        cout<<"Nhap tiep phim 1 de tiep tuc nhap thong tin hoc sinh <<(Neu nhap phim khac se chuyen sang tinh diem tong va xuat ra)>>: ";
        cin>>temp;
    }while(temp==1);
    cout<<"************************************************************************ "<<endl;

}
void HOCSINH::xuat(HOCSINH *hs)
{
    cout<<"******************** THONG TIN CUA HOC SINH ******************** "<<endl;
    for(int i=1;i<=siso;i++)
    {
        cout<<"Ho va ten cua hoc sinh thu "<<i<<" : "<<hs[i].HoTen<<endl;
        cout<<"Ngay thang nam sinh cua hoc sinh thu "<<i<<" : "<<hs[i].Ngaysinh<<endl;
        cout<<"Que quan cua hoc sinh thu "<<i<<" : "<<hs[i].Quequan<<endl;
        cout<<"Lop: "<<hs[i].lop<<endl;
        cout<<"Diem toan: "<<hs[i].toan<<endl;
        cout<<"Diem ly: "<<hs[i].ly<<endl;
        cout<<"Diem hoa: "<<hs[i].hoa<<endl;
        cout<<"Diem tong la: "<<hs[i].tongdiem<<endl;
    }
    cout<<"**************************************************************** "<<endl;
    delete[]hs;
}
void HOCSINH::tinhdiem(HOCSINH *hs)
{
    for(int i=1;i<=siso;i++)
    {
        hs[i].tongdiem=hs[i].toan+hs[i].ly+hs[i].hoa;
    }
}
int main()
{
    system("cls");
    HOCSINH hs;
    getch();
}