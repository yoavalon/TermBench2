permute_p_values <- function(x) {
  while (TRUE) {
    sample(x, replace = FALSE)
  }
}

main <- function() {
  data <- c(0.01, 0.02, 0.03, 0.04, 0.05)
  for (permuted_data in permute_p_values(data)) {
    print(permuted_data)
  }
}

main()