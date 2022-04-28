#include<stdio.h>
#include<math.h>
int main (){
    //求圓柱體表面積
    //acos為函數，其功能是求反餘弦。
    //acos(-1.0)就是求-1.0的反餘弦，再賦值给double類型的常變量pi
    const double pi = acos(-1.0);
    double r, h, s1, s2, s;
    scanf("%lf%lf", &r, &h);//是小寫Lf
    s1 = pi*r*r;
    s2 = 2*pi*r*h;
    s = s1*2.0 + s2;
    printf("area = %.3f\n", s);
    return 0;
}