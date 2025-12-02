#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

static void    unexpected(char c);
static int     accept(char **s, char c);
static int     parse_expr(char **s);
static int     parse_term(char **s);
static int     parse_primary(char **s);

static void unexpected(char c)
{
    if (c == '\0')
    {
        if (printf("Unexpected end of input\n") < 0)
            exit(1);
    }
    else
    {
        if (printf("Unexpected token '%c'\n", c) < 0)
            exit(1);
    }
    exit(1);
}

static int accept(char **s, char c)
{
    if (**s == c)
    {
        (*s)++;
        return (1);
    }
    return (0);
}

/* expr := term { '+' term } */
static int parse_expr(char **s)
{
    int value;
    int right;

    value = parse_term(s);
    while (accept(s, '+'))
    {
        right = parse_term(s);
        value += right;
    }
    return (value);
}

/* term := primary { '*' primary } */
static int parse_term(char **s)
{
    int value;
    int right;

    value = parse_primary(s);
    while (accept(s, '*'))
    {
        right = parse_primary(s);
        value *= right;
    }
    return (value);
}

/* primary := digit | '(' expr ')' */
static int parse_primary(char **s)
{
    int value;

    if (accept(s, '('))
    {
        value = parse_expr(s);
        if (!accept(s, ')'))
            unexpected(**s);  /* ここで '\0' なら end of input 扱い */
        return (value);
    }
    if (**s == '\0')
        unexpected('\0');      /* 何か期待しているのに終端 */
    if (isdigit((unsigned char)**s))
    {
        value = **s - '0';
        (*s)++;
        return (value);
    }
    unexpected(**s);           /* 想定外の文字 */
    return (0);                /* 到達しない */
}

int main(int ac, char **av)
{
    char *s;
    int   result;

    if (ac != 2)
        return (1);
    s = av[1];
    result = parse_expr(&s);
    /* パース終了後に余計な文字が残っていたらエラー */
    if (*s != '\0')
        unexpected(*s ? *s : '\0');
    if (printf("%d\n", result) < 0)
        return (1);            /* syscall failure */
    return (0);
}
