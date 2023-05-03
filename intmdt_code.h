
#define MAXCODE 8192
#include <stdbool.h>

typedef struct {
  enum { symbol, int_const, bool_const } type;

  union {
    int int_const_ptr;
    int bool_const_ptr;
  } addr;
} intmdt_addr_t;

struct quad {
  char *op;
  intmdt_addr_t *arg1;
  intmdt_addr_t *arg2;
  intmdt_addr_t *result;
};

typedef struct {
  bool is_temp;
  bool is_label;
  int idx;
  int literal;
} intmdt_new_addr_t;

typedef struct {
  char* op;
  intmdt_new_addr_t *arg1;
  intmdt_new_addr_t *arg2;
  intmdt_new_addr_t *result;
} new_quad;

typedef struct {
  new_quad *code[MAXCODE];
  unsigned int n;
} intmdt_new_code_t;


typedef struct {
  struct quad *code[MAXCODE];
  unsigned int n;
} intmdt_code_t;

int gen(intmdt_code_t *intermediate_code, char *op, intmdt_addr_t *arg1,
        intmdt_addr_t *arg2, intmdt_addr_t *result);

int new_gen(intmdt_new_code_t *intermediate_code, char *op, intmdt_new_addr_t *arg1,
        intmdt_new_addr_t *arg2, intmdt_new_addr_t *result);

int* new_print(intmdt_new_code_t* code);

void intmdt_new_addr_print(intmdt_new_addr_t* t);

void print_intmdt_code(intmdt_code_t *code);

void intmdt_addr_print(intmdt_addr_t *t);
