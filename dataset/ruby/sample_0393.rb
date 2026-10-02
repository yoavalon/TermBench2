require 'random'

def simulate_options(prices, days)
  loop do
    days.times do
      prices.each_index do |i|
        prices[i] *= 1 + (Random.rand - 0.5) * 0.1
      end
    end
    yield prices
  end
end

def main
  start_prices = [100, 150, 200]
  days = 5
  simulate_options(start_prices, days) do |result|
    puts result.inspect
  end
end

main