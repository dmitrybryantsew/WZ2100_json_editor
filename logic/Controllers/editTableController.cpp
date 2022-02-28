#include "editTableController.hpp"

EditTableController::EditTableController(const QJsonValue& jsonValue, QObject *parent) :  QObject{parent},
      _editTableModel(EditTableModel(jsonValue))
{

}

EditTableModel &EditTableController::getModel()
{
 return _editTableModel;
}
