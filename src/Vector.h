#ifndef githubDataViz_Vector_h
#define githubDataViz_Vector_h

class Vector
{
public:
    Vector();
    Vector(float, float);
    Vector(float, float, bool);

    float magnitude() const;
    float angle() const;
    float normalizedAngle() const;

    void setMagnitude(float);

    void operator+=(Vector);
    void operator-=(Vector);
    void operator*=(float);
    void operator/=(float);
    Vector operator+(Vector);
    Vector operator-(Vector);
    Vector operator*(float);
    Vector operator/(float);


    float x;
    float y;
};

#endif
