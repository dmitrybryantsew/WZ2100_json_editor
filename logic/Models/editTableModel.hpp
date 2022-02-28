#ifndef EDITTABLEMODEL_HPP
#define EDITTABLEMODEL_HPP

#include <QObject>
#include <QVector>
#include <QMap>
#include <QAbstractTableModel>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>

class EditTableModel : public QAbstractTableModel
{
public:
    //typedef QMap<QString,QString> Heading;
    //typedef QVector<Heading> Header;

    EditTableModel( const QJsonValue& json, QObject * parent = 0);
    bool setData(const QModelIndex &index, const QJsonValue &value, int role = Qt::EditRole) ;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    //bool setJson( const QJsonDocument& json );
    //bool setJson( const QJsonArray& array );

    //virtual QJsonObject getJsonObject( const QModelIndex &index ) const;

    virtual QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const;
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) const;
    virtual int columnCount(const QModelIndex &parent = QModelIndex()) const;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
signals:
    void editCompleted(QString);
private:
    QVector<QString> _verticalHeader;
    //Header m_header;
    QJsonValue _json;
};

#endif // EDITTABLEMODEL_HPP
