Option Explicit
Dim Message
Dim WshShell, objEnv
Set WshShell = CreateObject ("WScript.Shell")
Set objEnv = WshShell.Environment("Process")
objEnv("MyCom")="C:\Windows\notepad.exe D:\3\Œ—Ë—œ\4\sysvar.vbs"
WshShell.Run objEnv("MyCom"),1
