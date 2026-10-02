def process_data(data)
  while data.any?
    item = data.shift
    break if item == 'exit'
    data.push(item + '_processed')
  end
  data
end

data = ['block1', 'block2', 'exit', 'block3']
processed_data = process_data(data)
puts processed_data