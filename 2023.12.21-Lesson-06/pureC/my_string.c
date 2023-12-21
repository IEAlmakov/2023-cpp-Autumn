#include <stdio.h>
#include <stdlib.h>

char* my_strcat(char* dest, const char* src)
{
    char* ptr = dest;

    while (*ptr != '\0')
    {
        ptr++;
    }

    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0';

    return dest;
}

char* my_strstr(const char* haystack, const char* needle)
{
    if (*needle == '\0')
    {
        return (char*) haystack;
    }

    const char* p1 = haystack;
    while (*p1 != '\0')
    {
        const char* p1_begin = p1;
        const char* p2 = needle;

        while ((*p1 != '\0') && (*p2 != '\0') && (*p1 == *p2))
        {
            p1++;
            p2++;
        }

        if (*p2 == '\0')
        {
            return (char*) p1_begin;
        }

        p1 = p1_begin + 1;
    }

    return NULL;
}

char* my_substr(const char* str, int start, int length)
{
    char* substr = (char*) malloc((length + 1) * sizeof(char));

    if (substr == NULL)
    {
        return NULL;
    }

    int i;
    for (i = 0; i < length && str[start + i] != '\0'; i++)
    {
        substr[i] = str[start + i];
    }

    substr[i] = '\0';

    return substr;
}

int my_strcmp(const char *s1, const char *s2) {
    const unsigned char *us1 = (const unsigned char *) s1;
    const unsigned char *us2 = (const unsigned char *) s2;

    while (*us1 == *us2 && *us1 != '\0')
    {
        us1++;
        us2++;
    }

    return (*us1 > *us2) - (*us1 < *us2);
}

size_t my_strlen(const char* str)
{
    const char* ptr = str;
    while (*ptr)
    {
        ptr++;
    }
    return (size_t)(ptr - str);
}

char* my_strcpy(char* dest, const char* src)
{
    char* ptr = dest;

    while (*src != '\0')
    {
        *ptr = *src;
        ptr++;
        src++;
    }

    *ptr = '\0';

    return dest;
}

char* my_strmult(const char* str, int multiplier)
{
    int length = my_strlen(str);
    char* result = (char*) malloc((length * multiplier + 1) * sizeof(char));

    if (result == NULL)
    {
        return NULL;
    }

    int j = 0;
    for (int i = 0; i < multiplier; i++)
    {
        my_strcpy(result + j, str);
        j += length;
    }

    result[j] = '\0';

    return result;
}
