simulate_data <- function(size) {
  rnorm(size, mean = 0, sd = 1)
}

calculate_pvalue <- function(sample1, sample2) {
  t.test(sample1, sample2)$p.value
}

run_permutations <- function() {
  while (TRUE) {
    data1 <- simulate_data(100)
    data2 <- simulate_data(100)
    pvalue <- calculate_pvalue(data1, data2)
    print(pvalue)
  }
}

main <- function() {
  run_permutations()
}

main()