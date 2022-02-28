#include "connectionGraph.hpp"



ConnectionGraph::ConnectionGraph()
{

}

ConnectionGraph::ConnectionGraph(const QJsonObject& rootObject)
{
    createNodes(rootObject);
    createConnections(rootObject);
}

ConnectionGraph::~ConnectionGraph()
{
    for (auto it = _connectionGraphData.begin(); it != _connectionGraphData.end(); it++){
        delete *it; //todo uptr??
    }
    _connectionGraphData.clear();
}

void ConnectionGraph::createNodes(const QJsonObject &rootObject)
{
    auto stringList = rootObject.keys();

    //create all possible researches
    for (auto& id : stringList){
        auto object = rootObject.find(id).value(); //TODO fix are we even need this?
        if(object.isNull()) {
            qDebug() << "no such object in this json file";

        }
        QJsonObject requiredObject = object.toObject();
        auto name = requiredObject.find("name").value().toString();
        _connectionGraphData[id] = new ConnectionsNode(id, name); //todo uptr??
    }
}

void ConnectionGraph::createConnections(const QJsonObject& rootObject)
{
    //for every res
    for (auto& connectionsNode : _connectionGraphData){
        //get exact res copy // perhaps using iterators might be faster but it works fast enough
        auto concreteResValueRef = rootObject.find(connectionsNode->getID()).value();
        QJsonObject concreteResObject = concreteResValueRef.toObject();
        //if there is prerequired researches
        if(concreteResObject["requiredResearch"].isArray()){
            auto array = concreteResObject["requiredResearch"].toArray();
            //connect iterated res with its prerequired researches
            for (auto el : array){
                QString firstnodeID = el.toString();
                QString secondNodeID = connectionsNode->getID();
                _connectionGraphData[firstnodeID]->connectTo(*connectionsNode);
                emit nodesConnected(firstnodeID, secondNodeID);
            }
        }

    }
}

QStringList ConnectionGraph::getInConnections(const QString &id) const
{
    return _connectionGraphData[id]->getInConnections();
}

QStringList ConnectionGraph::getOutConnections(const QString &id) const
{
    return _connectionGraphData[id]->getOutConnections();
}

QString ConnectionGraph::getNodeName(const QString& id) const
{
    return _connectionGraphData[id]->getName();
}

QList<QString> ConnectionGraph::getAllObjects() const
{
    return _connectionGraphData.keys();
}


