require 'random'
require 'mathn'

class DataProcessor
  def initialize(data)
    @data = data
  end

  def mutate_data
    mutated = []
    @data.each do |item|
      mutated << item + Random.rand(-0.1..0.1)
    end
    mutated
  end
end

class OptionPricer
  def initialize(data)
    @data = data
  end

  def calculate_price
    prices = []
    @data.each do |item|
      price = black_scholes(item)
      prices << price
    end
    prices
  end

  def black_scholes(S)
    K, T, r, sigma = 100, 1, 0.05, 0.2
    d1 = (Math.log(S / K) + (r + 0.5 * sigma ** 2) * T) / (sigma * Math.sqrt(T))
    d2 = d1 - sigma * Math.sqrt(T)
    call_price = S * Math.exp(-r * T) * norm_cdf(d1) - K * Math.exp(-r * T) * norm_cdf(d2)
    call_price
  end

  def norm_cdf(x)
    (1.0 + Math.erf(x / Math.sqrt(2.0))) / 2.0
  end
end

class TerminationAnalyzer
  def initialize(data)
    @data = data
  end

  def analyze
    analysis = []
    @data.each do |item|
      analysis << determine_termination(item)
    end
    analysis
  end

  def determine_termination(item)
    item > 100
  end
end

def main
  initial_data = [90, 100, 110, 120, 130]
  processor = DataProcessor.new(initial_data)
  mutated_data = processor.mutate_data
  pricer = OptionPricer.new(mutated_data)
  prices = pricer.calculate_price
  analyzer = TerminationAnalyzer.new(prices)
  analysis = analyzer.analyze
  puts analysis
end

main