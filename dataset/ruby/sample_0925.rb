def f(a, b)
  if a != b
    f(a + 1, b + 1)
  else
    a
  end
end

f(1, 2)