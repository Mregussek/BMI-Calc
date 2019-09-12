#ifndef BMICALC_H
#define BMICALC_H

#include <QMainWindow>

namespace Ui {
class BMICalc;
}

/**
* Implements class for operating on Qt-based application
*/
class BMICalc : public QMainWindow
{
    Q_OBJECT

public:
    explicit BMICalc(QWidget *parent = 0);
    ~BMICalc();

private slots:
    /**
    * Decreases height by clicking the minus button
    */
    void on_minusHButton_clicked();

    /**
    * Increases height by clicking the plus button
    */
    void on_plusHButton_clicked();

    /**
    * Calculating BMI from given data
    */
    void on_calcButton_clicked();

    /**
    * Resets the whole data to standard 
    */
    void on_resetButton_clicked();

    /**
    * Decreases weight by clicking the minus button
    */
    void on_minusWButton_clicked();

    /**
    * Decreases weight by clicking the plus button
    */
    void on_plusWButton_clicked();

private:
    Ui::BMICalc *ui;
    int height = 100;
    double weight = 50.0;
    std::string heightStr = "100";
    std::string weightStr = "50.0";
    double result = 0.0;
    std::string resultStr = "0.0";


    /**
    * Calculates BMI from given data, when there is no error
    * converts to QString and returns
    * 
    * @return bmi
    */
    QString getResult();

    /**
     * Resets height and weight to standard values
     */
    void resetData();

    /**
     *  I use this function only on start of the app to show data on LineEdit Panels
     */
    void showData();

    /**
     * Gets height and weight from label. The reason for this method is to get
     * data, if user decided to use keyboard
     */ 
    void getData();

    /**
     * Update Height on labels to be actual from clicked button
     */
    void updateDataFromHeightClick();

    /**
     * Update Weight on labels to be actual from clicked button
     */
    void updateDataFromWeightClick();

    /**
     * Get height from label in QString format and return in std::string
     */
    std::string getHeight();

    /**
     * Get weight from label in QString format and return in std::string
     */
    std::string getWeight();

    /**
     * Decrements int value, int--
     * 
     * @param data value to decrement
     */
    void minus(int& data);

    /**
     * Increments int value, int++
     * 
     * @param data value to increment
     */
    void plus(int& data);
    
    /**
     * Decrements double value, double--
     * 
     * @param data value to decrement
     */
    void minus(double& data);

    /**
     * Incremets double value, double++
     * 
     * @param data value to increment
     */
    void plus(double& data);

    /**
     * Converts from double to std::string
     * 
     * @param data number in double format to convert
     */
    std::string DbStr(double data);

    /**
     * Converts from int to std::string
     * 
     * @param data number in int format to convert
     */
    std::string IntStr(int data);

    /**
     * Converts from std::string to in
     * 
     * @param data number in std::string to convert
     */
    int StrInt(std::string data);

    /**
     * Converts from std::string to double
     * 
     * @param data number in std::string to convert
     */
    double StrDb(std::string data);

    /**
     * Converts from QString to std::string
     * 
     * @param data number in QString to convert
     */
    std::string QtStr(QString data);

    /**
     * Converts from std::string to QString
     * 
     * @param data number in std::string to convert
     */
    QString StrQt(std::string data);

    /**
     * Checks if std::string is a double number
     * 
     * @param data std:string which will be checked
     */
    bool onlyNumbersDb(const std::string& data);

    /**
     * Checks if std::string is a int number
     * 
     * @param data std:string which will be checked
     */
    bool onlyNumbersInt(const std::string& data);

    /**
     * Updates the result by leaving the number only with 5 characters
     *
     * @param data result, which will be cut
     */ 
    QString eraseResult(std::string data);

    /**
     *  Issue when height is equal to 0
     */
    void issueWhenHeightIsNull();

    /** 
     * Issue when user doesn't type numbers
     */
    void noNumbersIssue();

    /**
     *  issue when user uses comma instead of dot
     * 
     * @param data std:string, which will be checked
     */
    std::string noDotIssue(std::string& data);
};

#endif // BMICALC_H
