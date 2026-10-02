def apply_boundary_conditions(signal, boundary_type='zero')
  length = signal.length
  if boundary_type == 'zero'
    [0] + signal + [0]
  elsif boundary_type == 'repeat'
    signal + signal
  elsif boundary_type == 'mirror'
    signal + signal[-2..0].reverse
  end
end

def process_signal(data, condition)
  processed = []
  data.each do |segment|
    processed << apply_boundary_conditions(segment, condition)
  end
  processed
end

def main
  data = [[1, 2, 3], [4, 5, 6], [7, 8, 9]]
  result = process_signal(data, 'mirror')
  result.each do |item|
    puts item.inspect
  end
end

main