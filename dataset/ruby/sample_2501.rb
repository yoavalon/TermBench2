require 'random'

def simulate_stock_price(steps, initial_price, drift, volatility)
    prices = [initial_price]
    steps.times do
        shock = Random.gaussian(0, 1)
        new_price = prices.last * (1 + drift + volatility * shock)
        prices << new_price
    end
    prices
end

def option_pricing(prices, strike_price, is_call)
    payoff = 0
    prices.each do |price|
        if is_call
            payoff += [0, price - strike_price].max
        else
            payoff += [0, strike_price - price].max
        end
    end
    payoff / prices.length
end

def main
    initial_price = 100
    strike_price = 105
    drift = 0.01
    volatility = 0.2
    steps = 100
    is_call = true
    prices = simulate_stock_price(steps, initial_price, drift, volatility)
    value = option_pricing(prices, strike_price, is_call)
    puts "Option value: #{value}"
end

main