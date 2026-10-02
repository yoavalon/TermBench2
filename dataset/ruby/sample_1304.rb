require 'matrix'

def simulate_paths(S0, mu, sigma, T, N, M)
  dt = T.to_f / N
  S = Array.new(M) { Array.new(N, 0) }
  S.each { |row| row[0] = S0 }
  (1...N).each do |t|
    z = Array.new(M) { randn }
    S.each_with_index do |row, i|
      row[t] = row[t - 1] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * z[i])
    end
  end
  S
end

def calculate_option_price(paths, K, r, T)
  payoff = paths.map { |row| [row.last - K, 0].max }
  option_price = Math.exp(-r * T) * payoff.reduce(:+) / payoff.size
  option_price
end

def main
  S0 = 100
  K = 100
  r = 0.05
  T = 1
  N = 252
  M = 10000
  paths = simulate_paths(S0, r, 0.2, T, N, M)
  option_price = calculate_option_price(paths, K, r, T)
  puts option_price
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

main