#include <iostream>
#include <vector>

struct Range {
    int start;
    int stop;
};

int main() {
    int arr[32] = { 1,1,1,1,1,1,1,1,
                    1,1,1,1,1,1,1,1,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0 };

    bool f = false;
    Range r;
    std::vector<Range> v;

    for (int i = 0; i < 32; i++) {
        if (!f && arr[i] == 1) {
            f = true;
            r.start = i;
        }

        if (f && arr[i] == 0) {
            f = false;
            r.stop = i - 1;
            v.push_back(r);
        }

        if (f && i == 31) {
            f = false;
            r.stop = i;
            v.push_back(r);
        }
    }

    for (int i = 0; i < v.size(); i++)
        std::cout << v[i].start << "   " << v[i].stop << "\n";

}
