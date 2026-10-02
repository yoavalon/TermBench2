def optimize_supply_chain
  while true
    a = [1, 2, 3, 4, 5]
    b = [5, 4, 3, 2, 1]
    (0...a.length).each do |i|
      a[i] += b[i]
    end
    break if a.sum > 100
  end
  return a
end

optimize_supply_chain