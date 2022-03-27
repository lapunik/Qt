#include <QCoreApplication>
#include <QTextStream>
#include <QString>

int main()
{
    QTextStream cout (stdout); // dopředu si vytvořím výstupní stream cout (jméno si můžu vybrat jaké chci)

//    QString str = "Nejaka veta. "; // vytvořím libovolný string
//    str.prepend("Pridani textu pred vetu. "); // mohu přidávat ke stringu ze předu
//    str.append("Pridani textu na konec."); // i ze zadu další text

//    cout << str << "\n";
//    cout << "Retezec obsahuje " << str.size() << "znaku.\n";
//    cout << str.toUpper() << "\n"; // obsah proměnné QString je zachovaný, jen výpis je změněn
//    cout << str.toLower() << "\n";

//    cout << str[3] << "\n";
//    cout << str[0] << "\n";

//    int modre = 10;
//    int cervene = 5;

//    QString str2("V nadobe se nachazi %1 modrych a %2 cervenych kulicek.");

//    cout << str2.arg(modre).arg(cervene) << "\n";

//    double desetinne_cislo = 0.05;
//    char znak = '+';

//    cout << str2.arg(desetinne_cislo).arg(znak) << "\n";

//    cout << str.left(4) << "\n"; // ctyři písmena z řetězce z leva
//    cout << str.right(5) << "\n"; // pět písmen z řetězce z prava
//    cout << str.mid(4,8) << "\n"; // písmena od čtvrtého do osmého

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    QString str3 = "Dneska, jsem snedl 10 knedliku.";

//    int mezery = 0;
//    int cisla = 0;
//    int pismena  = 0;
//    int interpunkce = 0;

//    foreach(QChar s, str3) // za prvý je super, že string můžu iterovat ve foreach
//    {
//        if(s.isDigit()) // a za druhý má spoutstu funkcí, jak se zeptat, jestli je danný znak písmeno, číslo, znak, mezera, a mnoh dašího
//        {
//            cisla++;
//        }
//        else if(s.isLetter())
//        {
//            pismena++;
//        }
//        if(s.isSpace())
//        {
//            mezery++;
//        }
//        if(s.isPunct())
//        {
//            interpunkce++;
//        }
//    }

//    cout << "Text obsahuje " << mezery << " mezery, " << cisla << " cisla, " << pismena << " pismen, a " << interpunkce << " interpunkcni znamenka.\n";


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    QString str("Na louce se pase bily kun");

//    foreach(QChar c,str)
//    {
//        cout << c << ", ";
//    }

//    cout << "\n";

//    for(QChar* c = str.begin(); c != str.end();c++)
//    {
//        cout << *c << ", ";
//    }
//    cout << "\n";

//    for(int i = 0;i < str.length();i++)
//    {
//        cout << str.at(i) << ", ";
//    }
//    cout << "\n";

//    for(auto c : str)
//    {
//        cout << c << ", ";
//    }
//    cout << "\n";


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    QString str_1 = "Louka";
//    QString str_2 = "LOUKA";
//    QString str_3 = "Louka";

////    if(!QString::compare(str_1,str_2)) // Neshoda
////    if(!QString::compare(str_1,str_3)) // Shoda
//    if(!QString::compare(str_1,str_2,Qt::CaseInsensitive)) // Shoda
//    {
//        cout << "Shoda" << "\n";
//    }
//    else
//    {
//        cout << "Neshoda" << "\n";
//    }

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    QString str_1 = "258";
//    QString str_2 = "258.6";
//    QString str_3 = "1e6";
//    QString str_4 = "0xE5";
//    QString str_5 = "10011101";


//    bool *is_ok = new bool; // tady bude true/flase, podle toho, jestli se konverze povedla

//    cout << str_1.toInt(is_ok,10) << "\n";
//    cout << str_2.toDouble(is_ok) << "\n";
//    cout << str_3.toDouble(is_ok) << "\n";
//    cout << str_4.toInt(is_ok,16) << "\n"; // DEC: 229
//    cout << str_5.toInt(is_ok,2) << "\n"; // DEC: 157

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    QString str_1, str_2;

//    int num_1 = 16;
//    double num_2 = 16.5;

//    cout << str_1.setNum(num_1) << "\n";
//    cout << str_2.setNum(num_2) << "\n\n";

//    cout << QString::number(num_1) << "\n";
//    cout << QString::number(num_2) << "\n\n";

//    cout << str_1.setNum(num_1,2) << "\n";
//    cout << QString::number(num_1,2) << "\n\n";

//    cout << str_1.setNum(num_1,16) << "\n";
//    cout << QString::number(num_1,16) << "\n\n";

//    cout << str_2.setNum(num_2,'e',10) << "\n"; // formát s e (deset na)
//    cout << str_2.setNum(num_2,'E',10) << "\n"; // formát s velkým E (deset na)
//    cout << str_2.setNum(num_2,'f',10) << "\n"; // normální desetinné číslo
//    cout << str_2.setNum(num_2,'g',10) << "\n"; // sám uváží, kdy se hodí formát s e a kdy normální desetinné číslo
//    cout << str_2.setNum(num_2,'G',10) << "\n"; // sám uváží, kdy se hodí formát s velkým E a kdy normální desetinné číslo

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    QString str;
//    str = "louce";
//    cout << QString("Puvodni retezec: ") << str << "\n";

//    str.append(" kun"); // na konec
//    cout << QString("Po zmene: ") << str << "\n";

//    str.prepend("Na "); // na zacatek
//    cout << QString("Po zmene: ") << str << "\n";

//    str.insert(9,"je "); // na zacatek
//    cout << QString("Po zmene: ") << str << "\n";

//    str.remove(9, 3); // devátý index včetně (indexy od nuly), tři znaky
//    cout << QString("Po dalsi zmene: ") << str << "\n";

//    str.replace(9, 3, "je krava"); // napíu od jakého indexu a kolik znaků chci vymazat a potom se na daný index insertne zadaný text
//    cout << QString("Po dalsi zmene: ") << str << "\n";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    QString str = "text";

//    if (str.isEmpty())
//    {
//        cout << QString("Retezec je prazdny!") << "\n";
//    }
//    else
//    {
//        cout << QString("Retezec neni prazdny!") << "\n";
//    }

//    str = "";

//    if (str.isEmpty())
//    {
//        cout << QString("Retezec je prazdny!") << "\n";
//    }
//    else
//    {
//        cout << QString("Retezec neni prazdny!") << "\n";
//    }


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//    QString jmeno = "Jmeno: ";
//    QString bydliste = "Bydliste: ";
//    QString zamestnani = "Zamestnani: ";

//    int width = zamestnani.length()+ 3;

//    cout << jmeno.leftJustified(width, ' ') << "Vojta" << "\n";
//    cout << bydliste.leftJustified(width, ' ') << "Plzen" << "\n";
//    cout << zamestnani.leftJustified(width, ' ') << "Student" << "\n\n";

//    cout << jmeno.rightJustified(width, ' ') << "Vojta" << "\n";
//    cout << bydliste.rightJustified(width, ' ') << "Plzen" << "\n";
//    cout << zamestnani.rightJustified(width, ' ') << "Student" << "\n\n";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    QVector<int> vec = {1,3,5,4,8};

    for(auto i : vec)
    {
        cout << i << ", ";
    }
    cout << "\n";

    QList<int> list = {1,3,5,4,8};

    while(!list.isEmpty())
    {
        cout << list.front() << ", ";
        list.pop_front();
    }
    cout << "\n";

    QStringList str_list = {"ahoj, nazdar, cus"};

    while(!str_list.isEmpty())
    {
        cout << str_list.front() << ", ";
        str_list.pop_front();
    }
    cout << "\n";

    QMap<QString,int> slovnik = {{"Ahoj",1},{"Cau",2},{"Nazdar",3},};

    cout << slovnik.value("Ahoj") << "\n";
    cout << slovnik.value("Cau") << "\n";
    cout << slovnik.value("Nazdar") << "\n\n";

}
