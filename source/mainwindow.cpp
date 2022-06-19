#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "./functions.h"
#include <QVBoxLayout>
#include <QCheckBox>
#include <QFrame>
#include <QLabel>
#include <QMessageBox>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

using namespace std;

//funkcja rozdzielajaca podany string podzielony danym znakiem.
vector<string> separateBy(string str, char by, bool deleteSpaces){
    vector<string> separated;
    string temp="";
    for(int i=0; i<str.length(); i++){
        if(i==str.length()-1){
            temp+=str[i];
            separated.push_back(temp);
        }
        else if(str[i]!=by){
           if(deleteSpaces==1 && str[i]==' ' && by!=' ') continue;
            temp+=str[i];
        }
        else{
            separated.push_back(temp);
            temp="";
        }
    }
    return separated;
}

//funkcja analizujaca plik z przepisami i porzadkujaca go do wektora przyjmujacego klasy recipes, ktore zawieraja nazwe, skladniki i przepis.
vector<recipes> analyseRecipeFile(fstream &file){
//sprawdzenie czy plik nie jest pusty
    file.seekg(0, ios::end);
    if(file.tellg()==0) return {};
    else{
        file.seekg(0, ios::beg);
    vector<recipes> recipe;
    string line="";
    string temp="";
    while(file){
        getline(file, line);
        if(!(line=="")){
//recipes object;
        recipes object;
//nazwa potrawy
        for(int i=6; line[i]!=39; i++){
            temp+=line[i];
        }
        object.name=temp;
        temp="";
//tablica skladnikow
        for(int i=(int)line.find("[")+1; line[i]!=']'; i++){
            temp+=line[i];
        }
        object.ingredients=separateBy(temp, ',');
        temp="";
//przepis
        for(int i=(int)line.find("recipe='")+8; line[i]!=39; i++){
            temp+=line[i];
        }
        object.recipe=temp;
        temp="";
        recipe.push_back(object);
    }
    }
    file.close();
    return recipe;
    }
}

//funkcja pozwalajaca uzytkownikowi dodawac przepisy
void addRecipe(string name, string ingredients, string recipe){
    fstream file("recipesBase.txt", ios::out | ios::app);
    file.seekg(0, ios::end);
    file<<"name='"<<name<<"' ingredients=["<<ingredients<<"] recipe='"<<recipe<<"'"<<endl;
    file.close();
}

//funkcja pozwalajaca usuwac przepisy
void MainWindow::deleteRecipe(){
    fstream fileTemp("recipesBase.txt", ios::in);
    QPushButton *button = (QPushButton*) sender();
    string name = button->objectName().toStdString();
    string line=""; string temp="";
    vector<recipes> analysedFile=analyseRecipeFile(fileTemp);
    fstream file("recipesBase.txt", ios::in);
    string toFind="name='"+name;
    bool flag=0;

    //szukanie danego przepisu w pliku
    ofstream out("outfile.txt");
    while(getline(file,line))
       {
           if (line.find(toFind) == string::npos){
               out << line << "\n";
           }
       }
    file.close();
    out.close();
    remove("recipesBase.txt");
    rename("outfile.txt","recipesBase.txt");
    QMessageBox::information(this, "Sukces", "Przepis poprawnie usunięty z bazy. Zmiany będą widoczne po ponownym otwarciu bazy.");
}

//szukanie skladnikow, ktore wystepuja w jakimkolwiek przepisie
vector <string> searchIngredients(){
    fstream fileRecipes("recipesBase.txt", ios::in);
    vector<recipes> analysedFile=analyseRecipeFile(fileRecipes);
    vector <string> ingredients;
    bool flag=0;
    for(int i=0; i<analysedFile.size(); i++){
        for(int j=0; j<analysedFile[i].ingredients.size(); j++){
            flag=0;
            for(int k=0; k<ingredients.size(); k++){
                if(analysedFile[i].ingredients[j]==ingredients[k]){
                    flag=1;
                }
            }
            if(flag==0) ingredients.push_back(analysedFile[i].ingredients[j]);
        }
    }

    fileRecipes.close();
               return ingredients;
}

//szukanie w pliku przepisow, ktore spelniaja skladniki podane przez uzytkownika
vector <recipes> searchRecipes(vector <string> chosenIngredients){
    vector <recipes> possibleRecipes;
    fstream fileRecipes("recipesBase.txt", ios::in);
    vector<recipes> analysedFile=analyseRecipeFile(fileRecipes);

    int flag=0;
    for(int i=0; i<analysedFile.size(); i++){
        for(int j=0; j<analysedFile[i].ingredients.size(); j++){
            for(int k=0; k<chosenIngredients.size(); k++) {
                if(chosenIngredients[k]==analysedFile[i].ingredients[j]) flag++;
            }
        }
        if(analysedFile[i].ingredients.size() == flag)
            possibleRecipes.push_back(analysedFile[i]);
        flag=0;
    }

    fileRecipes.close();
    return possibleRecipes;
}


void MainWindow::on_viewAll_Button_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
    QWidget *w = new QWidget;
    ui->scrollArea->setWidget(w);
    ui->scrollArea->setWidgetResizable(true);
    QVBoxLayout *layout = new QVBoxLayout(w);
    fstream fileRecipes("recipesBase.txt", ios::in);
    fileRecipes.seekg(0, ios::end);

    if(fileRecipes.tellg() != 0) {
        fileRecipes.seekg(0, ios::beg);
        vector<recipes> analysedFile=analyseRecipeFile(fileRecipes);

        for(int i=0; i<analysedFile.size(); i++){
            QWidget *recipe = new QWidget();
            QVBoxLayout *recipeLayout = new QVBoxLayout(recipe);
            recipe->setGeometry(65, 65, 800, 150);

            QLabel *header = new QLabel;
            header->setText(QString::fromStdString(analysedFile[i].name));
            QFont headerFont("Montserrat SemiBold", 16);
            header->setFont(headerFont);
            header->setGeometry(30, 30, 400, 120);
            recipeLayout ->addWidget(header);

            QLabel *timer  = new QLabel;
            timer->setText("Czas przygotowania: 20 minut");
            QFont newFont("Montserrat Medium", 10);
            timer->setFont(newFont);
            timer->setGeometry(30, 60, 160, 30);
            recipeLayout ->addWidget(timer);

            QLabel *ingredients  = new QLabel;
            string ingredientsString = "Składniki: ";
            for(int j=0; j<analysedFile[i].ingredients.size(); j++) {
                ingredientsString += analysedFile[i].ingredients[j];
                if( j != (analysedFile[i].ingredients.size() - 1)) ingredientsString += ", ";
            }
            ingredients->setText(QString::fromStdString(ingredientsString));
            QFont ingredientsFont("Montserrat Medium", 12);
            ingredients->setFont(ingredientsFont);
            ingredients->setGeometry(30, 90, 160, 30);
            recipeLayout->addWidget(ingredients);

            QLabel *recipeText = new QLabel;
            recipeText->setText(QString::fromStdString(analysedFile[i].recipe));
            QFont recipeFont("Montserrat Medium", 12);
            recipeText->setFont(recipeFont);
            recipeText->setGeometry(30, 90, 500, 300);
            recipeText->setWordWrap(true);
            recipeLayout->addWidget(recipeText);

            layout->addWidget(recipe);

        }
   }
    fileRecipes.close();
}


void MainWindow::on_label_linkActivated(const QString &link)
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_saveRecipe_clicked()
{
    string recipeName = ui->recipeName->text().toStdString();
    string ingredients = ui->addedIngredients->text().toStdString();
    string recipe = ui->recipe->toPlainText().toStdString();
    if (recipeName != "" && ingredients != "" && recipe != "") {
        addRecipe(recipeName, ingredients, recipe);
        QMessageBox::information(this, "Sukces", "Przepis poprawnie dodany do bazy!");
        ui->stackedWidget->setCurrentIndex(0);
    }
    else {
        QMessageBox::critical(this, "Błąd", "Uzupełnij brakujące pola!");
    }
}


void MainWindow::on_addIngredient_clicked()
{
    QString ingredient = ui->ingredient->text();
    if (ui->addedIngredients->text() != "")
        ui->addedIngredients->setText(ui->addedIngredients->text() + ", " + ingredient);
    else
        ui->addedIngredients->setText(ingredient);
    ui->ingredient->clear();

}


void MainWindow::on_viewAll_Button_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_viewAll_Button_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    QWidget *w = new QWidget;
    ui->scrollArea_2->setWidget(w);
    ui->scrollArea_2->setWidgetResizable(true);
    QVBoxLayout *layout = new QVBoxLayout(w);
    fstream fileRecipes("recipesBase.txt", ios::in);
    fileRecipes.seekg(0, ios::end);

    if(fileRecipes.tellg() != 0) {
        fileRecipes.seekg(0, ios::beg);
        vector<recipes> analysedFile=analyseRecipeFile(fileRecipes);

        for(int i=0; i < analysedFile.size(); i++){
            QWidget *recipe = new QWidget();
            QHBoxLayout *recipeLayout = new QHBoxLayout(recipe);
            recipe->setGeometry(0, 20, 800, 40);

            QLabel *header = new QLabel;
            header->setText(QString::fromStdString(analysedFile[i].name));
            QFont headerFont("Montserrat SemiBold", 16);
            header->setFont(headerFont);
            header->setGeometry(30, 10, 181, 20);
            recipeLayout ->addWidget(header);

            QPushButton *button = new QPushButton;
            button->setObjectName(QString::fromStdString(analysedFile[i].name));
            button->setText("Usuń przepis");
            button->setGeometry(400, 5, 330, 31);
            recipeLayout->addWidget(button);

            layout->addWidget(recipe);

            connect(button, SIGNAL(clicked()), this, SLOT(deleteRecipe()));

        }
   }
    fileRecipes.close();
}


void MainWindow::on_viewAll_Button_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
    vector <string> foundIngredients=searchIngredients();
    int w = 0;
    int c = 0;
    for(int k=0; k<foundIngredients.size(); k++) {
        QCheckBox *ingredient = new QCheckBox;
        QString ingredientName = QString::fromStdString(foundIngredients[k]);
        ingredient->setObjectName(ingredientName);
        ingredient->setText(ingredientName);
        if (k % 4 == 0) {
            w += 1;
            c = 0;
        }

        ui->gridLayout->addWidget(ingredient, w, c);
        c += 1;
    }
}



void MainWindow::on_filterButton_clicked()
{
    vector <string> chosenIngredients;
    QList<QCheckBox *> chosenIngredientsCheckboxes = ui->central->findChildren<QCheckBox *>();
    qDebug() << chosenIngredientsCheckboxes;
    for (const auto *ing: chosenIngredientsCheckboxes) {
        if (ing->isChecked())
            chosenIngredients.push_back(ing->objectName().toStdString());
    }

    if (chosenIngredients.size() == 0) {
        QMessageBox::critical(this, "Błąd", "Nie wybrano składników.");
    }
    else {
        vector<recipes> foundRecipes = searchRecipes(chosenIngredients);
        if (foundRecipes.size() == 0)
            QMessageBox::information(this, "Nie znaleziono", "Nie znaleziono przepisu o danych składnikach.");
        else {
            QWidget *w = new QWidget;
            ui->foundRecipesArea->setWidget(w);
            ui->foundRecipesArea->setWidgetResizable(true);
            QVBoxLayout *layout = new QVBoxLayout(w);
            for(int k=0; k<foundRecipes.size(); k++) {
                QWidget *recipe = new QWidget();
                QVBoxLayout *recipeLayout = new QVBoxLayout(recipe);
                recipe->setGeometry(65, 65, 800, 150);

                QLabel *header = new QLabel;
                header->setText(QString::fromStdString(foundRecipes[k].name));
                QFont headerFont("Montserrat SemiBold", 16);
                header->setFont(headerFont);
                header->setGeometry(30, 30, 400, 120);
                recipeLayout ->addWidget(header);

                QLabel *timer  = new QLabel;
                timer->setText("Czas przygotowania: 20 minut");
                QFont newFont("Montserrat Medium", 10);
                timer->setFont(newFont);
                timer->setGeometry(30, 60, 160, 30);
                recipeLayout ->addWidget(timer);

                QLabel *ingredients  = new QLabel;
                string ingredientsString = "Składniki: ";
                for(int j=0; j<foundRecipes[k].ingredients.size(); j++) {
                    ingredientsString += foundRecipes[k].ingredients[j];
                    if( j != (foundRecipes[k].ingredients.size() - 1)) ingredientsString += ", ";
                }
                ingredients->setText(QString::fromStdString(ingredientsString));
                QFont ingredientsFont("Montserrat Medium", 12);
                ingredients->setFont(ingredientsFont);
                ingredients->setGeometry(30, 90, 160, 30);
                recipeLayout->addWidget(ingredients);

                QLabel *recipeText = new QLabel;
                recipeText->setText(QString::fromStdString(foundRecipes[k].recipe));
                QFont recipeFont("Montserrat Medium", 12);
                recipeText->setFont(recipeFont);
                recipeText->setGeometry(30, 90, 500, 300);
                recipeText->setWordWrap(true);
                recipeLayout->addWidget(recipeText);

                layout->addWidget(recipe);
            }
        }
    }
}

