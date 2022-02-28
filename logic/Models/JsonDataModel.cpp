#include "JsonDataModel.hpp"

JsonDataModel::JsonDataModel(QObject *parent)
    : QObject{parent}
{}

bool JsonDataModel::readJsonFile(QString filename)
{
    QFile f(filename);
    QJsonParseError jsonError;
    if (f.exists()){
        f.open(QIODevice::ReadOnly | QIODevice::Text);
        _resData = QJsonDocument::fromJson(f.readAll(), &jsonError);
        f.close();
    }
    else{
        qDebug() << "Error: File not found!";
        return false;
    }

    if (_resData.isNull() || _resData.isEmpty()){
        qDebug() << "Error: " << jsonError.errorString() << jsonError.offset;
        return false;
    }
    else{
        qDebug() << "File" << _resData << " has been parsed correctly.";
    }
    return true;
}


bool JsonDataModel::setObjectProperty(const QString& key, const QString& propertyName, const QJsonValue& value)
{
    QJsonObject rootObject = _resData.object();
    QJsonValueRef objectRef = rootObject.find(key).value(); // concrete research // check if exists
    if(objectRef.isNull()) {
        qDebug() << "no such object in this json file";
        return false;
    }
    QJsonObject mutatedObject = objectRef.toObject();
    switch(value.type()){
    case QJsonValue::Null:
        return false;
        break;
    case QJsonValue::Bool:
        if(value.toBool())
            mutatedObject.insert(propertyName, "true");
        else mutatedObject.insert(propertyName, "false");
        break;
    case QJsonValue::Double:
        mutatedObject.insert(propertyName, value.toDouble());
        break;

    case QJsonValue::String:
        mutatedObject.insert(propertyName, value.toString());
        break;
    case QJsonValue::Array:
        mutatedObject.insert(propertyName, value.toArray()); //TODO check
        break;
    case QJsonValue::Object:
        mutatedObject.insert(propertyName, value.toObject()); //TODO check
        break;
    case QJsonValue::Undefined:
        return false; //TODO proper logging
        break;
    }

    objectRef = mutatedObject;
    _resData.setObject(rootObject);
    return true;
}

QJsonValue JsonDataModel::getObjectProperty(const QString& key, const QString& propertyName)
{
    QJsonObject rootObject = _resData.object();
    QJsonValueRef objectRef = rootObject.find(key).value(); // concrete research // check if exists
    if(objectRef.isNull()) {
        qDebug() << "no such object in this json file";

    }
    QJsonObject requiredObject = objectRef.toObject();
    return  QJsonValue(requiredObject.find(propertyName).value());

}

bool JsonDataModel::setObject(const QString &key)
{
    return false;
}

QJsonValue JsonDataModel::getObject(const QString &key)
{
    return QJsonValue(_resData.object().find(key).value());
}

void JsonDataModel::setupGraphNodes()
{
    if(!_resData.isObject()) {
        qDebug() << "no object loaded";
        return ;//TODO fix proper error handling
    }
    auto rootObject = _resData.object();
    _conectGraph.createNodes(rootObject);
}

void JsonDataModel::setupGraphConnections()
{
    if(!_resData.isObject()) {
        qDebug() << "no object loaded";
        return ;//TODO fix proper error handling
    }
    auto rootObject = _resData.object();
    _conectGraph.createConnections(rootObject);

}



QList<QString> JsonDataModel::getAllObjects() const
{
    return _conectGraph.getAllObjects();
}

const ConnectionGraph& JsonDataModel::getConnectionGraph() const
{
    return _conectGraph;
}


bool JsonDataModel::saveToJsonFile()
{
    if (_resData.isNull() || _resData.isEmpty()){
        qDebug() << "error json document is empty";
        return false;
    }

    QFile saveFile("saved.json");

    if (!saveFile.open(QIODevice::WriteOnly)) {
        qWarning("Couldn't open save file.");
        return false;

    }

    saveFile.write(_resData.toJson());
    saveFile.close();
    return true;
}

