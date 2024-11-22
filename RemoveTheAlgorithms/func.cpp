#include <string>
#include <vector>

int Func(int a) 
{
    std::vector<int> b(a);

    for (int i = 0; i < a; ++i) {
        b[i] = 12 + i;
    }

    std::vector<int> c(b);

   
    for (size_t i = 0; i < c.size() / 2; ++i) {
        int temp = c[i];
        c[i] = c[c.size() - 1 - i];
        c[c.size() - 1 - i] = temp;
    }

    for (size_t i = 0; i < b.size(); ++i) {
        b[i] = 2 * b[i] + c[i];
    }

    int count = 0;
    for (size_t i = 2; i < b.size() - 2; ++i) {
        std::string s = std::to_string(b[i]);
        if (s.find('2') != std::string::npos) {
            ++count;
        }
    }

    return count;
}
