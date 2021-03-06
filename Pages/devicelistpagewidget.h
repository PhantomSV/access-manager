#ifndef DEVICELISTPAGEWIDGET_H
#define DEVICELISTPAGEWIDGET_H

#include "stdafx.h"

#include "Models/devicelistmodel.h"
#include "Models/devicelistdelegate.h"
#include "Pages/dslampagewidget.h"
#include "Pages/switchpagewidget.h"
#include "Pages/editdslamboardlistpagewidget.h"

namespace Ui {
class DeviceListPageWidget;
}

class DeviceListPageWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit DeviceListPageWidget(QTabWidget* mParentTabWidget, QVector<PageType>* typePageList, QHash<QString, QWidget*>* pageList, QWidget* parent = 0);
    ~DeviceListPageWidget();
    DeviceListModel* deviceListModel()  const;
    QSortFilterProxyModel* proxyModel() const;
    QModelIndex currentDeviceListItem() const;
    void clearSelection();
private:
    Ui::DeviceListPageWidget*   ui;
    DeviceListModel*            mDeviceListModel;
    QSortFilterProxyModel*      mProxyModel;
    QVector<PageType>*          mTypePageList;
    QHash<QString, QWidget*>*   mPageList;
    QTabWidget*                 mParentTabWidget;
    void batchUpdate(DeviceType updatingDeviceType);
signals:
    void changedActiveItem(QModelIndex index);
public slots:
    void loadDeviceList();
    void saveDeviceList();
    void addDevice();
    void editDevice();
    void removeDevice();
    void updateVlanInfoSwitch();
    void updateBoardInfoDslam();
    void batchUpdateBoardsInfoDslam();
    void batchUpdateVlanInfoSwitch();
    void batchUpdateInfoAllDevices();
private slots:
    void filterDeviceTextChanged(QString text);
    void deviceViewRequestContextMenu(QPoint point);
    void showInfoVlanGroupBox();
    void vlanInfoGBoxStateChanged(bool state);
    void showDevicePage();
    void showEditDslamBoardListPage();
    void viewActivatedItem(QModelIndex currIndex, QModelIndex prevIndex);
};

#endif // DEVICELISTPAGEWIDGET_H
