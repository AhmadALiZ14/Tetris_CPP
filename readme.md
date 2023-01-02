* AhmedAZ14,CS,FASTNU
* Tetris Game in C++ using SFML Library

---------FEATURES----------

--Current--:
           
           * Left,Right and Down Movements Possible
           * Press Space key to instantly move block till end
           * Ability to rotate blocks
           * Shadow of a block that will tell user where block will fall 
           * Next Block will also be shown to help the user
           * Scoring : Lines Cleared and Points awarded
           * Game Over Menu
         
--Future--:
           
           * A bomb will fall after random time, giving player some advantages
           * A complete Menu
           * Game Levels : Number of next Block Suggestions and falling speed
           * Scoring : High Scores
           
                    

-----------COMPILE AND RUN-----------

* GNU LINUX(debian based): 

               # Note you should have a cpp compiler installed e.g. g++
            1. install sfml using : sudo apt install libsfml-dev
            2. g++ -c main.cpp
            3. g++ main.o -o tetris -lsfml-graphics -lsfml-window -lsfml-system
            4. ./tetris

-----------End------------
