#ifndef MACLISTMODEL_H
#define MACLISTMODEL_H

#include "stdafx.h"
#include "Info/macinfo.h"
#include "converters.h"
#include "snmpclient.h"

class MacListModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit MacListModel(QObject* parentDevice = 0);
    int rowCount(const QModelIndex& parentDevice) const;
    int columnCount(const QModelIndex& parentDevice) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;
    bool updateMacTable();
    void setIP(QString ip);
    void setInetVlanTag(int vlanTag);
    void setIptvVlanTag(int vlanTag);
    //ошибки
    QString error() const;
private:
    std::vector<MacInfo::Ptr> mMacList;
    QString mError;
    QString mIp;
    int mInetVlanTag;
    int mIptvVlanTag;
    void updateMacTableVlan(SnmpClient* snmp, quint32 vlanTag, QString vlanName);
};

#endif // MACLISTMODEL_H
