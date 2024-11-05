#include <stdio.h>

size_t stringLength ( const char * str );

int stringCompare ( const char * str1 , const char * str2 );

const char * findFirst ( const char * str , char c );

const char * findLast ( const char * str , char c );

int copyString ( char * dst , const char * src , size_t dstSize );

char * duplicateString ( const char * str );

char * concatenateStrings ( const char * str1 , const char * str2 );

char toLowerCase ( char c );

char toUpperCase ( char c );

int startWith ( const char * str , const char * start , int csensitive );

const char * searchString ( const char * haystack , const char * needle , int csensitive );


int main() {
    char str[] = "Hello, World!";
    printf("Length of string: %d\n", stringLength(str));
    printf("Comparison of strings: %d\n", stringCompare("Hello, World!", "Hello, World!"));
    printf("Comparison of strings: %d\n", stringCompare("Hello, World!", "Hello, World"));
    printf("Comparison of strings: %d\n", stringCompare("Hello, World!", "Hello, World!!"));
    printf("The first 'o' in the string is at position: %d\n", findFirst("Hello, World!", 'o'));
    printf("The first 'z' in the string is at position: %d\n", findFirst("Hello, World!", 'z'));
    printf("The last 'o' in the string is at position: %d\n", findLast("Hello, World!", 'o'));
    printf("The last 'z' in the string is at position: %d\n", findLast("Hello, World!", 'z'));
    char dst[6];
    printf("Copying string: %d\n", copyString(dst, "Hello, World!", 6));
    printf("Copied string: %s\n", dst);
    printf("Copying string: %d\n", copyString(dst, "Hello, World!", 13));
    printf("Copied string: %s\n", dst);
    char * dup = duplicateString("Hello, World!");
    printf("Duplicated string: %s\n", dup);
    char * concat = concatenateStrings("Hello, ", "World!");
    printf("Concatenated string: %s\n", concat);
    printf("Lowercase of 'A': %c\n", toLowerCase('A'));
    printf("Lowercase of 'z': %c\n", toLowerCase('z'));
    printf("Uppercase of 'a': %c\n", toUpperCase('a'));
    printf("Uppercase of 'Z': %c\n", toUpperCase('Z'));
    printf("Starts with 'Hello': %d\n", startWith("Hello, World!", "Hello", 1));
    printf("Starts with 'hello': %d\n", startWith("Hello, World!", "hello", 1));
    printf("'Hello' in 'Hello, World!': %s\n", searchString("Hello, World!", "Hello", 1));
    printf("'hello' in 'Hello, World!': %s\n", searchString("Hello, World!", "hello", 1));
    printf("'World' in 'Hello, World!': %s\n", searchString("Hello, World!", "World", 1));
    printf("'world' in 'Hello, World!': %s\n", searchString("Hello, World!", "world", 1));
    return 0;
}

size_t stringLength ( const char * str ) {
    size_t length = 0;
    while ( str[length] != '\0' ) {
        length++;
    }
    return length;
}

int stringCompare ( const char * str1 , const char * str2 ) {
    int i = 0;
    while ( str1[i] != '\0' && str2[i] != '\0' ) {
        if ( str1[i] < str2[i] ) {
            return -1;
        } else if ( str1[i] > str2[i] ) {
            return 1;
        }
        i++;
    }
    if ( str1[i] == '\0' && str2[i] == '\0' ) {
        return 0;
    } else if ( str1[i] == '\0' ) {
        return -1;
    } else {
        return 1;
    }
}

const char * findFirst ( const char * str , char c ) {
    int i = 0;
    while ( str[i] != '\0' ) {
        if ( str[i] == c ) {
            return &str[i];
        }
        i++;
    }
    return NULL;
}

const char * findLast ( const char * str , char c ) {
    int i = 0;
    const char * last = NULL;
    while ( str[i] != '\0' ) {
        if ( str[i] == c ) {
            last = &str[i];
        }
        i++;
    }
    return last;
}

int copyString ( char * dst , const char * src , size_t dstSize ) {
    int i = 0;
    while ( src[i] != '\0' && i < dstSize - 1 ) {
        dst[i] = src[i];
        i++;
    }
    dst[i] = '\0';
    if ( src[i] != '\0' ) {
        return -1;
    } else {
        return 0;
    }
}

char * duplicateString ( const char * str ) {
    size_t length = stringLength(str);
    char * dup = malloc(length + 1);
    copyString(dup, str, length + 1);
    return dup;
}

char * concatenateStrings ( const char * str1 , const char * str2 ) {
    size_t length1 = stringLength(str1);
    size_t length2 = stringLength(str2);
    char * concat = malloc(length1 + length2 + 1);
    copyString(concat, str1, length1 + 1);
    copyString(&concat[length1], str2, length2 + 1);
    return concat;
}

char toLowerCase ( char c ) {
    if ( c >= 'A' && c <= 'Z' ) {
        return c - 'A' + 'a';
    } else {
        return c;
    }
}

char toUpperCase ( char c ) {
    if ( c >= 'a' && c <= 'z' ) {
        return c - 'a' + 'A';
    } else {
        return c;
    }
}

int startWith ( const char * str , const char * start , int csensitive ) {
    int i = 0;
    while ( start[i] != '\0' ) {
        if ( csensitive ) {
            if ( str[i] != start[i] ) {
                return 0;
            }
        } else {
            if ( toLowerCase(str[i]) != toLowerCase(start[i]) ) {
                return 0;
            }
        }
        i++;
    }
    return 1;
}

const char * searchString ( const char * haystack , const char * needle , int csensitive ) {
    size_t length = stringLength(needle);
    int i = 0;
    while ( haystack[i] != '\0' ) {
        if ( startWith(&haystack[i], needle, csensitive) ) {
            return &haystack[i];
        }
        i++;
    }
    return NULL;
}