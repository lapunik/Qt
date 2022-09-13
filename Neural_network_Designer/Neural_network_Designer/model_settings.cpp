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
