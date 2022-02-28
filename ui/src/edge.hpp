#ifndef EDGE_HPP
#define EDGE_HPP

#include <QGraphicsItem>

class Edge : public QGraphicsItem
{
public:
    Edge();

    enum { Type = UserType + 2 };
    int type() const override { return Type; }
};

#endif // EDGE_HPP
