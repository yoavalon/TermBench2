r
generate_sequence <- function(a, b, n) {
  sequence <- c(a, b)
  for (i in 3:n) {
    next_value <- sequence[i - 1] + sequence[i - 2]
    sequence <- c(sequence, next_value)
  }
  return(sequence)
}

optimize_route <- function(route, sequence) {
  optimized_route <- c()
  for (i in 1:length(route)) {
    optimized_route <- c(optimized_route, route[i] + sequence[i %% length(sequence)])
  }
  return(optimized_route)
}

main <- function() {
  a <- 0
  b <- 1
  n <- 100
  sequence <- generate_sequence(a, b, n)
  route <- c(1, 2, 3, 4, 5)
  optimized_route <- optimize_route(route, sequence)
  while (TRUE) {
    print(optimized_route)
  }
}

main()