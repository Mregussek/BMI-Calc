#include "bmicalc.h"
#include "ui_bmicalc.h"
#include <string>
#include <sstream>
#include <qstring.h>
#include <QMessageBox>

BMICalc::BMICalc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::BMICalc)
{
    ui->setupUi(this);

    showData();
}

BMICalc::~BMICalc()
{
    delete ui;
}

// Height
void BMICalc::on_minusHButton_clicked()
{
    getData();
    minus(height);
    updateDataFromHeightClick();
}

void BMICalc::on_plusHButton_clicked()
{
    getData();
    plus(height);
    updateDataFromHeightClick();
}

// Reset
void BMICalc::on_resetButton_clicked()
{
    resetData();
}

// Weight
void BMICalc::on_minusWButton_clicked()
{
    getData();
    minus(weight);
    updateDataFromWeightClick();
}

void BMICalc::on_plusWButton_clicked()
{
    getData();
    plus(weight);
    updateDataFromWeightClick();
}

// calculate
void BMICalc::on_calcButton_clicked()
{
    getData();
    ui ->textResult ->setText( getResult() );
}

// source code for helpful functions
QString BMICalc::getResult()
{
    double helper = static_cast<double>(height * height);

    // if helper is equal to null it will run
    if( !static_cast<int>(helper) )
    {
        issueWhenHeightIsNull();
        return nullptr;
    }

    result = weight / helper;
    result *= 10000;

    resultStr = DbStr(result);
    QString secondHelper = eraseResult(resultStr);

    return secondHelper;
}

void BMICalc::resetData()
{
    height = 100;
    weight = 50.0;
    heightStr = "100";
    weightStr = "50.0";
    updateDataFromHeightClick();
    updateDataFromWeightClick();
}

void BMICalc::showData()
{
    updateDataFromHeightClick();
    updateDataFromWeightClick();
}

void BMICalc::getData()
{
    weightStr = getWeight();
    heightStr = getHeight();

    // if height or weight are not numbers it will run
    if(!onlyNumbersDb(weightStr) || !onlyNumbersInt(heightStr))
    {
        noNumbersIssue();
        return;
    }

    height = StrInt(heightStr);
    weight = StrDb(weightStr);
}

void BMICalc::updateDataFromHeightClick()
{
    QString helper = StrQt(heightStr);
    ui ->textH ->setText(helper);
}

void BMICalc::updateDataFromWeightClick()
{
    QString helper = StrQt(weightStr);
    ui ->textW ->setText(helper);
}

std::string BMICalc::getHeight()
{
    QString helper = ui ->textH ->text();
    std::string secondHelper = QtStr(helper);
    return secondHelper;
}

std::string BMICalc::getWeight()
{
    QString helper = ui ->textW ->text();
    std::string secondHelper = QtStr(helper);
    return secondHelper;
}

void BMICalc::minus(int& data)
{
    data--;
    heightStr = IntStr(data);
}

void BMICalc::minus(double& data)
{
    data--;
    weightStr = DbStr(data);
}

void BMICalc::plus(int& data)
{
    data++;
    heightStr = IntStr(data);
}

void BMICalc::plus(double& data)
{
    data++;
    weightStr = DbStr(data);
}

std::string BMICalc::DbStr(double data)
{
    std::string text = std::to_string(data);
    return text;
}

std::string BMICalc::IntStr(int data)
{
    std::string text = std::to_string(data);
    return text;
}

int BMICalc::StrInt(std::string data)
{
    std::stringstream geek(data);

    int number = 0;
    geek >> number;

    return number;
}

double BMICalc::StrDb(std::string data)
{
    double number = 0;
    number = std::stod(data);

    return number;
}

QString BMICalc::StrQt(std::string data)
{
    QString helper = QString::fromStdString(data);
    return helper;
}

std::string BMICalc::QtStr(QString data)
{
    std::string helper = data.toStdString();
    return helper;
}

bool BMICalc::onlyNumbersDb(std::string data)
{
    for(int i = 0; i < data.size(); i++)
        if(!(data[i] >= 48 && data[i] <= 56))
        {
            if(data[i] == 46 || data[i] == 44)
                continue;
            else
                return false;
        }

    return true;
}

bool BMICalc::onlyNumbersInt(std::string data)
{
    for(int i = 0; i < data.length(); i++)
        if(!(data[i] >= 48 && data[i] <= 56))
            return false;

    return true;
}

QString BMICalc::eraseResult(std::string data)
{
    data.erase(5, data.length() - 1);
    QString helper = StrQt(data);

    return helper;
}

void BMICalc::issueWhenHeightIsNull()
{
    QMessageBox warning;

    warning.setText("Uwaga!");
    warning.setInformativeText("Wysokość nie może być równa 0!");
    warning.setStandardButtons(QMessageBox::Ok);
    warning.setDefaultButton(QMessageBox::Ok);
    int run = warning.exec();
}

void BMICalc::noNumbersIssue()
{
    QMessageBox warning;

    warning.setText("Uwaga!");
    warning.setInformativeText("Dane muszą być liczbami!");
    warning.setStandardButtons(QMessageBox::Ok);
    warning.setDefaultButton(QMessageBox::Ok);
    int run = warning.exec();
}
