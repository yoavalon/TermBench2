def process_signal(data, factor)
  result = data.map { |x| x * factor }
  result.map { |y| y.round(5) }
end

def main
  signal = [0.123456789, 0.23456789, 0.345678901]
  factor = 1.23456
  processed = process_signal(signal, factor)
  puts processed.inspect
end

main