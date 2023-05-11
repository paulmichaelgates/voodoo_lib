#define assert(cond, msg) \
    do \
        { \
        if (!(cond)) \
            { \
            fprintf(stderr, "Assertion failed: %s, file %s, line %d\n: %s", #cond, __FILE__, __LINE__, msg); \
            abort(); \
            } \
        } while (0)
        