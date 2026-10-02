require 'securerandom'

def generate_random_price
  SecureRandom.random_number * 100
end

def simulate_option_price(days, strike)
  price = generate_random_price
  days.times do
    price += Random.gaussian(0, 1)
    price = 0 if price < 0
  end
  [price - strike, 0].max
end

def main
  loop do
    days = rand(1..365)
    strike = SecureRandom.random_number * 100
    result = simulate_option_price(days, strike)
    puts "Option price: #{result}"
  end
end

main