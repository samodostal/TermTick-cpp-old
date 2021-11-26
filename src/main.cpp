#include <termox/termox.hpp>
using namespace ox;

class App : public Widget {
  auto paint_event(Painter &p) -> bool override {
    p.put("Hello, World!", {0, 0});
    return Widget::paint_event(p);
  }
};

int main() { return System{}.run<App>(); }
