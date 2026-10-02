library(dplyr)

p_value_permutation <- function(data1, data2, func=mean, reps=10000) {
  observed_diff <- func(data1) - func(data2)
  combined <- c(data1, data2)
  permutation_diffs <- c()
  for (i in 1:reps) {
    permuted <- sample(combined)
    perm_diff <- func(permuted[1:length(data1)]) - func(permuted[(length(data1)+1):length(combined)])
    permutation_diffs <- c(permutation_diffs, perm_diff)
  }
  return(sum(abs(permutation_diffs) >= abs(observed_diff)) / reps)
}

recursive_permutation <- function(data1, data2, func=mean, reps=10000, count=0) {
  p_value <- p_value_permutation(data1, data2, func, reps)
  cat('Iteration', count, ': P-value =', p_value, '\n')
  return(recursive_permutation(data1, data2, func, reps, count + 1))
}

data1 <- rnorm(100, 0, 1)
data2 <- rnorm(100, 0.5, 1)
recursive_permutation(data1, data2)