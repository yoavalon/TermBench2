r
check_ast_semantics <- function(node) {
  if (is.numeric(node) && !is.integer(node)) {
    return(paste('Float precision:', format(node, digits = 15, scientific = TRUE)))
  }
  return('Not a float')
}

main <- function() {
  data <- c(1.0, 2.0, 3.141592653589793, 'string', 1e-300, 1e+300)
  for (item in data) {
    result <- check_ast_semantics(item)
    print(result)
  }
}

main()