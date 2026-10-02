require 'random'

def generate_prices(num_days, initial_price, volatility)
  prices = [initial_price]
  (num_days - 1).times do
    change = Random.gauss(0, volatility)
    new_price = prices.last * (1 + change)
    prices << new_price
  end
  prices
end

def calculate_payoffs(prices, strike_price, call_or_put)
  payoffs = []
  prices.each do |price|
    if call_or_put == 'call'
      payoff = [price - strike_price, 0].max
    else
      payoff = [strike_price - price, 0].max
    end
    payoffs << payoff
  end
  payoffs
end

def monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity)
  total_payoff = 0
  num_simulations.times do
    prices = generate_prices(num_days, initial_price, volatility)
    payoffs = calculate_payoffs(prices, strike_price, call_or_put)
    discounted_payoff = payoffs.sum / payoffs.length * (1 + risk_free_rate) ** (-time_to_maturity)
    total_payoff += discounted_payoff
  end
  total_payoff / num_simulations
end

def main
  num_simulations = 1000
  num_days = 365
  initial_price = 100
  strike_price = 100
  volatility = 0.2
  call_or_put = 'call'
  risk_free_rate = 0.05
  time_to_maturity = 1
  option_price = monte_carlo_pricing(num_simulations, num_days, initial_price, strike_price, volatility, call_or_put, risk_free_rate, time_to_maturity)
  puts "Option price: #{option_price}"
end

main