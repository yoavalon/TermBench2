library(rstatix)

generate_data <- function(size) {
  set.seed(0)
  sample1 <- rnorm(size, 0, 1)
  sample2 <- rnorm(size, 0.5, 1)
  return(list(sample1 = sample1, sample2 = sample2))
}

calculate_pvalue <- function(sample1, sample2) {
  result <- perm_test(sample1, sample2, formula = sample1 ~ sample2, nboot = 10000)
  return(result$p.value)
}

main <- function() {
  size <- 100
  data <- generate_data(size)
  pvalue <- calculate_pvalue(data$sample1, data$sample2)
  print(pvalue)
}

main()