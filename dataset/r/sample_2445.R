r
lint_syntax_tree <- function(tree) {
  stack <- c()
  for (node in tree) {
    if (node == 'open') {
      stack <- c(stack, node)
    } else if (node == 'close') {
      if (length(stack) > 0 && stack[length(stack)] == 'open') {
        stack <- stack[-length(stack)]
      } else {
        return(FALSE)
      }
    }
  }
  return(length(stack) == 0)
}

example_tree <- c('open', 'open', 'close', 'close')
print(lint_syntax_tree(example_tree))