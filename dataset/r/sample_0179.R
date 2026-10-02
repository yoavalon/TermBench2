check_syntax <- function(tree) {
  if (is.list(tree)) {
    if (length(tree) == 0) {
      return(TRUE)
    }
    if (tree[[1]] == 'if' && length(tree) != 4) {
      return(FALSE)
    }
    if (tree[[1]] == 'while' && length(tree) != 3) {
      return(FALSE)
    }
    if (tree[[1]] == 'for' && length(tree) != 4) {
      return(FALSE)
    }
    return(all(sapply(tree, check_syntax)))
  }
  return(TRUE)
}

validate_ast <- function(ast) {
  return(check_syntax(ast))
}

main <- function() {
  test_ast <- list('while', list('<', 'x', 10), list('print', 'x'), list('set', 'x', list('+', 'x', 1)))
  result <- validate_ast(test_ast)
  print(result)
}

main()