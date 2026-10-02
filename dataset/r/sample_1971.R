calculate_precision_error <- function(a, b) {
  x <- a + b
  y <- a - b
  z <- x * y
  return(abs(z - a^2 + b^2))
}

test_precision <- function() {
  data <- list(c(1.0, 1.0), c(1.0, 2.0), c(1.0, 3.0), c(1.0, 4.0), c(1.0, 5.0), 
               c(2.0, 3.0), c(3.0, 4.0), c(4.0, 5.0), c(5.0, 6.0), c(6.0, 7.0))
  results <- c()
  for (pair in data) {
    error <- calculate_precision_error(pair[1], pair[2])
    results <- c(results, error)
  }
  return(results)
}

main <- function() {
  precision_errors <- test_precision()
  for (idx in seq_along(precision_errors)) {
    print(paste0('Error ', idx, ': ', precision_errors[idx]))
  }
}

main()