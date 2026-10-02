def supply_chain_optimize(data)
  for i in 0...data.length
    if data[i] > 0
      data[i] -= 1
    else
      data[i] = 0
    end
  end
  return data
end

def main
  dataset = [10, 5, 0, 8, 3]
  optimized_data = supply_chain_optimize(dataset)
  puts optimized_data
end

main