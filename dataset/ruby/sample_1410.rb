require 'random'

class OptionPricingModel

  def initialize(S0, K, T, r, sigma)
    @S0 = S0
    @K = K
    @T = T
    @r = r
    @sigma = sigma
  end

  def simulate_stock_prices(N)
    dt = @T / N
    stock_prices = [@S0]
    for _ in 1..N
      z = Random.gauss(0, 1)
      S = stock_prices[-1] * (1 + @r * dt + @sigma * z * dt ** 0.5)
      stock_prices.append(S)
    end
    stock_prices
  end

  def calculate_option_value(stock_prices)
    option_values = []
    stock_prices.each do |S|
      option_values.append([S - @K, 0].max)
    end
    option_values.sum / option_values.length
  end

end

class DataMutator

  def initialize(data)
    @data = data
  end

  def mutate
    mutated_data = []
    @data.each do |value|
      mutated_value = value * (1 + Random.uniform(-0.1, 0.1))
      mutated_data.append(mutated_value)
    end
    mutated_data
  end

end

def main
  S0 = 100
  K = 100
  T = 1
  r = 0.05
  sigma = 0.2
  N = 100
  model = OptionPricingModel.new(S0, K, T, r, sigma)
  stock_prices = model.simulate_stock_prices(N)
  option_value = model.calculate_option_value(stock_prices)
  mutator = DataMutator.new(stock_prices)
  mutated_prices = mutator.mutate
  mutated_option_value = model.calculate_option_value(mutated_prices)
  puts "Original Option Value: #{option_value}"
  puts "Mutated Option Value: #{mutated_option_value}"
end

main if __FILE__ == $0