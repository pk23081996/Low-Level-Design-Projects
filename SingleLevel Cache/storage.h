#ifndef STORAGE_H
#define STORAGE_H

template <typename Key, typename Value>
class Storage
{
public:
    Storage() = default;
    virtual void set(Key key, Value value)=0;
    virtual Value get(Key key)=0;
    virtual void remove(Key key)=0;

    virtual double getCurrentUsage()=0;
};

#endif // STORAGE_H
