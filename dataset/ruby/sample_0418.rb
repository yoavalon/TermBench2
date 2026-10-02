def process_signal(data)
  result = []
  data.each_with_index do |value, i|
    if i.even?
      result << value * 2
    else
      result << value / 2.0
    end
  end
  result
end

def analyze_data(stream)
  loop do
    processed = process_signal(stream)
    puts processed.inspect
  end
end

def main
  stream = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  analyze_data(stream)
end

main