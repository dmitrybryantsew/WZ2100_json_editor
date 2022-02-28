#include "editTableWidget.hpp"
#include "ui_editTableWidget.h"
EditTableWidget::EditTableWidget(const QJsonValue& jsonValue, QWidget *parent) :
    QWidget(parent), ui(new Ui::editTableWidget), _editTableController(EditTableController(jsonValue))

{
    ui->setupUi(this);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    setWindowFlags(Qt::Window | Qt::WindowCloseButtonHint);
    this->setAttribute(Qt::WA_DeleteOnClose);

    ui->tableView->setModel(&_editTableController.getModel());
    ui->tableView->horizontalHeader()->setStretchLastSection(true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::DoubleClicked);
}

EditTableWidget::~EditTableWidget()
{
    delete ui;
}
