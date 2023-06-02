/*Xét cấu trúc gồm 3 thành phần: họ tên, ngày tháng năm sinh, bậc lương*/
#include<stdio.h>
#include<conio.h>
#include<string.h>
struct date
{
    int ngay,thang,nam;
};
typedef struct
{
    char ht[25];/*Họ tên*/
    struct date ns; /*Năm sinh*/
    float bl; /*bậc lương*/
}person;
/*Hàm có tác dụng tìm trong danh sách n nhân viên lưu trong mảng h người có têm trong ht, trả về địa chỉ*/
person *ptim(char *ht, person h[], int n)
{
    int i;
    for(i=1;i<=n;++i)
    {
        if(strcmp(ht,h[i].ht)==0)
        return(&h[i]); 
    }
    return(NULL);
}
/*Hàm có tác dụng tìm trong danh sách n nhân viên lưu trong mảng h người có têm trong ht, trả về cấu trúc chứa thông tin*/
person tim(char *ht, person h[], int n)
{
    int i; person ps;
    ps.ns.ngay=ps.ns.thang=ps.ns.nam=0;
    ps.bl=0;
    ps.ht[0]=0;
    for(i=1;i<=n;++i)
    {
        if(strcmp(ht,h[i].ht)==0)
        return(h[i]); 
    }
    return(ps);
}
/*Hàm hoán vị hai cấu trúc person*/
void hv(person *p1,person *p2)
{
    person h;
    h=*p2;
    *p2=*p1;
    *p1=h;
}
/*Hàm sắp xếp n phần tử của cấu trúc chứa trong p theo thứ tự tăng dần của năm sinh*/
void sapxep(person *p, int n)
{
    int i,j;
    for(i=1;i<=n-1;++i)
        for(j=i+1;j<=n;++j)
            if(p[i].ns.nam>p[j].ns.nam)
            hv(&p[i],&p[j]);
}
/*Hàm vào dữ liệu cho một cấu trúc kiểu person*/
void vaop(person *p)
{
    person h;
    float bl;
    printf("\n Ho ten: ");
    gets(h.ht);
    printf("\n Ngay thang nam sinh: ");
    scanf("%d%d%d&*c",&h.ns.ngay,&h.ns.thang,&h.ns.nam);
    printf("\n Bac luong: ");
    scanf("%f%*c",&bl);
    h.bl=bl;
    *p=h;
}
/*Hàm in kết quả*/
void inp(person p)
{
    printf("\n Ho ten: %s, sinh ngay %2d thang %2d nam %4d\n Bac luong: %0.1f",p.ht,p.ns.ngay,p.ns.thang,p.ns.nam,p.bl);
}
/*Chương trình chính*/
int main()
{
    person *p,ds[100];
    int n,i,j;
    char ht[40];
    /*Vào số liệu*/
    printf("\n Nhap so nguoi: "); scanf("%d%*c",&n);
    for (i=1;i<=n;++i)
    vaop(&ds[i]);
    /*Sắp xếp theo chiều tăng của năm sinh*/
    sapxep(ds,n);
    /*In danh sách sau khi sắp xếp*/
    for (i=1;i<=n;++i)
    inp(ds[i]);
    /*Tìm kiếm họ tên (dùng hàm *ptim)*/
    while(1)
    {
        printf("\n Ho ten nguoi can tim (bam enter de ket thuc): ");
        gets(ht);
        if(ht[0]==0) break;
        p=ptim(ht,ds,n);
        if(p==NULL) printf("\n Khong tim thay");
        else inp(*p);
    }
    /*Tìm kiếm họ tên (dùng hàm tim)*/
    while(1)
    {
        printf("\n Ho ten nguoi can tim (bam enter de ket thuc): ");
        gets(ht);
        if(ht[0]==0) break;
        if(tim(ht,ds,n).ht[0]=0)
            printf("\n Khong tim thay");
        else inp(tim(ht,ds,n));
    }
    getch();
}