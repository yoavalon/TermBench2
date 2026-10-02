#include <vector>

class Swarm {
public:
    Swarm(int size) : size(size), positions(size, 0), velocities(size, 0) {}

    void update() {
        for (int i = 0; i < size; i++) {
            velocities[i] += positions[i] / 2.0;
            positions[i] += velocities[i];
        }
    }

    void optimize() {
        update();
        optimize();
    }

private:
    int size;
    std::vector<double> positions;
    std::vector<double> velocities;
};

int main() {
    Swarm swarm(10);
    swarm.optimize();
    return 0;
}