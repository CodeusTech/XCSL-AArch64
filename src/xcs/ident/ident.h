/*
  ident.h
  Cody Fagley
  Authored on   February 14, 2019
  Last Modified    March  7, 2019
*/

/*
  Contains Backend Functionality for Identifier Resolution

  Order of Resolution
  ===================
  * Parameter
  * Function
  * Constant


  Table of Contents
  =================
  1.) Identifier Resolution
    1.a) Check for Parameter
    1.b) Check for Function
    1.c) Check for Constant
  2.) Type Inferrence
  3.) Type Checking
*/

#ifndef XCS_IDENT_H
#define XCS_IDENT_H

#include "functions/functions.h"
#include "types/types.h"
#include "typeclass/typeclass.h"

/*
  1.) Identifier Resolution

  Returns:
    0, if Successful
    1, if identifier is not found
*/
ErrorCode resolve_expression(char* ident)
{
  ID_NUMBER rtn;

  //  1.a) Check for Parameter
  rtn = find_parameter(ident);
  if (rtn) { printf("Identifier is Parameter\n"); return 1; }


  //  1.b) Check for Function
  rtn = find_function(ident);
  if (rtn) { return resolve_function(rtn); }


  //  1.c) Check for Constant
  rtn = find_constant(ident);
  if (rtn) { return resolve_constant(rtn); }

  printf("Unable to resolve Identifier: %s\n", ident);
  return 1;
}

/* 2.) Type Inferrence

  Returns:
    0, if UNSUCCESSFUL
    t, if Successful, where 't' is the type code
*/
int infer_type(char* ident)
{

  return 0;
}


/* 3.) Type Checking

  Returns:
    0, if Successful (SUBJECT TO CHANGE)
*/
int check_type(char* ident, unsigned int type)
{

  return 0;
}


#endif
