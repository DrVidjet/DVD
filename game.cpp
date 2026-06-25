#include <raylib.h>
#include <raymath.h>
#include <random>
#include <ctime>

void RandomColor(Color& color, Color table[], int size)
{
    Color newColor;

    do {
        newColor = table[rand() % size];
    } while (newColor.r == color.r &&
    newColor.g == color.g &&
    newColor.b == color.b &&
    newColor.a == color.a);

    color = newColor;
}

int main() {
    const int WIDTH = 1920;
    const int HEIGHT = 1080;
    const int SIZE = 100;
    const float speed = 150;


    InitWindow(WIDTH, HEIGHT, "Raylearn");
    DisableCursor();
    SetTargetFPS(200);

    float x = WIDTH/2-SIZE;
    float y = HEIGHT/2-SIZE;

    float directionx = 1;
    float directiony = -1;

    Color color_table[] =
    {
        BLUE,
        WHITE,
        YELLOW,
        GREEN,
        RED,
        SKYBLUE,
        LIME
    };

    Color color = WHITE;
    int color_index = 0;

    srand((unsigned)time(NULL));
    Font font = GetFontDefault();
    Vector2 size = MeasureTextEx(font, "DVD", SIZE, 0);

    float textWidth  = size.x;
    float textHeight = size.y;

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("DVD",(int)x,(int)y,SIZE,color);

        // DrawText(TextFormat("X: %.1f  Y: %.1f", x, y), x,y+SIZE,20,BLACK);

        DrawFPS(10, 10);

        if (x + textWidth + textWidth/8 >= WIDTH) directionx = -1, directiony = ((float)rand() / RAND_MAX) * 2.0f - 1.0f, RandomColor(color, color_table, 7);
        if (y + textHeight - textHeight/8 >= HEIGHT) directiony = -1, directionx = ((float)rand() / RAND_MAX) * 2.0f - 1.0f, RandomColor(color, color_table, 7);
        if (x <= 0) directionx = 1, directiony = ((float)rand() / RAND_MAX) * 2.0f - 1.0f, RandomColor(color, color_table, 7);
        if (y <= 0) directiony = 1, directionx = ((float)rand() / RAND_MAX) * 2.0f - 1.0f, RandomColor(color, color_table, 7);

        x += directionx * speed * GetFrameTime();
        y += directiony * speed * GetFrameTime();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
