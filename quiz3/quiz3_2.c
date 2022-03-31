#include <stdlib.h>

struct foo;
  
struct fd {
    struct foo *foo;
    unsigned int flags;
};

enum {
    FOO_DEFAULT = 0,
    FOO_ACTION,                           
    FOO_UNLOCK,
} FOO_FLAGS;

static inline struct fd to_fd(unsigned long v)
{
    return (struct fd){(struct foo *)(v & ~3), v & 3};
}