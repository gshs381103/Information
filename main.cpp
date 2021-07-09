#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void set_data();

void print_ans();

double graph(double x);

double diff_graph(double x);

double newton(double a);

void second_dimension();

void downgrade();

void formula_of_root(double, double, double);

//변수들 모음

double chs[4]= {};

double gn_1,gn_2,gn_3,gn_2_fake,gn_3_fake;

int fake;


int main(void)
{
    set_data();
    second_dimension();
    print_ans();

    return 0;
}

//------------------------------------


void set_data()
{
    for(int i=3; i>=0; i--)
    {
        if(!i)
        {
            printf("상수항?\n");
            scanf("%lf",&chs[0]);
        }
        else
        {
            printf("%d차식의 계수?\n",i);
            scanf("%lf",&chs[i]);
        }
    }

    double a;
    printf("Input the number : \n");
    scanf("%lf",&a);
    while(a==0)
    {
        printf("One more : \n");
        scanf("%lf",&a);
    }
    newton(a);
}

void print_ans()
{
    if(fake==0)
    {
        printf("\nThe answer is %lf %lf %lf",gn_1,gn_2,gn_3);
    }
    else
    {
        printf("\nThe answer is %lf || %lf+%lfi || %lf%lfi ",gn_1,gn_2,gn_2_fake,gn_3,gn_3_fake);
    }
}

double graph(double x) //함수 식
{
    double y;
    y=chs[3]*x*x*x+chs[2]*x*x+chs[1]*x+chs[0];
    return y;
}

double diff_graph(double x) // 미분때린거
{
    double y;
    y=3*chs[3]*x*x+2*chs[2]*x+chs[1];
    return y;
}

double newton(double a) //newton method
{
    double l0,l,x0,x,y0,y;
    x0=a;
    while(1)
    {
        y0=graph(x0);
        l0=diff_graph(x0);
        x=x0-(y0/l0);
        if(fabs(graph(x0)-graph(x))<0.0000001)
        {
            break;
        }
        y= fabs(x0-x);
        if(y<0.0000001) break;
        x0=x;
    }
    gn_1 = x;
    return 0;
}

void second_dimension() // 2차식 풀기
{
    downgrade();
    double a2=chs[3];

    double a1=chs[2];

    double a0=chs[1];

    formula_of_root(a2,a1,a0);
}


void downgrade() //조립제법
{
    chs[2]=chs[2]+(chs[3]*gn_1);
    chs[1]=chs[1]+(chs[2]*gn_1);
}

void formula_of_root(double a2, double a1, double a0) //근의 공식
{
    if((a1*a1 - 4.0*a2*a0)>=0.0)
    {
        gn_2=(-1.0*a1+sqrt(a1*a1 - 4.0*a2*a0))/(2.0*a2);
        gn_3=(-1.0*a1-sqrt(a1*a1 - 4.0*a2*a0))/(2.0*a2);
    }
    else
    {
        fake = 1;
        gn_2=(-1.0*a1)/(2.0*a2);
        gn_2_fake =(sqrt(fabs(a1*a1 - 4.0*a2*a0)))/(2.0*a2);
        gn_3=(-1.0*a1)/(2.0*a2);
        gn_3_fake = (-1.0*sqrt(fabs(a1*a1 - 4.0*a2*a0)))/(2.0*a2);
    }
}

