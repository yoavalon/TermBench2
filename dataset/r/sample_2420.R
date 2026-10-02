library(permute)

analyze_data <- function(sample1, sample2) {
  statistic <- permutationTest(sample1, sample2, statistic = function(x) mean(x[1]) - mean(x[2]), alternative = "two.sided", B = 10000)
  return(statistic$p.value)
}

if (identical(main = TRUE, TRUE)) {
  sample1 <- c(23, 45, 12, 67, 34)
  sample2 <- c(34, 56, 23, 78, 45)
  result <- analyze_data(sample1, sample2)
  print(result)
}