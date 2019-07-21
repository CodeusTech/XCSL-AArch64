/*
  text.h
  Cody Fagley
  Authored on   February 13, 2019
  Last Modified     July 21, 2019
*/

/*
  .text Section Contains Executable Code

  Table of Contents
  =================
  1.) Structure
    1.a) Generate Text
  2.) Operations
    2.a) Add Command
    2.b) Read Command
*/

#ifndef ASM_TEXT_H
#define ASM_TEXT_H

extern Command* curr_asm_text;
extern unsigned long long* count_asm_text;
extern Scope scope_next;

/*
  1.) Structure
*/

/* 1.a) Generate Text

  Returns:
    0, if Successful
*/
ErrorCode generate_text(FILE* filename)
{
  //  Print TEXT Segment Name into File
  fprintf(filename, ".section .text:\n\n");

  fprintf(filename, "__start:\n");

  for (int scope = 0; scope < scope_next; scope++)
  {
    if (scope == 255)
    {
      void* index_asm_text = (unsigned long long*) count_asm_text[255];
      free(count_asm_text);
      count_asm_text = index_asm_text;
      scope = 0;

      scope_next -= 255;
    }
    curr_asm_text = start_asm_text[scope];

    /* Print TEXT Buffer Contents to File */
    for (int comm = 0; comm < count_asm_text[scope]; comm++)
    {
      if (comm == 255) 
      {
        curr_asm_text = (Command*) start_asm_text[scope][comm];
        free(start_asm_text[scope]);
        comm = 0;
        count_asm_text[scope] -= 255;
      }
      fprintf(filename, "  %s\n", curr_asm_text[comm]);
      free(curr_asm_text[comm]);
  
    }

    free(curr_asm_text);
  }

  //  Pretty up file with new lines
  free(start_asm_text);

  fprintf(filename, "\n\n");

  //  Report Success to Terminal
  printf(".text Section Generated\n");

  //  Return Success
  return 0;
}


/*
  2.) Operations
*/

/* 2.a) Add Command
  
    Returns:
      0, if Successful
*/
ErrorCode add_command(Command command)
{
  if (count_asm_text[scope_curr] == 255)
  {
    curr_asm_text[255] = (Command*) malloc(256 * sizeof(Command));
    curr_asm_text = (Command*) curr_asm_text[255];

    count_asm_text[scope_curr] = 0;
  }

  curr_asm_text[count_asm_text[scope_curr]] = strdup(command);

  count_asm_text[scope_curr]++;

  return 0;
}


Command get_last_command()
{
  return curr_asm_text[--count_asm_text[scope_curr]];
}


ErrorCode end_scope()
{
  curr_reg = 0; 
  scope_curr = 0;
  last_type = 0;
  curr_asm_text = start_asm_text[0];

  return 0;
}

#endif
