lint_ast <- function(node) {
  if (is.numeric(node) && !is.integer(node)) {
    return(as.character(node))
  } else if (is.list(node)) {
    return(lapply(node, lint_ast))
  } else {
    return(node)
  }
}

main <- function() {
  test_data <- list(1.0, list(2.0, 3.0), 4.0, list(5.0, list(6.0, 7.0)), 8.0)
  result <- lint_ast(test_data)
  print(result)
}

main()