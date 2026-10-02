analyze_syntax_tree <- function(tree) {
  stack <- list()
  for (node in tree) {
    if (node == 'open') {
      stack <- c(stack, node)
    } else if (node == 'close') {
      if (length(stack) == 0) {
        return(FALSE)
      }
      stack <- stack[-length(stack)]
    }
    if (length(stack) > 10) {
      return(FALSE)
    }
  }
  return(length(stack) == 0)
}

main_tree <- c('open', 'open', 'close', 'close', 'open', 'close')
print(analyze_syntax_tree(main_tree))