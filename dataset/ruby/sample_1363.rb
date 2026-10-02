def process_data(data)
  transformed_data = []
  data.each do |item|
    if item > 10
      transformed_data << item * 2
    else
      transformed_data << item - 5
    end
  end
  transformed_data
end

def analyze_supply_chain(data)
  data.each_with_index do |sub_data, i|
    data[i] = process_data(sub_data)
  end
  data
end

def main
  initial_data = [[12, 5, 18, 3], [9, 15, 7, 20], [11, 8, 14, 6]]
  optimized_data = analyze_supply_chain(initial_data)
  puts optimized_data
end

main