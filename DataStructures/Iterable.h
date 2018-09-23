#include <functional>

template <typename T>
class Iterable
{
protected:
    Iterable();

public:

    virtual void forEach(std::function<void(T)> callback) const = 0;
};
