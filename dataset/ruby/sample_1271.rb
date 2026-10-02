def process_data(data)
  for i in 0...data.length
    data[i] += 1
  end
  return data
end

def main()
  data = [0, 1, 2, 3, 4]
  result = process_data(data)
  puts result
end

main()