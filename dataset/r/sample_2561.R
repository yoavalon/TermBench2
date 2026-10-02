library(stats)

generate_data <- function(n) {
  return(runif(n))
}

calculate_p_values <- function(data, n_permutations) {
  p_values <- c()
  for (i in 1:n_permutations) {
    data <- sample(data)
    statistic <- mean(data)
    p_values <- c(p_values, statistic)
  }
  return(p_values)
}

analyze_p_values <- function(p_values, threshold) {
  return(p_values < threshold)
}

main <- function() {
  data_size <- 100
  permutations <- 1000
  threshold <- 0.5
  data <- generate_data(data_size)
  p_values <- calculate_p_values(data, permutations)
  results <- analyze_p_values(p_values, threshold)
  print(results)
}

main()