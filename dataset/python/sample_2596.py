import random

def simulate_geometric_brownian_motion(S0, mu, sigma, T, N):
    dt = T / N
    S = [S0]
    for i in range(1, N + 1):
        dS = S[i - 1] * (mu * dt + sigma * random.gauss(0, dt ** 0.5))
        S.append(S[i - 1] + dS)
    return S[-1]

def monte_carlo_option_pricing(S0, K, T, r, sigma, N, M):
    C = 0
    for _ in range(M):
        ST = simulate_geometric_brownian_motion(S0, r, sigma, T, N)
        C += max(ST - K, 0)
    return C / M

def main():
    S0 = 100
    K = 100
    T = 1
    r = 0.05
    sigma = 0.2
    N = 100
    M = 1000
    option_price = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M)
    print(option_price)
main()