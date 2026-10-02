require 'random'

def simulate_stock_price(s0, mu, sigma, dt)
  s0 * (1 + mu * dt + sigma * rand.gaussian(0, 1) * Math.sqrt(dt))
end

def monte_carlo_option_pricing(s0, strike, r, t, sigma, n_simulations)
  dt = t / 252.0
  option_values = []
  n_simulations.times do
    price = s0
    252.times do
      price = simulate_stock_price(price, r - 0.5 * sigma ** 2, sigma, dt)
    end
    option_values << [price - strike, 0].max
  end
  option_values.sum / n_simulations
end

def main
  s0, strike, r, t, sigma, n_simulations = 100, 105, 0.05, 1, 0.2, 10000
  loop do
    price = monte_carlo_option_pricing(s0, strike, r, t, sigma, n_simulations)
    puts "Option price: #{price}"
  end
end

main