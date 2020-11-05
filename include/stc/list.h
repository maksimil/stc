#pragma once

#include <stddef.h>

typedef struct
{
    void *data;

    size_t element_size;

    size_t size;
    size_t allocated;
} st_list;

void st_initialize_list(st_list *, size_t);
void st_destroy_list(st_list *);

void *st_push(st_list *);

void *st_get(st_list *, size_t);
