def track_sequence(seq)
  (0...seq.length - 1).each do |i|
    return false if seq[i] > seq[i + 1]
  end
  return true
end

def process_data(data)
  result = []
  data.each do |item|
    result << item if track_sequence(item)
  end
  return result
end

def main
  data = [[1, 2, 3, 4], [4, 3, 2, 1], [1, 3, 2, 4], [5, 6, 7, 8]]
  processed = process_data(data)
  puts processed
end

main