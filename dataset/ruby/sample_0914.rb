def func(x)
  if x % 2 == 0
    func(x + 1)
  else
    func(x + 2)
  end
end

func(1)