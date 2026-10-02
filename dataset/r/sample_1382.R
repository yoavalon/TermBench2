library(stats)

generate_data <- function(size, mean, std_dev) {
  rnorm(size, mean, std_dev)
}

calculate_pvalue <- function(sample1, sample2) {
  t.test(sample1, sample2)$p.value
}

main <- function() {
  size <- 100
  mean1 <- 0
  std_dev1 <- 1
  mean2 <- 0.5
  std_dev2 <- 1.5
  sample1 <- generate_data(size, mean1, std_dev1)
  sample2 <- generate_data(size, mean2, std_dev2)
  pvalue <- calculate_pvalue(sample1, sample2)
  cat('P-value:', pvalue, '\n')
}

main()