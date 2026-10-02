require 'random'

def simulate_option_price(iterations, strike, drift, volatility, risk_free_rate, time_to_maturity)
  values = Array.new(iterations, 0)
  (0...iterations).each do |i|
    price = 0
    (0...time_to_maturity * 252).each do
      price += price * drift * (1 / 252.0) + price * volatility * Random.gauss(0, 1) * (1 / 252.0) ** 0.5
    end
    values[i] = [price - strike, 0].max
  end
  values.sum * (1 / iterations.to_f) * (1 / risk_free_rate)
end

simulate_option_price(1000, 100, 0.05, 0.2, 0.03, 1)