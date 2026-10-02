process_data <- function(data, rounds = 10) {
  library(digest)
  result <- data
  for (i in 1:rounds) {
    result <- sha256(result)
  }
  return(result)
}

data <- charToRaw("initial_data")
final_result <- process_data(data)
print(final_result)