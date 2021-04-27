#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QDoubleValidator"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QDoubleValidator* doubleValidator = new QDoubleValidator();
    ui->lineHeight->setValidator(doubleValidator);
    ui->lineWeight->setValidator(doubleValidator);
}

MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::on_pushButton_clicked()
{
    bool check;
    QString result;
    height=ui->lineHeight->text().toDouble(&check);
    weight=ui->lineWeight->text().toDouble(&check);
    if(!check){
        result="輸入錯誤";
        ui->labOutput->setText(result);
        return;
    }
    double bmiValue = weight/((height/100)*(height/100));
    result+="結果: " + QString::number(bmiValue);
    result+="\n您的體位: ";
    if(bmiValue<18.5)
        result+="體重過輕";
    else if(bmiValue<24)
        result+="體重健康";
    else if(bmiValue<27)
        result+="過重";
    else if(bmiValue<30)
        result+="體重肥胖";
    else if(bmiValue<35)
        result+="中度肥胖";
    else
        result+="重度肥胖";
    ui->labOutput->setText(result);
}
