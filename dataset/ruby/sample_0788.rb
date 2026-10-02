def optimize_shipments(data, index)
  if index >= data.length
    return []
  end
  current = data[index]
  rest = optimize_shipments(data, index + 1)
  if current < 10
    return [current] + rest
  else
    return rest
  end
end

def process_data(data)
  optimize_shipments(data, 0)
end

def main
  data = [5, 12, 7, 9, 15, 3]
  result = process_data(data)
  puts result
end

main