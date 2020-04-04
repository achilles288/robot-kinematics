#include <rk/matrix.h>

#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <wchar.h>


#if defined __cplusplus
extern "C" {
#endif


void rkMatPrint(void *ptr, int type) {
    float *data = 0;
    int row = 0, col = 0;
    if(type == RK_MAT3) {
        row = 2;
        col = 3;
        data = (float*) &(((rkMat3*)ptr)->data);
    }
    else if(type == RK_MAT4) {
        row = 3;
        col = 4;
        data = (float*) &(((rkMat4*)ptr)->data);
    }
    char *loc = setlocale(LC_ALL, 0);
    freopen(0, "a", stdout);
    setlocale(LC_ALL, "");
    
    int a[4];
    int line_width = 6 + 2*(col-1);
    for(int i=0; i<col; i++) {
        int m = 0;
        for(int j=0; j<row; j++) {
            char buff[12];
            if(fabs(data[j*col + i]) < 10000.0000f)
                sprintf(buff, "%.4f", data[j*col + i]);
            else
                sprintf(buff, "%.3e", data[j*col + i]);
            int c = strlen(buff);
            if(c > m)
                m = c;
        }
        a[i] = m;
        line_width += a[i];
    }
    
    wchar_t endline[line_width];
    wmemset(endline, L' ', line_width);
    endline[0] = L'┌';
    endline[1] = L'─';
    endline[line_width-4] = L'─';
    endline[line_width-3] = L'┐';
    endline[line_width-2] = '\n';
    endline[line_width-1] = '\0';
    fputws(endline, stdout);
    
    for(int i=0; i<row; i++) {
        wchar_t line[line_width];
        wmemset(line, ' ', line_width);
        wchar_t *p = line+2;
        
        line[0] = L'│';
        line[line_width-3] = L'│';
        line[line_width-2] = '\n';
        line[line_width-1] = '\0';
        
        for(int j=0; j<col; j++) {
            wchar_t buff[12];
            if(fabs(data[i*col + j]) < 10000.0000f)
                swprintf(buff, sizeof(buff), L"%.4f", data[i*col + j]);
            else
                swprintf(buff, sizeof(buff), L"%.3e", data[i*col + j]);
            int b = wcslen(buff);
            p += a[j]-b;
            wmemcpy(p, buff, b);
            p += b;
            
            if(j == col-1)
                break;
            *p = ',';
            p += 2;
        }
        fputws(line, stdout);
    }
    endline[0] = L'└';
    endline[line_width-3] = L'┘';
    fputws(endline, stdout);
    
    freopen(0, "a", stdout);
    setlocale(LC_ALL, loc);
}


#if defined __cplusplus
}
#endif
