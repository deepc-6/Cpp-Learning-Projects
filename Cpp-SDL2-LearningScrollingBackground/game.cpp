#include"game.h"

game::game()
{
    window = NULL;
    Running = true;
    background = NULL;
    car = NULL;
    building1 = NULL;
    building2 = NULL;
    building3 = NULL;
    ground = NULL;
    position=0;
}

int game::OnExecute() {
    if(OnInit() == false) {
        return -1;
    }
    if(LoadContent() == false)
    {
        return -1;
    }


    while(Running) {
        while(SDL_PollEvent(&Event)) {
            OnEvent(&Event);
        }

        OnLoop();
        OnRender();
    }

    OnCleanup();

    return 0;
}

int main(int argc, char* argv[]) {
    game theGame;

    return theGame.OnExecute();
}
