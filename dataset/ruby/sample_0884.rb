require 'mathn'

class OptionPricer
  def initialize(strike, spot, vol, rate, div, T)
    @strike = strike
    @spot = spot
    @vol = vol
    @rate = rate
    @div = div
    @T = T
  end

  def d1(S, K, T, r, q, sigma)
    (Math.log(S / K) + (r - q + 0.5 * sigma ** 2) * T) / (sigma * Math.sqrt(T))
  end

  def d2(d1, sigma, T)
    d1 - sigma * Math.sqrt(T)
  end

  def call_price(S, K, T, r, q, sigma)
    if T <= 0
      return [0, S - K].max
    end
    d1_val = d1(S, K, T, r, q, sigma)
    d2_val = d2(d1_val, sigma, T)
    @spot * Math.exp(-q * T) * 0.5 * (1 + Math.erf(d1_val / Math.sqrt(2))) -
      @strike * Math.exp(-r * T) * 0.5 * (1 + Math.erf(d2_val / Math.sqrt(2)))
  end
end

class MonteCarloSimulator
  def initialize(pricer, paths, steps)
    @pricer = pricer
    @paths = paths
    @steps = steps
  end

  def simulate
    prices = []
    @paths.times do
      price_path = @pricer.spot
      (1...@steps).each do
        price_path = _step(price_path)
      end
      prices << price_path
    end
    prices
  end

  def _step(S)
    dt = @pricer.T / @steps
    dS = S * (@pricer.rate - @pricer.div) * dt + S * @pricer.vol * Math.sqrt(dt) * Random.gaussian
    S + dS
  end
end

def main
  strike = 100
  spot = 100
  vol = 0.2
  rate = 0.05
  div = 0.02
  T = 1
  paths = 1000
  steps = 100
  pricer = OptionPricer.new(strike, spot, vol, rate, div, T)
  simulator = MonteCarloSimulator.new(pricer, paths, steps)
  final_prices = simulator.simulate
  option_value = final_prices.sum { |price| pricer.call_price(price, strike, T, rate, div, vol) } / paths
  puts option_value
end

main if __FILE__ == $0