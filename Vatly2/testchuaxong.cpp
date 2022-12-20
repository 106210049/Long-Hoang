#include<iostream>
#include<string.h>
#include<windows.h>
using namespace std;

class Khoi{
    protected:
    int khoi;
    static int solop;
    public:
    virtual void SetKhoi()
    {
        cin>>khoi;
    }
    class LopHoc{
        protected:
        int lop;
        static int siso;
        public:
        class Hocsinh{
            protected:
            string name, birthday,id;
            float Toan,Van,DTB;
            public:
            void nhap();
            void xuat();
            void TinhTB();
        };
    };
};
int Khoi::solop=0;
int Khoi::LopHoc::siso=0;

void Khoi::LopHoc::Hocsinh::nhap()
{
    cout<<"Nhap Khoi: ";
    
    cout<<"Nhap lop: ";
    
    cout<<"Nhap Ho va ten: ";
    fflush(stdin);
    getline(cin,name);
    cout<<"Nhap ngay thang nam sinh: ";
    fflush(stdin);
    getline(cin,birthday);
    cout<<"Nhap ma so hoc sinh: ";
    fflush(stdin);
    getline(cin,id);
    cout<<"Nhap diem toan: ";
    cin>>Toan;
    cout<<" Nhap diem van: ";
    cin>>Van;
}
void Khoi::LopHoc::Hocsinh::xuat()
{
    cout<<"Ho ten cua hoc sinh: "<<name;
    cout<<"Ngay thang nam sinh cua hoc sinh: "<<birthday<<endl;
    cout<<"Ma so hoc sinh: "<<id<<endl;
    cout<<"Diem toan: "<<Toan<<endl;
    cout<<"Diem van: "<<Van<<endl;
    cout<<"Diem trung binh: "<<DTB<<endl;
}
void Khoi::LopHoc::Hocsinh::TinhTB()
{
    DTB=(Toan+Van)/2;
}
typedef Khoi::LopHoc::Hocsinh Hocsinh;
int main()
{
    Hocsinh hs;
    hs.nhap();
    hs.TinhTB();
    hs.xuat();
}