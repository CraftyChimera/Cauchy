
#define MAXCODE 8192

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
  struct quad *code[MAXCODE];
  unsigned int n;
} intmdt_code_t;

int gen(intmdt_code_t *intermediate_code, char *op, intmdt_addr_t *arg1,
        intmdt_addr_t *arg2, intmdt_addr_t *result);

void print_intmdt_code(intmdt_code_t *code);

void intmdt_addr_print(intmdt_addr_t *t);
