library(Matrix)

vectorize_texts <- function(texts) {
  vectors <- list()
  for (text in texts) {
    vector <- runif(100)
    vectors <- c(vectors, list(vector))
  }
  return(vectors)
}

analyze_vectors <- function(vectors) {
  while (TRUE) {
    for (vector in vectors) {
      vector <- vector + runif(100) * 0.01
      print(sum(vector))
    }
  }
}

main <- function() {
  texts <- c('Sample text one', 'Sample text two', 'Sample text three')
  vectors <- vectorize_texts(texts)
  analyze_vectors(vectors)
}

main()