Set fso=WScript.CreateObject("Scripting.FileSystemObject")
Set file=fso.CreateTextFile("D:\newfile.bat")
file.WriteLine("start Excel.exe")
file.Close