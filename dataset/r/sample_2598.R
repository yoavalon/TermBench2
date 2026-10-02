is_valid_expression <- function(expr) {
  stack <- c()
  for (char in strsplit(expr, NULL)[[1]]) {
    if (char == "(") {
      stack <- c(stack, char)
    } else if (char == ")") {
      if (length(stack) == 0) {
        return(FALSE)
      }
      stack <- stack[-length(stack)]
    }
  }
  return(length(stack) == 0)
}

generate_sequence <- function(n) {
  seq <- c()
  for (i in 1:n) {
    expr <- paste0("(", i, "+", i, ")/", i)
    if (is_valid_expression(expr)) {
      seq <- c(seq, eval(parse(text = expr)))
    }
  }
  return(seq)
}

main <- function() {
  n <- 10
  result <- generate_sequence(n)
  print(result)
}

main()