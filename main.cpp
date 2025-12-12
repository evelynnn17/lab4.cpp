#include <iostream>
#include <string>
#include <vector>
#include <windows.h> // русский язык

using namespace std;
// структура информации о файлах папки (название, размер, тип)
struct FileInfo {
    string name;
    long size;
    string type;
};

// моя функция 1:
// 1. Получает путь к папке
// 2. Открывает эту папку через filesystem
// 3. Собирает ВСЕ файлы внутри папки (не подпапки!)
// 4. Для каждого файла получает данные
// 5. Возвращает вектор со структурой FileInfo для всех файлов
vector<FileInfo> scanFolder(const string& path) {
    vector<FileInfo> files;
    
    // временные тестовые данные
    files.push_back({"test.txt", 1500, ".txt"});
    
    return files;
}

// функции Маши
// 1. void printFileTable(const vector<FileInfo>& files)
 // Берёт вектор files
    // Форматирует в таблицу
// 2. void saveFolderReport(const vector<FileInfo>& files, const string& filename)
  // Берёт вектор files
    // Сохраняет в файл ("report.txt"):
    // Отчет анализа папки

int main() {
    SetConsoleOutputCP(CP_UTF8); // русский язык
    SetConsoleCP(CP_UTF8); // русский язык
    
    string path;
    cout << "Введите путь к папке: ";
    getline(cin, path);
    
    if (path.empty()) path = ".";
    
    // 1. моя функция
    vector<FileInfo> files = scanFolder(path);
    
    // 2. функция Маши 
    cout << "\n[DEBUG] Здесь будет вывод таблицы" << endl;
    
    // 3. функция Маши 
    cout << "[DEBUG] Здесь будет сохранение отчета" << endl;
    
    return 0;
}