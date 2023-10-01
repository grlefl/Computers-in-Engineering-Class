#include <SFML/Graphics.hpp>
#include <time.h>
#include <SFML/Audio.hpp>
#include <string>

using namespace sf; // sfml graphics module

int ts = 54; //tile size
Vector2i offset(48, 24); // change the position of the window (relatively to the desktop)

//////////////////////////////////////// CLASS DOCUMENTATION ////////////////////////////////////////
class Piece { // creating class Piece
private:
    int x, y, col, row, kind, match, alpha;
    // x = width of grid
    // y = height of grid
    // col = column of grid
    // row = row of grid
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
// I'm not sure what this does.

///////////////////////////////////////////////////////////////
// Description: swap two pieces in the game grid
// Input: p1 and p2 are Piece objects pass-by-value to swap
// Output: updated grid of pieces
///////////////////////////////////////////////////////////////
void swap(Piece p1, Piece p2) {
    // swapping the position of first piece
    int tmp = p1.getCol();
    p1.setCol(p2.getCol());
    p2.setCol(tmp);
    // swapping the position of second piece
    tmp = p1.getRow();
    p1.setRow(p2.getRow());
    p2.setRow(tmp);

    // updating the grid itself
    grid[p1.getRow()][p1.getCol()] = p1;
    grid[p2.getRow()][p2.getCol()] = p2;
}

int main() {

    //////////////////////////////////////// SETTING UP THE GAME ////////////////////////////////////////

    // seed random time
    srand(time(0));

    // create window and set frame rate
    RenderWindow app(VideoMode(740, 480), "Match-3 Game!");
    app.setFramerateLimit(60);

    // loading textures
    Texture t1, t2, t3, t4, t5, t6;
    if (!t1.loadFromFile("images/background.png")) { EXIT_FAILURE; }
    if (!t2.loadFromFile("images/gems.png")) { EXIT_FAILURE; }
    // https://betterbakingbible.com/pink-background-png/
    if (!t3.loadFromFile("images/pink-background.png")) { EXIT_FAILURE; }
    // Nicki Minaj Png Clipart by Hannah Hill, https://freepngimg.com/png/14695-nicki-minaj-png-clipart, License: Creative Commons
    if (!t4.loadFromFile("images/dinkyminaj.png")) { EXIT_FAILURE; }
    // Solid_black.png, https://commons.wikimedia.org/wiki/File:Solid_black.png, License: public domain
    if (!t5.loadFromFile("images/black.png")) { EXIT_FAILURE; }
    // Retro Pastel Yellow Color, https://www.color-name.com/retro-pastel-yellow.color
    if (!t6.loadFromFile("images/yellow.png")) { EXIT_FAILURE; }

    // intro sprites
    Sprite introBackground(t3), NICKIMINAJ(t4), instructions_black(t5), instructions_yellow(t6)
        , configurations_black(t5), configurations_yellow(t6);
    // gameplay sprites
    Sprite background(t1), gems(t2);


    // loading sound
    // PERIOD - Nicki Minaj by ThatsSoBold, https://www.myinstants.com/en/instant/period-nicki-minaj-10049/, License: Free for personal use.
    sf::SoundBuffer bufferMatch;
    if (!bufferMatch.loadFromFile("sounds/period.ogg")) {
        return EXIT_FAILURE;
    }
    sf::Sound match;
    match.setBuffer(bufferMatch);

    // loading fonts
    // Kiss Me Quick by Jonathan Harris, https://www.1001freefonts.com/, License: Free for personal use.
    sf::Font fancy_font;
    if (!fancy_font.loadFromFile("fonts/kiss_me_quick.ttf")) { return EXIT_FAILURE; }
    // Valentine Cute by AEN Creative Studio, https://www.1001freefonts.com/, License: Free for personal use.
    sf::Font normal_font;
    if (!normal_font.loadFromFile("fonts/ValentineCute/valentine-cute.ttf")) { return EXIT_FAILURE; }

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

    // initial variables
    int x0, y0, x, y;
    int click = 0;
    Vector2i pos;
    bool isSwap = false, isMoving = false;

    // first game variables
    int gameScore = 0; // overall game score
    time_t startTime;
    int time_limit = 40;

    // state of game
    enum GameState {start, play, end};
    GameState state = start;

    //////////////////////////////////////////////// GAME LOOP ////////////////////////////////////////////////
    while (app.isOpen()) {

        Event e;
        //////////////////////////////////////////////// EVENT LOOP ////////////////////////////////////////////////
        while (app.pollEvent(e)) { // while there are still events
            if (e.type == Event::Closed) { // if window is closed
                app.close();
            }

            if (state==start) {
                if (e.type == Event::MouseButtonPressed) {
                    startTime = time(0); // saving time at which game start
                    state = play;
                }
            }
            if (state==play) {
                if (e.type == Event::MouseButtonPressed) {
                    if (e.key.code == Mouse::Left) {
                        if (!isSwap && !isMoving) {
                            click++;
                        }
                        pos = Mouse::getPosition(app) - offset;
                    }
                }
            }
            if (state==end) {
                if (e.type == Event::KeyPressed) {
                    if (e.key.code == Keyboard::R) {
                        for (int i = 1; i <= 8; i++) {
                            for (int j = 1; j <= 8; j++) {
                                grid[i][j].setKind(rand() % 3);
                                grid[i][j].setCol(j);
                                grid[i][j].setRow(i);
                                grid[i][j].setX(j * ts);
                                grid[i][j].setY(i * ts);
                            }
                        }
                        startTime = time(0);
                        gameScore = 0;
                        state = play;
                    }
                }
            }
        }

        //////////////////////////////////////////////// GAME LOGIC ////////////////////////////////////////////////
        if (state == play) {

            // Countdown Timer
            // takes the difference between the current time and the time at the start of the game
            if (time(0) - startTime > time_limit) {
                state = end;
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
                            match.play();
                            for (int n = i; n > 0; n--) {
                                if (!grid[n][j].getMatch()) {
                                    gameScore += 1;
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
        }

        //////////////////////////////////////////// DISPLAY LOGIC ////////////////////////////////////////////

        if (state==start){
            // Part 4 - adding my own feature to Bejeweled game
            // The following portion of code displays an instruction
            // screen before the game begins. The user begins the game
            // by clicking the mouse.
            app.clear();

            // background images
            app.draw(introBackground);
            app.draw(NICKIMINAJ);

            // instructions background
            instructions_black.setTextureRect(IntRect(0,0,400,200));
            instructions_black.setPosition(60,30);
            app.draw(instructions_black);
            instructions_yellow.setTextureRect(IntRect(0,0,390,190));
            instructions_yellow.setPosition(65,35);
            app.draw(instructions_yellow);

            // configurations background
            configurations_black.setTextureRect(IntRect(0,0,280,175));
            configurations_black.setPosition(50,270);
            app.draw(configurations_black);
            configurations_yellow.setTextureRect(IntRect(0,0,270,165));
            configurations_yellow.setPosition(55,275);
            app.draw(configurations_yellow);

            // text for title
            sf::Text title;
            title.setFont(fancy_font);
            title.setString("Bejeweled"); // set the string to display
            title.setCharacterSize(60); // set the character size in pixels, not points!
            title.setFillColor(sf::Color::Red); // set the color
            title.setStyle(sf::Text::Bold); // set the text style
            title.setPosition(180, 40);
            app.draw(title);

            // text for instructions
            sf::Text instructions;
            instructions.setFont(normal_font);
            instructions.setString("Swap two gems to match 3 or more of them in a row\nor column. "
                                   "Do this by clicking once on each of the gems.\nMore matches mean "
                                   "more points. Get as many points\nas you can before the timer runs out!"); // set the string to display
            instructions.setCharacterSize(10); // set the character size in pixels, not points!
            instructions.setFillColor(sf::Color::Red); // set the color
            instructions.setStyle(sf::Text::Bold); // set the text style
            instructions.setPosition(83, 120);
            app.draw(instructions);

            // text for configurations
            sf::Text configurations;
            configurations.setFont(normal_font);
            configurations.setString("Acceptable gem configurations...\n\t\t3+ gems in a row or column\n\t\t5 gems in"
                                     " a cross shape\n\t\t5 gems in an L shape\n\n\t\tClick mouse to begin!");
            configurations.setCharacterSize(10); // set the character size in pixels, not points!
            configurations.setFillColor(sf::Color::Red); // set the color
            configurations.setStyle(sf::Text::Bold); // set the text style
            configurations.setPosition(80, 290);
            app.draw(configurations);

            app.display();
        }


        if (state==play) {
            app.clear();

            app.draw(background); // draw background

            // create text for score
            sf::Text scoreText;
            scoreText.setFont(fancy_font);
            scoreText.setString("Score  " + std::to_string(gameScore)); // set the string to display
            scoreText.setCharacterSize(24); // set the character size in pixels, not points!
            scoreText.setFillColor(sf::Color::Red); // set the color
            scoreText.setStyle(sf::Text::Bold); // set the text style
            scoreText.setPosition(485, 400);

            // create text for timer
            sf::Text timerText;
            timerText.setFont(fancy_font);
            timerText.setString("Time Left  " + std::to_string(time_limit - (time(0) - startTime)) +
                " seconds"); // set the string to display
            timerText.setCharacterSize(24); // set the character size in pixels, not points!
            timerText.setFillColor(sf::Color::Red); // set the color
            timerText.setStyle(sf::Text::Bold); // set the text style
            timerText.setPosition(485, 425);

            // draw text
            app.draw(scoreText);
            app.draw(timerText);

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

        if (state==end) {
            // I'm going to reuse the instructions yellow and black sprites

            // instructions background
            instructions_black.setTextureRect(IntRect(0,0,400,200));
            instructions_black.setPosition(170,140);
            app.draw(instructions_black);
            instructions_yellow.setTextureRect(IntRect(0,0,390,190));
            instructions_yellow.setPosition(175,145);
            app.draw(instructions_yellow);

            // create text for Game Over
            sf::Text gameOver;
            gameOver.setFont(normal_font);
            gameOver.setString("Game Over");
            gameOver.setCharacterSize(30); // set the character size in pixels, not points!
            gameOver.setFillColor(sf::Color::Red); // set the color
            gameOver.setStyle(sf::Text::Bold); // set the text style
            gameOver.setPosition(270, 190);
            app.draw(gameOver);

            // create text for restart
            sf::Text restart;
            restart.setFont(normal_font);
            restart.setString("press R to restart game");
            restart.setCharacterSize(20); // set the character size in pixels, not points!
            restart.setFillColor(sf::Color::Red); // set the color
            restart.setStyle(sf::Text::Bold); // set the text style
            restart.setPosition(210, 270);
            app.draw(restart);

            app.display();
        }
    }
    return 0;
}
