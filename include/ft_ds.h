#ifndef FT_DS_H
# define FT_DS_H

enum e_adjut {LEFT, RIGHT};

typedef struct s_flags {
    int             alternate_form;
    int             filler;
    enum e_adjut    adjustement;
    int             force_space;
    int             force_sign;
}   t_flags;

typedef struct s_format {
    t_flags flags;
    int width;
    int precision;
    int lenght_modifier;
    char specifier;
}   t_format;

#endif
