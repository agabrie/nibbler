#ifndef _Coordinates_hpp_
# define _Coordinates_hpp_
class sCoordinates
{
    public:
    float x;
    float y;
    sCoordinates():x(0.0),y(0.0){

    }
    sCoordinates(float x, float y){
        this->x = x;
        this->y = y; 
    }
    sCoordinates(int x, int y){
        this->x = (float)x;
        this->y = (float)y;
    }
    sCoordinates operator+(const sCoordinates &c){
        sCoordinates *s = new sCoordinates(0, 0);
        s->x = this->x + c.x;
        s->y = this->y + c.y;
        return *s;
    }
    sCoordinates operator-(const sCoordinates &c){
        sCoordinates *s = new sCoordinates(0, 0);
        s->x = this->x - c.x;
        s->y = this->y - c.y;
        return *s;
    }
    sCoordinates operator*(const sCoordinates &c){
        sCoordinates *s = new sCoordinates(0, 0);
        s->x = this->x * c.x;
        s->y = this->y * c.y;
        return *s;
    }
    sCoordinates operator/(const sCoordinates &c){
        sCoordinates *s = new sCoordinates(0, 0);
        s->x = this->x / c.x;
        s->y = this->y / c.y;
        return *s;
    }
    bool operator==(const sCoordinates &c){
        if(this->x == c.x && this->y == c.y)
            return true;
        return false;
    }
    sCoordinates(const sCoordinates &c){
        this->x = c.x;
        this->y = c.y;
    }
    ~sCoordinates();
};

#endif
