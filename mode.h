#if !defined(_H_MODE)
#define _H_MODE

typedef enum _MODE MODE;
typedef enum _STATE STATE;

enum _MODE {
    NORMAL,
    INSERT
};

enum _STATE {
    COMMAND,
    SEARCH,
    NONE
};

#endif // _H_MODE
