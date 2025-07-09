#pragma once
#include <iostream>
#include "fight.h"
using namespace std;

class StartStory {
    public:
        StartStory();
        void ChapterOne();
    private:
        Fight fight;
};