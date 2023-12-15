#ifndef VIEW_HPP
#define VIEW_HPP

#include "Framework.hpp"
#include "FlyingObject.hpp"
#include <vector>

class View {
private:
    Framework* framework;

public:
    View(Framework* fw) : framework(fw) {}
    void RefreshDisplay(const std::vector<FlyingObject*>& objects);
};

#endif // VIEW_HPP
