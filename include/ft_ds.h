#ifndef FT_DS_H
# define FT_DS_H

enum e_adjut {LEFT, RIGHT};

# define ALTERNATE_FORM 0b00001
# define FILLZERO       0b00010
# define ADJUSTLEFT     0b00100
# define FORCE_SPACE    0b01000
# define FORCE_SIGN     0b10000

typedef struct s_format {
    unsigned short flags;
    int width;
    int precision;
    int lenght_modifier;
    char specifier;
}   t_format;

#endif
