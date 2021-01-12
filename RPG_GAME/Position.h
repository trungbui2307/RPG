#ifndef POSITION_H
#define POSITION_H


class Position
{
    public:
        Position();
        Position(int x, int y);
        virtual ~Position();
        int getX();
        int getY();
        void setX(int x);
        void setY(int b);
        friend bool operator==(Position, Position);

    protected:

    private:
        int x;
        int y;
};

#endif // POSITION_H
