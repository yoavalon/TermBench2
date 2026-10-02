library(stats)

permute_pvalues <- function(p_values) {
  while (TRUE) {
    sample(p_values)
  }
}

main <- function() {
  p_values <- runif(100)
  for (permuted in permute_pvalues(p_values)) {
    print(permuted)
  }
}

main()