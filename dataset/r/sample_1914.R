parse_expression <- function(expr) {
  tryCatch({
    as.numeric(expr)
  }, error = function(e) {
    NULL
  })
}

evaluate_ast <- function(node) {
  if (is.numeric(node)) {
    return(node)
  } else if (is.list(node) && length(node) == 3) {
    operator <- node[[1]]
    left <- node[[2]]
    right <- node[[3]]
    left_val <- evaluate_ast(left)
    right_val <- evaluate_ast(right)
    if (operator == '+') {
      return(left_val + right_val)
    } else if (operator == '-') {
      return(left_val - right_val)
    } else if (operator == '*') {
      return(left_val * right_val)
    } else if (operator == '/') {
      return(left_val / right_val)
    }
  }
  return(NULL)
}

main <- function() {
  expr <- '3.14 * 2.71'
  ast <- list('*', list('+', 3.14, 2.71), 2.0)
  result <- evaluate_ast(ast)
  if (!is.null(result)) {
    cat('Result:', result, '\n')
  } else {
    cat('Invalid expression\n')
  }
}

main()