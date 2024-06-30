#include <SDL3/SDL.h>
#include <SDL3/SDL_events.h>
#include <SDL3/SDL_init.h>
#include <SDL3/SDL_keycode.h>
#include <SDL3/SDL_oldnames.h>
#include <SDL3/SDL_rect.h>
#include <SDL3/SDL_render.h>
#include <SDL3/SDL_video.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL3_image/SDL_image.h>

const int WIN_WIDTH = 282;
const int WIN_HEIGHT = 400;

bool is_running = true;
SDL_Window *window;
SDL_Renderer *renderer;
SDL_Texture *main_window_tex;
SDL_Texture *button_load_tex;
SDL_Texture *button_save_tex;
SDL_Texture *slider_tex;
SDL_Texture *close_tex;

typedef struct 
{
    int x;
    int y;
}Point;

void setup();
void input();
void update();
void render();
void cleanup();

void load_ui();
void render_ui();


int main(void)
{
    setup();
    // start infinite loop
    while (is_running)
    {

        input();
        update();
        render();
    }
    // end infinite loop
    cleanup();
    exit(EXIT_SUCCESS);
}
void setup()
{
    // Inizializzo sottosistemi eventi e video
    if (SDL_InitSubSystem(SDL_INIT_EVENTS | SDL_INIT_VIDEO) != 0)
    {
        fprintf(stderr, "Errore di inizializzazione SDL_InitSubSystem : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    // inizializzo finestra
    window = SDL_CreateWindow("ESC , q o pulsante di chiusura finestra per chiudere", 
    WIN_WIDTH, WIN_HEIGHT, SDL_WINDOW_BORDERLESS | SDL_WINDOW_HIGH_PIXEL_DENSITY | SDL_WINDOW_TRANSPARENT);

    if (window == NULL)
    {
        fprintf(stderr, "Errore di inizializzazione SDL_CreateWindow : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    // inizializzo renderer
    renderer = SDL_CreateRenderer(window, NULL);
    if (renderer == NULL)
    {
        fprintf(stderr, "Errore di inizializzazione SDL_CreateRenderer : %s", SDL_GetError());
        exit(EXIT_FAILURE);
    }
    load_ui();
    
}
void input()
{
    SDL_Event event;
    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
        case SDL_EVENT_QUIT:
            is_running = false;
            break;
        case SDL_EVENT_KEY_DOWN:
            switch (event.key.key)
            {
            case SDLK_ESCAPE:
            case SDLK_q:
                is_running = false;
                break;
            }
            break;
            case SDL_EVENT_MOUSE_BUTTON_DOWN:
                // const SDL_Point mouse_pos = {.x = event.button.x, .y = event.button.y};
                SDL_Point mouse_pos = {.x = event.button.x, .y = event.button.y};
                // SDL_PointInRect(&mouse_pos, const SDL_Rect *r);
            break;
        }
    }
}
void update()
{
    if (is_running)
    {
    }
}
void render()
{
    if (is_running)
    {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);
        render_ui();
        
        SDL_RenderPresent(renderer);
    }
}
void cleanup()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}
void load_ui()
{
    main_window_tex =IMG_LoadTexture(renderer, "Assets/Main window.png");
    if(main_window_tex == NULL)
    {
        fprintf(stderr, "Errore di inizializzazione IMG_LoadTexture main window :  %s", SDL_GetError());
        exit(EXIT_FAILURE);

    }
    button_load_tex =IMG_LoadTexture(renderer, "Assets/button_embossed.png");
    if(main_window_tex == NULL)
    {
        fprintf(stderr, "Errore di inizializzazione IMG_LoadTexture  button embossed :  %s", SDL_GetError());
        exit(EXIT_FAILURE);

    }
    button_save_tex =IMG_LoadTexture(renderer, "Assets/button_embossed.png");
    if(button_save_tex == NULL)
    {
        fprintf(stderr, "Errore di inizializzazione IMG_LoadTexture  button embossed :  %s", SDL_GetError());
        exit(EXIT_FAILURE);

    }
    slider_tex =IMG_LoadTexture(renderer, "Assets/slider.png");
    if(slider_tex == NULL)
    {
        fprintf(stderr, "Errore di inizializzazione IMG_LoadTexture  slider :  %s", SDL_GetError());
        exit(EXIT_FAILURE);

    }
    close_tex =IMG_LoadTexture(renderer, "Assets/close.png");
    if(slider_tex == NULL)
    {
        fprintf(stderr, "Errore di inizializzazione IMG_LoadTexture  close :  %s", SDL_GetError());
        exit(EXIT_FAILURE);

    }
}
void render_ui()
{
    SDL_FRect main_src_rect = {.x = 0, .y = 0, .w = 282, .h = 400};
    SDL_RenderTexture(renderer, main_window_tex, &main_src_rect,NULL);
    SDL_FRect button_load_dst_rect = {.x = 47, .y = 361, .w = 90, .h = 24};
    SDL_RenderTexture(renderer, button_load_tex, NULL,&button_load_dst_rect);
    SDL_FRect button_save_dst_rect = {.x = 148, .y = 361, .w = 90, .h = 24};
    SDL_RenderTexture(renderer, button_save_tex, NULL,&button_save_dst_rect);
    SDL_FRect slider1_dst_rect = {.x = 41, .y = 23, .w = 15, .h = 11};
    SDL_RenderTexture(renderer, button_save_tex, NULL,&slider1_dst_rect);
    SDL_FRect slider2_dst_rect = {.x = 41, .y = 52, .w = 15, .h = 11};
    SDL_RenderTexture(renderer, button_save_tex, NULL,&slider2_dst_rect);
    SDL_FRect slider3_dst_rect = {.x = 41, .y = 83, .w = 15, .h = 11};
    SDL_RenderTexture(renderer, button_save_tex, NULL,&slider3_dst_rect);
    SDL_FRect slider4_dst_rect = {.x = 41, .y = 145, .w = 15, .h = 11};
    SDL_RenderTexture(renderer, button_save_tex, NULL,&slider4_dst_rect);
    SDL_FRect slider5_dst_rect = {.x = 41, .y = 172, .w = 15, .h = 11};
    SDL_RenderTexture(renderer, button_save_tex, NULL,&slider5_dst_rect);
    SDL_FRect close_dst_rect = {.x = 245, .y = 8, .w = 19, .h = 17};
    SDL_RenderTexture(renderer, button_save_tex, NULL,&close_dst_rect);
}