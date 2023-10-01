/* Name: Grace Flores
 * Date: November 28th, 2022
 * Program Description: In  this  homework,  I added new  functionality  to  the asteroids  game written  by
 *                      Fam  Trinli (https://www.youtube.com/watch?v=rWaSo2usU4A).This program involves use of
 *                      dynamic  memory  allocation,  standard template library objects, object composition,
 *                      inheritance,and polymorphism.
 */

/*
 * Extra Credit Documentation:
 * I refactored the code so it is properly formatted and follows best programming practices such as using private
 * member variables, setters and getters, proper indentation with curly braces, modifying constructors to
 * initialize all member variables, properly following the principle of least privilege,
 * using public, protected, and private, etc.
 * I also added sounds to the bullets and explosions. I hope this makes up for anything
 * that might be lacking in fulfilling the conditions above.
 */

#include <SFML/Graphics.hpp>
#include <time.h>
#include <list>
#include <cmath>
#include <SFML/Audio.hpp>

using namespace sf;

const int W = 1200;
const int H = 800;
float DEGTORAD = 0.017453f;


/*
 * class: Animation
 * description: creates sprites for each frame of animation
 *              and controls frame rate
 */
class Animation {
public:
    // public variables
    Sprite sprite; // question: can I make this private?

    Animation() {}

    Animation(Texture &t, int x, int y, int w, int h, int count, float Speed) {
        // question: what do these variables mean?
        setFrame(0);
        setSpeed(Speed);

        for (int i = 0; i < count; i++) {
            frames.push_back(IntRect(x + i * w, y, w, h));
            // example: IntRect(0,0,20,5); rectangle located at 0,0 with size 20x5
        }

        sprite.setTexture(t);
        sprite.setOrigin(w / 2, h / 2);
        sprite.setTextureRect(frames[0]);
    }


    void update() {
        setFrame(getFrame() + getSpeed());
        int n = frames.size();
        if (getFrame() >= n) { setFrame(getFrame()-n); }
        if (n > 0) { sprite.setTextureRect(frames[int(getFrame())]); }
    }

    bool isEnd() {
        return getFrame() + getSpeed() >= frames.size();
    }

    // getters
    float getFrame() const { return m_Frame; }
    float getSpeed() const { return m_speed; }

    // setters
    void setFrame(const float Frame) { m_Frame = Frame; }
    void setSpeed(const float speed) { m_speed = speed; }

private:
    // private variables
    // question: what do these variables mean?
    float m_Frame;
    float m_speed;
    std::vector<IntRect> frames;
};


/*
 * class: Entity
 * description: base class entity; all game elements are derived from this class
 *              Involves position, speed, angle, and radius of an object.
 */
class Entity
{
public:
    // public variables
    Animation anim; // question: can I make this private?

    Entity() // default constructor
    {
        setLife(1);
    }

    void settings(Animation &a, int X, int Y, float Angle = 0, int radius = 1) // set everything at once
    {
        anim = a;
        setX(X);
        setY(Y);
        setAngle(Angle);
        setR(radius);
    }

    virtual void update() {}; // derived classes will override this function

    void draw(RenderWindow &app) {
        anim.sprite.setPosition(getX(), getY());
        anim.sprite.setRotation(getAngle() + 90);
        app.draw(anim.sprite);

        CircleShape circle(getR());
        circle.setFillColor(Color(255, 0, 0, 170));
        circle.setPosition(getX(), getY());
        circle.setOrigin(getR(), getR());
        //app.draw(circle);
    }

    virtual ~Entity() {};

    // getters
    float getX() const { return m_x; }
    float getY() const { return m_y; }
    float getDx() const { return m_dx; }
    float getDy() const { return m_dy; }
    float getR() const { return m_R; }
    float getAngle() const { return m_angle; }
    float getLife() const { return m_life; }
    std::string getName() const { return m_name; }
    // setters
    void setX(const float x) { m_x = x; }
    void setY(const float y) { m_y = y; }
    void setDx(const float dx) { m_dx = dx; }
    void setDy(const float dy) { m_dy = dy; }
    void setR(const float R) { m_R = R; }
    void setAngle(const float angle) { m_angle = angle; }
    void setLife(const float life) { m_life = life; }
    void setName(const std::string name) { m_name = name; }

private:
    // private variables
    float m_x, m_y; // position of object on screen
    float m_dx, m_dy; // speed
    float m_R; // blast radius
    float m_angle; // orientation of object on screen
    bool m_life; // drawn or not drawn on the screen
    std::string m_name; // name of object
};


/*
 * class: asteroid
 * description: derived from Entity, for asteroid objects
 *              The asteroid moves at a random speed and in a random direction. If it is hit by a bullet, it will
 *              break into two smaller asteroids with the same properties. If it collides with the player, it will
 *              simply be destroyed.
 *              Asteroid will reappear on other side of screen if it falls off screen.
 */
class asteroid : public Entity // derived from Entity
{
public:
    asteroid() {
        setDx(rand() % 8 - 4); // speed in x direction is random number from -4 to 3, positive is right
        setDy(rand() % 8 - 4); // speed in y direction is random number from -4 to 3, positive is down
        setName("asteroid"); // specify what is the name of the object

        setAsteroidCount(getAsteroidCount() + 1);
    }

    void update() {
        setX(getX() + getDx()); // move x and y coordinates by whatever the speeds are
        setY(getY() + getDy());

        // W = width of screen, H = height of screen
        if (getX() > W) { setX(0); }
        if (getX() < 0) { setX(W); } // if x goes beyond the side of the screen, it will appear on the opposite side
        if (getY() > H) setY(0);
        if (getY() < 0) setY(H); // if y goes beyond the side of the screen, it will appear on the opposite side
    }

    static int getAsteroidCount() { return m_asteroidCount; }
    void setAsteroidCount(const int count) { m_asteroidCount = count; }

    ~asteroid() {
        // question: do I need clarify the destruction of anything?
        setAsteroidCount(getAsteroidCount() - 1);
    }

private:
    static int m_asteroidCount; // number of asteroids present in the game
};

int asteroid::m_asteroidCount = 0;


/*
 * class: bullet
 * description: derived from Entity, for bullet objects
 *              The bullet will continue at a constant speed in the same direction as the player points. The bullet
 *              will be destroyed when it hits an asteroid or ufo.
 *              Once a bullet falls off screen, it no longer exists.
 */
class bullet : public Entity {
public:
    bullet() {
        setName("bullet");
    }

    void update() {
        // given angle and magnitude, then increments are determined
        setDx(cos(getAngle() * DEGTORAD) * 6); // polar to rectangular coordinates
        setDy(sin(getAngle() * DEGTORAD) * 6); // integer is how fast the bullets are moving
        // angle+=rand()%6-3;
        setX(getX() + getDx()); // update position
        setY(getY() + getDy()); // update position

        if (getX() > W || getX() < 0 || getY() > H || getY() < 0) { setLife(0); } // if bullet goes off screen, remove bullet
    }
};


/*
 * class: player
 * description: derived from Entity, for player object
 *              There is only one player. At the start of the game, it will start in the middle of the screen.
 *              The player can move in any direction at a constant speed, and it can also pivot. The player
 *              will explode when it collides with an asteroid or a ufo. It will then reappear again in the
 *              middle of the screen.
 *              Player will reappear on other side of screen if it falls off screen.
 */
class player : public Entity {
public:
    player() {
        setName("player");
    }

    void update() {
        if (getThrust()) // if up arrow is pushed, acceleration
        {
            setDx(getDx() + cos(getAngle() * DEGTORAD) * 0.2); // increments speed (going in direction of ship)
            setDy(getDy() + sin(getAngle() * DEGTORAD) * 0.2);
        } else {
            setDx(getDx() * 0.99);
            setDy(getDy() * 0.99);
        }

        int maxSpeed = 15; // max speed
        float speed = sqrt(getDx() * getDx() + getDy() * getDy());
        if (speed > maxSpeed) // if speed is greater than max speed, throttle it down
        {
            setDx(getDx() * (maxSpeed / speed));
            setDy(getDy() * (maxSpeed / speed));
        }

        setX(getX() + getDx()); // update position
        setY(getY() + getDy()); // update position

        if (getX() > W) { setX(0); }
        if (getX() < 0) { setX(W); } // player goes off the screen and comes back on the other side
        if (getY() > H) setY(0);
        if (getY() < 0) setY(H);
    }

    // getters
    bool getThrust() const { return m_thrust; }
    //setters
    void setThrust(const bool thrust) { m_thrust = thrust; }

private:
    // private member variables
    bool m_thrust; // whether or not the player has pressed the up arrow
};


/*
 * class: ufo
 * description: derived from Entity, for ufo objects
 *              Ufo enters from either screen side and moves horizontally at a constant speed. The position
 *              where the ufo enters is random, as well as its direction. A sound is played while the ufo
 *              is present. It will stop if the ufo is hit by a bullet or collides with the player and explodes.
 *              Only one ufo is present at a time. It will take 20 seconds at the start of the game until the
 *              first ufo appears. Once it is destroyed, another one will appear in 20 seconds.
 *              Ufo will reappear on other side of screen if it falls off screen.
 */
class ufo : public Entity {
public:
    ufo() {
        setName("ufo");

        // ufo speed is set to go 7 in either x or y direction
        int zero_or_one = (rand() % 2);
        if (zero_or_one == 0){
            setDx(7);
        }
        else {
            setDx(-7);
        }
    }

    void update() {
        // update position
        setX(getX() + getDx()); // update position

        if (getX() > W) { setX(0); } // if ufo goes off-screen, come back on other side
        if (getX() < 0) { setX(W); }
    }
};


/*
 * function: isCollide
 * description: determines if the radius of two objects have come into contact
 * inputs: two Entity objects
 * outputs: boolean of true or false
 */
bool isCollide(Entity *a, Entity *b) {
    return (b->getX() - a->getX()) * (b->getX() - a->getX()) +
           (b->getY()- a->getY()) * (b->getY() - a->getY()) <
           (a->getR() + b->getR()) * (a->getR() + b->getR());
}


int main() {
    srand(time(0));

    RenderWindow app(VideoMode(W, H), "Asteroids!");
    app.setFramerateLimit(60);

    // images
    Texture t1, t2, t3, t4, t5, t6, t7, t8;
    t1.loadFromFile("images/spaceship.png");
    t2.loadFromFile("images/background.jpg");
    t3.loadFromFile("images/explosions/type_C.png");
    t4.loadFromFile("images/rock.png");
    t5.loadFromFile("images/fire_blue.png");
    t6.loadFromFile("images/rock_small.png");
    t7.loadFromFile("images/explosions/type_B.png");
    t8.loadFromFile("images/ufo.png"); // <a href="https://www.flaticon.com/free-icons/spaceship" title="spaceship icons">Spaceship icons created by juicy_fish - Flaticon</a>

    t1.setSmooth(true);
    t2.setSmooth(true);

    Sprite background(t2);

    Animation sExplosion(t3, 0, 0, 256, 256, 48, 0.5);
    Animation sRock(t4, 0, 0, 64, 64, 16, 0.2);
    Animation sRock_small(t6, 0, 0, 64, 64, 16, 0.2);
    Animation sBullet(t5, 0, 0, 32, 64, 16, 0.8);
    Animation sPlayer(t1, 40, 0, 40, 40, 1, 0);
    Animation sPlayer_go(t1, 40, 40, 40, 40, 1, 0);
    Animation sExplosion_ship(t7, 0, 0, 192, 192, 64, 0.5);
    Animation sUfo(t8, 0, 0, 50, 50, 1, 0); // fixUfo

    // ufo sound
    // "Alarming saw wave" by ProjectsU012, License: Creative Commons, https://freesound.org/s/340941/
    // https://creativecommons.org/licenses/by/4.0/
    // sound file was changed from .wav to .ogg
    sf::SoundBuffer bufferSpaceship;
    if (!bufferSpaceship.loadFromFile("sounds/spaceship.ogg")) {
        return EXIT_FAILURE;
    }
    sf::Sound spaceship;
    spaceship.setBuffer(bufferSpaceship);

    // explosion sound
    // "Explosion02" by jeremysykes, License: Creative Commons, https://freesound.org/s/341237/
    // https://creativecommons.org/licenses/by/4.0/
    // sound file was changed from .wav to .ogg
    sf::SoundBuffer bufferExplosion;
    if (!bufferExplosion.loadFromFile("sounds/explosion.ogg")) {
        return EXIT_FAILURE;
    }
    sf::Sound explosion;
    explosion.setBuffer(bufferExplosion);

    // bullet sound
    // "Laser gun" by soundslikewillem, License: Creative Commons, https://freesound.org/s/190707/
    // https://creativecommons.org/licenses/by/4.0/
    // sound file was changed from .wav to .ogg
    sf::SoundBuffer bufferBullet;
    if (!bufferBullet.loadFromFile("sounds/bullet.ogg")) {
        return EXIT_FAILURE;
    }
    sf::Sound bullett;
    bullett.setBuffer(bufferBullet);

    std::list<Entity *> entities; // empty list, main list of objects in program, list of Entity pointers

    // create new memory for asteroids; beginning of game
    for (int i = 0; i < 15; i++) {
        asteroid *a = new asteroid(); // create new asteroid object
        a->settings(sRock, rand() % W, rand() % H, rand() % 360, 25); // sprite for the asteroid
        entities.push_back(a); // add asteroid pointer to entity list
    }

    // wait 20 seconds for first ufo to be created
    time_t ufo_explosion = time(0);
    bool ufo_is_present = false;

    // create new memory for player
    player *p = new player(); // create new player object
    p->settings(sPlayer, 600, 400, 0, 20); // sprite for player
    entities.push_back(p); // add player to entity list


    /////main loop/////
    while (app.isOpen()) {
        Event event;
        while (app.pollEvent(event)) {
            if (event.type == Event::Closed) {
                app.close();
            }

            if (event.type == Event::KeyPressed) {
                if (event.key.code == Keyboard::Space) {
                    bullet *b = new bullet();
                    b->settings(sBullet, p->getX(), p->getY(), p->getAngle(), 10);
                    entities.push_back(b);
                    bullett.play();
                }
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::Right)) { p->setAngle(p->getAngle() + 3); }
        if (Keyboard::isKeyPressed(Keyboard::Left)) { p->setAngle(p->getAngle() - 3); }
        if (Keyboard::isKeyPressed(Keyboard::Up)) { p->setThrust(true); }
        else { p->setThrust(false); }


        for (auto a: entities) {
            for (auto b: entities) {

                // bullet hits asteroid
                // asteroid breaks up into two small ones
                if (a->getName() == "asteroid" && b->getName() == "bullet") {
                    if (isCollide(a, b)) {
                        a->setLife(false);
                        b->setLife(false);

                        Entity *e = new Entity();
                        e->settings(sExplosion, a->getX(), a->getY());
                        e->setName("explosion");
                        entities.push_back(e);
                        explosion.play();

                        for (int i = 0; i < 2; i++) {
                            if (a->getR() == 15) { continue; }
                            Entity *e = new asteroid();
                            e->settings(sRock_small, a->getX(), a->getY(), rand() % 360, 15);
                            entities.push_back(e);
                        }

                    }
                }

                // asteroid hits player
                // an explosion is created and player position is reset
                if (a->getName() == "player" && b->getName() == "asteroid") {
                    if (isCollide(a, b)) {
                        b->setLife(false);

                        Entity *e = new Entity();
                        e->settings(sExplosion_ship, a->getX(), a->getY());
                        e->setName("explosion");
                        entities.push_back(e);
                        explosion.play();

                        p->settings(sPlayer, W / 2, H / 2, 0, 20);
                        p->setDx(0);
                        p->setDy(0);
                    }
                }

                // bullet hits ufo
                // ufo explodes and a new one respawns at some random interval
                if (a->getName() == "ufo" && b->getName() == "bullet") {
                    if (isCollide(a, b)) {
                        ufo_explosion = time(0);
                        a->setLife(false);
                        b->setLife(false);
                        ufo_is_present = false;

                        Entity *e = new Entity();
                        e->settings(sExplosion_ship, a->getX(), a->getY());
                        e->setName("explosion");
                        entities.push_back(e);
                        explosion.play();
                    }
                }

                // player hits ufo
                // explosion is created and player is reset
                if (a->getName() == "player" && b->getName() == "ufo") {
                    if (isCollide(a, b)) {
                        ufo_explosion = time(0);
                        b->setLife(false);
                        ufo_is_present = false;

                        Entity *e = new Entity();
                        e->settings(sExplosion_ship, a->getX(), a->getY());
                        e->setName("explosion");
                        entities.push_back(e);
                        explosion.play();

                        p->settings(sPlayer, W / 2, H / 2, 0, 20);
                        p->setDx(0);
                        p->setDy(0);
                    }
                }
            }
        }

        // ufo respawns 20 seconds after explosion
        if (ufo_is_present == false and (time(0) - ufo_explosion == 20)) {
            ufo_is_present = true;
            ufo *u = new ufo();
            u->settings(sUfo, 0, rand() % H, 0, 25);
            entities.push_back(u);
        }
        // sound for ufo
        // sound will stop if ufo explodes
        if (ufo_is_present == true) {
            spaceship.play();
        }
        else if (ufo_is_present == false) {
            spaceship.stop();
        }

        if (p->getThrust()) { p->anim = sPlayer_go; }
        else { p->anim = sPlayer; }


        for (auto e: entities) {
            if (e->getName() == "explosion") {
                if (e->anim.isEnd()) { e->setLife(0); }
            }
        }

        /*
        // random spawning for asteroids
        if (rand() % 150 == 0) {
            asteroid *a = new asteroid();
            a->settings(sRock, 0, rand() % H, rand() % 360, 25);
            entities.push_back(a);
        }
        */

        // 15 more asteroids will spawn when the number of asteroids in the game reaches 0
        if (asteroid::getAsteroidCount() == 0) {
            for (int i = 0; i < 15; i++) {
                asteroid *a = new asteroid(); // create new asteroid object
                a->settings(sRock, rand() % W, rand() % H, rand() % 360, 25); // sprite for the asteroid
                entities.push_back(a); // add asteroid pointer to entity list
            }
        }

        for (auto i = entities.begin(); i != entities.end();) {
            Entity *e = *i;

            e->update();
            e->anim.update();

            // dynamic memory allocation (deleting memory)
            if (e->getLife() == false) {
                i = entities.erase(i);
                delete e;
            } else { i++; }
        }



        //////draw//////
        app.draw(background);

        for (auto i: entities) { // auto: figure out what is in container, go through all elements of container class Entity
            i->draw(app);
        } // update entity location

        app.display();
    }

    return 0;
}
