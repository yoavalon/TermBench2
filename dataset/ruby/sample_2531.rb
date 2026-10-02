require 'random'

def simulate_paths(S0, mu, sigma, T, N, M)
  paths = Array.new(M) { [S0] }
  dt = T.to_f / N
  for _ in 1..N
    for i in 0...M
      z = Random.gaussian(0, 1)
      S = paths[i].last * (1 + mu * dt + sigma * z * Math.sqrt(dt))
      paths[i] << S
    end
  end
  paths
end

def calculate_option_price(paths, K, r, T)
  payoff = paths.map { |p| [p.last - K, 0].max }
  price = (payoff.sum.to_f / payoff.size) * (1 / (1 + r * T))
  price
end

def main
  S0 = 100
  K = 100
  r = 0.05
  T = 1
  N = 100
  M = 1000
  paths = simulate_paths(S0, r - 0.5 * 0.2 ** 2, 0.2, T, N, M)
  price = calculate_option_price(paths, K, r, T)
  puts price
end

main