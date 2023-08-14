#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>
#include "FileCalc.h"
#include "Info.h"


bool Menu()
{

    bool flag = true;

    int answer;

    std::cout << "Добро пожаловать в калькулятор расчёта ZHR метеорного потока!" << "\n";
    std::cout << "1. Исследовать поток" << "\n";
    std::cout << "2. Получить информацию о потоке" << "\n";

    std::cin >> answer;

    switch (answer)

    {

    case 1:
    {
        flag = true;
        break;
    }

    case 2:
    {
        flag = false;
        MeteorInfo();
        break;
    }

    }

    return flag;

}

int main()

{

    setlocale(LC_ALL, "ru");

    bool research = Menu();

    while (research)
    {

        FileWork HEAD;

        std::cout << "Выберите метеорный поток для изучения:" << "\n";
        std::cout << "1. Квадрантиды (QUA)" << "\n";
        std::cout << "2. дельта-Канцириды (DCA)" << "\n";
        std::cout << "3. альфа-Центавриды (ACE)" << "\n";
        std::cout << "4. дельта-Леониды (DLE)" << "\n";
        std::cout << "5. гамма-Нормиды (GNO)" << "\n";
        std::cout << "6. Виргиниды (VIR)" << "\n";
        std::cout << "7. Лириды (LYR)" << "\n";
        std::cout << "8. пи-Пуппиды (PPU)" << "\n";
        std::cout << "9. эта-Аквариды (ETA)" << "\n";
        std::cout << "10. Сагиттариды (SAG)" << "\n";
        std::cout << "11. Июньские Боотиды (JBO)" << "\n";
        std::cout << "12. Пегасиды (JPE)" << "\n";
        std::cout << "13. Июльские Фенициды (PHE)" << "\n";
        std::cout << "14. Южные Писциды (PAU)" << "\n";
        std::cout << "15. Южные дельта-Аквариды (SDA)" << "\n";
        std::cout << "16. альфа-Каприкорниды (CAP)" << "\n";
        std::cout << "17. Южные йота-Аквариды (SIA)" << "\n";
        std::cout << "18. Северные дельта-Аквариды (NDA)" << "\n";
        std::cout << "19. Персеиды (PER)" << "\n";
        std::cout << "20. каппа-Цигниды (KCG)" << "\n";
        std::cout << "21. Северные йота-Аквариды (NIA)" << "\n";
        std::cout << "22. альфа-Ауригиды (AUR)" << "\n";
        std::cout << "23. дельта-Ауригиды (DAU)" << "\n";
        std::cout << "24. Писциды (SPI)" << "\n";
        std::cout << "25. Дракониды (GIA)" << "\n";
        std::cout << "26. эпсилон-Геминиды (EGE)" << "\n";
        std::cout << "27. Ориониды (ORI)" << "\n";
        std::cout << "28. Южные Тауриды (STA)" << "\n";
        std::cout << "29. Северные Тауриды (NTA)" << "\n";
        std::cout << "30. Леониды (LEO)" << "\n";
        std::cout << "31. альфа-Моноцеротиды (AMO)" << "\n";
        std::cout << "32. хи-Ориониды (XOR)" << "\n";
        std::cout << "33. Декабрьские Фенициды (PHO)" << "\n";
        std::cout << "34. Пуппиды/Велиды (PUP)" << "\n";
        std::cout << "35. Моноцеротиды (MON)" << "\n";
        std::cout << "36. сигма-Гидриды (HYD)" << "\n";
        std::cout << "37. Геминиды (GEM)" << "\n";
        std::cout << "38. Кома Беренициды (COM)" << "\n";
        std::cout << "39. Урсиды(URS)" << "\n";
        std::cout << "40. Неизвестный метеорный поток" << "\n";

        int number;

        std::cin >> number;

        switch (number)
        {
        case 1:
        {
            std::cout << "Вы исследуете метеорный поток Квадрантиды (QUA)!" << "\n";
            double r = 2.1;
            double ZHR_0 = 120.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 2:
        {
            std::cout << "Вы исследуете метеорный поток дельта-Канцириды (DCA)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 4.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 3:
        {
            std::cout << "Вы исследуете метеорный поток альфа-Центавриды (ACE)!" << "\n";
            double r = 2.0;
            double ZHR_0 = 6.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 4:
        {
            std::cout << "Вы исследуете метеорный поток дельта-Леониды (DLE)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 2.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 5:
        {
            std::cout << "Вы исследуете метеорный поток гамма-Нормиды (GNO)!" << "\n";
            double r = 2.4;
            double ZHR_0 = 8.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 6:
        {
            std::cout << "Вы исследуете метеорный поток Виргиниды (VIR)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 5.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 7:
        {
            std::cout << "Вы исследуете метеорный поток Лириды (LYR)!" << "\n";
            double r = 2.1;
            double ZHR_0 = 18.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 8:
        {
            std::cout << "Вы исследуете метеорный поток пи-Пуппиды (PPU)!" << "\n";
            double r = 2.0;
            research = HEAD.ResearchMeteorStream(r);
            break;
        }
        case 9:
        {
            std::cout << "Вы исследуете метеорный поток эта-Аквариды (ETA)!" << "\n";
            double r = 2.4;
            double ZHR_0 = 60.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 10:
        {
            std::cout << "Вы исследуете метеорный поток Сагиттариды (SAG)!" << "\n";
            double r = 2.5;
            double ZHR_0 = 5.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 11:
        {
            std::cout << "Вы исследуете метеорный поток Июньские Боотиды (JBO)!" << "\n";
            double r = 2.2;
            research = HEAD.ResearchMeteorStream(r);
            break;
        }
        case 12:
        {
            std::cout << "Вы исследуете метеорный поток Пегасиды (JPE)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 3.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 13:
        {
            std::cout << "Вы исследуете метеорный поток Июльские Фенициды (PHE)!" << "\n";
            double r = 3.0;
            research = HEAD.ResearchMeteorStream(r);
            break;
        }
        case 14:
        {
            std::cout << "Вы исследуете метеорный поток Южные Писциды (PAU)!" << "\n";
            double r = 3.2;
            double ZHR_0 = 5.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 15:
        {
            std::cout << "Вы исследуете метеорный поток Южные дельта-Аквариды (SDA)!" << "\n";
            double r = 3.2;
            double ZHR_0 = 20.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 16:
        {
            std::cout << "Вы исследуете метеорный поток альфа-Каприкорниды (CAP)!" << "\n";
            double r = 2.5;
            double ZHR_0 = 4.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 17:
        {
            std::cout << "Вы исследуете метеорный поток Южные йота-Аквариды (SIA)!" << "\n";
            double r = 2.9;
            double ZHR_0 = 2.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 18:
        {
            std::cout << "Вы исследуете метеорный поток Северные дельта-Аквариды (NDA)!" << "\n";
            double r = 3.4;
            double ZHR_0 = 4.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 19:
        {
            std::cout << "Вы исследуете метеорный поток Персеиды (PER)!" << "\n";
            double r = 2.6;
            double ZHR_0 = 100.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 20:
        {
            std::cout << "Вы исследуете метеорный поток каппа-Цигниды (KCG)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 3.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 21:
        {
            std::cout << "Вы исследуете метеорный поток Северные йота-Аквариды (NIA)!" << "\n";
            double r = 3.2;
            double ZHR_0 = 3.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 22:
        {
            std::cout << "Вы исследуете метеорный поток альфа-Ауригиды (AUR)!" << "\n";
            double r = 2.6;
            double ZHR_0 = 10.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 23:
        {
            std::cout << "Вы исследуете метеорный поток дельта-Ауригиды (DAU)!" << "\n";
            double r = 2.9;
            double ZHR_0 = 5.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 24:
        {
            std::cout << "Вы исследуете метеорный поток Писциды (SPI)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 3.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 25:
        {
            std::cout << "Вы исследуете метеорный поток Дракониды (GIA)!" << "\n";
            double r = 2.6;
            research = HEAD.ResearchMeteorStream(r);
            break;
        }
        case 26:
        {
            std::cout << "Вы исследуете метеорный поток эпсилон-Геминиды (EGE)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 2.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 27:
        {
            std::cout << "Вы исследуете метеорный поток Ориониды (ORI)!" << "\n";
            double r = 2.5;
            double ZHR_0 = 23.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 28:
        {
            std::cout << "Вы исследуете метеорный поток Южные Тауриды (STA)!" << "\n";
            double r = 2.3;
            double ZHR_0 = 5.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 29:
        {
            std::cout << "Вы исследуете метеорный поток Северные Тауриды (NTA)!" << "\n";
            double r = 2.3;
            double ZHR_0 = 5.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 30:
        {
            std::cout << "Вы исследуете метеорный поток Леониды (LEO)!" << "\n";
            double r = 2.5;
            double ZHR_0 = 15.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 31:
        {
            std::cout << "Вы исследуете метеорный поток альфа-Моноцеротиды (AMO)!" << "\n";
            double r = 2.4;
            research = HEAD.ResearchMeteorStream(r);
            break;
        }
        case 32:
        {
            std::cout << "Вы исследуете метеорный поток хи-Ориониды (XOR)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 3.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 33:
        {
            std::cout << "Вы исследуете метеорный поток Декабрьские Фенициды (PHO)!" << "\n";
            double r = 2.8;
            research = HEAD.ResearchMeteorStream(r);
            break;
        }
        case 34:
        {
            std::cout << "Вы исследуете метеорный поток Пуппиды/Велиды (PUP)!" << "\n";
            double r = 2.9;
            double ZHR_0 = 10.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 35:
        {
            std::cout << "Вы исследуете метеорный поток Моноцеротиды (MON)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 3.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 36:
        {
            std::cout << "Вы исследуете метеорный поток сигма-Гидриды (HYD)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 2.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 37:
        {
            std::cout << "Вы исследуете метеорный поток Геминиды (GEM)!" << "\n";
            double r = 2.6;
            double ZHR_0 = 120.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 38:
        {
            std::cout << "Вы исследуете метеорный поток Кома Беренициды (COM)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 5.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 39:
        {
            std::cout << "Вы исследуете метеорный поток Урсиды(URS)!" << "\n";
            double r = 3.0;
            double ZHR_0 = 10.0;
            research = HEAD.ResearchMeteorStream(r, ZHR_0);
            break;
        }
        case 40:
        {
            std::cout << "Вы исследуете неизвестный метеорный поток!" << "\n";
            research = HEAD.New_ResearchMeteorStream();
            break;
        }

        return 0;

        }
    }
}
