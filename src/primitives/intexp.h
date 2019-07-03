/*
  int.h
  Cody Fagley
  Authored on   February 16, 2019
  Last Modified February 16, 2019
*/

/*
  Contains primitive integer expressions

  Definitions
  ===========
  TOP:  Top register on XCS REGISTER STACK
  NEXT: Next register from the top on XCS REGISTER STACK

  
  Table of Contents
  =================
  1.) Integer Literals
    1.a) Pop Integer
    1.b) Push Integer Literal
      1.b.1) Push Unsigned 8-Bit Integer
      1.b.2) Push Unsigned 16-Bit Integer
      1.b.3) Push Unsigned 32-Bit Integer
      1.b.4) Push Unsigned 64-Bit Integer
      1.b.5) Push Signed 8-Bit Integer
      1.b.6) Push Signed 16-Bit Integer
      1.b.7) Push Signed 32-Bit Integer
      1.b.8) Push Signed 64-Bit Integer
    1.c) Push Integer Identifier
  2.) Integer Arithmetic
    2.a) Integer Addition
    2.b) Integer Subtraction
    2.c) Integer Multiplication
    2.d) Integer Division
    2.e) Integer Modulus
  3.) Bitwise Arithmetic
    3.a) Bitwise Shift Left
    3.b) Bitwise Shift Right
    3.c) Bitwise And
    3.d) Bitwise Or
    3.e) Bitwise Xor
*/

#ifndef PRIMITIVES_INTEXP_H
#define PRIMITIVES_INTEXP_H

//  XCS Libraries
#include "typecodes.h"
#include "../grammar/status.h"
#include "../regstack/regstack.h"
#include "../globals/structs.h"


extern unsigned int grammar_status;

/*
  1.) Integer Literals
*/

/* 1.a) Pop Integer

  Returns:
    0, if Successful
*/
int pop_int()
{
  //  STUB STUB STUB
  printf("Integer Popped from Register Stack\n");
  rs_pop();

  return 0;
}

/* 1.b) Push Integer Literals

  Puts integer [lit] into current scope's register stack
  Puts integer TypeID into current scope's register stack

  Returns:
    0, if Successful
*/
int push_int(int lit)
{
  //  STUB STUB STUB
  printf("Integer Literal Pushed to Register Stack: %d\n", lit);

  //  Put Integer Literal on Top of Register Stack
  rs[scope_curr][rs_top()] = lit;

  //  Map Integer Literal Type to Top of Register Stack
  rs_types[scope_curr][rs_top()] = TYPE_INTEGER;

  printf("check\n");
  //  Create ARM Assembly Command
  char* str = (char*) malloc(50);
  sprintf(str, "mov  %s, %d\n", get_reg(rs_top(), 32), lit);

  //  Add to Queue for File Printing
  add_command(str);

  //  Free allocated memory and move to next register on stack
  free(str);
  ADR reg = rs_push();

  return 0;
}

/* 1.b.1) Push Unsigned 8-Bit Integer

*/



/* 1.c) Push Integer Identifier

  Returns:
    0, if Successful
    1, if Identifier is not an Integer
*/
int push_int_ident(char* ident)
{
  //  STUB STUB STUB
  printf("Integer Identifier Pushed to Register Stack: %s\n", ident);
  ADR reg = rs_push();
  

  switch (find_type(ident))
  {
    case TYPE_INTEGER:
      //  Handle Integer
      break;
    case TYPE_U8:
      //  Handle U8
      break;
    case TYPE_I8:
      //  Handle I8
      break;
    case TYPE_U16:
      //  Handle U16
      break;
    case TYPE_I16:
      //  Handle I16
      break;
    case TYPE_U32:
      //  Handle U32
      break;
    case TYPE_I32:
      //  Handle I32
      break;
    case TYPE_U64:
      //  Handle U64
      break;
    case TYPE_I64:
      //  Handle I64
      break;
    default:
      //  Not an Integer -- Throw Error
      //  TODO: Replace with yyerror()
      grammar_status = GRAMMAR_ERROR_TYPECHECK;
      return 1;
  }

  return 0;
}


/*
  2.) Integer Arithmetic
*/

/* 2.a) Integer Addition
  Adds TOP to NEXT register; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_addition()
{
  printf("Added top two registers on REGISTER STACK\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Addition
  ADR rhs = rs_top();
  ADR lhs = rs_second();

  //  After Addition, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

/* 2.b) Integer Subtraction
  Subtracts TOP from NEXT register; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_subtraction()
{
  printf("Subtracted top two registers on REGISTER STACK\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Subtraction
  ADR rhs = rs_top();
  ADR lhs = rs_second();

  //  After Subtraction, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

/* 2.c) Integer Multiplication
  Multiplies TOP and NEXT register; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_multiplication()
{
  printf("Multiplied top two registers on REGISTER STACK\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Multiplication
  ADR rhs = rs_top();
  ADR lhs = rs_second();

  //  After Multiplication, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

/* 2.d) Integer Division
  Divides TOP from NEXT register; NEXT holds quotient; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_division()
{
  printf("Divided top two registers on REGISTER STACK\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Division
  ADR rhs = rs_top();
  ADR lhs = rs_second();

  //  After Division, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

/* 2.e) Integer Modulus
  Divides TOP from NEXT register; NEXT holds remainder; TOP is deactivated

  Returns:
    0, if Successful
*/
int integer_modulus()
{
  printf("Modulus'd top two registers on REGISTER STACK\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Modulus
  ADR rhs = rs_top();     //  Must be Integer Type
  ADR lhs = rs_second();  //  Must be Integer Type

  //  After Modulus, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

/*
  3.) Bitwise Arithmetic
*/

/* 3.a) Bitwise Shift Left
  Shifts NEXT register's bits left by TOP places

  Returns:
    1, if Succcessful
*/
int bitwise_shl()
{
  printf("Bitwise Shift Left\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Bitwise Shift
  ADR rhs = rs_top();
  ADR lhs = rs_second();

  //  After Bitwise Shift, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

/* 3.b) Bitwise Shift Right
  Shifts NEXT register's bits right by TOP places

  Returns:
    0, if Successful
*/
int bitwise_shr()
{
  printf("Bitwise Shift Right\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Bitwise Shift
  ADR rhs = rs_top();
  ADR lhs = rs_second();

  //  After Bitwise Shift, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

/* 3.c) Bitwise And
  Performs bitwise and from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int bitwise_and()
{
  printf("Bitwise And\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Bitwise AND
  ADR rhs = rs_top();
  ADR lhs = rs_second();

  //  After Bitwise AND, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

/* 3.d) Bitwise Or
  Performs bitwise or from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int bitwise_or()
{
  printf("Bitwise Or\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Bitwise OR
  ADR rhs = rs_top();
  ADR lhs = rs_second();

  //  After Bitwise OR, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

/* 3.e) Bitwise Xor
  Performs bitwise exclusive or from TOP to NEXT; NEXT stores result

  Returns:
    0, if Successful
*/
int bitwise_xor()
{
  printf("Bitwise Exclusive Or\n");

  /*
    Error Check for Type Definition:
    (int) -> (int) -> (int)
  */

  //  Perform Bitwise XOR
  ADR rhs = rs_top();
  ADR lhs = rs_second();

  //  After Bitwise XOR, Pop Entry from Register Stack
  rs_pop();

  return 0;
}

#endif