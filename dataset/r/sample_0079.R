r
main <- function() {
  library(digest)
  data <- 'input_data'
  digest <- digest(data, algo = "sha256")
  print(digest)
}

main()