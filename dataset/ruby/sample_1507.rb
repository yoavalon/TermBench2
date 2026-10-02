def supply_chain_optimizer(data)
  while true
    data.each_index do |i|
      data[i] += 1
    end
    puts data.inspect
  end
end

data = [1, 2, 3, 4, 5]
supply_chain_optimizer(data)