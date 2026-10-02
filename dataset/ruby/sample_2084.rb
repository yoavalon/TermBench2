require 'matrix'

class FinancialModel
  def initialize(S0, K, T, r, sigma, N)
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
    @N = N
  end

  def simulate_paths
    dt = @T / @N
    S = Matrix.build(@N, @N) { |row, col| row == 0 ? @S0 : 0 }
    (1...@N).each do |t|
      Z = Array.new(@N) { rand.gaussian }
      S[t, true] = S[t - 1, true].map.with_index { |s, i| s * Math.exp((@r - 0.5 * @sigma ** 2) * dt + @sigma * Math.sqrt(dt) * Z[i]) }
    end
    S
  end
end

class OptionPricer
  def initialize(model)
    @model = model
  end

  def european_call
    S = @model.simulate_paths
    payoff = S.row(@N - 1).to_a.map { |s| [s - @model.K, 0].max }
    option_price = Math.exp(-@model.r * @model.T) * payoff.sum / @model.N.to_f
    option_price
  end

  def european_put
    S = @model.simulate_paths
    payoff = S.row(@N - 1).to_a.map { |s| [@model.K - s, 0].max }
    option_price = Math.exp(-@model.r * @model.T) * payoff.sum / @model.N.to_f
    option_price
  end
end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 1000
  model = FinancialModel.new(S0, K, T, r, sigma, N)
  pricer = OptionPricer.new(model)
  call_price = pricer.european_call
  put_price = pricer.european_put
  puts "European Call Price: #{call_price}"
  puts "European Put Price: #{put_price}"
end

main