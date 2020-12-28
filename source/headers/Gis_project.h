
// Copyright 2019 ESRI
//
// All rights reserved under the copyright laws of the United States
// and applicable international laws, treaties, and conventions.
//
// You may freely redistribute and use this sample code, with or
// without modification, provided you include the original copyright
// notice and use restrictions.
//
// See the Sample code usage restrictions document for further information.
//

#ifndef GIS_PROJECT_H
#define GIS_PROJECT_H

#include "Point.h"
#include "GeometryEngine.h"

namespace Esri
{
    namespace ArcGISRuntime
    {
        class Map;
        class MapQuickView;
    } // namespace ArcGISRuntime
} // namespace Esri

#include <QObject>

class Gis_project : public QObject
{
    Q_OBJECT

    Q_PROPERTY(Esri::ArcGISRuntime::MapQuickView *mapView READ mapView WRITE setMapView NOTIFY mapViewChanged)

public:
    explicit Gis_project(QObject *parent = nullptr);
    ~Gis_project() override;
    Q_INVOKABLE void changeBasemap(const QString& basemap);

signals:
    void mapViewChanged();

private:
    Esri::ArcGISRuntime::MapQuickView *mapView() const;
    void setMapView(Esri::ArcGISRuntime::MapQuickView *mapView);

    Esri::ArcGISRuntime::Map *m_map = nullptr;
    Esri::ArcGISRuntime::MapQuickView *m_mapView = nullptr;
    //protected:
};

#endif // GIS_PROJECT_H
