#ifndef BMICALC_H
#define BMICALC_H

#include <QMainWindow>

namespace Ui {
class BMICalc;
}

class BMICalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit BMICalc(QWidget *parent = 0);
    ~BMICalc();


    // QWidgets functions
private slots:
    void on_minusHButton_clicked();

    void on_plusHButton_clicked();

    void on_calcButton_clicked();

    void on_resetButton_clicked();

    void on_minusWButton_clicked();

    void on_plusWButton_clicked();

private:
    Ui::BMICalc *ui;

    // start data
    int height = 100;
    double weight = 50.0;
    std::string heightStr = "100";
    std::string weightStr = "50.0";
    double result = 0.0;
    std::string resultStr = "0.0";

    // ------
    // helpful functions
    // ------

    // shows result of all this
    QString getResult();

    // resets data on text labels
    void resetData();

    // I use this function only on start of the app to show data on LineEdit Panels
    void showData();

    // gets weight and height, i use this for a reason if user used keyboard to update data
    void getData();

    // these I use to update data when a button "plus" or "minus" is clicked
    void updateDataFromHeightClick();
    void updateDataFromWeightClick();

    // gets and convert height and weight from QString
    std::string getHeight();
    std::string getWeight();

    // these functions decrements / increments arguments
    // height
    void minus(int&);
    void plus(int&);
    // weight
    void minus(double&);
    void plus(double&);

    // int to string, string to double etc.
    std::string DbStr(double);
    std::string IntStr(int);
    int StrInt(std::string);
    double StrDb(std::string);
    std::string QtStr(QString);
    QString StrQt(std::string);

    // looking for some exceptions
    // checks if provided number by user is a double variable
    bool onlyNumbersDb(std::string);
    // the same but with the int variable instead
    bool onlyNumbersInt(std::string);

    // updates the result by leaving the number only with 5 characters
    QString eraseResult(std::string);

    // issue when height is equal to 0
    void issueWhenHeightIsNull();

    // issue when user doesn't type numbers
    void noNumbersIssue();
};

#endif // BMICALC_H
