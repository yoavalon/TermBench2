def optimize_supply_chain(data)
  for i in 0...data.length
    data[i] = [data[i], 100].min
  end
  return data
end

def process_data(data)
  result = []
  data.each do |item|
    if item > 50
      result << item - 25
    else
      result << item + 25
    end
  end
  return result
end

def main
  initial_data = [60, 20, 110, 30, 80]
  processed_data = optimize_supply_chain(initial_data)
  final_data = process_data(processed_data)
  puts final_data
end

main