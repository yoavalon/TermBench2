require 'matrix'

def simulate_prices(steps, simulations)
  Array.new(simulations) { Array.new(steps) { randn * 0.2 + 0.05 } }
end

def calculate_option_value(prices, strike)
  final_prices = prices.map(&:last)
  final_prices.select { |price| price > strike }.sum / final_prices.size
end

def main
  steps = 100
  simulations = 1000
  strike = 100
  prices = simulate_prices(steps, simulations)
  value = calculate_option_value(prices, strike)
  puts value
end

main