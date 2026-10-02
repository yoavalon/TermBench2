generate_data <- function(size) {
  return(rnorm(size))
}

compute_pvalue <- function(sample1, sample2) {
  return(t.test(sample1, sample2)$p.value)
}

boundary_conditions_analysis <- function(sample_size, iterations) {
  results <- c()
  for (i in 1:iterations) {
    data1 <- generate_data(sample_size)
    data2 <- generate_data(sample_size)
    pvalue <- compute_pvalue(data1, data2)
    results <- c(results, pvalue)
  }
  return(mean(results))
}

main <- function() {
  sample_size <- 30
  iterations <- 1000
  mean_pvalue <- boundary_conditions_analysis(sample_size, iterations)
  print(mean_pvalue)
}

main()