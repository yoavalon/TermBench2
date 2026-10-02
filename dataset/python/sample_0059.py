def monte_carlo_pricing(S0, K, T, r, sigma, N, M):
    import numpy as np
    d1 = (np.log(S0 / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * np.sqrt(T))
    d2 = d1 - sigma * np.sqrt(T)
    call_price = S0 * np.exp(-r * T) * np.cdf(d1) - K * np.exp(-r * T) * np.cdf(d2)
    return call_price
if __name__ == '__main__':
    result = monte_carlo_pricing(100, 100, 1, 0.05, 0.2, 1000, 100000)
    print(result)