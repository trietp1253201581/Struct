/*Chương trình cấp phát bộ nhớ động để quản lý các phòng trong viện*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
typedef struct 
{
    char ht[25];/*Họ tên*/
    int ns;/*Năm sinh*/
}person;
typedef struct 
{
    char tenphong[30];
    int sonhanvien;
    person nhanvien[50];
}room;
typedef struct 
{
    char tenvien[30];
    int sophong;
    room phong[30];
}vvv;
vvv vien[20];
int sovien;
int main()
{
    int i,j,k,ngay,thang,nam,sophong,sonhanvien,ns;
    /*Vào số liệu và cấp phát bộ nhớ*/
    printf("\n So vien:"); scanf("%d%*c",&sovien);
    /*Vào số liệu từng viện*/
    for(i=1;i<=sovien;++i)
    {
        printf("\n Ten vien thu %d: ",i);
        gets(vien[i].tenvien);
        printf("\n So phong cua vien %s: ",vien[i].tenvien);
        scanf("%d%*c",&sophong); vien[i].sophong=sophong;
        /*Nhập dữ liệu cho từng phòng*/
        for(j=1;j<=sophong;++j)
        {
            printf("\n Ten phong %d cua vien %s: ",j,vien[i].tenvien);
            gets(vien[i].phong[j].tenphong);
            printf("\n So nhan vien cua phong %s vien %s: ",vien[i].phong[j].tenphong,vien[i].tenvien);
            scanf("%d%*c",&sonhanvien); vien[i].phong[j].sonhanvien=sonhanvien;
            /*Nhập dữ liệu cho từng nhân viên*/
            printf("\n Vien %s phong %s",vien[i].tenvien,vien[i].phong[j].tenphong);
            for(k=1;k<=sonhanvien;++k)
            {
                printf("\n Nhap ho ten nhan vien %d: ",k);
                gets(vien[i].phong[j].nhanvien[k].ht);
                printf("\n Nam sinh nhan vien %d: ",k);
                scanf("%d%*c",&ns); vien[i].phong[j].nhanvien[k].ns=ns;
            } 
        }
    }
    /*Đưa ra màn hình*/
    for(i=1;i<=sovien;++i)
    {
        printf("\n Vien %s co %d phong:",vien[i].tenvien,vien[i].sophong);
        for(j=1;j<=vien[i].sophong;++j)
        {
            printf("\n Phong %s co %d nhan vien:",vien[i].phong[j].tenphong,vien[i].phong[j].sonhanvien);
            for(k=1;k<=vien[i].phong[j].sonhanvien;++k)
            {
                printf("\n Nhan vien %s sinh nam %d",vien[i].phong[j].nhanvien[k].ht,vien[i].phong[j].nhanvien[k].ns);
            }
        }
    }
    getch();
}



