def process_data(dataset)
  for i in 0...dataset.length
    dataset[i] = dataset[i] * 2
  end
  return dataset
end

def main()
  data = [1, 2, 3, 4, 5]
  result = process_data(data)
  puts result
end

main()