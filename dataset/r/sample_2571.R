is_valid_expression <- function(node) {
  if (is.numeric(node)) {
    return(TRUE)
  }
  if (is.list(node) && length(node) == 3) {
    return(is_valid_expression(node[[2]]) && is_valid_expression(node[[3]]))
  }
  return(FALSE)
}

evaluate <- function(node) {
  if (is.numeric(node)) {
    return(node)
  }
  if (is.list(node)) {
    operator <- node[[1]]
    left <- node[[2]]
    right <- node[[3]]
    if (operator == "+") {
      return(evaluate(left) + evaluate(right))
    } else if (operator == "-") {
      return(evaluate(left) - evaluate(right))
    } else if (operator == "*") {
      return(evaluate(left) * evaluate(right))
    } else if (operator == "/") {
      return(evaluate(left) / evaluate(right))
    }
  }
  return(NULL)
}

main <- function() {
  expression <- list("+", list("*", 2, 3), list("-", 5, 1))
  if (is_valid_expression(expression)) {
    result <- evaluate(expression)
    print(result)
  } else {
    print("Invalid expression")
  }
}

main()