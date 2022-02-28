#ifndef EDITTABLECONTROLLER_HPP
#define EDITTABLECONTROLLER_HPP

#include <QObject>
#include "../Models/editTableModel.hpp"
class EditTableController : public QObject
{
    Q_OBJECT
public:
    explicit EditTableController(const QJsonValue& jsonValue, QObject *parent = nullptr);
    EditTableModel& getModel();
signals:
private:
    EditTableModel _editTableModel;
};

#endif // EDITTABLECONTROLLER_HPP
