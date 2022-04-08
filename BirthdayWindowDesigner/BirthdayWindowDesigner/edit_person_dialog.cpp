#include "edit_person_dialog.h"

Edit_person_dialog::Edit_person_dialog(Person_model *model,QWidget *parent): QDialog(parent)
{
    mp_person_model = model;

    mp_main_layout = new QVBoxLayout(this);
    mp_sublayout = new QHBoxLayout();
    mp_buttons_layout = new QHBoxLayout();
    mp_form_layout = new QFormLayout();

    mp_main_layout->addLayout(mp_sublayout);

    mp_name_edit = new QLineEdit(this);
    mp_surname_edit = new QLineEdit(this);
    mp_day_edit = new QLineEdit(this);
    mp_month_edit = new QLineEdit(this);
    mp_year_edit = new QLineEdit(this);

    mp_form_layout->addRow(tr("Jméno :"), mp_name_edit);
    mp_form_layout->addRow(tr("Příjmení :"), mp_surname_edit);
    mp_form_layout->addRow(tr("Den narození :"), mp_day_edit);
    mp_form_layout->addRow(tr("Měsíc :"), mp_month_edit);
    mp_form_layout->addRow(tr("Rok :"), mp_year_edit);

    mp_id_label = new QLabel("");
    mp_form_layout->addRow(tr("Id :"), mp_id_label);

    mp_list_view = new QListView(this);
    mp_sublayout->addWidget(mp_list_view);

    mp_sublayout->addLayout(mp_form_layout);

    mp_main_layout->addLayout(mp_buttons_layout);

    mp_button_save = new QPushButton(tr("Uložit"), this);
    mp_button_exit = new QPushButton(tr("Konec"), this);
    mp_button_delete = new QPushButton(tr("Odtranit"));

    mp_buttons_layout->addWidget(mp_button_delete);
    mp_buttons_layout->addWidget(mp_button_exit);
    mp_buttons_layout->addWidget(mp_button_save);

    setLayout(mp_main_layout);

    mp_string_list = new QStringList();

    mp_person_model->find_all_names(mp_string_list); // Všechna jména si z modelu načteme do tohoto seznamu

    mp_string_list_model = new QStringListModel(*mp_string_list, this);     // Model pro listView naplníme daty

    mp_string_list_model->sort(0); // A budeme je řadit podle abecedy - index nula značí, že podle prvního sloupce v listView

    mp_list_view->setModel(mp_string_list_model); // Tento model přiřadíme našemu listView

    connect(mp_button_delete, SIGNAL(clicked()), this, SLOT(on_delete_button_clicked()));
    connect(mp_button_exit, SIGNAL(clicked()), this, SLOT(on_exit_button_clicked()));
    connect(mp_button_save, SIGNAL(clicked()), this, SLOT(on_save_button_clicked()));
    connect(mp_list_view, SIGNAL(clicked(const QModelIndex)), this, SLOT(on_list_view_clicked(const QModelIndex))); // kliknutím do seznamu lidí se vygeneruje událost a jako vstupní argument bude obsahovat index osoby

}

Edit_person_dialog::~Edit_person_dialog()
{

if (mp_button_exit != nullptr)
{
    delete mp_button_exit;
}
if (mp_button_save != nullptr)
{
    delete mp_button_save;
}
if (mp_button_delete != nullptr)
{
    delete mp_button_delete;
}
if (mp_year_edit != nullptr)
{
    delete mp_year_edit;
}
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
if (mp_buttons_layout != nullptr)
{
    delete mp_buttons_layout;
}
if (mp_sublayout != nullptr)
{
    delete mp_sublayout;
}
if (mp_main_layout != nullptr)
{
    delete mp_main_layout;
}

if (mp_list_view != nullptr)
{
    delete mp_list_view;
}
if (mp_string_list!= nullptr)
{
    delete mp_string_list;
}
if (mp_string_list_model != nullptr)
{
    delete mp_string_list_model;
}
if (mp_id_label != nullptr)
{
    delete mp_id_label;
}

}

void Edit_person_dialog::on_list_view_clicked(const QModelIndex &index)
{
    mp_model_index = index;

    QString name = mp_string_list_model->data(mp_model_index).toString();

    // ID osoby je zakomponováno přímo do jména, pro snadnější vyhledávání. Šlo by to řešit i více-sloupcovým seznamem, ale to by vyžadovalo výrazně náročnější postupy jak zobrazit potřebná data
    int id_begin = name.indexOf('|') + 1;     // ID je uloženo tímto způsobem: příjmení jméno |id|
    int id_end = name.lastIndexOf('|');
    int id = name.mid(id_begin, id_end-id_begin).toInt();

    mp_person_model->find_by_id(id, &mp_person);

    mp_id_label->setText(QString::number(mp_person.get_id()));
    mp_name_edit->setText(mp_person.get_name());
    mp_surname_edit->setText(mp_person.get_surname());

    QDate date = mp_person.get_birthday();

    mp_day_edit->setText(QString::number(date.day()));
    mp_month_edit->setText(QString::number(date.month()));
    mp_year_edit->setText(QString::number(date.year()));
}

void Edit_person_dialog::on_exit_button_clicked()
{
    if (QMessageBox::warning(this,tr("Zavřít dialog?"),tr("Pokud jste provedli nějaké změny a neuložili je, budou ztraceny!!!\nOpravdu zavřít toto okno?"),QMessageBox::Yes | QMessageBox::No) == QMessageBox::No)
    {
        return;
    }

    close();
}

void Edit_person_dialog::on_delete_button_clicked()
{
    if (QMessageBox::warning(this,
        tr("Vymazat osobu"),
        tr("Jste si jistí, že zvolenou osobu chcete opravdu smazat?"),
        QMessageBox::Yes | QMessageBox::No) == QMessageBox::No) {
        return;
    }

    mp_person_model->delete_person(mp_person.get_id());

    mp_string_list_model->removeRow(mp_model_index.row());
    mp_list_view->update();
}

void Edit_person_dialog::on_save_button_clicked()
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

    mp_person.set_name(mp_name_edit->text());
    mp_person.set_surname(mp_surname_edit->text());
    mp_person.set_birthday(date);

    // Zde si jen uděláme změněný záznam do modelu, pro listView
    mp_person_model->save_person(mp_person.get_id(), mp_person);
    mp_string_list_model->setData(mp_model_index, QVariant(QString("%1 %2 |%3|").arg(mp_person.get_surname()).arg(mp_person.get_name()).arg(QString::number(mp_person.get_id()))));
    mp_list_view->update();

    msg.information(this, tr("Hotovo"), tr("Osoba byla úspěšně přidána do seznamu."));
}
