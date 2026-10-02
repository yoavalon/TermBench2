require 'matrix'

def simulate_prices(steps, mean, volatility)
  prices = Array.new(steps, 0.0)
  prices[0] = 100
  (1...steps).each do |i|
    prices[i] = prices[i - 1] * (1 + rand.gaussian(mean, volatility))
  end
  prices
end

def calculate_option_value(prices, strike, r, t)
  payoff = [prices.last - strike, 0].max
  value = payoff * Math.exp(-r * t)
  value
end

def main
  steps = 100
  mean = 0.001
  volatility = 0.01
  strike = 105
  r = 0.05
  t = 1.0
  prices = simulate_prices(steps, mean, volatility)
  option_value = calculate_option_value(prices, strike, r, t)
  puts option_value
end

main