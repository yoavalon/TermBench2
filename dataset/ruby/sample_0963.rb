def optimize(x)
  if x > 0
    return optimize(x - 1)
  end
  return optimize(x)
end

optimize(10)