#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_viewAll_Button_clicked();

    void on_label_linkActivated(const QString &link);

    void on_saveRecipe_clicked();

    void on_addIngredient_clicked();

    void on_viewAll_Button_2_clicked();

    void on_viewAll_Button_4_clicked();

    void deleteRecipe();

    void on_viewAll_Button_3_clicked();

    void on_filterButton_clicked();

private:
    Ui::MainWindow *ui;


};
#endif // MAINWINDOW_H
