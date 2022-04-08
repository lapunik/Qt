#include "new_person_dialog.h"
#include <QMessageBox>

New_person_dialog::New_person_dialog(Person_model *model, QWidget *parent) : QDialog (parent)
{
    mp_model = model;                           // Ukazatel na model si uložíme

    setWindowTitle("Nová osoba");               // Dialogu nastavíme titulek

    mp_main_layout = new QVBoxLayout(this);      // Pouze hlavní layout může mít rodiče
    mp_sub_layout = new QHBoxLayout();           // ...this by zde již bylo warning
    mp_calendar_layout = new QVBoxLayout();
    mp_button_layout = new QHBoxLayout();
    mp_form_layout = new QFormLayout();

    mp_main_layout->addLayout(mp_sub_layout);     // Do vertikálního boxu si rovnou uložíme ještě jeden horizontální

    mp_name_edit = new QLineEdit(this);
    mp_surname_edit = new QLineEdit(this);
    mp_day_edit = new QLineEdit(this);
    mp_month_edit = new QLineEdit(this);
    mp_year_edit = new QLineEdit(this);

    // Vytvoříme jednotlivé řádky editačního formuláře
    mp_form_layout->addRow(tr("Jméno :"), mp_name_edit);
    mp_form_layout->addRow(tr("Příjmení :"), mp_surname_edit);
    mp_form_layout->addRow(tr("Den narození :"), mp_day_edit);
    mp_form_layout->addRow(tr("Měsíc :"), mp_month_edit);
    mp_form_layout->addRow(tr("Rok :"), mp_year_edit);

    mp_sub_layout->addLayout(mp_form_layout);     // Formulář vložíme do horizontálního boxu
    mp_sub_layout->addLayout(mp_calendar_layout); // A když jsme u toho, tak přihodíme další vertikální box, kde budou kalendáře

    mp_calendar_edit = new QCalendarWidget(this);
    mp_date_edit = new QDateEdit(this);

    mp_calendar_layout->addWidget(mp_calendar_edit);     // Kalendář dáme do layoutu pro kalendáře :-)
    mp_calendar_layout->addWidget(mp_date_edit);  // a stejně tak políčko pro datum

    mp_main_layout->addLayout(mp_button_layout);     // Ještě nám zbývají tlačítka, tak do hlavního layoutu přidáme jeden pro ně

    mp_button_ok = new QPushButton(tr("OK"), this);
    mp_button_cancel = new QPushButton(tr("Konec"), this);

    // a vložíme je do posledního horizontálního boxu
    mp_button_layout->addWidget(mp_button_cancel);
    mp_button_layout->addWidget(mp_button_ok);

    // Teď již jen nastavit dialogu, který layout má použít
    setLayout(mp_main_layout);

    QDate currentDate = mp_calendar_edit->selectedDate(); // datum je nastaven z kalendáře a podle něj je nastaven zbytek datumových prvků
    mp_date_edit->setDate(currentDate);
    mp_day_edit->setText(QString::number(currentDate.day()));
    mp_month_edit->setText(QString::number(currentDate.month()));
    mp_year_edit->setText(QString::number(currentDate.year()));

    connect(mp_calendar_edit, SIGNAL(selectionChanged()), this, SLOT(on_calendar_selection_changed()));
    connect(mp_date_edit, SIGNAL(dateChanged(const QDate&)), this, SLOT(on_date_edit_changed(const QDate&))); // vidíme že signály i sloty mohou mít atributy. Pozor ale na zápis, píše se jen typ, nikoiv název!
    connect(mp_day_edit, SIGNAL(textChanged(const QString&)), this, SLOT(on_day_edit_changed(const QString&)));
    connect(mp_month_edit, SIGNAL(textChanged(const QString&)), this, SLOT(on_month_edit_changed(const QString&)));
    connect(mp_year_edit, SIGNAL(textChanged(const QString&)), this, SLOT(on_year_edit_changed(const QString&)));

    connect(mp_button_ok, SIGNAL(clicked()), this, SLOT(on_button_ok_clicked()));
    connect(mp_button_cancel, SIGNAL(clicked()), this, SLOT(on_button_cancel_clicked()));

}

New_person_dialog::~New_person_dialog()
{
    if (mp_button_cancel != nullptr)
    {
        delete mp_button_cancel;
    }
    if (mp_button_ok != nullptr)
    {
        delete mp_button_ok;
    }
    if (mp_date_edit != nullptr)
    {
        delete mp_date_edit;
    }
    if (mp_calendar_edit != nullptr)
    {
        delete mp_calendar_edit;
    }
    if (mp_year_edit != nullptr)
    {
        delete mp_year_edit;}
    if (mp_month_edit != nullptr)
    {
        delete mp_month_edit;
    }
    if (mp_day_edit != nullptr)
    {
        delete mp_day_edit;
    }
    if (mp_surname_edit != nullptr)
    {
        delete mp_surname_edit;
    }
    if (mp_name_edit != nullptr)
    {
        delete mp_name_edit;
    }
    if (mp_form_layout != nullptr)
    {
        delete mp_form_layout;
    }
    if (mp_button_layout != nullptr)
    {
        delete mp_button_layout;
    }
    if (mp_sub_layout != nullptr)
    {
        delete mp_sub_layout;
    }
    if (mp_main_layout != nullptr)
    {
        delete mp_main_layout;
    }
}


void New_person_dialog::on_calendar_selection_changed()
{
    mp_date_edit->setDate(mp_calendar_edit->selectedDate());
    mp_day_edit->setText(QString::number(mp_calendar_edit->selectedDate().day()));
    mp_month_edit->setText(QString::number(mp_calendar_edit->selectedDate().month()));
    mp_year_edit->setText(QString::number(mp_calendar_edit->selectedDate().year()));
}

void New_person_dialog::on_date_edit_changed(const QDate &date)
{
    mp_calendar_edit->setSelectedDate(date);
}

void New_person_dialog::on_day_edit_changed(const QString &day)
{
    QDate date = mp_date_edit->date();
    date = QDate(date.year(), date.month(), day.toInt());
    mp_date_edit->setDate(date);
}

void New_person_dialog::on_month_edit_changed(const QString &month)
{
    QDate date = mp_date_edit->date();
    date = QDate(date.year(), month.toInt(), date.day());
    mp_date_edit->setDate(date);
}

void New_person_dialog::on_year_edit_changed(const QString &year)
{
    QDate date = mp_date_edit->date();
    date = QDate(year.toInt(), date.month(), date.day());
    mp_date_edit->setDate(date);
}

void New_person_dialog::on_button_cancel_clicked()
{
        this->close();
}

void New_person_dialog::on_button_ok_clicked()
{
    QMessageBox msg;

    if (mp_name_edit->text().isEmpty())
    {
        msg.warning(this, tr("Chyba"), tr("Jméno nelze nechat nevyplněné."));
        return;
    }

    if (mp_surname_edit->text().isEmpty())
    {
        msg.warning(this, tr("Chyba"), tr("Příjmení nelze nechat nevyplněné."));
        return;
    }

    bool isOk = true;
    int day = mp_day_edit->text().toInt(&isOk);
    int month = mp_month_edit->text().toInt(&isOk);
    int year = mp_year_edit->text().toInt(&isOk);

    if (!isOk)
    {
        msg.warning(this, tr("Chyba"), tr("Neplatné znaky v editačním okně datumu."));
        return;
    }

    QDate date = QDate(year, month, day);

    if (!date.isValid() || !isOk)
    {
        msg.warning(this, tr("Chyba"), tr("Datum je zadané chybně."));
        return;
    }


    Person person;
    person.set_name(mp_name_edit->text());
    person.set_surname(mp_surname_edit->text());
    person.set_birthday(date);

    mp_model->add_person(person);

    this->close();
    msg.information(this, tr("Hotovo"), tr("Osoba byla úspěšně přidána do seznamu."));
}
