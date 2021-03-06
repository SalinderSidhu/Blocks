#include "BlockGame.hpp"

BlockGame::BlockGame() {
	// Define Game constants
    const string title = "Blocks";
    const int winWidth = 600;
    const int winHeight = 700;
    const int FPS = 60;
    const int bits = 32;
    // Initialize the Game
    game = new Game(title, winWidth, winHeight, bits, FPS);
    // Obtain the ResourceManager, RenderWindow and SaveObject from Game
    resMan = game->getResourceManager();
    window = game->getWindow();
    saveObj = game->getSaveObject();
    try {
        showLoadingScreen();
        loadGameResources();
        setWindowIcon();
        setupLevels(title, winWidth);
        // Start the Game
        game->start();
        // Clean up Game pointer
        cleanup();
    } catch(exception &ex) {
        // Display error message and exit game if an exception was thrown
        game->getDialog()->showError(ex.what());
        window->close();
        // Clean up Game pointer
        cleanup();
    }
}

void BlockGame::cleanup() {
    // Delete and NULL the Game pointer to free up memory
    delete game;
    game = NULL;
}

void BlockGame::setWindowIcon() {
    // Add an icon to the Game's window
    Image icon = resMan->getImage("IM_ICON");
    window->setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());
}

void BlockGame::addGameLevel(string title, GameGrid *grid) {
    // Create and setup GameLevel and WinLevel objects
    GameLevel *gameLevel = new GameLevel(title, resMan, window, saveObj);
    gameLevel->setGameGrid(grid);
    WinLevel *winLevel = new WinLevel(title, resMan, window, saveObj);
    // Add GameLevel and WinLevel into Game
    game->addLevel(gameLevel);
    game->addLevel(winLevel);
}

void BlockGame::setupLevels(string gameTitle, int winWidth) {
    // Create and MenuLevel and add it into Game
    MenuLevel *menu = new MenuLevel(gameTitle, resMan, window, saveObj);
    game->addLevel(menu);
    // Create Level 1 and setup level 1 GameGrid
    GameGrid *gameGrid1 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid1->addBlock("TX_BV31", 3, 2, 0, 58, 221, true, false);
    gameGrid1->addBlock("TX_BH26", 2, 4, 0, 131, 57, false, false);
    gameGrid1->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
    gameGrid1->addBlock("TX_BH32", 3, 0, 3, 221, 57, false, false);
    gameGrid1->addBlock("TX_BV32", 3, 5, 3, 58, 221, true, false);
    addGameLevel("Level 1", gameGrid1);
    // Create Level 2 and setup level 2 GameGrid
    GameGrid *gameGrid2 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid2->addBlock("TX_BV31", 3, 2, 0, 58, 221, true, false);
    gameGrid2->addBlock("TX_BH21", 2, 3, 2, 131, 57, false, true);
    gameGrid2->addBlock("TX_BV32", 3, 5, 1, 58, 221, true, false);
    gameGrid2->addBlock("TX_BH31", 3, 0, 3, 221, 57, false, false);
    gameGrid2->addBlock("TX_BV25", 2, 3, 3, 58, 131, true, false);
    gameGrid2->addBlock("TX_BH23", 2, 4, 4, 131, 57, false, false);
    addGameLevel("Level 2", gameGrid2);
    // Create Level 3 and setup level 3 GameGrid
    GameGrid *gameGrid3 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid3->addBlock("TX_BV25", 2, 0, 0, 58, 131, true, false);
    gameGrid3->addBlock("TX_BV22", 2, 1, 0, 58, 131, true, false);
    gameGrid3->addBlock("TX_BH23", 2, 2, 0, 131, 57, false, false);
    gameGrid3->addBlock("TX_BH26", 2, 2, 1, 131, 57, false, false);
    gameGrid3->addBlock("TX_BV23", 2, 4, 0, 58, 131, true, false);
    gameGrid3->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
    gameGrid3->addBlock("TX_BV25", 2, 2, 2, 58, 131, true, false);
    gameGrid3->addBlock("TX_BV24", 2, 2, 4, 58, 131, true, false);
    gameGrid3->addBlock("TX_BV31", 3, 3, 2, 58, 221, true, false);
    gameGrid3->addBlock("TX_BV26", 2, 4, 3, 58, 131, true, false);
    addGameLevel("Level 3", gameGrid3);
    // Create Level 4 and setup level 4 GameGrid
    GameGrid *gameGrid4 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid4->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
    gameGrid4->addBlock("TX_BH31", 3, 0, 3, 221, 57, false, false);
    gameGrid4->addBlock("TX_BV25", 2, 2, 1, 58, 131, true, false);
    gameGrid4->addBlock("TX_BV23", 2, 0, 4, 58, 131, true, false);
    gameGrid4->addBlock("TX_BV22", 2, 1, 4, 58, 131, true, false);
    gameGrid4->addBlock("TX_BV26", 2, 2, 4, 58, 131, true, false);
    gameGrid4->addBlock("TX_BV31", 3, 4, 1, 58, 221, true, false);
    gameGrid4->addBlock("TX_BV21", 2, 5, 2, 58, 131, true, false);
    gameGrid4->addBlock("TX_BH25", 2, 4, 4, 131, 57, false, false);
    gameGrid4->addBlock("TX_BH23", 2, 4, 5, 131, 57, false, false);
    addGameLevel("Level 4", gameGrid4);
    // Create Level 5 and setup level 5 GameGrid
    GameGrid *gameGrid5 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid5->addBlock("TX_BH32", 3, 2, 0, 221, 57, false, false);
    gameGrid5->addBlock("TX_BH31", 3, 0, 1, 221, 57, false, false);
    gameGrid5->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
    gameGrid5->addBlock("TX_BH32", 3, 0, 3, 221, 57, false, false);
    gameGrid5->addBlock("TX_BH24", 2, 4, 4, 131, 57, false, false);
    gameGrid5->addBlock("TX_BH22", 2, 4, 5, 131, 57, false, false);
    gameGrid5->addBlock("TX_BV32", 3, 4, 1, 58, 221, true, false);
    gameGrid5->addBlock("TX_BV25", 2, 5, 2, 58, 131, true, false);
    gameGrid5->addBlock("TX_BV24", 2, 0, 4, 58, 131, true, false);
    gameGrid5->addBlock("TX_BV23", 2, 2, 4, 58, 131, true, false);
    addGameLevel("Level 5", gameGrid5);
    // Create Level 6 and setup level 6 GameGrid
    GameGrid *gameGrid6 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid6->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
    gameGrid6->addBlock("TX_BH23", 2, 3, 3, 131, 57, false, false);
    gameGrid6->addBlock("TX_BH26", 2, 1, 4, 131, 57, false, false);
    gameGrid6->addBlock("TX_BH32", 3, 0, 5, 221, 57, false, false);
    gameGrid6->addBlock("TX_BV31", 3, 2, 1, 58, 221, true, false);
    gameGrid6->addBlock("TX_BV25", 2, 5, 1, 58, 131, true, false);
    gameGrid6->addBlock("TX_BV22", 2, 0, 3, 58, 131, true, false);
    gameGrid6->addBlock("TX_BV23", 2, 3, 4, 58, 131, true, false);
    gameGrid6->addBlock("TX_BV26", 2, 4, 4, 58, 131, true, false);
    gameGrid6->addBlock("TX_BV32", 3, 5, 3, 58, 221, true, false);
    addGameLevel("Level 6", gameGrid6);
    // Create Level 7 and setup level 7 GameGrid
    GameGrid *gameGrid7 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid7->addBlock("TX_BH25", 2, 0, 0, 131, 57, false, false);
    gameGrid7->addBlock("TX_BH32", 3, 3, 0, 221, 57, false, false);
    gameGrid7->addBlock("TX_BH23", 2, 4, 1, 131, 57, false, false);
    gameGrid7->addBlock("TX_BH21", 2, 1, 2, 131, 57, false, true);
    gameGrid7->addBlock("TX_BH26", 2, 3, 3, 131, 57, false, false);
    gameGrid7->addBlock("TX_BH22", 2, 0, 4, 131, 57, false, false);
    gameGrid7->addBlock("TX_BH31", 3, 3, 5, 221, 57, false, false);
    gameGrid7->addBlock("TX_BV22", 2, 3, 1, 58, 131, true, false);
    gameGrid7->addBlock("TX_BV24", 2, 0, 2, 58, 131, true, false);
    gameGrid7->addBlock("TX_BV31", 3, 2, 3, 58, 221, true, false);
    gameGrid7->addBlock("TX_BV32", 3, 5, 2, 58, 221, true, false);
    addGameLevel("Level 7", gameGrid7);
    // Create Level 8 and setup level 8 GameGrid
    GameGrid *gameGrid8 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid8->addBlock("TX_BH25", 2, 0, 0, 131, 57, false, false);
    gameGrid8->addBlock("TX_BH24", 2, 4, 5, 131, 57, false, false);
    gameGrid8->addBlock("TX_BV31", 3, 5, 1, 58, 221, true, false);
    gameGrid8->addBlock("TX_BH23", 2, 4, 0, 131, 57, false, false);
    gameGrid8->addBlock("TX_BV22", 2, 2, 0, 58, 131, true, false);
    gameGrid8->addBlock("TX_BH21", 2, 1, 2, 131, 57, false, true);
    gameGrid8->addBlock("TX_BV32", 3, 0, 2, 58, 221, true, false);
    gameGrid8->addBlock("TX_BH26", 2, 0, 1, 131, 57, false, false);
    gameGrid8->addBlock("TX_BV22", 2, 3, 4, 58, 131, true, false);
    gameGrid8->addBlock("TX_BH22", 2, 0, 5, 131, 57, false, false);
    gameGrid8->addBlock("TX_BH32", 3, 1, 3, 221, 57, false, false);
    gameGrid8->addBlock("TX_BH23", 2, 4, 4, 131, 57, false, false);
    addGameLevel("Level 8", gameGrid8);
    // Create Level 9 and setup level 9 GameGrid
    GameGrid *gameGrid9 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid9->addBlock("TX_BH21", 2, 2, 2, 131, 57, false, true);
    gameGrid9->addBlock("TX_BV22", 2, 4, 1, 58, 131, true, false);
    gameGrid9->addBlock("TX_BV25", 2, 4, 3, 58, 131, true, false);
    gameGrid9->addBlock("TX_BH23", 2, 3, 0, 131, 57, false, false);
    gameGrid9->addBlock("TX_BH31", 3, 1, 4, 221, 57, false, false);
    gameGrid9->addBlock("TX_BH23", 2, 2, 3, 131, 57, false, false);
    gameGrid9->addBlock("TX_BV24", 2, 1, 2, 58, 131, true, false);
    gameGrid9->addBlock("TX_BV26", 2, 2, 0, 58, 131, true, false);
    addGameLevel("Level 9", gameGrid9);
    // Create Level 10 and setup level 10 GameGrid
    GameGrid *gameGrid10 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
        winWidth, 640, resMan);
    gameGrid10->addBlock("TX_BH21", 2, 1, 2, 131, 57, false, true);
    gameGrid10->addBlock("TX_BV31", 3, 4, 1, 58, 221, true, false);
    gameGrid10->addBlock("TX_BV32", 3, 5, 1, 58, 221, true, false);
    gameGrid10->addBlock("TX_BV32", 3, 3, 2, 58, 221, true, false);
    gameGrid10->addBlock("TX_BV22", 2, 3, 0, 58, 131, true, false);
    gameGrid10->addBlock("TX_BV26", 2, 2, 3, 58, 131, true, false);
    gameGrid10->addBlock("TX_BH32", 3, 3, 5, 221, 57, false, false);
    gameGrid10->addBlock("TX_BV25", 2, 0, 4, 58, 131, true, false);
    gameGrid10->addBlock("TX_BH22", 2, 0, 3, 131, 57, false, false);
    gameGrid10->addBlock("TX_BH23", 2, 0, 1, 131, 57, false, false);
    gameGrid10->addBlock("TX_BH25", 2, 0, 0, 131, 57, false, false);
    addGameLevel("Level 10", gameGrid10);
}

void BlockGame::showLoadingScreen() {
    // Load default Font from ResourceManager
    resMan->loadFont(cooperBlackStd, sizeof(cooperBlackStd), "FN_DEFAULT");
    // Create the loading display text and font
    Text loadingText;
    Font font = resMan->getFont("FN_DEFAULT");
    // Configure the loading display text
    loadingText.setFont(font);
    loadingText.setString("Loading Please Wait...");
    loadingText.setCharacterSize(40);
    loadingText.setColor(Color(38, 38, 38));
    // Center the loading display text on the screen
    FloatRect rect = loadingText.getLocalBounds();
    loadingText.setOrigin((rect.left + rect.width) / 2, (rect.top +
        rect.height) / 2);
    loadingText.setPosition((float)window->getSize().x / 2,
        (float)window->getSize().y / 2);
    // Draw the text
    window->clear(Color(64, 64, 64));
    window->draw(loadingText);
    window->display();
}

void BlockGame::loadGameResources() {
    // Load all of the Game's Images, Textures and Fonts
    resMan->loadTexture(bh21, sizeof(bh21), "TX_BH21");
    resMan->loadTexture(bh22, sizeof(bh22), "TX_BH22");
    resMan->loadTexture(bh23, sizeof(bh23), "TX_BH23");
    resMan->loadTexture(bh24, sizeof(bh24), "TX_BH24"); 
    resMan->loadTexture(bh25, sizeof(bh25), "TX_BH25");
    resMan->loadTexture(bh26, sizeof(bh26), "TX_BH26");
    resMan->loadTexture(bh31, sizeof(bh31), "TX_BH31");
    resMan->loadTexture(bh32, sizeof(bh32), "TX_BH32");
    resMan->loadTexture(bv21, sizeof(bv21), "TX_BV21");
    resMan->loadTexture(bv22, sizeof(bv22), "TX_BV22");
    resMan->loadTexture(bv23, sizeof(bv23), "TX_BV23");
    resMan->loadTexture(bv24, sizeof(bv24), "TX_BV24");
    resMan->loadTexture(bv25, sizeof(bv25), "TX_BV25");
    resMan->loadTexture(bv26, sizeof(bv26), "TX_BV26");
    resMan->loadTexture(bv31, sizeof(bv31), "TX_BV31");
    resMan->loadTexture(bv32, sizeof(bv32), "TX_BV32");
    resMan->loadImage(icon, sizeof(icon), "IM_ICON");
    resMan->loadTexture(menuBG, sizeof(menuBG), "TX_BG_MENU");
    resMan->loadTexture(levelBG, sizeof(levelBG), "TX_BG_GAME");
    resMan->loadTexture(btnHover, sizeof(btnHover), "TX_BUTTON_HOVER");
    resMan->loadTexture(btnNormal, sizeof(btnNormal), "TX_BUTTON_NORMAL");
    resMan->loadFont(cooperBlackStd, sizeof(cooperBlackStd), "FN_COPPER");
}
