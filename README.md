# Youtube Time Steps
A very small console application for generating text which you can paste in YouTube video descriptions to generate chapters.   
This programm only helps you out if you must create a lot of chapters in your video and the chapters always have the same time interval between each other.
Here is an example video where I used the software to generate chapters automatically:   
https://www.youtube.com/watch?v=id4Z0EB9fHQ

## Example output
```
00:12 Step 50 & 51
00:22 Step 52 & 53
00:32 Step 54 & 55
00:42 Step 56 & 57
00:52 Step 58 & 59
01:02 Step 60 & 61
01:12 Step 62 & 63
01:22 Step 64 & 65
01:32 Step 66 & 67
01:42 Step 68 & 69
```
## Preparation
- install cmake and do your configuration shizzle (set compiler etc.)   
- you can edit the INSTALL_DEST variable in the CMakelists file to set the correct install dir

## Windows
just run the batch script to create a solution via cmake and after that build the INSTALL Target.   

## Linux
if you have not already, do the following:
```
sudo apt-get update
sudo apt install git
sudo apt isntall cmake
sudo apt install -y build-essential
```

just run the shell script and do the following:
```
cd build
make install
```

## How to use it
This software is a console application. You need to execute it on a terminal like this:

Arg 1: start time in seconds of 1. step   
Arg 2: number of steps to create   
-s \<uint\> [optional] Arg: starting step number. default=1   
-n \<uint\> [optional] Arg: number of steps per page. default=1   
-t \<uint\> [optional] Arg: seconds per step. default=5   
-f \<string\> [optional] Arg: write output to file. give the path where to save the file

### Example

The following command will create 79 steps starting at 17 seconds and save output to file timesteps.txt at location Desktop.   
The Step counter starts at 157 and every step is 10 seconds long:
```
youtubeTimeSteps 17 79 -f C:/Users/NicsMocs/Desktop -s 157 -n 1 -t 10
```

## Feature Request
Maybe you need something special. Just create a new issue. I'll take a look at that when I get a chance.  
