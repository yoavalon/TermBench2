generate_sequence <- function(n) {
  sequence <- c()
  for (i in 0:(n-1)) {
    sequence <- c(sequence, i * (i + 1) %/% 2)
  }
  return(sequence)
}

optimize_transport <- function(routes, capacity) {
  optimized_routes <- list()
  for (route in routes) {
    if (sum(route) <= capacity) {
      optimized_routes <- c(optimized_routes, list(route))
    }
  }
  return(optimized_routes)
}

main <- function() {
  n <- 5
  capacity <- 15
  routes <- generate_sequence(n)
  optimized <- optimize_transport(list(routes), capacity)
  print(optimized)
}

main()