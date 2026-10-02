require 'random'

def price_option(step, path, strike, risk_free, volatility, time_to_maturity)
  if step == 0
    return [path[-1] - strike, 0].max
  end
  up = path[-1] * (1 + volatility)
  down = path[-1] * (1 - volatility)
  return (risk_free * price_option(step - 1, path + [up], strike, risk_free, volatility, time_to_maturity) + (1 - risk_free) * price_option(step - 1, path + [down], strike, risk_free, volatility, time_to_maturity)) / 2
end

def monte_carlo(strike, risk_free, volatility, time_to_maturity)
  steps = (time_to_maturity * 252).to_i
  paths = Array.new(1000) { price_option(steps, [100], strike, risk_free, volatility, time_to_maturity) }
  return paths.sum / paths.size
end

def main
  strike = 100
  risk_free = 0.05
  volatility = 0.2
  time_to_maturity = 1
  loop do
    monte_carlo(strike, risk_free, volatility, time_to_maturity)
  end
end

main