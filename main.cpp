
#include <stdio.h>
#include <stdlib.h>

#define MAXN 400

char a[MAXN+1], b[MAXN+1], ans[MAXN+1];

int main(void)
{
    char c;
    int aleftcount, arightcount, bleftcount, brightcount, carry, count, i, j, k, l;

    for(;;) {
        c=getchar();
        if(c == EOF)
            break;

        // step1 读入A
        i = 0;
        aleftcount = 0;
        arightcount = 0;
        // setp1.1 读入A的小数点前的各位，并且位数计数
        while(c != '.' && c != ' ') {
            a[i++] = c;
            aleftcount++;
            c=getchar();
        }
        a[i++] = c; // 小数点或空格
        // step1.2 读入A的小数点后的各位，并且位数计数
        if(c != ' ')
            while((c=getchar()) != ' ') {
                a[i++] = c;
                arightcount++;
            }
        k = i - 1;

        // step2 读入B
        i = 0;
        bleftcount = 0;
        brightcount = 0;
        // setp2.1 读入B的小数点前的各位，并且位数计数
        while((c=getchar()) != '.' && c != '\n') {
            b[i++] = c;
            bleftcount++;
        }
        b[i++] = c; // 小数点或换行符
        // step2.2 读入B的小数点后的各位，并且位数计数
        if(c != '\n' && c != EOF)
            while((c=getchar()) != '\n' && c != EOF) {
                b[i++] = c;
                brightcount++;
            }
        l = i - 1;

        // step3 计算Ａ＋Ｂ
        // step3.1 小数部分相加
        j = 0;
        // step3.1.1 拷贝长的部分
        if(arightcount > brightcount) {
            count = arightcount - brightcount;
            while(count--)
                ans[j++] = a[k--];
        } else if(arightcount < brightcount) {
            count = brightcount - arightcount;
            while(count--)
                ans[j++] = b[l--];
        }
        // step3.1.2 同长部分相加
        carry = 0;
        count = (arightcount > brightcount) ? brightcount : arightcount;
        for(i=1; i<=count; i++) {
            ans[j] = carry + a[k] + b[l] - '0';
            if(ans[j] > '9') {
                ans[j] -= 10;
                carry = 1;
            } else
                carry = 0;
            j++;
            k--;
            l--;
        }
        // step3.2 小数点
        ans[j++] = '.';
        // step3.3 整数部分相加
        k--;
        l--;
        while(k >= 0 || l >= 0) {
            ans[j] = carry + ((k>=0) ? a[k] : '0') + ((l>=0) ? b[l] : '0') - '0';
            if(ans[j] > '9') {
                ans[j] -= 10;
                carry = 1;
            } else
                carry = 0;
            j++;
            k--;
            l--;
        }
        if(carry == 1)
            ans[j++] = '1';

        // step4 输出结果
        // step4.1 去掉右边的０和小数点
        k = 0;
        while(ans[k] == '0')
            k++;
        if(ans[k] == '.')
            k++;
        // step4.2 输出结果
        for(i=j-1; i>=k; i--)
            putchar(ans[i]);
        putchar('\n');
    }

    return 0;
}
