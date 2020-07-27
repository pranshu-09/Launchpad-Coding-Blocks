
template <typename T> // We are making our vector class as Templated Class, through which we would be able to create our vectors of any datatype

class Vector
{
        int cs;
        int ms;
        T *arr;

    public:

        Vector()
        {
                cs=0;
                ms=1;
                arr = new T[ms];
        }

        void push_back(const T d)
        {
                if(cs==ms)
                {
                        //If the array becomes full
                        T *oldArr = arr;
                        arr = new T[2*ms];
                        ms = ms*2;

                        for(int i=0;i<cs;i++)
                            arr[i] = oldArr[i];

                        //Delete the old array now
                        delete [] oldArr;
                }

                arr[cs] = d;
                cs++;
        }

        void pop_back()
        {
                cs--;
        }

        T front() const
        {
                return arr[0];
        }

        T back() const
        {
                return arr[cs-1];
        }

        bool empty() const
        {
                return cs==0;
        }

        int capacity() const
        {
                return ms;
        }

        T at(const int i)
        {
                return arr[i];
        }

        T operator[] (const int i)       //Operator Overloading
        {
                return arr[i];
        }

        int size() const
        {
                return cs;
        }

};
