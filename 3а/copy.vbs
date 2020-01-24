Set WshShell = CreateObject ("WScript.Shell")
Set objEnv = WshShell.Environment("Process")
objEnv("MyDir") = "xcopy 1.txt 2.txt"
WShShell.Run objEnv("MyDir")
