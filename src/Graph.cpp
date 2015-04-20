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
    int a = 250 ,b = 0 ,c = 200;
    for (auto ln : language_nodes) {
        ln->draw(a,b,c);
        a = (a - 80) % 255;
        b = (b + 40) % 255;
        c = (c - 20) % 255;
    }
}

void Graph::step()
{
    for (auto rn : repository_nodes) {
        if (app->getDragged() == NULL || app->getDragged()->getName() != rn->getName()) {
            rn->step();
        }
    }
    for (auto ln : language_nodes) {
        ln->step();
    }
}

void Graph::setApp(ofApp *a)
{
    app = a;
}

ofApp *Graph::getApp()
{
    return app;
}

std::vector<LanguageNode *> Graph::getLanguageNodes() const { return language_nodes; };
std::vector<RepositoryNode *> Graph::getRepositoryNodes() const { return repository_nodes; };
