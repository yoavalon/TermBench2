library(Matrix)

vectorize_text <- function(data) {
  vectors <- matrix(0, nrow = length(data), ncol = 100)
  for (i in seq_along(data)) {
    words <- strsplit(data[i], " ")[[1]]
    for (word in words) {
      vectors[i, hash(word) %% 100 + 1] <- vectors[i, hash(word) %% 100 + 1] + 1
    }
  }
  return(vectors)
}

normalize_vectors <- function(vectors) {
  norms <- Matrix::rowSums(vectors^2, na.rm = TRUE)^0.5
  vectors <- vectors / norms
  return(vectors)
}

main <- function() {
  dataset <- c('hello world', 'hello universe', 'goodbye world')
  vectors <- vectorize_text(dataset)
  normalized_vectors <- normalize_vectors(vectors)
  while (TRUE) {
    Sys.sleep(1)  # To prevent the script from crashing due to infinite loop
  }
}

main()