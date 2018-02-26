
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

        // step1 ����A
        i = 0;
        aleftcount = 0;
        arightcount = 0;
        // setp1.1 ����A��С����ǰ�ĸ�λ������λ������
        while(c != '.' && c != ' ') {
            a[i++] = c;
            aleftcount++;
            c=getchar();
        }
        a[i++] = c; // С�����ո�
        // step1.2 ����A��С�����ĸ�λ������λ������
        if(c != ' ')
            while((c=getchar()) != ' ') {
                a[i++] = c;
                arightcount++;
            }
        k = i - 1;

        // step2 ����B
        i = 0;
        bleftcount = 0;
        brightcount = 0;
        // setp2.1 ����B��С����ǰ�ĸ�λ������λ������
        while((c=getchar()) != '.' && c != '\n') {
            b[i++] = c;
            bleftcount++;
        }
        b[i++] = c; // С������з�
        // step2.2 ����B��С�����ĸ�λ������λ������
        if(c != '\n' && c != EOF)
            while((c=getchar()) != '\n' && c != EOF) {
                b[i++] = c;
                brightcount++;
            }
        l = i - 1;

        // step3 ���������
        // step3.1 С���������
        j = 0;
        // step3.1.1 �������Ĳ���
        if(arightcount > brightcount) {
            count = arightcount - brightcount;
            while(count--)
                ans[j++] = a[k--];
        } else if(arightcount < brightcount) {
            count = brightcount - arightcount;
            while(count--)
                ans[j++] = b[l--];
        }
        // step3.1.2 ͬ���������
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
        // step3.2 С����
        ans[j++] = '.';
        // step3.3 �����������
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

        // step4 ������
        // step4.1 ȥ���ұߵģ���С����
        k = 0;
        while(ans[k] == '0')
            k++;
        if(ans[k] == '.')
            k++;
        // step4.2 ������
        for(i=j-1; i>=k; i--)
            putchar(ans[i]);
        putchar('\n');
    }

    return 0;
}
