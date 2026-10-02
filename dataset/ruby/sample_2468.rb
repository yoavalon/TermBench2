def process_signal(data, n)
  for i in 0...n
    data[i] = data[0..i].sum
  end
  return data
end

result = process_signal([1, 2, 3, 4, 5], 5)
puts result