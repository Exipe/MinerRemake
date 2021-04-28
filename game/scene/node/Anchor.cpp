//
// Created by Ludwig on 2017-06-20.
//

#include "Anchor.h"
#include <iostream>

int realX(Anchor anchor, int x, int nodeWidth, int windowWidth) {
    switch(anchor) {
        case LEFT:
        case TOP_LEFT:
        case BOTTOM_LEFT:
            return x;

        case RIGHT:
        case TOP_RIGHT:
        case BOTTOM_RIGHT:
            return windowWidth - nodeWidth + x;

        case TOP:
        case BOTTOM:
        case CENTER:
            return windowWidth / 2 - nodeWidth / 2 + x;
    }
}

int realY(Anchor anchor, int y, int nodeHeight, int windowHeight) {
    switch(anchor) {
        case TOP:
        case TOP_LEFT:
        case TOP_RIGHT:
            return y;

        case BOTTOM:
        case BOTTOM_LEFT:
        case BOTTOM_RIGHT:
            return windowHeight - nodeHeight + y;

        case LEFT:
        case RIGHT:
        case CENTER:
            return windowHeight / 2 - nodeHeight / 2 + y;
    }
}


