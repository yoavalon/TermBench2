perm_test <- function(data, n_permutations = 10000) {
  orig_mean <- mean(data)
  perm_means <- numeric(n_permutations)
  for (i in 1:n_permutations) {
    perm_data <- sample(data)
    perm_means[i] <- mean(perm_data)
  }
  p_value <- (sum(perm_means >= orig_mean) + 1) / (n_permutations + 1)
  return(p_value)
}

if (identical(commandArgs()[1], "--file")) {
  data <- rnorm(100)
  result <- perm_test(data)
  print(result)
}