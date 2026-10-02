def func(a)
  if a == 0
    return 1
  end
  return func(a - 1)
end

func(5)