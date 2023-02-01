#include <windows.h>
#include <stdbool.h>
#include <conio.h>
#include <iostream>

#define VK_LEFT 37
#define VK_UP 38
#define VK_RIGHT 39
#define VK_DOWN 40

HCURSOR hCurs1, hCurs2;    // cursor handles 
 
POINT pt;                  // cursor location  
RECT rc;                   // client area coordinates 
static int repeat = 1;     // repeat key counter 

HWND hWnd = GetActiveWindow();
 
// 
// Other declarations and initialization. 
// 
int main() {
    char message, wParam;


    while (true) {

        // clean buffer
        fflush(stdin);
        // get input
        message = getchar();



        switch (message) 
        { 
        // 
        // Process other messages. 
        // 
            // clean buffer
            fflush(stdin);
            // get input
            getchar();
            wParam = getchar();

        
            case WM_KEYDOWN: 
        
                if (wParam != VK_LEFT && wParam != VK_RIGHT && 
                wParam != VK_UP && wParam != VK_DOWN) 
                { 
                    break; 
                } 
        
                GetCursorPos(&pt); 
        
                // Convert screen coordinates to client coordinates. 
        
                ScreenToClient(hWnd, &pt); 
        
                switch (wParam) 
                { 
                // Move the cursor to reflect which 
                // arrow keys are pressed. 
        
                    case VK_LEFT:               // left arrow 
                        pt.x -= repeat; 
                        break; 
        
                    case VK_RIGHT:              // right arrow 
                        pt.x += repeat; 
                        break; 
        
                    case VK_UP:                 // up arrow 
                        pt.y -= repeat; 
                        break; 
        
                    case VK_DOWN:               // down arrow 
                        pt.y += repeat; 
                        break; 
        
                    default: 
                        return 0; 
                } 
        
                repeat++;           // Increment repeat count. 
        
                // Keep the cursor in the client area. 
        
                GetClientRect(hWnd, &rc); 
        
                if (pt.x >= rc.right) 
                { 
                    pt.x = rc.right - 1; 
                } 
                else 
                { 
                    if (pt.x < rc.left) 
                    { 
                        pt.x = rc.left; 
                    } 
                } 
        
                if (pt.y >= rc.bottom) 
                    pt.y = rc.bottom - 1; 
                else 
                    if (pt.y < rc.top) 
                        pt.y = rc.top; 
        
                // Convert client coordinates to screen coordinates. 
        
                ClientToScreen(hWnd, &pt); 
                SetCursorPos(pt.x, pt.y); 
                return 0; 

        
            case WM_KEYUP: 
        
                repeat = 1;            // Clear repeat count. 
                return 0; 
        
        }
    }
 }