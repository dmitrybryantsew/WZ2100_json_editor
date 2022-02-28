#ifndef EDITTABLEWIDGET_HPP
#define EDITTABLEWIDGET_HPP

#include <QWidget>
#include <QJsonObject>
#include "editTableController.hpp"
namespace Ui {
class editTableWidget;
}

class EditTableWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EditTableWidget(const QJsonValue& jsonValue, QWidget *parent = nullptr);
    ~EditTableWidget();

private:
    Ui::editTableWidget *ui;
    EditTableController _editTableController;
};

#endif // EDITTABLEWIDGET_HPP
