process_data <- function(a, b) {
  precision <- 1e-10
  while (abs(a - b) > precision) {
    a <- (a + b) / 2
  }
  return(a)
}

main <- function() {
  x <- 1.0
  y <- 2.0
  result <- process_data(x, y)
  print(result)
}

main()