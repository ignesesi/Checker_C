#include <fstream>
#include <random>

int n = 100, a[1000][1000];

int main ()
{
    std::ofstream test("park_test.in");
    std::random_device rd;
    std::default_random_engine gen(rd());
    //std::uniform_int_distribution<> rand_n(5,10);
    std::uniform_int_distribution<> rand_a(0,9);
    test << n << "\n";
    for (int i = 0; i < n; i ++)
    {
        a[i][i] = 0;
        for (int j = i + 1; j < n; j ++)
        {
            a[i][j] = rand_a(gen);
            a[j][i] = a[i][j];
        }
    }
    for (int i = 0; i < n; i ++)
    {
        for (int j = 0; j < n; j ++)
        {
            test << a[i][j] << " ";
        }
        test << "\n";
    }
    test.close ();
    return 0;
}
