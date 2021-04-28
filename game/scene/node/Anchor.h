//
// Created by Ludwig on 2017-06-20.
//

#ifndef MINER_ANCHOR_H
#define MINER_ANCHOR_H

enum Anchor {

    TOP_LEFT, TOP_RIGHT, BOTTOM_RIGHT, BOTTOM_LEFT,
    TOP, RIGHT, BOTTOM, LEFT, CENTER

};

int realX(Anchor anchor, int x, int nodeWidth, int windowWidth);

int realY(Anchor anchor, int y, int nodeHeight, int windowHeight);

#endif //MINER_ANCHOR_H
