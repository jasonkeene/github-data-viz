
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

    void operator+=(Vector);
    void operator-=(Vector);

    float x;
    float y;
};

#endif
