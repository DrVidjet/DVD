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
    const int SIZE = 200;
    const float speed = 200;


    InitWindow(WIDTH, HEIGHT, "Raylearn");
    DisableCursor();
    SetTargetFPS(200);

    Vector2 pos;
    Vector2 vel;

    pos.x = WIDTH/2-SIZE;
    pos.y = HEIGHT/2-SIZE;

    vel.x =  ((float)rand() / RAND_MAX) * 2.0f - 1.0f;
    vel.y = ((float)rand() / RAND_MAX) * 2.0f - 1.0f;

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

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(BLACK);

        DrawText("DVD",pos.x,pos.y,SIZE,color);

        // DrawText(TextFormat("X: %.1f  Y: %.1f", x, y), x,y+SIZE,20,BLACK);

        DrawFPS(10, 10);

        if (pos.x + size.x + size.x/8 >= WIDTH) vel.x = -1, vel.y = ((float)rand() / RAND_MAX) * 2.0f - 1.0f, RandomColor(color, color_table, 7), vel = Vector2Normalize(vel);
        if (pos.y + size.y - size.y/8 >= HEIGHT) vel.y = -1, vel.x = ((float)rand() / RAND_MAX) * 2.0f - 1.0f, RandomColor(color, color_table, 7), vel = Vector2Normalize(vel);
        if (pos.x <= 0) vel.x = 1, vel.y = ((float)rand() / RAND_MAX) * 2.0f - 1.0f, RandomColor(color, color_table, 7), vel = Vector2Normalize(vel);
        if (pos.y <= 0) vel.y = 1, vel.x = ((float)rand() / RAND_MAX) * 2.0f - 1.0f, RandomColor(color, color_table, 7), vel = Vector2Normalize(vel);

        pos.x += vel.x * speed * GetFrameTime();
        pos.y += vel.y * speed * GetFrameTime();

        EndDrawing();
    }

    CloseWindow();
    return 0;
}
