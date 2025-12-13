#include <iostream>
#include <string>
#include <vector>
#include <windows.h>
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
int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    string path = ".";
    cout << "Введите '.' для анализа текущей папки: ";
    getline(cin, path);
    
    getline(cin, path);
    if (path != ".") {
        path = ".";
        cout << "Используется текущая папка" << endl;
    }
    
    vector<FileInfo> files = scanFolder(path);
    
    // функции Маши
    
    cout << "\nНажмите Enter для выхода...";
    cin.ignore();
    cin.get();
    
    return 0;
}