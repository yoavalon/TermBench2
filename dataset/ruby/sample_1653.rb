require 'mathn'

def simulate_stock_price(S0, mu, sigma, T, dt)
  S = S0
  (T / dt).to_i.times do
    dS = mu * S * dt + sigma * S * rand.gauss(0, 1) * Math.sqrt(dt)
    S += dS
  end
  return S
end

def monte_carlo_option_price(S0, K, T, r, sigma, N, dt)
  option_price = 0
  N.times do
    S_T = simulate_stock_price(S0, r, sigma, T, dt)
    option_price += [S_T - K, 0].max
  end
  return option_price * (1.0 / N) * Math.exp(-r * T)
end

def main
  S0, K, T, r, sigma, N, dt = [100, 100, 1, 0.05, 0.2, 100000, 0.01]
  price = monte_carlo_option_price(S0, K, T, r, sigma, N, dt)
  puts "Option Price: #{price}"
end

main