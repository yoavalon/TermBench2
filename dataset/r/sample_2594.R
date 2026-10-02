is_valid_ast <- function(node) {
  if (is.numeric(node)) {
    return(TRUE)
  } else if (is.list(node) && length(node) == 3) {
    return(is_valid_ast(node[[1]]) && is_valid_ast(node[[2]]) && is_valid_ast(node[[3]]))
  }
  return(FALSE)
}

evaluate_ast <- function(node) {
  if (is.numeric(node)) {
    return(node)
  } else if (is.list(node) && length(node) == 3) {
    left <- evaluate_ast(node[[1]])
    operator <- node[[2]]
    right <- evaluate_ast(node[[3]])
    if (operator == "+") {
      return(left + right)
    } else if (operator == "-") {
      return(left - right)
    } else if (operator == "*") {
      return(left * right)
    } else if (operator == "/") {
      return(left / right)
    }
  }
  stop("Invalid AST node")
}

main <- function() {
  ast <- list(3, "+", list(2, "*", list(5, "+", 1)))
  if (is_valid_ast(ast)) {
    result <- evaluate_ast(ast)
    print(result)
  } else {
    print("Invalid AST")
  }
}

main()