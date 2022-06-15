#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <iostream>
#include <fstream>
#include <filesystem>
#include <regex>

class recipes{
public:
    std::string name;
    std::vector <std::string> ingredients;
    std::string recipe;
};

std::fstream openFile(std::string file);
std::vector<recipes> analyseRecipeFile(std::fstream &file);
std::vector<std::string> separateBy(std::string str, char by, bool deleteSpaces=0);
void addRecipe();
void deleteRecipe();
std::vector <std::string> searchIngredients();
//std::vector <recipes> searchRecipes();
std::vector <recipes> searchRecipes(std::vector <int> chosenIngredients);
std::vector <std::string> chooseIngredients(std::vector <std::string> Ingredients);
std::vector <recipes> searchRecipes(std::vector <std::string> chosenIngredients);
void menu();
void show();
void searchingRecipes();
void showBottomMenu();
bool isNumber(const std::string& str);

#endif
