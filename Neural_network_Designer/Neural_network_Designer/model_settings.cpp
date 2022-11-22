#include "model_settings.h"

Model_settings::Model_settings()
{

}

Model_settings::algorithm Model_settings::string_to_algorithm(QString al)
{

    if(al == QString("ADAM"))
    {
        return ADAM;
    }
    else if(al == QString("Moment"))
    {
        return moment;
    }
    else if(al == QString("None"))
    {
        return none;
    }
    else
    {
        return none;
    }

}

QString Model_settings::algorithm_to_string(algorithm al)
{

    switch (al)
    {
    case ADAM:
        return "ADAM";
    case moment:
        return "Moment";
    case none:
        return "None";
    default:
        return "None";

    }

}

int Model_settings::algorithm_to_index(algorithm al)
{
    return al;
}

int Model_settings::regularization_to_index(regularization reg)
{
    return reg;
}


Model_settings::regularization Model_settings::string_to_regularization(QString al)
{

    if(al == QString("lasso"))
    {
        return lasso;
    }
    else
    {
        return nothing;
    }

}

QString Model_settings::regularization_to_string(regularization reg)
{

    switch (reg)
    {
    case lasso:
        return "lasso";
    default:
        return "None";

    }

}
