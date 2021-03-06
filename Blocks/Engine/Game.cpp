#include "Game.hpp"

Game::Game(string title, int width, int height, int bits, int FPS) {
    // Initialize and setup the game RenderWindow
    window = new RenderWindow(VideoMode(width, height, bits), title,
        Style::Close);
    window->setFramerateLimit(FPS);
    // Initialize and setup the Dialog
    dialog = new Dialog(title, window);
    // Initialize and setup the ResourceManager
    try {
        resMan = new ResourceManager();
    } catch(exception &ex) {
        // Display error message and exit game if an exception was thrown
        dialog->showError(ex.what());
        window->close();
    }
    // Initialize the SaveObject
    saveObj = new SaveObject();
    // Set remaining instance variables
    currentLevelCount = 0;
}

Game::~Game() {
    // Free memory used by the instance pointers
    delete window;
    window = NULL;
    delete dialog;
    dialog = NULL;
    // Free memory used by all the LevelObject pointers
    vector<LevelObject*>::iterator iter;
    for(iter = levels.begin(); iter != levels.end(); iter++) {
        delete (*iter);
        (*iter) = NULL;
    }
}

ResourceManager *Game::getResourceManager() {
    // Return the ResourceManager
    return resMan;
}

RenderWindow *Game::getWindow() {
    // Return the RenderWindow pointer
    return window;
}

Dialog *Game::getDialog() {
    // Return the Dialog pointer
    return dialog;
}

SaveObject *Game::getSaveObject() {
    // Return the SaveObject pointer
    return saveObj;
}

void Game::addLevel(LevelObject *level) {
    // Add LevelObject pointer to the collection of LevelObject pointers
	levels.push_back(level);
}

void Game::start() {
    // Check if any LevelObject exist
    if (levels.size() > 0) {
        // Set the currentLevel to the first LevelObject pointer
        currentLevel = levels[0];
        gameLoop();
    } else {
        // Throw EngineException
        throw EngineException("Error: Cannot load Level, does not exist");
    }
}

void Game::gameLoop() {
    while(window->isOpen()) {
        // Process all input events for the current level
        Event event;
        while(window->pollEvent(event)) {
            // Default window close event
            if (event.type == Event::Closed) {
                window->close();
            }
            // Get the position of the mouse relative to the window
            Vector2i mousePosition = Mouse::getPosition(*window);
            currentLevel->processEvents(&event, mousePosition);
        }
        // Process all update events for the current level
        currentLevel->update();
        processLevelComplete();
        // Process all drawing events for the current level
        window->clear();
        currentLevel->draw();
        window->display();
    }
}

void Game::processLevelComplete() {
    // Process level completed event
    if (currentLevel->isFinished()) {
        // Reset the current level so it can be reused later
        currentLevel->reset();
        // NULL the currentLevel pointer
        currentLevel = NULL;
        // Increment currentLevelCount
        if (currentLevelCount + 1 < levels.size()) {
            currentLevelCount++;
        } else {
            // If currentLevel is the last level then reset the level counter
            currentLevelCount = 0;
        }
        currentLevel = levels[currentLevelCount];
    }
}
