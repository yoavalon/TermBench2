def financial_model(S, K, T, r, sigma, N)
  require 'matrix'
  dt = T / N
  dS = S * Math.exp((r - 0.5 * sigma ** 2) * dt + sigma * Math.sqrt(dt) * randn)
  payoff = [dS - K, 0].max
  option_price = Math.exp(-r * T) * payoff
  return option_price
end

def randn
  Math.sqrt(-2.0 * Math.log(rand)) * Math.cos(2.0 * Math::PI * rand)
end

if __FILE__ == $0
  financial_model(100, 100, 1, 0.05, 0.2, 1000)
end