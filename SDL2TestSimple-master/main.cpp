
#include<SDL2/SDL.h>
#include<SDL2/SDL_image.h>
#include<iostream>

SDL_Window* window;//ventana
SDL_Renderer* renderer;//podennnmos tener una imagen por medio de un rectangulo que adentro contiene una textura
SDL_Event Event;//ya puede ser sonido teclado mouse
SDL_Texture *background,*character, *character2;//para el personaje
SDL_Rect rect_background,rect_character, rect_character2;//para el   background



int main( int argc, char* args[] )
{
    //Init SDL
    if(SDL_Init(SDL_INIT_EVERYTHING) < 0)
    {
        return 10;
    }
    //Creates a SDL Window Define titulo tamaño
    if((window = SDL_CreateWindow("Mi titulo", 100, 100, 500/*WIDTH*/, 250/*HEIGHT*/, SDL_WINDOW_RESIZABLE | SDL_RENDERER_PRESENTVSYNC)) == NULL)
    {
        return 20;
    }
    //SDL Renderer
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED );
    if (renderer == NULL)
    {
        std::cout << SDL_GetError() << std::endl;
        return 30;
    }

    //Init textures
    int w=0,h=0;
    background = IMG_LoadTexture(renderer,"fondo.png");
    //SDL_QueryTexture(background, NULL, NULL, &w, &h);
    rect_background.x = 0;
    rect_background.y = 0;
    rect_background.w = 500;
    rect_background.h = 250;

    character = IMG_LoadTexture(renderer, "personaje.png");
    //SDL_QueryTexture(character, NULL, NULL, &w, &h);
    rect_character.x = 0;
    rect_character.y = 100;
    rect_character.w = 32;
    rect_character.h = 32;

    character2 = IMG_LoadTexture(renderer, "super.png");
    //SDL_QueryTexture(character2, NULL, NULL, &w, &h);
    rect_character2.x = 300;
    rect_character2.y = 100;
    rect_character2.w = 32;
    rect_character2.h = 32;

    //Main Loop
    while(true)
    {
        while(SDL_PollEvent(&Event))
        {

            if(Event.type == SDL_QUIT)
            {
                return 0;
            }
            if(Event.type == SDL_KEYDOWN)
            {
                if(Event.key.keysym.sym == SDLK_d)
                    rect_character.x+=15;
                if(Event.key.keysym.sym == SDLK_s)
                    rect_character.y+=15;
                if(Event.key.keysym.sym == SDLK_a)
                    rect_character.x-=15;
                if(Event.key.keysym.sym == SDLK_w)
                    rect_character.y-=15;
                if(Event.key.keysym.sym == SDLK_RIGHT)
                    rect_character2.x+=15;
                if(Event.key.keysym.sym == SDLK_LEFT)
                    rect_character2.x-=15;
                if(Event.key.keysym.sym == SDLK_UP)
                    rect_character2.y-=15;
                if(Event.key.keysym.sym == SDLK_DOWN)
                    rect_character2.y+=15;
            }
        }

        SDL_RenderCopy(renderer, background, NULL, &rect_background);
        SDL_RenderCopy(renderer, character, NULL, &rect_character);
        SDL_RenderCopy(renderer, character2, NULL, &rect_character2);
        SDL_RenderPresent(renderer);
    }

	return 0;
}
