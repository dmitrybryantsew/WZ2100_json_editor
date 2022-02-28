#ifndef RESEARCHMODEL_HPP
#define RESEARCHMODEL_HPP

#include <QObject>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include "../connectionsNode.hpp"
#include "../connectionGraph.hpp"
class JsonDataModel : public QObject
{
    Q_OBJECT
public:
    explicit JsonDataModel(QObject *parent = nullptr);
    bool readJsonFile(QString filename);
    bool saveToJsonFile();
    bool setObjectProperty(const QString& key, const QString& propertyName, const QJsonValue& value);
    QJsonValue getObjectProperty(const QString& key,const QString& propertyName);
    bool setObject(const QString& key);
    QJsonValue getObject(const QString& key);
    void setupGraphNodes();
    void setupGraphConnections();

    QList<QString> getAllObjects() const;
    const ConnectionGraph& getConnectionGraph() const;

signals:
private:
    QJsonDocument _resData;
    ConnectionGraph _conectGraph;
};

#endif // RESEARCHMODEL_HPP
