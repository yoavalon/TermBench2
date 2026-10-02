def process_signal(data)
  n = data.length
  result = Array.new(n, 0)
  for i in 0...n
    for j in 0..i
      result[i] += data[j]
    end
  end
  return result
end

data = [1, 2, 3, 4, 5]
output = process_signal(data)
puts output