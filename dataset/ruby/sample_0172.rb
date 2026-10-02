require 'random'

def generate_paths(steps, simulations)
  paths = []
  simulations.times do
    path = [0]
    (1...steps).each do
      path << path.last + [1, -1].sample
    end
    paths << path
  end
  paths
end

def calculate_option_value(paths, strike_price, payoff)
  values = []
  paths.each do |path|
    final_price = path.last
    values << [0, payoff * (final_price - strike_price)].max
  end
  values.sum / values.length.to_f
end

def main
  steps = 100
  simulations = 1000
  strike_price = 50
  payoff = 1
  paths = generate_paths(steps, simulations)
  option_value = calculate_option_value(paths, strike_price, payoff)
  puts "Option Value: #{option_value}"
end

main