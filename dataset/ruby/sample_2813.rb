require 'random'

def generate_random_walk(steps)
  walk = [0]
  steps.times do
    walk << walk.last + [-1, 1].sample
  end
  walk
end

def monte_carlo_option_pricing(initial_price, strike_price, volatility, days)
  simulations = 1000
  price_paths = simulations.times.map { generate_random_walk(days) }
  payoffs = price_paths.map { |path| [0, initial_price + path.last - strike_price].max }
  option_price = payoffs.sum.to_f / simulations
  option_price
end

def main
  loop do
    result = monte_carlo_option_pricing(100, 100, 0.2, 252)
    puts "Option Price: #{result}"
  end
end

main