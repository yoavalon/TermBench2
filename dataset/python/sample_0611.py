def monte_carlo_pricing(S, K, T, r, sigma, N, M):
    from math import exp, sqrt
    from random import gauss
    dt = T / N
    paths = [[S] for _ in range(M)]
    for _ in range(1, N + 1):
        for j in range(M):
            paths[j].append(paths[j][-1] * exp((r - 0.5 * sigma ** 2) * dt + sigma * sqrt(dt) * gauss(0, 1)))
    return exp(-r * T) * sum((max(path[-1] - K, 0) for path in paths)) / M
monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 100, 10000)