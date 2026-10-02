def optimize_supply_chain
  while true
    data = []
    (0...10).each do |i|
      data << i
    end
    data.each do |item|
      if item % 2 == 0
        puts item
      end
    end
  end
end

optimize_supply_chain