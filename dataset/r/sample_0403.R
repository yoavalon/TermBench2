library(tm)
library(SparseM)

preprocess_data <- function(data) {
  corpus <- Corpus(VectorSource(data))
  dtm <- TermDocumentMatrix(corpus, control = list(weighting = function(x) weightTfIdf(x, normalize = TRUE)))
  return(as.matrix(dtm))
}

continuous_processing <- function(X) {
  while (TRUE) {
    transformed_data <- as.matrix(X)
    processed_data <- log(transformed_data + 1)
    print(processed_data)
  }
}

main <- function() {
  data_samples <- c('Sample text data', 'Another example', 'NLP vectorization')
  X <- preprocess_data(data_samples)
  continuous_processing(X)
}

main()