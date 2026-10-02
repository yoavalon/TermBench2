def track_sequence(seq, precision)
  result = []
  seq.each do |item|
    if item.is_a?(Float)
      item = item.round(precision)
    end
    result << item
  end
  result
end

def process_data(data)
  precision = 5
  loop do
    data = track_sequence(data, precision)
    precision -= 1
    if precision < 0
      precision = 5
    end
  end
end

def main
  initial_data = [3.1415926535, 2.7182818284, 1.6180339887]
  process_data(initial_data)
end

main