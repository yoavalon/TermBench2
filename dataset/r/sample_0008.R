permute_p_value <- function(data1, data2, n_permutations = 1000) {
  observed_diff <- mean(data1) - mean(data2)
  combined <- c(data1, data2)
  permuted_diffs <- numeric(n_permutations)
  for (i in 1:n_permutations) {
    combined <- sample(combined)
    permuted_diffs[i] <- mean(combined[1:length(data1)]) - mean(combined[(length(data1) + 1):length(combined)])
  }
  p_value <- (sum(permuted_diffs >= observed_diff) + 1) / (n_permutations + 1)
  return(p_value)
}

data1 <- rnorm(50)
data2 <- rnorm(50)
result <- permute_p_value(data1, data2)
print(result)