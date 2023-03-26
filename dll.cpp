// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "dll.h"

string ribojimas(string vardas, string dienos[], string laikas[])
{
    string eilute = "net user " + vardas + " /time:" + dienos[0] + "-" + dienos[1] + "," + laikas[0] + "-" + laikas[1];
    return eilute;
}

bool compare(const Taskas& unit1, const Taskas& unit2)
{
    return(unit1.x < unit2.x);
}

void nested_folders()
{
    system("mkdir lukosiuno\ ");
    system("mkdir lukosiuno\\kasparo1\ ");
    system("mkdir lukosiuno\\kasparo1\\kasparokasparas1\ ");
    system("mkdir lukosiuno\\kasparo1\\kasparokasparas2\ ");
    system("mkdir lukosiuno\\kasparo1\\kasparokasparas3\ ");
    system("mkdir lukosiuno\\kasparo2\ ");
    system("mkdir lukosiuno\\kasparo2\\kasparokasparas1\ ");
    system("mkdir lukosiuno\\kasparo2\\kasparokasparas2\ ");
    system("mkdir lukosiuno\\kasparo2\\kasparokasparas3\ ");
    system("mkdir lukosiuno\\kasparo3\ ");
    system("mkdir lukosiuno\\kasparo3\\kasparokasparas1\ ");
    system("mkdir lukosiuno\\kasparo3\\kasparokasparas2\ ");
    system("mkdir lukosiuno\\kasparo3\\kasparokasparas3\ ");
}

const string paths[13] = { "lukosiuno", "lukosiuno/kasparo1", "lukosiuno/kasparo1/kasparokasparas1", "lukosiuno/kasparo1/kasparokasparas2", "lukosiuno/kasparo1/kasparokasparas3", "lukosiuno/kasparo2", "lukosiuno/kasparo2/kasparokasparas1", "lukosiuno/kasparo2/kasparokasparas2", "lukosiuno/kasparo2/kasparokasparas3", "lukosiuno/kasparo3", "lukosiuno/kasparo3/kasparokasparas1", "lukosiuno/kasparo3/kasparokasparas2", "lukosiuno/kasparo3/kasparokasparas3" };
const string info[13] = { "lukosiuno\\", "lukosiuno\\kasparo1\\", "lukosiuno\\kasparo1\\kasparokasparas1\\", "lukosiuno\\kasparo1\\kasparokasparas2\\", "lukosiuno\\kasparo1\\kasparokasparas3\\", "lukosiuno\\kasparo2\\", "lukosiuno\\kasparo2\\kasparokasparas1\\", "lukosiuno\\kasparo2\\kasparokasparas2\\", "lukosiuno\\kasparo2\\kasparokasparas3\\", "lukosiuno\\kasparo3\\", "lukosiuno\\kasparo3\\kasparokasparas1\\", "lukosiuno\\kasparo3\\kasparokasparas2\\", "lukosiuno\\kasparo3\\kasparokasparas3\\" };


double tschirnhausen(double F, double x) {
    return sqrt(x * x * 3 + x * x * x - F);
}

void writeToFile(double x, double y, int i, double F) {
    string line;
    string filename = paths[i % 13] + "/F" + to_string(F).erase(to_string(F).find_last_not_of('0') + 1, std::string::npos) + "pora" + to_string(i + 1) + ".txt"; // Kuriamas fialas
    ofstream fr(filename);
    line = to_string(x) + " " + to_string(y) + "\n";
    fr << line;
    fr.close();
}

void calculateTschirnhausen(double F, double x0, double xn, double dx) {
    double x = x0;
    double y;
    int i = 0;
    while (x <= xn) {
        y = tschirnhausen(F, x);
        if (!isnan(y)) {
            writeToFile(x, y, i, F);
            i++;
        }
        x += dx;
    }
}

void merge(double F)
{
    string line;
    const char DF[] = "duomenys.txt";
    string command1, command2;
    for (int i = 0; i < 13; i++)
    {
        command1 = "for %f in (" + info[i] + "*.txt) do type \"%f\" >> output" + to_string(i) + ".txt";
        command2 = "del /Q " + info[i] + "*.txt";
        system(command1.c_str());
        system(command2.c_str());
    }
    system("for %f in (*.txt) do type \"%f\" >> duomenys.txt");
    vector<Taskas> taskai;
    ifstream fd(DF);
    int i = 0;
    while (!fd.eof())
    {
        i++;
        Taskas temp;
        fd >> temp.x >> temp.y;
        //cout << i << " iteration and This is x = " << temp.x << " while this is y = " << temp.y<<endl;
        if (!fd.eof()) taskai.push_back(temp);
    }
    fd.close();
    system("del *.txt");
    //sort(taskai.begin(), taskai.end(), compare);
    ofstream fr("Answers/F_" + to_string(F).erase(to_string(F).find_last_not_of('0') + 1, std::string::npos) + "rezultatai.txt");
    for (int i = 0; i < taskai.size(); i++)
    {
        line = to_string(taskai[i].x) + " " + to_string(taskai[i].y) + "\n";
        fr << line;
    }
    fr.close();
    taskai.clear();
}

void delete_root()
{
    system("rmdir /s /q lukosiuno");
}
