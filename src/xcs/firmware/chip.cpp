/*
  chip.cpp
  Codeus Tech
  Authored on   July 28, 2021
  Last Modified July 29, 2021
*/

/*
  Contains Extended Implementations for `XitaChip` class functions
*/

#include "chip.h"
#include <xcs/context/manager.h>


/*
  Architecture Metadata
*/
ErrorCode XitaChip::setArchitecture(string target)
{
  if (strcmp("Arm32", target.c_str()) == 0)
  {
    target_architecture = XitaArchitecture::Arm32;
    arch = XitaArchitecture::Arm32;
    register_width = 32;
    l.log('d', "Chip", "Set System for 32-Bit Arm Architecture");
  }
  else if (strcmp("Arm64", target.c_str()) == 0)
  {
    target_architecture = XitaArchitecture::Arm64;
    arch = XitaArchitecture::Arm64;
    register_width = 64;
    l.log('d', "Chip", "Set System for 64-Bit Arm Architecture");
  }
  else if (strcmp("x86_64", target.c_str()) == 0)
  {
    target_architecture = XitaArchitecture::x86_64;
    arch = XitaArchitecture::x86_64;
    register_width = 64;
    l.log('d', "Chip", "Set System for 64-Bit Arm Architecture");
  }
  else
  {
    active_error_code = ERR_UNSUPPORTED_ARCH;
    yyerror("Chip file specifies an unsupported target architecture.\n Acceptable architectures include:  Arm32, Arm64");
    return ERR_UNSUPPORTED_ARCH;
  }

  return SUCCESS;
}


/*
  Firmware Interfaces
*/
ErrorCode XitaChip::newInterface(string name)
{
  interfaces.push_back(FirmwareInterface(name));

  l.log('d', "Chip", "Defined new Firmware Interface: "+name);

  return SUCCESS;
}

FirmwareInterface* XitaChip::getInterface(string name)
{
  for (Index i = 0; i < interfaces.size(); ++i)
    if (name.compare(interfaces[i].Name()) == 0)
      return &interfaces[i];

  return NULL;
}

ErrorCode XitaChip::addInterfaceRange(Address begin, Address end)
{
  //  Check the range doesn't overlap a different interface
  for (Index i = 0; i < interfaces.size(); ++i)
    if (interfaces[i].inRange(begin) || interfaces[i].inRange(end))
    {
      active_error_code = ERR_MEMORY_OVERLAP;
      l.log('c', "Chip", interfaces[i].Name() + " overlaps with other firmware interface memory ranges" );
      yyerror("Chip file defines two firmware interfaces with overlapping memory");
    }

  return interfaces.back().addRange(begin, end);
}
