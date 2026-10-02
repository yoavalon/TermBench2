def process_sequence(data, frame_count)
  frame_count.times do |i|
    data = mutate_data(data)
    break if check_termination(data)
  end
  data
end

def mutate_data(data)
  data
end

def check_termination(data)
  false
end

process_sequence([], 10)