#include "form1.h"
#include "ui_form1.h"
#include <QMovie>
#include <QVTKWidget.h>
#include"math.h"
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
// For compatibility with new VTK generic data arrays
#ifdef vtkGenericDataArray_h
#define InsertNextTupleValue InsertNextTypedTuple
#endif


#include <QSqlDatabase>
#include <QDebug>
#include <QMessageBox>
#include <QSqlError>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QTextCodec>
#include <QEvent>
#include <QTimer>


Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
    ui->label->setPixmap(QPixmap(":/image/cove.png"));
//    ui->label->setScaledContents(true);

    //gif?????????????????????move
    QMovie *mymovie = new QMovie(":/image/BF.gif");
    ui->label_2->setMovie(mymovie);
    mymovie->start();
    ui->label_2->setScaledContents(true);
    timerId = this-> startTimer(800);//???????????????




}

Form1::~Form1()
{
    delete ui;
}


void Form1::on_pushButton_clicked()
{

//    if (timer->isActive() == true)
//    {
//        timer->stop();

//    }



     qDebug() << QSqlDatabase::drivers();
    QSqlDatabase db =  QSqlDatabase::addDatabase("QOCI");
    //???????????????
    QString str1,str2,str3,str4,str5;

    str1= ui->lineEdit->text();
    str2= ui->lineEdit_2->text();
    str3= ui->lineEdit_3->text();
    str4= ui->lineEdit_4->text();
    str5= ui->lineEdit_5->text();

    db.setHostName(str1);//?????????????????? IP127.0.0.1
    db.setPort(str2.toInt());//????????????1521
    db.setUserName(str3);//???????????????wateruser
    db.setPassword(str4);//????????????
    db.setDatabaseName(str5);//??????orcl?????????
    model = new QSqlTableModel(this);
    model->setTable("SLAGTHICKNESS");//?????????????????????

    //???model??????view
    ui->tableView->setModel(model);

    //??????model????????????
    model->select();
    //????????????????????????????????????
    ui->tableView->setSortingEnabled(true);
    ui->tableView->sortByColumn(0,Qt::AscendingOrder);

    //?????????????????????
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


    //???????????????
    if(!db.open())
    {
        ui->label_3->setText("????????????,?????????..");
    }
    else {
        ui->label_3->setText("????????????,????????????....");
         }

//    connect(timer, SIGNAL(timeout()), this, SLOT(VTKprinter()));
//    timer->start(5000);


}
 //???????????????????????????
void Form1::timerEvent(QTimerEvent *ev)
{
    if(ui->label_3->text() == "????????????,????????????...." )
    {
        double  A1 = model->data(model->index(newrow,1)).toDouble();
        double  A2 = model->data(model->index(newrow,2)).toDouble();
        double  A3 = model->data(model->index(newrow,3)).toDouble();
        double  A4 = model->data(model->index(newrow,4)).toDouble();
        double  A5 = model->data(model->index(newrow,5)).toDouble();
        double  A6 = model->data(model->index(newrow,6)).toDouble();
        double  A7 = model->data(model->index(newrow,7)).toDouble();
        double  A8 = model->data(model->index(newrow,8)).toDouble();
        double  A9 = model->data(model->index(newrow,9)).toDouble();
        double  A10 = model->data(model->index(newrow,10)).toDouble();
        double  A11 = model->data(model->index(newrow,11)).toDouble();
        double  A12 = model->data(model->index(newrow,12)).toDouble();
        double  A13 = model->data(model->index(newrow,13)).toDouble();
        double  A14 = model->data(model->index(newrow,14)).toDouble();
        double  A15 = model->data(model->index(newrow,15)).toDouble();
        double  A16 = model->data(model->index(newrow,16)).toDouble();
        double  A17 = model->data(model->index(newrow,17)).toDouble();
        double  A18 = model->data(model->index(newrow,18)).toDouble();
        double  A19 = model->data(model->index(newrow,19)).toDouble();
        double  A20 = model->data(model->index(newrow,20)).toDouble();
        double  A21 = model->data(model->index(newrow,21)).toDouble();
        double  A22 = model->data(model->index(newrow,22)).toDouble();
        double  A23 = model->data(model->index(newrow,23)).toDouble();
        double  A24 = model->data(model->index(newrow,24)).toDouble();
        double  A25 = model->data(model->index(newrow,25)).toDouble();
        double  A26 = model->data(model->index(newrow,26)).toDouble();
        double  A27 = model->data(model->index(newrow,27)).toDouble();
        double  A28 = model->data(model->index(newrow,28)).toDouble();
        double  A29 = model->data(model->index(newrow,29)).toDouble();
        double  A30 = model->data(model->index(newrow,30)).toDouble();
        double  A31 = model->data(model->index(newrow,31)).toDouble();
        double  A32 = model->data(model->index(newrow,32)).toDouble();
        double  A33 = model->data(model->index(newrow,33)).toDouble();
        double  A34 = model->data(model->index(newrow,34)).toDouble();
        double  A35 = model->data(model->index(newrow,35)).toDouble();
        double  A36 = model->data(model->index(newrow,36)).toDouble();
        double  A37 = model->data(model->index(newrow,37)).toDouble();
        double  A38 = model->data(model->index(newrow,38)).toDouble();
        double  A39 = model->data(model->index(newrow,39)).toDouble();
        double  A40 = model->data(model->index(newrow,40)).toDouble();
        double  A41 = model->data(model->index(newrow,41)).toDouble();
        double  A42 = model->data(model->index(newrow,42)).toDouble();
        double  A43 = model->data(model->index(newrow,43)).toDouble();
        double  A44 = model->data(model->index(newrow,44)).toDouble();
        double  A45 = model->data(model->index(newrow,45)).toDouble();
        double  A46 = model->data(model->index(newrow,46)).toDouble();
        double  A47 = model->data(model->index(newrow,47)).toDouble();
        double  A48 = model->data(model->index(newrow,48)).toDouble();
        double  A49 = model->data(model->index(newrow,49)).toDouble();
        double  A50 = model->data(model->index(newrow,50)).toDouble();
        double  A51 = model->data(model->index(newrow,51)).toDouble();
        double  A52 = model->data(model->index(newrow,52)).toDouble();
        double  A53 = model->data(model->index(newrow,53)).toDouble();
        double  A54 = model->data(model->index(newrow,54)).toDouble();
        double  A55 = model->data(model->index(newrow,55)).toDouble();
        double  A56 = model->data(model->index(newrow,56)).toDouble();
        double  A57 = model->data(model->index(newrow,57)).toDouble();
        double  A58 = model->data(model->index(newrow,58)).toDouble();
        double  A59 = model->data(model->index(newrow,59)).toDouble();
        double  A60 = model->data(model->index(newrow,60)).toDouble();
        double  A61 = model->data(model->index(newrow,61)).toDouble();
        double  A62 = model->data(model->index(newrow,62)).toDouble();
        double  A63 = model->data(model->index(newrow,63)).toDouble();
        double  A64 = model->data(model->index(newrow,64)).toDouble();
        double  A65 = model->data(model->index(newrow,65)).toDouble();
        double  A66 = model->data(model->index(newrow,66)).toDouble();
        double  A67 = model->data(model->index(newrow,67)).toDouble();
        double  A68 = model->data(model->index(newrow,68)).toDouble();
        double  A69 = model->data(model->index(newrow,69)).toDouble();
        double  A70 = model->data(model->index(newrow,70)).toDouble();
        double  A71 = model->data(model->index(newrow,71)).toDouble();
        double  A72 = model->data(model->index(newrow,72)).toDouble();
        double slagthickness[72] = {A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,
                                   A19,A20,A21,A22,A23,A24,A25,A26,A27,A28,A29,A30,A31,A32,A33,A34,
                                   A35,A36,A37,A38,A39,A40,A41,A42,A43,A44,A45,A46,A47,A48,A49,A50,
                                   A51,A52,A53,A54,A55,A56,A57,A58,A59,A60,A61,A62,A63,A64,A65,A66,
                                   A67,A68,A69,A70,A71,A72};

        vtkSmartPointer<vtkPoints> points =
               vtkSmartPointer<vtkPoints>::New();
           double R=6.2;
           double R1=6.95;
           double R2=4.5;//??????????????????
           double H1=7.5;
           double H2=11;
           double H3=13;
           double H4=30.9;
           double H5=33.3;//??????????????????
           int numResolution=24;//????????????12??????????????????12?????????????????????????????????
           int numH=4;
           int numPts=72;

           for(int i=0;i<numResolution;i++){
               //double temp=R*(1.0-cos(i*2.0*3.14/intResolution));
               points->InsertNextPoint(R*cos(i*2.0*3.14/numResolution), 0.0, R*sin(i*2.0*3.14/numResolution));//????????????????????????????????????Z????????????????????????????????????????????????x,z,y)
               points->InsertNextPoint(R*cos(i*2.0*3.14/numResolution), H1, R*sin(i*2.0*3.14/numResolution));//???R*cos(x),R*sin(x))??????????????????????????????
               points->InsertNextPoint(R1*cos(i*2.0*3.14/numResolution), H2, R1*sin(i*2.0*3.14/numResolution));
               points->InsertNextPoint(R1*cos(i*2.0*3.14/numResolution), H3, R1*sin(i*2.0*3.14/numResolution));
               points->InsertNextPoint(R2*cos(i*2.0*3.14/numResolution), H4, R2*sin(i*2.0*3.14/numResolution));
               points->InsertNextPoint(R2*cos(i*2.0*3.14/numResolution), H5, R2*sin(i*2.0*3.14/numResolution));
           }

           vtkSmartPointer<vtkCellArray> cells =
               vtkSmartPointer<vtkCellArray>::New();
           for(int i=0;i<numResolution-1;i++){
               cells->InsertNextCell(4);
               cells->InsertCellPoint(i*6+1);
               cells->InsertCellPoint(i*6);
               cells->InsertCellPoint(i*6+6);
               cells->InsertCellPoint(i*6+7);

           }
           cells->InsertNextCell(4);
           cells->InsertCellPoint((numResolution-1)*6+1);
           cells->InsertCellPoint((numResolution-1)*6);
           cells->InsertCellPoint(0);
           cells->InsertCellPoint(1);

           for(int i=0;i<numResolution-1;i++){
               cells->InsertNextCell(4);
               cells->InsertCellPoint(i*6+2);
               cells->InsertCellPoint(i*6+1);
               cells->InsertCellPoint(i*6+7);
               cells->InsertCellPoint(i*6+8);
           }
           cells->InsertNextCell(4);
           cells->InsertCellPoint((numResolution-1)*6+2);
           cells->InsertCellPoint((numResolution-1)*6+1);
           cells->InsertCellPoint(1);
           cells->InsertCellPoint(2);

           for(int i=0;i<numResolution-1;i++){
               cells->InsertNextCell(4);
               cells->InsertCellPoint(i*6+3);
               cells->InsertCellPoint(i*6+2);
               cells->InsertCellPoint(i*6+8);
               cells->InsertCellPoint(i*6+9);
           }
           cells->InsertNextCell(4);
           cells->InsertCellPoint((numResolution-1)*6+3);
           cells->InsertCellPoint((numResolution-1)*6+2);
           cells->InsertCellPoint(2);
           cells->InsertCellPoint(3);

           for(int i=0;i<numResolution-1;i++){
               cells->InsertNextCell(4);
               cells->InsertCellPoint(i*6+4);
               cells->InsertCellPoint(i*6+3);
               cells->InsertCellPoint(i*6+9);
               cells->InsertCellPoint(i*6+10);
           }
           cells->InsertNextCell(4);
           cells->InsertCellPoint((numResolution-1)*6+4);
           cells->InsertCellPoint((numResolution-1)*6+3);
           cells->InsertCellPoint(3);
           cells->InsertCellPoint(4);


           for(int i=0;i<numResolution-1;i++){
               cells->InsertNextCell(4);
               cells->InsertCellPoint(i*6+5);
               cells->InsertCellPoint(i*6+4);
               cells->InsertCellPoint(i*6+10);
               cells->InsertCellPoint(i*6+11);
           }
           cells->InsertNextCell(4);
           cells->InsertCellPoint((numResolution-1)*6+5);
           cells->InsertCellPoint((numResolution-1)*6+4);
           cells->InsertCellPoint(4);
           cells->InsertCellPoint(5);

           vtkSmartPointer<vtkPolyData> polygonPolyData =
               vtkSmartPointer<vtkPolyData>::New();
           polygonPolyData->SetPoints(points);
           polygonPolyData->SetPolys(cells);

           vtkSmartPointer<vtkFloatArray> scalars = vtkSmartPointer<vtkFloatArray>::New();		// ???????????????????????????float??????
           scalars->SetNumberOfValues(numPts);

//           qDebug()<<scalars<<"-----------";
           //scalars=VTKprinter(slagthickness);

           for (int i = 0; i < numPts; ++i)		// ??????????????????????????????????????????????????????????????????????????????????????????
               scalars->SetValue(i, slagthickness[i]);////????????????????????????????????????(??????????????????????????????????????????????????????????????????????????????)
           polygonPolyData->GetPointData()->SetScalars(scalars);

           // ?????????????????????
           vtkSmartPointer<vtkLookupTable> hueLut = vtkSmartPointer<vtkLookupTable>::New();
           hueLut->SetNumberOfColors(numPts);		// ??????????????????????????????????????????
           hueLut->SetHueRange(0.6667, 0.0);	//???????????????
           hueLut->Build();

           vtkSmartPointer<vtkPolyDataMapper> mapper =
               vtkSmartPointer<vtkPolyDataMapper>::New();
           mapper->SetInputData(polygonPolyData);
           mapper->SetScalarRange(0, 500);			// ???????????????????????????0-100???
           mapper->ScalarVisibilityOn();
           //mapper->SetColorModeToMapScalars();		// ??????????????????????????????????????????????????????????????????????????????????????????
           mapper->SetColorModeToDefault();			// ?????????????????????????????????unsigned char??????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
           mapper->SetLookupTable(hueLut);

           vtkSmartPointer<vtkActor> actor =
               vtkSmartPointer<vtkActor>::New();
           actor->SetMapper(mapper);


           vtkSmartPointer<vtkScalarBarActor> scalarBar =
               vtkSmartPointer<vtkScalarBarActor>::New();
           scalarBar->SetLookupTable(mapper->GetLookupTable());
           //scalarBar->SetTitle("??????");
           scalarBar->SetNumberOfLabels(5);

           vtkSmartPointer<vtkRenderer> renderer =
               vtkSmartPointer<vtkRenderer>::New();
           renderer->AddActor(actor);
           renderer->AddActor2D(scalarBar);
           renderer->SetBackground(1.0, 1.0, 1.0);

           ui->widget->GetRenderWindow()->AddRenderer(renderer);
           vtkSmartPointer<vtkRenderWindowInteractor> iren =
               vtkSmartPointer<vtkRenderWindowInteractor>::New();

              iren->Start();
           ui->widget->update();



           newrow++;



        static int sec3=0;
        ui->progressBar->setMinimum(0);
        ui->progressBar->setMaximum(100);
        ui->progressBar->setValue(sec3++);
        if(sec3==101)
        {
            sec3=0;
        }

        if(sec3==101){
            killTimer(timerId);
        }
    }

}






