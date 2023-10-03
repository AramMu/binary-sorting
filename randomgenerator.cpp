#include "randomgenerator.h"
#include <ctime>

RandomGenerator::RandomGenerator(int rows, int cols) :
    rows(rows),
    cols(cols)
{}

std::mt19937& RandomGenerator::getGen() {
    static std::mt19937 gen(time (nullptr));
    return gen;
}

std::uniform_real_distribution<double>& RandomGenerator::getDist() {
    static std::uniform_real_distribution<double> dist(0,1);
    return dist;
}

double RandomGenerator::randProb () {
    return getDist() (getGen());
}

int RandomGenerator::randInt(int e) {
    return getDist() (getGen()) * e;
}

double RandomGenerator::randDouble (double e) {
    return getDist() (getGen()) * e;
}

int RandomGenerator::randInt(int b, int e) {
    return floor(getDist() (getGen()) * (e-b) + b);
}

double RandomGenerator::randDouble (double b, double e) {
    return getDist() (getGen()) * (e-b) + b;
}
