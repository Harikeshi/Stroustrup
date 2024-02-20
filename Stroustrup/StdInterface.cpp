
class Std_interface
{

public:
    virtual void start() = 0;
    virtual void suspend() = 0;
    virtual void resume() = 0;
    virtual void quit() = 0;
    virtual void full_size() = 0;
    virtual void small() = 0;

    virtual ~Std_interface() {}
};

class mem : public Std_interface
{
    void start() {}
    void suspend() {}
    void resume() {}
    void quit() {}
    void full_size() {}
    void small() {}
};

void sf(Std_interface* p)
{
    // указатель на член
    using Pstd_mem = void (Std_interface::*)();

    Pstd_mem s = &Std_interface::suspend;
    p->suspend();

    (p->*s)();
}
