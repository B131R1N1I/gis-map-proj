
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

import QtQuick 2.6
import QtQuick.Controls 2.4
import Esri.gis_project 1.0
//import Esri.ArcGISRuntime 100.9

Item {


    // Create MapQuickView here, and create its Map etc. in C++ code
    MapView {
        id: view
        objectName: "mapView"
        anchors.fill: parent
        // set focus to enable keyboard navigation
        focus: true
    }

    MenuBar{
        Menu {
            contentWidth: 200
            title: "..."

            MenuItem{text:"CCC"}
        }
    }
    Text {
        id: name
        text: qsTr("Choose your BaseMap: ")
    }
    ComboBox
    {
        id: changeBaseMap_box
        anchors {
            right: parent.right
            top: parent.top
            margins: 5
        }
        textRole: "text"
        property int bestWidth: implicitWidth
        width: bestWidth + leftPadding + rightPadding + indicator.width
        model: ListModel{
             ListElement { text: "Topographic"; map: "BasemapTopographic" }
             ListElement { text: "Streets"; map: "Streets" }
                         ListElement { text: "Streets (Vector)"}
                         ListElement { text: "Streets - Night (Vector)"}
                         ListElement { text: "Imagery (Raster)"}
                         ListElement { text: "Imagery with Labels (Raster)"}
                         ListElement { text: "Imagery with Labels (Vector)"}
                         ListElement { text: "Dark Gray Canvas (Vector)"}
                         ListElement { text: "Light Gray Canvas (Raster)"}
                         ListElement { text: "Light Gray Canvas (Vector)"}
                         ListElement { text: "Navigation (Vector)"}
                         ListElement { text: "OpenStreetMap (Raster)"}
                         ListElement { text: "Oceans"}
        }

        onCurrentTextChanged: {
            g_p.changeBasemap(qsTr(currentText));
        }

        onModelChanged: {
            for(let i = 0; i < changeBaseMap_box.model.length; ++i) {
                metrics.text = changeBaseMap_box.model[i];
                modelWidth = Math.max(modelWidth, metrics.width);
            }
            bestWidth = modelWidth;
        }

        TextMetrics{
            id: metrics
            font: changeBaseMap_box.font
        }

    }



    // Declare the C++ instance which creates the map etc. and supply the view
    Gis_project {
        id: g_p
        mapView: view
    }
}
