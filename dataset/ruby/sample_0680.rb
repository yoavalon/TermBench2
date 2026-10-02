def consensus(a, b)
  if a == b
    return a
  elsif a > b
    return consensus(a - 1, b)
  else
    return consensus(a, b - 1)
  end
end

consensus(10, 15)