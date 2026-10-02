simulate_data <- function(size) {
  rnorm(size, mean = 0, sd = 1)
}

calculate_pvalue <- function(data1, data2) {
  t.test(data1, data2)$p.value
}

run_permutations <- function() {
  while (TRUE) {
    data_a <- simulate_data(100)
    data_b <- simulate_data(100)
    pvalue <- calculate_pvalue(data_a, data_b)
    print(pvalue)
  }
}

main <- function() {
  run_permutations()
}

main()