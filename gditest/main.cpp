#include <windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    WNDCLASS wc;
    HWND hWnd;
    MSG msg;

    wc.cbClsExtra     = 0;
    wc.cbWndExtra     = 0;
    wc.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 1);
    wc.hCursor        = LoadCursor(NULL, IDC_ARROW);
    wc.hIcon          = LoadIcon(NULL, IDI_APPLICATION);
    wc.hInstance      = hInstance;
    wc.lpfnWndProc    = WndProc;
    wc.lpszClassName  = "Classe 1";
    wc.lpszMenuName   = NULL;
    wc.style          = CS_HREDRAW | CS_VREDRAW;

    RegisterClass(&wc);

    hWnd = CreateWindow("Classe 1",
                        "Notre première fenêtre",
                        WS_OVERLAPPEDWINDOW,
                        100, 100, 600, 300,
                        NULL,
                        NULL,
                        hInstance,
                        NULL);

    ShowWindow(hWnd, nCmdShow);

    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HDC hDC, hdcMem;
    PAINTSTRUCT ps;

    static HBITMAP hBitmap;
    static BITMAP bitmap;

    switch(message)
    {
        case WM_CREATE:
        {
            /* Chargement de l'image */
            hBitmap = LoadImage(NULL, "f:\\c\gditest\lena.bmp", IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
            GetObject(hBitmap, sizeof(bitmap), &bitmap);

            /* DC de la fenêtre */
            hDC = GetDC(hwnd);

            /* DC en mémoire */
            hdcMem = CreateCompatibleDC(hDC);
            SelectObject(hdcMem, hBitmap);

            break;
        }

        case WM_PAINT:
        {
            BeginPaint(hwnd, &ps);
            BitBlt(hDC, 20, 20, bitmap.bmWidth, bitmap.bmHeight, hdcMem, 0, 0, SRCCOPY);
            EndPaint(hwnd, &ps);

            break;
        }

        case WM_DESTROY:
        {
            ReleaseDC(hwnd, hDC);
            DeleteDC(hdcMem);
            DeleteObject(hBitmap);
            PostQuitMessage(0);

            break;
        }

        default:
        {
            return DefWindowProc(hwnd, message, wParam, lParam);
        }
    }

    return 0L;
}
