#include <iostream>
#include <unordered_map>
#include <array>
#include <algorithm>

#include "../headers/Pugilist.hpp"
#include "../headers/Knight.hpp"
#include "../headers/Mage.hpp"

enum class gameState {
    MainMenu,
    MainGame,
    DeathScreen
};


int main()
{
    constexpr size_t MAX_PLAYERS = 2;
    constexpr size_t width = 1920, height = 1080;
    const raylib::Vector2 player1Start{width/2 - 400, 800};
    const raylib::Vector2 player2Start{width/2 + 400, 800};

    std::vector<sas::Animation> animations;
    gameState state = gameState::MainMenu;

    std::array<sas::Character*, MAX_PLAYERS> players;

    std::string playerSelecting = "Player 1 choosing\n";

    raylib::Window window{width, height, "Game"};
    SetTargetFPS(60);
    window.SetPosition(GetMonitorPosition(0));

    raylib::Texture portraitKnight{"Assets/knightsas.png"};
    raylib::Texture portraitMage{"Assets/magesas.png"};
    raylib::Texture portraitFighter{"Assets/pugilistsas.png"};


    raylib::Image bowSprite("Assets/shadowFlameBow.png");
    sas::Weapon bow{sas::WeaponType::Ranged, 10, 600, "shadowflameBOW", bowSprite};
    raylib::Texture2D pugilistText{"Assets/pugilistmic.png"};

    raylib::Image swordSprite("Assets/shadowFlameBow.png");
    sas::Weapon sword{sas::WeaponType::Melee, 10, 10, "shadowflameBOW", swordSprite};
    raylib::Texture2D knightText{"Assets/knightmic.png"};

    raylib::Image rodSprite("Assets/shadowFlameBow.png");
    sas::Weapon rod{sas::WeaponType::Magic, 10, 10, "shadowflameBOW", rodSprite};
    raylib::Texture2D mageText{"Assets/magemic.png"};


    raylib::Texture2D backgroun("Assets/back.png");
    size_t currentPlayer = 0;

    sas::Animation PugilistAnimation;
    PugilistAnimation.addCustomAnimation([&](Vector2& startPos, const Vector2& endPos, float smoothness, float step)
    {
        DrawCircle(startPos.x + 60, startPos.y, 10, GREEN);
        switch (smoothness > 0)
        {
        case true:
            if(startPos.x >= endPos.x)
                return true;
            break;

        case false:
            if(startPos.x <= endPos.x)
                return true;
            break;
        }

        startPos.x = startPos.x + smoothness;        
        
        step = step + smoothness;

        return false;
    });

    sas::Animation Melee;
    Melee.addCustomAnimation([&](Vector2& startPos, const Vector2& endPos, float smoothness, float step)
    {
        DrawRectangle(startPos.x + 260, startPos.y, 50, 50, RED);
        DrawRectangle(startPos.x - 80, startPos.y, 50, 50, RED);
        switch (smoothness < 0)
        {
        case true:
            if(startPos.y >= endPos.y)
                return true;
            break;

        case false:
            if(startPos.y <= endPos.y)
                return true;
            break;
        }

        startPos.y = startPos.y - smoothness;        
        
        step = step + smoothness;

        return false;
    });

    sas::Animation MageAnimation;
    MageAnimation.addCustomAnimation([&](Vector2& startPos, const Vector2& endPos, float smoothness, float step)
    {
        DrawRing({startPos.x + 60, startPos.y}, 30, 60, 0, 360, 32, PURPLE);
        
        switch (smoothness > 0)
        {
        case true:
            if(startPos.x >= endPos.x)
                return true;
            break;

        case false:
            if(startPos.x <= endPos.x)
                return true;
            break;
        }

        startPos.x = startPos.x + smoothness;        
        
        step = step + smoothness;

        return false;
    });

    while (!window.ShouldClose())
    {
        float delta = GetFrameTime();
        BeginDrawing();
        window.ClearBackground(BLACK);


        if(IsKeyPressed(KEY_R))
        {
            state = gameState::MainMenu;
            currentPlayer = 0;
            playerSelecting = "Player 1 choosing\n";
        }
        

        if(state == gameState::MainMenu)
        {
            raylib::DrawText(playerSelecting, width/2 - 150 , 100, 20, RAYWHITE);

            constexpr size_t sizeIcons = 60;
            float dx = width/3 + 2 * sizeIcons, dy=height/3;
            DrawTexture(portraitFighter, dx, dy, WHITE);
            if(CheckCollisionPointRec(GetMousePosition(), Rectangle{dx, dy, sizeIcons, sizeIcons}) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                playerSelecting = "Player 2 choosing\n";
                players[currentPlayer] = new sas::Pugilist{100, 10, bow, currentPlayer == 1 ? player1Start : player2Start , pugilistText};
                players[currentPlayer]->addAnimation(PugilistAnimation);
                ++currentPlayer;
            }

            dx = dx + 2 * sizeIcons;
            DrawTexture(portraitKnight, dx, dy, WHITE);

            if(CheckCollisionPointRec(GetMousePosition(), Rectangle{dx, dy, sizeIcons, sizeIcons}) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                playerSelecting = "Player 2 choosing\n";
                players[currentPlayer] = new sas::Knight{100, 10, bow, currentPlayer == 1 ? player1Start : player2Start, knightText};
                players[currentPlayer]->addAnimation(Melee);
                ++currentPlayer;
            }


            dx = dx + 2 * sizeIcons;
            DrawTexture(portraitMage, dx, dy, WHITE);

            if(CheckCollisionPointRec(GetMousePosition(), Rectangle{dx, dy, sizeIcons, sizeIcons}) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
            {
                playerSelecting = "Player 2 choosing\n";
                players[currentPlayer] = new sas::Mage{100, 10, bow, currentPlayer == 1 ? player1Start : player2Start , mageText};
                players[currentPlayer]->addAnimation(MageAnimation);
                ++currentPlayer;
            }

            if(currentPlayer == 2)
                state = gameState::MainGame;

                
        }else if(state == gameState::MainGame)
        {

            backgroun.Draw();


            DrawRectangle(10, 10, 2 * players[0]->getHealth(), 20, RED);
            DrawRectangleLines(10, 10, 2 * players[0]->getMaxHealth(), 20, RAYWHITE);

            size_t position = 2 * players[1]->getHealth();

            DrawRectangle(width - position, 10, position, 20, RED);

            position = 2 * players[1]->getMaxHealth();
            DrawRectangleLines(width - position, 10, position, 20, RAYWHITE);
            DrawLine(0, 900, 1920, 900, RAYWHITE);

            if(IsKeyPressed(KEY_A) || IsKeyDown(KEY_A))
            {
                players[0]->moveLeft(delta);
            }

            if(IsKeyPressed(KEY_D) || IsKeyDown(KEY_D))
            {
                players[0]->moveRight(delta);
            }

            if(IsKeyPressed(KEY_LEFT) || IsKeyDown(KEY_LEFT))
            {
                players[1]->moveLeft(delta);
            }

            if(IsKeyPressed(KEY_RIGHT) || IsKeyDown(KEY_RIGHT))
            {
                players[1]->moveRight(delta);
            }

            if(IsKeyPressed(KEY_F))
            {
                if (auto animation = players[0]->attack(*players[1]); animation.has_value())
                {
                    animations.push_back(animation.value());
                }

            }
            
            if(IsKeyPressed(KEY_SPACE))
            {
                if (auto animation = players[1]->attack(*players[0]); animation.has_value()) 
                {
                    animations.push_back(animation.value());
                }
            }

            
            players[0]->getSprite().Draw(players[0]->getPosition());
            players[1]->getSprite().Draw(players[1]->getPosition());

            for (auto& element : animations)
            {
                element.draw();
            }

            animations.erase(std::remove_if(animations.begin(), animations.end(), [](const sas::Animation &obj){
                return obj.getFinishStatus();}), animations.end());

            if(players[0]->getHealth() <= 0 || players[1]->getHealth() <=0)
            {
                state = gameState::DeathScreen;
            }

        }else
        {
            DrawText("Press R to restart", width/2 - 300, height/2 - 20, 60, RAYWHITE);
        }
        EndDrawing();

    }

    delete players[0];
    delete players[1];


}
