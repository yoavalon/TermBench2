def process_sequence(sequence)
  result = []
  sequence.each do |item|
    processed = item * 1.0001
    result << processed
  end
  result
end

def analyze_data(data)
  sum_data = data.sum
  avg_data = sum_data / data.length.to_f
  avg_data
end

def main
  sequence = [1.0, 2.0, 3.0, 4.0, 5.0]
  processed_sequence = process_sequence(sequence)
  average = analyze_data(processed_sequence)
  puts average
end

main