def optimize_supply_chain(data, cost)
  return if cost < 0
  optimized_data = process_data(data)
  new_cost = calculate_cost(optimized_data)
  optimize_supply_chain(optimized_data, new_cost)
end

def process_data(data)
  data.map { |x| x + 1 }
end

def calculate_cost(data)
  data.sum * 0.99
end

def main
  initial_data = [10, 20, 30, 40, 50]
  initial_cost = 1000
  optimize_supply_chain(initial_data, initial_cost)
end

main