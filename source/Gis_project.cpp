
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

#include "headers/Gis_project.h"

#include "Basemap.h"
#include "Map.h"
#include "MapQuickView.h"
#include "ArcGISTiledLayer.h"

#include <QUrl>

using namespace Esri::ArcGISRuntime;

Gis_project::Gis_project(QObject *parent /* = nullptr */) : QObject(parent),
                                                            m_map(new Map(Basemap::topographic(this), this))
{
}

Gis_project::~Gis_project() = default;

MapQuickView *Gis_project::mapView() const
{
    return m_mapView;
}

// Set the view (created in QML)
void Gis_project::setMapView(MapQuickView *mapView)
{
    if (!mapView || mapView == m_mapView)
    {
        return;
    }

    m_mapView = mapView;
    m_mapView->setMap(m_map);

    emit mapViewChanged();
}

void Gis_project::changeBasemap(const QString &basemap)
{
    qDebug() << "Basemap set to: " << basemap;
    if (basemap == "")
        throw "Empty parameter";

    if (m_map->loadStatus() == LoadStatus::Loaded)
    {
        if (basemap == "Topographic")
            m_map->setBasemap(Basemap::topographic(this));
        else if (basemap == "Streets")
            m_map->setBasemap(Basemap::streets(this));
        else if (basemap == "Streets (Vector)")
            m_map->setBasemap(Basemap::streetsVector(this));
        else if (basemap == "Streets - Night (Vector)")
            m_map->setBasemap(Basemap::streetsNightVector(this));
        else if (basemap == "Imagery (Raster)")
            m_map->setBasemap(Basemap::imagery(this));
        else if (basemap == "Imagery with Labels (Raster)")
            m_map->setBasemap(Basemap::imageryWithLabels(this));
        else if (basemap == "Imagery with Labels (Vector)")
            m_map->setBasemap(Basemap::imageryWithLabelsVector(this));
        else if (basemap == "Dark Gray Canvas (Vector)")
            m_map->setBasemap(Basemap::darkGrayCanvasVector(this));
        else if (basemap == "Light Gray Canvas (Raster)")
            m_map->setBasemap(Basemap::lightGrayCanvas(this));
        else if (basemap == "Light Gray Canvas (Vector)")
            m_map->setBasemap(Basemap::lightGrayCanvasVector(this));
        else if (basemap == "Navigation (Vector)")
            m_map->setBasemap(Basemap::navigationVector(this));
        else if (basemap == "OpenStreetMap (Raster)")
            m_map->setBasemap(Basemap::openStreetMap(this));
        else if (basemap == "Oceans")
            m_map->setBasemap(Basemap::oceans(this));
    }
    m_mapView->setMap(m_map);

    emit mapViewChanged();
}
