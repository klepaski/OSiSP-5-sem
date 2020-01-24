Set fso = WScript.CreateObject("Scripting.FileSystemObject")
Set file = fso.CreateTextFile("info.txt")

strComputer = "."
Set objWMIService = GetObject("winmgmts:" _
    & "{impersonationLevel=impersonate}!\\" & strComputer & "\root\cimv2")

Set colItems = objWMIService.ExecQuery("Select * from Win32_Processor")

For Each objItem in colItems
    file.WriteLine("�������: " & objItem.CurrentClockSpeed & vbCrLf)  
    file.WriteLine("�����������: " & objItem.DataWidth& vbCrLf)
    file.WriteLine("��������: " & objItem.Description& vbCrLf)
    file.WriteLine("���������: " & objItem.Family& vbCrLf)
    file.WriteLine("������ ���: " & objItem.L2CacheSize& vbCrLf)
    file.WriteLine("������� ��������: " & objItem.LoadPercentage& vbCrLf)
    file.WriteLine("�������������: " & objItem.Manufacturer& vbCrLf)
    file.WriteLine("����� ����������: " & objItem.ProcessorId& vbCrLf)
    file.WriteLine("������: " & objItem.Version & vbCrLf)
   
Next
file.Close