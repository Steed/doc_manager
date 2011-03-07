#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QLineEdit>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    //¹¤¾ßÀ¸
    QToolButton * add_doc_button;
    QToolButton * del_doc_button;
    QToolButton * create_category_button;
    QToolButton * remove_category_button;
    QLineEdit * searchSquare;

    void initToolbar();
    void initMainArea();
    void initToolbarStyle();
    void initIcons();
};

#endif // MAINWINDOW_H
