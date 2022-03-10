struct foo_consumer {
    int (*handler)(struct foo_consumer *self, void *);
    struct foo_consumer *next;
};

struct foo {
    struct foo_consumer *consumers;
    unsigned long flags;
};

#include <stdbool.h>

/*
 * For foo @foo, delete the consumer @fc.
 * Return true if the @fc is deleted sfccessfully
 * or return false.
 */
static bool consumer_del(struct foo *foo, struct foo_consumer *fc)
{
    struct foo_consumer **con;
    bool ret = false;

    for (con = &foo->consumers; *con; con = &(*con)->next) {
        if (*con == fc) {
            *con = fc->next;
            ret = true;
            break;
        }
    }

    return ret;
}

int main()
{
    return 0;
}