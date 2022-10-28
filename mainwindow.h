#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QResizeEvent>
#include <QVBoxLayout>
#include "campos.h"
#include <QFile>
#include <QFileDialog>
#include <QFile>
#include <QFileDialog>
#include <QtPrintSupport/QPrinter>
#include <QTextDocument>
QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void resizeEvent(QResizeEvent *even);
    void addCampo(Campo *campo);
    void guardar();
private slots:
    void readFile();
    void generateFile();

private:
    Ui::MainWindow *ui;
    Campos *campos;
    QVector<QString> arrText;
    int begin;
    QString html;
};
#endif // MAINWINDOW_H
