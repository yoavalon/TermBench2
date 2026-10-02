def recursive_filter(x, n)
  if n == 0
    return x
  end
  return recursive_filter(x + 1, n - 1)
end

recursive_filter(0, 5)