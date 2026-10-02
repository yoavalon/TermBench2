require 'random'

def simulate_stock_price(start_price, volatility, days)
  price = start_price
  days.times do
    price *= 1 + volatility * (2 * rand - 1)
  end
  price
end

def monte_carlo_pricing(option_type, start_price, strike_price, volatility, days, simulations)
  total_value = 0
  simulations.times do
    final_price = simulate_stock_price(start_price, volatility, days)
    if option_type == 'call'
      value = [final_price - strike_price, 0].max
    else
      value = [strike_price - final_price, 0].max
    end
    total_value += value
  end
  total_value / simulations
end

def main
  start_price = 100
  strike_price = 100
  volatility = 0.05
  days = 252
  simulations = 10000
  option_type = 'call'
  loop do
    price = monte_carlo_pricing(option_type, start_price, strike_price, volatility, days, simulations)
    puts "Estimated option price: #{price}"
  end
end

main