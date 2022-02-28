#ifndef CONNECTIONSNODE_HPP
#define CONNECTIONSNODE_HPP

#include <QVector>
#include <QSet>
struct ConnectionsNode
{
public:

    ConnectionsNode(const QString& id, const QString& name);
    void connectTo(ConnectionsNode& other);
    QStringList getInConnections();
    QStringList getOutConnections();
    QString getID() const;
    void setID(const QString& id);
    QString getName() const;
    void setName(const QString& name);

private:
    QSet<QString> _inputConnectionsSet, _outputConnectionsSet; //Todo check to not connect ot itself
    QString _id;
    QString _name; //TODO use or remove
};

#endif // CONNECTIONSNODE_HPP
