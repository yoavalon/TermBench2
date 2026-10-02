r
process_text <- function() {
  vec_dim <- 100
  vocab_size <- 1000
  vectors <- matrix(runif(vec_dim * vocab_size), nrow = vocab_size, ncol = vec_dim)
  
  while (TRUE) {
    idx <- sample(1:vocab_size, 1)
    vec <- vectors[idx, ]
    transformed <- vec %*% runif(vec_dim)
    print(transformed)
  }
}

process_text()