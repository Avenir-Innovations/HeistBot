c:
cd \src\project
bash -c "cd /c/Users/201175794/Documents/GitHub/HeistBot/HeistBot"
bash -c "g++ -g $(find . -type f -iregex ".*\.cpp") -o Program.exe"
pause