#include "weather.h"

weather::weather()
{

}

void weather::setlocal(QString local2)
{
    local = local2;
    weather_url = "http://api.openweathermap.org/data/2.5/weather?q=" + local + "," + country+ "&appid=" + apiid;
}

void weather::setcountry(QString country2)
{
    country = country2;
    weather_url = "http://api.openweathermap.org/data/2.5/weather?q=" + local + "," + country + "&appid=" + apiid;
}

void weather::setapiid(QString apiid2)
{
    apiid = apiid2;
    weather_url = "http://api.openweathermap.org/data/2.5/weather?q=" + local + "," + country + "&appid=" + apiid;
}

void weather::initWeather()
{
    // If you very lazy, Here is set Macros!
    setlocal("London");
    setcountry("uk");
    setapiid("f936f868f0796c9a233453edd0bb7c2b");
}

void weather::getWeather()
{
    // If you will get Weather Info, Please start this function
        QByteArray result = "{}";
        QUrl url(weather_url);
        QNetworkRequest request(url);

        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

        QNetworkAccessManager *manager = new QNetworkAccessManager;

        QEventLoop loop;
        QObject::connect(manager, SIGNAL(finished(QNetworkReply*)), &loop, SLOT(quit()));
        QNetworkReply * reply = manager->post(request,result);
        loop.exec();

        QByteArray response = reply->readAll();

        QJsonDocument jsondocument = QJsonDocument::fromJson(response);
        QJsonObject jsonobject = jsondocument.object();
        QJsonObject main_infos = jsonobject.value("main").toObject();
        QJsonObject sys_infos = jsonobject.value("sys").toObject();
        QJsonArray weather_infos = jsonobject["weather"].toArray();

        // this part is can get weather temp
        weather_info_temp = main_infos.value("temp").toDouble();
        weather_info_temp_max = main_infos.value("temp_max").toDouble();
        weather_info_temp_min = main_infos.value("temp_min").toDouble();
        weather_info_temp_max_c = weather_info_temp - 273.15;
        weather_info_temp_c = weather_info_temp - 273.15;
        weather_info_temp_min_c = weather_info_temp - 273.15;
        weather_info_temp_max_f = (weather_info_temp_max * 9) / 5 - 459.67;
        weather_info_temp_f = (weather_info_temp * 9) / 5 - 459.67;
        weather_info_temp_min_f = (weather_info_temp_min * 9) / 5 - 459.67;

        // and, this part is can get posted local, and country
        weather_info_local = jsonobject.value("name").toString();
        weather_info_country = sys_infos.value("country").toString();

        // this part is can get weather info
        for(auto&& item: weather_infos)
        {
            const QJsonObject& weather_info = item.toObject();
            weather_info_main = weather_info["main"].toString();
            weather_info_description = weather_info["description"].toString();
            weather_info_icon = weather_info["icon"].toString();
        }
}

int weather::getTemp_C()
{
    return (int)weather_info_temp_c;
}

int weather::getTemp_Max_C()
{
    return (int)weather_info_temp_max_c;
}

int weather::getTemp_Min_C()
{
    return (int)weather_info_temp_min_c;
}

int weather::getTemp_F()
{
    return (int)weather_info_temp_f;
}

int weather::getTemp_Max_F()
{
    return (int)weather_info_temp_max_f;
}

int weather::getTemp_Min_F()
{
    return (int)weather_info_temp_min_f;
}

QString weather::getWeather_Icon()
{
    return weather_info_icon;
}

QString weather::getWeather_Main()
{
    return weather_info_main;
}

QString weather::getWeather_Description()
{
    return weather_info_description;
}

QString weather::getLocal()
{
    return weather_info_local;
}

QString weather::getCountry()
{
    return weather_info_country;
}
