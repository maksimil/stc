#include "stc/list.h"
#include <stdlib.h>

void st_initialize_list(st_list *list, size_t element_size)
{
    list->element_size = element_size;
    list->size = 0;
    list->allocated = 2;

    list->data = malloc(list->element_size * list->allocated);
}

void st_destroy_list(st_list *list)
{
    free(list->data);
}

void *st_push(st_list *list)
{
    if (list->size == list->allocated)
    {
        size_t nsize = list->allocated * 2;
        void *nptr = realloc(list->data, nsize * list->element_size);
        if (nptr == NULL)
            return NULL;

        list->data = nptr;
        list->allocated = nsize;
    }

    return st_get(list, list->size++);
}

void *st_get(st_list *list, size_t index)
{
    return list->data + list->element_size * index;
}
