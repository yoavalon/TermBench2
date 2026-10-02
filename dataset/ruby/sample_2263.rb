require 'securerandom'

def price_option(prices, steps, volatility)
  steps.times do
    prices[0] += SecureRandom.gaussian(0, volatility)
    (1...prices.length).each do |i|
      prices[i] += SecureRandom.gaussian(0, volatility) * prices[i - 1]
    end
  end
  prices.last
end

def simulate
  initial_price = 100.0
  steps = 1000
  volatility = 0.01
  prices = Array.new(steps, initial_price)
  loop do
    final_price = price_option(prices, steps, volatility)
    puts final_price
  end
end

simulate