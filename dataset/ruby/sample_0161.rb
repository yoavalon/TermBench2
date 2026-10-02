require 'random'

def simulate_stock_price(steps, initial_price, drift, volatility)
  price = initial_price
  steps.times do
    price += price * (drift + volatility * Random.gauss(0, 1))
  end
  price
end

def price_option(pricing_function, initial_price, strike_price, steps, drift, volatility, simulations)
  total = 0
  simulations.times do
    final_price = simulate_stock_price(steps, initial_price, drift, volatility)
    payoff = [final_price - strike_price, 0].max
    total += payoff
  end
  total / simulations
end

def main
  initial_price = 100
  strike_price = 100
  steps = 100
  drift = 0.0001
  volatility = 0.01
  simulations = 10000
  option_price = price_option(simulate_stock_price, initial_price, strike_price, steps, drift, volatility, simulations)
  puts "Option Price: #{option_price}"
end

main