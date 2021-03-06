#ifndef DEVICELISTPARSER_H
#define DEVICELISTPARSER_H

#include "stdafx.h"

#include "Info/dslaminfo.h"
#include "Info/oltinfo.h"
#include "Info/switchinfo.h"

class DeviceListHandler : public QXmlDefaultHandler
{
public:
    DeviceListHandler();
    bool startElement(const QString& namespaceURI, const QString& localName,
                      const QString& qName, const QXmlAttributes& attributes);
    bool endElement(const QString& namespaceURI, const QString& localName,
                    const QString& qName);
    bool fatalError(const QXmlParseException& exception);
    QString errorString() const;
    std::vector<DeviceInfo::Ptr>& deviceList();
private:
    QString m_error;
    std::vector<DeviceInfo::Ptr> m_deviceList;
    DeviceInfo::Ptr m_currDeviceInfoElement;
    QHash<int, BoardInfo> m_boardList;
    void parseSwitchElement(const QXmlAttributes& attributes);
    void parseDslamElement(const QXmlAttributes& attributes);
    void parseBoardElement(const QXmlAttributes& attributes);
    void parseOltElement(const QXmlAttributes& attributes);
    void parseUniOltProfileElement(const QXmlAttributes& attributes);
    void parseMultOltProfileElement(const QXmlAttributes& attributes);
};

#endif // DEVICELISTPARSER_H
