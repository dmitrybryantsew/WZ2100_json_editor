#include "connectionsNode.hpp"

ConnectionsNode::ConnectionsNode(const QString &id, const QString &name) : _id(id), _name(name)
{}

void ConnectionsNode::connectTo(ConnectionsNode &other)
{
    _outputConnectionsSet.insert( other._id);
    other._inputConnectionsSet.insert( this->_id);
}

QStringList ConnectionsNode::getInConnections()
{
    QStringList retVal;
    for(auto& e : qAsConst(_inputConnectionsSet)){
        retVal << e;
    }
    return retVal;
}

QStringList ConnectionsNode::getOutConnections()
{
    QStringList retVal;
    for(const auto& e : qAsConst(_outputConnectionsSet)){
        retVal << e;
    }
    return retVal;
}

QString ConnectionsNode::getID() const
{
    return _id;
}

void ConnectionsNode::setID(const QString& id)
{
    _id = id;
}

QString ConnectionsNode::getName() const
{
    return _name;
}

void ConnectionsNode::setName(const QString &name)
{
    _name = name;
}
