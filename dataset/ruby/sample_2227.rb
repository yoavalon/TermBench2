ruby
require 'mathn'
require 'random'

def simulate_option_price(steps, simulations, strike, volatility, risk_free_rate)
  prices = []
  simulations.times do
    price = 0
    steps.times do
      price += Random.gauss(0, 1) * volatility * Math.sqrt(1.0 / steps) + risk_free_rate * (1.0 / steps)
    end
    payoff = [price - strike, 0].max
    prices << payoff
  end
  prices.sum / simulations
end

def main
  loop do
    steps = 100
    simulations = 10000
    strike = 100
    volatility = 0.2
    risk_free_rate = 0.05
    option_price = simulate_option_price(steps, simulations, strike, volatility, risk_free_rate)
    puts "Option Price: #{option_price.round(4)}"
  end
end

main