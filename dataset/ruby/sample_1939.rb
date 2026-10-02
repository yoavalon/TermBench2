require 'matrix'

def simulate_stock_prices(S0, mu, sigma, T, N, M)
  dt = T / N
  S = Array.new(M) { Array.new(N + 1, 0) }
  S.each { |row| row[0] = S0 }
  (1..N).each do |t|
    Z = Array.new(M) { randn }
    S.each_with_index do |row, i|
      row[t] = row[t - 1] * Math.exp((mu - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * Z[i])
    end
  end
  return S
end

def price_european_option(S, K, T, r)
  payoff = S.map { |row| [row.last - K, 0].max }
  return Math.exp(-r * T) * payoff.sum / payoff.size
end

def main
  S0 = 100.0
  K = 100.0
  T = 1.0
  r = 0.05
  sigma = 0.2
  N = 100
  M = 100000
  S = simulate_stock_prices(S0, r, sigma, T, N, M)
  option_price = price_european_option(S, K, T, r)
  puts option_price
end

def randn
  Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

main