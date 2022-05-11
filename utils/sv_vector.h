#pragma once
#include <svdpi.h>
#include <cstdio>
#include <deque>
#include <string>
#include <algorithm>
#include <stdexcept>

class sv_vector
{
    public:
    sv_vector() {}
    sv_vector(const char* i)
        : info(std::string(i) + ": ") {}

    sv_vector(const sv_vector& other)
    {
        vec = other.vec;
    }

    sv_vector(const sv_vector& other, const char* i)
    {
        vec = other.vec;
        info = std::string(i) + ": ";
    }

    int at(int loc) const 
    {
        if (vec.size() <= loc)
        {
            char size_s[8];
            char loc_s[8];
            snprintf(size_s, 8, "%d", vec.size());
            snprintf(loc_s, 8, "%d", loc);
            throw std::out_of_range(
                info + "Accessing element " + loc_s + 
                    " while size is " + size_s
            );
        }
        return vec[loc];
    }

    int set(int loc, int x)
    {
        if (vec.size() <= loc)
        {
            char size_s[8];
            char loc_s[8];
            snprintf(size_s, 8, "%d", vec.size());
            snprintf(loc_s, 8, "%d", loc);
            throw std::out_of_range(
                info + "Accessing element " + loc_s + 
                    " while size is " + size_s
            );
        }
        vec[loc] = x;
    }

    void push_back(int x)
    {
        vec.push_back(x);
    }

    int pop_back()
    {
        if (vec.empty())
            throw std::out_of_range(info + "Calling pop_back on empty deque");
        int x = vec.back();
        vec.pop_back();
        return x;
    }

    void push_front(int x)
    {
        vec.push_front(x);
    }

    int pop_front()
    {
        if (vec.empty())
            throw std::out_of_range(info + "Calling pop_front on empty deque");
        int x = vec.front();
        vec.pop_front();
        return x;
    }

    int size() const
    {
        return vec.size();
    }

    void shuffle()
    {
        std::random_shuffle(vec.begin(), vec.end());
    }
    
    private:
    std::deque<int> vec;
    std::string info;
};

extern "C" 
{
    void* svv_new();
    void* svv_new_winfo(const char* s);
    void* svv_copy(void* other);
    void* svv_copy_winfo(void* other, const char* s);
    void svv_delete(void* v);
    int svv_at(void* v, int loc);
    void svv_set(void* v, int loc, int value);
    void svv_push_back(void* v, int value);
    int svv_pop_back(void* v);
    void svv_push_front(void* v, int value);
    int svv_pop_front(void* v);
    int svv_size(void* v);
    void svv_shuffle(void* v);
}

