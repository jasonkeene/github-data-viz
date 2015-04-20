#include "Graph.h"


Graph Graph::buildRandomGraph()
{
    Graph graph;

    // create mock language nodes
    vector<LanguageNode *> mock_languages;
    mock_languages.push_back(new LanguageNode("Python", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("Lua", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("Go", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("Haskell", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));
    mock_languages.push_back(new LanguageNode("C", rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100, rand() % 40 + 10));

    // create mock repository nodes
    for (int i=0; i < 30; i++) {
        // generate repo name
        std::stringstream s;
        s << "jasonkeene/test-rn-";
        s << i;
        string repo_name = s.str();

        RepositoryNode *test_rn = new RepositoryNode(repo_name, rand() % (ofGetWindowWidth()-200) + 100, rand() % (ofGetWindowHeight()-200) + 100);
        int language_count = rand() % mock_languages.size() + 1;
        std::vector<int> languages_used;
        int remaining_percent = 100;
        int percent = 0;

        for (int i = 0; i < language_count; ++i) {
            if (i == language_count - 1) {
                // last language node
                percent = remaining_percent;
            } else {
                percent = rand() % remaining_percent;
            }
            // find random language that isn't used
            LanguageNode *lang;
        find_lang:
            int index = rand() % mock_languages.size();
            for (auto tst : languages_used) {
                if (tst == index) {
                    // index is already used, generate a new one
                    goto find_lang;
                }
            }
            // index hasn't been used yet
            lang = mock_languages[index];
            languages_used.push_back(index);
            test_rn->addLanguageWeight(lang, float(percent) / 100.0);
            remaining_percent -= percent;
        }
        graph.addRepositoryNode(test_rn);
    }

    // build graph
    for (auto ln : mock_languages) {
        graph.addLanguageNode(ln);
    }
    return graph;
}

Graph Graph::buildSimpleGraph()
{
    Graph graph;

    // create mock language nodes
    vector<LanguageNode *> mock_languages;
    mock_languages.push_back(new LanguageNode("Go", 400, 200, 10));
    mock_languages.push_back(new LanguageNode("Python", 400, 600, 10));

    // create mock repository nodes
    RepositoryNode *test_rn = new RepositoryNode("jasonkeene/test-rn", 100, 400);
    test_rn->addLanguageWeight(mock_languages[0], 0.5);
    test_rn->addLanguageWeight(mock_languages[1], 0.5);

    // build graph
    for (auto ln : mock_languages) {
        graph.addLanguageNode(ln);
    }
    graph.addRepositoryNode(test_rn);
    return graph;
}

Graph Graph::buildProductionGraph()
{
    Graph graph;

    // read in prod data

    return graph;
}

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
        if (!rn->hover) {
            rn->draw();
        }
    }
    for (auto ln : language_nodes) {
        ln->draw();
    }
    // redrawn hover repo nodes
    if (app->getHovered() != NULL) {
        app->getHovered()->draw();
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
