#include "mainwindow.hpp"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), _rWidget(new ResearchWidget(this)),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //connect(ui->actionOpen_json_file, &QAction::triggered, this, &MainWindow::on_actionOpen_json_file_triggered, Qt::UniqueConnection);
    ui->horizontalLayout->addWidget(_rWidget);
    connect(&_rWidget->_stringEmitter, &EmitterObject::graphicNodePressedSignal, this, &MainWindow::callEditTableWidget);
    connect(&_controller.getConnectionGraph(), &ConnectionGraph::nodesConnected, _rWidget, &ResearchWidget::connectTwoGraphicItems);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::callEditTableWidget(const QString &name)
{
    qDebug() <<"name is " <<  name;
    auto obj = _controller.getObject(name);
    auto myWidget = new EditTableWidget(obj);
    myWidget->setWindowModality(Qt::ApplicationModal);
    myWidget->show();

}

void MainWindow::on_actionOpen_json_file_triggered()
{
    auto fileName = QFileDialog::getOpenFileName(this,
                                                 tr("Open Json"), "./../",
                                                 tr("json Files (*.json)"));
    _controller.readJsonFile(fileName);

    if(fileName.contains("research.json")){
        qDebug() << "processing nodes!!!";
        _controller.setupGraphNodes();
    }

    QList<QPair<QString, QString>> resIDsAndNames;
    for (auto& str : _controller.getAllObjects()){
        resIDsAndNames.append({_controller.getObjectProperty(str, "id").toString(), _controller.getObjectProperty(str, "name").toString()}); //TODO fix
    }
    _rWidget->addAllRes(resIDsAndNames);

    if(fileName.contains("research.json")){

        _controller.setupGraphConnections();
        qDebug() << "DONE!!!!!!!";
    }
}



