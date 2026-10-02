require 'random'

def simulate_geometric_brownian_motion(S0, mu, sigma, T, N)
  dt = T / N
  S = [S0]
  (1..N).each do |i|
    dS = S[i - 1] * (mu * dt + sigma * Random.gaussian(0, dt ** 0.5))
    S << S[i - 1] + dS
  end
  S[-1]
end

def monte_carlo_option_pricing(S0, K, T, r, sigma, N, M)
  C = 0
  M.times do
    ST = simulate_geometric_brownian_motion(S0, r, sigma, T, N)
    C += [ST - K, 0].max
  end
  C / M
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 100
  M = 1000
  option_price = monte_carlo_option_pricing(S0, K, T, r, sigma, N, M)
  puts option_price
end

main