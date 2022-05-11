#include "sv_vector.h"

void* svv_new()
{
    return new sv_vector();
}

void* svv_new_winfo(const char* s)
{
    return new sv_vector(s);
}

void* svv_copy(void* other)
{
    sv_vector* ov = reinterpret_cast<sv_vector*>(other);
    return new sv_vector(*ov);
}

void* svv_copy_winfo(void* other, const char* s)
{
    sv_vector* ov = reinterpret_cast<sv_vector*>(other);
    return new sv_vector(*ov, s);
}

void svv_delete(void* v)
{
    delete (sv_vector*)v;
}

int svv_at(void* v, int loc)
{
    sv_vector* vec = reinterpret_cast<sv_vector*>(v);
    return vec->at(loc);
}

void svv_set(void* v, int loc, int value)
{
    sv_vector* vec = reinterpret_cast<sv_vector*>(v);
    vec->set(loc, value);
}

void svv_push_back(void* v, int value)
{
    sv_vector* vec = reinterpret_cast<sv_vector*>(v);
    vec->push_back(value);
}

int svv_pop_back(void* v)
{
    sv_vector* vec = reinterpret_cast<sv_vector*>(v);
    return vec->pop_back();
}

void svv_push_front(void* v, int value)
{
    sv_vector* vec = reinterpret_cast<sv_vector*>(v);
    vec->push_front(value);
}

int svv_pop_front(void* v)
{
    sv_vector* vec = reinterpret_cast<sv_vector*>(v);
    return vec->pop_front();
}

int svv_size(void* v)
{
    sv_vector* vec = reinterpret_cast<sv_vector*>(v);
    return vec->size();
}

void svv_shuffle(void* v)
{
    sv_vector* vec = reinterpret_cast<sv_vector*>(v);
    vec->shuffle();
}