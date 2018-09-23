
class Transactable
{
protected:
    Transactable();

public:

    virtual Transactable* beginWriteTransaction() = 0;
    virtual void commitTransaction(Transactable*) = 0;
    virtual void rollbackTransaction() = 0;

    virtual void beginReadOnlyTransaction() = 0;
    virtual void endReadOnlyTransaction() = 0;
};
