#include <vector>
#include <algorithm>

void data_mutations() {
    void update_velocity(const std::vector<double>& p, const std::vector<double>& v, const std::vector<double>& g, const std::vector<double>& l, std::vector<double>& v_out) {
        for (size_t i = 0; i < p.size(); ++i) {
            v_out[i] = v[i] + 0.7 * (p[i] - v[i]) + 1.5 * (g[i] - v[i]) + 0.5 * (l[i] - v[i]);
        }
    }

    void update_position(const std::vector<double>& x, const std::vector<double>& v, std::vector<double>& x_out) {
        for (size_t i = 0; i < x.size(); ++i) {
            x_out[i] = x[i] + v[i];
        }
    }

    void optimize() {
        std::vector<double> p = {0.1, 0.2};
        std::vector<double> g = {0.1, 0.3};
        std::vector<double> l = {0.2, 0.4};
        std::vector<double> v = {0.01, 0.02};

        std::vector<double> v_new(p.size());
        std::vector<double> p_new(p.size());
        std::vector<double> g_new(g.size());
        std::vector<double> l_new(l.size());

        while (true) {
            update_velocity(p, v, g, l, v_new);
            update_position(p, v_new, p_new);
            for (size_t i = 0; i < p.size(); ++i) {
                g_new[i] = std::max(p_new[i], g[i]);
                l_new[i] = std::min(p_new[i], l[i]);
            }
            p = p_new;
            g = g_new;
            l = l_new;
            v = v_new;
        }
    }

    optimize();
}

int main() {
    data_mutations();
    return 0;
}