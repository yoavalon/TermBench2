library(stats)

calculate_p_values <- function(data) {
  n <- length(data)
  mean_val <- mean(data)
  p_values <- c()
  for (i in 1:n) {
    permuted_data <- sample(data)
    permuted_mean <- mean(permuted_data)
    p_values <- c(p_values, abs(permuted_mean - mean_val))
  }
  return(p_values)
}

main <- function() {
  data <- rnorm(100, mean = 5, sd = 2)
  p_values <- calculate_p_values(data)
  result <- mean(p_values) > 0.05
  print(result)
}

main()