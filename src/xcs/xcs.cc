/*
  xcs.c (AArch64)
  Cody Fagley
  Authored on   January 28, 2019
  Last Modfieid February 13, 2019
*/

/*
	Program Driver for XCS Linux-to-XCS Cross Compiler


	Table of Contents
	=================
	1.) Default Compiler Options
	2.) Handle Compiler Options
	3.) Interpreter Mode
*/

#ifndef XCS_CC
#define XCS_CC

//  Linux Libraries
#include "stdbool.h"
#include "stdio.h"
#include "string.h"
#include "stdlib.h"

//  XCS Libraries
#include <xcs/std/std.h>
#include <xcs/asm/asm.h>

//  Import Grammar Libraries
#include "../../lex.yy.c"

extern FILE* yyin;

/*
	1.) Default Compiler Options
*/
bool interpreted 		= true;	// LIVE INTERPRETER MODE
bool keep_assembly 	= false;

//  Driver File
int main(int argc, char** argv) 
{

	/*
		2.) Handle Compiler Options
	*/
	
	for (int i = 1; i < argc; i++)
	{

	/*
		ASSEMBLY OPTIONS:
			* -a || --keep-assembly
	*/

		//  Keep Assembly Option
		if (strncmp(argv[i], "-a\0", 3) == 0 || strncmp(argv[i], "--keep-assembly", 15) == 0) 
		{
			keep_assembly = true;
		}

	/*
		OPTIMIZATION OPTIONS:
			* -a32i
			* -a32f
			* -a48sr
			* -a64sr
	*/
		//  Optimization Option: a32i
		else if (strcmp(argv[i], "-a32i") == 0) 
		{
			printf("Enabling 32-bit Integer Optimization\n");
			set_optimization(xcs_optimization_scheme::a32i);
		}
		//  Optimization Option: a32f
		else if (strcmp(argv[i], "-a32f") == 0) 
		{
			printf("Enabling 32-bit Floating-Point Optimization\n");
			set_optimization(xcs_optimization_scheme::a32f);
		}
		//  Optimization Option: a48sr
		else if (strcmp(argv[i], "-a48sr") == 0) 
		{
			printf("Enabling 48-Wide Tuple Returns\n");
			set_optimization(xcs_optimization_scheme::a48sr);
		}
		//  Optimization Option: a64sr
		else if (strcmp(argv[i], "-a64sr") == 0) 
		{
			printf("Enabling 64-Wide Tuple Returns\n");
			set_optimization(xcs_optimization_scheme::a64sr);
		}

		//  Assume Input File
		else
		{
			interpreted = false;

			//  Init Module Tree
			modules.push_back(ModuleNode());
			context = &modules[0];

			char* str = (char*) malloc(50);
			sprintf(str, " ");

			add_function(str);
			
			yyin = fopen(argv[i], "r");
			yypush_buffer_state(yy_create_buffer(yyin, YY_BUF_SIZE));

			//  Set Parser File Pointer
			//yypush_buffer_state(YY_CURRENT_BUFFER);
			while(!feof(yyin)) yyparse();

			//  Create Assembly File
			char* asm_fname = (char*) malloc(strlen(argv[i])+3);
			asm_fname[strlen(argv[i])] = 0;
			strncpy(asm_fname, argv[i], strlen(argv[i]));
			strncat(asm_fname, ".s", 3);


			//  Populate Assembly File
			write_asm_file(asm_fname);

			free (asm_fname);

			return 0;
		}
	}


	/*
		3.) Interpreter Mode
	*/
	if (interpreted) yyin = stdin;
	//  Initialize Register Stack Backend

	while (!feof(yyin)) yyparse();

	return 0;
}

#endif
