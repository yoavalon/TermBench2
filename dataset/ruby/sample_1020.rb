require 'random'

def simulate_price(initial_price, volatility, time_steps)
  prices = [initial_price]
  time_steps.times do
    drift = 0.05 * prices.last
    shock = volatility * prices.last * Random.gauss(0, 1)
    new_price = prices.last + drift + shock
    prices << new_price
  end
  prices
end

def calculate_option_price(prices, strike_price, option_type='call')
  if option_type == 'call'
    [0, prices.max - strike_price].max
  else
    [0, strike_price - prices.min].max
  end
end

def main
  initial_price = 100
  volatility = 0.2
  time_steps = 100
  strike_price = 105
  loop do
    prices = simulate_price(initial_price, volatility, time_steps)
    option_price = calculate_option_price(prices, strike_price)
    puts "Option price: #{option_price}"
  end
end

main