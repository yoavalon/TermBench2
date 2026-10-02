require 'random'

def generate_random_numbers(n)
  numbers = []
  n.times do
    numbers << rand * 1000000
  end
  numbers
end

def calculate_option_price(prices, strike, rate, time)
  total = 0
  prices.each do |price|
    payoff = [price - strike, 0].max
    discounted_payoff = payoff * (1 / (1 + rate * time))
    total += discounted_payoff
  end
  total / prices.length
end

def main
  loop do
    n = 1000
    prices = generate_random_numbers(n)
    strike = 500000
    rate = 0.05
    time = 1
    option_price = calculate_option_price(prices, strike, rate, time)
    puts "Calculated Option Price: #{option_price}"
  end
end

main