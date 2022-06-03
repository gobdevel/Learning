#include "gtest/gtest.h"
#include "openClosePrinciple.h"

using namespace OCP;

TEST(OCP, Basic) {
    Product apple("Apple", Color::Green, Size::Small);
    Product tree("Tree", Color::Green, Size::Big);
    Product house("House", Color::Blue, Size::Big);
    Product mango("Mango", Color::Green, Size::Small);
    Product banana("Banana", Color::Red, Size::Medium);

    std::vector<Product*> all{&apple, &tree, &house, &mango, &banana};
    BetterFilter          bf;
    ColorSpecification    green(Color::Green);

    auto greenItems = bf.filter(all, green);

    for (const auto& i : greenItems) {
        std::cout << i->name << ", ";
    }
    std::cout << "\n";
    EXPECT_TRUE(true);
}
