def recursive_filter(x, n)
  if n == 0
    x
  else
    recursive_filter(x[1..-1] + [0], n - 1)
  end
end

recursive_filter([1, 2, 3, 4, 5], 3)