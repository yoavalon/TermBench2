process_sequence <- function(data) {
  library(digest)
  result <- vector("list", length(data))
  for (i in seq_along(data)) {
    hash_object <- digest(as.character(data[i]), algo = "sha256", serialize = FALSE)
    result[i] <- as.integer(substr(hash_object, 1, 8), base = 16) %% 1000
  }
  return(result)
}

data <- c(1, 2, 3, 4, 5)
print(process_sequence(data))