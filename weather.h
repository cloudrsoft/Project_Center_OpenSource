#ifndef WEATHER_H
#define WEATHER_H

#include <QNetworkRequest>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QtCore>

class weather
{
public:
    weather();
    void setlocal(QString local2);
    void setcountry(QString country2);
    void setapiid(QString apiid2);
    void initWeather();
    void getWeather();
    int getTemp_C();
    int getTemp_Max_C();
    int getTemp_Min_C();
    int getTemp_F();
    int getTemp_Max_F();
    int getTemp_Min_F();
    QString getWeather_Icon();
    QString getWeather_Main();
    QString getWeather_Description();
    QString getLocal();
    QString getCountry();
    QString weather_url = "http://api.openweathermap.org/data/2.5/weather?";
    QString local;
    QString country;
    QString apiid;
    double weather_info_temp_max;
    double weather_info_temp;
    double weather_info_temp_min;
    double weather_info_temp_max_c;
    double weather_info_temp_c;
    double weather_info_temp_min_c;
    double weather_info_temp_max_f;
    double weather_info_temp_f;
    double weather_info_temp_min_f;
    QString weather_info_local;
    QString weather_info_country;
    QString weather_info_main;
    QString weather_info_description;
    QString weather_info_icon;
    int weatherinfo = 0;
    int up = 0;
    int down = 0;
};

#endif // WEATHER_H
