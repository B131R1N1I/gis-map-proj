
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

#include "Gis_project.h"

#include "Basemap.h"
#include "Map.h"
#include "MapQuickView.h"

#include <QUrl>

using namespace Esri::ArcGISRuntime;

Gis_project::Gis_project(QObject* parent /* = nullptr */):
    QObject(parent),
    m_map(new Map(Basemap::topographic(this), this))
{
}

Gis_project::~Gis_project()
{
}

MapQuickView* Gis_project::mapView() const
{
    return m_mapView;
}

// Set the view (created in QML)
void Gis_project::setMapView(MapQuickView* mapView)
{
    if (!mapView || mapView == m_mapView)
    {
        return;
    }

    m_mapView = mapView;
    m_mapView->setMap(m_map);

    emit mapViewChanged();
}