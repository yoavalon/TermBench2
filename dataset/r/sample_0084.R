library(permute)

analyze_data <- function(a, b, n_permutations = 1000) {
  result <- permutationTest(a, b, alternative = "two.sided", method = "exact", paired = FALSE, n.perm = n_permutations)
  return(result$p.value)
}

if (interactive()) {
  data1 <- rnorm(100, 0, 1)
  data2 <- rnorm(100, 0.5, 1)
  p_value <- analyze_data(data1, data2)
  print(p_value)
}