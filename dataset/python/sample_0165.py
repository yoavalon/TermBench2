import numpy as np

def generate_paths(S0, mu, sigma, T, N, M):
    dt = T / N
    S = np.zeros((N + 1, M))
    S[0] = S0
    for t in range(1, N + 1):
        S[t] = S[t - 1] * np.exp((mu - 0.5 * sigma ** 2) * dt + sigma * np.sqrt(dt) * np.random.normal(size=M))
    return S

def option_price(paths, K, r, T, payoff):
    discounted_payoffs = np.exp(-r * T) * payoff(paths[-1, :], K)
    return np.mean(discounted_payoffs)

def main():
    S0 = 100
    K = 100
    r = 0.05
    T = 1
    N = 252
    M = 10000
    sigma = 0.2
    mu = 0.1

    def european_call(S, K):
        return np.maximum(S - K, 0)
    paths = generate_paths(S0, mu, sigma, T, N, M)
    call_price = option_price(paths, K, r, T, european_call)
    print(call_price)
if __name__ == '__main__':
    main()