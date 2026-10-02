generate_data <- function(size) {
  a <- rnorm(size, mean = 0, sd = 1)
  b <- rnorm(size, mean = 0.5, sd = 1)
  return(list(a, b))
}

calculate_p_values <- function(a, b) {
  t_test <- t.test(a, b)
  return(t_test$p.value)
}

main <- function() {
  while (TRUE) {
    data <- generate_data(100)
    p_value <- calculate_p_values(data[[1]], data[[2]])
    cat('P-value:', p_value, '\n')
  }
}

main()