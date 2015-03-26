#include "Graph.h"


void Graph::addRepositoryNode(RepositoryNode *rn)
{
    repository_nodes.push_back(rn);
}

void Graph::addLanguageNode(LanguageNode *ln)
{
    language_nodes.push_back(ln);
}

void Graph::draw()
{
    for (auto rn : repository_nodes) {
        rn->draw();
    }
    for (auto ln : language_nodes) {
        ln->draw();
    }
}

void Graph::step()
{
    for (auto rn : repository_nodes) {
        rn->step();
    }
    for (auto ln : language_nodes) {
        ln->step();
    }
}