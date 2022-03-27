#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QString>

class Model : public QObject
{
    Q_OBJECT
public:
    explicit Model(QObject *parent = nullptr); // při vytváření jsme dali Base class jako QObject a Qt nám vygenerovalo šablonu včetně tohto příkazu

    enum operation // výčet prvků představující matematické operace
    {
       add,
       sub,
       mlp,
       div,
    };
    enum number_basis // výčet prvků představující číselnou soustavu
    {
       dec,
       bin,
       hex,
       oct,
    };
    enum number // výčet odkazujícíc na první nebo druhé číslo (vlastnost tohoto typu bude využita pro chybový signál, který v tomto typu bude určovat, které z čísel bylo chybně zadáno)
    {
       first,
       second,
    };

private:

    int first_num; // první číslo
    int second_num; // druhé číslo

    operation op; // operacce
    number_basis nb; // číselná soustava

    bool is_first_ok;
    bool is_second_ok;

public:

    void set_first(QString value); // funkce pro nastavení prvního čísla
    void set_second(QString value); // funkce pro nastavení druhého čísla
    void set_operation(operation value); // funkce pro nastavení operace
    void set_num_basis(number_basis value); // funkce pro nastavení číslené soustavy
    int calculate();

private:

    int number_test(QString number, bool *isOk); // funkce pro kontrolu uživatelského vstupu

signals: // následující funkce budou sloužit jako uživatelské signály, proto toto uvození.
         // v podstatě toto uvození dělá totéž jako public. Jedná se tedy o funkce, které budeme moci propojit s určitými sloty.

    void number_false(Model::number value); // signál (funkce) pro chybu v zadávání hodnoty (vstupní argument obsahuje informaci, které z čísel je chybně zadáno)
    void zero_divide(); // signál (funkce) pro chybu z důvodu pokusu dělení nulou

public slots: // tady pro změnu připravíme sloty (funkce) pro přijímání signálů, kterých bude potřeba přijímat spousta (klikání na jednotlivé prvky aplikace atd..)

};

#endif // MODEL_H
