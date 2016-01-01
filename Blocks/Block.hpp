#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <string>
using namespace std;

/* Block class */
class Block {
    public:
		// Constructor and destructor
		Block(string, string, int, int, int, int, int, int, bool);
		virtual ~Block() {};
        int getX();
        int getY();
        int getSize();
        int getWidth();
        int getLength();
        bool isVictory();
        bool isSelected();
        bool isVertical();
        void setSelected(bool);
        void setX(int);
        void setY(int);
        string getSpriteName();
    private:
        string blockOrient;
        string blockSpriteName;
        int blockX;
        int blockY;
        int blockWidth;
        int blockLength;
        int blockSize;
        bool isBlockSelected;
        bool isVictoryBlock;
};

#endif
