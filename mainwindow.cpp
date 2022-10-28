#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    campos = new Campos();
    ui->scrollArea->setWidget(campos);
    connect(ui->actionCargarArchivo, SIGNAL(triggered()), this, SLOT(readFile()));
    connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(generateFile()));
    ui->pushButton->setText("Generate");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent *even)
{
    int uiHeightStatusBar = ui->statusbar->height();
    int uiHeightMenuBar = ui->menubar->height();
    int uiHeight = uiHeightStatusBar + uiHeightMenuBar;
    int height = this->height() - uiHeight;
    int width = this->width();
    ui->scrollArea->setGeometry(10, 0, width - 20, height - 50);
    ui->pushButton->setGeometry(width - 100, height - 45, 90, 30);
}

void MainWindow::addCampo(Campo *campo)
{
    ui->scrollArea->layout()->addWidget(campo);
}

void MainWindow::readFile()
{
    qDebug() << "reading file";

    QFile file;

    file.setFileName(QFileDialog::getOpenFileName(this, "Abrir", "", "*.txt"));
    if (file.open(QIODevice::ReadOnly))
    {
        QString text(file.readAll());
        file.close();

        arrText = text.split("###");

        int i = 0;
        if (!arrText.startsWith("###"))
            i = 1;
        begin = i;

        for (; i < arrText.length(); i += 2)
        {
            qDebug() << arrText[i].toLower().trimmed().replace(" ", "");

            if (begin > 0)
            {
                QString label = arrText[i];
                Campo *campo = new Campo();
                campo->addText(label);
                campos->addCampo(campo);
            }
        }
    }
}

void MainWindow::generateFile()
{
    // TODO : GENERATE FILE HERE
    qDebug() << "generating file";
    campos->mapLineEditToLabel();
    QMap<QString, QString> map = campos->getMapLineELabel();
    int i = begin;
    html ="<p>";
    for (; i < arrText.length(); i += 2)
    {
        QString label = arrText[i];
        QString lineEdit = map[label];
        html+=arrText[i-1] +"<b>" + lineEdit +"</b>";
    }

     html +="</p>";
     guardar();
}

void MainWindow::guardar()
{

    QTextDocument documento;
    QPrinter impresora(QPrinter::HighResolution);
    impresora.setOutputFormat(QPrinter::PdfFormat);
    impresora.setOutputFileName(QFileDialog::getSaveFileName(this, "Exportar a PDF", "C:\\Users\\ibrah\\Documents", "*.pdf"));
    impresora.setPageMargins(QMargins(20, 30, 20, 15));

    documento.setHtml(html);
    documento.print(&impresora);
}
