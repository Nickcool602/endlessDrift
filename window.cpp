#include "raylib.h"
#include <random>

int main() {

    int screenWidth = 2600;
    int screenHeight = 600;

    int lane = 2;

    double speedMod = 2;

    int score = 0;

    bool started = false;
    bool startScreen = true;

    bool dead = false;

    double timeOfStart = 0;

    int scoreWOTime = 0;

    int difficulty = 1;
    int intendedDiff = 1;

    double timeSinceClear = 0;
    double timeOfLastClear = 0;

    double fps = 0;

    bool paused = false;

    double pausedTime = 0;

    bool skip1 = false;
    bool skip2 = false;
    bool skip3 = false;
    bool skip4 = false;
    bool skip5 = false;
    bool skip6 = false;
    bool skip7 = false;
    bool skip8 = false;
    bool skip9 = false;
    bool skip10 = false;
    bool skip11 = false;
    bool skip12 = false;
    bool skip13 = false;

    bool firstClear = true;

    bool lockedLane = false;
    int lockedLaneNum = 1;

    double timeOfCheck = 0;

    InitWindow(screenWidth, screenHeight, "E N D L E S S  D R I F T");

    double startTime = GetTime();
    double currentTime = 0.0;

    Texture2D playerImage = LoadTexture("images/player.png");
    float playerX = 300;
    float playerY = 300;
    Vector2 player = {playerX, playerY};

    Texture2D fireImage = LoadTexture("images/fire.png");
    float fireX = 0;
    float fireY = 0;
    Vector2 fire = {fireX, fireY};

    Texture2D meteor1Image = LoadTexture("images/meteor.png");
    float meteor1X = 3000;
    float meteor1Y = 280;
    Vector2 meteor1 = {meteor1X, meteor1Y};
    int meteor1Lane = GetRandomValue(1,3);

    Texture2D meteor2Image = LoadTexture("images/meteor.png");
    float meteor2X = 3000;
    float meteor2Y = 280;
    Vector2 meteor2 = {meteor2X, meteor2Y};
    int meteor2Lane = GetRandomValue(1,3);

    Texture2D meteor3Image = LoadTexture("images/meteor.png");
    float meteor3X = 3000;
    float meteor3Y = 280;
    Vector2 meteor3 = {meteor3X, meteor3Y};
    int meteor3Lane = GetRandomValue(1,3);

    Texture2D meteor4Image = LoadTexture("images/meteor.png");
    float meteor4X = 3000;
    float meteor4Y = 280;
    Vector2 meteor4 = {meteor4X, meteor4Y};
    int meteor4Lane = GetRandomValue(1,3);

    Texture2D meteor5Image = LoadTexture("images/meteor.png");
    float meteor5X = 3000;
    float meteor5Y = 280;
    Vector2 meteor5 = {meteor5X, meteor5Y};
    int meteor5Lane = GetRandomValue(1,3);

    Texture2D meteor6Image = LoadTexture("images/meteor.png");
    float meteor6X = 3000;
    float meteor6Y = 280;
    Vector2 meteor6 = {meteor6X, meteor6Y};
    int meteor6Lane = GetRandomValue(1,3);

    Texture2D bgImage = LoadTexture("images/bg1.png");
    float bgX = 0;
    float bgY = 0;
    Vector2 bg = {bgX, bgY};

    Texture2D powerupImagePlaceholder = LoadTexture("images/powerup.png");
    Texture2D powerupImage1 = LoadTexture("images/powerup1.png");
    Texture2D powerupImage2 = LoadTexture("images/powerup2.png");
    Texture2D powerupImage3 = LoadTexture("images/powerup3.png");
    Texture2D powerupImage4 = LoadTexture("images/powerup4.png");
    Texture2D powerupImage5 = LoadTexture("images/powerup5.png");
    Texture2D powerupImage6 = LoadTexture("images/powerup6.png");
    Texture2D powerupImage7 = LoadTexture("images/powerup7.png");
    Texture2D powerupImage8 = LoadTexture("images/powerup8.png");
    Texture2D powerupImage9 = LoadTexture("images/powerup9.png");
    
    float powerupX = 2700;
    float powerupY = 300;
    Vector2 powerup = {powerupX, powerupY};
    int powerupLane = 2;
    int powerupNum = GetRandomValue(1,9);

    Texture2D coinImage = LoadTexture("images/coin.png");
    float coinX = 3000;
    float coinY = 300;
    Vector2 coin = {coinX, coinY};
    int coinLane = 1;

    InitAudioDevice();
    Music bgAmb = LoadMusicStream("sounds/static.wav");
    PlayMusicStream(bgAmb);

    Sound clickSound = LoadSound("sounds/e.wav"); //1

    Sound topSound = LoadSound("sounds/topLane.wav"); //1
    Sound middleSound = LoadSound("sounds/middleLane.wav"); //1
    Sound bottomSound = LoadSound("sounds/bottomLane.wav"); //1

    Sound laneClearSound = LoadSound("sounds/laneClear.wav"); //1

    Sound lockedLaneSound = LoadSound("sounds/lockedLane.wav"); //1

    Sound powerupSound1 = LoadSound("sounds/powerup1.wav"); //1
    Sound powerupSound2 = LoadSound("sounds/powerup2.wav"); //1
    Sound powerupSound3 = LoadSound("sounds/powerup3.wav"); //1
    Sound powerupSound4 = LoadSound("sounds/powerup4.wav"); //1
    Sound powerupSound5 = LoadSound("sounds/powerup5.wav"); //1
    Sound powerupSound6 = LoadSound("sounds/powerup6.wav"); //1
    Sound powerupSound7 = LoadSound("sounds/powerup7.wav"); //1
    Sound powerupSound8 = LoadSound("sounds/powerup8.wav"); //1
    Sound powerupSound9 = LoadSound("sounds/powerup9.wav"); //1

    Sound coinPickup = LoadSound("sounds/coinPickup.wav"); //1

    Sound lossSound = LoadSound("sounds/loss.wav"); //1

    SetTargetFPS(50);
    while (!WindowShouldClose()) {

        UpdateMusicStream(bgAmb);

        if((currentTime - timeOfCheck) >= 30) {{
            if(difficulty < intendedDiff) {
                difficulty += 1;
                timeOfCheck = currentTime;
            }
        }}

        if(!paused) {
            if((lockedLane) && (lockedLaneNum == 1)) {
                if(IsKeyPressed(KEY_Q)) {
                    PlaySound(lockedLaneSound);
                }
                if(IsKeyPressed(KEY_ONE)) {
                    PlaySound(lockedLaneSound);
                }
                if((lane == 2) && (IsKeyPressed(KEY_W))) {
                    PlaySound(lockedLaneSound);
                }
                if((lane == 3) && (IsKeyPressed(KEY_S))) {
                    PlaySound(lockedLaneSound);
                }
            }
            if((lockedLane) && (lockedLaneNum == 2)) {
                if(IsKeyPressed(KEY_A)) {
                    PlaySound(lockedLaneSound);
                }
                if(IsKeyPressed(KEY_TWO)) {
                    PlaySound(lockedLaneSound);
                }
                if((lane == 3) && (IsKeyPressed(KEY_W))) {
                    PlaySound(lockedLaneSound);
                }
                if((lane == 1) && (IsKeyPressed(KEY_S))) {
                    PlaySound(lockedLaneSound);
                }
            }
            if((lockedLane) && (lockedLaneNum == 3)) {
                if(IsKeyPressed(KEY_Z)) {
                    PlaySound(lockedLaneSound);
                }
                if(IsKeyPressed(KEY_THREE)) {
                    PlaySound(lockedLaneSound);
                }
                if((lane == 1) && (IsKeyPressed(KEY_W))) {
                    PlaySound(lockedLaneSound);
                }
                if((lane == 2) && (IsKeyPressed(KEY_S))) {
                    PlaySound(lockedLaneSound);
                }
            }

            if(IsKeyPressed(KEY_Q) && !((lockedLane) && (lockedLaneNum == 1))) {
                player.y = 150;
                lane = 1;
                PlaySound(topSound);
            }
            else if(IsKeyPressed(KEY_A) && !((lockedLane) && (lockedLaneNum == 2))) {
                player.y = 300;
                lane = 2;
                PlaySound(middleSound);
            }
            else if(IsKeyPressed(KEY_Z) && !((lockedLane) && (lockedLaneNum == 3))) {
                player.y = 450;
                lane = 3;
                PlaySound(bottomSound);
            }
            if(IsKeyPressed(KEY_ONE) && !((lockedLane) && (lockedLaneNum == 1))) {
                player.y = 150;
                lane = 1;
                PlaySound(topSound);
            }
            else if(IsKeyPressed(KEY_TWO) && !((lockedLane) && (lockedLaneNum == 2))) {
                player.y = 300;
                lane = 2;
                PlaySound(middleSound);
            }
            else if(IsKeyPressed(KEY_THREE) && !((lockedLane) && (lockedLaneNum == 3))) {
                player.y = 450;
                lane = 3;
                PlaySound(bottomSound);
            }
            else if(IsKeyPressed(KEY_W)) {
                if((lane == 1) && !((lockedLane) && (lockedLaneNum == 3))) {
                    lane = 3;
                    player.y = 450;
                    PlaySound(bottomSound);
                }
                else if((lane == 2) && !((lockedLane) && (lockedLaneNum == 1))) {
                    lane = 1;
                    player.y = 150;
                    PlaySound(topSound);
                }
                else if((lane == 3) && !((lockedLane) && (lockedLaneNum == 2))) {
                    lane = 2;
                    player.y = 300;
                    PlaySound(middleSound);
                }   
            }
            else if(IsKeyPressed(KEY_S)) {
                if((lane == 1) && !((lockedLane) && (lockedLaneNum == 2))) {
                    lane = 2;
                    player.y = 300;
                    PlaySound(middleSound);
                }
                else if((lane == 2) && !((lockedLane) && (lockedLaneNum == 3))) {
                    lane = 3;
                    player.y = 450;
                    PlaySound(bottomSound);
                }
                else if((lane == 3) && !((lockedLane) && (lockedLaneNum == 1))) {
                    lane = 1;
                    player.y = 150;
                    PlaySound(topSound);
                }
            }
            else if(IsKeyPressed(KEY_SPACE)) {
                if ((timeSinceClear >= 5) || (firstClear)) {
                    PlaySound(laneClearSound);
                    timeOfLastClear = currentTime;
                    firstClear = false;
                    if (meteor1Lane == lane) {
                        meteor1.x = GetRandomValue(2600,4000);
                    }
                    if (meteor2Lane == lane) {
                        meteor2.x = GetRandomValue(4300,6000);
                    }
                    if (meteor3Lane == lane) {
                        meteor3.x = GetRandomValue(6300,8000);
                    }
                    if (meteor4Lane == lane) {
                        meteor4.x = GetRandomValue(8300,10000);
                    }
                    if (meteor5Lane == lane) {
                        meteor5.x = GetRandomValue(10300,12000);
                    }
                    if (meteor6Lane == lane) {
                        meteor6.x = GetRandomValue(2600,10000);
                    }
                    if (coinLane == lane) {
                        coin.x = GetRandomValue(2600,10000);
                    }
                    if (powerupLane == lane) {
                        powerup.x = GetRandomValue(2600,10000);
                        powerupNum = GetRandomValue(1,9);
                    }
                }
            }
            else if(IsKeyPressed(KEY_E)) {
                if(!started) {
                    PlaySound(clickSound);
                    if(!startScreen) {
                        started = true;
                        startScreen = false;
                        timeOfStart = GetTime();;
                        meteor1.x = GetRandomValue(2600,4000);
                        meteor2.x = GetRandomValue(4300,6000);
                        meteor3.x = GetRandomValue(6300,8000);
                        meteor4.x = GetRandomValue(8300,10000);
                        meteor5.x = GetRandomValue(10300,12000);
                        meteor6.x = GetRandomValue(2600,10000);
                        coin.x = GetRandomValue(2600,10000); 
                        scoreWOTime = 0;
                        difficulty = 1;
                        lockedLane = false;
                        pausedTime = 0;
                        timeOfCheck = 0;
                    }
                    else {
                        startScreen = false;
                        timeOfStart = GetTime();
                        meteor1.x = GetRandomValue(2600,4000);
                        meteor2.x = GetRandomValue(4300,6000);
                        meteor3.x = GetRandomValue(6300,8000);
                        meteor4.x = GetRandomValue(8300,10000);
                        meteor5.x = GetRandomValue(10300,12000);
                        meteor6.x = GetRandomValue(2600,10000);
                        coin.x = GetRandomValue(2600,10000); 
                        scoreWOTime = 0;
                        difficulty = 1;
                        lockedLane = false;
                        dead = false;
                        pausedTime = 0;
                        timeOfCheck = 0;
                    }
                }
            }
        }
        if(IsKeyPressed(KEY_P)) {
            if(paused) {
                paused = false;
            }
            else {
                paused = true;
            }
        }
        if(IsKeyPressed(KEY_ESCAPE)) {
            CloseWindow();
        }

        if(started) {

            if(scoreWOTime < 0) {
                scoreWOTime = 0;
            }

            currentTime = GetTime() - startTime;

            score = scoreWOTime + currentTime - pausedTime - timeOfStart;

            timeSinceClear = currentTime - timeOfLastClear;

            fps = GetFPS();

            if(paused) {
                pausedTime += 1/fps;
            }

            if(!paused) {
                if((currentTime - timeOfStart - pausedTime >= 0) && (currentTime - timeOfStart - pausedTime < 10) && (skip1 == false)) {
                    difficulty = 1;
                    intendedDiff = 1;
                }
                if ((currentTime - timeOfStart - pausedTime >= 10) && (currentTime - timeOfStart - pausedTime < 25) && (skip2 == false) && (difficulty < 2)){
                    difficulty = 2;
                    intendedDiff = 2;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 25) && (currentTime - timeOfStart - pausedTime < 40) && (skip3 == false && (difficulty < 3))) {
                    difficulty = 3;
                    intendedDiff = 3;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 40) && (currentTime - timeOfStart - pausedTime < 60) && (skip4 == false) && (difficulty < 4)) {
                    difficulty = 4;
                    intendedDiff = 4;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 60) && (currentTime - timeOfStart - pausedTime < 70) && (skip5 == false) && (difficulty < 5)) {
                    difficulty = 5;
                    intendedDiff = 5;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 70) && (currentTime - timeOfStart - pausedTime < 80) && (skip6 == false) && (difficulty < 6)) {
                    difficulty = 6;
                    intendedDiff = 6;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 80) && (currentTime - timeOfStart - pausedTime < 90) && (skip7 == false) && (difficulty < 7)) {
                    difficulty = 7;
                    intendedDiff = 7;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 90) && (currentTime - timeOfStart - pausedTime < 100) && (skip8 == false) && (difficulty < 8)) {
                    difficulty = 8;
                    intendedDiff = 8;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 100) && (currentTime - timeOfStart - pausedTime < 120) && (skip9 == false) && (difficulty < 9)) {
                    difficulty = 9;
                    intendedDiff = 9;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 120) && (currentTime - timeOfStart - pausedTime < 140) && (skip10 == false) && (difficulty < 10)) {
                    difficulty = 10;
                    intendedDiff = 10;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 140) && (currentTime - timeOfStart - pausedTime < 160) && (skip11 == false) && (difficulty < 11)) {
                    difficulty = 11;
                    intendedDiff = 11;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 160) && (currentTime - timeOfStart - pausedTime < 180) && (skip12 == false) && (difficulty < 12)) {
                    difficulty = 12;
                    intendedDiff = 12;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 180) && (currentTime - timeOfStart - pausedTime < 200) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 13;
                    intendedDiff = 13;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 200) && (currentTime - timeOfStart - pausedTime < 220) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 14;
                    intendedDiff = 14;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 220) && (currentTime - timeOfStart - pausedTime < 240) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 15;
                    intendedDiff = 15;
                }
                else if ((currentTime - timeOfStart - pausedTime>= 240) && (currentTime - timeOfStart - pausedTime < 260) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 16;
                    intendedDiff = 16;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 260) && (currentTime - timeOfStart - pausedTime < 280) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 17;
                    intendedDiff = 17;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 280) && (currentTime - timeOfStart - pausedTime < 300) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 18;
                    intendedDiff = 18;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 300) && (currentTime - timeOfStart - pausedTime < 320) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 19;
                    intendedDiff = 19;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 320) && (currentTime - timeOfStart - pausedTime < 340) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 20;
                    intendedDiff = 20;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 340) && (currentTime - timeOfStart - pausedTime < 360) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 21;
                    intendedDiff = 21;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 360) && (currentTime - timeOfStart - pausedTime < 380) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 22;
                    intendedDiff = 22;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 380) && (currentTime - timeOfStart - pausedTime < 400) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 23;
                    intendedDiff = 23;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 400) && (currentTime - timeOfStart - pausedTime < 420) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 24;
                    intendedDiff = 24;
                }
                else if ((currentTime - timeOfStart - pausedTime >= 420) && (currentTime - timeOfStart - pausedTime < 440) && (skip13 == false) && (difficulty < 13)) {
                    difficulty = 25;
                    intendedDiff = 25;
                }

                while((lockedLane) && (lockedLaneNum == powerupLane) && (powerupNum == 8)) {
                    powerupLane = GetRandomValue(1,3);
                }

                if(powerup.x < 400) {
                    if(powerup.x > 200) {
                        if(powerupLane == lane) {
                            powerup.x = GetRandomValue(2600,5200);
                            powerupLane = GetRandomValue(1,3);
                            if (powerupNum == 1) {
                                PlaySound(powerupSound1);
                                if(difficulty == 2) {
                                skip2 = true;
                                difficulty = 1;
                                }
                                else if(difficulty == 3) {
                                    skip3 = true;
                                    difficulty = 2;
                                }
                                else if(difficulty == 4) {
                                    skip4 = true;
                                    difficulty = 3;
                                }
                                else if(difficulty == 5) {
                                    skip5 = true;
                                    difficulty = 4;
                                }
                                else if(difficulty == 6) {
                                    skip6 = true;
                                    difficulty = 7;
                                }
                                else if(difficulty == 7) {
                                    skip7 = true;
                                    difficulty = 6;
                                }
                                else if(difficulty == 8) {
                                    skip8 = true;
                                    difficulty = 7;
                                }
                                else if(difficulty == 9) {
                                    skip9 = true;
                                    difficulty = 8;
                                }
                                else if(difficulty == 10) {
                                    skip10 = true;
                                    difficulty = 9;
                                }
                                else if(difficulty == 11) {
                                    skip11 = true;
                                    difficulty = 10;
                                }
                                else if(difficulty == 12) {
                                    skip12 = true;
                                    difficulty = 11;
                                }
                                else if(difficulty == 13) {
                                    skip13 = true;
                                    difficulty = 12;
                                }
                            }
                            else if(powerupNum == 2) {
                                PlaySound(powerupSound2);
                                difficulty += 1;
                                scoreWOTime += 200;
                            }
                            else if(powerupNum == 3) {
                                PlaySound(powerupSound3);
                                scoreWOTime -= 100;
                            }
                            else if(powerupNum == 4) {
                                PlaySound(powerupSound4);
                                meteor1.x = GetRandomValue(2600,4000);
                                meteor2.x = GetRandomValue(4300,6000);
                                meteor3.x = GetRandomValue(6300,8000);
                                meteor4.x = GetRandomValue(8300,10000);
                                meteor5.x = GetRandomValue(10300,12000);
                                meteor6.x = GetRandomValue(2600,10000);
                                coin.x = GetRandomValue(2600,10000);
                            }
                            else if(powerupNum == 5) {
                                PlaySound(powerupSound5);
                                speedMod += 0.2;
                                scoreWOTime += 150;
                            }
                            else if(powerupNum == 6) {
                                PlaySound(powerupSound6);
                                speedMod -= 0.2;
                                if (speedMod <= .25) {
                                    speedMod = .5;
                                }
                            }
                            else if(powerupNum == 7) {
                                PlaySound(powerupSound7);
                                lockedLane = true;
                                lockedLaneNum = lane;
                                scoreWOTime += 300;
                            }
                            else if(powerupNum == 8) {
                                PlaySound(powerupSound8);
                                lockedLane = false;
                            }
                            else if(powerupNum == 9) {
                                PlaySound(powerupSound9);
                                if (meteor1Lane == lane) {
                                    meteor1.x = GetRandomValue(2600,4000);
                                    scoreWOTime += 20;
                                }
                                if (meteor2Lane == lane) {
                                    meteor2.x = GetRandomValue(4300,6000);
                                    scoreWOTime += 20;
                                }
                                if (meteor3Lane == lane) {
                                    meteor3.x = GetRandomValue(6300,8000);
                                    scoreWOTime += 20;
                                }
                                if (meteor4Lane == lane) {
                                    meteor4.x = GetRandomValue(8300,10000);
                                    scoreWOTime += 20;
                                }
                                if (meteor5Lane == lane) {
                                    meteor5.x = GetRandomValue(10300,12000);
                                    scoreWOTime += 20;
                                }
                                if (meteor6Lane == lane) {
                                    meteor6.x = GetRandomValue(2600,10000);
                                    scoreWOTime += 20;
                                }
                                if (coinLane == lane) {
                                    coin.x = GetRandomValue(2600,10000);
                                }
                                if (powerupLane == lane) {
                                    powerup.x = GetRandomValue(2600,10000);
                                }
                            }
                            powerupNum = GetRandomValue(1,9);
                        }
                    }
                }
                if(powerup.x < -400) {
                    powerupNum = GetRandomValue(1,9);
                    powerupLane = GetRandomValue(1,3);
                    powerup.x = GetRandomValue(2600,5200);
                }
                else {
                    if (currentTime + timeOfStart >= 5) {
                        powerup.x -= 500*difficulty/5/fps*speedMod;
                    }
                }
                if (powerupLane == 1) {
                    powerup.y = 140;
                }
                else if (powerupLane == 2) {
                    powerup.y = 300;
                }
                else if (powerupLane == 3) {
                    powerup.y = 440;
                }

                if((lockedLane) && (powerupNum == 7)) {
                    powerupNum = 8;
                }
                else if((!lockedLane) && (powerupNum == 8)) {
                    powerupNum = 7;
                }
                if(powerupLane == meteor1Lane) {
                    if((powerup.x - meteor1.x) < 100) {
                        if((powerup.x - meteor1.x) > -100) {
                            powerup.x = GetRandomValue(2600,50000);
                        }
                    }
                }
                if(powerupLane == meteor2Lane) {
                    if((powerup.x - meteor2.x) < 100) {
                        if((powerup.x - meteor2.x) > -100) {
                            powerup.x = GetRandomValue(2600,50000);
                        }
                    }
                }
                if(powerupLane == meteor3Lane) {
                    if((powerup.x - meteor3.x) < 100) {
                        if((powerup.x - meteor3.x) > -100) {
                            powerup.x = GetRandomValue(2600,50000);
                        }
                    }
                }
                if(powerupLane == meteor4Lane) {
                    if((powerup.x - meteor4.x) < 100) {
                        if((powerup.x - meteor4.x) > -100) {
                            powerup.x = GetRandomValue(2600,50000);
                        }
                    }
                }
                if(powerupLane == meteor5Lane) {
                    if((powerup.x - meteor5.x) < 100) {
                        if((powerup.x - meteor5.x) > -100) {
                            powerup.x = GetRandomValue(2600,50000);
                        }
                    }
                }
                if(powerupLane == meteor6Lane) {
                    if((powerup.x - meteor6.x) < 100) {
                        if((powerup.x - meteor6.x) > -100) {
                            powerup.x = GetRandomValue(2600,50000);
                        }
                    }
                }

                if(coin.x < 350) {
                    if(coin.x >250) {
                        if(coinLane == lane) {
                            PlaySound(coinPickup);
                            coin.x = GetRandomValue(2600,3200);
                            scoreWOTime += GetRandomValue(1,75);
                            coinLane = GetRandomValue(1,3);
                        }
                    }
                }
                if(coin.x < -400) {
                    coinLane = GetRandomValue(1,3);
                    coin.x = GetRandomValue(2600,5200);
                }
                else {
                    coin.x -= 500*difficulty/5/fps*speedMod;
                }
                if (coinLane == 1) {
                    coin.y = 140;
                }
                else if (coinLane == 2) {
                    coin.y = 300;
                }
                else if (coinLane == 3) {
                    coin.y = 440;
                }

                if(coinLane == meteor1Lane) {
                    if((coin.x - meteor1.x) < 100) {
                        if((coin.x - meteor1.x) > -100) {
                            coin.x = GetRandomValue(2600,50000);
                        }
                    }
                }
                if(coinLane == meteor2Lane) {
                    if((coin.x - meteor2.x) < 100) {
                        if((coin.x - meteor2.x) > -100) {
                            coin.x = GetRandomValue(2600,50000);
                        }
                    }
                }
                if(coinLane == meteor3Lane) {
                    if((coin.x - meteor3.x) < 100) {
                        if((coin.x - meteor3.x) > -100) {
                            coin.x = GetRandomValue(2600,50000);
                        }
                    }
                }
                if(coinLane == meteor4Lane) {
                    if((coin.x - meteor4.x) < 100) {
                        if((coin.x - meteor4.x) > -100) {
                            coin.x = GetRandomValue(2600,50000);
                        }
                    }
                }
                if(coinLane == meteor5Lane) {
                    if((coin.x - meteor5.x) < 100) {
                        if((coin.x - meteor5.x) > -100) {
                            coin.x = GetRandomValue(2600,50000);
                        }
                    }
                }
                if(coinLane == meteor6Lane) {
                    if((coin.x - meteor6.x) < 100) {
                        if((coin.x - meteor6.x) > -100) {
                            coin.x = GetRandomValue(2600,50000);
                        }
                    }
                }
 
                //Meteor Movement
                if(meteor1.x < 350) {
                    if(meteor1.x >250) {
                        if(meteor1Lane == lane) {
                            meteor1.x = GetRandomValue(2600,7000);
                            started = false;
                            startScreen = true;
                            dead = true;
                            PlaySound(lossSound);
                        }
                    }
                }
                if(meteor1.x < -400) {
                    meteor1Lane = GetRandomValue(1,3);
                    meteor1.x = GetRandomValue(2600,7000);
                }
                else {
                    meteor1.x -= 500*difficulty/5/fps*speedMod;
                }
                if (meteor1Lane == 1) {
                    meteor1.y = 120;
                }
                else if (meteor1Lane == 2) {
                    meteor1.y = 280;
                }
                else if (meteor1Lane == 3) {
                    meteor1.y = 430;
                }

                if(meteor2.x < 350) {
                    if(meteor2.x >250) {
                        if(meteor2Lane == lane) {
                            meteor1.x = GetRandomValue(2600,7000);
                            started = false;
                            startScreen = true;
                            dead = true;
                            PlaySound(lossSound);
                        }
                    }
                }
                if(meteor2.x < -400) {
                    meteor2Lane = GetRandomValue(1,3);
                    meteor2.x = GetRandomValue(2600,7000);
                }
                else {
                    if (currentTime + timeOfStart >= 5) {
                        meteor2.x -= 500*difficulty/5/fps*speedMod;
                    }
                }
                if (meteor2Lane == 1) {
                    meteor2.y = 120;
                }
                else if (meteor2Lane == 2) {
                    meteor2.y = 280;
                }
                else if (meteor2Lane == 3) {
                    meteor2.y = 430;
                }

                if(meteor3.x < 350) {
                    if(meteor3.x >250) {
                        if(meteor3Lane == lane) {
                            meteor1.x = GetRandomValue(2600,7000);
                            started = false;
                            startScreen = true;
                            dead = true;
                            PlaySound(lossSound);
                        }
                    }
                }
                if(meteor3.x < -400) {
                    meteor3Lane = GetRandomValue(1,3);
                    meteor3.x = GetRandomValue(2600,7000);
                }
                else {
                    if (currentTime + timeOfStart >= 10) {
                        meteor3.x -= 500*difficulty/5/fps*speedMod;
                    }
                }
                if (meteor3Lane == 1) {
                    meteor3.y = 120;
                }
                else if (meteor3Lane == 2) {
                    meteor3.y = 280;
                }
                else if (meteor3Lane == 3) {
                    meteor3.y = 430;
                }

                if(meteor4.x < 350) {
                    if(meteor4.x >250) {
                        if(meteor4Lane == lane) {
                            meteor1.x = GetRandomValue(2600,7000);
                            started = false;
                            startScreen = true;
                            dead = true;
                            PlaySound(lossSound);
                        }
                    }
                }
                if(meteor4.x < -400) {
                    meteor4Lane = GetRandomValue(1,3);
                    meteor4.x = GetRandomValue(2600,7000);
                }
                else {
                    if (currentTime + timeOfStart >= 20) {
                        meteor4.x -= 500*difficulty/5/fps*speedMod;
                    }
                }
                if (meteor4Lane == 1) {
                    meteor4.y = 120;
                }
                else if (meteor4Lane == 2) {
                    meteor4.y = 280;
                }
                else if (meteor4Lane == 3) {
                    meteor4.y = 430;
                }

                if(meteor5.x < 350) {
                    if(meteor5.x >250) {
                        if(meteor5Lane == lane) {
                            meteor1.x = GetRandomValue(2600,7000);
                            started = false;
                            startScreen = true;
                            dead = true;
                            PlaySound(lossSound);
                        }
                    }
                }
                if(meteor5.x < -400) {
                    meteor5Lane = GetRandomValue(1,3);
                    meteor5.x = GetRandomValue(2600,7000);
                }
                else {
                    if (currentTime + timeOfStart >= 50) {
                        meteor5.x -= 500*difficulty/5/fps*speedMod;
                    }
                }
                if (meteor5Lane == 1) {
                    meteor5.y = 120;
                }
                else if (meteor5Lane == 2) {
                    meteor5.y = 280;
                }
                else if (meteor5Lane == 3) {
                    meteor5.y = 430;
                }

                if(meteor6.x < 350) {
                    if(meteor6.x >250) {
                        if(meteor6Lane == lane) {
                            meteor1.x = GetRandomValue(2600,7000);
                            started = false;
                            startScreen = true;
                            dead = true;
                            PlaySound(lossSound);
                        }
                    }
                }
                if(meteor6.x < -400) {
                    meteor6Lane = GetRandomValue(1,3);
                    meteor6.x = GetRandomValue(2600,7000);
                }
                else {
                    if (currentTime + timeOfStart >= 100) {
                        meteor6.x -= 500*difficulty/5/fps*speedMod;
                    }
                }
                if (meteor6Lane == 1) {
                    meteor6.y = 120;
                }
                else if (meteor6Lane == 2) {
                    meteor6.y = 280;
                }
                else if (meteor6Lane == 3) {
                    meteor6.y = 430;
                }

                if (difficulty < 1) {
                    difficulty = 1;
                }
            }

            if(lockedLane) {
                scoreWOTime += 20/fps;
            }
            }

        BeginDrawing();

        ClearBackground(BLACK);

        if (started) {
            DrawTexture(bgImage, bg.x, bg.y, WHITE);

            DrawTexture(playerImage, player.x, player.y, WHITE);

            DrawTexture(fireImage, fire.x, fire.y, WHITE);

            DrawTexture(meteor1Image, meteor1.x, meteor1.y, WHITE);
            DrawTexture(meteor2Image, meteor2.x, meteor2.y, WHITE);
            DrawTexture(meteor3Image, meteor3.x, meteor3.y, WHITE);
            DrawTexture(meteor4Image, meteor4.x, meteor4.y, WHITE);
            DrawTexture(meteor5Image, meteor5.x, meteor5.y, WHITE);
            DrawTexture(meteor6Image, meteor6.x, meteor6.y, WHITE);

            if (powerupNum == 1) {
                DrawTexture(powerupImage1, powerup.x, powerup.y, WHITE);
            }
            else if(powerupNum == 2) {
                DrawTexture(powerupImage2, powerup.x, powerup.y, WHITE);
            }
            else if(powerupNum == 3) {
                DrawTexture(powerupImage3, powerup.x, powerup.y, WHITE);
            }
            else if(powerupNum == 4) {
                DrawTexture(powerupImage4, powerup.x, powerup.y, WHITE);
            }
            else if(powerupNum == 5) {
                DrawTexture(powerupImage5, powerup.x, powerup.y, WHITE);
            }
            else if(powerupNum == 6) {
                DrawTexture(powerupImage6, powerup.x, powerup.y, WHITE);
            }
            else if(powerupNum == 7) {
                DrawTexture(powerupImage7, powerup.x, powerup.y, WHITE);
            }
            else if(powerupNum == 8) {
                DrawTexture(powerupImage8, powerup.x, powerup.y, WHITE);
            }
            else if(powerupNum == 9) {
                DrawTexture(powerupImage9, powerup.x, powerup.y, WHITE);
            }
            else {
                DrawTexture(powerupImagePlaceholder, powerup.x, powerup.y, WHITE);
            }

            DrawTexture(coinImage, coin.x, coin.y, WHITE);

            DrawText(TextFormat("Score: %i",score), 300, 10, 30, WHITE);

            while((currentTime - timeOfStart) < 0) {
                timeOfStart -= 1;
            }

            DrawText(TextFormat("Time: %.0f",currentTime-timeOfStart-pausedTime), 700, 10, 30, WHITE);

            DrawText(TextFormat("Difficulty: %i",difficulty), 1100, 10, 30, WHITE);

            DrawText(TextFormat("E N D L E S S    D R I F T"), 2140, 560, 30, WHITE);

        }
        else if (startScreen == true) {
            if(!dead) {
                DrawText(TextFormat("Avoid the meteors (sad faces), and collect coins and powerups. Some powerups have bad effects but give lots of points."), 60, 70, 30, WHITE);
                DrawText(TextFormat("W to move up, S to move down"), 150, 150, 30, WHITE);
                DrawText(TextFormat("The lanes loop, going down from bottom goes to the top and vice-versa"), 150, 190, 30, WHITE);
                DrawText(TextFormat("Spacebar to clear everything in your lane, this has a 10-second cooldown"), 150, 250, 30, WHITE);
                DrawText(TextFormat("P to pause, Q to close the window"), 150, 310, 30, WHITE);
                DrawText(TextFormat("Alternate Controls:"), 150, 370, 30, WHITE);
                DrawText(TextFormat("Q for top lane, A for middle and Z for bottom"), 200, 410, 30, WHITE);
                DrawText(TextFormat("1 for top lane, 2 for middle lane, 3 for bottom"), 200, 470, 30, WHITE);
                DrawText(TextFormat("Press E to continue"), 1700, 530, 30, WHITE);
            } 
            else {
                DrawText(TextFormat("dead."), 150, 250, 30, WHITE);
                DrawText(TextFormat("Score: %i",score), 150, 290, 30, WHITE);
                DrawText(TextFormat("Press E to continue"), 1700, 530, 30, WHITE);
            }
        }
        else if (startScreen == false) {
            DrawTexture(coinImage, 80, 40, WHITE);
            DrawText(TextFormat("+(1-100) points"), 200, 76, 30, WHITE);
            DrawTexture(powerupImage1, 80, 150, WHITE);
            DrawText(TextFormat("-1 Difficulty until next level"), 200, 186, 30, WHITE);
            DrawTexture(powerupImage2, 80, 260, WHITE);
            DrawText(TextFormat("+1 Difficulty until next level, +100 points"), 200, 296, 30, WHITE);
            DrawTexture(powerupImage3, 80, 370, WHITE);
            DrawText(TextFormat("-100 points"), 200, 406, 30, WHITE);
            DrawTexture(powerupImage4, 80, 480, WHITE);
            DrawText(TextFormat("Clears screen of everything"), 200, 516, 30, WHITE);


            DrawTexture(powerupImage5, 1000, 40, WHITE);
            DrawText(TextFormat("Speeds everything up, +150 points"), 1120, 76, 30, WHITE);
            DrawTexture(powerupImage6, 1000, 150, WHITE);
            DrawText(TextFormat("Slows everything down"), 1120, 186, 30, WHITE);
            DrawTexture(powerupImage7, 1000, 260, WHITE);
            DrawText(TextFormat("Disables movement to the lane once left, +300 points"), 1120, 296, 30, WHITE);
            DrawTexture(powerupImage8, 1000, 370, WHITE);
            DrawText(TextFormat("Unlocks locked lane"), 1120, 406, 30, WHITE);
            DrawTexture(powerupImage9, 1000, 480, WHITE);
            DrawText(TextFormat("Clears lane, gives points for each thing in lane"), 1120, 516, 30, WHITE);
        }
        EndDrawing();
    }
    UnloadMusicStream(bgAmb);
    CloseAudioDevice();
    
    CloseWindow();
}