#include "editTableModel.hpp"

EditTableModel::EditTableModel( const QJsonValue& json, QObject * parent )
    : QAbstractTableModel( parent )
    , _json( json )
{
    qDebug() << _json.toObject().size() << " size is _________________________";
    for (auto& it : _json.toObject().keys()){

        qDebug() << it;
        _verticalHeader.push_back( it );
    }
}

bool EditTableModel::setData(const QModelIndex &index, const QJsonValue &value, int role)
{
    if (role == Qt::EditRole) {
        if (!checkIndex(index))
            return false;
        const QString& key = _verticalHeader[index.row()];
        _json.toObject().insert(key, value.toString());
        /*
        QJsonValueRef ref = RootObject.find("Address").value();
        QJsonObject m_addvalue = ref.toObject();
        m_addvalue.insert("Street","India");//set the value you want to modify
        ref=m_addvalue; //assign the modified object to reference
        JsonDocument.setObject(RootObject); // set to json document
        */
        ;
        //_json.[index.][index.column()] = value;
        return true;

    }
    return false;
}

Qt::ItemFlags EditTableModel::flags(const QModelIndex &index) const
{
    return Qt::ItemIsEditable | QAbstractTableModel::flags(index);
}

//bool QJsonTableModel::setJson(const QJsonDocument& json)
//{
//    return setJson( json.array() );
//}

//bool QJsonTableModel::setJson( const QJsonArray& array )
//{
//    beginResetModel();
//    _json = const_cast<QJsonArray*>(&array);
//    endResetModel();
//    return true;
//}

QVariant EditTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if( role != Qt::DisplayRole )
    {
        return QJsonValue();
    }

    switch( orientation )
    {
    case Qt::Horizontal:
        return QJsonValue();
    case Qt::Vertical:
        return _verticalHeader[section];
        //return section + 1;

    default:
        return QVariant();
    }

}

int EditTableModel::rowCount(const QModelIndex &parent ) const
{
    //return m_json.size();
    return _verticalHeader.size();
}

int EditTableModel::columnCount(const QModelIndex &parent ) const
{
    return 1;
}


//QJsonObject QJsonTableModel::getJsonObject( const QModelIndex &index ) const
//{
//    const QJsonValue& value = _json[index.row() ];
//    return value.toObject();
//}

QVariant EditTableModel::data( const QModelIndex &index, int role ) const
{
    const QString& key = _verticalHeader[index.row()];
    QJsonValue v = _json[key];
    switch( role )
    {
    case Qt::DisplayRole:
    {
        //QJsonObject obj = getJsonObject( index );
        const QString& key = _verticalHeader[index.row()];
        qDebug() <<"key is " << key;
        //QJsonValue v = _json[key];



        if( v.isString() )
        {
            return v.toString();
        }
        else if( v.isDouble() )
        {
            return QString::number( v.toDouble() );
        }
        else if (v.isArray())
        {
            QString ans;
            for (const auto& e : v.toArray())
            {
                ans += e.toString();
                ans += "\n";
            }
            return ans;
        }
        else
        {
            return QVariant();
        }


    }
    case Qt::EditRole:
        //QJsonObject obj = getJsonObject( index );
        //const QString& key = _verticalHeader[index.row()];
        qDebug() <<"key is " << key;

        if( v.isString() )
        {
            return v.toString();
        }
        else if( v.isDouble() )
        {
            return QString::number( v.toDouble() );
        }
        else if (v.isArray())
        {
            QString ans;
            for (const auto& e : v.toArray())
            {
                ans += e.toString();
                ans += "\n";
            }
            return ans;
        }
        else
        {
            return QVariant();
        }
        return QVariant();

    case Qt::ToolTipRole:
        return QJsonValue();
    default:
        return QVariant();
    }
}
