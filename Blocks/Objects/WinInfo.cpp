#include "WinInfo.hpp"

WinInfo::WinInfo(SaveObject *_saveObj, Font font, Color col, float winWidth) {
    // Set the instance variables
    textColor = col;
    textFont = font;
    saveObj = _saveObj;
    // Configure the congrats text
    congratsText.setFont(textFont);
    congratsText.setString("CONGRATULATIONS!");
    congratsText.setCharacterSize(37);
    congratsText.setColor(col);
    centerText(&congratsText, winWidth, 280);
    // Configure the level complete text
    levelCompleteText.setFont(textFont);
    levelCompleteText.setString("LEVEL COMPLETE!");
    levelCompleteText.setCharacterSize(37);
    levelCompleteText.setColor(col);
    centerText(&levelCompleteText, winWidth, 320);
    // Configure the total time text
    totalTimeText.setFont(textFont);
    totalTimeText.setCharacterSize(25);
    totalTimeText.setColor(col);
    totalTimeText.setPosition(140, 400);
    // Configure the total moves text
    totalMovesText.setFont(textFont);
    totalMovesText.setCharacterSize(25);
    totalMovesText.setColor(col);
    totalMovesText.setPosition(140, 425);
}

void WinInfo::update() {
    totalTimeText.setString("Total Time:        " + saveObj->getData("TIME"));
    totalMovesText.setString("Total Moves:      " + saveObj->getData("MOVES"));
}

void WinInfo::draw(RenderWindow *window) {
    // Draw all of the text objects
    window->draw(congratsText);
    window->draw(levelCompleteText);
    window->draw(totalTimeText);
    window->draw(totalMovesText);
}

void WinInfo::centerText(Text *text, float winWidth, float y) {
    FloatRect rect;
    // Center the text horizontally
    rect = text->getLocalBounds();
    text->setOrigin((rect.left + rect.width) / 2, 0);
    text->setPosition(winWidth / 2, y);
}
