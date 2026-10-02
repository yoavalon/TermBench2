require 'matrix'

def generate_paths(S0, T, r, sigma, N, M)
  dt = T.to_f / N
  paths = Array.new(N + 1) { Array.new(M, 0) }
  paths[0] = Array.new(M, S0)
  (1..N).each do |t|
    z = Array.new(M) { randn }
    paths[t] = paths[t - 1].map.with_index { |s, i| s * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i]) }
  end
  paths
end

def calculate_payoffs(paths, K, option_type)
  if option_type == 'call'
    paths[-1].map { |s| [s - K, 0].max }
  elsif option_type == 'put'
    paths[-1].map { |s| [K - s, 0].max }
  else
    nil
  end
end

def price_option(S0, K, T, r, sigma, N, M, option_type)
  paths = generate_paths(S0, T, r, sigma, N, M)
  payoffs = calculate_payoffs(paths, K, option_type)
  Math.exp(-r * T) * payoffs.sum.to_f / M
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 100
  M = 10000
  option_type = 'call'
  option_price = price_option(S0, K, T, r, sigma, N, M, option_type)
  puts "Option price: #{option_price.round(2)}"
end

main