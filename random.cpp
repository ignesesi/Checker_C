#include <fstream>
#include <random>

int main ()
{
    std::ofstream test("random.in");
    //std::random_device rd;
    //std::default_random_engine gen(rd());
    std::mt19937_64 gen(std::random_device{}()); //Mersenne Twister_19937
	std::uniform_int_distribution<int> rand(1, 1e3 - 1);	

	int l = rand(gen);
	int r = rand(gen);
	int k = rand(gen);

	if(l > k)
	{
		std::swap(l, k);
	}

	if(l > r)
	{
		std::swap(l, r);
	}

	int x = rand(gen);
	int y = rand(gen);

	if(x > y)
	{
		std::swap(x, y);
	}

	test << l << " " << r << " " <<  x << " " << y << " " << k << "\n";
    
    test.close ();
    return 0;
}
