mingw32-make
(start /B test.exe 1> test.txt 2>&1) || (./test.exe 1> test.txt 2>&1)
pause