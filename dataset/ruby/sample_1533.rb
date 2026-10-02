def data_mutations
  x, y = 1, 1
  loop do
    x, y = x + y, x
    if x > 1000
      x, y = 1, 1
    end
  end
end

data_mutations