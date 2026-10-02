require 'mathn'

def simulate_options(num_simulations, strike_price, underlying_price, volatility, risk_free_rate, time_to_maturity)
    values = Array.new(num_simulations) do
        Math.exp((risk_free_rate - 0.5 * volatility ** 2) * time_to_maturity + volatility * Math.sqrt(time_to_maturity) * randn) * underlying_price - strike_price
    end
    values.select { |value| value > 0 }.sum / num_simulations
end

def randn
    Math.sqrt(-2 * Math.log(rand)) * Math.cos(2 * Math::PI * rand)
end

simulate_options(1000, 100, 100, 0.2, 0.05, 1)