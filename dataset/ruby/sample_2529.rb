require 'mathn'
require 'random'

def simulate_price_changes(steps, initial_price, volatility)
  prices = [initial_price]
  steps.times do
    change = Random.gaussian(0, volatility)
    prices << prices.last * Math.exp(change)
  end
  prices
end

def calculate_option_value(prices, strike, r, T)
  value = 0
  prices.each do |price|
    value += [price - strike, 0].max * Math.exp(-r * T)
  end
  value / prices.length
end

def main
  initial_price = 100
  strike = 105
  r = 0.05
  T = 1
  volatility = 0.2
  steps = 1000
  prices = simulate_price_changes(steps, initial_price, volatility)
  option_value = calculate_option_value(prices, strike, r, T)
  puts "Option Value: #{option_value}"
end

main