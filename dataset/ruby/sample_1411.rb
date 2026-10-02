require 'random'

def simulate_paths(S0, mu, sigma, T, N, M)
  dt = T / N
  paths = Array.new(M) { [S0] }
  (1..N).each do |t|
    (0...M).each do |i|
      z = Random.gaussian(0, 1)
      paths[i] << paths[i].last * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z)
    end
  end
  paths
end

def calculate_payoffs(paths, K, T, r, type='call')
  payoffs = []
  paths.each do |path|
    ST = path.last
    if type == 'call'
      payoff = [0, ST - K].max
    else
      payoff = [0, K - ST].max
    end
    payoffs << payoff * Math.exp(-r * T)
  end
  payoffs
end

def monte_carlo_pricing(S0, K, T, r, sigma, M)
  paths = simulate_paths(S0, r, sigma, T, 100, M)
  payoffs = calculate_payoffs(paths, K, T, r)
  payoffs.sum / M
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  M = 10000
  price = monte_carlo_pricing(S0, K, T, r, sigma, M)
  puts "Option Price: #{price.round(2)}"
end

main