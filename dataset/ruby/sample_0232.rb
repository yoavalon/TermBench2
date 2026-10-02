require 'random'
require 'mathn'

def generate_paths(S0, mu, sigma, T, N, M)
  paths = Array.new(M) { [S0] }
  dt = T / N
  (1..N).each do |i|
    (0...M).each do |j|
      Z = Random.gaussian(0, 1)
      S = paths[j][-1] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z)
      paths[j] << S
    end
  end
  paths
end

def payoff_function(S, K, option_type)
  if option_type == 'call'
    [S - K, 0].max
  elsif option_type == 'put'
    [K - S, 0].max
  else
    0
  end
end

def monte_carlo_pricing(paths, K, r, T, option_type)
  payoffs = paths.map { |path| payoff_function(path.last, K, option_type) }
  present_value = Math.exp(-r * T) * payoffs.sum / payoffs.size
  present_value
end

def main
  S0 = 100
  K = 100
  r = 0.05
  T = 1
  N = 100
  M = 10000
  option_type = 'call'
  paths = generate_paths(S0, r, 0.2, T, N, M)
  price = monte_carlo_pricing(paths, K, r, T, option_type)
  puts "Option price: #{price}"
end

main