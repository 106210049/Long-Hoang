#include<iostream>
#include<string.h>
#include<windows.h>
#include<conio.h>
#include<stdio.h>

using namespace std;
class NSX{
    // public:
    private:
    string Ten_NSX;
    string address;
    public:
    friend class May;
    friend class Maytinh;
    friend class phone;
};
class May{
    protected:
    string color;
    float quantities;
    string brand;
    NSX nsx;
    float price;
    public:
    May()
    {
        brand="Viet Nam local";
        quantities=0;
        color="red";
        nsx.Ten_NSX="VietNam airlines ";
        price=0;
        nsx.address="336 Nguyen Luong Bang- Quan Hai Chau- Thanh pho Da Nang";
    }

};

class Maytinh:public May{
    private:
    
    int speed, RAM,HDD;
    static int soluong;
    public:
    // NSX nsx;
    Maytinh();
    friend istream &operator>>(istream &is, Maytinh &computer);
    friend ostream &operator<<(ostream &os, Maytinh &computer);
    
};
int Maytinh::soluong=0;
Maytinh::Maytinh():May()
{
    ++Maytinh::soluong;
    speed=0;
    RAM=0;
    HDD=0;
}
class phone:public May{
    private:
    int ram,rom;
    float resolution;
    static int soluong;
    public:
    phone();
    friend istream &operator>>(istream &is, phone &PHONE);
    friend void Tinhtien();
    friend ostream &operator<<(ostream &os, phone &PHONE);
};
int phone::soluong=0;
phone::phone():May()
{
    ++phone::soluong;
    ram=0;
    rom=0;
    resolution=0;
}

istream &operator>>(istream &is, Maytinh &computer)
{
    cout<<"Nhap nhan hang: ";
    fflush(stdin);
    getline(is,computer.brand);
    // cout<<"Nhap ten nha san xuat: ";
    // fflush(stdin);
    // getline(is,computer.nsx.Ten_NSX);
    cout<<"Nhap mau sac: ";
    fflush(stdin);
    getline(is,computer.color);
    cout<<"Nhap khoi luong: ";
    fflush(stdin);
    is>>computer.quantities;
    cout<<"Nhap toc do may: (GHz)";
    is>>computer.speed;
    cout<<"Nhap suc chua o nho: ";
    is>>computer.HDD;
    cout<<"Nhap o nho RAM: ";
    is>>computer.RAM;
    cout<<"Nhap menh gia: ";
    is>>computer.price;
}
ostream &operator<<(ostream &os, Maytinh &computer)
{
    cout<<"Nhan hang la: "<<computer.brand<<endl;
    cout<<"Mau sac: "<<computer.color<<endl;
    cout<<"Khoi luong: "<<computer.quantities<<endl;
    cout<<"Toc do may: "<<computer.speed<<" GHz "<<endl;
    cout<<" Suc chua o nho: "<<computer.HDD<<" GB "<<endl;
    cout<<"Vung nho RAM: "<<computer.RAM<<" GB "<<endl;
    cout<<"Gia ca la: "<<computer.price<<" $ "<<endl;
}
istream &operator>>(istream &is,phone &PHONE)
{
    cout<<"Nhap hang san xuat: ";
    fflush(stdin);
    getline(is,PHONE.brand);
    cout<<"Nhap mau sac: ";
    fflush(stdin);
    getline(is,PHONE.color);
    cout<<"Nhap khoi luong: ";
    is>>PHONE.quantities;
    cout<<"Nhap RAM: ";
    is>>PHONE.ram;
    cout<<"Nhap ROM: ";
    is>>PHONE.rom;
    cout<<"Nhap do phan giai: ";
    is>>PHONE.resolution;
    cout<<"Nhap gia: ";
    is>>PHONE.price;
}
ostream &operator<<(ostream &os, phone &PHONE)
{
    os<<"Nhan hang: "<<PHONE.brand<<endl;
    os<<"Mau sac: "<<PHONE.color<<endl;
    os<<"Do phan giai: "<<PHONE.resolution<<endl;
    os<<"Khoi luong: "<<PHONE.quantities<<endl;
    os<<"Vung nho RAM: "<<PHONE.ram<<endl;
    os<<"ROM: "<<PHONE.rom<<endl;
    os<<"Don gia: "<<PHONE.price<<endl;
}
int main()
{
    
}