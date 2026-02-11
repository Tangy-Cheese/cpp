#include <iostream>
#include <cmath>
#include <random>
#include <functional>

bool InsideUnitSphere(double x, double y, double z)
{ 
    return ((x*x + y*y + z*z) <= 1);
}

bool check(double x, double y, double z){
    if((x*x + y*y + z*z) <= 1){
        return true;
    }

    return false;
}

double IntegrateMonteCarlo3D(int n_points, double min, double max, int seed, std::function<bool(double, double, double)> check)
{
    int count = 0;
    // N.B. std::pow with integer arguments can be less efficient than
    // writing the multiplication explicitly, so be careful about using it
    // inside loops for example!
    double VolCube = std::pow((max - min), 3);

    //set up random number generator here
    std::uniform_real_distribution<double> uniform_dist(-1.0, 1.0);
    std::mt19937 rng_mt(seed);

    for(int i = 0; i < n_points; i++)
    {
        //generate random points here
        double x = uniform_dist(rng_mt);
        double y = uniform_dist(rng_mt);
        double z = uniform_dist(rng_mt);
        if(check(x, y, z)) count++;
    }

    return static_cast<double>(count) / n_points * VolCube;
}


int main(int argc, char** argv)
{
    int N_points = 10000;

    int seed = std::stoi(argv[1]);
    double UnitSphereVol = IntegrateMonteCarlo3D(N_points, -1.0, 1.0, seed, &check);

    std::cout << "Volume estimate of sphere using " << N_points << " points = " << UnitSphereVol << std::endl;
}