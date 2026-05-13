#include "audio.h"

audio::audio(string n, node* ptr, string ft) : file(n, ptr, ft) {}

void audio::create() {
    string ffmpegPath = "C:\\Users\\Abdur Rehman\\source\\repos\\File Management System\\ffmpeg-8.1.1-essentials_build\\bin\\ffmpeg.exe";
    string deviceName = "@device_cm_{33D9A762-90C8-11D0-BD43-00A0C911CE86}\\wave_{37982850-FF97-4DE7-8ADC-6D71FC5BE609}";
    string outputFile = getPath();
    string command = "cmd /C \""
        + string("\"") + ffmpegPath + "\""
        + " -f dshow"
        + " -i audio=\"" + deviceName + "\""
        + " -t 5"
        + " \"" + outputFile + "\""
        + "\"";
    cout << "Recording for 5 seconds..." << endl;
    int result = system(command.c_str());
    if (result == 0) {
        cout << "Recording complete. File saved: " << getName() << "." << getFileType() << endl;
    }
    else {
        cout << "Error: Could not record audio." << endl;
    }
}

void audio::open() {
    string ffplayPath = "C:\\Users\\Abdur Rehman\\source\\repos\\File Management System\\ffmpeg-8.1.1-essentials_build\\bin\\ffplay.exe";
    string inputFile = getPath();
    string command = "cmd /C \""
        + string("\"") + ffplayPath + "\""
        + " -nodisp -autoexit"
        + " \"" + inputFile + "\""
        + "\"";
    cout << "Playing: " << getName() << "." << getFileType() << endl;
    system(command.c_str());
}

bool audio::Delete() {
    filesystem::remove(getPath());
    return true;
}