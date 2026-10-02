def optimize(x, y)
  optimize(y, x + y)
end

optimize(0, 1)