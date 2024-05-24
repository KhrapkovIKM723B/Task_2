#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class File 
{
protected:
    string name;
    int size;

public:
    File(string n, int s) : name(n), size(s) {}

    virtual void show() 
    {
        cout << "Назва: " << name << endl;
        cout << "Розмір: " << size << " кілобайт" << endl;
    }

    virtual void read() = 0;
    virtual void write() = 0;
};

class TextFile : public File 
{
    string content;

public:
    TextFile(string n, int s, string c) : File(n, s), content(c) {}

    void show() override 
    {
        cout << "Текстовий файл:" << endl;
        File::show();
        cout << "Зміст: " << content << endl;
    }

    void read() override
    {
        cout << "Зчитування текстового файлу: " << content << endl;
    }

    void write() override
    {
        cout << "Запис текстового файлу: " << content << endl;
    }
};

class ImageFile : public File 
{
    int width;
    int height;

public:
    ImageFile(string n, int s, int w, int h) : File(n, s), width(w), height(h) {}

    void show() override 
    {
        cout << "Зображення:" << endl;
        File::show();
        cout << "Розмір: " << width << "x" << height << " пікселів" << endl;
    }

    void read() override 
    {
        cout << "Зчитування зображення: " << name << endl;
    }

    void write() override
    {
        cout << "Запис зображення: " << name << endl;
    }
};

class VideoFile : public File
{
    int duration;

public:
    VideoFile(string n, int s, int d) : File(n, s), duration(d) {}

    void show() override 
    {
        cout << "Відео файл:" << endl;
        File::show();
        cout << "Тривалість: " << duration << " секунд" << endl;
    }

    void read() override 
    {
        cout << "Зчитування відео: " << name << endl;
    }

    void write() override
    {
        cout << "Запис відео: " << name << endl;
    }
};

int main() 
{
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    TextFile text("Документ.txt", 100, "Це зміст текстового файлу.");
    ImageFile image("Фото.jpg", 2048, 1920, 1080);
    VideoFile video("Фільм.mp4", 500000, 7200);

    text.show();
    text.read();
    text.write();

    cout << endl;

    image.show();
    image.read();
    image.write();

    cout << endl;

    video.show();
    video.read();
    video.write();

    return 0;
}
