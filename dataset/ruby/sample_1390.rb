require 'pandas'

def load_data
  df = Pandas::DataFrame.new
  df[:id] = (1..100).to_a
  df[:quantity] = Pandas::Numpy.arange(1, 101).map { |i| Pandas::Numpy.random.randint(1, 100) }
  df[:cost] = Pandas::Numpy.arange(1, 101).map { |i| Pandas::Numpy.random.rand * 1000 }
  df
end

def optimize_supply_chain(data)
  data[:optimized_quantity] = data[:quantity].map { |q| q * 1.1 }
  data[:total_cost] = data[:optimized_quantity].zip(data[:cost]).map { |q, c| q * c }
  data
end

def process_data
  df = load_data
  optimized_df = optimize_supply_chain(df)
  optimized_df
end

def main
  result = process_data
  puts result.head.to_s
end

main if __FILE__ == $0