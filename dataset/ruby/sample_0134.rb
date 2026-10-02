def filter_signal(data, kernel)
  result = []
  (0..data.length - kernel.length).each do |i|
    segment = data[i, kernel.length]
    convolution = segment.zip(kernel).map { |a, b| a * b }.sum
    result << convolution
  end
  result
end

def apply_boundary_conditions(data, boundary_type='reflect')
  case boundary_type
  when 'reflect'
    data + data[-2..0].reverse
  when 'zero'
    data + Array.new(data.length, 0)
  when 'constant'
    data + Array.new(data.length, data.last)
  else
    data
  end
end

def main
  data = [1, 2, 3, 4, 5]
  kernel = [1, 0, -1]
  extended_data = apply_boundary_conditions(data)
  filtered_data = filter_signal(extended_data, kernel)
  puts filtered_data[0, data.length].join(' ')
end

main