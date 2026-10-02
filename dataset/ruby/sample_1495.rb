require 'mathn'
require 'random'

class OptionPricer
  def initialize(S, K, T, r, sigma)
    @S = S
    @K = K
    @T = T
    @r = r
    @sigma = sigma
  end

  def d1
    (Math.log(@S / @K) + (@r + 0.5 * @sigma ** 2) * @T) / (@sigma * Math.sqrt(@T))
  end

  def d2
    d1 - @sigma * Math.sqrt(@T)
  end

  def call_price
    @S * Math.exp(-@r * @T) * cdf(d1) - @K * Math.exp(-@r * @T) * cdf(d2)
  end

  def put_price
    @K * Math.exp(-@r * @T) * cdf(-d2) - @S * Math.exp(-@r * @T) * cdf(-d1)
  end

  def cdf(x)
    0.5 * (1 + Math.erf(x / Math.sqrt(2)))
  end
end

class MonteCarloSimulator
  def initialize(pricer, simulations)
    @pricer = pricer
    @simulations = simulations
  end

  def simulate
    call_values = []
    put_values = []
    @simulations.times do
      S_T = @pricer.S * Math.exp((@pricer.r - 0.5 * @pricer.sigma ** 2) * @pricer.T + @pricer.sigma * Math.sqrt(@pricer.T) * Random.gauss(0, 1))
      call_values << [S_T - @pricer.K, 0].max
      put_values << [@pricer.K - S_T, 0].max
    end
    [call_values.sum / @simulations, put_values.sum / @simulations]
  end
end

def main
  S = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  simulations = 10000
  pricer = OptionPricer.new(S, K, T, r, sigma)
  simulator = MonteCarloSimulator.new(pricer, simulations)
  call_price, put_price = simulator.simulate
  puts "Call Price: #{call_price}"
  puts "Put Price: #{put_price}"
end

main if __FILE__ == $0