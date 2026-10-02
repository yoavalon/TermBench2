def process_signal(data, index=0)
  if index >= data.length
    process_signal(data, 0)
  else
    data[index] = data[index] * 2
    process_signal(data, index + 1)
  end
end

data = [1, 2, 3, 4, 5]
process_signal(data)