#ifndef RESEARCHCONTROLLER_HPP
#define RESEARCHCONTROLLER_HPP

#include <QObject>
#include "../Models/JsonDataModel.hpp" //TODO cant find file without full path
class JsonDataController : public QObject
{
    Q_OBJECT
public:
    explicit JsonDataController(QObject *parent = nullptr);
    bool readJsonFile(QString filename);
    bool saveJsonFile();
    bool setObjectProperty(QString key, QString propertyName, QJsonValue value);
    QJsonValue getObjectProperty(const QString& key,const QString& propertyName);
    bool setObject(const QString& key);
    QJsonValue getObject(const QString& key);
    void setupGraphNodes();
    void setupGraphConnections();
    const ConnectionGraph& getConnectionGraph() const;
    //remove later
    QList<QString> getAllObjects() const;


signals:
private:
    JsonDataModel _model;
};

#endif // RESEARCHCONTROLLER_HPP
