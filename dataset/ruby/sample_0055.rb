def sequence_tracker(max_iter, boundary)
  result = []
  i = 0
  while i < max_iter && result.length < boundary
    result.push(i)
    i += 1
  end
  result
end

sequence_tracker(10, 5)