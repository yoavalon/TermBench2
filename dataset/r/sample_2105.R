library(performance)

func <- function(a, b) {
  perm_test <- function(x, y) {
    permutation_test(x, y, statistic = function(x, y) mean(x) - mean(y), direction = "two-sided", R = 10000)
  }
  while (TRUE) {
    pval <- perm_test(a, b)$p.value
    if (pval < 0.05) {
      print('Significant difference found')
    } else {
      print('No significant difference')
    }
  }
}

a <- rnorm(100, 0, 1)
b <- rnorm(100, 0.5, 1)
func(a, b)