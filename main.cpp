#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // русский язык
#include <iomanip>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = filesystem;

struct FileInfo {
    string name;
    long size;
    string type;
};

// функция 1 (участник №1 - Эвелина)
vector<FileInfo> scanFolder(const string& path) {
    vector<FileInfo> files;
    cout << "Выполняется сканирование: " << path << endl;
    
    for (const auto& entry : fs::directory_iterator(path)) {
        if (fs::is_regular_file(entry.path())) {
            FileInfo file;
            file.name = entry.path().filename().string();
            file.size = fs::file_size(entry.path());
            file.type = entry.path().extension().string();
            if (file.type.empty()) {
                file.type = "файл";
            }
            
            files.push_back(file);
            cout << "  " << file.name << " - " << file.size << " байт (" << file.type << ")" << endl;
        }
    }
    cout << "Всего файлов: " << files.size() << endl;
    return files;
}


// функции Маши
void printFileTable(const vector<FileInfo>& files)
{
if (files.empty()) {
        cout << "Папка пуста или файлы не найдены." << endl;
        return;
}
 cout << "\n" << string(60, '=') << endl;
    cout << left << setw(40) << "Имя файла" 
         << setw(15) << "Размер(байты)" 
         << setw(10) << "Тип" << endl;
    cout << string(60, '-') << endl;
    
    // Print data
    for (const auto& file : files) 
    {
        cout << left << setw(40) << file.name
             << setw(15) << file.size
             << setw(10) << file.type << endl;
    }
    cout << string(60, '=') << endl;
    
    
    long totalSize = 0;
    for (const auto& file : files) 
    {
        totalSize += file.size;
    }
    cout << "Всего файлов: " << files.size() << endl;
    cout << "Общий размер: " << totalSize << " байт";
    
    if (totalSize >= 1024) 
    {
        cout << " (" << fixed << setprecision(2) << (double)totalSize / 1024 << " КБ)";
    }
    if (totalSize >= 1024 * 1024) 
    {
        cout << " (" << fixed << setprecision(2) << (double)totalSize / (1024 * 1024) << " МБ)";
    }
    cout << endl;
}

// 2. Function to save folder report to file
void saveFolderReport(const vector<FileInfo>& files, const string& filename)
{
    ofstream outFile(filename);
    
    if (!outFile.is_open()) 
    {
        cerr << "Ошибка: не удалось создать файл " << filename << endl;
        return;
    }
    
    outFile << "ОТЧЁТ АНАЛИЗА ПАПКИ" << endl;
    outFile << "======================" << endl << endl;
    
    if (files.empty()) 
    {
        outFile << "Папка пуста или файлы не найдены." << endl;
        outFile.close();
        return;
    }
    
    outFile << "Найденные файлы:" << endl;
    outFile << string(50, '-') << endl;
    
    for (const auto& file : files) 
    {
        outFile << "• " << file.name;
        outFile << " | Размер: " << file.size << " байт";
        outFile << " | Тип: " << file.type << endl;
    }
    
    outFile << string(50, '-') << endl;
    
    long totalSize = 0;
    for (const auto& file : files) 
    {
        totalSize += file.size;
    }
    
    outFile << "ИТОГИ:" << endl;
    outFile << "Количество файлов: " << files.size() << endl;
    outFile << "Общий размер: " << totalSize << " байт";
    
    
    outFile.close();
    cout << "Отчёт сохранён в файл: " << filename << endl;
}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    string path;
    cout << "Введите '.' для анализа текущей папки: ";
    
    
    getline(cin, path);
    if (path != ".") {
        path = ".";
        cout << "Используется текущая папка" << endl;
    }
    
    vector<FileInfo> files = scanFolder(path);
    
    // 2. функция Маши 
    printFileTable(files);
    
    // 3. функция Маши 
    saveFolderReport(files, "folder_report.txt");

    // функции Маши
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore();
    cin.get();
    
    return 0;
}
