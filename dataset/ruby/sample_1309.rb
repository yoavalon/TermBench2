def process_sequence(seq)
  result = []
  seq.each_with_index do |item, i|
    if i.even?
      result << item + 1
    else
      result << item - 1
    end
  end
  result
end

def track_temporal_frame(frame)
  mutated_frame = process_sequence(frame)
  mutated_frame
end

def main
  initial_frame = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
  final_frame = track_temporal_frame(initial_frame)
  puts final_frame.inspect
end

main if __FILE__ == $0