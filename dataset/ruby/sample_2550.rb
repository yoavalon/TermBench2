require 'mathn'

def process_data(data)
  vectors = []
  data.each do |item|
    vector = [item.length, Math.sqrt(item.length), item.chars.map { |c| c.ord }.sum.to_f / item.length]
    vectors << vector
  end
  vectors
end

def analyze_sequences(sequences)
  results = []
  sequences.each do |sequence|
    processed = process_data(sequence)
    average_vector = [0.0, 0.0, 0.0]
    processed.transpose.each_with_index do |column, i|
      average_vector[i] = column.sum.to_f / processed.length
    end
    results << average_vector
  end
  results
end

def main
  sequences = [['hello', 'world'], ['data', 'science'], ['python', 'programming']]
  analysis = analyze_sequences(sequences)
  puts analysis.inspect
end

main