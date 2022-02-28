#ifndef CONNECTIONGRAPH_HPP
#define CONNECTIONGRAPH_HPP

#include <QMap>
#include "connectionsNode.hpp"
#include <QJsonObject>
#include <QJsonArray>
class ConnectionGraph : public QObject
{
    Q_OBJECT
public:
    ConnectionGraph();
    ConnectionGraph(const QJsonObject& rootObject);
    ~ConnectionGraph();
    void createNodes(const QJsonObject& rootObject);
    void createConnections(const QJsonObject& rootObject);
    QStringList getInConnections(const QString& id) const;
    QStringList getOutConnections(const QString& id) const;
    QString getNodeName(const QString& id) const;
    QList<QString> getAllObjects() const ;
signals:
    void nodesConnected(const QString&, const QString&);
private:
    QMap<QString, ConnectionsNode*> _connectionGraphData;
};

#endif // CONNECTIONGRAPH_HPP
