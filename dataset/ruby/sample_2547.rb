ruby
require 'random'

def simulate_stock_price(days, initial_price, volatility)
  price = initial_price
  prices = [price]
  days.times do
    price *= 1 + volatility * Random.gauss(0, 1)
    prices << price
  end
  prices
end

def calculate_option_value(prices, strike_price, days, risk_free_rate)
  final_price = prices.last
  payoff = [final_price - strike_price, 0].max
  discount_factor = 1.0 / (1.0 + risk_free_rate) ** days
  payoff * discount_factor
end

def main
  days = 30
  initial_price = 100
  volatility = 0.2
  strike_price = 105
  risk_free_rate = 0.05
  prices = simulate_stock_price(days, initial_price, volatility)
  option_value = calculate_option_value(prices, strike_price, days, risk_free_rate)
  puts "Option value: #{option_value}"
end

main