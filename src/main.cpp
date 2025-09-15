#include <Python.h>
#include <iostream>
#include <string>

void waitForUser() {
    std::cout << "Press Enter to continue...";
    std::cin.get();
}

int main() {
    // Initialize Python interpreter
    Py_Initialize();
    if (!Py_IsInitialized()) {
        std::cerr << "Error: Python interpreter initialization failed.\n";
        waitForUser();
        return 1;
    }
    std::cout << "Python interpreter initialized successfully.\n";
    std::cout << "Python version: " << Py_GetVersion() << "\n";

  
    // (Optional) also add user/system site-packages
    PyRun_SimpleString(
        "import sys, site\n"
        "sys.path.append(site.getusersitepackages())\n"
        "for p in site.getsitepackages():\n"
        "    if p not in sys.path:\n"
        "        sys.path.append(p)\n"
    );

    
    std::string url = "https://www.youtube.com/watch?v=dQw4w9WgXcQ"; // sample video

    // Get user input for URL
    std::cout << "Enter the URL of the video to download (or press Enter to use default): ";
    std::string userInput;
    std::getline(std::cin, userInput);
    if (!userInput.empty()) {
        url = userInput;
    }

    std::string pyCode =
        "import yt_dlp\n"
        "url = '" + url + "'\n"
        "ydl_opts = {'outtmpl': '%(title)s.%(ext)s'}\n"
        "with yt_dlp.YoutubeDL(ydl_opts) as ydl:\n"
        "    ydl.download([url])\n";

    // Run the script with the provided URL
    int result = PyRun_SimpleString(pyCode.c_str());
    if (result != 0) {
        std::cerr << "Error: yt-dlp execution failed.\n";
    } else {
        std::cout << "Download complete!\n";
    }


    waitForUser();

    // Finalize Python interpreter
    Py_Finalize();

    return 0;
}

/*
# Generate build files
cmake -B build -S .


# Compile
cmake --build build --config Release
*/