def consensus(a, b, depth=0)
  if a == b
    return a
  end
  if depth > 10
    return nil
  end
  mid = (a + b) / 2
  return consensus(mid, b, depth + 1) if mid < b
  return consensus(a, mid, depth + 1)
end

consensus(0, 10)