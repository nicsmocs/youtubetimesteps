#include "nicsmocs.h"
#include <iostream>
#include <fstream>
#include <string>

//defaults
unsigned long startTime = 0;
unsigned long numSteps = 0;
unsigned long startingStep = 1;
unsigned long numStepsPerPage = 1;
unsigned long stepSize = 5;
constexpr char fileName[] = "/timeSteps.txt";
std::string filePath = "";
std::string text = "";

std::string convertSecondsToYTString(int step)
{
    int minutes = static_cast<int>(startTime / 60);
    int secs = startTime - (minutes * 60);
    std::string strTime = "";

    if (minutes < 10)
    {
        strTime += "0";
    }

    strTime += std::to_string(minutes);
    strTime += ":";

    if (secs < 10)
    {
        strTime += "0";
    }

    strTime += std::to_string(secs);
    strTime += " Step " + std::to_string(step);

    for(int i = step+1; i < step + numStepsPerPage; ++i)
    {
        strTime += " & " + std::to_string(i);
    }

    strTime += "\n";
    return strTime;
}

void printHelp()
{
    std::cout << "YouTube Time Steps Creator" << std::endl;
    std::cout << "##########################" << std::endl;
    std::cout << "Arg 1: start time in seconds of 1. step" << std::endl;
    std::cout << "Arg 2: number of steps to create" << std::endl;
    std::cout << "-s <uint> [optional] Arg: starting step number. default=1" << std::endl;
    std::cout << "-n <uint> [optional] Arg: number of steps per page. default=1" << std::endl;
    std::cout << "-t <uint> [optional] Arg: seconds per step. default=5" << std::endl;
    std::cout << "-f <string> [optional] Arg: write output to file. give the path where to save the file" << std::endl;
    std::cout << "##########################" << std::endl;
    std::cout << "Example:" << std::endl;
    std::cout << "The following command will create 79 steps starting at 17 seconds and save output to file timesteps.txt at location Desktop." << std::endl;
    std::cout << "The Step counter starts at 157 and every step is 10 seconds long:" << std::endl;
    std::cout << "$ youtubeTimeSteps 17 79 -f C:/Users/NicsMocs/Desktop -s 157 -n 1 -t 10" << std::endl;
}

void printWelcome()
{
    std::cout << "__   __        _____     _        _____ _                _____ _                 " << std::endl;
    std::cout << "\\ \\ / /       |_   _|   | |      |_   _(_)              /  ___| |                " << std::endl;
    std::cout << " \\ V /___  _   _| |_   _| |__   ___| |  _ _ __ ___   ___\\ `--.| |_ ___ _ __  ___ " << std::endl;
    std::cout << "  \\ // _ \\| | | | | | | | '_ \\ / _ | | | | '_ ` _ \\ / _ \\`--. | __/ _ | '_ \\/ __|" << std::endl;
    std::cout << "  | | (_) | |_| | | |_| | |_) |  __| | | | | | | | |  __/\\__/ | ||  __| |_) \\__ \\" << std::endl;
    std::cout << "  \\_/\\___/ \\__,_\\_/\\__,_|_.__/ \\___\\_/ |_|_| |_| |_|\\___\\____/ \\__\\___| .__/|___/" << std::endl;
    std::cout << "                                                                      | |        " << std::endl;
    std::cout << "                                                                      |_|        " << std::endl;
}

int evaluateUserInput(int argc, char* argv[])
{
    if (argc < 3)
    {
        std::cout << "ERROR: too few arguments";
        return -1;
    }

    try
    {
        std::cout << std::endl << "started..." << std::endl;
        startTime = std::atoi(argv[1]);
        numSteps = std::atoi(argv[2]);

        for (unsigned int i = 3; i < argc; i+=2)
        {
            std::string arg = std::string(argv[i]);
            if (arg == "-f")
            {
                filePath = argv[i + 1];
            }
            else if(arg == "-s")
            {
                startingStep = std::stoul(argv[i + 1]);
            }
            else if (arg == "-t")
            {
                stepSize = std::stoul(argv[i + 1]);
            }
            else if (arg == "-n")
            {
                numStepsPerPage = std::stoul(argv[i + 1]);
            }
            else
            {
                return -1;
            }
        }
        return 0;
    }
    catch (...)
    {
        return -1;
    }
}

void writeToFile()
{
    const auto outFilePath = filePath + fileName;
    std::ofstream outputFile;
    outputFile.open(outFilePath);
    outputFile << text;
    outputFile.close();
    std::cout << "wrote output to file: " << outFilePath << std::endl;
}

void generateSteps()
{
    for (int i = startingStep; i <= startingStep - 1 + numSteps; i = i + numStepsPerPage)
    {
        text += convertSecondsToYTString(i);
        startTime += stepSize;
    }
}

int main(int argc, char* argv[])
{
    Init();
    printWelcome();

    if (evaluateUserInput(argc, argv) != 0)
    {
        std::cout << "wrong input. check arguments" << std::endl;
        printHelp();
        return -1;
    }

    generateSteps();

    if (!filePath.empty())
    {
        writeToFile();
    }
    else
    {
        std::cout << text <<std::endl;
    }

    std::cout << std::endl << std::endl << "finished" << std::endl;
    return 0;
}