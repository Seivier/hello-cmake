#include <iostream>
#include "ball.h"

int main(int argc, char const *argv[])
{
    std::cout << "Hello CC7515!" << std::endl;
    cc7515::Ball ball({0, 0}, 1, 1);
    ball += {1, 1};
    ball.update(1);
    std::cout << ball << std::endl;
    return 0;
}
