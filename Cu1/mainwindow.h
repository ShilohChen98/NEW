#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<vtkAutoInit.h>
#include <QMainWindow>
#include <form1.h>
VTK_MODULE_INIT(vtkRenderingOpenGL2);
VTK_MODULE_INIT(vtkInteractionStyle);
VTK_MODULE_INIT(vtkRenderingFreeType);
#include <QOpenGLWidget>
#include <QOpenGLExtraFunctions>





QT_BEGIN_NAMESPACE
namespace Ui {class MainWindow;}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


protected:
    void keyPressEvent(QKeyEvent *e);//键盘按下事件



private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    Form1 *form_1;

};

#endif // MAINWINDOW_H
