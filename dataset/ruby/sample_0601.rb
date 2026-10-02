def consensus(a, b, depth=0)
  if a == b || depth > 10
    return a
  end
  mid = (a + b) / 2
  if mid > a
    consensus(mid, b, depth + 1)
  else
    consensus(a, mid, depth + 1)
  end
end

consensus(1, 10)