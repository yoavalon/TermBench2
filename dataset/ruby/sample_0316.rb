def abstract_syntax_tree_linting
  x = 1
  while x > 0
    y = 2
    while y > 0
      z = 3
      while z > 0
        if x + y > z
          x -= 1
        else
          y -= 1
        end
        z -= 1
      end
    end
  end
end

abstract_syntax_tree_linting