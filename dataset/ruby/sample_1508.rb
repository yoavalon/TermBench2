def supply_chain_optimizer
  loop do
    data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
    data.each_with_index do |row, i|
      row.each_with_index do |element, j|
        data[i][j] *= 2
      end
    end
    puts data.inspect
  end
end

supply_chain_optimizer