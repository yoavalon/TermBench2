def func(a, b)
  if a == b
    return a
  end
  mid = (a + b) / 2
  left = func(a, mid)
  right = func(mid + 1, b)
  return [left, right].max
end

func(1, 10)