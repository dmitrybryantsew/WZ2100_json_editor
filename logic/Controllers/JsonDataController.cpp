#include "JsonDataController.hpp"

JsonDataController::JsonDataController(QObject *parent)
    : QObject{parent}
{

}

bool JsonDataController::readJsonFile(QString filename)
{
    return _model.readJsonFile(filename);
}

bool JsonDataController::saveJsonFile()
{
    return _model.saveToJsonFile();
}

bool JsonDataController::setObjectProperty(QString key, QString propertyName, QJsonValue value)
{
    return _model.setObjectProperty(key, propertyName, value);
}

QJsonValue JsonDataController::getObjectProperty(const QString &key, const QString &propertyName)
{
    return _model.getObjectProperty(key, propertyName);
}

bool JsonDataController::setObject(const QString &key)
{
    return _model.setObject(key);
}

QJsonValue JsonDataController::getObject(const QString &key)
{
    return _model.getObject(key);
}

void JsonDataController::setupGraphNodes()
{
    _model.setupGraphNodes();
}

void JsonDataController::setupGraphConnections()
{
    _model.setupGraphConnections();
}

const ConnectionGraph &JsonDataController::getConnectionGraph() const
{
    return _model.getConnectionGraph();
}

QList<QString> JsonDataController::getAllObjects() const
{
    return _model.getAllObjects();
}

