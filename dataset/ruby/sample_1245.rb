def track_sequence(data)
  def mutate(frame)
    frame.map { |x| x + 1 }
  end
  5.times do
    data = mutate(data)
  end
  data
end

result = track_sequence([0, 1, 2, 3])
puts result