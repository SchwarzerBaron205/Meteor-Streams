#include <iostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>

class Calculating

{
    std::vector<double> vector;

public:

    int RepetitionsCounting(std::vector<double> vector, double x); // Функция подсчёта повторений элемента x в матрице звёздных величин

    std::vector<double> InsertSort(std::vector<double> vector_test); // Сортировка вставками 

    std::vector<double> ExclusivVector(std::vector<double> vector); // Создание вектора из всех элементов заданного вектора без повторений

    void CountingMeteors(std::vector<double> vector, std::string filename_write); // Счёт числа каждого уникального метеора

    void CountingAllMeteorsAndBolids(std::vector<double> vector, std::string filename); // Счёт всех метеоров и болидов

    void MeanPopulationIndex(std::vector<double> vector_test, std::string filename_write); // Расчёт среднего популяционного индекса 

    double MeanPopulationIndex(std::vector<double> vector_test);

    double ZenithHourlyRateCalculating(std::vector<double> vector_test, int n, double factor, double limit_magnitude, double zenith_distance); // Вычисление зенитного часового числа

    std::vector<double> ZenithHourlyRateMatrix(std::vector<double> vector, double r); // Заполнение матрицы зенитного часового числа полученными значениями

    void MeanZenithHourlyRate(std::vector<double> zhr, std::string filename_write);

    double MeanZenithHourlyRate(std::vector<double> zhr); // Среднее значение зенитного часового числа

    void DispersionExperiment(std::vector<double> zhr, std::string filename_write); // Расчёт дисперсии эксперимента

    double DispersionExperiment(std::vector<double> zhr);

    void CorrectDispersionExperiment(std::vector<double> zhr, double dispersion, std::string filename_write); // Расчёт исправленной дисперсии эксперимента

    void MeanNorm(std::vector<double> zhr, std::string filename_write); // Отклонение среднего значения зенитного часового числа от нормы

};

class FileWork : public Calculating

{

public:

    std::string filename;
    std::string filename_write;
    std::vector<double> vector;
    std::string string;

    std::vector<double> ReadFile(std::string filename);

    void WriteFile_Number(double a, std::string filename_write);
    void WriteFile_Vector(std::vector<double> vector_test, std::string filename_write);
    void WriteFile_Datum(std::string string_test, std::string filename_write);
    bool ResearchMeteorStream(double r, double ZHR_0);
    bool ResearchMeteorStream(double r);
    bool New_ResearchMeteorStream();

};

int Calculating::RepetitionsCounting(std::vector<double> vector_test, double x) // Функция подсчёта повторений элемента x в матрице звёздных величин

{
    int counter = 0;

        for (int i = 0; i < vector_test.size(); i++)
        {

            if (vector_test[i] == x)
            {
                counter += 1;
            }
        }

    return counter;
}

std::vector<double> Calculating::ExclusivVector(std::vector<double> vector_test)

{
    std::vector<double> _vector;

    for (int i = 0; i < vector_test.size(); ++i)
    {
        // Начиная со второго все элементы проверяем на равенство с предыдущим, если равен, то пропускаем
        if ((i > 0) && (vector_test[i] == vector_test[static_cast<std::vector<double, std::allocator<double>>::size_type>(i) - 1]))
        {
            continue;
        }

        _vector.push_back(vector_test[i]);

    }

    return _vector;
}

std::vector<double> Calculating::InsertSort(std::vector<double> vector_test)

{
    for (int i = 1; i < vector_test.size(); ++i)
    {
        int j = i - 1;
        while ((j >= 0) && (vector_test[j] > vector_test[static_cast<std::vector<double, std::allocator<double>>::size_type>(j) + 1]))
        {
            std::swap(vector_test[j], vector_test[static_cast<std::vector<double, std::allocator<double>>::size_type>(j) + 1]);
            j--;
        }
    }
    return vector_test;
}

std::vector<double> FileWork::ReadFile(std::string filename_write) // считывание из файла

{

    std::ifstream file(filename_write);

    if (!file.is_open())

    {
        std::cerr << "Error 404! File isn't open!";
    }

    std::vector <double> vector;

    while (!file.eof())

    {
        double number;
        file >> number;
        vector.push_back(number);
    }

    file.close();

    std::cout << "Файл считан успешно!" << "\n";

    return vector;

}

void FileWork::WriteFile_Number(double a, std::string filename_write)
{

    std::ofstream file;

    file.open(filename_write, std::ofstream::app);

    file << a;

    file.close();

}

void FileWork::WriteFile_Vector(std::vector<double> vector_test, std::string filename_write)
{

    std::ofstream file;

    file.open(filename_write, std::ofstream::app);

    if (file.is_open())
    {
        for (int i = 0; i < vector_test.size(); i++)
        {

            if ((vector_test[i] >= 0) && (std::fmod(vector_test[i], 1) == 0))
            {
                file << " " << vector_test[i] << ".0 " << "\n";
            }
            if ((vector_test[i] > 0) && (std::fmod(vector_test[i], 1) != 0))
            {
                file << " " << vector_test[i] << "\n";
            }
            if ((vector_test[i] < 0) && std::fmod(vector_test[i], -1) == 0)
            {
                file << vector_test[i] << ".0 " << "\n";
            }
            if ((vector_test[i] < 0) && (std::fmod(vector_test[i], -1) != 0))
            {
                file << vector_test[i] << "\n";
            }

        }
    }
    else
    {
        std::cerr << "Error 404! File isn't open!";
    }
    file.close();

    std::cout << "Данные успешно записаны в файл " << filename_write << "\n";

}

void FileWork::WriteFile_Datum(std::string string_test, std::string filename_write)
{

    std::ofstream file;
    file.open(filename_write);

    file << "Дата наблюдений: " << string_test << "\n\n";

    file.close();

}

void Calculating::CountingMeteors(std::vector<double> vector_test, std::string filename_write) // Счёт числа каждого уникального метеора

{
    std::ofstream file1;

    file1.open(filename_write, std::ofstream::app);

    std::vector<double> second_vector;

    if (file1.is_open())

    {

        vector_test = InsertSort(vector_test);

        file1 << "\n3. N(m) метеоров равны: " << "\n\n";

        second_vector = ExclusivVector(vector_test);

        for (int i = 0; i < second_vector.size(); i++)

        {
            if ((second_vector[i] >= 0) && (std::fmod(second_vector[i], 1) == 0))

            {
                file1 << "   N(" << second_vector[i] << ".0) = " << RepetitionsCounting(vector_test, second_vector[i]) << "\n";
            }

            if ((second_vector[i] >= 0) && (std::fmod(second_vector[i], 1) != 0))

            {
                file1 << "   N(" << second_vector[i] << ") = " << RepetitionsCounting(vector_test, second_vector[i]) << "\n";
            }

            if ((second_vector[i] < 0) && (std::fmod(second_vector[i], -1) == 0))

            {
                file1 << "   N(" << second_vector[i] << ".0) = " << RepetitionsCounting(vector_test, second_vector[i]) << "\n";
            }

            if ((second_vector[i] < 0) && (std::fmod(second_vector[i], -1) != 0))

            {
                file1 << "   N(" << second_vector[i] << ") = " << RepetitionsCounting(vector_test, second_vector[i]) << "\n";
            }

        }

    }

    else 
    {
        std::cout << "Error! File isn't open!";
    }

    std::cout << "Числа уникальных метеоров успешно записаны в файл " << filename_write << "\n";

    file1.close();
}

void Calculating::CountingAllMeteorsAndBolids(std::vector<double> vector_test, std::string filename_write) // Счёт всех метеоров и болидов

{
    std::ofstream file;

    file.open(filename_write, std::ofstream::app);

    file << "1. Общее число метеоров: " << vector_test.size() << "\n";

    int bolids_counter = 0;

    for (int i = 0; i < vector_test.size(); i++)
    {
        if (vector_test[i] <= -4.5)
        {
            bolids_counter += 1;
        }
    }

    file << "\n2. Число болидов: " << bolids_counter << "\n";

    std::cout << "Число всех метеоров успешно записано в файл " << filename_write << "\n";

    file.close();
}

void Calculating::MeanPopulationIndex(std::vector<double> vector_test, std::string filename_write) // Расчёт среднего популяционного индекса

{
    std::ofstream file;

    file.open(filename_write, std::ofstream::app);

    std::vector<double> second_vector;

    if (file.is_open())

    {

        vector_test = InsertSort(vector_test);

        second_vector = ExclusivVector(vector_test);


        double summ = 0;
        int counter = 1;

        for (int i = 0; i < second_vector.size() ; i++)
            for (int j = 0; j <= second_vector.size() - 1; j++)
                if ((std::abs(second_vector[i] - second_vector[j]) <= 1) && (i != j))
                {
                    double p = RepetitionsCounting(vector_test, second_vector[i]);
                    double q = RepetitionsCounting(vector_test, second_vector[j]);
                    summ += p / q;
                    counter += 1;
                }

        double mean_population_index = summ / counter;

        file << "\n4. Средний популяционный индекс потока r = " << mean_population_index << "\n";

    }

    else
    {
        std::cerr << "Error 404! File isn't open!";
    }

    std::cout << "Вычислен средний популяционный индекс потока!" << "\n";

    file.close();

}

double Calculating::MeanPopulationIndex(std::vector<double> vector_test) // Расчёт среднего популяционного индекса

{

    std::vector<double> _vector_test;
    vector_test = InsertSort(vector_test);

    _vector_test = ExclusivVector(vector_test);


    double summ = 0;
    int counter = 1;

    for (int i = 0; i < _vector_test.size(); i++)
        for (int j = 0; j <= _vector_test.size() - 1; j++)
            if ((std::abs(_vector_test[i] - _vector_test[j]) <= 1) && (i != j))
            {
                double p = RepetitionsCounting(vector_test, _vector_test[i]);
                double q = RepetitionsCounting(vector_test, _vector_test[j]);
                summ += p / q;
                counter += 1;
            }

    double mean_population_index = summ / counter;

    return mean_population_index;

}

double Calculating::ZenithHourlyRateCalculating(std::vector<double> vector_test,int n, double factor, double limit_magnitude, double zenith_distance) // Вычисление зенитного часового числа

{
    const double pi = acos(-1.0);

    double rating_degree = 6.5 - limit_magnitude;

    double rating = MeanPopulationIndex(vector_test);

    double powered_rating = std::pow(rating, rating_degree);

    double a = (n * factor * powered_rating);

    double z = ((zenith_distance * pi) / 180.0);

    double b = cos(z);

    double zenith_hourly_rate = (a / b);

    std::cout << powered_rating;

    return zenith_hourly_rate;
}

std::vector<double> Calculating::ZenithHourlyRateMatrix(std::vector<double> vector_test, double r) // Заполнение матрицы зенитного часового числа полученными значениями

{

    int time;
    std::cout << "Сколько часов велись наблюдения?" << "\n";
    std::cin >> time;

    double alpha;
    std::cout << "Введите коэффициент закрытия неба облаками (в процентах) " << "\n";
    std::cin >> alpha;

    double factor = (1 / (1 - (alpha / 100)));

    double limit_magnitude;
    std::cout << "Введите предельную звёздную величину в данном эксперименте " << "\n";
    std::cin >> limit_magnitude;

    std::vector<double> zhr;
    double zenith_distance;
    int N;
    int counter = 1;

    while (counter <= time)
    {


        std::cout << "Введите зенитное расстояние радианта (в градусах) за " << counter << " час наблюдений " << "\n";
        std::cin >> zenith_distance;

        std::cout << "Введите число увиденных метеоров за " << counter << " час наблюдений " << "\n";
        std::cin >> N;

        if ((zenith_distance > 0) || (zenith_distance < 90))
        {
            double z = ZenithHourlyRateCalculating(vector_test, N, factor, limit_magnitude, zenith_distance);
            zhr.push_back(z);
        }

        else
        {
            std::cerr << "Некорректный ввод координат радианта потока!";
        }

        counter += 1;

    }

    return zhr;

}

void Calculating::MeanZenithHourlyRate(std::vector<double> zhr, std::string filename_write)
{
    std::ofstream file;

    file.open(filename_write, std::ofstream::app);

    double summ = 0;
    int counter = 0;

    for (int i = 0; i < zhr.size(); i++)
    {
        summ += zhr[i];
        counter += 1;
    }
    double mean_zhr = summ / counter;

    file << "\n" << "5. Среднее зенитное часовое число потока ZHR_ср = " << mean_zhr << "\n";

    std::cout << "Вычислено среднее зенитное часовое число потока!" << "\n";

    file.close();

}

double Calculating::MeanZenithHourlyRate(std::vector<double> zhr) // Среднее значение зенитного часового числа

{
    double summ = 0;

    for (int i = 0; i < zhr.size(); i++)
    {
        summ += zhr[i];
    }
    double mean_zhr = summ / zhr.size();

    return mean_zhr;
}

void Calculating::DispersionExperiment(std::vector<double> zhr, std::string filename_write) // Расчёт дисперсии эксперимента

{
    std::ofstream file;

    file.open(filename_write, std::ofstream::app);

    double summ = 0;
    int counter = 0;

    if (zhr.size() == 1)

    {
        file << "\n6. Выборочная дисперсия отсутствует " << "\n";
        std::cout << "Отстутствует выборочная дисперсия эксперимента" << "\n";
    }

    else

    {
        double zhr_mean = MeanZenithHourlyRate(zhr);

        for (int i = 0; i < zhr.size(); i++)
        {
            summ += (zhr[i] - zhr_mean) * (zhr[i] - zhr_mean);
            counter += 1;
        }

        double dispersion = summ / counter;

        file << "\n6. Выборочная дисперсия эксперимента D = " << dispersion << "\n";

        std::cout << "Вычислена выборочная дисперсия эксперимента!" << "\n";

    }

    file.close();

}

double Calculating::DispersionExperiment(std::vector<double> zhr)
{
    double zhr_mean = MeanZenithHourlyRate(zhr);

    double summ = 0;

    for (int i = 0; i < zhr.size(); i++)
    {
        summ += (zhr[i] - zhr_mean) * (zhr[i] - zhr_mean);
    }
    double dispersion = summ / zhr.size();

    return dispersion;
}

void Calculating::CorrectDispersionExperiment(std::vector<double> zhr, double dispersion, std::string filename_write) // Расчёт исправленной дисперсии эксперимента

{
    std::ofstream file;
    file.open(filename_write, std::ofstream::app);

    if (zhr.size() == 1)

    {
        file << "\n7. Исправленная дисперсия отсутствует " << "\n";
        std::cout << "Отстутствует исправленная дисперсия эксперимента" << "\n";
    }

    else

    {
        double correct_dispesion = dispersion * zhr.size() / (zhr.size() - 1);

        file << "\n7. Исправленная выборочная дисперсия эксперимента S^2 = " << correct_dispesion << "\n";

        std::cout << "Вычислена исправленная выборочная дисперсия эксперимента!" << "\n";

    }

    file.close();

}

void Calculating::MeanNorm(std::vector<double> zhr, std::string filename_write) // Отклонение среднего значения зенитного часового числа от нормы

{
    std::ofstream file;

    file.open(filename_write, std::ofstream::app);

    double zhr_0;

    std::cout << "Введите стандартное зенитное часовое число для изучаемого потока " << "\n";

    std::cin >> zhr_0;

    double zhr_mean = MeanZenithHourlyRate(zhr);

    double zhr_not_norm = zhr_0 - zhr_mean;

    file << "\n8. Отклонение вычисленного зенитного часового числа равно delta(ZHR) = " << zhr_not_norm << "\n";

    std::cout << "Вычислено отклонение вычисленного зенитного часового числа от нормы!" << "\n";
    file.close();
}

bool FileWork::ResearchMeteorStream(double r, double ZHR_0)
{

    FileWork file;
    FileWork file_write;

    std::string filename;
    std::string filename_write;
    std::string datum;
    std::string answer;

    bool flag = true;

    std::cout << "Введите имя файла, из которого надо считать данные" << "\n";
    std::cin >> filename;
    file.filename = filename;

    std::cout << "Введите имя файла, в который надо записывать данные " << "\n";
    std::cin >> filename_write;
    file_write.filename_write = filename_write;

    std::cout << "Введите дату наблюдений: ";
    std::cin >> datum;

    file_write.WriteFile_Datum(datum, filename_write);

    std::vector<double> magnitude_vector = file.ReadFile(filename);

    file_write.CountingAllMeteorsAndBolids(magnitude_vector, filename_write);

    file_write.CountingMeteors(magnitude_vector, filename_write);

    std::ofstream file1;

    file1.open(filename_write, std::ofstream::app);

    file1 << "\n4. Популяционный индекс потока r = ";

    file1.close();

    file_write.WriteFile_Number(r, filename_write);

    std::vector<double> zhr = file.ZenithHourlyRateMatrix(magnitude_vector, r);

    file1.open(filename_write, std::ofstream::app);

    file1 << "\n\n" << "5. Зенитные часовые числа:" << "\n\n";

    for (int i = 0; i < zhr.size(); i++) file1 << "\tZHR_" << i + 1 << " = " << zhr[i] << "\n";

    file1.close();

    file_write.MeanZenithHourlyRate(zhr, filename_write);

    double ZHR_mean = MeanZenithHourlyRate(zhr);

    file_write.DispersionExperiment(zhr, filename_write);

    double dispersion = file.DispersionExperiment(zhr);

    file_write.CorrectDispersionExperiment(zhr, dispersion, filename_write);


    file1.open(filename_write, std::ofstream::app);

    file1 << "\n8. Отклонение зенитного часового числа от нормы ZHR_0 - ZHR_ср = ";

    file1.close();

    double dZHR = ZHR_0 - ZHR_mean;

    file_write.WriteFile_Number(dZHR, filename_write);

    std::cout << "\n" << "Продолжить расчёт?" << "\n";
    std::cin >> answer;

    if ((answer == "Да") || (answer == "да") || (answer == "Yes") || (answer == "yes"))  flag = true;

    if ((answer == "Нет") || (answer == "нет") || (answer == "No") || (answer == "no"))  flag = false;

    return flag;

    }

bool FileWork::ResearchMeteorStream(double r)
{

        FileWork file;
        FileWork file_write;

        std::string filename;
        std::string filename_write;
        std::string datum;
        std::string answer;

        bool flag = true;

        std::cout << "Введите имя файла, из которого надо считать данные" << "\n";
        std::cin >> filename;
        file.filename = filename;

        std::cout << "Введите имя файла, в который надо записывать данные " << "\n";
        std::cin >> filename_write;
        file_write.filename_write = filename_write;

        std::cout << "Введите дату наблюдений: ";
        std::cin >> datum;

        file_write.WriteFile_Datum(datum, filename_write);

        std::vector<double> magnitude_vector = file.ReadFile(filename);

        file_write.CountingAllMeteorsAndBolids(magnitude_vector, filename_write);

        file_write.CountingMeteors(magnitude_vector, filename_write);

        std::ofstream file1;

        file1.open(filename_write, std::ofstream::app);

        file1 << "\n4. Популяционный индекс потока r = ";

        file1.close();

        file_write.WriteFile_Number(r, filename_write);

        std::vector<double> zhr = file.ZenithHourlyRateMatrix(magnitude_vector, r);

        file1.open(filename_write, std::ofstream::app);

        file1 << "\n\n" << "5. Зенитные часовые числа:" << "\n\n";

        for (int i = 0; i < zhr.size(); i++) file1 << "\tZHR_" << i + 1 << " = " << zhr[i] << "\n";

        file1.close();

        file_write.MeanZenithHourlyRate(zhr, filename_write);

        double ZHR_mean = MeanZenithHourlyRate(zhr);

        file_write.DispersionExperiment(zhr, filename_write);

        double dispersion = file.DispersionExperiment(zhr);

        file_write.CorrectDispersionExperiment(zhr, dispersion, filename_write);

        file1.open(filename_write, std::ofstream::app);

        file1 << "\n8. Норма данного потока неопределена. ZHR_0 - переменная величина. " << "\n";

        file1.close();

        std::cout << "Продолжить расчёт?" << "\n";
        std::cin >> answer;

        if ((answer == "Да") || (answer == "да") || (answer == "Yes") || (answer == "yes")) flag = true;

        if ((answer == "Нет") || (answer == "нет") || (answer == "No") || (answer == "no")) flag = false;

        return flag;

    }

bool FileWork::New_ResearchMeteorStream()
{


        FileWork file;
        FileWork file_write;

        std::string filename;
        std::string filename_write;
        std::string datum;
        std::string answer;

        bool flag = true;

        std::cout << "Введите имя файла, из которого надо считать данные" << "\n";
        std::cin >> filename;
        file.filename = filename;

        std::cout << "Введите имя файла, в который надо записывать данные " << "\n";
        std::cin >> filename_write;
        file_write.filename_write = filename_write;

        std::cout << "Введите дату наблюдений: ";
        std::cin >> datum;

        file_write.WriteFile_Datum(datum, filename_write);

        std::vector<double> magnitude_vector = file.ReadFile(filename);

        file_write.CountingAllMeteorsAndBolids(magnitude_vector, filename_write);

        file_write.CountingMeteors(magnitude_vector, filename_write);

        file_write.MeanPopulationIndex(magnitude_vector, filename_write);

        double r = file.MeanPopulationIndex(magnitude_vector);

        std::vector<double> zhr = file.ZenithHourlyRateMatrix(magnitude_vector, r);

        std::ofstream file1;

        file1.open(filename_write, std::ofstream::app);

        file1 << "\n" << "5. Зенитные часовые числа:" << "\n\n";

        for (int i = 0; i < zhr.size(); i++) file1 << "\tZHR_" << i + 1 << " = " << zhr[i] << "\n";

        file1.close();

        file_write.MeanZenithHourlyRate(zhr, filename_write);

        file_write.DispersionExperiment(zhr, filename_write);

        double dispersion = file.DispersionExperiment(zhr);

        file_write.CorrectDispersionExperiment(zhr, dispersion, filename_write);

        file_write.MeanNorm(zhr, filename_write);

        std::cout << "Продолжить расчёт?" << "\n";
        std::cin >> answer;

        if ((answer == "Да") || (answer == "да") || (answer == "Yes") || (answer == "yes")) flag = true;

        if ((answer == "Нет") || (answer == "нет") || (answer == "No") || (answer == "no")) flag = false;

        return flag;

    }
