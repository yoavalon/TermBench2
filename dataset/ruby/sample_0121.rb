require 'random'

def simulate_stock_price(start, volatility, days)
  prices = [start]
  days.times do
    price_change = Random.gaussian(0, volatility)
    new_price = prices.last * (1 + price_change)
    prices << new_price
  end
  prices
end

def calculate_option_value(prices, strike, days, risk_free_rate)
  final_price = prices.last
  payoff = [final_price - strike, 0].max
  payoff / (1 + risk_free_rate) ** days
end

def main
  start_price = 100
  volatility = 0.2
  strike_price = 105
  days = 30
  risk_free_rate = 0.05
  iterations = 1000
  total_value = 0
  iterations.times do
    prices = simulate_stock_price(start_price, volatility, days)
    option_value = calculate_option_value(prices, strike_price, days, risk_free_rate)
    total_value += option_value
  end
  average_value = total_value / iterations
  puts average_value
end

main