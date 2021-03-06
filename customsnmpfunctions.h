#ifndef CUSTOMSNMPFUNCTIONS_H
#define CUSTOMSNMPFUNCTIONS_H

#include "stdafx.h"

inline bool IsValidSnmpValue(netsnmp_variable_list* vars)
{
    return (vars->type != SNMP_ENDOFMIBVIEW)
            && (vars->type != SNMP_NOSUCHINSTANCE)
            && (vars->type != SNMP_NOSUCHOBJECT);
}

#endif // CUSTOMSNMPFUNCTIONS_H
