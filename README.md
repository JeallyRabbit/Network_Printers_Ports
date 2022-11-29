# Network_printers_ports

1. "powershell -Command "Get-Printer | Select-Object PortName" > ports.txt" - sends ports names to "ports.txt"
2. Read that file to vector "ports_file" and delete "ports.txt"
3.1 if ports is standard TCP/IP port (starting with "19") print that port
3.2 If port is standart HP TCP/IP port (starting with "HP") save name of that port
3.3 Execute "reg query "HKLM\SYSTEM\currentcontrolset\control\print\monitors\HP Standard TCP/IP Port\Ports\<HP_Port>\ /v IPAdress >> HP_reg_printer.txt" - sends HP ports ip to "HP_reg_printer.txt"
3.4 Read "HP_reg_printer.txt" and print <port_name> <port_ip>
3.5 Delete "HP_reg_printer.txt"
4. End program


Libraries: <iostream>, <fstream>, <vector>, <string>, <cstdio> 

Variables:
const char* powershell command - store comand to send to cmd

Vector <string> ip_address - zakomentowane - chyba nie potrzebna
string address - zakomentowane - chyba nie potrzebna

fstream ports_file - for reading "ports.txt"
vector <string> port - stores ports names
string port_temp - auxiliary for storing in "port"
fstream reg_file - for reading "HP_reg_printer.txt"
string reg_temp - auxiliary for reading "HP_reg_printer.txt"
