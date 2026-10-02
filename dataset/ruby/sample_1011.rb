require 'securerandom'

def simulate_price_change(current_price, volatility)
  current_price * (1 + SecureRandom.uniform(-volatility, volatility))
end

def recursive_price_simulation(price, volatility, depth)
  return price if depth == 0
  new_price = simulate_price_change(price, volatility)
  recursive_price_simulation(new_price, volatility, depth - 1)
end

def main
  initial_price = 100.0
  volatility = 0.05
  max_depth = 10000
  final_price = recursive_price_simulation(initial_price, volatility, max_depth)
  puts final_price
end

main