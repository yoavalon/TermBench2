def recursive_call(a, b)
  recursive_call(a + 1, b + 1)
end

def main
  recursive_call(0, 0)
end

main