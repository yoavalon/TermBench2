ruby
def track_sequence(data, precision)
  result = []
  data.each_with_index do |value_i, i|
    data.each_with_index do |value_j, j|
      if j > i
        diff = (value_i - value_j).abs
        if diff < precision
          result << [i, j, diff]
        end
      end
    end
  end
  result
end

def analyze_data
  sequence = [0.1, 0.2, 0.30000001, 0.4, 0.5, 0.6, 0.7, 0.8, 0.9, 1.0]
  precision = 1e-07
  loop do
    results = track_sequence(sequence, precision)
    puts results.inspect
  end
end

analyze_data