/***
This is a derivative work of ADMS.  Original code is copyight the original authors.
Modifications Copyright Luther T. Cat

ADMS
Copyright (C) 2015  Luther T. Cat
Original code copyright the original authors.

This file is part of ADMS.

ADMS is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, version 2 of the License.

ADMS is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with ADMS.  If not, see <http://www.gnu.org/licenses/>.
***/

#include "adms_source.h"

int adms_source_cmp (p_source mysource,p_source refsource)
{
  return
  (
    (mysource->_module != refsource->_module)
    ||
    (mysource->_branch != refsource->_branch)
    ||
    (mysource->_nature != refsource->_nature)
  );
}

p_source adms_source_new (p_module mymodule,p_branch mybranch,p_nature mynature)
{
  p_source mynewsource = new s_source(mymodule, mybranch, mynature);
  return mynewsource;
}

std::string s_source::get_uid_implemented()
{
  std::string myuid=_nature->get_uid();
  myuid += "(";
  myuid += _branch->get_uid();
  myuid += ")";
  return myuid;
}

void s_source::get_reference_list_implemented(references_list_t &rlist)
{
  rlist = {
    mytup1{"module", create_adms_list(_module)},
    mytup1{"branch", create_adms_list(_branch)},
    mytup1{"nature", create_adms_list(_nature)},
    mytup1{"discipline", create_adms_list(_discipline)},
  };
  push_back_mytup1(rlist, "probe", _probe);
}

void s_source::get_attribute_list_implemented(attributes_list_t &alist)
{
  push_back_attributes(alist, _attribute);
}

void s_source::get_string_list_implemented(strings_list_t &slist)
{
}

