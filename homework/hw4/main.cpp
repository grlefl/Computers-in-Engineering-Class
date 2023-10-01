// completed
#include <SFML/Graphics.hpp>
#include <time.h>


using namespace sf; // sfml graphics module

int ts = 54; //tile size
Vector2i offset(48, 24); // change the position of the window (relatively to the desktop)

class Piece { // creating class Piece
private:
    int x, y, col, row, kind, match, alpha; // private variables
public:
    // constructor
    Piece(int m_x = 1, int m_y = 1, int m_col = 1, int m_row = 1, int m_kind = 1, int m_match = 0, int m_alpha = 255):
        x{m_x}, y{m_y}, col{m_col}, row{m_row}, kind{m_kind}, match{m_match}, alpha{m_alpha} {}
    // GETTERS
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }
    int getCol() const {
        return col;
    }
    int getRow() const {
        return row;
    }
    int getKind() const {
        return kind;
    }
    int getMatch() const {
        return match;
    }
    int getAlpha() const {
        return alpha;
    }
    // SETTERS
    void setX(const int i) {
        x = i;
    }
    void setY(const int i) {
        y = i;
    }
    void setCol(const int i) {
        col = i;
    }
    void setRow(const int i) {
        row = i;
    }
    void setKind(const int i) {
        kind = i;
    }
    void setMatch(const int i) {
        match = i;
    }
    void setAlpha(const int i) {
        alpha = i;
    }
};

Piece grid[10][10]; // initializing object

// Description: swap two pieces in the game grid
// Input: p1 and p2 are Piece objects pass-by-value to swap
// Output: updated grid of pieces

void swap(Piece p1, Piece p2) {
    int tmp = p1.getCol();
    p1.setCol(p2.getCol());
    p2.setCol(tmp);

    tmp = p1.getRow();
    p1.setRow(p2.getRow());
    p2.setRow(tmp);

    grid[p1.getRow()][p1.getCol()] = p1;
    grid[p2.getRow()][p2.getCol()] = p2;
}


int main() {

    srand(time(0)); // seed random time

    RenderWindow app(VideoMode(740, 480), "Match-3 Game!"); // create window
    app.setFramerateLimit(60); // set framerate limit

    Texture t1, t2;
    // loading textures
    if (!t1.loadFromFile("images/background.png")) { EXIT_FAILURE; }
    if (!t2.loadFromFile("images/gems.png")) { EXIT_FAILURE; }

    Sprite background(t1), gems(t2); // creating sprites

    // setting up grid
    for (int i = 1; i <= 8; i++) {
        for (int j = 1; j <= 8; j++) {
            grid[i][j].setKind(rand() % 3);
            grid[i][j].setCol(j);
            grid[i][j].setRow(i);
            grid[i][j].setX(j * ts);
            grid[i][j].setY(i * ts);
        }
    }

    int x0, y0, x, y;
    int click = 0;
    Vector2i pos;
    bool isSwap = false, isMoving = false;

    while (app.isOpen()) {
        Event e;
        while (app.pollEvent(e)) { // while there are still events
            if (e.type == Event::Closed) { // if window is closed
                app.close();
            }

            if (e.type == Event::MouseButtonPressed) {
                if (e.key.code == Mouse::Left) {
                    if (!isSwap && !isMoving) {
                        click++;
                    }
                    pos = Mouse::getPosition(app) - offset;
                }
            }
        }

        // mouse click
        if (click == 1) {
            x0 = pos.x / ts + 1;
            y0 = pos.y / ts + 1;
        }
        if (click == 2) {
            x = pos.x / ts + 1;
            y = pos.y / ts + 1;
            if (abs(x - x0) + abs(y - y0) == 1) {
                swap(grid[y0][x0], grid[y][x]);
                isSwap = 1;
                click = 0;
            } else {
                click = 1;
            }
        }

        //Match finding
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                if (grid[i][j].getKind() == grid[i + 1][j].getKind()) {
                    if (grid[i][j].getKind() == grid[i - 1][j].getKind()) {
                        for (int n = -1; n <= 1; n++) {
                            grid[i + n][j].setMatch(grid[i + n][j].getMatch() + 1);
                        }
                    }
                }

                if (grid[i][j].getKind() == grid[i][j + 1].getKind()) {
                    if (grid[i][j].getKind() == grid[i][j - 1].getKind()) {
                        for (int n = -1; n <= 1; n++) {
                            grid[i][j + n].setMatch(grid[i][j + n].getMatch() + 1);
                        }
                    }
                }
            }
        }

        //Moving animation
        isMoving = false;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                Piece &p = grid[i][j];
                int dx, dy;
                for (int n = 0; n < 4; n++)   // 4 - speed
                {
                    dx = p.getX() - p.getCol() * ts;
                    dy = p.getY() - p.getRow() * ts;
                    if (dx) {
                        p.setX(p.getX() - dx / abs(dx));
                    }
                    if (dy) {
                        p.setY(p.getY() - dy / abs(dy));
                    }
                }
                if (dx || dy) {
                    isMoving = 1;
                }
            }
        }

        //Deleting animation
        if (!isMoving) {
            for (int i = 1; i <= 8; i++) {
                for (int j = 1; j <= 8; j++) {
                    if (grid[i][j].getMatch()) {
                        if (grid[i][j].getAlpha() > 10) {
                            grid[i][j].setAlpha(grid[i][j].getAlpha() - 10);
                            isMoving = true;
                        }
                    }
                }
            }
        }

        //Get score
        int score = 0;
        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                score += grid[i][j].getMatch();
            }
        }

        //Second swap if no match
        if (isSwap && !isMoving) {
            if (!score) {
                swap(grid[y0][x0], grid[y][x]);
            }
            isSwap = 0;
        }

        //Update grid
        if (!isMoving) {
            for (int i = 8; i > 0; i--) {
                for (int j = 1; j <= 8; j++) {
                    if (grid[i][j].getMatch()) {
                        for (int n = i; n > 0; n--) {
                            if (!grid[n][j].getMatch()) {
                                swap(grid[n][j], grid[i][j]);
                                break;
                            }
                        }
                    }
                }
            };

            for (int j = 1; j <= 8; j++) {
                for (int i = 8, n = 0; i > 0; i--) {
                    if (grid[i][j].getMatch()) {
                        grid[i][j].setKind(rand() % 7);
                        grid[i][j].setY(-ts * n++);
                        grid[i][j].setMatch(0);
                        grid[i][j].setAlpha(255);
                    }
                }
            }
        }


        //////draw///////
        app.draw(background); // draw background

        for (int i = 1; i <= 8; i++) {
            for (int j = 1; j <= 8; j++) {
                Piece p = grid[i][j];
                gems.setTextureRect(IntRect(p.getKind() * 49, 0, 49, 49));
                gems.setColor(Color(255, 255, 255, p.getAlpha()));
                gems.setPosition(p.getX(), p.getY());
                gems.move(offset.x - ts, offset.y - ts);
                app.draw(gems);
            }
        }

        app.display(); // display drawing
    }
    return 0;
}
