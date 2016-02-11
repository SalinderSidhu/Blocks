#include <string>
#include <exception>
#include "Engine/Game.hpp"
#include "Levels/WinLevel.hpp"
#include "Levels/GameLevel.hpp"
#include "Objects/GameGrid.hpp"
#include "Levels/MenuLevel.hpp"
#include "Engine/SaveObject.hpp"
#include "Engine/ResourceManager.hpp"
using namespace sf;
using namespace std;

int main() {
	// Game constants
	const string resFileHash =
		"1b68baabebca8455942322ce77f8c99f707f0ead64e1cf27ab54577b06289b60";
	const string resFile = "data.7z";
	const string title = "Blocks";
	const int winWidth = 600;
	const int winHeight = 700;
	const int FPS = 60;
	const int bits = 32;
	// Initialize the Game
	Game game = Game(title, winWidth, winHeight, bits, FPS, resFile,
		resFileHash);
	// Obtain the ResourceManager and RenderWindow from Game
	ResourceManager *resMan = game.getResourceManager();
	RenderWindow *window = game.getWindow();
	SaveObject *saveObj = game.getSaveObject();
	// Try to call functions from ResourceManager
	try {
		// Load all of the Game's Images, Textures, Sounds and Fonts
		resMan->loadImage("icon.png", "IM_ICON");
		resMan->loadTexture("bh21.png", "TX_BH21");
		resMan->loadTexture("bh22.png", "TX_BH22");
		resMan->loadTexture("bh23.png", "TX_BH23");
		resMan->loadTexture("bh24.png", "TX_BH24");
		resMan->loadTexture("bh25.png", "TX_BH25");
		resMan->loadTexture("bh26.png", "TX_BH26");
		resMan->loadTexture("bh31.png", "TX_BH31");
		resMan->loadTexture("bh32.png", "TX_BH32");
		resMan->loadTexture("bv21.png", "TX_BV21");
		resMan->loadTexture("bv22.png", "TX_BV22");
		resMan->loadTexture("bv23.png", "TX_BV23");
		resMan->loadTexture("bv24.png", "TX_BV24");
		resMan->loadTexture("bv25.png", "TX_BV25");
		resMan->loadTexture("bv26.png", "TX_BV26");
		resMan->loadTexture("bv31.png", "TX_BV31");
		resMan->loadTexture("bv32.png", "TX_BV32");
		resMan->loadSound("victory.ogg", "SN_VICTORY");
		resMan->loadSound("hover.ogg", "SN_BUTTON_HOVER");
		resMan->loadSound("click.ogg", "SN_BUTTON_CLICK");
		resMan->loadSound("musicbg.ogg", "MS_BACKGROUND");
		resMan->loadTexture("button.png", "TX_BUTTON_NORMAL");
		resMan->loadTexture("menubg.png", "TX_BACKGROUND_MENU");
		resMan->loadTexture("levelbg.png", "TX_BACKGROUND_GAME");
		resMan->loadTexture("button_select.png", "TX_BUTTON_HOVER");
		resMan->loadFont("CooperBlackStd.otf", "FN_COPPER"); // Must load last
		// Add an icon to the Game's window
		Image icon = resMan->getImage("IM_ICON");
		window->setIcon(icon.getSize().x, icon.getSize().y,
			icon.getPixelsPtr());
		// Create and setup the main menu level
		MenuLevel *mainMenuLevel = new MenuLevel(title, resMan, window,
			saveObj);
		// Create Level 1 and setup level 1 GameGrid
		GameGrid *gameGrid1 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
			winWidth, 640, resMan);
		gameGrid1->addBlock("TX_BV31", 3, 2, 0, 58, 221, true, false);
		gameGrid1->addBlock("TX_BH26", 2, 4, 0, 131, 57, false, false);
		gameGrid1->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
		gameGrid1->addBlock("TX_BH32", 3, 0, 3, 221, 57, false, false);
		gameGrid1->addBlock("TX_BV32", 3, 5, 3, 58, 221, true, false);
		GameLevel *gameLevel1 = new GameLevel("Level 1", resMan, window,
			saveObj);
		gameLevel1->setGameGrid(gameGrid1);
		WinLevel *winLevel1 = new WinLevel("Level 1", resMan, window, saveObj);
		// Create Level 2 and setup level 2 GameGrid
		GameGrid *gameGrid2 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
			winWidth, 640, resMan);
		gameGrid2->addBlock("TX_BV31", 3, 2, 0, 58, 221, true, false);
		gameGrid2->addBlock("TX_BH21", 2, 3, 2, 131, 57, false, true);
		gameGrid2->addBlock("TX_BV32", 3, 5, 1, 58, 221, true, false);
		gameGrid2->addBlock("TX_BH31", 3, 0, 3, 221, 57, false, false);
		gameGrid2->addBlock("TX_BV25", 2, 3, 3, 58, 131, true, false);
		gameGrid2->addBlock("TX_BH23", 2, 4, 4, 131, 57, false, false);
		GameLevel *gameLevel2 = new GameLevel("Level 2", resMan, window,
			saveObj);
		gameLevel2->setGameGrid(gameGrid2);
		WinLevel *winLevel2 = new WinLevel("Level 2", resMan, window, saveObj);
		// Create Level 3 and setup level 3 GameGrid
		GameGrid *gameGrid3 = new GameGrid(55, 167, 480, 470, 375, 327, 80,
			winWidth, 640, resMan);
		gameGrid3->addBlock("TX_BV25", 2, 0, 0, 58, 131, true, false);
		gameGrid3->addBlock("TX_BV22", 2, 1, 0, 58, 131, true, false);
		gameGrid3->addBlock("TX_BH23", 2, 2, 0, 131, 57, false, false);
		gameGrid3->addBlock("TX_BH26", 2, 2, 1, 131, 57, false, false);
		gameGrid3->addBlock("TX_BV23", 2, 4, 0, 58, 131, true, false);
		gameGrid3->addBlock("TX_BH21", 2, 0, 2, 131, 57, false, true);
		gameGrid3->addBlock("TX_BV25", 2, 2, 2, 131, 57, true, false);
		gameGrid3->addBlock("TX_BV24", 2, 2, 4, 58, 131, true, false);
		gameGrid3->addBlock("TX_BV31", 3, 3, 2, 58, 221, true, false);
		gameGrid3->addBlock("TX_BV26", 2, 4, 3, 58, 131, true, false);
		GameLevel *gameLevel3 = new GameLevel("Level 3", resMan, window,
			saveObj);
		gameLevel3->setGameGrid(gameGrid3);
		WinLevel *winLevel3 = new WinLevel("Level 3", resMan, window, saveObj);
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
		GameLevel *gameLevel4 = new GameLevel("Level 4", resMan, window,
			saveObj);
		gameLevel4->setGameGrid(gameGrid4);
		WinLevel *winLevel4 = new WinLevel("Level 4", resMan, window, saveObj);
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
		GameLevel *gameLevel5 = new GameLevel("Level 5", resMan, window,
			saveObj);
		gameLevel5->setGameGrid(gameGrid5);
		WinLevel *winLevel5 = new WinLevel("Level 5", resMan, window, saveObj);
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
		GameLevel *gameLevel6 = new GameLevel("Level 6", resMan, window,
			saveObj);
		gameLevel6->setGameGrid(gameGrid6);
		WinLevel *winLevel6 = new WinLevel("Level 6", resMan, window, saveObj);
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
		GameLevel *gameLevel7 = new GameLevel("Level 7", resMan, window,
			saveObj);
		gameLevel7->setGameGrid(gameGrid7);
		WinLevel *winLevel7 = new WinLevel("Level 7", resMan, window, saveObj);
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
		GameLevel *gameLevel8 = new GameLevel("Level 8", resMan, window,
			saveObj);
		gameLevel8->setGameGrid(gameGrid8);
		WinLevel *winLevel8 = new WinLevel("Level 8", resMan, window, saveObj);
		// Create Level 9 and setup Level 9 GameGrid
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
		GameLevel *gameLevel9 = new GameLevel("Level 9", resMan, window,
			saveObj);
		gameLevel9->setGameGrid(gameGrid9);
		WinLevel *winLevel9 = new WinLevel("Level 9", resMan, window, saveObj);
		// Create Level 10 and setup Level 10 GameGrid
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
		GameLevel *gameLevel10 = new GameLevel("Level 10", resMan, window,
			saveObj);
		gameLevel10->setGameGrid(gameGrid10);
		WinLevel *winLevel10 = new WinLevel("Level 10", resMan, window,
			saveObj);
		// Add all levels to the Game
		game.addLevel(mainMenuLevel);
		game.addLevel(gameLevel1);
		game.addLevel(winLevel1);
		game.addLevel(gameLevel2);
		game.addLevel(winLevel2);
		game.addLevel(gameLevel3);
		game.addLevel(winLevel3);
		game.addLevel(gameLevel4);
		game.addLevel(winLevel4);
		game.addLevel(gameLevel5);
		game.addLevel(winLevel5);
		game.addLevel(gameLevel6);
		game.addLevel(winLevel6);
		game.addLevel(gameLevel7);
		game.addLevel(winLevel7);
		game.addLevel(gameLevel8);
		game.addLevel(winLevel8);
		game.addLevel(gameLevel9);
		game.addLevel(winLevel9);
		game.addLevel(gameLevel10);
		game.addLevel(winLevel10);
		// Start the Game
		game.start();
	} catch(exception &ex) {
		// Display error message and exit game if an exception was thrown
		game.getDialog()->showError(ex.what());
		window->close();
		// Exit with failure
		return 1;
	}
	// Exit with success
	return 0;
}
