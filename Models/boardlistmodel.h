#ifndef BOARDLISTMODEL_H
#define BOARDLISTMODEL_H

#include "stdafx.h"
#include "Info/deviceinfo.h"
#include "Info/boardinfo.h"
#include "basicdialogs.h"
#include "constant.h"
#include "snmpclient.h"
#include "customsnmpfunctions.h"

class BoardListModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit BoardListModel(QObject* parent = 0);
    int rowCount(const QModelIndex& parent) const;
    int columnCount(const QModelIndex& parent) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    bool setData(const QModelIndex& index, const QVariant& value, int role);
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    Qt::ItemFlags flags(const QModelIndex& index) const;
    bool removeRow(int row, const QModelIndex& parent);
    //настройка модели
    QHash<int, BoardInfo> boardList() const;
    short autoFill() const;
    short autoNumeringBoard() const;
    DeviceInfo::Ptr parentDevice();
    void setBoardList(QHash<int, BoardInfo>& boardList);
    void setAutoFill(short autoFill);
    void setAutoNumeringBoard(short autoNumeringBoard);
    void setParentDevice(const DeviceInfo::Ptr& parent);
    bool getBoardListFromDevice();
    void renumeringPairList();
    //ошибки
    QString error() const;
private:
    QHash<int, BoardInfo> mBoardList;
    QString mError;
    short mAutoFill;
    short mAutoNumeringBoard;
    DeviceInfo::Ptr mParentDevice;
    QString rangePairs(int firstPair, BoardType typeBoard) const;
};

#endif // BOARDLISTMODEL_H
