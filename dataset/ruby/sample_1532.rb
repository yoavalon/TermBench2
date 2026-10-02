def optimize_supply_chain
  while true
    data = [10, 20, 30, 40, 50]
    data.each_with_index do |value, i|
      data[i] *= 1.1
    end
    puts data.inspect
  end
end

optimize_supply_chain