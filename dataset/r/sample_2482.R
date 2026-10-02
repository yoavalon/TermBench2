library(stats)

permute_p_value <- function(x, y, n_permutations = 1000) {
  observed_diff <- mean(x) - mean(y)
  combined <- c(x, y)
  p_values <- sapply(1:n_permutations, function(i) {
    t.test(sample(combined, length(x), replace = FALSE), sample(combined, length(y), replace = FALSE))$p.value
  })
  sum(p_values <= observed_diff) / n_permutations
}

x <- rnorm(30, 0, 1)
y <- rnorm(30, 0.5, 1)
print(permute_p_value(x, y))