#include "Engine.h"

void pixel(SDL_Renderer *renderer, int x, int y, int c) // draw a pixel at x/y with rgb
{
    int rgb[3];
    if (c == 0)
    {
        rgb[0] = 255;
        rgb[1] = 255;
        rgb[2] = 0;
    } // Yellow
    if (c == 1)
    {
        rgb[0] = 160;
        rgb[1] = 160;
        rgb[2] = 0;
    } // Yellow darker
    if (c == 2)
    {
        rgb[0] = 0;
        rgb[1] = 255;
        rgb[2] = 0;
    } // Green
    if (c == 3)
    {
        rgb[0] = 0;
        rgb[1] = 160;
        rgb[2] = 0;
    } // Green darker
    if (c == 4)
    {
        rgb[0] = 0;
        rgb[1] = 255;
        rgb[2] = 255;
    } // Cyan
    if (c == 5)
    {
        rgb[0] = 0;
        rgb[1] = 160;
        rgb[2] = 160;
    } // Cyan darker
    if (c == 6)
    {
        rgb[0] = 160;
        rgb[1] = 100;
        rgb[2] = 0;
    } // brown
    if (c == 7)
    {
        rgb[0] = 110;
        rgb[1] = 50;
        rgb[2] = 0;
    } // brown darker
    if (c == 8)
    {
        rgb[0] = 0;
        rgb[1] = 60;
        rgb[2] = 130;
    } // background

    SDL_Rect rect = {x, y, pixelScale, pixelScale}; // X, Y, largura, altura
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Cor preta
    SDL_RenderFillRect(renderer, &rect);
    // glColor3ub(rgb[0],rgb[1],rgb[2]);
    // glBegin(GL_POINTS);
    // glVertex2i(x*pixelScale+2,y*pixelScale+2);
    // glEnd();
}

static void __render(t_camera *this, SDL_Renderer *renderer)
{
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Cor branca
    SDL_RenderClear(renderer);
    int wx[4], wy[4], wz[4];
    float cs = this->math.cos[this->angle];
    float sn = this->math.sin[this->angle];

    int x1 = 40 - this->position.x, y1 = 10 - this->position.y;
    int x2 = 40 - this->position.x, y2 = 290 - this->position.y;

    // world x position
    wx[0] = x1 * cs - y1 * sn;
    wx[1] = x2 * cs + y2 * cs;

    // world Y position
    wy[0] = y1 * cs + x1 * sn;
    wy[1] = y2 * cs + x2 * sn;

    // world Z position
    wz[0] = 0 - this->position.z + ((this->look * wy[0]) / 32.0);
    wz[1] = 0 - this->position.z + ((this->look * wy[1]) / 32.0);

    // screen X, screen Y
    wx[0] = wx[0] * 200 / wy[0] + SW2;
    wy[0] = wz[0] * 200 / wy[0] + SH2;
    wx[1] = wx[1] * 200 / wy[1] + SW2;
    wy[1] = wz[1] * 200 / wy[1] + SH2;

    // draw points
    if (wx[0] > 0 && wx[0] < SW && wy[0] > 0 && wy[0] < SH)
        pixel(renderer, wx[0], wy[0], 0);
    if (wx[1] > 0 && wx[1] < SW && wy[1] > 0 && wy[1] < SH)
        pixel(renderer, wx[1], wy[1], 0);
    // draw player
    pixel(renderer, this->position.x, this->position.x, 0);
    // SDL_Delay(1000);
}

static void __key(t_camera *this, bool *key, SDL_Event *event)
{
    if (event->type == SDL_KEYDOWN)
    {
        if (event->key.keysym.sym == SDLK_w)
        {
            this->w = 1;
        }
        if (event->key.keysym.sym == SDLK_s)
        {
            this->s = 1;
        }
        if (event->key.keysym.sym == SDLK_a)
        {
            this->a = 1;
        }
        if (event->key.keysym.sym == SDLK_d)
        {
            this->d = 1;
        }
        if (event->key.keysym.sym == SDLK_LSHIFT)
        {
            this->sl = 1;
        }
        if (event->key.keysym.sym == SDLK_SPACE)
        {
            this->sr = 1;
        }
        if (event->key.keysym.sym == SDLK_LCTRL)
        {
            this->m = 1;
        }
    }
    if (event->type == SDL_KEYUP)
    {
        if (event->key.keysym.sym == SDLK_w)
        {
            this->w = 0;
        }
        if (event->key.keysym.sym == SDLK_s)
        {
            this->s = 0;
        }
        if (event->key.keysym.sym == SDLK_a)
        {
            this->a = 0;
        }
        if (event->key.keysym.sym == SDLK_d)
        {
            this->d = 0;
        }
        if (event->key.keysym.sym == SDLK_LSHIFT)
        {
            this->sl = 0;
        }
        if (event->key.keysym.sym == SDLK_SPACE)
        {
            this->sr = 0;
        }
        if (event->key.keysym.sym == SDLK_LCTRL)
        {
            this->m = 0;
        }
    }
    // move up, down, left, right
    if (this->a == 1 && this->m == 0)
    {
        printf("left\n");
        this->angle -= 4;
        if (this->angle < 0)
            this->angle += 360;
    }
    if (this->d == 1 && this->m == 0)
    {
        printf("right\n");
        this->angle += 4;
        if (this->angle > 359)
            this->angle -= 360;
    }
    int dx = this->math.cos[this->angle] * 10.0f;
    int dy = this->math.sin[this->angle] * 10.0f;
    if (this->w == 1 && this->m == 0)
    {
        printf("up\n");
        this->position.x += dx;
        this->position.y += dy;
    }
    if (this->s == 1 && this->m == 0)
    {
        printf("down\n");
        this->position.x -= dx;
        this->position.y -= dy;
    }
    // move up, down, look up, look down
    if (this->a == 1 && this->m == 1)
    {
        printf("look up\n");
        this->look -= 1;
    }
    if (this->d == 1 && this->m == 1)
    {
        printf("look down\n");
        this->look += 1;
    }
    if (this->w == 1 && this->m == 1)
    {
        printf("move up\n");
        this->position.z += 4;
    }
    if (this->s == 1 && this->m == 1)
    {
        printf("move down\n");
        this->position.z -= 4;
    }
    printf("angle: %d look: %d x: %f y: %f z: %f\n", this->angle, this->look, this->position.x, this->position.y, this->position.z);
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
    camera->position.x = 70;
    camera->position.y = -110;
    camera->position.z = 0;
    camera->angle = 0;
    camera->look = 0;
    int x = 0;
    while (x < 360)
    {
        camera->math.cos[x] = cos(x / 180.0 * M_PI);
        camera->math.sin[x] = sin(x / 180.0 * M_PI);
        x++;
    }
    return (camera);
}