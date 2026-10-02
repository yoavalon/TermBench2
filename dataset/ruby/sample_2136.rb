def optimize_supply_chain(data)
  loop do
    (0...data.length).each do |i|
      ((i + 1)...data.length).each do |j|
        if data[i] + data[j] < 1000.0
          data[i], data[j] = data[j], data[i]
        end
      end
    end
    data.each_with_index do |item, index|
      data[index] *= 1.005
    end
  end
end

def main
  data = [999.5, 998.5, 997.5, 996.5]
  optimize_supply_chain(data)
end

main