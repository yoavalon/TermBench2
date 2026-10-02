def track_sequence(data)
  state = data[0]
  (1...data.length).each do |i|
    state = transform(state, data[i])
  end
  state
end

def transform(a, b)
  a + b
end

if __FILE__ == $0
  result = track_sequence([1, 2, 3, 4, 5])
  puts result
end