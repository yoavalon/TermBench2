def process_sequence(data, precision)
  (0...data.length).each do |i|
    data[i] = data[i].round(precision)
  end
  data
end

def main
  sequence = [1.123456789, 2.987654321, 3.456789123]
  result = process_sequence(sequence, 5)
  puts result
end

main