Set fso = WScript.CreateObject("Scripting.FileSystemObject")
Set file = fso.CreateTextFile("info.txt")

strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
    & "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")

Set colItems = objWMIService.ExecQuery("Select * from Win32_Processor")

For Each objItem in colItems
    file.WriteLine("Частота: " & objItem.CurrentClockSpeed & vbCrLf)  
    file.WriteLine("Разрядность: " & objItem.DataWidth& vbCrLf)
    file.WriteLine("Описание: " & objItem.Description& vbCrLf)
    file.WriteLine("Семейство: " & objItem.Family& vbCrLf)
    file.WriteLine("Размер кэш: " & objItem.L2CacheSize& vbCrLf)
    file.WriteLine("Текущая загрузка: " & objItem.LoadPercentage& vbCrLf)
    file.WriteLine("Производитель: " & objItem.Manufacturer& vbCrLf)
    file.WriteLine("Номер процессора: " & objItem.ProcessorId& vbCrLf)
    file.WriteLine("Версия: " & objItem.Version & vbCrLf)
   
Next
file.Close