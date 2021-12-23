#include "block.h"
#include <cmath>
#include <iostream>

/* Returns the width, in pixels
 * of the current block
 */
int Block::width() const
{
    // Your code here!
    return data[0].size();
}

/* Returns the width, in pixels
 * of the current block
 */
int Block::height() const
{
    // Your code here!
    return data.size();
}

/* Given an image whose size is large enough, place
 * the current block in the image so that its upper left corner
 * is at position column, row. Existing pixels in the image
 * will be replaced by those of the block.
 */
void Block::render(PNG &im, int column, int row) const
{
    // Your code here!
    for (unsigned int x = column; x < (unsigned int) column + width(); x++) {
        for (unsigned int y = row; y < (unsigned int) row + height(); y++) {
            *im.getPixel(x,y) = data[y - row][x - column];
        }
    }
}

/* create a block of pixels whose color values are the same as the
 * rectangle in the image described by the upper left corner (column, row)
 * whose size is width x height.
 */
void Block::build(PNG &im, int column, int row, int width, int height)
{
    // Your code here!
    vector<vector<HSLAPixel>> pic;

    for(unsigned int y = row; y < row + height; y++){
        vector<HSLAPixel> row;
        for(unsigned int x = column; x < column + width; x++){
            HSLAPixel *pixel = im.getPixel(x,y);
            row.push_back(*pixel);
        }
        pic.push_back(row);
    } 
    data = pic;
}

/* Flip the current block across its horizontal midline.
 * This function changes the existing block.
 */
void Block::flipVert()
{
    vector<vector<HSLAPixel>> pic;
    for(int y = height() - 1; y > -1; y--){
        vector<HSLAPixel> row;
        for(int x = 0; x < width(); x++){
            HSLAPixel pixel = data[y][x];
            row.push_back(pixel);
        }
        pic.push_back(row);
    }
    data = pic;
    // Your code here!   
}


/* Flip the current block across its vertical midline.
 * This function changes the existing block.
 */
void Block::flipHoriz()
{
    // Your code here!
    vector<vector<HSLAPixel>> pic;
    for(int y = 0; y < height(); y++){
        vector<HSLAPixel> row;
        for(int x = width() - 1; x > -1; x--){
            HSLAPixel pixel = data[y][x];
            row.push_back(pixel);
        }
        pic.push_back(row);
    } 
    data = pic;
}

/* Rotate the current block 90 degrees counterclockwise.
 * This function changes the existing block.
 */
void Block::rotateRight()
{
    // Your code here!
    vector<vector<HSLAPixel>> pic;
    for(int x = 0; x < width(); x++){
        cout << "reached line 103";
        vector<HSLAPixel> col;
        for(int y = height() - 1; y > -1; y--){
            cout << "reached line 106";
            HSLAPixel pixel = data[y][x];
            col.push_back(pixel);
        }
        cout << "reached line 111";
        pic.push_back(col);
    } 
    cout << "reached line 114";
    data = pic; 
}

