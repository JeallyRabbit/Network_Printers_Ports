#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
using namespace std;

int main()
{
    //system("echo off");
    const char* powershell_command="powershell -Command \"Get-Printer | Select-Object PortName\" > ports.txt";
    string reg_command="reg query \"HKLM\\SYSTEM\\currentcontrolset\\control\\print\\monitors\\HP Standard TCP/IP Port\\Ports\\";
    system(powershell_command);
    vector <string> ip_address;
    string address;
    fstream ports_file;
    ports_file.open("ports.txt",std::fstream::in);
    vector <string> port;
    string port_temp;
    while(ports_file>>port_temp)
    {
        port.push_back(port_temp);
    }
    ports_file.close();
    system("del ports.txt");

    cout<<"----------------------------Porty Zainstalowanych Drukarek----------------------------"<<endl;

    for(int i=0; i<port.size(); i++)
    {
        if(port[i].length()>0)
        {
            if(port[i][0]=='H' && port[i][1]=='P')
            {
                reg_command+=port[i];
                reg_command+="\"";
                //reg_command+=" /v IPAddress";
                reg_command+=" /v IPAddress >> HP_reg_printer.txt";
                const char* register_command=reg_command.c_str();
                //cout<<register_command<<endl;
                //cout<<endl;
                address=system(register_command);
                //cout<<"adress= "<<address<<endl;
                ip_address.push_back(address);
                reg_command="reg query \"HKLM\\SYSTEM\\currentcontrolset\\control\\print\\monitors\\HP Standard TCP/IP Port\\Ports\\";
                register_command="";
            }
            else if(port[i][0]=='1' && port[i][1]=='9')
            {

                cout<<port[i]<<endl;
            }
        }
    }

    //wyciagnac z reg_printer.txt adresy
    fstream reg_file;
    reg_file.open("HP_reg_printer.txt",std::fstream::in);
    if(reg_file.good())
    {
        string reg_temp;
        cout<<"Zainstalowane za pomoca portow HP:"<<endl;
        while(getline(reg_file,reg_temp))
        {
            getline(reg_file,reg_temp);
            reg_temp.erase(0,97);
            cout<<reg_temp<<": ";
            getline(reg_file,reg_temp);
            reg_temp.erase(0,27);
            cout<<reg_temp<<endl;
            getline(reg_file,reg_temp);
        }
        reg_file.close();
        system("del HP_reg_printer.txt");

    }

    cout<<"---------------------------Press anything to end the program--------------------------"<<endl;
    char stop;
    stop=getchar();
    return 0;
}
