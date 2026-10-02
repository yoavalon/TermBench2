require 'matrix'
require 'numo/narray'

def simulate_prices(steps, simulations)
  drift = 0.05
  volatility = 0.2
  initial_price = 100
  dt = 1.0 / steps
  paths = Numo::DFloat.zeros(simulations, steps)
  paths.column(0) = initial_price
  (1...steps).each do |t|
    z = Numo::DFloat.rand(simulations).map { |x| (x * 2 - 1) * Math.sqrt(12) } # Box-Muller transform for standard normal
    paths.column(t) = paths.column(t - 1) * Math.exp((drift - 0.5 * volatility ** 2) * dt + volatility * Math.sqrt(dt) * z)
  end
  paths
end

def option_pricing(prices, strike, option_type='call')
  if option_type == 'call'
    prices.max(strike, 0)
  elsif option_type == 'put'
    strike.max(prices, 0)
  else
    nil
  end
end

def main
  steps = 252
  simulations = 10000
  strike = 105
  prices = simulate_prices(steps, simulations)
  option_values = option_pricing(prices.column(-1), strike)
  puts option_values.mean
end

main