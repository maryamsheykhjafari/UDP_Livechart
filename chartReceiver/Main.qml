import QtQuick
import QtCharts



    ChartView{
     id:chart
     anchors.fill: parent
     antialiasing: true

     title: "chart"

     ValuesAxis{
         id: axisX
         min :0
         max: 100
     }
     ValuesAxis{
         id: axisY
         min :0
         max: 500
     }


     LineSeries{
           id: series
           axisX: axisX
           axisY: axisY
           name: "Incoming Data"
     }

     Connections{

        target: udpreceiver

         onDataReceived: (value) =>{


                             series.append(series.count ,value)


                             /*if(series.count > 200)
                             {
                                               series.remove(0)
                                               axisX.min += 1
                                               axisX.max += 1

                            }*/            }


     }

     }


