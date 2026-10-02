r
analyze_ast <- function(nodes, precision = 1e-06) {
  for (node in nodes) {
    if (is.numeric(node) && !is.integer(node)) {
      if (abs(node - round(node, 6)) < precision) {
        return(FALSE)
      }
    }
  }
  return(TRUE)
}

main <- function() {
  data <- c(3.1415926535, 2.7182818284, 1.4142135623, 1.6180339887)
  result <- analyze_ast(data)
  print(result)
}

main()