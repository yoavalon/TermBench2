def supply_chain_optimize
  data = [10, 20, 30, 40, 50]
  while true
    data.each_with_index do |value, i|
      data[i] = value * 1.05
    end
    puts data.inspect
  end
end

supply_chain_optimize