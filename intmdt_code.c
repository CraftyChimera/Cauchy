#include "intmdt_code.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int gen(intmdt_code_t *intermediate_code, char *op, intmdt_addr_t *arg1,
        intmdt_addr_t *arg2, intmdt_addr_t *result)
{
  if (intermediate_code == NULL)
  {
    printf("EHR");
    exit(0);
  }
  struct quad *instr = malloc(sizeof(struct quad));

  if (instr == NULL)
  {
    return 0;
  }
  instr->op = op;
  instr->arg1 = arg1;
  instr->arg2 = arg2;
  instr->result = result;

  if (intermediate_code->n < MAXCODE)
  {
    intermediate_code->code[intermediate_code->n] = instr;
    intermediate_code->n++;
    return 1;
  }
  else
  {
    printf("Error");
    return 0;
  }
}

int new_gen(intmdt_new_code_t *intermediate_code, char *op, intmdt_new_addr_t *arg1,
            intmdt_new_addr_t *arg2, intmdt_new_addr_t *result)
{
  if (intermediate_code == NULL)
  {
    printf("EHR");
    exit(0);
  }
  new_quad *instr = malloc(sizeof(new_quad));

  if (!instr)
  {
    return 0;
  }
  instr->op = op;
  instr->arg1 = arg1;
  instr->arg2 = arg2;
  instr->result = result;

  if (intermediate_code->n < MAXCODE)
  {
    intermediate_code->code[intermediate_code->n] = instr;
    intermediate_code->n++;
    return 1;
  }
  else
  {
    printf("Error");
    return 0;
  }
}

void new_print(intmdt_new_code_t *code)
{
  unsigned int i = 0;
  while (i < code->n)
  {
    char *op = code->code[i]->op;
    // if (strcmp(op, "LOAD") == 0)
    {
      printf("\t\t");
      printf(op);
      printf("\t\t");
      intmdt_new_addr_print(code->code[i]->arg1);
      intmdt_new_addr_print(code->code[i]->arg2);
      intmdt_new_addr_print(code->code[i]->result);
    }
    printf("\n");
    i++;
  }
}

void print_intmdt_code(intmdt_code_t *code)
{
  printf("\nThree Address Code:\n");
  printf("Op\tArg1\t\tArg2\t\tResult\n");
  unsigned int i = 0;
  while (i < code->n)
  {

    printf("%s\t", code->code[i]->op);
    intmdt_addr_print(code->code[i]->arg1);
    intmdt_addr_print(code->code[i]->arg2);
    intmdt_addr_print(code->code[i]->result);
    printf("\n");

    i++;
  }
}

void intmdt_addr_print(intmdt_addr_t *t)
{

  if (t == NULL)
  {
    printf("\t\t");
    return;
  }

  switch (t->type)
  {
  case int_const:
    printf("Integer: %d\t", (t->addr).int_const_ptr);
    break;
  case bool_const:
    printf("Bool: %d\t", (t->addr).bool_const_ptr);
    break;
  }
}

void intmdt_new_addr_print(intmdt_new_addr_t *t)
{
  if (t->is_temp)
  {
    if(t->idx == -1)
    {
      printf("\t\t--\t");
      return;
    }
    printf("\t\t$%d", t->idx);
    return;
  }
  if (t->idx == -1)
  {
    printf("\t\t%d", t->literal);
    return;
  }
  printf("\t\t%c", 'a' + t->idx);
}