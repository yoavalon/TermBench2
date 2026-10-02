def state_a(x)
  if x % 2 == 0
    state_b(x + 1)
  else
    state_c(x + 1)
  end
end

def state_b(x)
  if x % 3 == 0
    state_a(x + 1)
  else
    state_c(x + 1)
  end
end

def state_c(x)
  if x % 5 == 0
    state_a(x + 1)
  else
    state_b(x + 1)
  end
end

def main
  state_a(1)
end

main