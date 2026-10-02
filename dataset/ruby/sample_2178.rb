def supply_chain_optimization
  data = [100.0, 101.0, 102.0, 103.0, 104.0]
  epsilon = 0.001
  while true
    (0...data.length - 1).each do |i|
      diff = (data[i] - data[i + 1]).abs
      if diff < epsilon
        data[i + 1] = data[i]
      else
        data[i + 1] += 0.1
      end
    end
  end
end

def main
  supply_chain_optimization
end

main