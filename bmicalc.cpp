#include "bmicalc.h"
#include "ui_bmicalc.h"
#include <iostream> // std::noskipws
#include <string>
#include <sstream> // std::istringstream
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
    QString bmi = eraseResult(resultStr);

    return bmi;
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
    return QtStr(helper);
}

std::string BMICalc::getWeight()
{
    QString helper = ui ->textW ->text();
    std::string secondHelper =  QtStr(helper);
    return noDotIssue(secondHelper);
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
    return QString::fromStdString(data);
}

std::string BMICalc::QtStr(QString data)
{
    return data.toStdString();
}

bool BMICalc::onlyNumbersDb(const std::string& data)
{
    std::istringstream iss(data);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
}

bool BMICalc::onlyNumbersInt(const std::string& data)
{
    return !data.empty() && std::find_if(data.begin(), 
        data.end(), [](char c) { return !std::isdigit(c); }) == data.end();
}

QString BMICalc::eraseResult(std::string data)
{
    data.erase(5, data.length() - 1);
    return StrQt(data);
}

void BMICalc::issueWhenHeightIsNull()
{
    QMessageBox warning;

    warning.setText("Warning!");
    warning.setInformativeText("Height cannot be equal to 0!");
    warning.setStandardButtons(QMessageBox::Ok);
    warning.setDefaultButton(QMessageBox::Ok);
    int run = warning.exec();
}

void BMICalc::noNumbersIssue()
{
    QMessageBox warning;

    warning.setText("Warning!");
    warning.setInformativeText("Given data must be a number!\nNote:\nUse dot (72.0), not comma!");
    warning.setStandardButtons(QMessageBox::Ok);
    warning.setDefaultButton(QMessageBox::Ok);
    int run = warning.exec();
}

std::string BMICalc::noDotIssue(std::string& data)
{
    for(int i = 0; i < data.length(); i++)
    {
        if(data[i] == ',')
            data[i] = '.';
    }

    return data;
}
