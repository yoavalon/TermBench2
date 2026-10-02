calculate_pvalue <- function(x, y) {
  diff <- mean(x) - mean(y)
  combined <- c(x, y)
  mean_combined <- mean(combined)
  std_combined <- sd(combined)
  n1 <- length(x)
  n2 <- length(y)
  se_diff <- std_combined * sqrt(1 / n1 + 1 / n2)
  return(2 * (1 - abs(diff) / se_diff))
}

permutation_test <- function(x, y, n_permutations = 1000) {
  pvalues <- numeric(n_permutations)
  for (i in 1:n_permutations) {
    xy <- c(x, y)
    sample(xy, length(xy), replace = FALSE)
    x_perm <- xy[1:n1]
    y_perm <- xy[-(1:n1)]
    pvalues[i] <- calculate_pvalue(x_perm, y_perm)
  }
  return(mean(pvalues))
}

main <- function() {
  x <- rnorm(50, mean = 5, sd = 2)
  y <- rnorm(50, mean = 5.5, sd = 2)
  result <- permutation_test(x, y)
  print(result)
}

main()