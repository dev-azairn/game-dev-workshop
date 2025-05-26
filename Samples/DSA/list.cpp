// List Interface
template <typename T>
class List
{
    public:
        virtual ~List() {};
        virtual int size() = 0;
        virtual T get(int index) = 0;
        virtual void set(int index, T data) = 0;
        virtual bool addFirst(T data) = 0;
        virtual bool addLast(T data) = 0;
        virtual bool deleteFirst() = 0;
        virtual bool deleteLast() = 0;
        virtual bool addAt(int index, T data) = 0;
        virtual bool deleteAt(int index) = 0;
        virtual void display() = 0;
};