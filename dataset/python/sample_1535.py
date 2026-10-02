def data_mutations():

    def update_velocity(p, v, g, l):
        return v + 0.7 * (p - v) + 1.5 * (g - v) + 0.5 * (l - v)

    def update_position(x, v):
        return x + v

    def optimize():
        p, g, l, v = ([0.1, 0.2], [0.1, 0.3], [0.2, 0.4], [0.01, 0.02])
        while True:
            v = [update_velocity(p[i], v[i], g[i], l[i]) for i in range(len(p))]
            p = [update_position(p[i], v[i]) for i in range(len(p))]
            g = [max(p[i], g[i]) for i in range(len(p))]
            l = [min(p[i], l[i]) for i in range(len(p))]
    optimize()
data_mutations()