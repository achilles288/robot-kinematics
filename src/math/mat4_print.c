#include <rk/matrix.h>

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>


#if defined __cplusplus
extern "C" {
#endif


void rkMat4Print(rkMat4 M) {
    char *loc = setlocale(LC_ALL, 0);
    freopen(0, "w", stdout);
    setlocale(LC_ALL, "");
    
    int a[4];
    int line_width = 12;
    for(int i=0; i<4; i++) {
        int m = 0;
        for(int j=0; j<3; j++) {
            char buff[16];
            sprintf(buff, "%.4f", M.data[j][i]);
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
    
    for(int i=0; i<3; i++) {
        wchar_t line[line_width];
        wmemset(line, ' ', line_width);
        wchar_t *p = line+2;
        
        line[0] = L'│';
        line[line_width-3] = L'│';
        line[line_width-2] = '\n';
        line[line_width-1] = '\0';
        
        for(int j=0; j<4; j++) {
            wchar_t buff[16];
            swprintf(buff, 16, L"%.4f", M.data[i][j]);
            int b = wcslen(buff);
            p += a[j]-b;
            wmemcpy(p, buff, b);
            p += b;
            
            if(j == 3)
                break;
            *p = ',';
            p += 2;
        }
        fputws(line, stdout);
    }
    endline[0] = L'└';
    endline[line_width-3] = L'┘';
    fputws(endline, stdout);
    
    freopen(0, "w", stdout);
    setlocale(LC_ALL, loc);
}


#if defined __cplusplus
}
#endif
