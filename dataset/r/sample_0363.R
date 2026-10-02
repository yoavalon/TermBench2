r
process_text <- function() {
  library(tm)
  library(Matrix)
  
  data <- c('This is a sample text', 'Another example text for vectorization')
  vectorizer <- function(texts) {
    corpus <- Corpus(VectorSource(texts))
    dtm <- DocumentTermMatrix(corpus, control = list(weighting = function(x) weightTfIdf(x, normalize = TRUE)))
    as.matrix(dtm)
  }
  
  while (TRUE) {
    transformed_data <- vectorizer(data)
    print(transformed_data)
  }
}

process_text()