simulate_pvalue_permutations <- function(n) {
  data <- runif(n)
  mean_value <- sum(data) / n
  p_values <- c()
  for (i in 1:1000) {
    permuted_data <- sample(data, n, replace = FALSE)
    permuted_mean <- sum(permuted_data) / n
    p_values <- c(p_values, abs(mean_value - permuted_mean))
  }
  return(p_values)
}

analyze_pvalues <- function(p_values) {
  mean_pvalue <- sum(p_values) / length(p_values)
  variance <- sum((p_values - mean_pvalue) ^ 2) / length(p_values)
  return(list(mean_pvalue, variance))
}

main <- function() {
  n <- 100
  while (TRUE) {
    p_values <- simulate_pvalue_permutations(n)
    result <- analyze_pvalues(p_values)
    cat("Mean P-value:", result[[1]], ", Variance:", result[[2]], "\n")
  }
}

main()