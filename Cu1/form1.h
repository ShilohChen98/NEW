#ifndef FORM1_H
#define FORM1_H
#include <vtkConeSource.h>
#include <vtkCubeSource.h>
#include <vtkCylinderSource.h>
#include <vtkSphereSource.h>
#include <vtkPolyDataMapper.h>
#include <vtkRenderer.h>
#include <vtkRenderWindow.h>
#include <vtkActor.h>
#include <vtkImageActor.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkSmartPointer.h>
#include <vtkImageCanvasSource2D.h>
#include <vtkImageData.h>
#include <vtkInteractorStyleImage.h>
#include <vtkPolygon.h>
#include <vtkTriangle.h>
#include <vtkCellData.h>
#include <vtkCellArray.h>
#include <vtkPolyData.h>
#include <vtkProperty.h>
#include <vtkPointData.h>
#include <vtkLookupTable.h>
#include <vtkTransformTextureCoords.h>
#include <iostream>
#include <vtkFloatArray.h>
#include <vtkPlaneSource.h>
#include <vtkCellDataToPointData.h>
#include <vtkPointDataToCellData.h>
#include <vtkDataSet.h>
#include <vtkScalarBarActor.h>
#include <vtkTriangleFilter.h>
#include <vtkMassProperties.h>
#include <iostream>
#include <vtkDijkstraGraphGeodesicPath.h>
#include <vtkOutlineFilter.h>
#include <vtkPolyDataMapper.h>
#include <vtkXMLPolyDataReader.h>
#include <vtkPolyDataReader.h>
#include <vtkPLYReader.h>
#include <vtkFloatArray.h>
#include <vtkPointData.h>
#include <vtkPolyDataNormals.h>
#include <vtkGlyph3D.h>
#include <vtkArrowSource.h>
#include <vtkSphereSource.h>
#include <vtkMaskPoints.h>
#include <vtkCurvatures.h>
#include <vtkPolyDataReader.h>
#include <vtkLookupTable.h>
#include <vtkColorTransferFunction.h>
#include <vtkColorSeries.h>
#include <vtkScalarBarActor.h>
#include <vtkTubeFilter.h>
#include <vtkDoubleArray.h>
#include <vtkCamera.h>
#include <vtkMath.h>
#include <vtkFloatArray.h>
#include <vtkHedgeHog.h>
#include <vtkMath.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPointData.h>
#include <vtkPoints.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderWindowInteractor.h>
#include <vtkRenderer.h>
#include <vtkStructuredGrid.h>
#include <vtkMultiBlockDataSet.h>
#include <vtkStructuredGridOutlineFilter.h>
#include <vtkCompositeDataGeometryFilter.h>
#include <vtkContourFilter.h>
#include <vtkBandedPolyDataContourFilter.h>
#include <vtkSurfaceReconstructionFilter.h>
#include <vtkThreshold.h>
#include <vtkSmoothPolyDataFilter.h>
#include <array>
#include <QWidget>
#include <QTimer>
#include <QSqlTableModel>



namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    ~Form1();
protected:
    void closeEvent(QCloseEvent *e);//窗口关闭事件
    void  timerEvent(QTimerEvent *ev);//计时器事件




private slots:
    void on_pushButton_clicked();
//    void VTKprinter();


private:
    Ui::Form1 *ui;
    int timerId;
    int timerId2;
    int timerId3;
    QSqlTableModel *model;
    vtkSmartPointer<vtkFloatArray> scalars = vtkSmartPointer<vtkFloatArray>::New();
    int numPts=72;
    int  newrow=0;
    QTimer* timer = new QTimer(this);
};

#endif // FORM1_H
