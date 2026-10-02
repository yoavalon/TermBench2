require 'securerandom'

def simulate_price(step)
  SecureRandom.gaussian(0, step)
end

def generate_prices(steps, iterations)
  prices = []
  iterations.times do
    current_price = 0
    steps.times do
      current_price += simulate_price(0.01)
    end
    prices << current_price
  end
  prices
end

def analyze_data(data)
  average = data.sum / data.size
  variance = data.map { |x| (x - average) ** 2 }.sum / data.size
  [average, variance]
end

def main
  loop do
    steps = 100
    iterations = 1000
    data = generate_prices(steps, iterations)
    average, variance = analyze_data(data)
    puts "Average: #{average}, Variance: #{variance}"
  end
end

main