#include <SDL.h>
#include <stdio.h>

int main()
{
    // Inicializa o SDL
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
        fprintf(stderr, "Erro ao inicializar o SDL: %s\n", SDL_GetError());
        return 1;
    }
    SDL_SetHint(SDL_HINT_RENDER_DRIVER, "opengl");

    // Cria uma janela
    SDL_Window *window = SDL_CreateWindow("Exemplo SDL2", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window)
    {
        fprintf(stderr, "Erro ao criar a janela: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // Cria um renderer
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        fprintf(stderr, "Erro ao criar o renderer: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // Define a cor de fundo para azul (RGB: 0, 0, 255)
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);

    // Limpa a tela com a cor de fundo
    SDL_RenderClear(renderer);

    // Atualiza a tela
    SDL_RenderPresent(renderer);

    // Aguarda 5 segundos antes de fechar a janela
    SDL_Delay(5000);

    // Libera recursos e fecha o SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}