def func(a, b)
  while true
    c = a + b
    a = b
    b = c
  end
end

func(1.0, 2.0)