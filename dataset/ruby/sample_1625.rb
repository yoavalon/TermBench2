require 'matrix'

def simulate_prices(base_price, volatility, days)
  prices = Array.new(days, 0)
  prices[0] = base_price
  (1...days).each do |i|
    daily_return = rand.gaussian(0, volatility)
    prices[i] = prices[i - 1] * (1 + daily_return)
  end
  prices
end

def calculate_option_premium(prices, strike_price, days)
  option_values = prices.map { |price| [price - strike_price, 0].max }
  option_values.sum * 365 / days
end

def main
  base_price = 100
  volatility = 0.2
  days = 365
  strike_price = 100
  loop do
    prices = simulate_prices(base_price, volatility, days)
    premium = calculate_option_premium(prices, strike_price, days)
    puts "Calculated option premium: #{premium}"
  end
end

main