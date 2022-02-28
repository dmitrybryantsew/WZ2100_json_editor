#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QFileDialog>
#include "JsonDataController.hpp"
#include "researchWidget.hpp"
#include "editTableWidget.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void callEditTableWidget(const QString& name);

private slots:
    void on_actionOpen_json_file_triggered();

private:
    //utility functions

    //members
    JsonDataController _controller;
    ResearchWidget* _rWidget;
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_HPP
