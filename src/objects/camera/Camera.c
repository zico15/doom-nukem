#include "Engine.h"

static void move(t_camera *this, double speed, double strafe)
{
    this->position.x += speed * cos(this->angle + strafe);
    this->position.y += speed * sin(this->angle + strafe);
}

static void __key(t_camera *this, bool *key, SDL_Event *event)
{
    printf("key: %i\n", event->key.keysym.sym == SDLK_LEFT);
    bool strafe = event->key.keysym.sym == SDLK_LCTRL;
    if (strafe && event->key.keysym.sym == SDLK_LEFT)
        move(this, 2.0f * this->speed, toRadians(90));
    else if (strafe && event->key.keysym.sym == SDLK_RIGHT)
        move(this, 2.0f * this->speed, toRadians(-90));

    if (!strafe && event->key.keysym.sym == SDLK_LEFT)
        this->angle += this->angSpeed;
    else if (!strafe && event->key.keysym.sym == SDLK_RIGHT)
        this->angle -= this->angSpeed;

    if (event->key.keysym.sym == SDLK_w)
        move(this, this->speed, 0.0);
    else if (event->key.keysym.sym == SDLK_s)
        move(this, -this->speed, 0.0);
    else if (event->key.keysym.sym == SDLK_d)
        move(this, this->speed, toRadians(90));
    else if (event->key.keysym.sym == SDLK_a)
        move(this, this->speed, toRadians(-90));
}

static void __render(t_camera *this, SDL_Renderer *renderer)
{

    // __key(this, NULL, &engine()->sdl->event);
    //   g.setColor(new Color((int) (Integer.MAX_VALUE * Math.random())));

    //     int px = (int) (MAP_SCALE * x);
    //     int py = (int) (MAP_SCALE * y);
    //     g.fillOval(px - 2, py - 2, 4, 4);

    //     int dx = (int) (10 * Math.cos(angle));
    //     int dy = (int) (10 * Math.sin(angle));
    //     g.drawLine(px, py, px + dx, py + dy);
    // convert para sdl2
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    int px = (int)(MAP_SCALE * this->position.x);
    int py = (int)(MAP_SCALE * this->position.y);
    SDL_Rect rec = {px - 2, py - 2, 4, 4};
    SDL_RenderDrawRect(renderer, &rec);
    int dx = (int)(10 * cos(this->angle));
    int dy = (int)(10 * sin(this->angle));
    SDL_RenderDrawLine(renderer, px, py, px + dx, py + dy);

    // fundo branco
}

t_vector2 getDirection(t_camera *this)
{
    double dx = cos(this->angle);
    double dy = sin(this->angle);
    this->direction.x = dx;
    this->direction.y = dy;
    return this->direction;
}

t_camera *new_camera()
{
    t_camera *camera;

    camera = (t_camera *)new_object(sizeof(t_camera));
    camera->render = __render;
    camera->key = __key;
    camera->rect.x = 0;
    camera->rect.y = 0;
    camera->rect.w = 640;
    camera->rect.h = 480;
    camera->position.x = (short)engine()->sdl->width / 2;
    camera->position.y = (short)engine()->sdl->height / 2;
    printf("camera->position.x: %f\n", camera->position.x);
    printf("camera->position.y: %f\n", camera->position.y);
    camera->angle = toRadians(0);
    camera->angSpeed = 0.05;
    camera->speed = 3.0;
    return (camera);
}