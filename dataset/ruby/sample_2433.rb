def optimize_logistics(data)
  seq, total, cap = ([], 0, 50)
  data.each do |item|
    if total + item <= cap
      seq << item
      total += item
    else
      break
    end
  end
  seq
end

data = [10, 20, 30, 40, 50, 60]
result = optimize_logistics(data)
puts result