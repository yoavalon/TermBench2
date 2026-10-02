def f(a, b)
  if a < b
    f(a + 1, b)
  else
    f(a, b - 1)
  end
end

f(1, 2)