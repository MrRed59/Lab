#include <SFML/Graphics.hpp>
#include <time.h>

using namespace sf;

int main()
{
    srand(time(0));

    RenderWindow app(VideoMode(400, 400), "Minesweeper!");

    int w = 32;

    int gridLogic[12][12];
    int gridView[12][12];

    Texture t;
    t.loadFromFile("images/tiles.jpg");
    Sprite s(t);

    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            gridView[i][j] = 10;
            if (rand() % 5 == 0) gridLogic[i][j] = 9;
            else gridLogic[i][j] = 0;
        }

    //Расстановка цифр, отражающих наличие мин в соседних клетках
    for (int i = 1; i <= 10; i++)
        for (int j = 1; j <= 10; j++)
        {
            int n = 0;
            if (gridLogic[i][j] == 9) continue;
            if (gridLogic[i + 1][j] == 9) n++;
            if (gridLogic[i][j + 1] == 9) n++;
            if (gridLogic[i - 1][j] == 9) n++;
            if (gridLogic[i][j - 1] == 9) n++;
            if (gridLogic[i + 1][j + 1] == 9) n++;
            if (gridLogic[i - 1][j - 1] == 9) n++;
            if (gridLogic[i - 1][j + 1] == 9) n++;
            if (gridLogic[i + 1][j - 1] == 9) n++;
            gridLogic[i][j] = n;
        }

    while (app.isOpen())
    {
        Event e;

        while (app.waitEvent(e))
        {
            Vector2i pos = Mouse::getPosition(app);
            int x = pos.x / w;
            int y = pos.y / w;

            if (e.type == Event::Closed)
                app.close();

            if (e.type == Event::MouseButtonPressed)
            {
                if (e.key.code == Mouse::Left)
                {
                    gridView[x][y] = gridLogic[x][y];
                    if (gridLogic[x][y] == 9)
                        for (int i = 1; i <= 10; i++)
                            for (int j = 1; j <= 10; j++)
                            {
                                gridView[i][j] = gridLogic[i][j];
                            }
                }
                else if (e.key.code == Mouse::Right) gridView[x][y] = 11;
            }

            app.clear(Color::White);

            for (int i = 1; i <= 10; i++)
                for (int j = 1; j <= 10; j++)
                {
                    s.setTextureRect(IntRect(gridView[i][j] * w, 0, w, w));
                    s.setPosition(i * w, j * w);
                    app.draw(s);
                }
            app.display();
        }
    }

    return 0;
}