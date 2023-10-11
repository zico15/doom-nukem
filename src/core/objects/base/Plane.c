
#include "Engine.h"



static void __render(t_plane *this, SDL_Renderer *renderer)
{

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // Cor branca
    SDL_RenderClear(renderer);

    // Desenhe um retângulo (plano) na tela baseado no plano definido
    SDL_Rect rect = {100, 100, 400, 200};           // Coordenadas X, Y, largura, altura
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Cor preta

    // Verifique se o retângulo está na frente ou atrás do plano
    float result = this->a * rect.x + this->b * rect.y + this->c * 0 + this->d;

    // if (result >= 0)
    // {
    // O retângulo está à frente do plano, então desenhe-o
    SDL_RenderFillRect(renderer, &rect);
    // }
}

t_plane *new_plane(float a, float b, float c, float d)
{
    t_plane *p;

    p = (t_plane *)new_object(sizeof(t_plane));
    p->a = a;
    p->b = b;
    p->c = c;
    p->d = d;
    p->render = __render;
    return (p);
}