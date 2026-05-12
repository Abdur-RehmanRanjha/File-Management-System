#include "audio.h"

audio::audio(string n, node* ptr, string ft) :file(n, ptr, ft) {}

void audio::create() {
    cout << "Microphone recording started!" << endl;
    string command = "ffmpeg -y -f dshow -i audio=\"Microphone Array(Intel® Smart Sound Technology(Intel® SST))\" -t 5 \"" + getPath() + "\"";
    int result = system(command.c_str());
    if (result == 0) {
        cout << "Recording period has ended. File created." << endl;
    }
    else {
        cout << "Error: Could not access microphone. Check device name." << endl;
    }
}

void audio::open() {
    cout << "Playing: " << name << endl;
    string command = "ffplay -nodisp -autoexit \"" + getPath() + "\"";
    system(command.c_str());
}

bool audio::Delete() {
    filesystem::remove(getPath());
    return true;
}