#include "ofMain.h"

#include "LanguageNode.h"


LanguageNode::LanguageNode(string name, float x, float y, float size)
    : name(name), x(x), y(y), size(size) {}

void LanguageNode::draw()
{
    ofCircle(x, y, size);
    ofDrawBitmapStringHighlight(name, x, y);
}