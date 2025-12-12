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
void printFileTable(const vector<FileInfo>& files)
{
if (files.empty()) {
        cout << "Folder is empty or no files found." << endl;
        return;
}
 cout << "\n" << string(60, '=') << endl;
    cout << left << setw(40) << "File Name" 
         << setw(15) << "Size (bytes)" 
         << setw(10) << "Type" << endl;
    cout << string(60, '-') << endl;
    
    // Print data
    for (const auto& file : files) 
    {
        cout << left << setw(40) << file.name
             << setw(15) << file.size
             << setw(10) << file.type << endl;
    }
    cout << string(60, '=') << endl;
    cout << string(60, '=') << endl;
    
    long totalSize = 0;
    for (const auto& file : files) 
    {
        totalSize += file.size;
    }
}

// 2. Function to save folder report to file
void saveFolderReport(const vector<FileInfo>& files, const string& filename)
{
    ofstream outFile(filename);
    
    if (!outFile.is_open()) 
    {
        cerr << "Error: Could not create file " << filename << endl;
        return;
    }
    
    outFile << "FOLDER ANALYSIS REPORT" << endl;
    outFile << "======================" << endl << endl;
    
    if (files.empty()) 
    {
        outFile << "Folder is empty or no files found." << endl;
        outFile.close();
        return;
    }
    
    outFile << "Found files:" << endl;
    outFile << string(50, '-') << endl;
    
    for (const auto& file : files) 
    {
        outFile << "• " << file.name;
        outFile << " | Size: " << file.size << " bytes";
        outFile << " | Type: " << file.type << endl;
    }
    
    outFile << string(50, '-') << endl;
    
    long totalSize = 0;
    for (const auto& file : files) 
    {
        totalSize += file.size;
    }
    
    outFile << "SUMMARY:" << endl;
    outFile << "Number of files: " << files.size() << endl;
    outFile << "Total size: " << totalSize << " bytes";
    
    // Convert to KB/MB
    if (totalSize >= 1024) 
    {
        outFile << " (" << fixed << setprecision(2) << (double)totalSize / 1024 << " KB)";
    }
    if (totalSize >= 1024 * 1024) 
    {
        outFile << " (" << fixed << setprecision(2) << (double)totalSize / (1024 * 1024) << " MB)";
    }
    
    outFile.close();
    cout << "Report saved to file: " << filename << endl;
}

int main() 
{
    SetConsoleOutputCP(CP_UTF8); // русский язык
    SetConsoleCP(CP_UTF8); // русский язык
    
    string path;
    cout << "Введите путь к папке: ";
    getline(cin, path);
    
    if (path.empty()) path = ".";
    
    // 1. моя функция
    vector<FileInfo> files = scanFolder(path);
    
    // 2. функция Маши 
    printFileTable(files);
    
    // 3. функция Маши 
    saveFolderReport(files, "folder_report.txt");
    
    return 0;
}
